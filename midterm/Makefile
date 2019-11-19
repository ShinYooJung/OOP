.SUFFIXES: .cpp .o

OBJECTS = human.o student.o smart_obj.o shared_ref.o weak_pointer.o test.o 

CXX = g++
CPPFLAGS = -c

TARGET = a

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)

human.o : human.cpp
student.o: student.cpp
smart_obj.o: smart_obj.cpp
shared_ref.o: shared_ref.cpp
weak_pointer.o: weak_pointer.cpp
test.o: test.cpp
