# c++ compiler
CXX = clang++

# compiler flags
CXXFLAGS += -Wall -std=c++17 -g

# for creating build dir
MKDIR_P = mkdir -p build

# cpp files
SOURCES := src/*.cpp

# hpp files
HEADERS := src/*.hpp

OUTPUT = build/main

# all depends on output
all: $(OUTPUT)

# the output depends on sources and headers
$(OUTPUT): $(SOURCES) $(HEADERS)
	$(MKDIR_P)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	$(RM) $(OUTPUT)