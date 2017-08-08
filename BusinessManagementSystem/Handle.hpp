//
//  Handle.hpp
//  BusinessManagementSystem
//
//  Created by Lean on 2017/7/24.
//  Copyright © 2017年 Lean. All rights reserved.
//

#ifndef Handle_hpp
#define Handle_hpp

#include <stdio.h>


void Start();

void DisplayCatalogueList(int* Command,int* MenuIndex);

void DisplayEventList(int* Command,int* MenuIndex);

void DisplayEvent(int* Command,int* MenuIndex);

void AddEvent(int* Command,int* MenuIndex);

void DeleteEvent(int* Command,int* MenuIndex);

void UpdateEvent(int* Command,int* MenuIndex);


#endif /* Handle_hpp */
