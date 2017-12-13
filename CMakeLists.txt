cmake_minimum_required(VERSION 3.8)
project(cpp_primer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        prog1.cc Sales_data.h ch07/Window_mgr.h ch07/Screen.h ch07/Screen.cpp ch07/Window_mgr.cpp ch11.cpp StrBlob.h StrBlob.cpp)

add_executable(cpp_primer ${SOURCE_FILES})
add_executable(ex3.23 ex3.23.cpp)
add_executable(binary_search binary_search.cpp)
add_executable(array array.cpp)
add_executable(ch08 ch08/ch0802.cpp)
add_executable(ch11 ch11.cpp)
add_executable(StrBlob StrBlob.cpp StrBlobPtr.cpp StrBlobPtr.h)
add_executable(TextQuery TextQuery.cpp TextQuery.h)
add_executable(ch13 ch13/HasPtrAsVal.cpp ch13/Folder.h ch13/Folder.cpp ch13/Message.h ch13/Message.cpp ch13/StrVec.cpp ch13/StrVec.h)
add_executable(ch15 ch15/Quote.h ch15/Quote.cpp ch15/Query_base.cpp ch15/Query_base.h TextQuery.cpp TextQuery.h)