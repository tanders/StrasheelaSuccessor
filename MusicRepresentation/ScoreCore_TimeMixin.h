//
//  ScoreCore_TimeMixin.h
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreCore_TimeMixin__
#define __MusicRepresentation__ScoreCore_TimeMixin__

#include "ScoreCore_TypeArgs.h"
#include "ScoreCore_Parameter.h"

/*!  [abstract class] The TimeMixin adds several timing attributes and methods to its subclasses.
 The instance variables startTime and endTime are absolute TimePoints. The variable offsetTime is a relative TimeInterval, whose meaning depends on the enclosign container (semultaneous or sequential). The variable duration is the TimeInterval difference between startTime and endTime.
 */
class TimeMixin {
    TimeInterval offsetTime;
    TimePoint startTime;
    TimeInterval duration;
    TimePoint endTime;
    
public:
    TimeMixin(Args as);
    
#warning replace int by FD int var (and return reference of those vars?)
    int getOffsetTime(void) {return offsetTime.getValue();};
    int getStartTime(void) {return startTime.getValue();};
    int getDuration(void) {return duration.getValue();};
    int getEndTime(void) {return endTime.getValue();};

    // return pointer, because I do not want copy of FD int var (and because vector of pointers stored in variable parameters)
    TimeInterval* getOffsetTimeParameter(void) {return &offsetTime;};
    TimePoint* getStartTimeParameter(void) {return &startTime;};
    TimeInterval* getDurationParameter(void) {return &duration;};
    TimePoint* getEndTimeParameter(void) {return &endTime;};
    
    
#warning TODO: many functions still missing, see Strasheela
    
     
};


#endif /* defined(__MusicRepresentation__ScoreCore_TimeMixin__) */
