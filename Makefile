OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
CPPFLAGS += -O3
a.out:$(OBJ) 
	-@g++ $^ -o $@
clean:
	-@rm *.out *.o
image:
	cp a.out image.out

