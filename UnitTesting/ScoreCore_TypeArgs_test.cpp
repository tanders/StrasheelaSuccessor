
#include "catch.hpp"
#include "ScoreCore_TypeArgs.h"
#include "ScoreCore_Item.h"

/// Simple construction and printing tests
/*
    vector<string> args1 {"arg1", "x", "arg2", "y"};

    for_each(args1.begin(), args1.end(), [](string s){
        cout << s << "\n";
    });

    Args args2 {{"arg1", "x"}, {"arg2", "y"}};
    for(auto x: args2)
        std::cout << x.first << ": " << x.second << '\n';

    for(auto x: Args {{"arg1", 42}, {"arg2", "test"}})
        std::cout << x.first << ": " << x.second << '\n';
*/

SCENARIO( "type Args wraps named arguments of various types savely in a map", "[ScoreCore][Args]" ) {

    GIVEN( "A test Args map" ) {
        
        Args myArgs {
            {"string_arg1", "x"},
            {"int_arg1", 42},
//            {"item_arg1", Item {Args {{"info", "testItem"}}}},
            {"vectorOfItems_args1", std::vector<ScoreObject> {
                Item {Args {{"info", "item1"}}},
                Item {Args {{"info", "item2"}}}}}};
        
        WHEN( "string arg extracted with extractStringArg" ) {
            REQUIRE( extractStringArg(myArgs, "string_arg1", "default") == "x" );
            REQUIRE( extractStringArg(myArgs, "noArg", "default") == "default" );
            // extracting string from int arg throws exception -- instead, it could return the int as string
            REQUIRE_THROWS( extractStringArg(myArgs, "int_arg1", "default") );
        }
        
        WHEN( "int arg extracted with extractIntArg" ) {
            REQUIRE( extractIntArg(myArgs, "int_arg1", 0) == 42 );
            REQUIRE( extractIntArg(myArgs, "noArg", 0) == 0 );
            // extracting int from string arg throws -- instead, it could try to transform the string into an int
            REQUIRE_THROWS( extractIntArg(myArgs, "string_arg1", 0) );
        }

        WHEN( "calling extractVectorOfScoreObjectsArg" ) {
            REQUIRE( extractVectorOfScoreObjectsArg(myArgs, "vectorOfItems_args1")[1].hasThisInfo("item2") == true );
            REQUIRE_THROWS( extractVectorOfScoreObjectsArg(myArgs, "string_arg1") );
        }
        
        WHEN( "calling reduceArgsBy" ) {
            REQUIRE( reduceArgsBy(myArgs, std::vector<std::string> {"vectorOfItems_args1"}).size() == 2 );
            // removing all keys results in empty vector
            REQUIRE( reduceArgsBy(myArgs, std::vector<std::string> {"string_arg1", "int_arg1", "vectorOfItems_args1"}).empty() == true );
            // Any key not existing in myArgs is ignored.
            // TODO: once I have == operators overloaded for ScoreObjects, I could test whether result of reduceArgsBy is same as myArgs
            REQUIRE( reduceArgsBy(myArgs, std::vector<std::string> {"noArg"}).size() == 3 );

        }
        
        
    }
}