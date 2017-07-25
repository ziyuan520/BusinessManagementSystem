//
//  Handle.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Handle.h"
#include "Data.h"
#include "Controller.h"
#include "EventController.h"
#include "CatalogueController.h"

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void Start()
{
    CatalogueData List[3];
    char All_Event[30]="All Event";
    char Schedule[30]="Schedule";
    char Finished[30]="Finished";
    
    
    SetCatalogue(&List[0], 0, All_Event, nullptr);
    SetCatalogue(&List[1], 0, Schedule, nullptr);
    SetCatalogue(&List[2], 0, Finished, nullptr);
  //  cout<<List[2].Name<<endl;
    //待修改：需从数据库中读取Event数据 暂用nullptr代替 
    
    char Cmd = 'a';
    int Index[2]={0,0};
    
    while(Cmd!='q')
    {
        switch (Cmd)
        {
            case 'a':DisplayCatalogueList(List,&Cmd,Index);break;
            case'b':DisplayEventList(List,&Cmd,Index);break;
            case'c':DisplayEvent(List, &Cmd, Index);break;
            case'd':AddEvent(List, &Cmd,Index);break;
        }
    }
    
}

void DisplayCatalogueList(CatalogueData* List,char* Cmd,int* Index)
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
        *Cmd='b';
        Index[0]=tmp;
    }
    else if(tmp==0)
        *Cmd='q';
    else
    {
        cout<<"输入有误"<<endl;
        Index[0]=0;
        //*Cmd='a';
        
        //重置输入流
        cin.clear();
        cin.ignore();
    }
    
}

void DisplayEventList(CatalogueData* List,char* Cmd,int* Index)
{
    int tmp;
    cout<<"————————————————————"<<endl;
    cout<<"<"<<List[Index[0]-1].Name<<">"<<endl;
    PrintEventList(&List[Index[0]-1]);
    
    if(List[Index[0]-1].Total!=0)
    cout<<"请输入你要查看的事项编号,\n";
    
    cout<<"(0 后退|-1 添加事项):";
    
    cin>>tmp;
    
    if(tmp<=List[Index[0]-1].Total&&tmp>=1)
    {
        *Cmd='c';
        Index[1]=tmp;
    }
    else if(tmp==-1)
    {
        *Cmd='d';
    }
    else if(tmp==0)
    {
        *Cmd='a';
    }
    else
    {
        cout<<"输入有误,请重新输入:"<<endl;
        
        //重置输入流
        cin.clear();
        cin.ignore();
    }
}

void DisplayEvent(CatalogueData* List,char* Cmd,int* Index)
{
    int tmp;
    cout<<"————————————————————"<<endl;
    PrintEvent(List[Index[0]-1].EventIndex[Index[1]-1]);
    cout<<"(0 后退|-1 修改事项|-2 删除事项): ";
    cin>>tmp;
    
    if(tmp==0)
    {
        *Cmd='b';
    }
    else if(tmp==-1)
    {
        cout<<"该功能尚未完成"<<endl;
    }
    else if(tmp==-2)
    {
        cout<<"该功能尚未完成"<<endl;
    }
}

void AddEvent(CatalogueData* List,char* Cmd,int* Index)
{
    int tmp;
    cout<<"————————————————————"<<endl;
    tmp=CreatOneEvent(&List[Index[0]-1]);
    cout<<"————————————————————"<<endl;
    if(tmp==1)
    {
        cout<<"添加成功！"<<endl;
    }
    else
    {
        cout<<"添加失败。"<<endl;
    }
    
    //返回上一级，（事项列表）
    
    *Cmd='b';
    //(*Index=*Index;)
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
    if(Event->Type==0)  //待修改，为测试现有程序type==0， 0应该为1
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

int CreatOneEvent(CatalogueData *Catalogue)
{
    if(Catalogue->Total<10)
    {
        EventData *Event=new EventData;
        
        int type=0;
        char title[100];
        char detail[500];
        int begin=0;
        int end=0;
        
        cin.clear();
        cin.ignore();
        
        cout<<"标题 :";
        cin.getline(title,100);
        cout<<"内容 :";
        cin.getline(detail,500);
        //待修改:getline(cin,string str),检测str长度是否超出字数限制
        
        //待修改
        cout<<"时间(2017/07/18,则输入20170718)，不输入则设定为今日："<<endl;
        cout<<"开始时间 :";
        cin>>begin;
        cout<<"结束时间 :";
        cin>>end;
        //待修改：检测输入是否合法，输入当前系统时间
        SetEvent(Event, type, title, detail, begin, end);
        
        Catalogue->EventIndex[Catalogue->Total]=Event;
        Catalogue->Total++;
        
        return 1;
    }
    else
    {
        cout<<"error，该分类已满"<<endl;
    }
    
    return 0;
}


