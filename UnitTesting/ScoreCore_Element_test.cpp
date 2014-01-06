
#include "catch.hpp"

#include "ScoreCore_Element.h"

// Unit Testing


//    Parameter p = {Args {{"info", "bla"}, {"value", 41}}};
//    TimePoint p = {Args {{"value", 0}, {"unit",  "beats"}}};

//    cout << "value:  " << p.getValue() << "\n";
//    cout << "unit :  " << p.getUnit() << "\n";


SCENARIO( "Testing Element instances", "[ScoreCore][Element]" ) {
    
    GIVEN( "An Element with temporal parameters explicitly initialised" ) {
        
        Element myElement = {Args {
            {"offsetTime", 0},
            {"startTime", 0},
            {"duration", 4},
            {"endTime", 4}
        }};
        
        WHEN( "The time parameters are accessed" ) {
            REQUIRE( myElement.getOffsetTime() == 0 );
            REQUIRE( myElement.getStartTime() == 0 );
            REQUIRE( myElement.getDuration() == 4 );
            REQUIRE( myElement.getEndTime() == 4 );
        }
        
        // TODO: once parameter values are variables test propagation of temporal params

        
        // TODO: when timeUnit is set for a score, test that all temporal params can access that time unit
        
        // TODO: make getTimeUnit() available again, but cleanly (no need for unification)
//        WHEN( "The default time unit is accessed" ) {
//            REQUIRE( myElement.getTimeUnit() == "beats" );
//        }
        
        
        
        // TODO: test parameter linking with getParameters
        

        // dummy test -- check that getParameters() returns a std::vector<Parameter*> -- the compiler already enforces that anyway
//        WHEN( "The vector of all params is accessed" ) {
//            std::vector<Parameter*> ps = myElement.getParameters();
//            REQUIRE( all_of(ps.begin(), ps.end(), [&](Parameter* p){return true;}) );
//        }
        

    }
    
    
    // TODO: getContainer
    
}