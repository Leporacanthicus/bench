CXXFLAGS = -Wall -Wextra -O3
CFLAGS = -Wall -Wextra -O3

CC=clang
CXX=clang++

EXECS = sort csort dynarray vector strcat strcatxx

all: ${EXECS}

csort: csort.c

sort: sort.cpp

dynarray: dynarray.c

vector: vector.cpp

strcatxx: strcatxx.cpp

strcat: strcat.c

clean:
	-rm ${EXECS}
