
/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"
//+1 card
//+2 actions

int main()
{
    int seed = 1000;
    int numPlayers = 2;
    struct gameState g, testg;
    int k[10] = {smithy,adventurer,sea_hag,embargo,tribute,minion,ambassador, steward,embargo,baron};

    //printf("first test:%d, testg.handCount[testg.whoseTurn])
    printf("----------------- TESTING CARD: %s ----------------\n", TESTCARD);

    initializeGame(numPlayers, k, seed, &g);
    memcpy(&testg, &g, sizeof(struct gameState));
    villageCard(&testg, 0);
    printf("Expected value: %d, Actual value: %d\n", g.handCount[g.whoseTurn] + 1, testg.handCount[testg.whoseTurn]);

    memcpy(&testg, &g, sizeof(struct gameState));
    villageCard(&testg, 0);

    //printf("final test:%d, testg.handCount[testg.whoseTurn])
    printf("Expected action count: %d, Actual action count: %d\n", g.numActions + 2, testg.numActions);

    printf("** END OF CARD TEST: %s **\n", TESTCARD);
    return 0;
}
