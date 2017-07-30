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
#include <string>

using namespace std;

void SetCatalogue(CatalogueData *Catalogue,int catalogueIndex,int total,string name,EventData *Event)
{
       Catalogue->CatalogueIndex=catalogueIndex;
       Catalogue->Total=total;
       Catalogue->Name=name;
       Catalogue->EventIndex[Catalogue->Total]=Event;
}
