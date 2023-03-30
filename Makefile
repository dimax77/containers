PROJECT=s21_containers
CXX=gcc
CXXFLAGS+=--std=c++17 -g -Wall -Werror -Wextra --coverage
TESTFILE=S21Gtest.cc
TESTFLAGS=-lgtest -lgcov -lm -lpthread -lstdc++
OS=$(shell uname)

all: clean check

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt *.dSYM

test: $(TESTFILE)
	$(CXX) $^ $(TESTFLAGS) -o $@
	./$@

check: test
	clang-format -style="{BasedOnStyle: Google}" -i *.cc *.h
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(SRC) *.h
ifeq ($(OS), Darwin)
	leaks --atExit -- test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test
endif
