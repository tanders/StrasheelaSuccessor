//
//  ScoreCore_Container.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Container.h"


/*! Container constructor.
 
Arguments in Args as
\param vector<Item> items
\param int offsetTime
\param int startTime
\param int duration
\param int endTime

In addition all Args of constructors of Container superclasses are supported.
 
TODO: revise orig Strasheela doc:
The optional argument 'items' expects a list of items which are contained in the container instance. (Additionally, items can be given by calling the method bilinkItems.) A convenient shorthand notation for 'items' is the init method argument at record position 1.
  Example: init(MyItems ...)
 */
Container::Container(Args as) :
// Variables parameters and container are not supported as Args anyway, so no reduction necessary when forwarding to TimeMixin
Item{reduceArgsBy(as, std::vector<std::string>{"startTime", "offsetTime", "endTime", "duration"})},
TimeMixin{reduceArgsBy(as, std::vector<std::string>{"info"})}
#warning !! initialise vector items -- bilinkItems
{
    // problem: extractVectorOfScoreObjectsArg only works with vector<ScoreObject>, not vector<Item> -- need template variant...
//    this->bilinkItems(extractVectorOfScoreObjectsArg(as, "items"));
    this->bilinkParameters(std::vector<Parameter*> {
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

/*! [aux method] Container (*this) and Items are bidirectional linked. Function must not be called by user (called only once during initialisation).
 */
// TODO: make function private.
void Container::bilinkItems(std::vector<Item> xs) {
    for (auto x : xs) {
        items.push_back(x);
        x.setContainer(this);
    }
}

