// map_tester.cc

#include "llrb_map.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

	/* ORIGINAL TEST with two different types of keys and values */
	LLRB_map<int, std::string> llrb1;
	std::vector<std::string> str_vector = { "Priscilla", "and", "Laura", "are", "really awesome" };

	int i = 0;
	for (std::string str_i : str_vector) {
		llrb1.Insert(i, str_i);
		++i;
	}

	std::cout << "Printing first tree:" << std::endl;
	llrb1.Print();

	/* Remove Test */
	std::cout << "Removing node 1" << std::endl;
	llrb1.Remove(1);
	std::cout << "Removing node 2" << std::endl;
	llrb1.Remove(2);
	llrb1.Print();

	/* Test random insertion (with different types) in second tree*/
	std::cout << std::endl << "Printing second tree:" << std::endl;
	LLRB_map<char, double> llrb2;
	llrb2.Insert('N', 4.0);
	llrb2.Insert('D', -5.0);
	llrb2.Insert('G', 3.5);
	llrb2.Insert('Z', 100);
	llrb2.Insert('A', 0.1);
	llrb2.Insert('F', -23.056);

	llrb2.Print();

	/* Test other functions */
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
	try {
		std::cout << "Remove Y" << std::endl;
		llrb2.Remove('Y'); // TODO: Make an exception for this
		llrb2.Print();
	}
	catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl << std::endl;
	}
	

	/* Testing third tree with one node with key & value being same type */
	std::cout << std::endl << "Printing third tree:" << std::endl;
	LLRB_map<int, int> llrb3;
	llrb3.Insert(24, -914);

	llrb3.Print();

	std::cout << "Size of Tree: " << llrb3.Size() << std::endl;
	std::cout << "Min of Tree: " << llrb3.Min() << std::endl;
	std::cout << "Max of Tree: " << llrb3.Max() << std::endl;

	std::cout << "Remove the only node";
	llrb3.Remove(24);
	llrb3.Print();

	std::cout << "Size of Tree: " << llrb3.Size() << std::endl;
	try {
		std::cout << "Min of Tree: " << std::endl;
		std::cout << llrb3.Min() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Max of Tree: " << std::endl;
		std::cout << llrb3.Max() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl;
	}

	std::cout << "Inserting a node (56, 7): " << std::endl;
	llrb3.Insert(56, 7);
	llrb3.Print();
	
	std::cout << "Size of Tree: " << llrb3.Size() << std::endl;
	std::cout << "Min of Tree: " << llrb3.Min() << std::endl;
	std::cout << "Max of Tree: " << llrb3.Max() << std::endl;

	std::cout << "Inserting a node (-3, 34): " << std::endl;
	llrb3.Insert(-3, 34);
	llrb3.Print();

	std::cout << "Size of Tree: " << llrb3.Size() << std::endl;
	std::cout << "Min of Tree: " << llrb3.Min() << std::endl;
	std::cout << "Max of Tree: " << llrb3.Max() << std::endl;

	std::cout << "Testing insertion of an existing key." << std::endl;
	try {
		llrb3.Insert(-3, 3.4);
	}
	catch (std::exception &e) {
		std::cout << "Expected exception: " << e.what() << std::endl << std::endl;
	}

	return 0;
}
