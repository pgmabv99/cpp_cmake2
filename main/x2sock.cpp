#include "x2sock.h"
#include "util.h"


#ifdef __linux
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

struct x2socki_t {
	struct sockaddr_in sockaddr_in;
	int listenfd;
	int acceptfd;
};

x2sock::x2sock(int port) {

	auto x2socki_p = new x2socki_t();
	pi = (void*)x2socki_p;
	x2socki_p->listenfd = socket(AF_INET, SOCK_STREAM, 0);
	cout << x2socki_p->listenfd << endl;

	memset(&x2socki_p->sockaddr_in, 0, sizeof(sockaddr_in));
	x2socki_p->sockaddr_in.sin_family = AF_INET;
	x2socki_p->sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);
	x2socki_p->sockaddr_in.sin_port = htons(5000);

	bind(x2socki_p->acceptfd, (struct sockaddr*)&x2socki_p->sockaddr_in, sizeof(x2socki_p->sockaddr_in));


}

void x2sock::sock_accept() {

	x2socki_t* x2socki_p = (x2socki_t*)pi;

	bind(x2socki_p->acceptfd, (struct sockaddr*)&x2socki_p->sockaddr_in, sizeof(x2socki_p->sockaddr_in));


}

x2sock::~x2sock() {

	x2socki_t* x2socki_p = (x2socki_t*)pi;

}
#else
x2sock::x2sock(int n) {
	pi = nullptr;
}



void x2sock::sock_accept() {

}
x2sock::~x2sock() {

	auto x2socki_p = pi;

}
#endif

