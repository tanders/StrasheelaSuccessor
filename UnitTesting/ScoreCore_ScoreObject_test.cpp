
#include "catch.hpp"

#include "ScoreCore_ScoreObject.h"

// Unit Testing

SCENARIO( "Testing plain ScoreObject instances", "[ScoreCore][ScoreObject]" ) {
    
    GIVEN( "A score object with initialised info string" ) {
        ScoreObject myScoreObject = {Args {{"info", "foo"}}};
        REQUIRE( myScoreObject.hasThisInfo("foo") == true );
        
        myScoreObject.addInfo("bar");
        REQUIRE( myScoreObject.hasThisInfo("bar") == true );
        
        // testing for an unset info
        REQUIRE( myScoreObject.hasThisInfo("bla") == false );
        
        std::vector<std::string> infoVector {"foo", "bar"};
        
        REQUIRE( myScoreObject.getInfo() == infoVector);
        
        WHEN( "A score object is constructed with unsupported args " ) {
            // unsupported key arg ("buggy_arg" not supported)
            Args myArgs1 {{"buggy_arg", "value"}};
            REQUIRE_THROWS( ScoreObject {myArgs1} );
            
            // wrong type given to arg (info requires string)
            Args myArgs2 {{"info", 42}};
            REQUIRE_THROWS( ScoreObject {myArgs2} );
        }
    }
}

