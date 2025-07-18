这个文件是一个管道应力分析系统的结构化输入或输出数据，可能用于像 CAESAR II、AutoPIPE、Rohr2 等软件。

以下是主要字段的说明：

## 🔧 顶层结构
```json

{
  "auxiliary": {...},
  "boundary_condition": {...},
  "check_code": null,
  "geometry": {...},
  "global_overview": {...},
  "pipe_system": {...}
}
```

### 1. auxiliary（辅助数据）
#### - allowables

每项代表一种材料的许用应力数据。

```json
"allowable_sy_st": 屈服强度与许用应力的比值
"allowed_cycles_max": 允许的最大循环次数
"sy`: 屈服强度
"sy_at_temp`: 不同温度下的屈服强度数组
"uts_ambient`: 室温下极限抗拉强度
"uts_at_temp`: 各温度下极限抗拉强度数组
"cyclic_factors`: 周期加载因子（疲劳分析）
"cold_allowable` / `hot_allowables`: 冷/热态的许用应力
```

#### - bends
管道弯头的属性，每个对象表示一个弯头。

```json

"radius": 弯头半径
"angle_pos1": 主平面弯曲角度（弧度）
"node_pos1`: 起始节点
"node_pos2`: 结束节点
"fitting_thickness`: 厚度
"flexibility_factor`: 柔度因子
```

#### - rigids


刚性元件，如泵体、法兰等：

```json

"second": 材料ID或类型
"weight": 元件重量（单位未指定）
```

#### - reducers
异径管组件：

```json
"second_diameter": 小端直径
"second_thickness": 小端厚度
```

#### - siftees
SIF (Stress Intensification Factor) 接口，对分支或焊缝进行强度修正：

```json
"siftee1` / `siftee2`: 两个端的 SIF 参数，比如：
"in_plane_sif": 面内应力集中系数
"out_plane_sif": 面外应力集中系数
"torsion_sif": 扭转集中系数
"node": 节点编号
```

#### - miscel_1
杂项参数，包含：

1. execution_options: 
分析控制参数
```json
"ambient_temp": 环境温度
"bourdon_effects": 是否考虑布尔登效应
"thermal_bowing": 是否考虑热弯曲
"liberal_stress": 是否使用宽松应力评判
```
2. hanger_defaults: 
吊架默认设置
```json
"cold_load_calc": 是否根据冷态计算载荷
"max_travel": 最大行程（单位 mm）
"load_variation": 允许载荷变动范围（%）
"short_spring": 是否允许使用短行程弹簧吊架
```
3. hangers
单个吊架对象，常用于热位移补偿：
```json
"node": 吊架节点
"hot_load` / `cold_load` / `operating_load": 热/冷/操作载荷
"stiffness": 吊架刚度
"load_variation": 载荷波动范围
```

### 2. boundary_condition
边界条件，包括：

#### - restraints
支撑和约束条件
```json
"node": 被约束的节点编号
"type`: 支撑类型（如固定、滑动、弹性等）
"stiffness": 刚度（约束刚度）
"direction_x/y/z": 支撑方向向量
"friction`: 摩擦系数
```

### 3. geometry
```json
"geo_components": 结构几何组件（为空）
"count": 几何元素计数（大数字，疑似未使用）
```

### 4. global_overview
整体工程参数汇总：
```json
"num_bends": 弯头数量
"num_elements": 管段数量
"num_reducers`: 异径管数量
"vertical_axis`: 竖直方向轴编号（4代表Z轴）
"points`: 定义管网起点位置的坐标
```
### 5. pipe_system
包含所有管段信息：

#### - pipes -> elements
每一段管道的信息：
```json
"from_node` / `to_node`: 起止节点
"delta_x/y/z`: 管道段的位移向量
"diameter`: 管道直径（mm）
"wall_thickness`: 壁厚
"fluid_density`: 流体密度
"insulation_thickness`: 保温层厚度
"pressures`: 操作压力数组
"thermal_coeffs`: 热膨胀系数
"test_pressure`: 试验压力
```
## 🚧 总结
这个文件记录了一个完整的管道应力模型，包括：

- 材料强度标准

- 管道结构布置

- 辅助元件（弯头、异径管、刚性件）

- 支吊架配置

- 边界支撑与节点条件

- 操作工况（温度、压力、密度）

