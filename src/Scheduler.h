#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

#define MAX_TASKS 50

class Scheduler {
  
  long basePeriod;
  int nTasks;
  Task* taskList[MAX_TASKS];  
  long tempo1;
public:
  void init(int basePeriod);  
  virtual bool addTask(Task* task);  
  virtual void schedule();
  virtual void deactivateAllTasks();
};

#endif
