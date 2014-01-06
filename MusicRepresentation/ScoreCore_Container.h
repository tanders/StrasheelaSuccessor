//
//  ScoreCore_Container.h
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreCore_Container__
#define __MusicRepresentation__ScoreCore_Container__

//#include "ScoreCore_ScoreObject.h" // TMP
#include "ScoreCore_Item.h"
#include "ScoreCore_TimeMixin.h"


/*! [abstract class] A container contains one or more score items.
  
 The variable items points to the items contained in a container. Because containers themself are items as well, a container can contain other containers to form a score hierarchy of containers and elements. However, a container must not contain itself.
 */
// Simplification of Strasheela: Container is basically a TemporalAspect (only nesting in a tree, no graph)
class Container : public Item, public TimeMixin {
    std::vector<Item> items;
    
public:
    Container(Args as);
    std::vector<Item> getItems(void);
    void addItem(Item*);
    
    void bilinkItems(std::vector<Item> xs);

};


/*! [concrete class] A Sequential expresses that the items contained in it follow each other in a sequential manner in time. 
 
 TODO: revise orig Strasheela doc
 Usually, the parameter endTime of a proceeding item equals the parameter startTime of the following item. However, setting the parameter offsetTime of an item to a value greater zero causes a gap (i.e. a pause) before the item and a negative offsetTime causes an overlap with the proceeding item.
 For a documentation of the time unit see doc of TimeMixin.
 NB: A negative offsetTime value is not possible if the offsetTime is a FD integer (which presently is the only option).
  */
class Sequential : public Container {
public:
    void constrainTiming(void);
};

/*! [concrete class] A Simultaneous expresses that the items contained in it start at the same time.  
 
 However, setting the parameter offsetTime of an item to a value greater zero causes this item to delay its startTime the amount of offsetTime.
For a documentation of the time unit see doc of TimeMixin.
 */
class Simultaneous : public Container {
public:
    void constrainTiming(void);
};


#endif /* defined(__MusicRepresentation__ScoreCore_Container__) */
