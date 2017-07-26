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

void DisplayCatalogueList(CatalogueData* List,int* Command,int* MenuIndex);

void DisplayEventList(CatalogueData* List,int* Command,int* MenuIndex);

void DisplayEvent(CatalogueData* List,int* Command,int* MenuIndex);

void AddEvent(CatalogueData* List,int* Command,int* MenuIndex);

void PrintCatalogueList(CatalogueData *Catalogue,int Number);

int  PrintEventList(CatalogueData *Catalogue);

void PrintEvent(EventData *Event);

int  CreatOneEvent(CatalogueData *Catalogue);

//void DeleteOneEvent();

//void UpdataOneEvent();

#endif /* Handle_hpp */
