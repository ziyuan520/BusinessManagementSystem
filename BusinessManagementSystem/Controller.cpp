//
//  Controller.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/30.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Controller.hpp"


#include "Database_controll_API.hpp"
#import "sqlite3.h"

#include <iostream>
#include <string>
#include <string.h>

sqlite3 *Database=nullptr;
char *err_msg=nullptr;



void Initialize_DataBase()
{
    //if(table未/已经创建)
    //creat table : event
    char Sql_Create_Buffer[200]="create table event(Id integer primary key,Catalogue integer,Event integer,Title text,Detail text,State integer,Start_Time text,End_Time text)";
    createTable_Intelligent_API(Database, err_msg, Sql_Create_Buffer);
    
    if(1)
    {
        //creat table : catalogue
        strcpy(Sql_Create_Buffer, "create table catalogue(Id integer primary key,Name text)");
        Sql_Intelligent_API(Database, err_msg, Sql_Create_Buffer);
        
        char Sql_Insert_Buffer[200]="insert into catalogue values (1,'<全部事项>')";
        Sql_Intelligent_API(Database, err_msg, Sql_Insert_Buffer);
        
        strcpy(Sql_Insert_Buffer,"insert into catalogue values (2,'<日程表>')");
        Sql_Intelligent_API(Database, err_msg, Sql_Insert_Buffer);
        
        strcpy(Sql_Insert_Buffer,"insert into catalogue values (3,'<已完成>')");
        Sql_Intelligent_API(Database, err_msg, Sql_Insert_Buffer);
    }

}


void Set_Event_To_DataBase(int Catalogue,int Total_Event,int type,string title,string detail,string begin,string end)
{
    //"insert into event values ()"
    //"create table event(Id integer primary key,Catalogue_Index integer,Event_Index integer,Title text,Detail text,State integer,Start_Time text,End_Time text)";
    
    int Database_Key=Catalogue*100+Total_Event;
    
    string Sqlite_Insert_Buffer="";
    Sqlite_Insert_Buffer+="insert into event values (";
    Sqlite_Insert_Buffer+=to_string(Database_Key);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=to_string(Catalogue);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=to_string(Total_Event+1);
    Sqlite_Insert_Buffer+=",'";
    Sqlite_Insert_Buffer+=title;
    Sqlite_Insert_Buffer+="','";
    Sqlite_Insert_Buffer+=detail;
    Sqlite_Insert_Buffer+="',";
    Sqlite_Insert_Buffer+=to_string(type);
    Sqlite_Insert_Buffer+=",'";
    Sqlite_Insert_Buffer+=begin;
    Sqlite_Insert_Buffer+="','";
    Sqlite_Insert_Buffer+=end;
    Sqlite_Insert_Buffer+="')";
    
    Sqlite_Insert_Buffer.c_str();
    char *Sqlite_Sentence=new char[sizeof(title)+sizeof(detail)+100];
    strcpy(Sqlite_Sentence,Sqlite_Insert_Buffer.c_str());
    
    cout<<Sqlite_Insert_Buffer<<endl;
    Sql_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

//type = 0:get the total Catalogue, 1:get the total Event
int Get_Total_Number_From_DataBase(int Type,int Catalogue)
{
    //select (column) from (table:catalogue or event) where (.....)
    
    string Sql_Select_Buffer;
    if(Type==0)
    {
        Sql_Select_Buffer="select Name from catalogue where id>0";
    }
    else if(Type==1)
    {
        Sql_Select_Buffer="select TItle from event where Catalogue =";
        Sql_Select_Buffer+=to_string(Catalogue);
    }
    
    char *Sql_Sentence=new char[100];
    strcpy(Sql_Sentence, Sql_Select_Buffer.c_str());
    
    int Total_Number=Get_Row_From_Database(Database, err_msg,Sql_Sentence);
    
    return Total_Number;
}

void Get_Catalogue_From_DataBase(int Catalogue)
{
    string Sql_Select_Buffer;
    if(Catalogue==0)
    {
        Sql_Select_Buffer="select id,Name from catalogue where id>0";
    }
    else
    {
        Sql_Select_Buffer="select id,Name from catalogue where id=";
        Sql_Select_Buffer+=to_string(Catalogue);
    }
    
    char *Sql_Sentence=new char[100];

    
    strcpy(Sql_Sentence,Sql_Select_Buffer.c_str());
    Displaytable_Intelligent_API(Database, err_msg, Sql_Sentence);
    delete[] Sql_Sentence;
}

void Get_EventList_From_DataBase(int Catalogue)
{
    //select Title from event where Catalogue_Index = \Catalogue->CatalogueIndex\;
   
    string Sqlite_Select_Buffer=Format_select_Sentence("Event, Title"); //select Title from event.
    Sqlite_Select_Buffer+=" where Catalogue = ";
    Sqlite_Select_Buffer+=to_string(Catalogue);

    char* Sqlite_Sentence=new char[100];

    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer.c_str());

    Displaytable_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

void Get_Event_From_DataBase(int Catalogue,int Event_Index)
{
    //标题 内容 开始时间 结束时间
    //select \Column\ from event where Catalogue_Index = \Catalogue->CatalogueIndex\ and Event_Index=\EnentIndex\;
    
    string Sqlite_Select_Buffer_Head;
    
    string Sqlite_Select_Buffer_Tail=" where Catalogue = ";
    Sqlite_Select_Buffer_Tail+=to_string(Catalogue);
    Sqlite_Select_Buffer_Tail+=" and Event = ";
    Sqlite_Select_Buffer_Tail+=to_string(Event_Index);
    
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

void Delete_Event_From_Database(int Catalogue,int EventIndex)
{
    string Sqlite_Delete_Buffer="delete from event where Catalogue = ";
    Sqlite_Delete_Buffer+=to_string(Catalogue);
    Sqlite_Delete_Buffer+=" and Event = ";
    Sqlite_Delete_Buffer+=to_string(EventIndex);
    
    char* Sqlite_Sentence=new char[100];
    strcpy(Sqlite_Sentence,Sqlite_Delete_Buffer.c_str());
    
    Sql_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

void Update_Event_From_Database(int Catalogue,int Event_Index,int type,string title,string detail,string begin,string end)
{
    //"create table event(Id integer primary key,Catalogue integer,Event integer,Title text,Detail text,State integer,Start_Time text,End_Time text)";
    //update event set xx=xx
    string Sqlite_Update_Buffer="update event set ";
    
    if(type!=0)
    {
        Sqlite_Update_Buffer+="State = ";
        Sqlite_Update_Buffer+=to_string(type);
        Sqlite_Update_Buffer+=", ";
    }

    if(title!="")
    {
        Sqlite_Update_Buffer+="Title = '";
        Sqlite_Update_Buffer+=title;
        Sqlite_Update_Buffer+="', ";
    }
    
    if(detail!="")
    {
        Sqlite_Update_Buffer+="Detail = '";
        Sqlite_Update_Buffer+=detail;
        Sqlite_Update_Buffer+="', ";
    }
    
    if(begin!="")
    {
        Sqlite_Update_Buffer+="Start_Time = '";
        Sqlite_Update_Buffer+=begin;
        Sqlite_Update_Buffer+="', ";
    }
    
    if(end!="")
    {
        Sqlite_Update_Buffer+="End_Time = '";
        Sqlite_Update_Buffer+=end;
        Sqlite_Update_Buffer+="', ";
    }
    
    //对数据无改动的语句，用于防止sql语法错误。
    Sqlite_Update_Buffer+="Catalogue = ";
    Sqlite_Update_Buffer+=to_string(Catalogue);
    //
    
    Sqlite_Update_Buffer+=" where Catalogue = ";
    Sqlite_Update_Buffer+=to_string(Catalogue);
    Sqlite_Update_Buffer+=" and Event = ";
    Sqlite_Update_Buffer+=to_string(Event_Index);
    
    char *Sqlite_Sentence=new char[sizeof(title)+sizeof(detail)+100];
    strcpy(Sqlite_Sentence,Sqlite_Update_Buffer.c_str());
    
    Sql_Intelligent_API(Database, err_msg, Sqlite_Sentence);
}

string Format_select_Sentence(string Column)
{
    string Sqlite_Select_Sentence="select ";
    Sqlite_Select_Sentence+=Column;
    Sqlite_Select_Sentence+=" from event";
    return Sqlite_Select_Sentence;
}

string FormatTime(int Time)
{
    
    int Year,Month,Day;
    
    string Date;
    
    
    Year=Time/10000;
    Month=Time/100-Year*100;
    Day=Time-Year*10000-Month*100;
    
    Date=to_string(Year)+"年"+to_string(Month)+"月"+to_string(Day)+"日";
    
    return Date;
}











