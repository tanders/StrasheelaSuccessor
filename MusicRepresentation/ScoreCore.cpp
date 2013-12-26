//
//  ScoreCore.cpp
//  MusicRepresentation
//
//  Created by torsten on 25/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

/**
 This file defines the core for a music score data structure of [Strasheela successor].
 
 Certain classes in the hierarchy are marked as [abstract class]. These classes should not be instantiated. Other classes are marked as [semi abstract class]. These classes are generic data types which may be instantiated. However, the user is encouraged to define more specific subclasses of these. Classes marked as [concrete class] may be freely instantiated, of course the user may define subclasses of them too.
 */


/* // Musing on design
 
 
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

#include "ScoreCore.h"

//using namespace std;

 
