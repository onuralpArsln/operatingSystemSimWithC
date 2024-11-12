CC=gcc
CFLAGS=-ggdb
CPPFLAGS=$(DEFS)
LDFLAGS=-lpthread

.PRECIOUS=%.tests

coursework : coursework.o logger.o list.o blocking_queue.o non_blocking_queue.o simulator.o environment.o event_source.o evaluator.o utilities.o
	$(CC) $^ -o $@ $(LDFLAGS)

list.tests : list.tests.o list.o
	$(CC) $(LDFLAGS) $^ -o $@

blocking_queue.tests : blocking_queue.tests.o list.o blocking_queue.o utilities.o
	$(CC) $(LDFLAGS) $^ -o $@

non_blocking_queue.tests : non_blocking_queue.tests.o list.o non_blocking_queue.o utilities.o
	$(CC) $(LDFLAGS) $^ -o $@

evaluator.tests : evaluator.tests.o evaluator.o
	$(CC) $(LDFLAGS) $^ -o $@

%.tested : %.tests
	./$<
	touch $@

%.o : %.c %.h
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -f *.o *.tests *.tested coursework *.gz

coursework.tar.gz : coursework.c logger.c logger.h list.c list.h blocking_queue.c blocking_queue.h non_blocking_queue.c non_blocking_queue.h simulator.c simulator.h environment.c environment.h event_source.c event_source.h evaluator.c evaluator.h utilities.c utilities.h evaluator.tests.c list.tests.c blocking_queue.tests.c non_blocking_queue.tests.c Makefile 
	tar -czvf $@ $^
