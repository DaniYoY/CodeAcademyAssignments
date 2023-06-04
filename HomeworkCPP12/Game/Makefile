.PHONY = build src bin clean
CXX = g++
CXXFLAGS = -std=c++11 -MMD -Wall -Wextra
TARGET = consoleGames.exe
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
BLDF = build
SRCF = src
BINF = bin

$(BLDF)\$(TARGET): $(BINF)\$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

$(BINF)\%.o: $(SRCF)\%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	-include $(DEPS)

build:
	mkdir -p $@

src:
	mkdir -p $@

bin:
	mkdir -p $(BINF)

clean:
	del -f &(BINF)\%.o
