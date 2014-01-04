//
//  ScoreCore_TimeMixin.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_TimeMixin.h"

#warning unify all timeUnit values
/*!
 Args:
 int offsetTime (later Gecode::IntVar)
 int startTime
 int duration
 int endTime
 string timeUnit
 
The timeUnit specifies what the numeric values for the values of the parameters like startTime and endTime actually mean. The timeUnit either specifies an absolute value (e.g., "seconds") or a relative value (e.g., "beats"). The meaning of a beat depends on the output definition. For instance, it may mean a quarter note. 
 // TODO: update doc -- this is still the Strasheela doc, until these value conversions are actually implemented
 Currently, possible values are 'seconds' (or 'secs'), 'milliseconds' (or 'msecs'), 'beats', or beats(N), where  N means number of ticks (i.e. the integer range) within a beat. For example, if the timeUnit = beats(4) and a beat corresponds to a quarter note, then a note of duration 1 corresponds to a sixteenth note. beats is equivalent with beats(1). The meaning of a beat for sound output can be specified by the tempo (see Init.setBeatDuration, Init.setTempo etc.)
 
 NB: To avoid confusion, the timeUnit of all temporal items in the score are unified when a score is created.
 */
TimeMixin::TimeMixin(Args as) :
#warning hardcoded default timeUnit
offsetTime{TimeInterval {Args
    {{"value", extractIntArg(as, "offsetTime", 0)},
     {"unit",  extractStringArg(as, "timeUnit", "beats")}}}},
startTime{TimePoint {Args
    {{"value", extractIntArg(as, "startTime", 0)},
        {"unit",  extractStringArg(as, "timeUnit", "beats")}}}},
duration{TimeInterval {Args
    {{"value", extractIntArg(as, "duration", 0)},
        {"unit",  extractStringArg(as, "timeUnit", "beats")}}}},
endTime{TimePoint {Args
    {{"value", extractIntArg(as, "endTime", 0)},
        {"unit",  extractStringArg(as, "timeUnit", "beats")}}}}
{}

