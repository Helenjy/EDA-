//
// Created by he on 23-11-18.



#ifndef PARSER_H
#define PARSER_H

 #include "database.h"
 #include <fstream>


class Parser{

public:

explicit Parser(InputDataBase &data_base, const std::string &filename):

filename_(filename),
file_(filename) {};


public:
    Parser();
    void parseFile(const std::string& filename);
    void printData();

void parse();

private:
int numRows;
int numCols;
int numInstances;
int numNets;



std::string filename_;
std::ifstream file_;
};

#endif
