# c++ compiler
CXX = clang++

# compiler flags
CXXFLAGS += -Wall -std=c++17 -g

# cpp files
SOURCES := src/*.cpp

# hpp files
HEADERS := src/*.hpp

OUTPUT := build/main

# all depends on output
all: $(OUTPUT)

# the output depends on sources and headers
$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	$(RM) $(OUTPUT)