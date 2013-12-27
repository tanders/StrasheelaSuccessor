//
//  ScoreCore_Element.cpp
//  MusicRepresentation
//
//  Created by torsten on 27/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Element.h"


Element::Element(args as) :
Item{reduceArgsBy(as, std::vector<std::string>{"startTime", "offsetTime", "endTime", "duration"})},
TimeMixin{reduceArgsBy(as, std::vector<std::string>{"info"})}
{}

