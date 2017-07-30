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


string Format_int_To_string(int Integer);

string Format_select_Sentence(string Column);

void Initialize_DataBase();

void Set_To_DataBase(CatalogueData *Catalogue,EventData *Event);

void Get_EventList_From_DataBase(CatalogueData *Catalogue);

void Get_Event_From_DataBase(CatalogueData *Catalogue,int EventIndex);

#endif /* Controller_hpp */

