//
//  Catalogue.c
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "CatalogueController.h"
#include "Data.h"

#include <iostream>
#include <string.h>

using namespace std;

void SetCatalogue(CatalogueData *Catalogue,int total,char *name,EventData *Event)
{
       Catalogue->Total=total;
       strcpy(Catalogue->Name,name);
       Catalogue->EventIndex[Catalogue->Total]=Event;
}
