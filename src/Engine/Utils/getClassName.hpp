// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by andrew on 15.01.19.
//

#ifndef PROJECTOR_GETCLASSNAME_HPP
#define PROJECTOR_GETCLASSNAME_HPP

#include <string>
#include "CONST_DEFINITIONS.hpp"
template <class T>
inline std::string getClassName()
{
    std::string tmp = typeid(T).name();
    us_int position = 0;
    for (us_int i = 0; i < tmp.length(); i++)
    {
        if (isdigit(tmp.at(i)))
        {
            position = i;
        }
    }
    tmp.erase(0, position + 1);
    return tmp;
}

#endif //PROJECTOR_GETCLASSNAME_HPP
