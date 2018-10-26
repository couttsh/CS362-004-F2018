//TESTING FUNCTION:  numHandCards

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    printf("\n UNIT TEST #4\n");
    struct gameState g;
    struct gameState * y = &g;
    int k[10] = {smithy,adventurer,sea_hag,embargo,tribute,minion,ambassador, steward,embargo,baron};
    initializeGame(2, k, 5, &g);
    assert((y->handCount[whoseTurn(y)]) == 0);
    //printf("checkpoint 1");
    assert(numHandCards(y) == 0);
    
    printf("Test passed!\n");
    
    return 0;
}
