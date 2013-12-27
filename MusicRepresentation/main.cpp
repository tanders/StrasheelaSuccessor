//
//  main.cpp
//  MusicRepresentation
//
//  Created by torsten on 21/12/2013.
//  Copyright (c) 2013 torsten. All rights reserved.
//

#include "ScoreCore_Element.h"

using namespace std;
//using namespace StrasheelaSuccessor;


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
    
    
//    Parameter p = {args {{"info", "bla"}, {"value", 41}}};
//
////    cout << "hasThisInfo? " << scoreObject.hasThisInfo("bla") << "\n";
//    cout << "hasThisInfo? " << p.hasThisInfo("bla") << "\n";
//    cout << "value:  " << p.getValue() << "\n";
//    cout << "unit :  " << p.getUnit() << "\n";
    
    Element e = {args {{"info", "bla"}, {"endTime", 10}, {"duration", 10}}};
    
    //    cout << "hasThisInfo? " << scoreObject.hasThisInfo("bla") << "\n";
    cout << "hasThisInfo? " << e.hasThisInfo("bla") << "\n";
    cout << "startTime:  " << e.getStartTime() << "\n";
    cout << "endTime:  " << e.getEndTime() << "\n";
    cout << "duration :  " << e.getDuration() << "\n";
    
    
    
    return 0;
}

