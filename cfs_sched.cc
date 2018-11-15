// cfs_sched.cc

#include "llrb_multimap.h"

#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
	std::ifstream in(argv[1]);

	if (in.good()) std::cout << "its good";

	LLRB_multimap<char, int> CFS;
	while (in.peek() != EOF) {
		char key;
		in >> key;
		int startTime;
		in >> startTime;
		int duration;
		in >> duration;
		CFS.Insert(key, startTime);
		CFS.Insert(key, duration);
	}

	CFS.Print();

	std::cout << " Hi";
	return 0;
}