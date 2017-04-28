#File: Makefile                         
#Author: Justin James                                                         
#Purpose: Compiles program files more efficiently                               
#Usage Notes: ...                                                               

#TARGET                                                                         

#Compiler Version                                                               
CC=g++

#Compile with all errors and warnings                                           
CFLAGS = -c -Wall

all: BST

BST: driver.o BST.o node.o
	$(CC) driver.o BST.o node.o -o BST

driver.o: driver.cpp BST.h node.h
	$(CC) $(CFLAGS) driver.cpp

BST.o: BST.cpp BST.h node.h
	$(CC) $(CFLAGS) BST.cpp

node.o: node.cpp node.h BST.h
	$(CC) $(CFLAGS) node.cpp

clean:
	rm *.o BST *~
