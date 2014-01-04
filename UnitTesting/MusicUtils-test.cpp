
// Unit tests for MusicUtils definitions

#include "catch.hpp"
#include "MusicUtils.h"


// TEST_CASE Args: test name (must be unique), and one or more tags

TEST_CASE( "keynumToFreq", "[MusicUtils]" ) {
    CHECK(keynumToFreq(69, 12) >= 439.9);
    CHECK(keynumToFreq(69, 12) <= 440.1);
    CHECK(keynumToFreq(6900, 1200) >= 439.9);
    CHECK(keynumToFreq(6900, 1200) <= 440.1);
    CHECK(keynumToFreq(0, 1200) >= 8.175);
    CHECK(keynumToFreq(0, 1200) <= 8.176);
}

TEST_CASE( "freqToKeynum", "[MusicUtils]" ) {
    CHECK(ceil(freqToKeynum(440, 12)) == 69);
}

TEST_CASE( "isET", "[MusicUtils]" ) {
    CHECK(isET("et12") == true);
    CHECK(isET("bla") == false);
    // IDE catches this
    //    CHECK_THROWS(isET(42));
}

TEST_CASE( "getPitchesPerOctave", "[MusicUtils]" ) {
    CHECK( getPitchesPerOctave("et12") == 12 );
    CHECK( getPitchesPerOctave("et31") == 31 );
    CHECK_THROWS( getPitchesPerOctave("bla") );
}

TEST_CASE( "pitchToMidi", "[MusicUtils]" ) {
    CHECK( pitchToMidi(60, "et12") == 60 );
    CHECK( pitchToMidi(60, "midi") == 60 );
    CHECK( pitchToMidi(6000, "midicent") == 60 );
    CHECK( pitchToMidi(6000, "midic") == 60 );
    CHECK( pitchToMidi(6000000, "millimidicent") == 60 );
    
    CHECK( ceil(pitchToMidi(440, "Hz")) == 69 );
    CHECK( ceil(pitchToMidi(440, "freq")) == 69 );
    CHECK( ceil(pitchToMidi(440000, "mHz")) == 69 );
    
    CHECK( pitchToMidi(155, "et31") == 60 );
    
    CHECK_THROWS( pitchToMidi(60, "bla") );
}

