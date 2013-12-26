//
//  ScoreCore_TypeArgs.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include <boost/lexical_cast.hpp>
#include "ScoreCore_TypeArgs.h"

using namespace std;

/*******************************************************************************************************/
//
// Defining args typ for accessing optional and named arguments for constructors of ScoreObject and subclasses.
//
/*******************************************************************************************************/

string getStringArg::operator()(string& str) const {
    return str;
}
string getStringArg::operator()(int & i) const {
    throw invalid_argument{"Not a string: " + boost::lexical_cast<string>(i)};
}

int getIntArg::operator()(string& str) const {
    throw invalid_argument{"Not an int: " + str};
}
int getIntArg::operator()(int & i) const {
    return i;
}

/*******************************************************************************************************/
//
// Aux functions
//
/*******************************************************************************************************/

/** Returns a copy of args map as, reduced by the keys in keys
 */
args reduceArgsBy(args as, vector<string> keys) {
    for(auto key: keys) {
        as.erase(key);
    }
    return as;
}


/** Extracts arg named argName from args map as. If not contained in as, then defaultVal is return instead.
 */
// TODO: consider rewriting with type template
int extractIntArg(args as, string argName, int defaultVal){
    return as.count(argName) ?
    boost::apply_visitor(getIntArg(), as.at(argName)) :
    defaultVal;
}
string extractStringArg(args as, string argName, string defaultVal){
    return as.count(argName) ?
    boost::apply_visitor(getStringArg(), as.at(argName)) :
    defaultVal;
}

