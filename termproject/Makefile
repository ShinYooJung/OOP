.SUFFIXES: .cpp .o
OBJECTS = array_2d.o block.o 
TEST_FILE = Main.o $(OBJECTS) 
CXX = g++
TEST = test
$(TEST) : $(TEST_FILE)
	$(CXX) -o $(TEST) $(TEST_FILE)

clean: 
	rm -rf $(TEST) $(TEST_FILE)

Main.o : Main.cpp
array_2d.o : array_2d.cpp
block.o : block.cpp
