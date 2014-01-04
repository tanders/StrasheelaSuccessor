//
//  ScoreCore_TypeArgs.cpp
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

/*! \file ScoreCore_TypeArgs.cpp
 Defines types and classes which allow to quasi hand optional and named parameters to score object constructors. These parameters are wrapped in a map called Args.
 */

#include <boost/lexical_cast.hpp>
#include "ScoreCore_TypeArgs.h"

using namespace std;

/*******************************************************************************************************/
//
// Defining Args typ for accessing optional and named arguments for constructors of ScoreObject and subclasses.
//
/*******************************************************************************************************/

string getStringArg::operator()(string& str) const {
    return str;
}
string getStringArg::operator()(int & i) const {
    throw invalid_argument{"Not a string: " + boost::lexical_cast<string>(i)};
}
string getStringArg::operator()(ScoreObject& x) const {
    throw invalid_argument{"Not a string: " // + boost::lexical_cast<string>(x)
    };
}
string getStringArg::operator()(std::vector<ScoreObject>& xs) const {
    throw invalid_argument{"Not a string: " // + boost::lexical_cast<string>(xs)
    };
}

int getIntArg::operator()(int & i) const {
    return i;
}
int getIntArg::operator()(string& str) const {
    throw invalid_argument{"Not an int: " + str};
}
int getIntArg::operator()(ScoreObject& x) const {
    throw invalid_argument{"Not an int: " // + boost::lexical_cast<string>(x)
    };
}
int getIntArg::operator()(std::vector<ScoreObject>& xs) const {
    throw invalid_argument{"Not a string: " // + boost::lexical_cast<string>(xs)
    };
}

ScoreObject getScoreObjectArg::operator()(ScoreObject& x) const {
    return x;
}
ScoreObject getScoreObjectArg::operator()(string& str) const {
    throw invalid_argument{"Not an ScoreObject: " + str};
}
ScoreObject getScoreObjectArg::operator()(int & i) const {
    throw invalid_argument{"Not an ScoreObject" // + boost::lexical_cast<string>(i)
    };
}
ScoreObject getScoreObjectArg::operator()(std::vector<ScoreObject>& xs) const {
    throw invalid_argument{"Not a string" // + boost::lexical_cast<string>(xs)
    };
}


std::vector<ScoreObject> getVectorOfScoreObjectsArg::operator()(std::vector<ScoreObject>& xs) const {
    return xs;
}
std::vector<ScoreObject> getVectorOfScoreObjectsArg::operator()(string& str) const {
    throw invalid_argument{"Not a vector<ScoreObject>: " + str};
}
std::vector<ScoreObject> getVectorOfScoreObjectsArg::operator()(int & i) const {
    throw invalid_argument{"Not a vector<ScoreObject>: " // + boost::lexical_cast<string>(i)
    };
}
std::vector<ScoreObject> getVectorOfScoreObjectsArg::operator()(ScoreObject& x) const {
    throw invalid_argument{"Not a vector<ScoreObject>" // + boost::lexical_cast<string>(x)
    };
}

/*******************************************************************************************************/
//
// Aux functions
//
/*******************************************************************************************************/


/*! Returns a copy of Args map as, reduced by the keys in keys
 */
Args reduceArgsBy(Args as, vector<string> keys) {
    for(auto key: keys) {
        as.erase(key);
    }
    return as;
}


/*! Extracts arg named argName from Args map as. If not contained in as, then defaultVal is return instead.
 */
// TODO: consider rewriting with type template
int extractIntArg(Args as, string argName, int defaultVal){
    return as.count(argName) ?
    boost::apply_visitor(getIntArg(), as.at(argName)) :
    defaultVal;
}
string extractStringArg(Args as, string argName, string defaultVal){
    return as.count(argName) ?
    boost::apply_visitor(getStringArg(), as.at(argName)) :
    defaultVal;
}
// // Before uncommenting again find suitable default value (corresponding to nil)
//ScoreObject extractScoreObjectArg(Args as, string argName){
//    return as.count(argName) ?
//    boost::apply_visitor(getScoreObjectArg(), as.at(argName)) :
//    void; // is this equivalent of nil?
//}
std::vector<ScoreObject> extractVectorOfScoreObjectsArg(Args as, string argName){
    return as.count(argName) ?
    boost::apply_visitor(getVectorOfScoreObjectsArg(), as.at(argName)) :
    // empty vector as default (TODO: when/how is this deleted)
    std::vector<ScoreObject> {};
}
