#include "dictionary.h"
#include <stdlib.h>

//read from the file and put the words into the vector
std::vector<std::string> readDic(char * dictionary_name){    //read the whole dictionary and put it into a dynamic array

	std::vector<std::string> word_list;
	std::string line;

	std::ifstream dic(dictionary_name);

	if (dic.is_open()){
		while ( std::getline(dic, line)){
			if(line[line.length() - 1] == '\r') {
				line = line.substr(0, line.length() - 1);
			}
			word_list.push_back(line);
			// std::cout << line;
		}
		dic.close();
	}
	else{
		std::cout <<"the dictionay does not exist"<<std::endl;
	}
	
	return word_list;
}

int main(int argc, char * argv[]){

	// std::cout <<"start \n";

	char * dictionary_name;
	dictionary_name = "default";
	int limit;
	limit = -1;


	for (int i = 0; i < argc; i++){
		if (strcmp(argv[i],"-d")==0){
			dictionary_name = argv[++i];
		}
		else if (strcmp(argv[i],"-l")==0){
			limit = atoi(argv[++i]);
		}
	}

	if (dictionary_name =="default" || limit == -1){
		std::cout <<"mymachine-promt >> ./myspeller -d <dictionary> -l <numofwordsinoutput>"<<std::endl;
		return EXIT_FAILURE;
	}

	std::vector<std::string> dic;
	dic=readDic(dictionary_name);

	//int size = dic.size();

	std::cout <<"Welcome to mySpeller. Please enter the word to search. Enter exit to quit the program."<<std::endl;

	std::string input;
	std::cin >> input;

	while (input !="exit"){
		Enquiry enquiry( input, dic, limit );
		std::cout <<"Enter the word to search. Enter exit to quit the program."<<std::endl;
		std::cin >> input;
	}

	return 0;

}
