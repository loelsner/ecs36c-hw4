// map_tester.cc

#include <llrb_map.h>

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	LLRB_map<int, std::string> llrb1;
	std::vector<std::string> str_vector = { "Priscilla", "and", "Laura", "are", "awesome" };
	int i = 0;
	for (std::string str_i : str_vector) {
		llrb1.Insert(i, str_i);
		++i;
	}
	llrb1.Print();
	
	return 0;
}