//
//  MusicUtils.h
//  MusicRepresentation
//
//  Created by torsten on 01/01/2014.
//  Copyright (c) 2014 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__MusicUtils__
#define __MusicRepresentation__MusicUtils__

#include <vector>


double keynumToFreq(double keynum, int keysPerOctave);

double freqToKeynum(double freq, int keysPerOctave);

bool isET(std::string pitchUnit);

int getPitchesPerOctave(std::string pitchUnit);


double pitchToMidi(double pitch, std::string pitchUnit);
// TODO: add support for tuning table (default and user-defined)
// decide type of tuningTable (better map<int,double> ?)
//double pitchToMidi(double pitch, std::string pitchUnit, std::vector<double> tuningTable);



// TODO: many defs from Strasheela's MusicUtils.oz still missing, but add them only when needed


#endif /* defined(__MusicRepresentation__MusicUtils__) */
