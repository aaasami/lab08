# Makefile

CXX=clang++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES=testSimpleList1 testSimpleList2 testSimpleList3

all: ${BINARIES}

testSimpleList1: testSimpleList1.o SimpleList.o tddFuncs.o
	${CXX} $^ -o $@

testSimpleList2: testSimpleList2.o SimpleList.o tddFuncs.o
	${CXX} $^ -o $@

testSimpleList3: testSimpleList3.o SimpleList.o tddFuncs.o
	${CXX} $^ -o $@

lt01: testSimpleList3
	- valgrind -q --leak-check=full ./testSimpleList3

tests: ${BINARIES}
	./testSimpleList1
	./testSimpleList2
	./testSimpleList3

leaktests: lt01

clean:
	/bin/rm -f ${BINARIES} *.o

