//
// Created by he on 23-11-18.
//

#ifndef LAYOUT_SOLVER_H
#define LAYOUT_SOLVER_H

#include "parser_dh.h"
#include <vector>

// 计算线长
int calculateBusLength(const LayoutDatabase& layoutDB, const std::vector<int>& layout);

// 穷举布局
void exhaustiveLayout(const LayoutDatabase& layoutDB, std::vector<int>& currentLayout, std::vector<int>& bestLayout,
                      int currentIndex, int& bestBusLength);

// 布局求解入口函数
void solveLayout(const LayoutDatabase& layoutDB);

#endif  // LAYOUT_SOLVER_H
