CC = g++
CFLAGS = -I.
SRCDIR = .

# List your source files for hw3.1_main here
SRC_HW3_1 = $(SRCDIR)/hw3.1_main.cpp $(SRCDIR)/hw3.1_impl.cpp

# List your source file for hw3.2 here
SRC_HW3_2 = $(SRCDIR)/hw3.2.cpp

# Specify the executable names
EXECUTABLE_HW3_1 = hw3.1_main
EXECUTABLE_HW3_2 = hw3.2

# Default target
all: $(EXECUTABLE_HW3_1) $(EXECUTABLE_HW3_2)

# Linking steps for hw3.1_main
$(EXECUTABLE_HW3_1): $(SRC_HW3_1)
	$(CC) $(CFLAGS) -o $@ $^

# Linking step for hw3.2
$(EXECUTABLE_HW3_2): $(SRC_HW3_2)
	$(CC) $(CFLAGS) -o $@ $^

# Clean up intermediate and executable files
clean:
	rm -f $(EXECUTABLE_HW3_1) $(EXECUTABLE_HW3_2)
