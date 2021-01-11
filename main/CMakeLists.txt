cmake_minimum_required (VERSION 3.8)
message(STATUS " CMAKE_SYSTEM_NAME ${CMAKE_SYSTEM_NAME}")
# Add source to this project's executable.
add_executable (test01
"main.cpp"
"test02_thr.cpp"
"util.cpp" 
 "x2sock.cpp" "x2sock.h"
 "test.h"
 "test_triplets.cpp"  
 "test_arr_dist.cpp"
 "test_maxabssum.cpp" 
 "test_tree.cpp" 
 "test_hrt.cpp" 
 "test_maxk.cpp" 
 "test_uniqptr.cpp" 
 #"test_pimpl.cpp"
 )
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
add_definitions(-DX2_OS_LINUX)
target_link_libraries(test01 -lpthread)
else()
add_definitions(-DX2_OS_WIN)
endif()

