CC=g++
CFLAGS=-c -Wall -lncurses

all: shop

shop: main.o shop.o customer.o product.o
	$(CC) main.o customer.o shop.o product.o -o shop

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

customer.o: customer.cpp
	$(CC) $(CFLAGS) customer.cpp

shop.o: shop.cpp
	$(CC) $(CFLAGS) shop.cpp

clean:
	rm *.o
