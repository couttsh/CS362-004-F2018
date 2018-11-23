/*
 * cardtest2.c
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

////adventure card test

#define TESTCARD "adventurer"
/*
 Reveal cards from deck until you reveal 2 Treasure cards.
 Put those Treasure cards into your hand and discard the
 other revealed cards.
 */

int main()
{

    int x, treas, draw;
    int treas1 = 0;
    int treas2 = 0;
    int i = 0;
    int temp[MAX_HAND];
    int seed = 1000;
    int numPlayers = 2;
    struct gameState g, testg;
    //have to declare all cards in the array
    int k[10] = {smithy,adventurer,sea_hag,embargo,tribute,minion,ambassador, steward,embargo,baron};
    //copied from dominion.c to make function run
    int tempHand[MAX_HAND];// moved above the if statement
    int drawnTreasure=0;
    int cardDrawn;
    int curPlayer = 1;
    int z = 0;// this is the counter for the temp hand
    //output tests

   printf("----------------- TESTING CARD: %s ----------------\n", TESTCARD);//

    //printf("first test :%d, Result: %d\n", g.handCount[g.whoseTurn] + 2, testg.handCount[testg.whoseTurn])
    initializeGame(numPlayers, k, seed, &g);
    memcpy(&testg, &g, sizeof(struct gameState));
    testg.hand[testg.whoseTurn][0] = minion;

    //printf("second test :%d, Result: %d\n", g.handCount[g.whoseTurn] + 2, testg.handCount[testg.whoseTurn])
    useAdventurer(z, drawnTreasure, curPlayer, &g, cardDrawn, tempHand);
    printf("Expected value: %d, Result: %d\n", g.handCount[g.whoseTurn] + 2, testg.handCount[testg.whoseTurn]);

    g.discardCount[g.whoseTurn] = 5;
    memcpy(&testg, &g, sizeof(struct gameState));
//    adventurerCard(&testg, 0);
    useAdventurer(z, drawnTreasure, curPlayer, &g, cardDrawn, tempHand);


    while(treas<2){
        drawCard(g.whoseTurn, &g);
        draw = g.hand[g.whoseTurn][g.handCount[g.whoseTurn]-1];
        if (draw == copper || draw == silver || draw == gold){
            treas++;
        }
        else{
            temp[i]=draw;
            g.handCount[g.whoseTurn]--;
            i++;
        }
    }
    //printf("third test:%d, testg.handCount[testg.whoseTurn])
    printf("Expected  card count: %d, Result: %d\n", g.discardCount[g.whoseTurn] + i, testg.discardCount[testg.whoseTurn]);

    for(x = 0; x < g.handCount[g.whoseTurn]; x++){
        if (g.hand[g.whoseTurn][x] == copper || g.hand[g.whoseTurn][x] == silver || g.hand[g.whoseTurn][x] == gold){
            treas1++;
        }

    }

    for(x = 0; x < testg.handCount[testg.whoseTurn]; x++){
        if (testg.hand[testg.whoseTurn][x] == copper || testg.hand[testg.whoseTurn][x] == silver || testg.hand[testg.whoseTurn][x] == gold){
            treas2++;
            //printf("final test:%d, testg.handCount[testg.whoseTurn])
        }

    }

    printf("Final expected treasure count: %d, Result: %d\n", treas1, treas2);

    printf("** END OF CARD TEST: Adventure **\n");

    return 0;
}
