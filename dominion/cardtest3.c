#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertAdventurerCheck(int a, int b){
     printf("\n Cardtest3: \n");
    if(a==b-2){
        printf("ASSERT SUCCESSFUL. \n");
    }
    else{
        printf("ASSERT FAILED. Hand size before: %d. Hand size after: %d. There should be two more cards in the hand. You draw 2 treasure cards. \n", a, b);
    }
    
}

//this unit test checks that adventurer adds two treasure cards to your hand
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 120, p);
    int handSizeBefore = numHandCards(p);
    cardEffect(adventurer, 0, 0, 0, p, 10, 0);
    int handSizeAfter = numHandCards(p);
    
    myAssertAdventurerCheck(handSizeBefore, (handSizeAfter));
    
    
    return 0;
}
