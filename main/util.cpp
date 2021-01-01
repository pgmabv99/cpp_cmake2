
#include "util.h"

#ifdef __WIN64
std::string get_current_dir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	_getcwd(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}
#else
std::string get_current_dir() {
	string current_working_dir(" not_supported");
	return current_working_dir;
}

#endif


