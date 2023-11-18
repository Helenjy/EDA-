#include "parser_dh.h"
#include "placement.h"
#include "exporter.h"
#include "parser.h"
#include "database.h"
#include <iostream>


int main() {
   // LayoutDatabase layoutDB;
    // 解析布局数据库文件
    //layoutDB.parseFile("layout_database.txt");

    //std::string exportFilename = "layout_result.txt";

    // 求解布局并导出结果
    //solveLayout(layoutDB, exportFilename);

    //return 0;

    auto *input_database = new InputDataBase();
    auto *output_database = new OutputDataBase();

    auto *parser = new Parser(&: *input_database, filename:"../case1.txt"); parser->parse();

    delete parser;

    place(input_data_base: input_database, output data_base:output_database);

    auto *exporter = new Exporter(&:* output_database, filename:"../output.txt");
    exporter->output();

    delete exporter;

    delete input_database;
    delete output_database;

    std::cout <<"Hello World!"<< std::endl;
}
