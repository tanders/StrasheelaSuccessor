//
//  ScoreCore.h
//  MusicRepresentation
//
//  Created by torsten on 25/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreCore__
#define __MusicRepresentation__ScoreCore__

#include <vector>
#include <map>
#include <boost/variant.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;


/*******************************************************************************************************/
//
// Defining args typ for accessing optional and named arguments for constructors of ScoreObject and subclasses.
//
/*******************************************************************************************************/

// typedef boost::variant<int,string> arg;
/** Shorthand type for argument maps for score object initialisation, which allow for optional and named arguments for constructors of ScoreObject and subclasses. Conveniently create argument map for constructors like
 
 SomeScoreObjectClass x = {args {{"arg1", 42}, {"arg2", "test"}}}
 */
// boost::variant doc: http://www.boost.org/doc/libs/1_55_0/doc/html/variant.html
typedef map<string, boost::variant<int,string>> args;

/*******************************************************************************************************/
//
// Music representation class hierarchy
//
/*******************************************************************************************************/



#endif /* defined(__MusicRepresentation__ScoreCore__) */
