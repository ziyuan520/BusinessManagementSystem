//
//  main.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/23.
//  Copyright © 2017年 Lean. All rights reserved.
//

//test #

#include "Handle.h"
#include "Data.h"
#include "Datebase_Test_API.hpp"
#include "Controller.hpp"
#import "sqlite3.h"
//end test



#include <iostream>


sqlite3 *Database;
char *err_msg;

int main(int argc, const char * argv[])
{
    EventData Event={0,"这是标题","这是内容",20151231,20171231};
    EventData Event2={0,"这是标题2","这是内容2",20150606,20170923};
    CatalogueData Catalogue={0,0,"今日代办",};
    
    Initialize_DataBase(Database, err_msg);
    cout<<"-------------------"<<endl;
    Set_To_DataBase(Database, err_msg, &Catalogue, &Event);
    Catalogue.Total++;
    Set_To_DataBase(Database, err_msg, &Catalogue, &Event2);
    cout<<"-------------------"<<endl;
    Get_EventList_From_DataBase(Database, err_msg, &Catalogue);
    cout<<"-------------------"<<endl;
    Displaytable_Call_Test_AllData(Database, err_msg);
    return 0;
}
