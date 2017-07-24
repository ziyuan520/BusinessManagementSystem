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

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void PrintCatalogueList(CatalogueData *Catalogue,int Number)
{
    for(int i=0;i<Number;i++)
    {
        cout<<i+1<<"."<<Catalogue[i].Name<<endl;
    }
}

int PrintEventList(CatalogueData *Catalogue)
{
    if(Catalogue->Total==0)
    {
        cout<<"该列表没有事项"<<endl;
        return 0;
    }
    
    for(int i=0;i<Catalogue->Total;i++)
    {
        cout<<i+1<<"."<<Catalogue->EventIndex[i]->Title<<endl;
    }
    return 1;
}

void PrintEvent(EventData *Event)
{
    cout<<"标题:"<<Event->Title<<endl;
    cout<<"内容"<<Event->Detail<<endl;
    if(Event->Type==1)
    {
        //待修改:将时间由int转换为string 输出"x年x月x日"
        cout<<"开始时间："<<Event->Begin<<endl;
        cout<<"结束时间:"<<Event->End<<endl;
    }
    else if(Event->Type==2)
    {
        cout<<"完成日期:"<<Event->End<<endl;
    }
}

int CreatOneEvent(CatalogueData *Catalogue)  //未完成
{
    if(Catalogue->Total<10)
    {
        
        
        int type=0;
        char title[100];
        char detail[500];
        int begin=0;
        int end=0;
        
        cout<<"标题:";
        cin.getline(title,100);
        cout<<"内容:";
        cin.getline(detail,500);
        //待修改:getline(cin,string str),检测str长度是否超出字数限制
        
        cout<<"输入时间(如：2017年07月18日输入为20170718)，不输入则设定为今日："<<endl;
        cout<<"开始时间：";
        cin>>begin;
        cout<<"结束时间";
        cin>>end;
        //待修改：检测输入是否合法，输入当前系统时间
        //SetEvent(Event, type, title, detail, begin, end);
    
        
        return 1;
    }
    else
    {
        cout<<"error，该分类已满，无法添加"<<endl;
    }
    
    return 0;
}
























