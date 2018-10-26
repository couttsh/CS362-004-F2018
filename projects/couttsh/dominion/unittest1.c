//TESTING Function
//int whoseTurn(struct gameState *state) {
//return state->whoseTurn;
//}
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    printf("\n UNIT TEST #1: Whose Turn? \n");
    struct gameState g;
    struct gameState * y = &g;
    int k[10] = {smithy,adventurer,sea_hag,embargo,tribute,minion,ambassador, steward,embargo,baron};
    //int a;

    for(int i = 2; i < 5; ++i){
            initializeGame(2, k, 5, y);
            int a = whoseTurn(y);
            assert(a == g.whoseTurn);
            printf("PASSED \n");
            }
    
    return 0;
}
