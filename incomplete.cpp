#include "dictionary.h"

void Enquiry::incomplete_search(std::vector<std::string*> & result_list, int p, char & c){

	int first_occurance;
	int last_occurance;
	first_occurance = -1;
	last_occurance = -1;

	//find the first occurance with the prefix	
	find_first_occurance(first_occurance,p);
	find_last_occurance(last_occurance,p);


	if (c == '?'){
		int len;
		len = input.length();

		int dynamic_index;
		dynamic_index = first_occurance;
		while (dynamic_index <= last_occurance){
			if (len == dictionary[dynamic_index].length() && \
				input.substr(p+1, len-p-1) == dictionary[dynamic_index].substr(p+1, len-p-1))
			{
				n_word_found++;
				result_list.push_back(&dictionary[dynamic_index]);
				dynamic_index++;
			}
		}
	}

	if (c =='*'){
		if (first_occurance != -1){
			int dynamic_index;
			dynamic_index = first_occurance;
			while (dynamic_index <= last_occurance){
				n_word_found++;
				result_list.push_back(&dictionary[dynamic_index]);
				dynamic_index++;
			}
		}
	}
}

void Enquiry::binary_search(std::vector<std::string *> & result_list){
	int left;
	int right;
	int middle;
	int index_found;
	index_found = -1;
	left = 0;
	right = size - 1;
	
	while (left <= right) {
		n_comparison++;
		middle = (left + right)/ 2;

		if (input.compare(dictionary[middle]) > 0) {
			left = middle + 1;
		}
		else if (input.compare(dictionary[middle]) < 0) {
			right = middle - 1;
		}
		else {
			index_found = middle;	
			// std::cout <<"found!!!yes!!" <<std::endl;
			break;
		}
	}

	if (index_found == -1){
		n_word_found = 0;
	}
	else{
		// std::cout <<"the index is "<<index_found << std::endl;
		result_list.push_back(&dictionary[middle]);
		n_word_found = 1;
	}

}


//find the first occurance with the prefix
void Enquiry::find_first_occurance(int & first_occurance, int & p){
	int left = 0;
	int right = size - 1;
	int middle;

	while (left <= right) {
		n_comparison++;
		middle = (left + right)/ 2;

		if (input.substr(0,p).compare(dictionary[middle].substr(0,p)) > 0) {
			left = middle + 1;
		}
		else if (input.substr(0,p).compare(dictionary[middle].substr(0,p)) <= 0) {
			right = middle;
		}
		if (left == right) break;
	}
	if (left == right && dictionary[left].substr(0,p) == input.substr(0,p)){
		first_occurance = left;

	}

}


//find the last occurance with the prefix
void Enquiry::find_last_occurance(int & last_occurance, int & p){

	int left = 0;
	int right = size - 1;
	int middle;

	
	while (left <= right) {
		n_comparison++;
		middle = (left + right + 1)/ 2;

		if (input.substr(0,p).compare(dictionary[middle].substr(0,p)) >= 0) {
			left = middle;
		}
		else if (input.substr(0,p).compare(dictionary[middle].substr(0,p)) < 0) {
			right = middle - 1;
		}
		if (left == right) {
			break;
		}
	}

	if (left == right && dictionary[left].substr(0,p) == input.substr(0,p)){
		last_occurance = left;
	}


}