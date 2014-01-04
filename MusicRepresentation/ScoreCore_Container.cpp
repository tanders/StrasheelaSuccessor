//
//  ScoreCore_Container.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Container.h"


/*! Container constructor.
 
Arguments in args as
\param vector<Item> items
\param int offsetTime
\param int startTime
\param int duration
\param int endTime

In addition all args of constructors of Container superclasses are supported.
 
TODO: revise orig Strasheela doc:
The optional argument 'items' expects a list of items which are contained in the container instance. (Additionally, items can be given by calling the method bilinkItems.) A convenient shorthand notation for 'items' is the init method argument at record position 1.
  Example: init(MyItems ...)
 */
Container::Container(args as) :
// Variables parameters and container are not supported as args anyway, so no reduction necessary when forwarding to TimeMixin
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

/*! [aux def] Adds an item to container -- should not be called by users.
 */
void Container::addItem(Item* x) {
    items.push_back(*x);
}
