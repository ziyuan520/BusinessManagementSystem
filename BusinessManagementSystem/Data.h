//
//  Data.h
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Data_h
#define Data_h

struct EventData{
    int Type;
    char Title[100];
    char Detail[500];
    int Begin;
    int End;
};

struct CatalogueData{
    int Total;
    char Name[30];
    EventData *EventIndex[10];  //每个分类下最大10个事项，
};

#endif /* Data_h */
