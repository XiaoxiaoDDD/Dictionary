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
	int count;

public:
	Enquiry(std::string, std::vector<std::string> &);
	int complete_search();
	int quesiton_mark();

	~Enquiry();
};

#endif 
