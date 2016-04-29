#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertSmithyCheck(int a, int b){
     printf("\n Cardtest1: \n");
    if(a==b-2){
        printf("ASSERT SUCCESSFUL. \n");
    }
    else{
        printf("ASSERT FAILED. Hand size before: %d. Hand size after: %d. There should be two more cards in the hand. You draw 3 cards, then discard the smithy card. \n", a, b);
    }
    
}

//this unit test checks that smithy makes the player draw 3 cards then discard the smithy card. 
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 120, p);
    int handSizeBefore = numHandCards(p);
    cardEffect(smithy, 0, 0, 0, p, 10, 0);
    int handSizeAfter = numHandCards(p);

    myAssertSmithyCheck(handSizeBefore, (handSizeAfter));
    
    
    return 0;
}
