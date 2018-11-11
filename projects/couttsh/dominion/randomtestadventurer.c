#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main() {
    struct gameState g;
    int seed = 1000;
    int numPlayers = 2;
    int curPlayer = 0;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int deckSize;
    int handSize;
    int i;
    int j;
    int q;
    int randomCard;
    int randomHand;
    int m;
    int coinCount;
    int x;
    int discardCopper;
    int discardSilver;
    int discardGold;
    int coinCountPre;
    int testPassed = 0;
    int drawFailure = 0;
    int discardFailure = 0;
    clock_t tic = clock();

    
    srand(time(NULL));
    //randomize hand size
    for(i = 0; i < 5; i++){
        initializeGame(numPlayers, k, seed, &g);
        coinCountPre = 0;
        deckSize = rand() % (MAX_DECK + 1);
        //set handsize
        handSize = rand() % (deckSize + 1);
        
        
        g.deckCount[0] = deckSize - handSize;
        g.handCount[0] = handSize;
        
//        printf("Hand Size %d\n", handSize);

        for (j = 0; j < numPlayers; j++){
            for(q = 0;q < g.deckCount[j]; q++){
                randomCard = rand() % (50 + 1);
                randomHand = rand() % (10);

                if(randomCard == 1){
                    g.deck[j][q] = copper;
                } else if(randomCard == 2){
                    g.deck[j][q] = silver;
                }else if(randomCard == 3){
                    g.deck[j][q] = gold;
                }else {
                    g.deck[j][q] = k[randomHand];
                }
            }
        }
        
        for(m = 0; m < g.handCount[curPlayer]; m++){
            if(g.hand[curPlayer][m] == copper || g.hand[curPlayer][m] == silver || g.hand[curPlayer][m] == gold){
                coinCountPre++;
            }
        }
//        printf("Coin Count before: %d\n", coinCount);
//        printf("discard count before: %d\n", g.discardCount[curPlayer]);
//        printf("deckSize: %d, deck: %d, and hand: %d\n", deckSize, g.deckCount[0], g.handCount[0]);
        adventurerCard(curPlayer, &g);
        
        coinCount = 0;
        
        for(m = 0; m < g.handCount[curPlayer]; m++){
            if(g.hand[curPlayer][m] == copper || g.hand[curPlayer][m] == silver || g.hand[curPlayer][m] == gold){
                coinCount++;
            }
        }
//        printf("Coin Count after: %d\n", coinCount);
//        printf("discard count after: %d\n", g.discardCount[curPlayer]);
        discardCopper = 0;
        discardSilver = 0;
        discardGold = 0;
        for(x = 0; x < g.discardCount[curPlayer]; x++){
            if(g.discard[curPlayer][x] == copper) {
                discardCopper++;
            } else if(g.discard[curPlayer][x] == silver) {
                discardSilver++;
            } else if(g.discard[curPlayer][x] == gold) {
                discardGold++;
            }
        }
        int passed = 1;

        
        if(coinCount > (coinCountPre + 2)){
            printf("Too many cards drawn: Test Failed\n\n");
            drawFailure++;
            passed = 0;
        }

        if( coinCount < coinCountPre){
            printf("Fewer cards exist in hand than were first present: Test Failed\n\n");
            drawFailure++;
            passed = 0;
        }


        if(discardCopper != 0){
            printf("Copper was discarded: Test Failed\n\n");
            discardFailure++;
            passed = 0;
        }

        
        if(discardSilver != 0){
            printf("Silver was discarded: Test Failed\n\n");
            discardFailure++;
            passed = 0;
        }
        
        if(discardGold != 0){
            printf("Gold was discarded: Test Failed\n\n");
            discardFailure++;
            passed = 0;
        }
        
        if(passed == 1){
            printf("All Tests: Passed\n\n");
            testPassed++;
        }
    }
    
    printf("\n\n");
    printf("# of Tests Passed: %d\n", testPassed);
    printf("# of Cards Drawn To Hand Failed: %d\n", drawFailure);
    printf("# of Adventurer Discarded Fails: %d\n\n", discardFailure);
    
    clock_t toc = clock();
    
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
    return 0;
}
