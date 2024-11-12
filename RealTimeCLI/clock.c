#include <stdio.h>
#include <time.h>

time_t getTime() {
    time_t start;
    time(&start);
    return start;
}

double elapsedTime(time_t start){
    time_t now;
     time(&now);
     double elapsed = difftime(now, start);
     return elapsed;
}