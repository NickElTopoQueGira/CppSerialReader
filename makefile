OBJS	= myfile.o serialreader.o
SOURCE	= myfile.cc serialreader.cpp
HEADER	= myFile.hh
OUT	= serialReaderOut.out
FLAGS	= -g -c -Wall
LFLAGS	= -lpthread
CC	= g++

# -g option enables debugging mode 
# -c flag generates object code for separate files

# compile all components of the solution by using a single tag
all:	serialReaderOut.out

# Compile all components of a specific project by using a single tag
serialReaderOut.out: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

#
# create/compile the individual files >>separately<<

myfile.o: myfile.cc
	$(CC) $(FLAGS) myfile.cc -std=c++17

serialreader.o: serialreader.cpp
	$(CC) $(FLAGS) serialreader.cpp -std=c++17

# clean house
clean:
	rm -f $(OBJS) $(OUT)

# run the program
run: serialReaderOut.out
	./serialReaderOut.out
