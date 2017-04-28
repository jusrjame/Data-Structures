#File: Makefile                         
#Author: Chase Breeden                                                         
#Purpose: Compiles program files more efficiently                               
#Usage Notes: ...                                                               

#TARGET                                                                         
TARGET=collection

#Compiler Version                                                               
CC=g++

#Compile with all errors and warnings                                           
CFLAGS = -c -Wall

all: $(TARGET)

$(TARGET): main.o $(TARGET).o
	$(CC) main.o $(TARGET).o -o $(TARGET)

main.o: main.cpp $(TARGET).h CD.h
	$(CC) $(CFLAGS) main.cpp

$(TARGET).o: $(TARGET).cpp $(TARGET).h CD.h
	$(CC) $(CFLAGS) $(TARGET).cpp

clean:
	rm *.o $(TARGET) *~
