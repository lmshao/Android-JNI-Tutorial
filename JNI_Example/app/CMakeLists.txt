cmake_minimum_required(VERSION 3.4.1)

set(SRC_LIST
    src/main/cpp/native-lib.cpp
    src/main/cpp/CppSource.cpp)

add_library(native-lib SHARED ${SRC_LIST})

find_library(log-lib log)

target_link_libraries(native-lib ${log-lib})