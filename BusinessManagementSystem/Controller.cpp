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
    //"create table event(Id integer primary key,Catalogue_Index integer,Event_Index integer,Title text,Detail text,State integer,Start_Time text,End_Time text)";
    
    int Database_Key=(Catalogue->CatalogueIndex+1)*100+Catalogue->Total;
    
    string Sqlite_Insert_Buffer="";
    Sqlite_Insert_Buffer+="insert into event values (";
    Sqlite_Insert_Buffer+=Format_int_To_string(Database_Key);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=Format_int_To_string(Catalogue->CatalogueIndex);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=Format_int_To_string(Catalogue->Total+1);
    Sqlite_Insert_Buffer+=",'";
    Sqlite_Insert_Buffer+=Event->Title;
    Sqlite_Insert_Buffer+="','";
    Sqlite_Insert_Buffer+=Event->Detail;
    Sqlite_Insert_Buffer+="',";
    Sqlite_Insert_Buffer+=Format_int_To_string(Event->Type);
    Sqlite_Insert_Buffer+=",'";
    Sqlite_Insert_Buffer+=Event->Begin;
    Sqlite_Insert_Buffer+="','";
    Sqlite_Insert_Buffer+=Event->End;
    Sqlite_Insert_Buffer+="')";
    
    Sqlite_Insert_Buffer.c_str();
    char *Sqlite_Sentence=new char[sizeof(Event->Title)+sizeof(Event->Detail)+100];
    strcpy(Sqlite_Sentence,Sqlite_Insert_Buffer.c_str());
    
    Sql_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}



void Get_EventList_From_DataBase(sqlite3 *Database, char *err_msg,CatalogueData *Catalogue)
{
    //select Title from event where Catalogue_Index = \Catalogue->CatalogueIndex\;
   
    string Sqlite_Select_Buffer=Format_select_Sentence("Event_Index, Title"); //select Title from event.
    Sqlite_Select_Buffer+=" where Catalogue_Index = ";
    Sqlite_Select_Buffer+=Format_int_To_string(Catalogue->CatalogueIndex);

    char* Sqlite_Sentence=new char[100];

    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer.c_str());

    Displaytable_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

void Get_Event_From_DataBase(sqlite3 *Database, char *err_msg,CatalogueData *Catalogue,int EventIndex)
{
    //标题 内容 开始时间 结束时间
    //select \Column\ from event where Catalogue_Index = \Catalogue->CatalogueIndex\ and Event_Index=\EnentIndex\;
    
    string Sqlite_Select_Buffer_Head;
    
    string Sqlite_Select_Buffer_Tail=" where Catalogue_Index = ";
    Sqlite_Select_Buffer_Tail+=Format_int_To_string(Catalogue->CatalogueIndex);
    Sqlite_Select_Buffer_Tail+=" and Event_Index = ";
    Sqlite_Select_Buffer_Tail+=Format_int_To_string(EventIndex);
    
    char* Sqlite_Sentence=new char[100];
    
    //1.Title
    Sqlite_Select_Buffer_Head=Format_select_Sentence("Title");
    Sqlite_Select_Buffer_Head+=Sqlite_Select_Buffer_Tail;
    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer_Head.c_str());
    cout<<"标题: ";
    Displaytable_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    //2.Detail
    Sqlite_Select_Buffer_Head=Format_select_Sentence("Detail");
    Sqlite_Select_Buffer_Head+=Sqlite_Select_Buffer_Tail;
    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer_Head.c_str());
    cout<<"内容: ";
    Displaytable_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    //3.Begin Time
    Sqlite_Select_Buffer_Head=Format_select_Sentence("Start_Time");
    Sqlite_Select_Buffer_Head+=Sqlite_Select_Buffer_Tail;
    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer_Head.c_str());
    cout<<"开始时间: ";
    Displaytable_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    //4.End Time
    Sqlite_Select_Buffer_Head=Format_select_Sentence("End_Time");
    Sqlite_Select_Buffer_Head+=Sqlite_Select_Buffer_Tail;
    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer_Head.c_str());
    cout<<"结束时间: ";
    Displaytable_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

string Format_int_To_string(int Integer)
{
    char char_temp[13];
    string str_temp;
    sprintf(char_temp,"%d",Integer);
    str_temp=char_temp;
    return str_temp;
}


string Format_select_Sentence(string Column)
{
    string Sqlite_Select_Sentence="select ";
    Sqlite_Select_Sentence+=Column;
    Sqlite_Select_Sentence+=" from event";
    return Sqlite_Select_Sentence;
}











