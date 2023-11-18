//
// Created by he on 23-11-18.
//

#include "exporter.h"
#include "database.h"
#include "placement.h"
#include <vector>

void Exporter::output_() {
    // 获取布局结果
    OutputDataBase::LayoutDatabase layout = outputData_.get_layout();

    // 输出每个模块的位置
    for (const auto& module : layout.modules) {
        std::string moduleName = module.name;
        // 假设 positions 是保存每个模块位置的属性
        int row = module.position.row;
        int col = module.position.col;

        std::cout << moduleName << " " << row << " " << col << " # 单元" << moduleName << "的位置为(" << row << ", " << col << ")" << std::endl;
    }
}
