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

using namespace std;


void Initialize_DataBase();

void Set_Event_To_DataBase(int Catalogue,int Total_Event,int type,string title,string detail,string begin,string end);

//返回 分类总数 or 一个分类下的事件总数
int Get_Total_Number_From_DataBase(int Type,int Catalogue);

void Get_Catalogue_From_DataBase(int Catalogue);

void Get_EventList_From_DataBase(int Catalogue);

void Get_Event_From_DataBase(int Catalogue,int Event_Index);

void Delete_Event_From_Database(int Catalogue,int Event_Index);

void Update_Event_From_Database(int Catalogue,int Event_Index,int type,string title,string detail,string begin,string end);

string Format_select_Sentence(string Column);

string FormatTime(int Time);





#endif /* Controller_hpp */

