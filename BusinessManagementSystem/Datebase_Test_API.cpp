//
//  Datebase_Test_API.cpp
//  DataBaseTest
//
//  Created by 龙子俊 on 2017/7/27.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#include "Datebase_Test_API.hpp"
#include "Database_controll_API.hpp"
#import "sqlite3.h"
#include <iostream>

void CreateTable_Test(sqlite3 *Database, char *err_msg){
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("打开数据库成功！\n");
    
<<<<<<< HEAD
    char Sql_Create_Buffer[200]= "create table event(Id integer primary key,Title text,Catalogue text,State integer,Start_Time text,End_Time text)";
    char Sql_Delete[100]= "drop table event";
=======
    const char Sql_Create_Buffer[200]="create table event(Id integer primary key,Catalogue_Index integer,Event_Index integer,Title text,Detail text,State integer,Start_Time text,End_Time text)";
    
    const char Sql_Delete[100]= "drop table event";
>>>>>>> branch_lean_1
    
    if (sqlite3_exec(Database, Sql_Delete, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Database deleted successfully"<<endl;
    
    if (sqlite3_exec(Database, Sql_Create_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Database created successfully"<<endl;
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("关闭数据库成功！\n");
}

void Insert_Test(sqlite3 *Database, char *err_msg){
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("打开数据库成功！\n");
    
<<<<<<< HEAD
    const char *Sql_Insert_Buffer = new char[200];
    Sql_Insert_Buffer = "insert into event values (54,'车日天是狗','全部事项',0,'201707272330','201707272400')";
=======
    char *Sql_Insert_Buffer = new char[200];
    strcpy(Sql_Insert_Buffer,"insert into event values (54,'车日天是狗','全部事项',0,'201707272330','201707272400')");
    
>>>>>>> branch_lean_1
    if (sqlite3_exec(Database, Sql_Insert_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Data inserted successfully"<<endl;
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("关闭数据库成功！\n");
<<<<<<< HEAD
    
=======
    //delete
    delete []Sql_Insert_Buffer;
>>>>>>> branch_lean_1
}

void Displaytable_Test_AllData(sqlite3 *Database, char *err_msg){
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("打开数据库成功！\n");
    char *Sql_Query_Buffer = new char[100];
<<<<<<< HEAD
    
    Sql_Query_Buffer = "select * from event";
=======
    strcpy(Sql_Query_Buffer, "select * from event");

>>>>>>> branch_lean_1
    if(sqlite3_exec(Database,Sql_Query_Buffer, &sqlite3_exec_callback, 0, &err_msg)!=SQLITE_OK)
    {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Data display successfully"<<endl;
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("关闭数据库成功！\n");
<<<<<<< HEAD
}

void CreateTable_Call_Test(sqlite3 *Database, char *err_msg){
    char Sql_Create_Buffer[200]= "create table event(Id integer primary key,Title text,Catalogue text,State integer,Start_Time text,End_Time text)";
    CreateTable_Manual(Database, err_msg, Sql_Create_Buffer);
}

void Insert_Call_Test(sqlite3 *Database, char *err_msg){
    char Sql_Insert_Buffer[200] = "insert into event values (54,'车日天是狗','全部事项',0,'201707272330','201707272400')";
    Sql_Manual(Database, err_msg, Sql_Insert_Buffer);
}

void Displaytable_Call_Test_AllData(sqlite3 *Database, char *err_msg){
    char Sql_Query_Buffer [200] = "select * from event";
    Displaytable_Manual(Database, err_msg, Sql_Query_Buffer);
}

void CreateTable_Enter_Call_Test(sqlite3 *Database, char *err_msg){
    //char Sql_Create_Buffer[200];
    //cin.getline(Sql_Create_Buffer, 200);
    CreateTable_Manual(Database, err_msg, nullptr);
}
void Insert_Enter_Call_Test(sqlite3 *Database, char *err_msg){
    Sql_Manual(Database, err_msg, nullptr);
}
void Displaytable_Enter_Call_Test_AllData(sqlite3 *Database, char *err_msg){
    Displaytable_Manual(Database, err_msg, nullptr);
=======
    
    //delete
    delete []Sql_Query_Buffer;
}

void CreateTable_Default_Call_Test(sqlite3 *Database, char *err_msg){
    char Sql_Create_Buffer[200]="create table event(Id integer primary key,Catalogue_Index integer,Event_Index integer,Title text,Detail text,State integer,Start_Time text,End_Time text)";
    createTable_Intelligent_API(Database, err_msg, Sql_Create_Buffer);
}

void Insert_Default_Call_Test(sqlite3 *Database, char *err_msg){
    char Sql_Insert_Buffer[200] = "insert into event values (54,'车日天是狗','全部事项',0,'201707272330','201707272400')";
    Sql_Intelligent_API(Database, err_msg, Sql_Insert_Buffer);
}

void Displaytable_Default_Call_Test_AllData(sqlite3 *Database, char *err_msg){
    char Sql_Query_Buffer [200] = "select * from event";
    Displaytable_Intelligent_API(Database, err_msg, Sql_Query_Buffer);
}

void CreateTable_Enter_Call_Test(sqlite3 *Database, char *err_msg){

    createTable_Intelligent_API(Database, err_msg, nullptr);
}
void Insert_Enter_Call_Test(sqlite3 *Database, char *err_msg){
    Sql_Intelligent_API(Database, err_msg, nullptr);
}

void Displaytable_Enter_Call_Test_AllData(sqlite3 *Database, char *err_msg){
    Displaytable_Intelligent_API(Database, err_msg, nullptr);
>>>>>>> branch_lean_1
}
