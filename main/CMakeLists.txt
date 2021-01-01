cmake_minimum_required (VERSION 3.8)
message(STATUS " CMAKE_SYSTEM_NAME ${CMAKE_SYSTEM_NAME}")
# Add source to this project's executable.
add_executable (test01
"main.cpp"
"test02_thr.cpp"
"util.cpp" 
 "x2sock.cpp" "x2sock.h")
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
target_link_libraries(test01 -lpthread)
endif()

