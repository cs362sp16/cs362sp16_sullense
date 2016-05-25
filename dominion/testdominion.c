#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int isCardUnique(int card, int *c){
    int i;
    for(i=0; i<10; i++){
        if(card == c[i]){
            return 0;
        }
    }
    return 1;
}

bool hasActionCardInHand(struct gameState *g){
   // printf("inside hasactioncardinhand\n");
    enum CARD *curHand = g->hand[g->whoseTurn];
    int i;
    for(i=0; i< g->handCount[g->whoseTurn];i++){
        if(g->hand[g->whoseTurn][i]>=adventurer){
            return true;
        }
    }
    printf("no action cards\n");
    return false;
}

int main(int argc, char **argv){
    int seed = atoi(argv[1]);
    SelectStream(1);
    srand(seed);
    
    
    // choose random set of cards
    int cards[20] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
    int k[10] = {0,0,0,0,0,0,0,0,0,0};
    int i;
    bool unique = false;
    int randomCard;
    for(i=0;i<10;i++){
        while(!unique){
            randomCard = rand() %20;
            unique = isCardUnique(cards[randomCard], k);
            k[i] = cards[randomCard];
        }
        unique = false;
    }
    
    //number of players 2-4
    int numPlayers = 2+ rand()%3;
    printf("number of players: %d\n", numPlayers);
    
    struct gameState G;
    initializeGame(numPlayers, k, seed, &G);
    while(!isGameOver(&G)){
        printf("Player %d's turn: \n", G.whoseTurn);
        
        
        
        //action phase
        int maxActions = 4;
        while(G.numActions > 0 && hasActionCardInHand(&G) && maxActions>0){
            //printf("hasaction card: %d\n", hasActionCardInHand(&G));
            enum CARD *curHand = G.hand[G.whoseTurn];
            
            int randActionCard = rand() % G.handCount[G.whoseTurn];
           // printf("randActionCArd: %d\n", randActionCard);
            if(curHand[randActionCard] >=adventurer){
                playCard(randActionCard, -1,-1,-1,&G);
                
                maxActions--;
                printf("Player %d played %d \n", whoseTurn(&G), G.hand[G.whoseTurn][randActionCard]);

            }
        }
        
        
        //buy phase
        
        int money = updateCoins(G.whoseTurn, &G, 0);
        bool canbuycard =true;
        int maxNumberOfBuys = 3;
        enum CARD cardToBuy = (enum CARD)(int)floor(Random() * (treasure_map + 1));
        while(G.numBuys >0 && canbuycard==true && maxNumberOfBuys>0 && cardToBuy != curse){
            
            if(G.numBuys ==0 || G.coins ==0 || maxNumberOfBuys==false){
                canbuycard = false;
            }
            maxNumberOfBuys--;
            
            cardToBuy = (enum CARD)(int)floor(Random() * (treasure_map + 1));
            if(getCost(cardToBuy)<=money){
                int returnThing = buyCard(cardToBuy,&G);
                
                
                
                //printf("return of buy card: %d\n", returnThing);
                printf("Player %d purchased  %d \n", G.whoseTurn, cardToBuy);
            }
            money = updateCoins(G.whoseTurn, &G, 0);
        }
        
        //end turn
        endTurn(&G);
        
        

    }
    
    printf("Game over\n");
    for(i = 0; i<G.numPlayers;i++){
        
        
        printf("Player %d scored: %d\n", i, scoreFor(i, &G));
    }
    
    
    
    
    
    
    
    return 0;
}















