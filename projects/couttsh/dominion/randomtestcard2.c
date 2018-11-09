#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


//testing sea hag
int main() {
    
    struct gameState G;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int deckSize;
    int handSize;
    int handPos;
    int deckBefore;
    int deckAfter;
    int handBefore;
    int handAfter;
    int discardBefore;
    int discardAfter;
    int actionsBefore;
    int actionsAfter;
    int i;
    int deckFailure = 0;
    int handFailure = 0;
    int actionFailure = 0;
    int discardFailure = 0;
    int testPassed = 0;
    int passed;
    clock_t tic = clock();
    
    srand(time(NULL));
    //randomize hand size
    //    for(i = 0; i < 1000000; i++){
    for(i = 0; i < 1000000; i++){
        initializeGame(numPlayers, k, seed, &G);
        deckSize = rand() % (MAX_DECK + 1);
        //set handsize
        handSize = rand() % (deckSize + 1);
        
        
        G.deckCount[0] = deckSize - handSize;
        G.handCount[0] = handSize;
        
        handPos = G.hand[curPlayer][G.handCount[curPlayer] - 1];
        //personal checks
        deckBefore = G.deckCount[0];
                printf("deck before %d\n", deckBefore);
        handBefore = G.handCount[0];
                printf("Hand before %d\n",handBefore);
        discardBefore = G.playedCardCount;
                printf("Discard before %d\n", discardBefore);
        actionsBefore = G.numActions;
                printf("Actions before %d\n", actionsBefore);
        
        
        villageCard(curPlayer, &G, handPos);
        
        deckAfter = G.deckCount[0];
                printf("deck after %d\n", deckAfter);
        handAfter = G.handCount[0];
                printf("hand After %d\n", handAfter);
        discardAfter = G.playedCardCount;
                printf("Discard After %d\n\n", discardAfter);
        actionsAfter = G.numActions;
            printf("Actions before %d\n", actionsAfter);
        
        passed = 1;
        
        if(handAfter != (handBefore + 1)){
            printf("Incorrect amount of cards drawn: Test Failed\n\n");
            handFailure++;
            passed = 0;
        }
        
        if(deckAfter != (deckBefore - 1)){
            printf("Incorrect number of cards removed from deck: Test Failed\n\n");
            deckFailure++;
            passed = 0;
        }
        
        
        if(actionsBefore == actionsAfter){
            printf("Incorrect number of actions taken: Test Failed\n\n");
            actionFailure++;
            passed = 0;
        }
        
        if(actionsAfter != (actionsBefore + 2)){
            printf("Incorrect number of actions taken: Test Failed\n\n");
            actionFailure++;
            passed = 0;
        }
        
        if(discardAfter != (discardBefore + 1)){
            printf("Smithy Not Discarded after use: Test Failed\n\n");
            discardFailure++;
            passed = 0;
        }
        
        if(passed == 1){
            printf("All Tests Passed!! Horray lucky us!\n\n");
            testPassed++;
        }
        
    }
    
    printf("\n\n");
    printf("# of Tests Passed: %d\n", testPassed);
    printf("# of Cards Drawn To Hand Failed: %d\n", handFailure);
    printf("# of Village Discarded Fails: %d\n\n", discardFailure);
    
    clock_t toc = clock();
    
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
    return 0;
}

