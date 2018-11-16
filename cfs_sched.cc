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
	int _vRuntime; //  = starttime + runtime

	Task(char id, int startTime, int duration) : _id(id), _startTime(startTime), _duration(duration), _runtime(0) {}
	friend std::ostream& operator<<(std::ostream& stream, const Task& task) {
		stream << task._id;
		return stream;
	}
	bool operator<(const Task* right) const {
		if (_startTime < right->_startTime) {
			return true;
		}
		if (_startTime > right->_startTime) {
			return false;
		}
		if (_id < right->_id) {
			return true;
		}
		return false;
	}
};


class CFS
{
public:
	CFS() {};
	//~CFS();
	bool IsEmpty() {
		return tree.Size() == 0;
	}
	void AddTask(Task* task) {
		task->_vRuntime = min_vruntime;
		tree.Insert(min_vruntime, task);
	}
	void RunTask(int& tick);
private:
	LLRB_multimap<int, Task*> tree;
	int min_vruntime;
	

};

void CFS::RunTask(int& tick) {

		
	if (tree.Min() != min_vruntime) // ???
		{
			min_vruntime++;
		}
	//if (tree.Min() <= min_vruntime)
	//{
		int key = tree.Min();
		Task* task = tree.Get(key);
		task->_runtime++;
		task->_vRuntime++;

		std::cout << tick << " [" << tree.Size() << "]: " << task->_id << std::endl;

		if (task->_vRuntime >= min_vruntime)
		{
			tree.Remove(key);
		}


		if (task->_duration != task->_runtime) // if task isn't completed
		{
			if (task->_vRuntime <= min_vruntime)
			{
				tree.Insert(key, task);
			}
			else
			{
				tree.Insert(key + 1, task);
			}
		}

	//}
}

int main(int argc, char* argv[]) {
	std::ifstream in(argv[1]);

	if (in.good()) std::cout << "its good"<<std::endl;

	std::list<Task*> sortedTasks;
	
	char id;
	while (in >> id) {
		int startTime;
		in >> startTime;
		int duration;
		in >> duration;
		sortedTasks.push_back(new Task(id, startTime, duration));
	}	

	for (Task* task : sortedTasks){
		std::cout << *task << std::endl;
	}

	sortedTasks.sort();
	std::cout << std::endl;
	for (Task* task : sortedTasks) {
		std::cout << *task << std::endl;
	}

	int min_vruntime = 0;
	int tick = 0;
	CFS cfs;
	while (sortedTasks.size() > 0 || !cfs.IsEmpty())
	{
		while ((sortedTasks.size() != 0) && (tick >= (sortedTasks.front())->_startTime))
		{
			cfs.AddTask(sortedTasks.front());
			sortedTasks.pop_front();
		}

		// do tree stuff
		if (!cfs.IsEmpty())
		{
			cfs.RunTask(tick);
		}
		else {
			std::cout << tick << " [0] _ " << std::endl;
		}
		tick++;
	}
	//Run(cfs, min_vruntime, tick);

	std::cout << " Hi";
	return 0;
}