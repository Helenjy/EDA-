//
// Created by he on 23-11-18.
//

#include "parser.h"
#include "parser_dh.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "database.h"

Parser::Parser() {
    numRows = 0;
    numCols = 0;
    numInstances = 0;
    numNets = 0;
}

void Parser::(const std::string &filename, LayoutDatabase database)  {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 " << filename << std::endl;
        return;
    }

    std::string line;
    std::stringstream ss;
    std::string keyword;

    while (std::getline(file, line)) {
        ss.clear();
        ss.str(line);
        ss >> keyword;

        if (keyword == "DieSize") {
            ss >> numRows >> numCols;
        } else if (keyword == "NumInstances") {
            ss >> numInstances;
        } else if (keyword == "Inst") {
            Instance instance;
            ss >> instance.name;
            instances.push_back(instance);
        } else if (keyword == "NumNets") {
            ss >> numNets;
        } else if (keyword == "Net") {
            Net net;
            ss >> net.name;
            int numPins;
            ss >> numPins;
            for (int i = 0; i < numPins; ++i) {
                std::string pin;
                ss >> pin;
                net.pins.push_back(pin);
            }
            nets.push_back(net);
        }
    }

    file.close();
}

void Parser::printData() {
    std::cout << "DieSize " << numRows << " " << numCols << std::endl;
    std::cout << "NumInstances " << numInstances << std::endl;
    for (const auto& instance : instances) {
        std::cout << "Inst " << instance.name << std::endl;
    }
    std::cout << "NumNets " << numNets << std::endl;
    for (const auto& net : nets) {
        std::cout << "Net " << net.name << " " << net.pins.size() << std::endl;
        for (const auto& pin : net.pins) {
            std::cout << "Pin " << pin << std::endl;
        }
    }
}
