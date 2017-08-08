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


void Start();

void DisplayCatalogueList(CatalogueData* List,int* Command,int* MenuIndex);

void DisplayEventList(CatalogueData* List,int* Command,int* MenuIndex);

void DisplayEvent(CatalogueData* List,int* Command,int* MenuIndex);

void AddEvent(CatalogueData* List,int* Command,int* MenuIndex);

void DeleteEvent(CatalogueData* List,int* Command,int* MenuIndex);

void UpdateEvent(CatalogueData* List,int* Command,int* MenuIndex);

//void DeleteOneEvent();

//void UpdataOneEvent();

#endif /* Handle_hpp */
