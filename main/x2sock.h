#pragma once
#include "util.h"
class x2sock {
public:
	x2sock(int n);
	~x2sock();
	void x2listen();
	x2sock* x2accept();
	void x2connect();
	void x2close();

	string x2read();
	void  x2write(std::string buf);

	enum x2err_t {
		X2_FAIL,
		X2CONNECT_FAIL,
		X2LISTEN_FAIL
	};

	class x2err2_t :public exception {
	public:
		x2err2_t(int code, string msg) {
			x2err2_t::msg = msg;
			x2err2_t::code = code;
		};
		string msg;
		int code;
	};

private:
	void* pi = nullptr;

};

