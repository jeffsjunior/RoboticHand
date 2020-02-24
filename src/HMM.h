/*  This code implements a Hidden Markov Model
    The transition probabilites and emission probabilities
    are to be added in the variable sState statesArray[]
    Implemented by: Jefferson Junior.
    Date: February 21, 2020.
*/

#ifndef HMM_H
#define HMM_H
#include "Hand.h"

//  Structures
typedef enum { sHappy, sSad, sAngry, nStates} tState;
extern const char* const statesStr[nStates];

typedef enum {peace, rock, tranquilo, nBehaviors} tBehavior;


typedef void (Hand::*behaviorFun)(void);

typedef struct{
    tBehavior behavior;
    behaviorFun run;
} sBehavior;

typedef struct {
    tState state;
    float transitionProb[nStates];
    float behaviorProb[nBehaviors];
} sState ;


extern sState statesArray[];

extern sBehavior behaviorsArray[];


//  Functions
sState nextState(sState currentState); //, sState statesArray[]
tBehavior runBehavior(sState currentState, Hand handObj); //, sBehavior behaviorsArray[]
void printData(sState sCurrent, tBehavior bSelected);
uint8_t sortPMF(float pdf[], uint8_t numel);

#endif