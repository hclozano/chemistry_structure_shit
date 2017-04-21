CC = g++

#Used for running
CFLAGS = -Wall
CPPFLAGS = -Wall

#Used for compiling
#CFLAGS += -g
#CPPFLAGS += -g

all: main

main: main.o extraction.o center_of_mass.o bond_length.o bond_angle.o bond_number.o
	${CC} ${CPPFLAGS} main.o extraction.o center_of_mass.o bond_length.o bond_angle.o bond_number.o -o main

extraction: extraction.o
	${CC} ${CPPFLAGS} extraction.o

center_of_mass: center_of_mass.o
	${CC} ${CPPFLAGS} center_of_mass.o
	
bond_length: bond_length.o
	${CC} ${CPPFLAGS} bond_length.o
	
bond_angle: bond_angle.o
	${CC} ${CPPFLAGS} bond_angle.o

bond_number: bond_number.o
	$(CC) $(CPPFLAGS) bond_number.o

clean:
	\rm -f -rf *.o

cleanall:
	\rm -f -rf main *.o *.txt

cleanfiles:
	\rm -f -rf *.txt
