//
//  Handle.cpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#include "Handle.hpp"

#include "Controller.hpp"

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void Start()
{
   
    //incomplete：缺少判断条件，若数据库已存在则不运行
    Initialize_DataBase();
    
    int Command = 1;
    
    int MenuIndex[2]={0,0};
    //MenuIndex[0] save Catalogue Index
    //MenuIndex[1] save Event Index
    
    while(Command!=0)
    {
        switch (Command)
        {
            case 1 :DisplayCatalogueList(&Command,MenuIndex);break;
            case 2 :DisplayEventList(&Command,MenuIndex);break;
            case 3 :DisplayEvent(&Command, MenuIndex);break;
            case 4 :AddEvent(&Command,MenuIndex);break;
            case 5 :UpdateEvent(&Command, MenuIndex);break;
            case 6 :DeleteEvent(&Command, MenuIndex);break;
        }
    }
    
}

void DisplayCatalogueList(int* Command,int* MenuIndex)
{
    int tmp;
    int total=Get_Total_Number_From_DataBase(0, 0);
    
    cout<<"————————————————————"<<endl;
    cout<<"——欢迎使用事务管理系统——"<<endl;
    cout<<"——————— 列表 ————————"<<endl;
    /*
    for(int i=0;i<3;i++)
    {
        cout<<i+1<<"."<<List[i].Name<<endl;
    }
     */
    Get_Catalogue_From_DataBase(0);
    cout<<"--------------------"<<endl;
    cout<<"请输入你要查看的事务分类编号(0 退出|-1 添加事项):";
    cin>>tmp;
    
    if (tmp>=1&&tmp<=total)
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

void DisplayEventList(int* Command,int* MenuIndex)
{
    int tmp;
    int total=Get_Total_Number_From_DataBase(1, MenuIndex[0]);
    
    cout<<"————————————————————"<<endl;
   
    Get_Catalogue_From_DataBase(MenuIndex[0]);
    cout<<"--------------------"<<endl;
    Get_EventList_From_DataBase(MenuIndex[0]);
    cout<<"--------------------"<<endl;
    

    
    if(total!=0)
        cout<<"请输入你要查看的事项编号,"<<endl;
    cout<<"(0 后退|-1 添加事项):";
    
    cin>>tmp;
    
    if(tmp<=total&&tmp>=1)
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

void DisplayEvent(int* Command,int* MenuIndex)
{
    int tmp;
    cout<<"————————————————————"<<endl;

    Get_Event_From_DataBase(MenuIndex[0], MenuIndex[1]);
    
    cout<<"--------------------"<<endl;
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

void AddEvent(int* Command,int* MenuIndex)
{
    int tmp;

    //当没有选择添加到哪个分类时
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
   
    //incomplete:终止输入模块
    if(/* DISABLES CODE */ (1))
    {
        int total=Get_Total_Number_From_DataBase(1, MenuIndex[0]);
        
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
        
        //写入数据库
        Set_Event_To_DataBase(MenuIndex[0],total,type,title,detail,FormatTime(begin),FormatTime(end));
        
        *Command=3;
        MenuIndex[1]=total+1;
        
        cout<<"————————————————————"<<endl;
        cout<<"添加成功!"<<endl;
    }
    
}

void DeleteEvent(int* Command,int* MenuIndex)
{
    int total=Get_Total_Number_From_DataBase(1, MenuIndex[1]);
    
    //cout<<"确定删除？(1 确定|0 取消)？";
    cout<<"————————————————————"<<endl;
    if(MenuIndex[1]>=1&&MenuIndex[1]<=total)
    {
        Delete_Event_From_Database(MenuIndex[0], MenuIndex[1]);
        cout<<"删除成功"<<endl;
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

void UpdateEvent(int* Command,int* MenuIndex)
{
    //incomplete:终止输入模块
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
        
        Update_Event_From_Database(MenuIndex[0], MenuIndex[1], type, title, detail,FormatTime(begin), FormatTime(end));
        
        cout<<"————————————————————"<<endl;
        cout<<"修改成功!"<<endl;
        
        *Command=3;
    }
    
}
