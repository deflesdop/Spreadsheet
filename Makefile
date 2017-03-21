CXX = g++ 
CFLAGS =	-O2 -g -std=c++14 -Wall -fmessage-length=0
CCFILE =	main.cpp
OBJS =		main.o
BIN = bin
LIBS =
SRC = src
TARGET =	main

all:	$(TARGET)
    
$(TARGET):	$(BIN)/$(OBJS)
	$(CXX) $(CFLAGS) -o $@ $(BIN)/$(OBJS)
	
$(BIN)/$(OBJS): $(SRC)/$(CCFILE)
	$(CXX) $(CFLAGS) -c -o $@ $<
clean:
	rm -f $(OBJS) $(TARGET)
