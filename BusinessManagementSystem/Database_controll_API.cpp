     //
//  Database_controll_API.cpp
//  DataBaseTest
//
//  Created by 龙子俊 on 2017/7/27.
//  Copyright © 2017年 Longkuku. All rights reserved.
//

#include "Database_controll_API.hpp"
#include "Datebase_Test_API.hpp"
#include <iostream>
#import "sqlite3.h"
using namespace std;

<<<<<<< HEAD
=======
static bool checkTableIsExist_Values = 0;
>>>>>>> branch_lean_1


int sqlite3_exec_callback(void *data, int nColumn, char **colValues, char **colNames)
{
    for (int i = 0; i < nColumn; i++)
    {
        printf("%s\t", colValues[i]);
    }
    printf("\n");
    
    return 0;
}

<<<<<<< HEAD
int sqlite3_exec_callback_checkexsit(void *data, int nColumn, char **colValues, char **colNames){
    //    int check;
    //    char compare[2] = "1";
    //    if(*colValues[0]==compare[0]){check=1;}
    //    else check = 0;
    //    printf("%s", colValues[0]);
    //    cout<<check;
    for (int i = 0; i < nColumn; i++)
    {
        printf("%s\t", colValues[i]);
    }
    printf("\n");
    
    cout<<"running";
    return 0;
}

int CheckTableExist(char *Sql,sqlite3 *Database, char *err_msg){
    int check = 0;
    
    char * Sql_Sentence = Sql;
    //sql_sentence = "SELECT COUNT(*) FROM sqlite_master where type='table' and name='20170526'";
    cout<<Sql_Sentence<<endl;
    //check =
    if(sqlite3_exec(Database, Sql_Sentence, &sqlite3_exec_callback, 0, &err_msg)){
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    };
    
    cout<<check<<endl;
    return check;
}

void CreateTable_Manual(sqlite3 *Database, char *err_msg, char *sql){
=======
int sqlite3_exec_callback_checkisexsit(void *data, int nColumn, char **colValues, char **colNames){
    char compare = '1';
    
    if(*colValues[0]==compare){checkTableIsExist_Values = 1;}
    else checkTableIsExist_Values = 0;

    cout<<"CallReturn values is : "<<colValues[0]<<endl;
    cout<<"Return values is : "<<checkTableIsExist_Values<<endl;

    return 0;
}

bool CheckTableISExist(char *tableName,sqlite3 *Database, char *err_msg){
    
    //data
    char *sql_Sentence = new char[200];
    strcpy(sql_Sentence,"SELECT COUNT(*) FROM sqlite_master where type='table' and name=");
    //
    
    //add tablename into sql
    if (tableName != nullptr) {
        strcat(sql_Sentence, tableName);
        cout<<"sql is : "<<sql_Sentence<<"."<<endl;
    }
    else cout<<"sytax error,please enter the right name."<<endl;
    
    if(sqlite3_exec(Database, sql_Sentence, &sqlite3_exec_callback_checkisexsit, 0, &err_msg)){
        cout<<"Operation fail:"<<err_msg;
        exit(-1);
    }
    else cout<<"sql excuted succesfully."<<endl;
    
    cout<<"checkTableIsExist_Values is :"<<checkTableIsExist_Values<<"."<<endl;
    //
    
    //data delete
    delete []sql_Sentence;
    return checkTableIsExist_Values;
    //
}

char *catch_Title_EventName_DisplayALL(char *pointer1,char *pointer2){
    //data
    long titleLength = strlen(pointer1);
    long nameLength = strlen(pointer2);
    char *Sql_Display_Buffer= new char[titleLength+nameLength+10];
    strcpy(Sql_Display_Buffer, "select ");
    //
    
    //input
    if (pointer1 != nullptr) {
        strcat(Sql_Display_Buffer, pointer1);
        
    }
    else strcpy(Sql_Display_Buffer, "*");
    
    strcat(Sql_Display_Buffer, " from ");
    if (pointer2 != nullptr) {
        strcat(Sql_Display_Buffer, pointer2);
    }
    else cout<<"sytax error,please enter the right name";
    cout<<"The sql is: "<<Sql_Display_Buffer<<endl;
    //
    
    //delete
    delete []Sql_Display_Buffer;
    return Sql_Display_Buffer;
    //
}

void deletePointer(){

}

void createTable_Intelligent_API(sqlite3 *Database, char *err_msg, char *sql){
    //open
>>>>>>> branch_lean_1
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("打开数据库成功！\n");
<<<<<<< HEAD
=======
    //
    
    //choose excute sentence
>>>>>>> branch_lean_1
    char *Sql_Create_Buffer = new char[200];
    if(sql==nullptr)
    {
        cout<<"please enter sql"<<endl;
        cin.getline(Sql_Create_Buffer, 200);
<<<<<<< HEAD
        cout<<Sql_Create_Buffer<<endl;
    }
    else    {
        Sql_Create_Buffer = sql;
        cout<<Sql_Create_Buffer<<endl;
    }
    
    char Sql_Delete[100]= "drop table event";
    
    if (sqlite3_exec(Database, Sql_Delete, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Database deleted successfully"<<endl;
    
=======
        cout<<"sql is :"<<Sql_Create_Buffer<<"."<<endl;
    }
    else    {
        Sql_Create_Buffer = sql;
        cout<<"sql is :"<<Sql_Create_Buffer<<"."<<endl;
    }
    //
    
    //choose whether excute drop
    char Sql_Delete[100]= "drop table event";
    char *tableName = new char[200];
    strcpy(tableName, "'event'");
    //
    
    //excute delete
    if (CheckTableISExist(tableName, Database, err_msg)) {
        if (sqlite3_exec(Database, Sql_Delete, NULL, NULL, &err_msg) != SQLITE_OK) {
            cout<<"Operation fail"<<err_msg;
            exit(-1);
        }
        else cout<<"Database deleted successfully"<<endl;
    }
    //
    
    //excute sql create
>>>>>>> branch_lean_1
    if (sqlite3_exec(Database, Sql_Create_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
    else cout<<"Database created successfully"<<endl;
<<<<<<< HEAD
=======
    //
    
    //close
>>>>>>> branch_lean_1
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
    else printf("关闭数据库成功！\n");
<<<<<<< HEAD
}


void Sql_Manual(sqlite3 *Database, char *err_msg,char *sql){
=======
    //
    
    //delete
    //delete []Sql_Create_Buffer;
    delete []tableName;
    //
    
}

void Sql_Intelligent_API(sqlite3 *Database, char *err_msg,char *sql){
    //open
>>>>>>> branch_lean_1
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
<<<<<<< HEAD
    else printf("打开数据库成功！\n");
    
    char *Sql_Insert_Buffer = new char[200];
    if(sql==nullptr)
    {
        cout<<"please enter sql"<<endl;
        cin.getline(Sql_Insert_Buffer, 200);
        cout<<Sql_Insert_Buffer<<endl;
    }
    else    {
        Sql_Insert_Buffer = sql;
        cout<<Sql_Insert_Buffer<<endl;
    }
    
=======
//    else printf("打开数据库成功！\n");
    //
    
    //input
    char *Sql_Insert_Buffer = new char[200];
    
    if(sql==nullptr)
    {
        cout<<"please enter sql(support all sql sentence): "<<endl;
        cin.getline(Sql_Insert_Buffer, 200);
        cout<<"sql sentence is"<<Sql_Insert_Buffer<<endl;
    }
    else    {
//        cout<<"run default sql sentence."<<endl;
        Sql_Insert_Buffer = sql;
//        cout<<"sql sentence is: "<<Sql_Insert_Buffer<<"."<<endl;
    }
    //
    
    //excute
>>>>>>> branch_lean_1
    if (sqlite3_exec(Database, Sql_Insert_Buffer, NULL, NULL, &err_msg) != SQLITE_OK) {
        cout<<"Operation fail"<<err_msg;
        exit(-1);
    }
<<<<<<< HEAD
    else cout<<"Data inserted successfully"<<endl;
=======
//    else cout<<"Data inserted successfully"<<endl;
    //
    
    //close
>>>>>>> branch_lean_1
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
<<<<<<< HEAD
    else printf("关闭数据库成功！\n");
    
}

void Displaytable_Manual(sqlite3 *Database, char *err_msg,char *sql){
=======
//    else printf("关闭数据库成功！\n");
    //
    
    //delete
    //delete []Sql_Insert_Buffer;
    //
}

void Displaytable_Intelligent_API(sqlite3 *Database, char *err_msg,char *sql){
    //open
>>>>>>> branch_lean_1
    if(sqlite3_open("test.db", &Database) != SQLITE_OK)
    {
        printf("无法打开，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
<<<<<<< HEAD
    else printf("打开数据库成功！\n");
    
    char *Sql_Query_Buffer = new char[200];
    if(sql==nullptr)
    {
        cout<<"please enter sql"<<endl;
        cin.getline(Sql_Query_Buffer, 200);
        cout<<Sql_Query_Buffer<<endl;
    }
    else    Sql_Query_Buffer = sql;
    cout<<Sql_Query_Buffer<<endl;
    
    if(sqlite3_exec(Database,Sql_Query_Buffer, &sqlite3_exec_callback, 0, &err_msg)!=SQLITE_OK)
    {
        cout<<"Operation fail:"<<err_msg<<endl;
        exit(-1);
    }
    else cout<<"Data display successfully"<<endl;
=======
//    else printf(" 连接数据库成功！\n");
    //
    
    //data
    char *Sql_Display_Buffer = new char[200];
    char *Open_Name = new char[100];
    //
    
    //input
    if(sql==nullptr)
    {
        cout<<"Please enter the item name"<<endl;
        char *itemName = new char[200];
        char *tableName = new char[100];
        cin.getline(itemName, 200);
        cin.getline(tableName, 200);
        Sql_Display_Buffer = catch_Title_EventName_DisplayALL(itemName, tableName);
        cout<<"Sql_Display_Buffer is :"<<Sql_Display_Buffer<<endl;
    }
    else    Sql_Display_Buffer = sql;
//    cout<<Sql_Display_Buffer<<endl;
    //
    
    //excute
    if(sqlite3_exec(Database,Sql_Display_Buffer, &sqlite3_exec_callback, 0, &err_msg)!=SQLITE_OK)
    {
        cout<<"Operation fail:"<<err_msg;
        exit(-1);
    }
//    else cout<<"Data display successfully"<<endl;
    //
    
    //close
>>>>>>> branch_lean_1
    if (sqlite3_close(Database) != SQLITE_OK)
    {
        printf("无法关闭，错误代码: %s\n", sqlite3_errmsg(Database));
        exit(-1);
    }
<<<<<<< HEAD
    else printf("关闭数据库成功！\n");
=======
//    else printf("断开数据库连接成功！\n");
    //
    //delete
    delete []Open_Name;
    //delete []Sql_Display_Buffer;
    //
>>>>>>> branch_lean_1
}
