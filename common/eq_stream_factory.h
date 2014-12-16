#ifndef _EQSTREAMFACTORY_H

#define _EQSTREAMFACTORY_H

#include <queue>
#include <map>

#include "../common/eq_stream.h"
#include "../common/condition.h"
#include "../common/timeoutmgr.h"

class EQStream;
class Timer;

class EQStreamFactory : private Timeoutable {
	private:
		int sock;
		int Port;

		bool ReaderRunning;
		Mutex MReaderRunning;
		bool WriterRunning;
		Mutex MWriterRunning;

		Condition WriterWork;

		EQStreamType StreamType;

		std::queue<EQStream *> NewStreams;
		Mutex MNewStreams;

		std::map<std::pair<uint32, uint16>,EQStream *> Streams;
		Mutex MStreams;

		virtual void CheckTimeout();

		Timer *DecayTimer;

		uint32 stream_timeout;

	public:
		EQStreamFactory(EQStreamType type, uint32 timeout = 135000) : Timeoutable(5000), stream_timeout(timeout) { ReaderRunning=false; WriterRunning=false; StreamType=type; sock=-1; }
		EQStreamFactory(EQStreamType type, int port, uint32 timeout = 135000);

		EQStream *Pop();
		void Push(EQStream *s);

		bool Open();
		bool Open(unsigned long port) { Port=port; return Open(); }
		bool IsOpen() { return sock!=-1; }
		void Close();
		void ReaderLoop();
		void WriterLoop();
		void Stop() { StopReader(); StopWriter(); }
		void StopReader() { MReaderRunning.lock(); ReaderRunning=false; MReaderRunning.unlock(); }
		void StopWriter() { MWriterRunning.lock(); WriterRunning=false; MWriterRunning.unlock(); WriterWork.Signal(); }
		void SignalWriter() { WriterWork.Signal(); }
};

#endif
