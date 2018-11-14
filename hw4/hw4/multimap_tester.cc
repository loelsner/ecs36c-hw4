// multimap_tester.cc

#include "llrb_multimap.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

	/* ORIGINAL TEST: 1 item lists */
	LLRB_multimap<int, std::string> llrb1;
	std::vector<std::string> str_vector = { "Priscilla", "and", "Laura", "are", "awesome af" };
	int i = 0;
	for (std::string str_i : str_vector) {
		llrb1.Insert(i, str_i);
		++i;
	}
	llrb1.Print();

	/* Remove Test */
	llrb1.Remove(1);
	llrb1.Remove(2);
	llrb1.Print();

	/* Test random insertion in Multiple List Sizes */
	LLRB_multimap<char, double> llrb2;
	llrb2.Insert('N', 4.0);
	llrb2.Insert('D', -5.0);
	llrb2.Insert('N', 37);
	llrb2.Insert('G', 3.5);
	llrb2.Insert('G', -99);
	llrb2.Insert('G', 13.4);
	llrb2.Insert('G', 3.5);
	llrb2.Insert('Z', 100);
	llrb2.Insert('A', 0.1);
	llrb2.Insert('F', -23.056);

	llrb2.Print();

	/* Test other functions */
	llrb2.Print();
	std::cout << "Size of tree: " << llrb2.Size() << std::endl;
	std::cout << "Tree contains 'N'? " << std::boolalpha << llrb2.Contains('N') << std::endl;
	std::cout << "Tree contains 'M'? " << std::boolalpha << llrb2.Contains('M') << std::endl;
	std::cout << "Min of Tree: " << llrb2.Min() << std::endl;
	std::cout << "Remove A" << std::endl;
	llrb2.Remove('A');
	llrb2.Print();
	std::cout << "Min of Tree: " << llrb2.Min() << std::endl;
	std::cout << "Max of Tree: " << llrb2.Max() << std::endl;
	std::cout << "Remove Z" << std::endl;
	llrb2.Remove('Z');
	llrb2.Print();
	std::cout << "Max of Tree: " << llrb2.Max() << std::endl;
	std::cout << "Remove G" << std::endl;
	llrb2.Remove('G');
	llrb2.Print();

	/* Testing Errors */
	std::cout << "Remove Y" << std::endl;
	llrb2.Remove('Y'); // TODO: Make an exception for this
	llrb2.Print();


	return 0;
}