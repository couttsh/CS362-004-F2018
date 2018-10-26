//TESTING function: buycard

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <assert.h>

int main(){
    printf("\n UNIT TEST #2: buyCard\n");
    struct gameState g;
    struct gameState * y = &g;
    int test = 0;
    
    g.coins = 2;
    g.numBuys = 2;
    printf("Do we have enough coins in our hand to buy a card?\n");
    test = buyCard(2, y);
    if(test != -1)
        printf("Test failed!\n");
    else
        printf("Test passed!\n");
    
    printf("Can we buy the card we want?\n");
    g.coins = 12;
    test = buyCard(2, y);
    if (test == 0)
        printf("Test passed!\n");
    else
        printf("Test failed!\n");
    
    printf("Do we have any existing buys?\n");
    g.coins = 6;
    test = buyCard(2, y);
    if(test == -1)
        printf("Test passed! \n");
    else
        printf("Test failed! \n");
    
    return 0;
    
}
