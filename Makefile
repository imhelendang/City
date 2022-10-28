CFLAGS = -Wall -Werror -Wpedantic -std=gnu99 -O0 -g
CC = gcc

OBJECTS = driver.o city.o

default: run-tests

run-tests: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

driver.o: driver.c city.h

city.o: city.c city.h

clean:
	rm -f run-tests *.o *~