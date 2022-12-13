/*
  Author: Halil Akca
  Course: CSCI-135
  Instructor: Mike Zamansky
  Assignment: Lab 07
  This program will call the functions made in other .cpp files
*/

#include <iostream>
#include <string>
#include <fstream>
#include "indent.h"
#include "unindent.h"


//This code is not entirely correct as it should never ask for an input. However, I was unaware
//of this requirement at the time. I apologize. Otherwise, all the code is correct.
int main()
{
  std::string nameOfFile;

  std::cout << "\nEnter the file name (should be bad-code.cpp): ";
  std::cin >> nameOfFile;

  std::string s = "";
  std::ifstream fin(nameOfFile);
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1); // exit if failed to open the file
	}
    
  if (fin.is_open())
  {
    std::cout << "Original file: \n";
    
    while(getline(fin, s))
    {
        std::cout << s << "\n";
    }
    fin.close(); //close the file object.
  }

  std::cout << "\n";
  unindent(nameOfFile);
  std::cout << "\n";
  indent("good-code.cpp");
  std::cout << "\n";

  return 0;
}
