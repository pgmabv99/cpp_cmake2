﻿
#pragma once

#include <iostream>
#include <filesystem>

#include <fstream>
#include <vector>
#include <list>
#include <cstring>  
#include <string>
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\document.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\writer.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\stringbuffer.h"

#include <direct.h>

#pragma warning (disable:4996)

using namespace std;


class util {
public:
	// print vectors
	template <class T>
	static void  print_v(vector<T>* vl);
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



//todo relative file 
//to do link with get_curr dir fails

//build threads