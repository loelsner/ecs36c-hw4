csf_sched: csf_sched.cc llrb_multimap.h
	g++ -Wall -Werror -std=c++11 csf_sched.cc -o csf_sched

clean: 
	rm -fr csf_sched