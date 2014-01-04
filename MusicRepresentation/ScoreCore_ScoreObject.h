//
//  ScoreScore_ScoreObject.h
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreScore_ScoreObject__
#define __MusicRepresentation__ScoreScore_ScoreObject__

#include <map>
#include <vector>
#include <boost/variant.hpp>

class ScoreObject;
typedef std::map<std::string, boost::variant<int,std::string,ScoreObject,std::vector<ScoreObject>>> args;

#include "ScoreCore_TypeArgs.h"

/*! [abstract class] The most general data type for score data is a ScoreObject. info can store arbitrary user information (internally a vector of strings).
 */
class ScoreObject {
    //    int id;  // Perhaps I need id later again...
    std::vector<std::string> info;
    
public:
    ScoreObject(args as);
    
    std::vector<std::string> getInfo(void);
    void addInfo(std::string myInfo);
    bool hasThisInfo(std::string myInfo);
    
    #warning TODO -- many member functions still missing -- see Strasheela source
};


#endif /* defined(__MusicRepresentation__ScoreScore_ScoreObject__) */
