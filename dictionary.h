#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

//class prototype
class Enquiry
{
private:
	std::string input;
	std::vector<std::string> & dictionary;
	int size;
	int n_comparison;
	int n_word_found;

public:
	Enquiry(std::string, std::vector<std::string> &);
	std::pair<char, int> pre_process();
	void myspeller (char, int);
	void binary_search( std::vector<std::string *>&);
	//void wildcard_search ( std::vector<std::string *>&, int, char &);
	void incomplete_search( std::vector<std::string *>&, int, char &);
	void find_first_occurance(int & , int & );
	void find_last_occurance(int & , int & );


	~Enquiry();
};

#endif 
