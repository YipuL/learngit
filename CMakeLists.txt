cmake_minimum_required(VERSION 3.17)
project(learn)

set(CMAKE_CXX_STANDARD 14)

find_package( Poco REQUIRED Foundation)
include_directories( ${Poco_INCLUDE_DIRS} )

add_executable(learn ping.cpp ip.cpp main.cpp ip_config.cpp)
target_link_libraries(learn Poco::Foundation)