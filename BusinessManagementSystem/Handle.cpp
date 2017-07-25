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
        //*Cmd='c';
        Index[1]=tmp;
        cout<<"该功能尚未完成"<<endl;
    }
    else if(tmp==-1)
    {
        //在该列表下添加事项

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
