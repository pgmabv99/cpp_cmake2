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

	auto x2sockip = new x2socki_t();
	pi = (void*)x2sockip;
	x2sockip->listenfd = socket(AF_INET, SOCK_STREAM, 0);
	cout << x2sockip->listenfd << endl;

	memset(&x2sockip->sockaddr_in, 0, sizeof(sockaddr_in));
	x2sockip->sockaddr_in.sin_family = AF_INET;
	x2sockip->sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);
	x2sockip->sockaddr_in.sin_port = htons(5000);

	bind(x2sockip->acceptfd, (struct sockaddr*)&x2sockip->sockaddr_in, sizeof(x2sockip->sockaddr_in));


}

void x2sock::sock_accept() {

	x2socki_t* x2sockip = (x2socki_t*)pi;

	bind(x2sockip->acceptfd, (struct sockaddr*)&x2sockip->sockaddr_in, sizeof(x2sockip->sockaddr_in));


}

x2sock::~x2sock() {

	x2socki_t* x2sockip = (x2socki_t*)pi;

}
#else
x2sock::x2sock(int n) {
	pi = nullptr;
}

void x2sock::sock_accept() {

}
x2sock::~x2sock() {

	auto x2socki = pi;

}
#endif

