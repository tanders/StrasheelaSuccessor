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
 
 Problem: this (likely) only returns label of actual class, but cannot be used to check type of superclasses.
 
 Strasheela core approach: def bool member functions for type checking (isScoreObject etc.), but that needs some top-level class to define all those checking functions (all returning false). So, this approach cannot be extended.
 
 Strasheela extensions approach: add unforgable datum to every class (Oz name) and check for that:
 
 fun {IsInterval X}
    {Score.isScoreObject X} andthen {HasFeature X IntervalType}
 end
 
 */


#include <iostream>
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

/** Defines compile-time checked accessors for every arg type (i.e. the values in the map type called args).
 */
class getStringArg : public boost::static_visitor<string> {
public:
    string operator()(string& str) const {
        return str;
    }
    string operator()(int & i) const {
        throw invalid_argument{"Not a string: " + boost::lexical_cast<std::string>(i)};
    }
};
class getIntArg : public boost::static_visitor<int> {
public:
    int operator()(string& str) const {
        throw invalid_argument{"Not a string: " + str};
    }
    int operator()(int & i) const {
        return i;
    }
};


/*******************************************************************************************************/
//
//Aux functions
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

/*******************************************************************************************************/
//
// Music representation class hierarchy
//
/*******************************************************************************************************/

/* Skipped Strasheela classes
 
 NonType
 Reflection
 
 */


/** [abstract class] The most general data type for score data is a ScoreObject. info can store arbitrary user information (internally a vector of strings).
  */
class ScoreObject {
//    int id;  // Perhaps I need id later again...
    // !! TODO: does class destructor explicitly need to delete any internal vector?
    vector<string> info;
    
public:
    /** [constructor with map argument for optional/named arguments] 
        Args:
        string info: arbitrary user information for this score object (additional infos can be added with nmember function addInfo)
     */
    // TODO: handle argument could be added later: arg is *ScoreObject, which is bound in constructor to *this
    ScoreObject(args as) {
        // process arg info
        if (as.count("info")){
            info.push_back(boost::apply_visitor(getStringArg(), as.at("info")));
            as.erase("info");
        }
        // raise exception if there are any remaining args
        for(auto x: as)
            throw invalid_argument{"ScoreObject::ScoreObject(args as)" + x.first};
    };
    
    /** Returns vectors of all info strings stored. */
    vector<string> getInfo(void) { return info; }

    /** [destructive method] Adds myInfo to vector of stored infos. */
    void addInfo(string myInfo) { info.push_back(myInfo); }

    /** Returns bool whether internal vector of info strings contains myInfo. */
    bool hasThisInfo(string myInfo) {
        return any_of(info.begin(), info.end(), [&](string s){return s.compare(myInfo) == 0;});
    }
    
    // !! TODO -- many member functions still missing -- see Strasheela source
    
 };


/* // TODO: uncompleted definitions, wrapped in comments

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

 */


/** [semi abstract class] Musical parameters are the basic magnitudes in a music representation; examples are the parameters duration, amplitude and pitch, which add information to a note. A parameter is represented by an own class (i.e. not just as a instance variables of score items, as in most other composition environments) to allow the expression of additional information on the parameter besides the actual parameter value. For instance, a single numeric value for a pitch is ambitious, it could express a frequency, a MIDI-keynumber, MIDI-cents, a scale degree etc. Therefore, a parameter allows to specify the unit of measurement explicitly. The unit is mainly used when exporting the score.
 Also, due to bidirectional links between nested score objects, all information stored in a score can be accessed from a parameter object (using member function getItem).
 Users should ensure that parameters have corresponding units when constraining the relation between multiple parameters.
 For efficiency, the parameter value is limited to integer values and integer variable (planned: float variables). However, due to the flexibility of the unit, these values can be mapped to arbitrary other data (e.g. midicent integer to frequency float).
 */
class Parameter : public ScoreObject {
    // The parameter attributes value and 'unit' specify the parameter setting and the unit of measurement. The attribute item points to the score item the parameter belongs to.
    // !! TMP comment
//    Item item;
    int value;
    string unit;
    // heuristics  // for internal bookkeeping of heuristic constraints
    
public:
    /** Args: 
        int value: the parameter value
        string unit: parameter unit of measurement
     */
    Parameter(args as) : ScoreObject{ reduceArgsBy(as, vector<string> {"value", "unit"}) } {
        // process args
        if (as.count("value")){
            value = boost::apply_visitor(getIntArg(), as.at("value"));
        } else {
            value = 0; // default
        }
        if (as.count("unit")){
            unit = boost::apply_visitor(getStringArg(), as.at("unit"));
        } else {
            unit = ""; // default
        }
    };
    
    int getValue(void) { return value; }
    string getUnit(void) { return unit; }
    
    /* // TODO: missing functions
     
     getItem
     initFD
     initFS
     isDet
     
     ?? getHeuristics
     ?? addHeuristic
     
     ?? getInitInfo
     ?? toPPrintRecord
     
     */

};


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
//    ScoreObject scoreObject = {args {{"info", "bla"}}}; // working
//    ScoreObject scoreObject = {args {{"info", 42}}}; // throws as expected
//    ScoreObject scoreObject = {args {{"info", "bla"}, {"buggy_arg", "value"}}}; // successfully throws exception
//    scoreObject.addInfo("test 2");
    
    Parameter p = {args {{"info", "bla"}, {"value", 42}}};

//    cout << "hasThisInfo? " << scoreObject.hasThisInfo("bla") << "\n";
    cout << "hasThisInfo? " << p.hasThisInfo("bla") << "\n";
    cout << "value:  " << p.getValue() << "\n";
    return 0;
}

