#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertGreatHallCheckAction(int a, int b){
     printf("\n Cardtest2: \n");
    if(a==b-1){
        printf("ASSERT SUCCESSFUL. Correct number of actions. \n");
    }
    else{
        printf("ASSERT FAILED. Actions = %d. There needs to be one more action.\n", b);
    }
    
}
void myAssertGreatHallCheckCards(int a, int b){
    if(a==b){
        printf("ASSERT SUCCESSFUL. Correct number of cards. \n");
    }
    else{
        printf("ASSERT FAILED. Hand size before: %d. Hand size after: %d. There should be two more cards in the hand. You draw 1 card, then discard the great hall card. \n", a, b);
    }
}


//this unit test checks that when the Great Hall card is played that the player gets one more actions and that they player draws a card.
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 120, p);
    int actionsBefore = p->numActions;
    int cardsBefore = numHandCards(p);
    cardEffect(great_hall, 0, 0, 0, p, 10, 0);
    int actionsAter = p->numActions;
    int cardsAfter = numHandCards(p);
    
    myAssertGreatHallCheckAction(actionsBefore, actionsAter);
    myAssertGreatHallCheckCards(cardsBefore, cardsAfter);
    
    return 0;
}
