.PHONY: all clean

CXX = g++
CXXFLAGS = -std=c++11 -MMD -Wall -Wextra
SRCF = src
BLDF = build
BINF = bin
SRCS = $(wildcard $(SRCF)\*.cpp)
OBJS = $(patsubst $(SRCF)\%.cpp, $(BINF)\%.o, $(SRCS))
TARGET = $(BLDF)\inventory.exe
DEPS = $(OBJS:.o=.d)

all: build $(TARGET)

$(TARGET): $(OBJS) | $(BLDF)
    $(CXX) $(CXXFLAGS) $^ -o $@

$(BINF)\%.o: $(SRCF)\%.cpp | $(BINF)
    $(CXX) $(CXXFLAGS) -c $< -o $@
	
-include $(DEPS)

build:
    mkdir -p $(BLDF)

$(BINF):
    mkdir -p $(BINF)

clean:
    del /Q $(BINF)\*.o
    del /Q $(TARGET)
    rmdir /Q $(BLDF)
    rmdir /Q $(BINF)