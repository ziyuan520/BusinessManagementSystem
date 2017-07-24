//
//  Catalogue.h
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Catalogue_h
#define Catalogue_h

#include <stdio.h>
#include "Event.h"

class CatalogueData{

public:
    void Add();
    void Updata();
    void Delete();

private:
    int Total;
    char Name[30];
    EventData *EventIndex[10];
、
};



#endif /* Catalogue_h */
