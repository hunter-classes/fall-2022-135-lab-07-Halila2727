/*
  Author: Halil Akca
  Course: CSCI-135
  Instructor: Mike Zamansky
  Assignment: Lab 07
  This program will call the functions made in other .cpp files
*/

#include <iostream>
#include <string>
#include "indent.h"
#include "unindent.h"

int main()
{
  std::string nameOfFile;

  std::cout << "\nEnter the file name (should be bad-code.cpp): ";
  std::cin >> nameOfFile;


  std::cout << "\n";
  unindent(nameOfFile);
  std::cout << "\n";
  indent("good-code.cpp");
  std::cout << "\n";
}