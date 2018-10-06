#include "dictionary.h"

using namespace std;

Enquiry::Enquiry(std::string input, std::vector<std::string> & dic)
		:input(input), dictionary(dic){
		size = dictionary.size();

		std::pair<char, int> instruction = pre_process(); //determine the type of enquiry: complete word, wildcard, or ?

		myspeller(instruction.first, instruction.second);
	}

// pre_prosess identifies the type of the enquiry and the position of * and ?
std::pair<char, int> Enquiry::pre_process() {
	for (int i = 0; i < size; i++){
		if (input[i] == '*'){
			std::pair<char,int> p('*', i);
			std::cout <<"wildcard"<<std::endl;
			return p;
		}
		if (input[i] == '?'){
			std::pair<char,int> p('?', i);
			std::cout <<"question" <<std::endl;
			return p;
		}
	}
	std::pair<char,int> p('\0', -1);
	std::cout <<"complete"<< std::endl;
	return p;
}

//myspeller processes the enquires

void Enquiry::myspeller(char c, int p){  //c is the enquiry type, p is the position where * and ? appear
	std::vector<std::string *> result_list;
	int n_comparison;
	n_comparison = 0;
	int n_word_found;
	n_word_found = 0;
	if (c == '\0'){
		complete_search(n_word_found, n_comparison, result_list);
	}

	else if (c =='*'){
		wildcard_search(n_word_found, n_comparison, result_list, p);
		

	}

	else if (c == '?'){
		;
		// here insert codes that deal with enquires with ?


	}
			

	std::cout << n_word_found <<" words found:"<<std::endl;

	for (int i = 0; i < n_word_found; i++){
		std::cout << * result_list[i] <<std::endl;
	}


	std::cout << n_comparison <<" comparisons carried out."<<std::endl;
	std::cout <<"--------------"<<std::endl;
}

		
void Enquiry::complete_search(int & n_word_found, int & comparison_count, std::vector<std::string *> & result_list){
	int left;
	int right;
	int middle;
	int index_found;
	index_found = -1;
	left = 0;
	right = size - 1;
	
	while (left <= right) {
		comparison_count++;
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

void Enquiry::wildcard_search(int & n_word_found, int & comparison_count, std::vector<std::string*> & result_list, int p){

	int first_occurance, last_occurance;
	first_occurance = -1;
	last_occurance = -1;
	int left;
	int right;
	int middle;
	left = 0;
	right = size - 1;

	
	while (left <= right) {
		comparison_count++;
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

	if (first_occurance != -1){
		int dynamic_index;
		dynamic_index = first_occurance;
		while (dictionary[dynamic_index].substr(0,p) == input.substr(0,p)){
			comparison_count++;
			n_word_found++;
			result_list.push_back(&dictionary[dynamic_index]);
			dynamic_index++;
		}

	}

}


	
Enquiry::~Enquiry(){
	;
}


