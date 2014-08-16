all: clean

%.exe: %.cpp
	g++ -std=c++11 -Wall -g -O0 -o $@ $^
clean:
	rm -rf a.out *.exe *~
