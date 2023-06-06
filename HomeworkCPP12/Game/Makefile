#.PHONY: build src bin clean
CXX = g++
CXXFLAGS = -std=c++11 -MMD -Wall -Wextra
SRCF = src
BLDF = build
BINF = bin
SRCS = $(wildcard $(SRCF)\*.cpp)
OBJS = $(patsubst $(SRCF)\%.cpp, $(BINF)\%.o, $(SCRS))
# OBJS = $( SRCS: $(SRCF)\%.cpp = $(BINF)\%.o)
TARGET = consoleGames.exe
DEPS = $(OBJS:.o=.d)

all: build src bin $(BLDF)\$(TARGET) 

$(BLDF)\$(TARGET): $(OBJS) | $(BLDF)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

$(BINF)\%.o: $(SRCF)\%.cpp | $(BINF)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
-include $(DEPS)

build:
	mkdir $(BLDF)

src:
	mkdir $(SRCF)

bin:
	mkdir $(BINF)

.PHONY: all clean


clean:
	del -f $(BINF)\%.o
