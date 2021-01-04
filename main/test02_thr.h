#include "util.h"
#include "x2sock.h"

#include <thread>
#include <chrono>


class test02_thr {


	struct thr_cb {
		thread* thread_p;
		x2sock* x2sock_p;			//client connect or server listedn
		x2sock* x2sock_acpt_p;		//server accept   
		int tid;
	};

public:
	void test02_thr_run();
private:
	static void hello_srv(thr_cb* thr_cbp);	
	static void hello_cln(thr_cb* thr_cbp);
};