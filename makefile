slist: main.o student.o
	gcc -o slist main.o student.o

main.o: main.c student.h
	gcc -c main.c

student.o: student.c student.h
	gcc -c student.c

clean:
	rm -f *.o slist

# Written with the assiatance of ChatGPT 5.6, Prompt used: "can you remind me how a makefile works?"