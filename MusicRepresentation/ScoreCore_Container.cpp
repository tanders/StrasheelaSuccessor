//
//  ScoreCore_Container.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Container.h"


/** Constructor args:
    vector<Item> items
    int offsetTime
    int startTime
    int duration
    int endTime
    args of constructors of Container superclasses.
 */
// New item variables (parameters and container) are not supported as args anyway, so no reduction necessary when forwarding to TimeMixin
Container::Container(args as) :
Item{reduceArgsBy(as, std::vector<std::string>{"startTime", "offsetTime", "endTime", "duration"})},
TimeMixin{reduceArgsBy(as, std::vector<std::string>{"info"})}
#warning TMP comment: initialise items
//items{"items", extractVectorOfScoreObjectsArg(as, "items")}
#warning !! initialise vector items -- bilinkItems
{ this->bilinkParameters(std::vector<Parameter*> {
    this->getOffsetTimeParameter(),
    this->getStartTimeParameter(),
    this->getDurationParameter(),
    this->getEndTimeParameter()}); }
//{ this->bilinkParameters(std::vector<Parameter&>
//    { this->getOffsetTime(), this->getStartTime(), this->getDuration(), this->getEndTime()}) }


std::vector<Item> Container::getItems(void) { return items; }

/* [aux def] Adds an item to container -- should not be called by users.
 */
void Container::addItem(Item* x) {
    items.push_back(*x);
}
