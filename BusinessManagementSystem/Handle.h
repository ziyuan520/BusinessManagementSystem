//
//  Handle.hpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Handle_h
#define Handle_h

#include <stdio.h>
#include "Handle.h"
#include "Data.h"
#include "Controller.h"
#include "EventController.h"
#include "CatalogueController.h"

void Start();

void DisplayCatalogueList(CatalogueData* List,char* Cmd,int* Index);

void DisplayEventList(CatalogueData* List,char* Cmd,int* Index);

void DisplayEvent(CatalogueData* List,char* Cmd,int* Index);

void AddEvent(CatalogueData* List,char* Cmd,int* Index);

#endif /* Handle_hpp */
