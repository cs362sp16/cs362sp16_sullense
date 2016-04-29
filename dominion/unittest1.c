#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertCopperCheck(int a, int b){
    printf("\n Unittest1: \n");
    if(a==b){
        printf("ASSERT SUCCESSFUL. Total copper cards in starting hand: %d. Cards needed = %d\n", a, b);
    }
    else{
        printf("ASSERT FAILED. Not the right amount of copper cards in starting deck.\n");
    }
    
}

//this unit test tests that you start out with the correct amount of copper cards in your deck
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 120, p);
    int c = fullDeckCount(1, copper, p);
    myAssertCopperCheck(7,c);
    
    return 0;
}
