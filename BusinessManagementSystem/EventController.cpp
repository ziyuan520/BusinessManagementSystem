//
//  Event.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "EventController.h"
#include "Data.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void SetEvent(EventData *Event,int type,string title,string detail,int begin,int end)
{
    Event->Type=type;
    Event->Title=title;
    Event->Detail=detail;
    Event->Begin=begin;
    Event->End=end;
}

string FormatTime(int Time)
{
    
    int Year,Month,Day;
   
    string Date;

    
    Year=Time/10000;
    Month=Time/100-Year*100;
    Day=Time-Year*10000-Month*100;
    
    Date=to_string(Year)+"年"+to_string(Month)+"月"+to_string(Day)+"日";
    
    return Date;
}
