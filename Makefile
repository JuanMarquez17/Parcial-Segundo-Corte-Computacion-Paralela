GCC = gcc
FLAGS = -pedantic -Wall
CFLAGS = -lm -lpthread -fopenmp

PROGS: MMPosix MM1cOMP MM1fOMP

MM1cOMP:
	$(GCC) $(FLAGS) modulo.c -c $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) modulo.o $@.o -o $@ $(CFLAGS) 

MM1fOMP:
	$(GCC) $(FLAGS) modulo.c -c $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) modulo.o $@.o -o $@ $(CFLAGS) 
	
MMPosix:
	$(GCC) $(FLAGS) modulo.c -c $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS) 
	$(GCC) $(FLAGS) modulo.o $@.o -o $@ $(CFLAGS) 

clean:
	$(RM) $(PROGS) *.o
	$(RM) MMPosix MM1cOMP MM1fOMP
