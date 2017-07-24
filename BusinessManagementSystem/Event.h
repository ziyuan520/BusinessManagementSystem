//
//  Event.h
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Event_h
#define Event_h

#include <stdio.h>

class EventData{

public:
    void Add();
    void Updata();
    void Delete();
    
private:
    int Type;       //type:
    char Title[100];
    char Detail[500];
    int Begin;
    int End;
};



#endif /* Event_h */
