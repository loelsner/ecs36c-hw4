cfs_sched: cfs_sched.cc llrb_multimap.h
	g++ -Wall -Werror -std=c++11 cfs_sched.cc -o cfs_sched

clean: 
	rm -fr cfs_sched