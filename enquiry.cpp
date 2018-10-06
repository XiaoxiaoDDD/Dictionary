#include "dictionary.h"

using namespace std;

Enquiry::Enquiry(std::string input, std::vector<std::string> & dic)
		:input(input), dictionary(dic), n_word_found(0), n_comparison(0){
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

	if (c == '\0'){
		binary_search(result_list);
	}

	else if (c =='*'){
		incomplete_search(result_list, p, c);		
	}

	else if (c == '?'){
		incomplete_search(result_list, p, c);
	}
			

	std::cout << n_word_found <<" words found:"<<std::endl;

	for (int i = 0; i < n_word_found; i++){
		std::cout << * result_list[i] <<std::endl;
	}


	std::cout << n_comparison <<" comparisons carried out."<<std::endl;
	std::cout <<"--------------"<<std::endl;
}

		

Enquiry::~Enquiry(){
	;
}


