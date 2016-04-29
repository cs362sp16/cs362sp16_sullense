#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertGameOverCheck(int a){
     printf("\n Unittest4: \n");
    if(a==1){
        printf("ASSERT SUCCESSFUL. The game has ended because there are no more provinces.\n");
    }
    else{
        printf("ASSERT FAILED. isGameOver did not return the correct value. With no more provinces, the game should be over\n");
    }
    
}

//this unit test checks that the game is over when there are no more provinces in the supply.
int main (int argc, char** argv) {
    struct gameState G;
    struct gameState *p = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 120, p);
    p->supplyCount[province] = 0;
    
    int game = isGameOver(p);
    myAssertGameOverCheck(game);
    
    return 0;
}
