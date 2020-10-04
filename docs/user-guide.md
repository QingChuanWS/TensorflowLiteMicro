# Tensorflow Lite Micro使用说明

`Tensorflow Lite Micro` 是` TensorFlow Lite `的实验性端口，专门用于在微控制器和其他只有几千字节内存的设备上运行机器学习模型。

它不需要操作系统支持、任何标准 C/C++ 库或动态内存分配。核心运行时在 Arm Cortex M3 上占用 16 KB 的内存，并且具有足够多的运算符来运行语音关键字检测模型，总共占用 22 KB 的内存。

# 建立与转换模型

由于嵌入式设备具有有限的 RAM 和存储空间，因此限制了深度学习模型的规模。此外，本TensorFlow Lite Micro 目前只支持有限的一部分运算，因此并非所有的模型结构都是可行的。

本部分将介绍由 TensorFlow 模型转换为可在嵌入式设备中上运行的过程。本部分也概述了可支持的运算，并对设计与训练一个模型以使其符合内存限制给出了一些指导。

## 模型转换

将一个已训练好的 TensorFlow 模型转换为可以在嵌入式设备中运行的Tensorflow Lite模型可以使用 [TensorFlow Lite 转换器 Python API](ModelConvert.md) 。它能够将模型转换成 [`FlatBuffer`](https://google.github.io/flatbuffers/) 格式，减小模型规模，并修改模型以使用 TensorFlow Lite 支持的运算。

### 量化

为了获得尽可能小的模型规模，你应该考虑使用[训练后量化](https://tensorflow.google.cn/lite/performance/post_training_quantization)。它会降低你模型中数字的精度，从而减小模型规模。不过，这种操作可能会导致模型推理准确性的下降，对于小规模模型来说尤为如此, 所有我们需要在量化前后分析模型的准确性变换以确保这种损失在可接受范围内。

以下这段 Python 代码片段展示了如何使用预训练量化进行模型转换：

```python
import tensorflow as tf
converter = tf.lite.TFLiteConverter.from_saved_model(saved_model_dir)
converter.optimizations = [tf.lite.Optimize.OPTIMIZE_FOR_SIZE]
tflite_quant_model = converter.convert()
open("converted_model.tflite", "wb").write(tflite_quant_model)
```

### 转换为一个 C 数组

许多微控制器平台没有本地文件系统的支持。从程序中使用一个模型最简单的方式是将其以一个 C 数组的形式并将其编译进你的程序。

以下的 unix 命令会生成一个以 `char` 数组形式包含 TensorFlow Lite 模型的 C 源文件：

```bash
xxd -i converted_model.tflite > model_data.cc
```

其输出类似如下：

```c
unsigned char converted_model_tflite[] = {
  0x18, 0x00, 0x00, 0x00, 0x54, 0x46, 0x4c, 0x33, 0x00, 0x00, 0x0e, 0x00,
  // <Lines omitted>
};
unsigned int converted_model_tflite_len = 18200;
```

在生成了此文件之后，你可以将它包含到你的程序。在嵌入式平台上，我们需要将该数组声明为 `const` 类型以获得更好的内存效率。

一个如何在你的程序中包含及使用模型的例子，请见微型语音示例中的 [`model.h`](tensorflow/lite/micro/examples/micro_speech/micro_features/model.h) 。

## 模型结构与训练

在设计一个面向微控制器的模型时，考虑模型的规模、工作负载，以及用到的运算是非常重要的。

### 模型规模

一个模型必须在二进制和运行时方面都足够小，以使其可以和你程序的其他部分一起符合你目标设备的内存限制。

为了创建一个更小的模型，你可以在你的结构里使用更少和更小的层。然而，小规模的模型更易面临欠拟合问题。这意味着对于许多问题，尝试并使用符合内存限制的尽可能大规模的模型是有意义的。但是，使用更大规模的模型也会导致处理器工作负载的增加。

注：在一个 Cortex M3 上，面向微控制器的 TensorFlow Lite 的核心运行时占 16 KB。

### 工作负载

工作负载受到模型规模与复杂度的影响。大规模、复杂的模型可能会导致更高的占空比，即导致你所用设备处理器的工作时间增长、空闲时间缩短。视你的应用，这种情况所带来的电力消耗与热量输出的增加可能会成为一个问题。

### 运算支持

面向微控制器的 TensorFlow Lite 目前仅支持有限的部分 TensorFlow 运算，这影响了可以运行的模型结构。我们正致力于在参考实现和针对特定结构的优化方面扩展运算支持。

已支持的运算可以在文件 [`all_ops_resolver.cc`](../tensorflow/lite/micro/all_ops_resolver.cc) 中看到。

## 运行推断

以下部分将介绍软件包自带语音历程中的 [main_functions.cc](../tensorflow/lite/micro/examples/micro_speech/main_functions.cc) 文件并解释了它如何使用用于微控制器的 Tensorflow Lite 来运行推断。

### 包含项

要使用库，必须包含以下头文件：

```C++
#include "tensorflow/lite/micro/kernels/micro_ops.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"
```

- [`micro_ops.h`](../tensorflow/lite/micro/kernels/micro_ops.h) 提供给解释器（interpreter）用于运行模型的操作。
- [`micro_error_reporter.h`](../tensorflow/lite/micro/micro_error_reporter.h) 输出调试信息。
- [`micro_interpreter.h`](../tensorflow/lite/micro/micro_interpreter.h) 包含处理和运行模型的代码。
- [`schema_generated.h`](../tensorflow/lite/schema/schema_generated.h) 包含 TensorFlow Lite [`FlatBuffer`](https://google.github.io/flatbuffers/) 模型文件格式的模式。
- [`version.h`](../tensorflow/lite/version.h) 提供 Tensorflow Lite 架构的版本信息。

示例还包括其他一些文件。以下这些是最重要的：

```C++
#include "tensorflow/lite/micro/examples/micro_speech/feature_provider.h"
#include "tensorflow/lite/micro/examples/micro_speech/micro_features/micro_model_settings.h"
#include "tensorflow/lite/micro/examples/micro_speech/micro_features/model.h"
```

- [`feature_provider.h`](../tensorflow/lite/micro/examples/micro_speech/feature_provider.h) 包含从音频流中提取要输入到模型中的特征的代码。
- [`model.h`](../tensorflow/lite/micro/examples/micro_speech/micro_features/model.h) 包含存储为 `char` 数组的模型。阅读 [“构建与转换模型”](ModelConvert.md)来了解如何将 Tensorflow Lite 模型转换为该格式。
- [`micro_model_settings.h`](../tensorflow/lite/micro/examples/micro_speech/micro_features/micro_model_settings.h) 定义与模型相关的各种常量。

### 设置日志记录

要设置日志记录，需要使用一个指向 `tflite::MicroErrorReporter` 实例的指针来创建一个 `tflite::ErrorReporter` 指针：

```C++
tflite::MicroErrorReporter micro_error_reporter;
tflite::ErrorReporter* error_reporter = &micro_error_reporter;
```

该变量被传递到解释器（interpreter）中，解释器允许它写日志。由于微控制器通常具有多种日志记录机制，`tflite::MicroErrorReporter` 的实现是为您的特定设备所定制的。

### 加载模型

在以下代码中，模型是从一个 `char` 数组中实例化的，`g_tiny_conv_micro_features_model_data` （要了解其是如何构建的，请参见[“构建与转换模型”](ModelConvert.md)）。 随后我们检查模型来确保其架构版本与我们使用的版本所兼容：

```C++
const tflite::Model* model =
    ::tflite::GetModel(g_tiny_conv_micro_features_model_data);
if (model->version() != TFLITE_SCHEMA_VERSION) {
  error_reporter->Report(
      "Model provided is schema version %d not equal "
      "to supported version %d.\n",
      model->version(), TFLITE_SCHEMA_VERSION);
  return 1;
}
```

### 实例化操作解析器

解释器（interpreter）需要一个 [`micro_ops`](../tensorflow/lite/micro/kernels/micro_ops.h) 实例来访问 Tensorflow 操作。可以扩展此类以向您的项目添加自定义操作：

```C++
tflite::ops::micro::micro_op_resolver resolver;
```

### 分配内存

我们需要预先为输入、输出以及中间数组分配一定的内存。该预分配的内存是一个大小为 `tensor_arena_size` 的 `uint8_t` 数组，它被传递给 `tflite::SimpleTensorAllocator` 实例：

```C++
const int tensor_arena_size = 10 * 1024;
uint8_t tensor_arena[tensor_arena_size];
tflite::SimpleTensorAllocator tensor_allocator(tensor_arena,
                                               tensor_arena_size);
```

注意：所需内存大小取决于您使用的模型，可能需要通过实验来确定。

### 实例化解释器（Interpreter）

我们创建一个 `tflite::MicroInterpreter` 实例，传递给之前创建的变量：

```C++
tflite::MicroInterpreter interpreter(model, resolver, &tensor_allocator,
                                     error_reporter);
```

### 验证输入维度

`MicroInterpreter` 实例可以通过调用 `.input(0)` 为我们提供一个指向模型输入张量的指针，其中 `0` 代表第一个（也是唯一一个）输入张量。我们检查这个张量以确认它的维度与类型是我们所期望的：

```C++
TfLiteTensor* model_input = interpreter.input(0);
if ((model_input->dims->size != 4) || (model_input->dims->data[0] != 1) ||
    (model_input->dims->data[1] != kFeatureSliceCount) ||
    (model_input->dims->data[2] != kFeatureSliceSize) ||
    (model_input->type != kTfLiteUInt8)) {
  error_reporter->Report("Bad input tensor parameters in model");
  return 1;
}
```

在这个代码段中，变量 `kFeatureSliceCount` 和 `kFeatureSliceSize` 与输入的属性相关，它们定义在 [`micro_model_settings.h`](../tensorflow/lite/micro/examples/micro_speech/micro_features/micro_model_settings.h) 中。枚举值 `kTfLiteUInt8` 是对 Tensorflow Lite 某一数据类型的引用，它定义在 [`common.h`](../tenserflow/lite/c/common.h) 中。

### 生成特征

我们输入到模型中的数据必须由微控制器的音频输入生成。[`feature_provider.h`](../tensorflow/lite/micro/examples/micro_speech/feature_provider.h) 中定义的 `FeatureProvider` 类捕获音频并将其转换为一组将被传入模型的特征集合。当该类被实例化时，我们用之前获取的 `TfLiteTensor` 来传入一个指向输入数组的指针。`FeatureProvider` 使用它来填充将传递给模型的输入数据：

```C++
  FeatureProvider feature_provider(kFeatureElementCount,
                                   model_input->data.uint8);
```

以下代码使 `FeatureProvider` 从最近一秒的音频生成一组特征并填充进输入张量：

```C++
TfLiteStatus feature_status = feature_provider.PopulateFeatureData(
    error_reporter, previous_time, current_time, &how_many_new_slices);
```

在此例子中，特征生成和推断是在一个循环中发生的，因此设备能够不断地捕捉和处理新的音频。

当在编写自己的程序时，您可能会以其它的方式生成特征，但您总需要在运行模型之前就用数据填充输入张量。

### 运行模型

要运行模型，我们可以在 `tflite::MicroInterpreter` 实例上调用 `Invoke()`：

```C++
TfLiteStatus invoke_status = interpreter.Invoke();
if (invoke_status != kTfLiteOk) {
  error_reporter->Report("Invoke failed");
  return 1;
}
```

我们可以检查返回值 `TfLiteStatus` 以确定运行是否成功。在 [`common.h`](../tenserflow/lite/c/common.h) 中定义的 `TfLiteStatus` 的可能值有 `kTfLiteOk` 和 `kTfLiteError`。

### 获取输出

模型的输出张量可以通过在 `tflite::MicroIntepreter` 上调用 `output(0)` 获得，其中 `0` 代表第一个（也是唯一一个）输出张量。

在示例中，输出是一个数组，表示输入属于不同类别（“是”（yes）、“否”（no）、“未知”（unknown）以及“静默”（silence））的概率。由于它们是按照集合顺序排列的，我们可以使用简单的逻辑来确定概率最高的类别：

```C++
    TfLiteTensor* output = interpreter.output(0);
    uint8_t top_category_score = 0;
    int top_category_index;
    for (int category_index = 0; category_index < kCategoryCount;
         ++category_index) {
      const uint8_t category_score = output->data.uint8[category_index];
      if (category_score > top_category_score) {
        top_category_score = category_score;
        top_category_index = category_index;
      }
    }
```

在示例其他部分中，使用了一个更加复杂的算法来平滑多帧的识别结果。该部分在 [recognize_commands.h](../tensorflow/lite/micro/examples/micro_speech/recognize_commands.h) 中有所定义。在处理任何连续的数据流时，也可以使用相同的技术来提高可靠性。