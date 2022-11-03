/*
    Author: Halil Akca
    Course: CSCI-135
    Instructor: Zamansky
    Assignment: Lab 7B
    This program will indent as needed.
*/
#include <iostream>
#include <string>
#include <fstream>

int countChar(std::string line, char c)
{
    int count = 0;
    for(int i=0; i<line.length(); i++)
    {
        if(line[i] == c)
        {
            count++;
        }
    }

    return count;
}

void indent(std::string nameOfFile)
{
    std::string s = "";
    std::string f = "";

    std::ifstream fin(nameOfFile);
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1); // exit if failed to open the file
	}

    int current = 0;
    std::string tab = " ";
    
    if (fin.is_open())
    {
        while(getline(fin, s))
        {
            if(!(countChar(s, '{')>0 && countChar(s, '}')>0))
            {
                if(countChar(s, '}') > 0)
                {
                    current--;
                }
            }
            for(int i=0; i<current; i++)
            {
                f += tab;
            }
            
            
            current += countChar(s, '{');
            current -= countChar(s, '}');

            f += s + "\n";
        }
        fin.close(); //close the file object.
    }

    std::ofstream myFile("good-code.cpp");
    myFile << f;
    myFile.close();

    std::cout << "File after indenting:\n\n" << f << "\n";
}