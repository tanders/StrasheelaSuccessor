//
//  ScoreScore_ScoreObject.h
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreScore_ScoreObject__
#define __MusicRepresentation__ScoreScore_ScoreObject__

#include "ScoreCore_TypeArgs.h"

/** [abstract class] The most general data type for score data is a ScoreObject. info can store arbitrary user information (internally a vector of strings).
 */
class ScoreObject {
    //    int id;  // Perhaps I need id later again...
    // !! TODO: does class destructor explicitly need to delete any internal vector?
    std::vector<std::string> info;
    
public:
    ScoreObject(args as);
    std::vector<std::string> getInfo(void);
    void addInfo(std::string myInfo);
    bool hasThisInfo(std::string myInfo);
    
    // !! TODO -- many member functions still missing -- see Strasheela source
    
};


#endif /* defined(__MusicRepresentation__ScoreScore_ScoreObject__) */
