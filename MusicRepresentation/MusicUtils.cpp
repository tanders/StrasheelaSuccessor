//
//  MusicUtils.cpp
//  MusicRepresentation
//
//  Created by torsten on 01/01/2014.
//  Copyright (c) 2014 torsten. All rights reserved.
//

/*! \file MusicUtils.cpp
This file defines some utilities which are related to music or acoustics.
 */

// http://www.cplusplus.com/reference/cmath/
//#include <cmath>
#include <math.h>
#include <string>
#include <boost/algorithm/string/predicate.hpp> // string istarts_with
#include "MusicUtils.h"

/*! freq at keynum 0, keynum 69 = 440 Hz
 */
const float freq0 = 8.175798915643707;

/*! Transforms a keynum into the corresponding frequency in an equally tempered scale with keysPerOctave keys per octave. The function is 'tuned' such that keynumToFreq(69 12) returns 440 Hz.
 Note that he term keynum here is not limited to a MIDI keynumber but denotes a keynumber in any equidistant tuning. For instance, if keysPerOctave=1200 then keynum denotes cent values.
  */
double keynumToFreq(double keynum, int keysPerOctave){
    return pow(2.0, keynum / (double)(keysPerOctave)) * freq0;
}


/*! Transforms freq into the corresponding keynum in an equally tempered scale with keysPerOctave keys per octave. The function is 'tuned' such that freqToKeynum(440, 12) returns 69.
Note that he term keynum here is not limited to a MIDI keynumber but denotes a keynumber in any equidistant tuning. For instance, if keysPerOctave=1200 then keynum denotes cent values.
 */
double freqToKeynum(double freq, int keysPerOctave){
    return log2(freq/freq0) * (double)(keysPerOctave);
}


/* // skipped defs
 
GetPitchesPerOctave

*/

/*! Returns true if PitchUnit is an atom which matches the pattern et<Digit>+ such as et31 or et72.
 */
bool isET(std::string pitchUnit) {
//    char pitchString[] = pitchUnit;
    // tail are the chars after first two chars
    std::string tail {pitchUnit};
    tail.erase(tail.begin(), tail.begin()+2);
    return boost::istarts_with(pitchUnit, "et")
        && tail != ""
        && boost::algorithm::all(tail, isdigit);
}

/*! Returns the pitches per octave expressed by an ET pitch unit, e.g., for et31 it returns 31.
 */
// TODO: consider whether test isET is really needed in this definition. E.g., when pitchToMidi is called, this test is executed again.
int getPitchesPerOctave(std::string pitchUnit) {
    if (isET(pitchUnit)) {
        std::string tail {pitchUnit};
        tail.erase(tail.begin(), tail.begin()+2);
        return stoi(tail, nullptr); // nullptr: unused arg
    } else {
        throw std::invalid_argument{"pitch unit must have form et<number>"};
    }
}


/*! Transforms pitch, measured in pitchUnit, into the corresponding "Midi float"
 
 A "Midi float" is a Midi number where positions after the decimal point express microtonal pitch deviations (e.g., 60.5 is middle C raised by a quarter tone). Possible pitch units are "midi: (i.e., 12-TET); "midicent" or "midic" (pitch measured in cent); "frequency", "freq", "Hz" or "hz" (a frequency measured in Hz); "mHz"; and arbitrary equal temperaments notated "et<divisionOfOctave>", e.g., "et31", "et72" etc.
  */
// TODO: after adding feature add doc: The transformation takes account a tuning table defined with Init.setTuningTable. Alternatively, a tuning table can be given directly to the optional arg 'table'.
// Difference to Strasheela: pitchUnit always bound (cannot be empty variable).
double pitchToMidi(double pitch, std::string pitchUnit) {
// TODO: Add support for default tuning table
#warning Make sure default pitch unit (midi) always available in a pitch parameter
    if (pitchUnit == "midi") { return pitch; }
    else if (pitchUnit == "midic" || pitchUnit == "midicent") { return pitch / 100.0; }
    else if (pitchUnit == "millimidicent" || pitchUnit == "mmidic" ) { return pitch / 100000.0; }
    else if (pitchUnit == "frequency" || pitchUnit == "freq" || pitchUnit == "Hz" || pitchUnit == "hz")
        { return freqToKeynum(pitch, 12.0); }
    else if (pitchUnit == "mHz" || pitchUnit == "mhz") { return freqToKeynum(pitch/1000.0, 12.0); }
    else if (isET(pitchUnit)) { return pitch * 12.0 / (double)(getPitchesPerOctave(pitchUnit)); }
    else throw std::invalid_argument{"Supported pitch units are midi, midicent (or midic), frequency (or freq), hz, mHz, and arbitrary equal temperaments (notated et<number>)."};
}
