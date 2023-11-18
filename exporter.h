//
// Created by he on 23-11-18.
//

#ifndef EXPORTER_H
#define EXPORTER_H

#include "parser_dh.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

// 布局结果导出器类
//class Exporter {
//public:
    // 构造函数，指定输出文件名
    //explicit Exporter(const std::string &filename);

    // 导出布局结果
    //void exportLayout(const LayoutDatabase &layoutDB, const std::vector<int> &layout);

//private:
    //std::ofstream output;  // 输出文件流

//};
#include "database.h"

class Exporter {
    public:

    explicit Exporter(OutputDataBase &data_base,

                      std::string filename):
                      database_(data_base),
                      filename_(std::move(filename)){}
         void output(){

        return output_();
    };

private:

    OutputDataBase &database_;
    std::string filename_;
    std::string output_path_;

    void output_();

};


#endif  // EXPORTER_H
