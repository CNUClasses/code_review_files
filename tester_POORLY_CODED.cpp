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
	switch(wp) {
		//TODO whats wrong with below case statement
		case P1:
		{
			//TODO whats wrong with these enormous repetitive blocks of code?
			for(int k = 0; k < num_times; k++)
			{
				//TODO will this ever exit if work == true
				std::this_thread::sleep_for(std::chrono::milliseconds(del_milli));
				if(work == true)
					PRINT1(UCTC);
				else
					PRINT1(text);
			}
			break;
		}

		case P2:
		{
			for(int k = 0; k < num_times; k++)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(del_milli));
				if(work == true)
					PRINT1(UCTC);
				else
					PRINT2(text, text);
			}
			break;
		}

		case P3:
		{
			for(int k = 0; k < num_times; k++)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(del_milli));
				if(work == true)
					PRINT1(UCTC);
				else
					PRINT3(text, text, text);
			}
			break;
		}

		case P4:
		{
			for(int k = 0; k < num_times; k++)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(del_milli));
				if(work == true)
					PRINT1(UCTC);
				else
					PRINT4(text, text, text, text);
			}
			break;
		}

		case P5:
		{
			for(int k = 0; k < num_times; k++)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(del_milli));
				if(work == true)
					PRINT1(UCTC);
				else
					PRINT5(text, text, text, text, text);
			}
			break;
		}
	}
}


void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
	//TODO what happens if you call startThreads twice with the following in place
	threads.clear();

	for(int i = 0;i < numThreads;i++)
		threads.push_back(thread(func,s,wp,numTimesToPrint,millisecond_delay));
}

//TODO can this be simplified?
void setCancelThreads(bool bCancel) {
	if (bCancel) {
		bCancelThreads = false;
	} else {
		bCancelThreads = true;

	}

}

// TODO what if you call this function twice
void joinThreads() {
	for(auto& thr : threads)
		thr.join();
}
