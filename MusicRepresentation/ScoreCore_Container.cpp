//
//  ScoreCore_Container.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Container.h"



// New item variables (parameters and container) are not supported as args anyway, so no reduction necessary when forwarding to TimeMixin
Container::Container(args as) :
Item{reduceArgsBy(as, std::vector<std::string>{"startTime", "offsetTime", "endTime", "duration"})},
TimeMixin{reduceArgsBy(as, std::vector<std::string>{"info"})}
#warning !! initialise vector items
{}


std::vector<Item> Container::getItems(void) { return items; }
