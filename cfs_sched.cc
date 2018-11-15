// cfs_sched.cc

#include "llrb_multimap.h"

#include <fstream>
#include <iostream>

class Task {
public:
	char _id;
	int _duration; // max runtime
	int _runtime;
	Task(char id, int duration) : _id(id), _duration(duration), _runtime(0) {}
	friend std::ostream& operator<<(std::ostream& stream, const Task& task) {
		stream << task._id;
		return stream;
	}
};

bool Run(LLRB_multimap<int, Task>& cfs, int min_vruntime, int tick, ) {
	if (cfs.Size() == 0) return false;

	if (cfs.Contains(tick) || )
	if (tick == cfs.Min()) {
		int totalTasks = cfs.
			std::cout << tick << " " << "[";
	}
	return;
}

int main(int argc, char* argv[]) {
	std::ifstream in(argv[1]);

	if (in.good()) std::cout << "its good"<<std::endl;

	LLRB_multimap<int, Task> cfs;
	int totalTasks;
	while (in.peek() != EOF) {
		char id;
		in >> id;
		int startTime;
		in >> startTime;
		int duration;
		in >> duration;
		Task task(id, duration);
		cfs.Insert(startTime, task);
	}

	cfs.Print();

	int min_vruntime = 0;
	int tick = 0;

	Run(cfs, min_vruntime, tick);

	std::cout << " Hi";
	return 0;
}