readQuestions.o: readQuestions.c struct.h
	gcc -c readQuestions.c -o readQuestions.o

shuffle.o: shuffle.c struct.h
	gcc -c shuffle.c -o shuffle.o

sort.o: sort.c struct.h
	gcc -c sort.c -o sort.o

display.o: display.c struct.h
	gcc -c display.c -o display.o

review.o: review.c struct.h
	gcc -c review.c -o review.o

main.o: main.c struct.h
	gcc -c main.c -o main.o

ngeo: main.o readQuestions.o shuffle.o sort.o display.o review.o struct.h
	gcc readQuestions.o shuffle.o sort.o display.o review.o main.o -o ngeo

clean:
	rm -rf *.o