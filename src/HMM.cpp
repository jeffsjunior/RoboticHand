#include "HMM.h"
#include "TrueRandom.h"

//Definitions
const char* const statesStr[nStates] = {"Happy", "Sad", "Angry"};
const char* const behaviorsStr[nBehaviors] = {"Peace", "Rock", "Tranquilo"};

//Transition and Emission Parameters of the Hidden Markov Model
//                       state      Transition              Emission
sState statesArray[] = {{sHappy, {0.8, 0.1, 0.1}, {0.4, 0.4, 0.068}},
                        {sSad,   {0.1, 0.8, 0.1}, {0.05, 0.05, 0.4}},
                        {sAngry, {0.1, 0.1, 0.8}, {0.05, 0.05, 0.1}}};

sBehavior behaviorsArray[] = {{peace, &Hand::peaceGest},
                              {rock, &Hand::rockGest},
                              {tranquilo, &Hand::tranquilo_favoravel}};

//Functions
sState nextState(sState currentState){
    uint8_t i = sortPMF(currentState.transitionProb, nStates);
    return statesArray[i];
}

uint8_t sortPMF(float pdf[], uint8_t numel){
    float x = trueRandom(0, 1025)/1024.0;
    float pCum = pdf[0];

    uint8_t i = 0;
    while((x > pCum) && (i < numel)){
        i++;
        pCum += pdf[i];
    }
    return i;
}

tBehavior runBehavior(sState currentState, Hand behaviorObj){
    uint8_t i = sortPMF(currentState.behaviorProb, nBehaviors);
    (behaviorObj.*behaviorsArray[i].run)(100); //TODO: change!

    return behaviorsArray[i].behavior;
}


//// Utils
void printData(sState sCurrent, tBehavior bSelected){
    Serial.println("~~~~~~~~~~~~~~~~~");
    Serial.print("Current State: "); Serial.println(statesStr[sCurrent.state]); Serial.println();

    Serial.println("~~Next State Prob.~~ "); 
    for(int i = 0; i<nStates;i++)
    {
        Serial.print(statesStr[i]);Serial.print(": ");
        Serial.println(statesArray[sCurrent.state].transitionProb[i]);
    }
    Serial.println();

    Serial.println("~~Behavior Prob.~~ "); 
    for(int i = 0; i<nBehaviors;i++)
    {
        Serial.print(behaviorsStr[i]);Serial.print(": ");
        Serial.println(statesArray[sCurrent.state].behaviorProb[i]);
    }
    Serial.println();
    Serial.print("Chosen Behavior: "); Serial.println(behaviorsStr[bSelected]);
    Serial.println("~~~~~~~~~~~~~~~~~");
    Serial.println();
}