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

void DisplayCatalogueList(CatalogueData* List,char* cmd,int* index);

void DisplayEventList(CatalogueData* List,char* cmd,int* index);

#endif /* Handle_hpp */
