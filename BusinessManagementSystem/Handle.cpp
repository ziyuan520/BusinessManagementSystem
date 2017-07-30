//
//  Handle.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Handle.h"
#include "Data.h"

#include "EventController.h"
#include "CatalogueController.h"
#include "Controller.hpp"

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void Start()
{
    CatalogueData List[3];
    string All_Event="All Event";
    string Schedule="Schedule";
    string Finished="Finished";
    
    SetCatalogue(&List[0],0,0, All_Event, nullptr);
    SetCatalogue(&List[1],1,0, Schedule, nullptr);
    SetCatalogue(&List[2],2,0, Finished, nullptr);

    
    Initialize_DataBase();
    //incomplete：缺少判断条件，若table已存在则不创建新表
    
    int Command = 1;
    
    int MenuIndex[2]={0,0};
    //MenuIndex[0] save Catalogue Index
    //MenuIndex[1] save Event Index
    
    while(Command!=0)
    {
        switch (Command)
        {
            case 1 :DisplayCatalogueList(List,&Command,MenuIndex);break;
            case 2 :DisplayEventList(List,&Command,MenuIndex);break;
            case 3 :DisplayEvent(List, &Command, MenuIndex);break;
            case 4 :AddEvent(List, &Command,MenuIndex);break;
        }
    }
    
}

void DisplayCatalogueList(CatalogueData* List,int* Command,int* MenuIndex)
{
    int tmp;
    cout<<"————————————————————"<<endl;
    cout<<"——欢迎使用事务管理系统——"<<endl;
    cout<<"——————— 列表 ————————"<<endl;
    PrintCatalogueList(List, 3);
    cout<<"————————————————————"<<endl;
    cout<<"请输入你要查看的事务分类编号(0退出):";
    cin>>tmp;
    if (tmp>=1&&tmp<=3)
    {
        *Command= 2 ;
        MenuIndex[0]=tmp;
    }
    else if(tmp==0)
        *Command= 0 ;
    else
    {
        cout<<"输入有误"<<endl;
        MenuIndex[0]=0;
        //*Cmd=1;
        
        //重置输入流
        cin.clear();
        cin.ignore();
    }
    
}

void DisplayEventList(CatalogueData* List,int* Command,int* MenuIndex)
{
    int tmp;
    cout<<"————————————————————"<<endl;
    cout<<"<"<<List[MenuIndex[0]-1].Name<<">"<<endl;
    PrintEventList(&List[MenuIndex[0]-1]);
    
    if(List[MenuIndex[0]-1].Total!=0)
    cout<<"请输入你要查看的事项编号,\n";
    
    cout<<"(0 后退|-1 添加事项):";
    
    cin>>tmp;
    
    if(tmp<=List[MenuIndex[0]-1].Total&&tmp>=1)
    {
        *Command= 3 ;
        MenuIndex[1]=tmp;
    }
    else if(tmp==-1)
    {
        *Command= 4 ;
    }
    else if(tmp==0)
    {
        *Command= 1 ;
    }
    else
    {
        cout<<"输入有误,请重新输入:"<<endl;
        
        //重置输入流
        cin.clear();
        cin.ignore();
    }
}

void DisplayEvent(CatalogueData* List,int* Command,int* MenuIndex)
{
    int tmp;
    cout<<"————————————————————"<<endl;
    PrintEvent(&List[MenuIndex[0]-1], MenuIndex[1]);
    //PrintEvent(List[MenuIndex[0]-1].EventIndex[MenuIndex[1]-1]);
    cout<<"(0 后退|-1 修改事项|-2 删除事项): ";
    cin>>tmp;
    
    if(tmp==0)
    {
        *Command=2;
    }
    else if(tmp==-1)
    {
        cout<<"该功能尚未完成"<<endl;
    }
    else if(tmp==-2)
    {
        cout<<"该功能尚未完成"<<endl;
    }
    else
    {
        cout<<"输入有误,请重新输入:"<<endl;
        
        //重置输入流
        cin.clear();
        cin.ignore();
    }
}

void AddEvent(CatalogueData* List,int* Command,int* MenuIndex)
{
    int tmp;
    cout<<"————————————————————"<<endl;
    tmp=CreatOneEvent(&List[MenuIndex[0]-1]);
    cout<<"————————————————————"<<endl;
    if(tmp==1)
    {
        cout<<"添加成功！"<<endl;
        
        //Display this new Event
        *Command=3;
        MenuIndex[1]=List[MenuIndex[0]-1].Total;
    }
    else
    {
        cout<<"添加失败。"<<endl;
        
        //Come back to Event List
        *Command=2;
    }
}

void PrintCatalogueList(CatalogueData *Catalogue,int Number)
{
    for(int i=0;i<Number;i++)
    {
        cout<<i+1<<"."<<Catalogue[i].Name<<endl;
    }
}

int PrintEventList(CatalogueData *Catalogue)
{
    Get_EventList_From_DataBase(Catalogue);
    
    //以下功能不可用
    /*
    if(Catalogue->Total==0)
    {
        cout<<"该列表没有事项"<<endl;
        return 0;
    }

    for(int i=0;i<Catalogue->Total;i++)
    {
        cout<<i+1<<"."<<Catalogue->EventIndex[i]->Title<<endl;
    }
         */
    return 1;
}

void PrintEvent(CatalogueData *Catalogue,int EventIndex)
{
    Get_Event_From_DataBase(Catalogue, EventIndex);
/*
    cout<<"标题: "<<Event->Title<<endl;
    cout<<"内容: "<<Event->Detail<<endl;

    if(Event->Begin!=0)
    {
        string BeginDate;
        
        BeginDate=FormatTime(Event->Begin); //formattiing,for print "****年**月**日"
        
        cout<<"开始时间："<<BeginDate<<endl;
    }

    if(Event->End!=0)
    {
        string EndDate;
        
        EndDate=FormatTime(Event->End);
        
        cout<<"结束时间: "<<EndDate<<endl;
    }

    
    else if(Event->Type==2)//incomplete;unused module
    {
        cout<<"完成日期: "<<Event->End<<endl;
    }
*/
}

int CreatOneEvent(CatalogueData *Catalogue)
{
    if(Catalogue->Total<10)
    {
        EventData *Event=new EventData;
        
        int type=0;
        string title;
        string detail;
        int begin;
        int end;
        
        cin.clear();
        cin.ignore();
        
        cout<<"标题: ";
        getline(cin,title);
        cout<<"内容: ";
        getline(cin,detail);
        
        //incomplete:the [condition] to cin the Begin and End
        cout<<"时间(2017/07/18,则输入20170718)，不输入则设定为今日："<<endl;
        cout<<"开始时间: ";
        cin>>begin;
        cout<<"结束时间: ";
        cin>>end;
        //incomplete：检测输入是否合法，加入当前系统时间
        SetEvent(Event, type, title, detail, Format_int_To_string(begin), Format_int_To_string(end));
        
        //写入数据库
        Set_To_DataBase(Catalogue, Event);

    //该功能不可用    Catalogue->EventIndex[Catalogue->Total]=Event;
        Catalogue->Total++;
        
        return 1;
    }
    else
    {
        cout<<"error，该分类已满"<<endl;
    }
    
    return 0;
}


