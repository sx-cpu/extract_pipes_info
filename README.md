# Pipe Extractor VSCode Project

## 简介
这是一个基于 C++ 和 nlohmann/json 的 JSON 管道信息提取工具。  
它会读取 JSON 格式的管道数据，输出 CSV 格式的管道段信息，字段包括：  
ID, StartNode, EndNode, DeltaX, DeltaY, DeltaZ, Diameter, WallThickness, InsulationThickness, ElasticModulus, PoissonRatio, Density。

## 使用方法
1. 将你的 JSON 文件命名为 `Default.txt`，放在项目根目录。  
2. 在 VSCode 中打开本项目。  
3. 使用 VSCode 任务（Ctrl+Shift+B）编译程序。  
4. 运行调试或在终端运行 `./extract_pipe` 即可看到 CSV 输出。  
5. 你可以用重定向将结果保存到 CSV 文件：  
   ```bash
   ./extract_pipe > result.csv
   ```

## 缺点
1. 依赖于 nlohmann/json 库，可能不符合要求。
2. fst文件没法直接读取，可能是二进制文件，这里手动转换为jsonw文件或txt文件。
3. ID 信息可能需要手动处理，因为在 fst/JSON 中没有直接的 ID 字段。

## 依赖
- C++11
- `json.hpp` (nlohmann/json 单头文件，已包含)

## VSCode 配置
- 编译任务: g++ 编译器  
- 调试配置: 运行生成的可执行文件  

