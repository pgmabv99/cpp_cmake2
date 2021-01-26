
#pragma once

#include <iostream>
//#include <filesystem>

#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <cstring>  
#include <string>
#include <algorithm>

#ifdef _WIN64
#include <direct.h>
#endif  



#pragma warning (disable:4996)

using namespace std;


class util {
public:
	// print collection
	template <class T>
	static void  print_col(T&  vl){
		for (auto v : *vl) {
			cout << v << " ";

		};
		cout << endl;
	}
	;

	//get current folder on win 
	static std::string get_current_dir();


};





#define X2_CRT cout << "constructor " << typeid(this).name() << ":"<< this << endl;
#define X2_DST cout << "destructor " << typeid(this).name() << ":"<< this << endl;

//todo relative file 
//to do link with get_curr dir fails

//build threads