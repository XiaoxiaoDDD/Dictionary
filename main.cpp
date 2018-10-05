#include "dictionary.h"

//class prototype
class Enquiry(std::string input, std::vector<string> & dic);


//read from the file and put the words into the vector
std::vector<std::string> readDic(std::string dictionary_name){    //read the whole dictionary and put it into a dynamic array

	std::vector<std::string> word_list;
	std::string line;

	std::ifstream dic(dictionary_name);

	if (dic.is_open()){
		while ( std::getline(dic, line)){
			word_list.push_back(line);
			// std::cout << line <<std::endl;
		}
		dic.close();
	}
	
	return word_list;
}

int main(){

	// std::cout <<"start \n";

	std::vector<std::string> dic;
	dic=readDic("Dictionary141words.txt");

	//int size = dic.size();

	std::cout <<"Welcome to the dictionary. Please enter the word to search. Enter exit to quit the program."<<std::endl;

	std::string input;
	std::cin >> input;

	while (not input =="exit"){
		Enquiry enquiry( input, dic );
		std::cout <<"Please enter the word to search. Enter exit to quit the program."<<std::endl;
		std::cin >> input;
	}

	return 0;

}
