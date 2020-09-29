# TensorFlow Lite Micro软件包

TensorFlow Lite Micro 是 TensorFlow Lite 的实验性端口，专门用于在嵌入式设备和其他只有几千字节内存的设备上运行机器学习模型。

它不需要操作系统支持、任何标准 C/C++ 库或动态内存分配。核心运行时在 Arm Cortex M3 上占用 16 KB 的内存，并且具有足够多的运算符来运行语音关键字检测模型，运行时总共占用 22 KB 的内存。

一些示例应用演示了如何使用微控制器执行唤醒字词检测，根据加速度计数据进行手势分类(待移植)，以及使用相机数据进行图像分类(待移植)等任务。

## 使用入门

如需试用示例应用并了解如何使用该 API，请参阅[用户指导](user-guide.md)。

## 为什么要在嵌入式设备中使用机器学习模型

嵌入式设备通常是小型低功耗计算设备，往往嵌入到需要执行基本计算的硬件（包括家用电器和物联网设备）中。微控制芯片的年生产量高达数十亿。

微控制器芯片通常经过优化以实现低能耗和小尺寸，但处理能力、内存和存储空间会受到影响。同时一些微控制器是为了优化机器学习任务的性能而被设计出来的。

通过在微控制器上运行机器学习推断，开发者可以在不依靠网络连接的情况下向各种硬件设备添加 AI 功能，而依赖网络的AI功能通常会受到带宽和功率限制，并且会导致长时间延迟。由于数据无需离开设备，因此在设备端运行推断也有助于保护隐私。

## 开发者工作流程

为了将 TensorFlow 模型部署到微控制器，您需要遵循以下流程：

1. **创建或获取 TensorFlow 模型**

   该模型必须足够小，在转换后适合目标设备，并且只能使用[支持的操作](https://tensorflow.google.cn/lite/microcontrollers/build_convert#operation_support)。如果您想使用目前不受支持的操作，可以提供自己的实现。

2. **将模型转换为 TensorFlow Lite FlatBuffer**

   您可以使用 [TensorFlow Lite 转换器](https://tensorflow.google.cn/lite/microcontrollers/build_convert#model_conversion)将模型转换为标准 TensorFlow Lite 格式。您可能希望输出量化模型，因为它们更小而且执行效率更高。

3. **将 FlatBuffer 转换为 C 字节数组**

   模型保存在只读程序内存中，并以简单 C 文件的形式提供。您可以使用标准工具[将 FlatBuffer 转换为 C 数组](https://tensorflow.google.cn/lite/microcontrollers/build_convert#convert_to_a_c_array)。

4. **集成适用于微控制器的 TensorFlow Lite C++ 库**

   编写微控制器代码以收集数据、使用 [C++ 库](https://tensorflow.google.cn/lite/microcontrollers/library)执行推断，并利用结果。

5. **部署到您的设备**

   构建程序并将其部署到您的设备。

## 限制

适用于微控制器的 TensorFlow Lite 专为满足微控制器开发的特定限制条件而设计。如果您使用的是更强大的设备（例如 Raspberry Pi 等嵌入式 Linux 设备），那么标准 TensorFlow Lite 框架可能更易于集成。

应考虑以下限制条件：

- 支持的 TensorFlow 操作[有限](https://tensorflow.google.cn/lite/microcontrollers/build_convert#operation_support)
- 支持的设备有限
- 需要手动内存管理的低阶 C++ API
- 不支持训练