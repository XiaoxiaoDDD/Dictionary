
// void Enquiry::wildcard_search(std::vector<std::string*> & result_list, int p, char & c){

// 	int first_occurance, last_occurance;
// 	first_occurance = -1;
// 	last_occurance = -1;
// 	int left;
// 	int right;
// 	int middle;
// 	left = 0;
// 	right = size - 1;

// 	//find the first occurance with the prefix
// 	while (left <= right) {
// 		n_comparison++;
// 		middle = (left + right)/ 2;

// 		if (input.substr(0,p).compare(dictionary[middle].substr(0,p)) > 0) {
// 			left = middle + 1;
// 		}
// 		else if (input.substr(0,p).compare(dictionary[middle].substr(0,p)) <= 0) {
// 			right = middle;
// 		}
// 		if (left == right) break;
// 	}
// 	if (left == right && dictionary[left].substr(0,p) == input.substr(0,p)){
// 		first_occurance = left;
// 	}

// 	//if there are at least one occurance, given the first occurance, find the rest of them:

// 	if (first_occurance != -1){

// 		int dynamic_index;
// 		dynamic_index = first_occurance;
// 		while (dictionary[dynamic_index].substr(0,p) == input.substr(0,p)){
// 			n_comparison++;
// 			n_word_found++;
// 			result_list.push_back(&dictionary[dynamic_index]);
// 			dynamic_index++;
// 		}
// 	}
// }

