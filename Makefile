TARGET=classmanager
CXX=g++
DEBUG=-g
LDFLAGS=-lncurses -ltinfo
CXXFLAGS=$(DEBUG) $(LDFLAGS) -pipe
OBJS=main.o classmanager.o menu.o
all: $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)
	@rm -rf *.o

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

classmanager.o: classmanager.cpp
	$(CXX) -c $(CXXFLAGS) classmanager.cpp -o classmanager.o

menu.o: menu.cpp
	$(CXX) -c $(CXXFLAGS) menu.cpp -o menu.o
