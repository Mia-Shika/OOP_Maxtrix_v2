#**************************************************************************************************
#
#   raylib makefile for Desktop platforms, Raspberry Pi, Android, and HTML5
#
#   Copyright (c) 2013-2019 Ramon Santamaria (@raysan5)
#
#   This software is provided "as-is", without any express or implied warranty. In no event
#   will the authors be held liable for any damages arising from the use of this software.
#
#**************************************************************************************************

.PHONY: all clean

# Define required raylib variables
PROJECT_NAME       ?= game
RAYLIB_VERSION     ?= 4.5.0
RAYLIB_PATH        ?= ../../raylib

# Define compiler path on Windows
COMPILER_PATH      ?= C:/raylib/w64devkit/bin

# Define default options
PLATFORM           ?= PLATFORM_DESKTOP

# Define the default include and library paths
INCLUDE = -I./include -I../../raylib/src -I../../raylib/src/external
LDFLAGS = -L../../raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -DPLATFORM_DESKTOP

# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++14 -g -O0

# Additional flags for the platform
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    ifeq ($(OS),Windows_NT)
        PLATFORM_OS = WINDOWS
        export PATH := $(COMPILER_PATH):$(PATH)
    endif
endif

# Define the output name
TARGET = $(PROJECT_NAME)

# Define source files
SRC = src/main.cpp  # Update the path if the file is in a different folder
OBJ = $(SRC:.cpp=.o)

# Build directory
BUILD_DIR = ./build

# All target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Compile .cpp files to .o object files
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

# Clean object files and executable
clean:
	del /Q *.o $(TARGET)


