runProgram: main.o insertion_sort.o merge_sort.o
	g++ main.o insertion_sort.o merge_sort.o -o test

main.o: main.cpp 
	g++ -c main.cpp

insertion_sort.o: insertion_sort.cpp
	g++ -c insertion_sort.cpp

merge_sort.o: merge_sort.cpp
	g++ -c merge_sort.cpp

clean: 
	rm main.o insertion_sort.o merge_sort.o a.out

