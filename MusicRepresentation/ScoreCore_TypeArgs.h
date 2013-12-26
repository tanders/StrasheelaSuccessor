//
//  ScoreCore_TypeArgs.h
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

/* // Musing on design
 
 In Strasheela the score object constructors are a large number of named arguments, and the constructor definition is spread over multiple classes. How can I implement something like that in C++?
 
 It is essential I get constructors with something like named arguments, even if they are not supported by bindings to other languages, because the complexity of creating score data gets unmanagable otherwise;
 If necessary, I may have additional simpler constructors for bindings to other langs;
 
 - Specify a single nested data structure (e.g., vector) as argument, which contains all args, and which can be created in-place, e.g., the following (note: such constructor does not work with map, unfortunately). Is this too lengthy? Likely...
 vector<string> args {"arg1", "x", "arg2", "y"};
 
 map<string,string> args2 {{"arg1", "x"}, {"arg2", "y"}};
 for(auto x: args2)
 std::cout << x.first << ": " << x.second << '\n';
 
 Lengthy type declaration can be reduced:
 typedef map<string,string> args;
 args myArgs {{"arg1", "x"}, {"arg2", "y"}};
 
 Constructor can be used in an expression, e.g., I can call an init method with
 init(args {{"arg1", "x"}, {"arg2", "y"}})
 init(arg1: "x", arg2: "y")  // preferred syntax comparions -- much shorter, but the other is not unreasonable
 
 Problem: args are only captured at run-time, and so the compiler cannot help much.
 
 Arg values are boost::variant instances. boost::apply_visitor cares for compile-time error checking of types.
 
 
 - Similar approach
 http://www.reddit.com/r/programming/comments/19bul0/c11_named_parameters_using_operator_suffixes_and/
 
 
 
 - method chaining: http://www.parashift.com/c++-faq-lite/named-parameter-idiom.html
 
 - The Boost Parameter Library: http://www.boost.org/doc/libs/1_55_0/libs/parameter/doc/html/index.html
 
 - Variadic function:
 https://en.wikipedia.org/wiki/Variadic_function#Example_in_C
 
  */

#ifndef __MusicRepresentation__ScoreCore_TypeArgs__
#define __MusicRepresentation__ScoreCore_TypeArgs__

#include <map>
#include <vector>
#include <boost/variant.hpp>

/*******************************************************************************************************/
//
// Defining args typ for accessing optional and named arguments for constructors of ScoreObject and subclasses.
//
/*******************************************************************************************************/

// typedef boost::variant<int,std::string> arg;
/** Shorthand type for argument maps for score object initialisation, which allow for optional and named arguments for constructors of ScoreObject and subclasses. Conveniently create argument map for constructors like
 
 SomeScoreObjectClass x = {args {{"arg1", 42}, {"arg2", "test"}}}
 */
// boost::variant doc: http://www.boost.org/doc/libs/1_55_0/doc/html/variant.html
typedef std::map<std::string, boost::variant<int,std::string>> args;


/** Defines compile-time checked accessors for every arg type (i.e. the values in the map type called args).
 */
// TODO: consider rewriting with type template
class getStringArg : public boost::static_visitor<std::string> {
public:
    std::string operator()(std::string& str) const;
    std::string operator()(int & i) const;
};
class getIntArg : public boost::static_visitor<int> {
public:
    int operator()(std::string& str) const;
    int operator()(int & i) const;
};


/*******************************************************************************************************/
//
// Aux functions
//
/*******************************************************************************************************/

args reduceArgsBy(args as, std::vector<std::string> keys);

int extractIntArg(args as, std::string argName, int defaultVal);
std::string extractStringArg(args as, std::string argName, std::string defaultVal);



#endif /* defined(__MusicRepresentation__ScoreCore_TypeArgs__) */
