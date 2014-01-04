//
//  ScoreCore_Item.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Item.h"
#include "ScoreCore_Container.h"

// New item variables (parameters and container) are not supported as args anyway, so no reduction necessary when forwarding
Item::Item(args as) :
ScoreObject{as}
{}

std::vector<Parameter*> Item::getParameters(void) { return parameters; }

Container* Item::getContainer(void) { return container; }

/** [aux method] Parameters and Item *this are bidirectional linked. Method must not be called by user (only by designer of class with additional parameters).
 */
void Item::bilinkParameters(std::vector<Parameter*> ps) {
    for (auto p : ps) {
        parameters.push_back(p);
        p->setItem(this);
    }
}

/** [aux method] Container and Item *this are bidirectional linked. Method must not be called by user (called only once during initialisation).
 */
void Item::bilinkContainer(Container* c) {
    container = c;
    c->addItem(this);
}




