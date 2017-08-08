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


void Initialize_DataBase();

void Set_To_DataBase(CatalogueData *Catalogue,int type,string title,string detail,string begin,string end);

void Get_Catalogue_From_DataBase();

void Get_EventList_From_DataBase(CatalogueData *Catalogue);

void Get_Event_From_DataBase(CatalogueData *Catalogue,int EventIndex);

void Delete_Event_From_Database(CatalogueData *Catalogue,int EventIndex);

void Update_Event_From_Database(CatalogueData *Catalogue,int EventIndex,int type,string title,string detail,string begin,string end);


string Format_select_Sentence(string Column);

string FormatTime(int Time);

void SetCatalogue(CatalogueData *Catalogue,int catalogueIndex,int total,string name);

int Get_Event_Number_From_Database(int CatalogueIndex)

#endif /* Controller_hpp */

