
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cstring>  
#include <string>
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\document.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\writer.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\stringbuffer.h"

#pragma warning (disable:4996)

using namespace std;

class util {
public:

	template <class T>
	static void  print_v(vector<T>* vl);

};

template <class T>
void  util::print_v(vector<T>* vl) {
	for (auto v : *vl) {
		cout << v << " ";

	};
	cout << endl;
}


//todo move cpp tp separe file
//build threads