// cfs_sched.cc

#include "llrb_multimap.h"

#include <fstream>
#include <iostream>
#include <list>

class Task {
public:
	char _id;
	int _startTime;
	int _duration; // max _runtime
	int _runtime;
	int _vRuntime; 

	Task(char id, int startTime, int duration) : _id(id), _startTime(startTime), _duration(duration), _runtime(0) {}
	friend std::ostream& operator<<(std::ostream& stream, const Task& task) {
		stream << task._id;
		return stream;
	}
	bool operator<(const Task& right) const {
		if (_startTime < right._startTime) {
			return true;
		}
		if (_startTime > right._startTime) {
			return false;
		}
		if (_id < right._id) {
			return true;
		}
		return false;
	}
};


class CFS
{
public:
	CFS();
	//~CFS();

private:
	friend class LLRB_multimap<int, Task>;
	LLRB_multimap<int, Task> tree;
	int min_vruntime;
	

};


bool Run(LLRB_multimap<int, Task>& cfs, int min_vruntime, int tick) {
	if (cfs.Size() == 0) return false;

	if (cfs.Contains(tick))
	if (tick == cfs.Min()) {
			//std::cout << tick << " " << "[";
	}
	return true;
}

int main(int argc, char* argv[]) {
	std::ifstream in(argv[1]);

	if (in.good()) std::cout << "its good"<<std::endl;

	std::list<Task>	sortedTasks;
	
	char id;
	while (in >> id) {
		int startTime;
		in >> startTime;
		int duration;
		in >> duration;
		Task task(id, startTime, duration);
		sortedTasks.push_back(task);
	}	

	for (Task task : sortedTasks){
		std::cout << task << std::endl;
	}

	sortedTasks.sort();
	std::cout << std::endl;
	for (Task task : sortedTasks) {
		std::cout << task << std::endl;
	}

	int min_vruntime = 0;
	int tick = 0;

	//Run(cfs, min_vruntime, tick);

	std::cout << " Hi";
	return 0;
}