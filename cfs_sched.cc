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

class CFS
{
public:
	CFS(std::ifstream& in);
	//~CFS();

private:
	friend class LLRB_multimap<int, Task>;
	LLRB_multimap<int, Task> tree;
	int min_vruntime;
	

};

CFS::CFS(std::ifstream& in)
{
	while (in.peek() != EOF) {
		char id;
		in >> id;
		int startTime;
		in >> startTime;
		int duration;
		in >> duration;
		Task task(id, duration);
		tree.Insert(startTime, task);
	}

}


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

	CFS cfs(in);
	

	int min_vruntime = 0;
	int tick = 0;

	//Run(cfs, min_vruntime, tick);

	std::cout << " Hi";
	return 0;
}