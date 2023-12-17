CXX = g++
NVCC = nvcc
CXXFLAGS = -std=c++11 -Wall
NVCCFLAGS = -std=c++11

all: problem1 problem2 problem3 problem4a problem4b problem4c 

problem1: problem1.cpp
	$(CXX) $(CXXFLAGS) -o problem1 problem1.cpp

problem2: problem2.cpp
	$(CXX) $(CXXFLAGS) -o problem2 problem2.cpp

problem3: problem3.cpp
	$(CXX) $(CXXFLAGS) -o problem3 problem3.cpp

problem4a: problem4a.cpp
	$(CXX) $(CXXFLAGS) -o problem4a problem4a.cpp

problem4b: problem4b.cpp
	$(CXX) $(CXXFLAGS) -o problem4b problem4b.cpp

problem4c: problem4c.cpp
	$(CXX) $(CXXFLAGS) -std=c++11 -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp -o problem4c problem4c.cpp

# problem4d: problem4d.cu
# 	$(NVCC) $(NVCCFLAGS) -o problem4d problem4d.cu


clean:
	rm -f problem1 problem2 problem3 problem4a problem4b problem4c 
