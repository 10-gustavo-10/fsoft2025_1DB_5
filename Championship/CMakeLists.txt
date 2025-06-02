cmake_minimum_required(VERSION 3.14)
project(Championship)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

file(GLOB_RECURSE SOURCES "sources/*.cpp")

add_executable(Championship main.cpp ${SOURCES}
        headers/model/Players.h
        sources/model/Players.cpp
        headers/model/Cards.h
        sources/model/Cards.cpp
        headers/model/Referee.h
        sources/model/Referee.cpp
        headers/model/Stadium.h
        sources/model/Stadium.cpp)
