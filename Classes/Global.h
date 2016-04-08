//
//  Global.h
//  albumDemo
//
//  Created by liuhui on 16/4/8.
//
//

#ifndef __albumDemo__Global__
#define __albumDemo__Global__

#include <vector>
#include <string>

class Global{
public:
    static std::vector<std::string> g_vector;
    static void cleanVector();
};

#endif /* defined(__albumDemo__Global__) */
