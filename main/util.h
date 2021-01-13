
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
#ifdef X2_OS_WIN
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\document.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\writer.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\stringbuffer.h"
#elif X2_OS_LINUX  
#include "/home/azureuser/rapidjson/include/rapidjson/document.h"
#include "/home/azureuser/rapidjson/include/rapidjson/writer.h"
#include "/home/azureuser/rapidjson/include/rapidjson/stringbuffer.h"
#endif

#ifdef _WIN64
#include <direct.h>
#endif  



#pragma warning (disable:4996)

using namespace std;
using namespace rapidjson;


class util {
public:
	// print vectors
	template <class T>
	static void  print_v(vector<T>* vl);	

	template <class T>
	static void  print_col(T&  vl);


	template <class T>
	static void  print_vs(shared_ptr<vector<T>>&  vl);

	template <class T>
	static void  print_l(list<T>* vl);
	//get current folder on win 
	static std::string get_current_dir();


};

//template def must be same file as temp;ate declaration
template <class T>
void  util::print_v(vector<T>* vl) {
	for (auto v : *vl) {
		cout << v << " ";

	};
	cout << endl;
}

template <class T>
void  util::print_l(list<T>* vl) {
	for (auto v : *vl) {
		cout << v << " ";

	};
	cout << endl;
}


template <class T>
void  util::print_col(T& vl) {
	for (auto v : *vl) {
		cout << v << " ";

	};
	cout << endl;
}





#define X2_CRT cout << "constructor " << typeid(this).name() << ":"<< this << endl;
#define X2_DST cout << "destructor " << typeid(this).name() << ":"<< this << endl;

//todo relative file 
//to do link with get_curr dir fails

//build threads