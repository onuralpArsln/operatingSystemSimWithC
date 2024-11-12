#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "evaluator.h"

typedef unsigned int ProcessIdT;

typedef enum ProcessState {
  unallocated,
  ready,
  running,
  blocked,
  terminated
} ProcessStateT;

void simulator_start(int threads, int max_processes);
void simulator_stop();

ProcessIdT simulator_create_process(EvaluatorCodeT const code);
void simulator_wait(ProcessIdT pid);
void simulator_kill(ProcessIdT pid);
void simulator_event();

#endif
