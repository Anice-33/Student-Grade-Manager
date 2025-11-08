cmake_minimum_required(VERSION 3.16)
project(StudentManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StudentManager
        main.cpp
        student.cpp
        database.cpp
        utils.cpp
        database.cpp
        database.h
        utils.cpp
        utils.h
)