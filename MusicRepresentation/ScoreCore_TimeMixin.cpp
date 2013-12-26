//
//  ScoreCore_TimeMixin.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_TimeMixin.h"

// !! TODO doc
/**
 Args
 int startTime
 int endTime
 int offsetTime
 int duration
 
 !! TODO: REVISE: The TimeUnit specifies what the numeric values for the TimeMixin attributes actually mean. The TimeUnit either specifies an absolute value (e.g. seconds) or a relative value (e.g. beats). The meaning of beat depends on the output definition, for instance, for the Lilypond output a beat is a quarter note. Currently, possible values are 'seconds' (or 'secs'), 'milliseconds' (or 'msecs'), 'beats', or beats(N), where  N means number of ticks (i.e. the integer range) within a beat. For example, if the TimeUnit = beats(4) and a beat corresponds to a quarter note, then a note of duration 1 corresponds to a sixteenth note. beats is equivalent with beats(1). The meaning of a beat for sound output can be specified by the tempo (see Init.setBeatDuration, Init.setTempo etc.)
 NB: to avoid confusion, the time units of all temporal items in the score are unified when a Strasheela score is initialised.
 NB: A negative offsetTime value is not possible if the offsetTime is a FD integer (which presently is the only option). For the other temporal parameters, a negative value does not make sense anyway.
 */
TimeMixin::TimeMixin(args as) :
startTime{extractIntArg(as, "startTime", 0)},
endTime{extractIntArg(as, "endTime", 0)},
offsetTime{extractIntArg(as, "offsetTime", 0)},
duration{extractIntArg(as, "duration", 0)}
{}

