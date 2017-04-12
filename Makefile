CXX = g++ 
CFLAGS =	-std=c++14 -Wall -g -Wextra -pedantic 
OBJDIR = bin
OBJS =	$(addprefix $(OBJDIR)/, $(patsubst $(SRC)/%.cpp, %.o, $(wildcard $(SRC)/*.cpp)))
#TESTOBJS = $(addprefix $(OBJDIR)/, $(patsubst $(TEST)/%.cpp, %.o, $(wildcard $(TEST)/*.cpp)))
TESTOBJ = $(addprefix $(TEST)/, $(patsubst $(TEST)/%.cpp, %, $(wildcard $(TEST)/*.cpp)))
INC = include
SRC = src
LIB = curses
BOOST_LIBS =  -lboost_unit_test_framework
BOOST_CXXFLAGS = -I/vol/share/groups/liacs/scratch/pt2017/include -DBOOST_TEST_DYN_LINK
LDFLAGS = -L/vol/share/groups/liacs/scratch/pt2017/lib
TARGET =	main
TEST = test

.PHONY: all clean

all: clean $(OBJDIR) $(TARGET)
	@echo Done Building...	

$(OBJDIR):
	@echo Making bin directory
	@mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRC)/%.cpp
	@echo Building $@
	@$(CXX) $(CFLAGS) $(BOOST_CXXFLAGS) $(LDFLAGS) -c $< -o $@	
	@echo Done Building $@
	
    
$(TARGET):	$(OBJS)
	@echo Building executable $@
	@$(CXX) $(CFLAGS) -I$(INC) -o $@ $^ -l$(LIB)

test: $(TESTOBJ)
	./$(TESTOBJ)
	
$(TESTOBJ):	$(TESTOBJ).cpp $(INC)/*.h
		$(CXX) $(CFLAGS) $(BOOST_CXXFLAGS) -o $@ $< -L/usr/lib/ $(BOOST_LIBS)

	

clean:
	@echo Cleaning $(OBJDIR) $(TARGET) $(wildcard *.o)...
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)
	@echo Done Cleaning...
