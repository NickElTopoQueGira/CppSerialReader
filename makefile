OBJS	= myfile.o serialreader.o
SOURCE	= myfile.cc serialreader.cpp
HEADER	= myFile.hh
OUT	= serialReaderOut.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

myfile.o: myfile.cc
	$(CC) $(FLAGS) myfile.cc -std=c++17

serialreader.o: serialreader.cpp
	$(CC) $(FLAGS) serialreader.cpp -std=c++17


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)