//
// Created by he on 23-11-18.
//

#include "placement.h"
#include "parser_dh.h"
#include <vector>
#include <string>
#include <algorithm>

// 计算总线长度
int calculateBusLength(const LayoutDatabase& layoutDB, const std::vector<int>& layout) {
    int busLength = 0;
    for (const auto &net: layoutDB.nets) {
        int minX = layoutDB.numCols;
        int maxX = 0;
        int minY = layoutDB.numRows;
        int maxY = 0;
        for (const auto &pin: net.pins) {
            int moduleIndex = std::stoi(pin.substr(1)) - 1;
            int row = layout[moduleIndex] / layoutDB.numCols;
            int col = layout[moduleIndex] % layoutDB.numCols;
            minX = std::min(minX, col);
            maxX = std::max(maxX, col);
            minY = std::min(minY, row);
            maxY = std::max(maxY, row);
        }
        busLength += (maxX - minX) + (maxY - minY);
    }
    return busLength;
};

    void exhaustiveLayout(const LayoutDatabase &layoutDB, std::vector<int> &currentLayout, std::vector<int> &bestLayout,
                          int currentIndex, int &bestBusLength) {
        if (currentIndex == layoutDB.modules.size()) {
            int busLength = calculateBusLength(layoutDB, currentLayout);
            if (busLength < bestBusLength) {
                bestBusLength = busLength;
                bestLayout = currentLayout;
            }
            return;
        }

        for (int i = 0; i < layoutDB.numRows * layoutDB.numCols; i++) {
            currentLayout[currentIndex] = i;
            exhaustiveLayout(layoutDB, currentLayout, bestLayout, currentIndex + 1, bestBusLength);
        }
    };

