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
	cout << "starting servers" << endl;
	for (auto tid = 0; tid < n; tid++) {
		auto thr_cb_p = new (thr_cb);
		thr_cb_p->tid = tid;


		thr_cb_p->thread_p = new thread(hello_srv, thr_cb_p);
		thr_cb_list->push_back(thr_cb_p);
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));

	// create N client 
	cout << "starting clients" << endl;
	for (auto tid = 0; tid < n; tid++) {
		auto thr_cb_p = new (thr_cb);
		thr_cb_p->tid = tid;
		thr_cb_p->thread_p = new thread(hello_cln, thr_cb_p);
		thr_cb_list->push_back(thr_cb_p);
	}

	//std::this_thread::sleep_for(std::chrono::seconds(1));
	//	cout << "parent thread " << std::this_thread::get_id() <<  endl;
	cout << "wait for threads to join" <<endl;
	for (auto thr_cb_p : *thr_cb_list) {
		thr_cb_p->thread_p->join();
	}
	cout << "threads are joined" << endl;
};

void test02_thr::hello_srv(thr_cb* thr_cb_p) {
	auto nm = 3;
	auto port = 8120 + thr_cb_p->tid;
	auto thr_name = to_string(thr_cb_p->tid);

	try
	{
		thr_cb_p->x2sock_p = new x2sock(port+4);
		thr_cb_p->x2sock_p->x2listen();

		thr_cb_p->x2sock_acpt_p = thr_cb_p->x2sock_p->x2accept();

		// send nm msg
		for (int i = 0; i < nm; i++) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			auto buf = " iter  " + to_string(i);
			cout << "tid srv send " << thr_cb_p->tid << " " << buf << endl;
			thr_cb_p->x2sock_acpt_p->x2write(buf);
		}

	}
	catch (x2sock::x2err2_t& x2err2)
	{
		cout << "srv exception  caught " << x2err2.code << " " << x2err2.msg << endl;
	}

	thr_cb_p->x2sock_p->x2close();
	if (thr_cb_p->x2sock_p)delete(thr_cb_p->x2sock_p);	
	thr_cb_p->x2sock_acpt_p->x2close();
	if (thr_cb_p->x2sock_acpt_p)delete(thr_cb_p->x2sock_acpt_p);
};

void test02_thr::hello_cln(thr_cb* thr_cb_p) {

	auto port = 8120 + thr_cb_p->tid;
	auto thr_name = to_string(thr_cb_p->tid);

	try
	{
		thr_cb_p->x2sock_p = new x2sock(port);
		thr_cb_p->x2sock_p->x2connect();

		//receive nm msg
		while (true) {
			auto buf = thr_cb_p->x2sock_p->x2read();
			cout << "tid cln receive " << thr_cb_p->tid << " " << buf << endl;
			if (buf == "fin" || buf == "") break;
		}
	}
	catch (x2sock::x2err2_t& x2err2)
	{
		cout << "cln exception  caught " << x2err2.code <<" "<< x2err2.msg << endl;
	}
	thr_cb_p->x2sock_p->x2close();
	if (thr_cb_p->x2sock_p)delete(thr_cb_p->x2sock_p);
};

//todo pipe results to main thread 