CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

cardtesthelper.o: cardtesthelper.h cardtesthelper.c dominion.o rngs.o
	gcc -c cardtesthelper.c -g $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o cardtesthelper.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o cardtesthelper.o $(CFLAGS)

clean: 
	rm -f *.o cardtest3 *.gcov *.gcda *.gcno *.so *.out *.dSYM 
