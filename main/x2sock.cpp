#include "x2sock.h"
#include "util.h"
#include <thread>
#include <chrono>



#ifdef X2_OS_LINUX

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

#define X2_MAX_LEN 4096
struct x2socki_t {
	struct sockaddr_in sockaddr_in;
	int fd;				//listen or accept or connect
	char* cbuf;
	string buf;
	int cbuf_len;
	int port;
	int errno2;			//copy system errno	
	string  strerr2;	//err text
	int sock_rc;		//lateset socket call rc
};

void x2diag(void* pi, string text, int fd);

void x2diag(void* pi, string text, int fd) {

	x2socki_t* x2socki_p = (x2socki_t*)pi;
	x2socki_p->errno2 = errno;
	x2socki_p->strerr2.assign(strerror(x2socki_p->errno2));

	cout << std::this_thread::get_id()
		<< " " + text
		<< ":fd " << to_string(x2socki_p->fd)
		<< ":port " << to_string(x2socki_p->port)
		<< ":errno " + to_string(x2socki_p->errno2)
		<< ":strerr " + x2socki_p->strerr2
		<< endl;


	if (x2socki_p->errno2 != 0) throw  x2sock::x2err2_t(x2sock::X2_FAIL, "  fail " + text + ":" + x2socki_p->strerr2);

}


x2sock::x2sock(int port) {

	auto x2socki_p = new x2socki_t();
	pi = (void*)x2socki_p;
	x2socki_p->fd = 0;
	//get c buffer
	x2socki_p->cbuf = new char[X2_MAX_LEN];
	memset((void*)x2socki_p->cbuf, 0, X2_MAX_LEN);
	x2socki_p->port = port;
	x2socki_p->sock_rc = 0;
}

void x2sock::x2listen() {

	x2socki_t* x2socki_p = (x2socki_t*)pi;
	int rc;

	x2socki_p->fd = socket(AF_INET, SOCK_STREAM, 0);
	x2diag(pi, "listenfd socket created ", x2socki_p->fd);

	memset(&x2socki_p->sockaddr_in, 0, sizeof(sockaddr_in));
	x2socki_p->sockaddr_in.sin_family = AF_INET;
	x2socki_p->sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);
	x2socki_p->sockaddr_in.sin_port = htons(x2socki_p->port);

	x2socki_p->sock_rc = bind(x2socki_p->fd, (struct sockaddr*)&x2socki_p->sockaddr_in, sizeof(x2socki_p->sockaddr_in));
	x2diag(pi, "bind", x2socki_p->fd);

	x2socki_p->sock_rc = listen(x2socki_p->fd, 10);
	x2diag(pi, "listen", x2socki_p->fd);


}

x2sock* x2sock::x2accept() {

	x2socki_t* x2socki_p = (x2socki_t*)pi;

	//new x2sock instance
	x2sock* x2sock_acpt_p = new x2sock(0);
	x2socki_t* x2socki_acpt_p = (x2socki_t*)x2sock_acpt_p->pi;

	x2socki_acpt_p->fd = accept(x2socki_p->fd, (struct sockaddr*)NULL, NULL);
	x2diag(pi, "accept", x2socki_acpt_p->fd);
	return x2sock_acpt_p;
}


void x2sock::x2connect() {

	x2socki_t* x2socki_p = (x2socki_t*)pi;
	char  host[11] = "localhost";

	x2socki_p->fd = socket(AF_INET, SOCK_STREAM, 0);
	x2diag(pi, "socket create  ", x2socki_p->fd);

	memset(&x2socki_p->sockaddr_in, 0, sizeof(sockaddr_in));
	x2socki_p->sockaddr_in.sin_family = AF_INET;
	x2socki_p->sockaddr_in.sin_port = htons(x2socki_p->port);

	x2socki_p->sock_rc = inet_pton(AF_INET, host, &x2socki_p->sockaddr_in.sin_addr);
	x2diag(pi, "inet_pton", 0);

	x2socki_p->sock_rc = connect(x2socki_p->fd, (struct sockaddr*)&x2socki_p->sockaddr_in, sizeof(x2socki_p->sockaddr_in));
	x2diag(pi, "socket   connect", x2socki_p->fd);

}

void x2sock::x2close() {
	x2socki_t* x2socki_p = (x2socki_t*)pi;

	if (x2socki_p->fd != 0)close(x2socki_p->fd);
}

void x2sock::x2write(string buf) {
	x2socki_t* x2socki_p = (x2socki_t*)pi;

	memset((void*)x2socki_p->cbuf, 0, X2_MAX_LEN);
	strncpy(x2socki_p->cbuf, buf.c_str(), X2_MAX_LEN);
	x2socki_p->cbuf_len = strlen(buf.c_str());
	auto rc = write(x2socki_p->fd, x2socki_p->cbuf, x2socki_p->cbuf_len);
	x2diag(pi, "socket  write", x2socki_p->fd);
}

string x2sock::x2read() {
	x2socki_t* x2socki_p = (x2socki_t*)pi;

	memset((void*)x2socki_p->cbuf, 0, X2_MAX_LEN);
	x2socki_p->sock_rc = read(x2socki_p->fd, x2socki_p->cbuf, X2_MAX_LEN - 1);
	x2diag(pi, "socket  read", x2socki_p->fd);
	x2socki_p->buf.assign(x2socki_p->cbuf);
	return x2socki_p->buf;
}




x2sock::~x2sock() {

	x2socki_t* x2socki_p = (x2socki_t*)pi;

}




#endif

#ifdef X2_OS_WIN

//#include <sys/types.h>
//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#include <errno.h>
//#include <ws2def.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>



x2sock::x2sock(int port) {

	//auto x2socki_p = new x2socki_t();
	//pi = (void*)x2socki_p;
	//x2socki_p->fd = 0;
	////get c buffer
	//x2socki_p->cbuf = new char[X2_MAX_LEN];
	//memset((void*)x2socki_p->cbuf, 0, X2_MAX_LEN);
	//x2socki_p->port = port;
	//x2socki_p->sock_rc = 0;
}

void x2sock::x2listen() {

	//x2socki_t* x2socki_p = (x2socki_t*)pi;
	//int rc;

	//x2socki_p->fd = socket(AF_INET, SOCK_STREAM, 0);
	//x2diag(pi, "listenfd socket created ", x2socki_p->fd);

	//memset(&x2socki_p->sockaddr_in, 0, sizeof(sockaddr_in));
	//x2socki_p->sockaddr_in.sin_family = AF_INET;
	//x2socki_p->sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);
	//x2socki_p->sockaddr_in.sin_port = htons(x2socki_p->port);

	////x2socki_p->sock_rc = bind(x2socki_p->fd, (struct sockaddr*)&x2socki_p->sockaddr_in, sizeof(x2socki_p->sockaddr_in));
	//x2diag(pi, "bind", x2socki_p->fd);

	//x2socki_p->sock_rc = listen(x2socki_p->fd, 10);
	//x2diag(pi, "listen", x2socki_p->fd);


}

x2sock* x2sock::x2accept() {

	//x2socki_t* x2socki_p = (x2socki_t*)pi;

	////new x2sock instance
	//x2sock* x2sock_acpt_p = new x2sock(0);
	//x2socki_t* x2socki_acpt_p = (x2socki_t*)x2sock_acpt_p->pi;

	////x2socki_acpt_p->fd = accept(x2socki_p->fd, (struct sockaddr*)NULL, NULL);
	//x2diag(pi, "accept", x2socki_acpt_p->fd);
	//return x2sock_acpt_p;
	return nullptr;
}


void x2sock::x2connect() {

	//x2socki_t* x2socki_p = (x2socki_t*)pi;
	//char  host[11] = "localhost";

	////x2socki_p->fd = socket(AF_INET, SOCK_STREAM, 0);
	//x2diag(pi, "socket create  ", x2socki_p->fd);

	//memset(&x2socki_p->sockaddr_in, 0, sizeof(sockaddr_in));
	//x2socki_p->sockaddr_in.sin_family = AF_INET;
	//x2socki_p->sockaddr_in.sin_port = htons(x2socki_p->port);

	////x2socki_p->sock_rc = inet_pton(AF_INET, host, &x2socki_p->sockaddr_in.sin_addr);
	//x2diag(pi, "inet_pton", 0);

	////x2socki_p->sock_rc = connect(x2socki_p->fd, (struct sockaddr*)&x2socki_p->sockaddr_in, sizeof(x2socki_p->sockaddr_in));
	//x2diag(pi, "socket   connect", x2socki_p->fd);

}

void x2sock::x2close() {
//	x2socki_t* x2socki_p = (x2socki_t*)pi;
//
//	//if (x2socki_p->fd != 0)close(x2socki_p->fd);
}

void x2sock::x2write(string buf) {
	//x2socki_t* x2socki_p = (x2socki_t*)pi;

	//memset((void*)x2socki_p->cbuf, 0, X2_MAX_LEN);
	//strncpy(x2socki_p->cbuf, buf.c_str(), X2_MAX_LEN);
	//x2socki_p->cbuf_len = strlen(buf.c_str());
	////auto rc = write(x2socki_p->fd, x2socki_p->cbuf, x2socki_p->cbuf_len);
	//x2diag(pi, "socket  write", x2socki_p->fd);
}

string x2sock::x2read() {
	//x2socki_t* x2socki_p = (x2socki_t*)pi;

	//memset((void*)x2socki_p->cbuf, 0, X2_MAX_LEN);
	////x2socki_p->sock_rc = read(x2socki_p->fd, x2socki_p->cbuf, X2_MAX_LEN - 1);
	//x2diag(pi, "socket  read", x2socki_p->fd);
	//x2socki_p->buf.assign(x2socki_p->cbuf);
	//return x2socki_p->buf;
	return nullptr;
}




x2sock::~x2sock() {

	/*x2socki_t* x2socki_p = (x2socki_t*)pi;*/

}





#endif



