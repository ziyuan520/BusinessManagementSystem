//
//  Data.h
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Data_h
#define Data_h

#include<string>

using namespace std;

struct EventData{
    int Type;
    string Title;
    string Detail;
    int Begin;
    int End;
};

struct CatalogueData{
    int CatalogueIndex;
    int Total;
    string Name;
    EventData *EventIndex[10];  //每个分类下最大10个事项，
};

#endif /* Data_h */
