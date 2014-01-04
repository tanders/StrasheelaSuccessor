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
typedef std::map<std::string, boost::variant<int,std::string,ScoreObject,std::vector<ScoreObject>>> Args;

#include "ScoreCore_TypeArgs.h"

/*! [abstract class] The most general data type for score data is a ScoreObject. 
  */
class ScoreObject {
    std::vector<std::string> info;
    //    int id;  // Perhaps I need id later again...
    
public:
    ScoreObject(Args as);
    
    std::vector<std::string> getInfo(void);
    void addInfo(std::string myInfo);
    bool hasThisInfo(std::string myInfo);
    
    #warning TODO -- many member functions still missing -- see Strasheela source
};


#endif /* defined(__MusicRepresentation__ScoreScore_ScoreObject__) */
