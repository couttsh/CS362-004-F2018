#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


//testing smithy
int main() {
    
    struct gameState g;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int deckSize;
    int handSize;
    int handPos;
    int deckPre;
    int deckPost;
    int handPre;
    int handPost;
    int discardPre;
    int discardPost;
    int i;
    int deckFailure = 0;
    int handFailure = 0;
    int discardFailure = 0;
    int testPassed = 0;
    int passed;
    clock_t tic = clock();
    
    srand(time(NULL));
    //randomize hand size
    //    for(i = 0; i < 1000000; i++){
    for(i = 0; i < 1000000; i++){
        initializeGame(numPlayers, k, seed, &g);
        deckSize = rand() % (MAX_DECK + 1);
        //set handsize
        handSize = rand() % (deckSize + 1);
        
        
        g.deckCount[0] = deckSize - handSize;
        g.handCount[0] = handSize;
        
        handPos = g.hand[curPlayer][g.handCount[curPlayer] - 1];
        //personal checks
        deckPre = g.deckCount[0];
        //        printf("deck before %d\n", deckPre);
        handPre = g.handCount[0];
        //        printf("Hand before %d\n",handPre);
        discardPre = g.playedCardCount;
        //        printf("Discard before %d\n", discardPre);
        
        useSmithy(k, curPlayer, handPos, &g);
        
        deckPost = g.deckCount[0];
        //        printf("deck after %d\n", deckPost);
        handPost = g.handCount[0];
        //        printf("hand After %d\n", handPost);
        discardPost = g.playedCardCount;
        //        printf("Discard After %d\n\n", discardPost);
        
        passed = 1;
        
        if(handPost != (handPre + 2)){
            printf("Incorrect amount of cards drawn: Test Failed\n\n");
            handFailure++;
            passed = 0;
        }
        
        if(deckPost != (deckPre - 3)){
            printf("Incorrect number of cards removed from deck: Test Failed\n\n");
            deckFailure++;
            passed = 0;
        }
        
        if(discardPost != (discardPre + 1)){
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
    printf("# of Smithy Discarded Fails: %d\n\n", discardFailure);
    
    clock_t toc = clock();
    
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
    return 0;
}
