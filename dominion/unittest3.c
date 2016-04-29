#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertDiscardCheck(int a, int b){
     printf("\n Unittest3: \n");
    if(a==(b+1)){
        printf("ASSERT SUCCESSFUL. A card was discarded. Cards in hand before: %d. Cards in hand after discard = %d\n", a, b);
    }
    else{
        printf("ASSERT FAILED. Did not discard the right number of cards. Hand before: %d. Hand after: %d\n", a, b);
    }
    
}

//this unit test checks that when you discard a card your hand size decreases by 1.
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 120, p);
    int curPlayer = whoseTurn(p);
    int cardsInHand = numHandCards(p);
    discardCard(1, curPlayer, p, 1);
    int cardsInHandAfterDiscard = numHandCards(p);
    myAssertDiscardCheck(cardsInHand, cardsInHandAfterDiscard);
    
    
    return 0;
}
