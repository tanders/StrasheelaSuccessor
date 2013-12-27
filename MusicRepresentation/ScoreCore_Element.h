//
//  ScoreCore_Element.h
//  MusicRepresentation
//
//  Created by torsten on 27/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreCore_Element__
#define __MusicRepresentation__ScoreCore_Element__

#include "ScoreCore_TimeMixin.h"
#include "ScoreCore_Item.h"

// Simplification of Strasheela: Element is a TemporalElement (only nesting in a tree, no graph)
class Element : public Item, public TimeMixin {
public:
    Element(args as);
};



#endif /* defined(__MusicRepresentation__ScoreCore_Element__) */
