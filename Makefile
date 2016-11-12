objects = main.cpp Field.cpp DataManager.cpp Trigger.cxx
all: $(objects)
	clang++ -g -ggdb $(objects) -o Block -std=c++11 -Wall
clean:
	rm Block
re: clean
	clang++ -g -ggdb $(objects) -o Block -std=c++11 -Wall
run: all
	./Block
