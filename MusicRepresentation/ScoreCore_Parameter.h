//
//  ScoreCore_Parameter.h
//  MusicRepresentation
//
//  Created by torsten on 26/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#ifndef __MusicRepresentation__ScoreCore_Parameter__
#define __MusicRepresentation__ScoreCore_Parameter__

#include "ScoreCore_ScoreObject.h" // TMP
#include "ScoreCore_Item.h"

/** [semi abstract class] Musical parameters are the basic magnitudes in a music representation; examples are the parameters duration, amplitude and pitch, which add information to a note. A parameter is represented by an own class (i.e. not just as a instance variables of score items, as in most other composition environments) to allow the expression of additional information on the parameter besides the actual parameter value. For instance, a single numeric value for a pitch is ambitious, it could express a frequency, a MIDI-keynumber, MIDI-cents, a scale degree etc. Therefore, a parameter allows to specify the unit of measurement explicitly. The unit is mainly used when exporting the score.
 Also, due to bidirectional links between nested score objects, all information stored in a score can be accessed from a parameter object (using member function getItem).
 Users should ensure that parameters have corresponding units when constraining the relation between multiple parameters. 
 For efficiency, the parameter value is limited to integer values and integer variable (planned: float variables). However, due to the flexibility of the unit, these values can be mapped to arbitrary other data (e.g. midicent integer to frequency float).
 */
class Parameter : public ScoreObject {
    // The parameter attributes value and 'unit' specify the parameter setting and the unit of measurement. The attribute item points to the score item the parameter belongs to.
    // !! TMP comment
//    Item& item; // backwards reference -- must be reference because otherwise they contain each other indefinitely
    int value;
    std::string unit;
    // heuristics  // for internal bookkeeping of heuristic constraints
    
public:
    Parameter(args as);
    
    int getValue(void);
    std::string getUnit(void);
//    Item getItem(void);
    
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



class TimeParameter : public Parameter {
public:
    float getValueInSeconds(void);
    float getValueInBeats(void);
};

class TimePoint : public TimeParameter {
};

class TimeInterval : public TimeParameter {
};


class Pitch : public Parameter {
public:
    float getValueInMidi(void);
    float getValueInMidi(std::map<std::string,int> tuningTable);
};



#endif /* defined(__MusicRepresentation__ScoreCore_Parameter__) */
