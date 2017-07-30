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

void Initialize_DataBase(sqlite3 *Database, char *err_msg);

void Set_To_DataBase(sqlite3 *Database, char *err_msg,CatalogueData *Catalogue,EventData *Event);

void Get_EventList_From_DataBase(sqlite3 *Database, char *err_msg,CatalogueData *Catalogue);


#endif /* Controller_hpp */
