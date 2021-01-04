#pragma once
#include "util.h"
class x2sock {
public:
	x2sock(int n);
	~x2sock();
	void x2accept();
	void x2connect();
	void x2close();

	string x2read();
	void  x2write(std::string buf);

private:
	void* pi = nullptr;

};

