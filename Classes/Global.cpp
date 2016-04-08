//
//  Global.cpp
//  albumDemo
//
//  Created by liuhui on 16/4/8.
//
//

#include "Global.h"

std::vector<std::string> Global::g_vector;

void Global::cleanVector(){
    g_vector.clear();
    std::vector<std::string>().swap(g_vector);
}
