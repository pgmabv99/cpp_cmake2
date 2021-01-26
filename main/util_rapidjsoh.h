
#pragma once
#include "util.h"
#ifdef X2_OS_WIN
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\document.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\writer.h"
#include "C:\Users\alexe\source\repos\rapidjson\include\rapidjson\stringbuffer.h"
#elif X2_OS_LINUX  
#include "/home/azureuser/rapidjson/include/rapidjson/document.h"
#include "/home/azureuser/rapidjson/include/rapidjson/writer.h"
#include "/home/azureuser/rapidjson/include/rapidjson/stringbuffer.h"
#endif

using namespace rapidjson;

