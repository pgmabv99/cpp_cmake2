#pragma once
#include "util.h"
class x2sock {
public:
	x2sock(int n);
	void x2accept();
	void x2connect();
	std::string x2read();
	void  x2write(std::string buf);
	void x2close();
	~x2sock();
#define X2_MAX_LEN 4096
private:
	void* pi = nullptr;


};

