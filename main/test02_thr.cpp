#include "test02_thr.h"
#include "util.h"
#include "x2sock.h"
#include <thread>
#include <chrono>


void test02_thr::test02_thr_run() {
	//to do why static is needed 
	auto n = 1;
	auto thr_cb_list = new list<thr_cb*>;



	for (auto tid = 0; tid < n; tid++) {
		auto thr_cbp = new (thr_cb);
		

		thr_cbp->threadp = new thread(hello_srv, tid, thr_cbp);
		thr_cb_list->push_back(thr_cbp);
	}

	while (true) {
		//get msg and print
	}

	for (auto thr_cbp : *thr_cb_list) {
		thr_cbp->threadp->join();
	}
};

void test02_thr::hello_srv(int tid,thr_cb* thr_cbp) {
	auto n = 10;
	thr_cbp->x2sockp = new x2sock(8120 + tid);
	thr_cbp->x2sockp->sock_accept();

	for (auto i = 0; i < n; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << " tid" << tid << endl;
	}
};

//todo pipe results to main thread 