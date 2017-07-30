//
//  Controller.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/30.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Controller.hpp"

#include "Data.h"
#include "Test_option.hpp"
#include "Database_controll_API.hpp"
#import "sqlite3.h"
#include "Data.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;




void Initialize_DataBase(sqlite3 *Database, char *err_msg)
{
    
    Test_Option *Test_Option_Instance=new Test_Option;
    
    //if(table未/已经创建)
    Test_Option_Instance->Run_CreateTable_Auto(Database, err_msg);
    
    //从数据库中获取所有数据
    
}


void Set_To_DataBase(sqlite3 *Database, char *err_msg,CatalogueData *Catalogue,EventData *Event)
{
    //"insert into event values (Key,0,0,'事件名','事件内容',0,20170727,20170727)"
    //"create table event(Id integer primary key,Catalogue_Index integer,Event_Index intelger,Title text,Detail text,State integer,Start_Time integer,End_Time integer)";
    
    int Database_Key=(Catalogue->CatalogueIndex+1)*100+Catalogue->Total;
    
    string Sqlite_Insert_Buffer="";
    Sqlite_Insert_Buffer+="insert into event values (";
    Sqlite_Insert_Buffer+=Format_int_To_string(Database_Key);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=Format_int_To_string(Catalogue->Total+1);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=Format_int_To_string(Catalogue->CatalogueIndex);
    Sqlite_Insert_Buffer+=",'";
    Sqlite_Insert_Buffer+=Event->Title;
    Sqlite_Insert_Buffer+="','";
    Sqlite_Insert_Buffer+=Event->Detail;
    Sqlite_Insert_Buffer+="',";
    Sqlite_Insert_Buffer+=Format_int_To_string(Event->Type);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=Format_int_To_string(Event->Begin);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=Format_int_To_string(Event->End);
    Sqlite_Insert_Buffer+=")";
    
    Sqlite_Insert_Buffer.c_str();
    char *Sqlite_Sentence=new char[sizeof(Event->Title)+sizeof(Event->Detail)+100];
    strcpy(Sqlite_Sentence,Sqlite_Insert_Buffer.c_str());
    
    Sql_Manual(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}



void Get_EventList_From_DataBase(sqlite3 *Database, char *err_msg,CatalogueData *Catalogue)
{
    //select * from event where Catalogue = /Catalogue->CatalogueIndex/;
    string Sqlite_Select_Buffer="select * from event where Catalogue_Index=";
    Sqlite_Select_Buffer+=Format_int_To_string(Catalogue->CatalogueIndex);
    
    char* Sqlite_Sentence=new char[100];

    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer.c_str());

    Displaytable_Manual(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

void Get_Event_From_DataBase(sqlite3 *Database, char *err_msg,CatalogueData *Catalogue)
{
    
}

string Format_int_To_string(int Integer)
{
    char char_temp[13];
    string str_temp;
    sprintf(char_temp,"%d",Integer);
    str_temp=char_temp;
    return str_temp;
}














