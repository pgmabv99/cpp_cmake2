#include "test02_thr.h"
#include "util.h"
#include "x2sock.h"
#include <thread>
#include <chrono>


void test02_thr::test02_thr_run() {
	//to do why static is needed 
	auto n = 1;
	auto thr_cb_list = new list<thr_cb*>;


	//create N servers
	for (auto tid = 0; tid < n; tid++) {
		auto thr_cb_p = new (thr_cb);
		thr_cb_p->tid = tid;


		thr_cb_p->thread_p = new thread(hello_srv, thr_cb_p);
		thr_cb_list->push_back(thr_cb_p);
	}

	std::this_thread::sleep_for(std::chrono::seconds(10));
	cout << "starting clients" << endl;

	// create N client 
	for (auto tid = 0; tid < n; tid++) {
		auto thr_cb_p = new (thr_cb);
		thr_cb_p->tid = tid;
		thr_cb_p->thread_p = new thread(hello_cln, thr_cb_p);
		thr_cb_list->push_back(thr_cb_p);
	}

	//while (true) {
	//	std::this_thread::sleep_for(std::chrono::seconds(1));
	//	cout << "parent thread " << std::this_thread::get_id() <<  endl;
	//}

	for (auto thr_cb_p : *thr_cb_list) {
		thr_cb_p->thread_p->join();
	}
};

void test02_thr::hello_srv(thr_cb* thr_cb_p) {
	auto nm = 3;
	auto port = 8120 + thr_cb_p->tid;
	auto thr_name = to_string(thr_cb_p->tid);

	thr_cb_p->x2sock_p = new x2sock(port);
	thr_cb_p->x2sock_p->x2accept();

	// send nm msg
	for (int i = 0; i < nm; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		auto buf = " iter  " + to_string(i);
		cout << " tid srv send " << thr_cb_p->tid << " " << buf << endl;
		thr_cb_p->x2sock_p->x2write(buf);
	}
	thr_cb_p->x2sock_p->x2close();
	if (thr_cb_p->x2sock_p)delete(thr_cb_p->x2sock_p);
};

void test02_thr::hello_cln(thr_cb* thr_cb_p) {

	auto port = 8120 + thr_cb_p->tid;
	auto thr_name = to_string(thr_cb_p->tid);

	thr_cb_p->x2sock_p = new x2sock(port);
	thr_cb_p->x2sock_p->x2connect();

	//receive nm msg
	while (true) {
		auto buf = thr_cb_p->x2sock_p->x2read();
		cout << " tid cln receive " << thr_cb_p->tid << " " << buf << endl;
		if (buf == "fin" || buf=="") break;
	}
	thr_cb_p->x2sock_p->x2close();
	if(thr_cb_p->x2sock_p)delete(thr_cb_p->x2sock_p);
};

//todo pipe results to main thread 