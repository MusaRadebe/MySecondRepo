#ifndef STOPWATCH_H
#define STOPWATCH_H

class StopWatch
{
public:

StopWatch();

double getProcessTime();
void Start();
void Pause();
void Resume();
void End();
void Time();

private:


	  double _time=0.0;
	  double _start=0.0;
	  double _end=0.0;
	  double _pause=0.0;
	  double _resume=0.0;
      bool Running(){ return _running;}
      bool _running=false;


};
#endif
