#include "print_ts.h"
#include "tester.h"
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::string UCTC = "User choose to cancel";
vector<std::thread> threads;
bool bCancelThreads = false;

void func(std::string text, WHICH_PRINT wp, int num_times, int del_milli)
{
	for(int k = 0; k < num_times; k++){
		if (bCancelThreads == true){
			PRINT1(UCTC);
			break;
		}

		switch(wp) {
			case P1:
				PRINT1(text);
				break;
			case P2:
				PRINT2(text, text);
				break;
			case P3:
				PRINT3(text, text, text);
				break;
			case P4:
				PRINT4(text, text, text, text);
				break;
			case P5:
				PRINT5(text, text, text, text, text);
				break;
		}
		//check for delay
		if (del_milli > 0)
			std::this_thread::sleep_for(std::chrono::milliseconds(del_milli));
	}
}

void setCancelThreads(bool bCancel) {
	bCancelThreads = bCancel;
}

void joinThreads() {
	for(auto& thr : threads)
		thr.join();
	threads.clear();
}

void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
	for(int i = 0;i < numThreads;i++)
		threads.push_back(thread(func,s,wp,numTimesToPrint,millisecond_delay));
}

