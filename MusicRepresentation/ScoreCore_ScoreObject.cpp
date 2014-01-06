//
//  ScoreScore_ScoreObject.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_ScoreObject.h"

using namespace std;

/*! ScoreObject constructor with optional/named arguments wrapped in Args map.
 
 [constructor with map argument for optional/named arguments]
 Args:
 string info: arbitrary user information for this score object (additional infos can be added with nmember function addInfo)
 */
// TODO: handle argument could be added later: arg is *ScoreObject, which is bound in constructor to *this
ScoreObject::ScoreObject(Args as) {
    // process arg info
    if (as.count("info")){
        info.push_back(boost::apply_visitor(getStringArg(), as.at("info")));
        as.erase("info");
    }
    // raise exception if there are any remaining Args
    for(auto x: as)
        throw std::invalid_argument{"ScoreObject constructor: " + x.first + " is not supported as arg in Args map"};
};

/*! Returns vectors of all info strings stored. */
vector<string> ScoreObject::getInfo(void) { return info; }

/*! [destructive method] Adds myInfo to vector of stored infos. The internal vector info can store arbitrary user information.
 */
void ScoreObject::addInfo(string myInfo) { info.push_back(myInfo); }

/*! Returns bool whether myInfo is stored as an info in the object. */
bool ScoreObject::hasThisInfo(string myInfo) {
    return any_of(info.begin(), info.end(), [&](string s){return s.compare(myInfo) == 0;});
}

