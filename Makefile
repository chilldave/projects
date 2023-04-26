TARGET=classmanager
CXX=g++
DEBUG=-g
NCURSES=-lncurses -ltinfo
LDFLAGS=$(NCURSES)
CXXFLAGS=$(DEBUG) $(NCURSES) -pipe
OBJS=main.o classmanager.o
all: $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)
	@rm -rf *.o

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

classmanager.o: classmanager.cpp
	$(CXX) -c $(CXXFLAGS) classmanager.cpp -o classmanager.o
