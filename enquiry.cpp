#include "dictionary.h"

using namespace std;

Enquiry::Enquiry(std::string input, std::vector<std::string> & dic)
		:input(input), dictionary(dic){
		size = dictionary.size();
		count = 0;

		int result = complete_search();
		std::cout << "the search result is " << result <<std::endl;
		if (result != -1){
			std::cout << dictionary[result]<<" is found.\n"<<count <<" comparisons carried out." <<std::endl;
		}
		else {
			std::cout << input <<" is not found.\n" <<count <<" comparisons carried out."<<std::endl;
		}
	}
			
		
int Enquiry::complete_search(){
	int left;
	int right;
	int middle;
	left = 0;
	right = size - 1;
	
	while (left <= right) {
		count++;
		middle = (left + right)/ 2;

		if (input.compare(dictionary[middle]) > 0) {
			left = middle + 1;
		}
		else if (input.compare(dictionary[middle]) < 0) {
			right = middle - 1;
		}
		else {
			return middle;
		}
	}
	return -1;
}


	
Enquiry::~Enquiry(){
	;
}


