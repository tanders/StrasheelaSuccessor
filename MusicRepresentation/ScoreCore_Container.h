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


// Simplification of Strasheela: Container is basically a TemporalAspect (only nesting in a tree, no graph)
class Container : public Item, public TimeMixin {
    std::vector<Item> items;
    
public:
    Container(args as);
    std::vector<Item> getItems(void);
    void addItem(Item*);

};


class Sequential : public Container {
public:
    void constrainTiming(void);
};

class Simultaneous : public Container {
public:
    void constrainTiming(void);
};


#endif /* defined(__MusicRepresentation__ScoreCore_Container__) */
