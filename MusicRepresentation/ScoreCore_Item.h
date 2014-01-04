//  ScoreCore_Item.h
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreCore_Item__
#define __MusicRepresentation__ScoreCore_Item__

// forward declared dependencies
// -> Container def should go into its own file, and this declaration at the top of this file.
class Container;
class Parameter; // TODO: BUG: should not be needed, as Parameter class def is included!

#include "ScoreCore_Parameter.h"

// TODO: add public MappingMixin
// Avoid mutual dependencies between class defs of Item and Container with forward-declare and a reference, see
// http://stackoverflow.com/questions/1429336/cross-referencing-included-headers-in-c-program
// http://www.cplusplus.com/forum/articles/10627/
class Item : public ScoreObject {
    // Parameter objects stored already elsewhere, therefore only pointers to those params
    // No smart pointer, because this is only a back-reference to an object cared for elesewhere
    std::vector<Parameter*> parameters;
    Container* container; // backwards reference -- must be reference because otherwise they contain each other indefinitely
    void bilinkContainer(Container*);

public:
    Item(args as);
    std::vector<Parameter*> getParameters(void);
    Container* getContainer(void);

    void bilinkParameters(std::vector<Parameter*> ps);
    
    // TODO: many missing Item functions

};


#endif /* defined(__MusicRepresentation__ScoreCore_Item__) */
