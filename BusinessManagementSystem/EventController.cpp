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

using namespace std;

void SetEvent(EventData *Event,int type,string title,string detail,int begin,int end)
{
    Event->Type=type;
    Event->Title=title;
    Event->Detail=detail;
    Event->Begin=begin;
    Event->End=end;
}
