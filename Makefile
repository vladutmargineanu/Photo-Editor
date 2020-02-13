CC=gcc
CFLAGS=-Wall
SRC=tema1.c
EXE=tema1

build: $(EXE)

$(EXE): tema1.o
	$(CC) tema1.o -o $(EXE) -lm
	
tema1.o: $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o tema1.o -lm 

clean: 
	rm -f tema1.o $(EXE)
