#pragma once

class x2sock {
public:
	x2sock(int n);
	void sock_accept();
	~x2sock();
private:
	void* pi=nullptr;


};

