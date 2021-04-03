cmake_minimum_required(VERSION 2.8)
project(mydatabase)
add_library(databaselib SHARED DatabaseInterface.cpp file.cpp)