CC = g++
CFLAGS = -c
TARGET = snakegame
$(TARGET) : SnakeGame.o main.o
	$(CC) -o  snakegame SnakeGame.o main.o -lncurses
main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp -lncurses
SnakeGame.o : SnakeGame.cpp
	$(CC) $(CFLAGS) SnakeGame.cpp -lncurses
	
	
clean :
	rm *.o snakegame
	
run :
	./$(TARGET)
	
