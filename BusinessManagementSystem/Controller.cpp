//
//  Controller.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Controller.h"
#include "EventController.h"
#include "CatalogueController.h"
#include "Data.h"
#include "Test_option.hpp"

#import "sqlite3.h"


#include <iostream>

using namespace std;

void Initialize_DataBase(sqlite3 *Database, char *err_msg)
{
    char Sql_Create_Buffer[200]= "create table event(Id integer primary key,Title text,Catalogue text,Detail text,State integer,Start_Time text,End_Time text)";
    CreateTable_Manual(Database, err_msg, Sql_Create_Buffer);
}

void Set_To_DataBase()
{
    
}

void Insert_Call_Test(sqlite3 *Database, char *err_msg){
    char Sql_Insert_Buffer[200] = "insert into event values (54,'车日天是狗','全部事项',0,'201707272330','201707272400')";
    Sql_Manual(Database, err_msg, Sql_Insert_Buffer);
}

void Get_From_DataBase();






















