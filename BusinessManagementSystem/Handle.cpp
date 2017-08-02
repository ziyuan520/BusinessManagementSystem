//
//  Handle.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Handle.h"
#include "Data.h"

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
    
    SetCatalogue(&List[0],0,0, All_Event);
    SetCatalogue(&List[1],1,0, Schedule);
    SetCatalogue(&List[2],2,0, Finished);

    
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
            case 5 :UpdateEvent(List, &Command, MenuIndex);break;
            case 6:DeleteEvent(List, &Command, MenuIndex);break;

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
    cout<<"请输入你要查看的事务分类编号(0 退出|-1 添加事项):";
    cin>>tmp;
    if (tmp>=1&&tmp<=3)
    {
        *Command= 2 ;
        MenuIndex[0] = tmp;
    }
    else if(tmp==0)
        *Command = 0 ;
    else if(tmp==-1)
    {
        MenuIndex[0]=-1;
        *Command=4;
    }
    else
    {
        cout<<"输入有误"<<endl;
        MenuIndex[0] = 0;
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

    Get_EventList_From_DataBase(&List[MenuIndex[0]-1]);
    
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

    Get_Event_From_DataBase(&List[MenuIndex[0]-1], MenuIndex[1]);
    cout<<"(0 后退|-1 修改事项|-2 删除事项): ";
    cin>>tmp;
    
    if(tmp==0)
    {
        *Command=2;
    }
    else if(tmp==-1)
    {
        *Command=5;
    }
    else if(tmp==-2)
    {
        *Command=6;
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

    if(MenuIndex[0]==-1)
    {
        cout<<"请输出你要添加进入的<分类>编号: ";

        if(cin>>tmp&&tmp>=1&&tmp<=3)
        {
            MenuIndex[0]=tmp;
        }
        else
        {
            cout<<"————————————————————"<<endl;
            cout<<"输入有误，请重新输入"<<endl;
            
            //重置输入流
            cin.clear();
            cin.ignore();
        }
    }
    cout<<"————————————————————"<<endl;
   
    if(/* DISABLES CODE */ (1))
    {
        
        int type=1;
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
        
        //SetEvent(Event, type, title, detail, Format_int_To_string(begin), Format_int_To_string(end));
        
        //写入数据库
        Set_To_DataBase(&List[MenuIndex[0]-1], type, title, detail, FormatTime(begin), FormatTime(end));
        
        List[MenuIndex[0]-1].Total++;
        
        *Command=3;
        MenuIndex[1]=List[MenuIndex[0]-1].Total;
        cout<<"————————————————————"<<endl;
        cout<<"添加成功!"<<endl;
    }
    
    /*
    cout<<"————————————————————"<<endl;
    /*
    if(tmp==1)
    {
        cout<<"————————————————————"<<endl;
        cout<<"添加成功！"<<endl;
        
        //Display this new Event
        *Command=3;
        MenuIndex[1]=List[MenuIndex[0]-1].Total;
    }
    else
    {
        cout<<"————————————————————"<<endl;
        cout<<"添加失败。"<<endl;
        
        //Come back to Event List
        *Command=2;
    }
     */
}

void PrintCatalogueList(CatalogueData *Catalogue,int Number)
{
    for(int i=0;i<Number;i++)
    {
        cout<<i+1<<"."<<Catalogue[i].Name<<endl;
    }
}

void DeleteEvent(CatalogueData* List,int* Command,int* MenuIndex)
{
    
    //cout<<"确定删除？(1 确定|0 取消)？";
    cout<<"————————————————————"<<endl;
    if(MenuIndex[1]>=1&&MenuIndex[1]<=List[MenuIndex[0]-1].Total)
    {
        Delete_Event_From_Database(&List[MenuIndex[0]-1], MenuIndex[1]);
        cout<<"删除成功"<<endl;
        List[MenuIndex[0]-1].Total--;
        *Command=2; //come back to Event List
    }
    else
    {
        cout<<"输入有误，请重新输入"<<endl;
        //重置输入流
        cin.clear();
        cin.ignore();
    }
}

void UpdateEvent(CatalogueData* List,int* Command,int* MenuIndex)
{
    if(/* DISABLES CODE */ (1))
    {
        
        int type=1;
        string title;
        string detail;
        int begin;
        int end;
        
        cin.clear();
        cin.ignore();
        cout<<"————————————————————"<<endl;
        cout<<"输入要修改的内容，不输入则不更改"<<endl;
        cout<<"标题: ";
        getline(cin,title);
        cout<<"内容: ";
        getline(cin,detail);
        
        //incomplete:the [condition] to cin the Begin and End
        cout<<"时间(2017/07/18,则输入20170718)，输入0则不更改（bug） ："<<endl;
        cout<<"开始时间: ";
        cin>>begin;
        cout<<"结束时间: ";
        cin>>end;
        //incomplete：检测输入是否合法
        
        
        Update_Event_From_Database(&List[MenuIndex[0]-1], MenuIndex[1], type, title, detail,FormatTime(begin), FormatTime(end));
        cout<<"————————————————————"<<endl;
        cout<<"修改成功!"<<endl;
        *Command=3;
    }
    
}
