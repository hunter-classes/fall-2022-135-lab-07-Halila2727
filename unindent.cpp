/*
    Author: Halil Akca
    Course: CSCI-135
    Instructor: Zamansky
    Assignment: Lab 7A
    This program will unindent and remove leading spaces.
*/
#include <iostream>
#include <string>
#include <fstream>

std::string removeLeadingSpaces(std::string line)
{
    while(line.substr(0, 1) == " ")
    {
        line = line.substr(1);
    }

    return line;
}

void unindent(std::string nameOfFile)
{
    std::string s = "";
    std::string f = "";

    std::ifstream fin(nameOfFile);
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1); // exit if failed to open the file
	}
    
    if (fin.is_open())
    {
        while(getline(fin, s))
        {
            f += removeLeadingSpaces(s) + "\n";
        }
        fin.close(); //close the file object.
    }

    std::ofstream myFile("good-code.cpp");
    myFile << f;
    myFile.close();

    std::cout << "File after unindenting:\n\n" << f << "\n";
}