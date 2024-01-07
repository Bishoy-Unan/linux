


#minimum version required to start cmake
Cmake_minimum_required (VERSION 3.2...3.7)

#project name and description to the project
Project (Calculator
	DESCRIPTION "Calculator Project"
	LANGUAGES	C) 

# to create the librar operation that would be link with the file main.c 
add_library(operation STATIC Lib/addition.c Lib/division.c Lib/modulus.c Lib/multiplication.c Lib/subtraction.c)

#include the files that the operation library needs
target_include_directories(operation INTERFACE Include)


#to create the executable
add_executable(${PROJECT_NAME} main.c)

#link the library with main.c
target_link_libraries(${PROJECT_NAME} PUBLIC operation)
