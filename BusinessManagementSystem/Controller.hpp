//
//  Controller.hpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/30.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include <iostream>
#include "sqlite3.h"
#include "Data.h"
using namespace std;



string Format_select_Sentence(string Column);

string FormatTime(int Time);

void Initialize_DataBase();

void Set_To_DataBase(CatalogueData *Catalogue,int type,string title,string detail,string begin,string end);

void Get_EventList_From_DataBase(CatalogueData *Catalogue);

void Get_Event_From_DataBase(CatalogueData *Catalogue,int EventIndex);

void SetCatalogue(CatalogueData *Catalogue,int catalogueIndex,int total,string name);



#endif /* Controller_hpp */

