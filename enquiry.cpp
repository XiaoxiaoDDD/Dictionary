#include "dictionary.h"

Enquiry::Enquiry(std::string input, std::vector<std::string> & dic)
		:input(input), dictionary(dic){
		std::cout <<"the input is " <<input<< std::endl;
	}
	
Enquiry::~Enquiry(){
	;
}


