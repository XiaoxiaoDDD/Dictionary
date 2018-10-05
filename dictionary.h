#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <vector>

//class prototype
class Enquiry
{
private:
	std::string input;
	std::vector<std::string> & dictionary;

public:
	Enquiry(std::string, std::vector<std::string> &);

	~Enquiry();
};

#endif 
