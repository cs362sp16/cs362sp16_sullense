#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



void checkTestCard2(int p, struct gameState *post ){
    struct gameState pre;
    memcpy(&pre, post, sizeof(struct gameState));
    
    int r;
    
    r = cardEffect(smithy, 0,0,0, post, 0, 0);
    
    
    if(pre.deckCount[p]>2){
        pre.handCount[p]+=3;
    }else if(pre.discardCount[p]>2){
        memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
        memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
        pre.hand[p][post->handCount[p]-1]= post->hand[p][post->handCount[p]-1];
        pre.handCount[p]+=2;
        pre.deckCount[p] = pre.discardCount[p]-3;
        pre.discardCount[p] = 1;
    }
    myAssert(memcmp(&pre,post, sizeof(struct gameState)));
    
}

int myAssert(int check ){
    if(check ==0){
        //the test passed
        return 0;
    }
    else{
        
        return -1;
    }
}

int main (int argc, char** argv) {
    int seed = atoi(argv[1]);
    SelectStream(2);
    PutSeed(seed);
    int i, n, r, p, deckCount, discardCount, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    for(n = 0; n<4000; n++){
        for(i =0;i<sizeof(struct gameState); i++){
            ((char*)&G)[i] = floor(Random()*256);
        }
        p = floor(Random()*2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() *MAX_HAND);
        int passed = checkTestCard2(p, &G);
        if(passed == 0){
            printf("Test Passed!");
        }
        if(passed ==-1){
            printf("Test Failed");
        }
    }
    
    
    return 0;
}