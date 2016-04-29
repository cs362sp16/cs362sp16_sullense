#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertTreasureMapCheck(int a, int b){
     printf("\n Cardtest4: \n");
    if(a==b-4){
        printf("ASSERT SUCCESSFUL. There are 4 more gold in the deck. Gold before: %d, Gold after: 5d\n", a, b);
    }
    else{
        printf("ASSERT FAILED. Gold in deck before: %d. Gold in deck after: %d. There should be 4 more gold cards in the deck. \n", a, b);
    }
    
}

//this unit test checks that truesure_map adds two treasure cards to your hand
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    int player = whoseTurn(p);
    int numberOfGoldBefore = fullDeckCount(player, gold, p);
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 120, p);
    int count = p->handCount[player];//Get current hand count for player
    int deckCounter;
    deckCounter = p->deckCount[player];//Create holder for the deck count
    p->hand[player][count-1] = treasure_map;//Add card to the hand
    int numofTM = fullDeckCount(player, treasure_map,p);
    printf("number of treasure maps in hand: %d\n", numofTM);
    cardEffect(treasure_map, 0, 0, 0, p, 10, 0);
    int numberOfGoldAfter = fullDeckCount(player, gold, p);
    
    myAssertTreasureMapCheck(numberOfGoldBefore, (numberOfGoldAfter));
    
    
    return 0;
}
