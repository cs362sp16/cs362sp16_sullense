#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



void myAssertGetCost(int a, int b){
     printf("\n Unittest2: \n");
    if(a==b){
        printf("ASSERT SUCCESSFUL. Cost of silver: 3, getCost returned: %d\n", b);
    }
    else{
        printf("ASSERT FAILED. Not the right cost. What getCost returned: %d. Actual cost: 3\n", b);
    }
    
}

//this unit test tests that getCost returns the correct value for silver
int main (int argc, char** argv) {
    int c = getCost(silver);
    myAssertGetCost(3,c);
    
    return 0;
}
