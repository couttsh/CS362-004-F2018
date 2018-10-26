//TESTING: isGameOver

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    printf("\n UNIT TEST #3\n");
    struct gameState g;
    struct gameState * y = &g;
    int k[10] = {smithy,adventurer,sea_hag,embargo,tribute,minion,ambassador, steward,embargo,baron};
   // printf("Checkpoint 1\n");
    initializeGame(2, k, 5, &g);
   // printf("Checkpoint 2\n");
    int a = isGameOver(y);
   // printf("Checkpoint 3\n");
    assert(a == 1);
    printf("Test passed! \n");

    return 0;
}
