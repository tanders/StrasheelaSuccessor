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

/**  [abstract class] The TimeMixin adds several timing attributes and methods to its subclasses.
 The instance variables startTime and endTime are absolute TimePoints. The variable offsetTime is a relative TimeInterval, whose meaning depends on the enclosign container (semultaneous or sequential). The variable duration is the TimeInterval difference between startTime and endTime.
 */
class TimeMixin {
    int startTime, endTime, offsetTime, duration;
    
public:
    TimeMixin(args as);
    
    // !! TODO: many functions, see Strasheela
};


#endif /* defined(__MusicRepresentation__ScoreCore_TimeMixin__) */
