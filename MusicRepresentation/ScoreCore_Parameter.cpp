//
//  ScoreCore_Parameter.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Parameter.h"

using namespace std;

/** Args:
 int value: the parameter value
 string unit: parameter unit of measurement
 
 and args of ScoreObject
 */
Parameter::Parameter(args as) :
ScoreObject{reduceArgsBy(as, vector<string>{"value", "unit"})},
value{extractIntArg(as, "value", 0)},
unit{extractStringArg(as, "unit", "")}
{
    
}

int Parameter::getValue(void) { return value; }
string Parameter::getUnit(void) { return unit; }
Item* Parameter::getItem(void) { return item; };
/** %% [aux method] Method must not be called by user (must only used by Item::bilinkParameters).
 % */
void Parameter::setItem(Item* i) { item = i; };

