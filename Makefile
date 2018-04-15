CC = g++
SOURCE = main.cpp bubbleSortRecursive.cpp heapSort.cpp insertSort.cpp mergeSort.cpp quickSort.cpp selectionSortRecursive.cpp vectorManipulationFunctions.cpp
OBJECT = $(SOURCE:.cpp=.o)
NAME_OF_EXECUTABLE = main

all: $(SOURCE) $(NAME_OF_EXECUTABLE)
	$(CC) -g -o  $(NAME_OF_EXECUTABLE) $(SOURCE)

$(NAME_OF_EXECUTABLE): $(OBJECT)
	$(CC) -g  $(OBJECT) -o $@

.c.o:
	$(CC) -c $< -o $@

clean:
	rm $(NAME_OF_EXECUTABLE) *.o