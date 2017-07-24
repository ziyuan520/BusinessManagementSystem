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
    
    char cmd = 'a';
    int index=0;
    
    while(cmd!='q')
    {
        switch (cmd)
        {
            case 'a':DisplayCatalogueList(List,&cmd,&index);break;
            case'b':DisplayEventList(List,&cmd,&index);break;
            case'c':;break;
        }
    }
    
}

void DisplayCatalogueList(CatalogueData* List,char* cmd,int* index)
{
    int tmp;
    cout<<"——欢迎使用事务管理系统——"<<endl;
    cout<<"——————— 列表 ————————"<<endl;
    PrintCatalogueList(List, 3);
    cout<<"————————————————————"<<endl;
    cout<<"请输入你要查看的事务表编号(0退出):";
    cin>>tmp;
    if (tmp>=1&&tmp<=3)
    {
        *cmd='b';
        *index=tmp;
    }
    else if(tmp==0)
        *cmd='q';
    else
    {
        cout<<"输入有误"<<endl;
        *index=0;
        //*cmd='a';
        //待修改：重置输入流
    }
    
}

void DisplayEventList(CatalogueData* List,char* cmd,int* index)//未完成
{
    int tmp;
    cout<<"————————————————————"<<endl;
    cout<<"<"<<List->Name<<">"<<endl;
    PrintEventList(&List[*index-1]);
    
    if(List[*index-1].Total!=0)
        cout<<"请输入你要查看的事项编号,\n";
    cout<<"输入-1添加事项(0退回):";
    
    cin>>tmp;
    if(tmp==0)
    {
        
    }
    if(tmp<=List[*index-1].Total&&tmp>=1)
    {
        *cmd='c';
        *index=tmp;
    }
}
