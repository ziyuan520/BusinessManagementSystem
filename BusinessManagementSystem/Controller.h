//
//  Controller.h
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Controller_h
#define Controller_h

#include <stdio.h>
#include "EventController.h"
#include "Controller.h"
#include "Data.h"

void PrintCatalogueList(CatalogueData *Catalogue,int Number);

int PrintEventList(CatalogueData *Catalogue);

void PrintEvent(EventData *Event);

int CreatOneEvent(CatalogueData *Catalogue);

//void DeleteOneEvent();

//void UpdataOneEvent();

#endif /* Controller_h */
