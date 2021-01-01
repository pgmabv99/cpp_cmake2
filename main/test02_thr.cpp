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
		auto thr_cb_p = new (thr_cb);
		

		thr_cb_p->thread_p = new thread(hello_srv, tid, thr_cb_p);
		thr_cb_list->push_back(thr_cb_p);
	}

	while (true) {
		//get msg and print
	}

	for (auto thr_cb_p : *thr_cb_list) {
		thr_cb_p->thread_p->join();
	}
};

void test02_thr::hello_srv(int tid,thr_cb* thr_cb_p) {
	auto n = 10;
	thr_cb_p->x2sock_p = new x2sock(8120 + tid);
	thr_cb_p->x2sock_p->sock_accept();

	for (auto i = 0; i < n; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << " tid" << tid << endl;
	}
};

//todo pipe results to main thread 