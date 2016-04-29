CFLAGS = -Wall -fpic -coverage -lm


rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o unittest1.c
	gcc -c dominion.c -g  $(CFLAGS)
playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c dominion.o unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
	gcc -o unit1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unit4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o card4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	unit1 > unittestresults.out 
	unit2 >> unittestresults.out
	unit3 >> unittestresults.out
	unit4 >> unittestresults.out
	card1 >> unittestresults.out
	card2 >> unittestresults.out
	card3 >> unittestresults.out
	card4 >> unittestresults.out
all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
