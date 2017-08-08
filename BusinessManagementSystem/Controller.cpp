//
//  Controller.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/30.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Controller.hpp"

#include "Data.h"
#include "Database_controll_API.hpp"
#import "sqlite3.h"
#include "Data.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

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
        
        char Sql_Insert_Buffer[200]="insert into catalogue values (1,'全部事项')";
        Sql_Intelligent_API(Database, err_msg, Sql_Insert_Buffer);
        
        strcpy(Sql_Insert_Buffer,"insert into catalogue values (2,'日程表')");
        Sql_Intelligent_API(Database, err_msg, Sql_Insert_Buffer);
        
        strcpy(Sql_Insert_Buffer,"insert into catalogue values (3,'已完成')");
        Sql_Intelligent_API(Database, err_msg, Sql_Insert_Buffer);
    }

}


void Set_To_DataBase(CatalogueData *Catalogue,int type,string title,string detail,string begin,string end)
{
    //"insert into event values ()"
    //"create table event(Id integer primary key,Catalogue_Index integer,Event_Index integer,Title text,Detail text,State integer,Start_Time text,End_Time text)";
    
    int Database_Key=(Catalogue->CatalogueIndex+1)*100+Catalogue->Total;
    
    string Sqlite_Insert_Buffer="";
    Sqlite_Insert_Buffer+="insert into event values (";
    Sqlite_Insert_Buffer+=to_string(Database_Key);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=to_string(Catalogue->CatalogueIndex);
    Sqlite_Insert_Buffer+=",";
    Sqlite_Insert_Buffer+=to_string(Catalogue->Total+1);
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

void Get_Catalogue_From_DataBase()
{
    char Sql_Select_Buffer[100]="select id,Name from catalogue where id>0";
    Displaytable_Intelligent_API(Database, err_msg, Sql_Select_Buffer);
}

void Get_EventList_From_DataBase(CatalogueData *Catalogue)
{
    //select Title from event where Catalogue_Index = \Catalogue->CatalogueIndex\;
   
    string Sqlite_Select_Buffer=Format_select_Sentence("Event, Title"); //select Title from event.
    Sqlite_Select_Buffer+=" where Catalogue = ";
    Sqlite_Select_Buffer+=to_string(Catalogue->CatalogueIndex);

    char* Sqlite_Sentence=new char[100];

    strcpy(Sqlite_Sentence, Sqlite_Select_Buffer.c_str());

    Displaytable_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

void Get_Event_From_DataBase(CatalogueData *Catalogue,int EventIndex)
{
    //标题 内容 开始时间 结束时间
    //select \Column\ from event where Catalogue_Index = \Catalogue->CatalogueIndex\ and Event_Index=\EnentIndex\;
    
    string Sqlite_Select_Buffer_Head;
    
    string Sqlite_Select_Buffer_Tail=" where Catalogue = ";
    Sqlite_Select_Buffer_Tail+=to_string(Catalogue->CatalogueIndex);
    Sqlite_Select_Buffer_Tail+=" and Event = ";
    Sqlite_Select_Buffer_Tail+=to_string(EventIndex);
    
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

void Delete_Event_From_Database(CatalogueData *Catalogue,int EventIndex)
{
    string Sqlite_Delete_Buffer="delete from event where Catalogue = ";
    Sqlite_Delete_Buffer+=to_string(Catalogue->CatalogueIndex);
    Sqlite_Delete_Buffer+=" and Event = ";
    Sqlite_Delete_Buffer+=to_string(EventIndex);
    
    char* Sqlite_Sentence=new char[100];
    strcpy(Sqlite_Sentence,Sqlite_Delete_Buffer.c_str());
    
    Sql_Intelligent_API(Database, err_msg, Sqlite_Sentence);
    
    delete[] Sqlite_Sentence;
}

void Update_Event_From_Database(CatalogueData *Catalogue,int EventIndex,int type,string title,string detail,string begin,string end)
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
    
    //无意义的修改，用于防止sql语句错误。
    Sqlite_Update_Buffer+="Catalogue = ";
    Sqlite_Update_Buffer+=to_string(Catalogue->CatalogueIndex);
    
    Sqlite_Update_Buffer+=" where Catalogue = ";
    Sqlite_Update_Buffer+=to_string(Catalogue->CatalogueIndex);
    Sqlite_Update_Buffer+=" and Event = ";
    Sqlite_Update_Buffer+=to_string(EventIndex);
    
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

void SetCatalogue(CatalogueData *Catalogue,int catalogueIndex,int total,string name)
{
    Catalogue->CatalogueIndex=catalogueIndex;
    Catalogue->Total=total;
    Catalogue->Name=name;
}
/*
 string strSql = "select * from MyTable";
 char** pResult;
 int nRow;
 int nCol;
 nResult = sqlite3_get_table(db,strSql.c_str(),&pResult,&nRow,&nC,&errmsg);
 if (nResult != SQLITE_OK)
 {
 sqlite3_close(db);
 cout<<errmsg<<endl;
 sqlite3_free(errmsg);
 return 0;
 }

nResult = sqlite3_get_table(db,strSql.c_str(),&pResult,&nRow,&nCol,&errmsg);
if (nResult != SQLITE_OK)
{
    sqlite3_close(db);
    cout<<errmsg<<endl;
    sqlite3_free(errmsg);
    return 0;
    }
*/




int Get_Event_Number_From_Database(int CatalogueIndex)
{
    //select Title from event where Catalogue = \Catalogue->CatalogueIndex\ and Event_Index=\EnentIndex\;
    char** colResult=nullptr;
    int nRow;
    int nColumn;
    
    //Redefined:
    //sqlite3 *Database=nullptr;
    //char *err_msg=nullptr;
    
    string Sql_Select_Buffer="select Title from Event where Catalogue =";
    Sql_Select_Buffer+=to_string(CatalogueIndex);
    char *Sql_Sentence=new char[100];
    
    strcpy(Sql_Sentence, Sql_Select_Buffer.c_str());
    
    
    if (sqlite3_get_table(Database,Sql_Sentence,&colResult,&nRow,&nColumn,&err_msg))
    {
        cout<<"Operation fail"<<err_msg;
        cout<<"The sql sentence is: "<<Sql_Select_Buffer;
        exit(-1);
    }
    //    else cout<<"Data inserted successfully"<<endl;
    delete[] Sql_Sentence;
    return nRow;
}







