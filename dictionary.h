#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <string>

//class prototype
class Enquiry
{
private:
	std::string input;
	std::vector<std::string> & dictionary;
	int size;

public:
	Enquiry(std::string, std::vector<std::string> &);
	std::pair<char, int> pre_process();
	void myspeller (char, int);
	void complete_search(int &, int &, std::vector<std::string *>&);
	void wildcard_search (int &, int &, std::vector<std::string *>&, int);


	~Enquiry();
};

#endif 
