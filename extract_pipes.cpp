#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "json.hpp"  // 需要 https://github.com/nlohmann/json/releases 下载 json.hpp

using json = nlohmann::json;

void extract_pipe_info(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ 无法打开文件: " << filename << std::endl;
        return;
    }

    json j;
    file >> j;

    const auto& pipes = j["pipe_system"]["pipes"];

    // int Num_Pipes = 0;
    // for (const auto& pipe : pipes){const auto& elements = pipe["elements"];
    //     for (const auto& elem : elements) {Num_Pipes++;}}
    // std::cout << "Num_Pipes: " << Num_Pipes << std::endl;  
    

    int id = 0;

    std::cout << "ID,StartNode,EndNode,DeltaX,DeltaY,DeltaZ,Diameter,WallThickness,InsulationThickness,ElasticModulus,PoissonRatio,Density\n";

    for (const auto& pipe : pipes) {
        const auto& elements = pipe["elements"];
        for (const auto& elem : elements) {
            int from_node = elem.value("from_node", -1);
            int to_node = elem.value("to_node", -1);
            double dx = elem.value("delta_x", 0.0);
            double dy = elem.value("delta_y", 0.0);
            double dz = elem.value("delta_z", 0.0);
            double diameter = elem.value("diameter", 0.0);
            double wall_thickness = elem.value("wall_thickness", 0.0);
            double insulation_thickness = elem.value("insulation_thickness", 0.0);
            double elastic_modulus = elem.value("elastic_modulus_cold", 0.0);
            double poisson_ratio = elem.value("poisson_ratio", 0.0);

            // 读取 fluid_density 数组中的第一个值
            double density = 0.0;
            if (elem.contains("fluid_density") && elem["fluid_density"].is_array() && !elem["fluid_density"].empty()) {
                density = elem["fluid_density"][0].get<double>();
            }

            std::cout << id++ << ","
                      << from_node << "," << to_node << ","
                      << dx << "," << dy << "," << dz << ","
                      << diameter << "," << wall_thickness << ","
                      << insulation_thickness << "," << elastic_modulus << ","
                      << poisson_ratio << "," << density << "\n";
        }
    }
}
