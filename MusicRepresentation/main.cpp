//
//  main.cpp
//  MusicRepresentation
//
//  Created by torsten on 21/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

/**
  This file defines the core for a music score data structure of [Strasheela successor]int area (void);.
 
  Certain classes in the hierarchy are marked as [abstract class]. These classes should not be instantiated. Other classes are marked as [semi abstract class]. These classes are generic data types which may be instantiated. However, the user is encouraged to define more specific subclasses of these. Classes marked as [concrete class] may be freely instantiated, of course the user may define subclasses of them too.
 %%
 
 */

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
 
 -------------------

// rely on default constructor/destructor (implicitly defined and with empty argument list)
// except you need more refined behaviour

 -------------------

 Type checking with built-in typeid, an operator that returns a type_info
 It works dynamically (e.g., only at runtime)
 http://www.cplusplus.com/reference/typeinfo/type_info/
 
 */


#include <iostream>
#include <vector>
#include <map>
#include "boost/variant.hpp"


using namespace std;


/* Workaround to allow for arguments of different types for argument maps. Downside: all static typing (error checking etc.) is lost. Also, I always need to check with type is actually contained, before anything can actually be done with that data.
 */
// TODO: What I actually want here is a super class for both int and string, so that both types are allowed.
// union types are intended for saving memory, by allowing different types at times to use the same data slot -- I actually want to do something else.
// Possible alternative: Boost.Variant, http://www.boost.org/doc/libs/1_55_0/doc/html/variant.html
//union arg {
//    string s; // union cannot wrap a string?
//    int i;
//};

// typedef boost::variant<int,string> arg;

/** Shorthand type for argument maps for score object initialisation. Conveniently create argument map like
 * init(args {{"arg1", 42}, {"arg2", "test"}})
 */
// boost::variant doc: http://www.boost.org/doc/libs/1_55_0/doc/html/variant.html
typedef map<string, boost::variant<int,string>> args;



/* Skipped Strasheela classes
 
 NonType
 Reflection
 
 */


/** [abstract class] The most general data type for score data is a ScoreObject. info can store arbitrary user information (internally a vector of strings).
  */
class ScoreObject {
//    int id;  // Perhaps I need id later again...
    vector<string> info;
    
public:
    /** [constructor with map argument for optional/named arguments] The argument info is a string of arbitrary user information for this score object.
     */
    ScoreObject(args as) {
        // process arg info
        if (as.count("info")){
            // TODO: throw invalid_argument in case "info" value is not string
            info.push_back(boost::get<string>(as.at("info")));
            as.erase("info");
        }
        // raise exception if there are any remaining args
        for(auto x: as)
            throw invalid_argument{"ScoreObject::ScoreObject(args as)" + x.first};
    };
    
    vector<string> getInfo (void) { return info; }
    /** [destructive method] Adds myInfo to vector of stored infos. */
    void addInfo(string myInfo) { info.push_back(myInfo); }
    /** Returns bool whether internal vector of info strings contains myInfo. */
    bool hasThisInfo(string myInfo) {
        return any_of(info.begin(), info.end(), [&](string s){return s.compare(myInfo) == 0;});
    }
};


/* // uncompilable/uncompleted definitions are wrapped in comments

class TimeMixin {
    <#instance variables#>
    
public:
    <#member functions#>
};

// should this go in a different file?
class MappingMixin {
    <#instance variables#>
    
public:
    <#member functions#>
};

class Parameter : public ScoreObject {
    <#instance variables#>
    
public:
    <#member functions#>
};
 
 */

/* Skipped Strasheela classes
 
 LeaveUninitialisedParameterMixin
 
 */

/* // uncompilable/uncompleted definitions are wrapped in comments


class TimeParameter : public Parameter {
    <#instance variables#>
    
public:
    <#member functions#>
};

class TimePoint : public TimeParameter {
    <#instance variables#>
    
public:
    <#member functions#>
};

class TimeInterval : public TimeParameter {
    <#instance variables#>
    
public:
    <#member functions#>
};

// Shall I really use this?
class Amplitude : public Parameter {
    <#instance variables#>
    
public:
    <#member functions#>
};

class Pitch : public Parameter {
    <#instance variables#>
    
public:
    <#member functions#>
};



class Item : public ScoreObject, public MappingMixin {
    <#instance variables#>
    
public:
    <#member functions#>
};


// Simplification of Strasheela: Container is basically a TemporalAspect (only nesting in a tree, no graph)
class Container : public Item, public TimeMixin {
    <#instance variables#>
    
public:
    <#member functions#>
};
 
 */

/* Skipped Strasheela classes
 
 Modifier
 Aspect
 TemporalAspect
 
 */

/* // uncompilable/uncompleted definitions are wrapped in comments

class Sequential : public Container {
    <#instance variables#>
    
public:
    <#member functions#>
};

class Simultaneous : public Container {
    <#instance variables#>
    
public:
    <#member functions#>
};


// Simplification of Strasheela: Element is a TemporalElement (only nesting in a tree, no graph)
class Element : public Item, public TimeMixin {
    <#instance variables#>
    
public:
    <#member functions#>
};
 
 */

/* Skipped Strasheela classes
 
 AbstractElement
 TemporalElement
 
 */


/* // uncompilable/uncompleted definitions are wrapped in comments

// Class renamed: Pause -> Rest
class Rest : public Element {
    <#instance variables#>
    
public:
    <#member functions#>
};

 */

/* Skipped Strasheela classes
 
 Event
 
 */

/* // uncompilable/uncompleted definitions are wrapped in comments


class MinimalNote : public Element {
    <#instance variables#>
    
public:
    <#member functions#>
};


*/


int main(int argc, const char * argv[])
{
    
//    vector<string> args1 {"arg1", "x", "arg2", "y"};
//    
//    for_each(args1.begin(), args1.end(), [](string s){
//        cout << s << "\n";
//    });

//    args args2 {{"arg1", "x"}, {"arg2", "y"}};
//    for(auto x: args2)
//        std::cout << x.first << ": " << x.second << '\n';

//    for(auto x: args {{"arg1", 42}, {"arg2", "test"}})
//        std::cout << x.first << ": " << x.second << '\n';
    
//    ScoreObject(args {{"info", "bla"}});
    ScoreObject scoreObject = {args {{"info", 3}}}; // working
//    ScoreObject scoreObject = {args {{"info", "bla"}, {"buggy_arg", "value"}}}; // successfully throws exception
    scoreObject.addInfo("test 2");

    // insert code here...
    cout << "hasThisInfo? " << scoreObject.hasThisInfo("bla") << "\n";
    return 0;
}

