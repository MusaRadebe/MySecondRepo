#include "StopWatch.h"
#include <ctime>
#include <iostream>
using namespace std;

StopWatch::StopWatch()
{
	_time=0.0;
	_start=0.0;
	_end=0.0;
}

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing
double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}
void StopWatch::Start()
{
	_start=getProcessTime();
	_running=true;
}
void StopWatch::End()
{
    _end=getProcessTime();
	_time=_end-_start;
	_running=false;

	cout<<"Runtime time: "<<_time<<endl;
}
void StopWatch::Pause()
{
	_pause=getProcessTime();
	_time= _pause-_start;
	_running=false;
}
void StopWatch::Resume()
{
	_start=_pause-_start;
	_time= _start;
	_running=true;

}
void StopWatch::Time()
{
	if(Running())
	{
		cout<<"Current Time: "<<(getProcessTime()-_start)<<endl;
	}
	else
		{
			cout<<"Current Time: "<<_time<<endl;
		}
}
