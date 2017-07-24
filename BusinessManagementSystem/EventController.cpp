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
#include <string.h>

using namespace std;

void SetEvent(EventData *Event,int type,char *title,char *detail,int begin,int end)
{
    Event->Type=type;
    strcpy(Event->Title,title);
    strcpy(Event->Detail,detail);
    Event->Begin=begin;
    Event->End=end;
}
