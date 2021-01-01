#include "util.h"
#include "x2sock.h"

#include <thread>
#include <chrono>


class test02_thr {


	struct thr_cb {
		thread* thread_p;
		x2sock* x2sock_p;
	};

public:
	void test02_thr_run();
private:
	static void hello_srv(int tid, thr_cb* thr_cbp);
};