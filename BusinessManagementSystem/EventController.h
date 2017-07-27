//
//  Event.h
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef EventController_h
#define EventController_h

#include <stdio.h>
#include "Data.h"

void SetEvent(EventData *Event,int type,string title,string detail,int begin,int end);

string FormatTime(int Time);


//void Updata_Event();
//void Delete_Event();

#endif /* Event_h */
