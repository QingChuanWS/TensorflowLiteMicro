# Tensorflow Lite Micro API

## 目前软件包支持的算子(共52个算子)

每个算子定义的详细内容可以参见[`all_ops_resolver.cc`](../tensorflow/lite/micro/all_ops_resolver.cc)

| 算子名称              		| 描述  |
|:-------------------------------------|--------|
|`ABS()`  | 元素级取绝对值 |
| `ADD()` | 元素级求和 |
| `ARG_MAX()` | 获得最大值对应的下标 |
| `ARG_MIN()` | 获得最小值对应的下标 |
| `AVERAGE_POOL_2D()` | 二维均值池化算子 |
| `CEIL()` | 对tensor向上取整 |
| `CONCATENATION()` | tensor按第一维进行聚合 |
| `CONV_2D()` | 二维卷积 |
| `COS()` | cos(x)函数 |
| `DEPTHWISE_CONV_2D()` | 深度可分离二维卷积 |
| `DEQUANTIZE()` | 反量化算子 |
| `EQUAL()` | 量化算子 |
| `FLOOR()` | 对tensor向下取整 |
| `FULLY_CONNECTED()` | 全连接层 |
| `GREATER()` |  |
| `GREATER_EQUAL()` |  |
| `L2_NORMALIZATION()` | 应用欧式距离进行归一化 |
| `LESS()` |  |
| `LESS_EQUAL()` |  |
| `LOG()` | 对tensor进行log运算 |
| `AND()` | 元素级与 |
| `NOT()` | 元素级取反 |
| `OR()` | 元素级或 |
| `LOGISTIC()` | 对tensor引用逻辑回归函数 |
| `MAX_POOL_2D()` | 最大值池化 |
| `MAXIMUM()` | 对两个输入tensor求较大的tensor |
| `MEAN()` |  |
| `MINIMUM()` |  |
| `MUL()` |  |
| `NEG()` |  |
| `NOT_EQUAL()` |  |
| `PACK()` |  |
| `PAD()` |  |
| `PADV2()` |  |
| `PRELU()` |  |
| `QUANTIZE()` |  |
| `RELU()` | RELU激活函数 |
| `RELU6()` |  |
| `RESHAPE()` | 对tensor维度进行重新设置 |
| `RESIZE_NEAREST_NEIGHBOR()` |  |
| `ROUND()` |  |
| `RSQRT()` |  |
| `SIN()` | sin(x)函数 |
| `SOFTMAX()` |  |
| `SPLIT()` |  |
| `SQRT()` |  |
| `SQUARE()` |  |
| `STRIDED_SLICE()` |  |
| `SVDF()` |  |
| `TANH()` | tan(x)函数 |
| `UNPACK()` |  |
