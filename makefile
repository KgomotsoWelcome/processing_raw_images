#*****************************************************************
# makefile used to compile the driver file
# Author: Kgomotso Welcome
# Date: 25/02/2019
# Date completed: 17/03/2019
#*****************************************************************

CC=g++
CK=-c -std=c++11

#all:VolImagedriver

imageops: Image.o Imageops.o
	$(CC) Imageops.o Image.o -o imageops

Image.o: Image.cpp Image.h
	$(CC) Image.cpp -c 

Imageops.o: Imageops.cpp Image.h
	$(CC) Imageops.cpp -c 

test: test.o 
	$(CC) test.o Imageops.o -o test

addition: 
	./imageops -a Lenna_standard Lenna_hat_mask 

subtraction: 
	./imageops -s Lenna_standard Lenna_hat_mask

inverse: 
	./imageops -i shrek_rectangular 

mask:
	./imageops -l Lenna_standard Lenna_hat_mask

threshold:
	./imageops -t Lenna_standard 45

clean:
	@rm -f *.o
	@rm imageops


