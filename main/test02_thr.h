#include "util.h"
#include <thread>
#include <chrono>

class test02_thr {

public:
	void test02_thr_run(); 
private:
	static void hello(int tid);
};