# Tensorflow Lite Micro 软件包

中文版 | [English Version](./README_en.md)

## 1、介绍

Tensorflow Lite Micro软件包(简称TFLu)是针对RT-Thread实时操作系统移植的嵌入式推理框架, 主要解决在资源, 功耗, 性能等受限环境下的嵌入式系统中, 基于Tensorflow Lite框架实现深度学习模型的端测部署问题

### 1.1 目录结构

| 名称 | 说明 |
| ---- | :--- |
| docs  | 文档目录 |
| examples | Tensorflow Lite Micro示例 |
| fixedpoint | Google Fixedpoint定点量化库 |
| flatbuffers | Google Flatbuffer模型解释库 |
| ruy | Google Ruy矩阵计算加速库 |
| tflite | Google Tensorflow Lite Micro推理框架 |

### 1.2 许可证

Tensorflow Lite Micro package 遵循 LGPLv2.1 许可，详见 `LICENSE` 文件。

### 1.3 依赖

RT-Thread 3.0+

## 2、如何打开 Tensorflow Lite Micro

使用 Tensorflow Lite Micro package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite Micro: a lightweight deep learning end-test inference framework for RT-Thread operating system.
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 Tensorflow Lite Micro

在成功下载 Tensorflow Lite Micro package 之后:

- 首先通过RT-Thread 的 env工具中 menuconfig 进行功能配置, 其中在menuconfig中的配置选项为:

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite Micro: a lightweight deep learning end-test inference framework for RT-Thread operating system.
            Version(latest) --->
            Select Offical Example(Enable Tensorflow Lite Micro aduio example) --->
            Select Tensorflow Lite Operations Type (Using Tensorflow Lite reference operations)  --->
```

其中, Select Offical Example中有两个选项:

```
(X) Enable Tensorflow Lite Micro audio example
( ) No Tensorflow Lite Micro example
```

注 : audio example是执行官方携带的语音示例, No example则是不集成example文件, 只使用Tensorflow Lite Micro标准框架. 

- 如果选择了语音示例, 则需要从example文件夹下拷贝audio_main.cc文件到工程的Application目录中, 然后即可以编译, 烧录/下载查看效果了

Select Tensorflow Lite Operations Type中有两个选项:

```
(X) Using Tensorflow Lite reference operations
( ) Using Tensorflow Lite CMSIS NN operations 
```

注 : reference operation是应用TFLMicro的通用算子(算子与平台隔离,可移植性好),  CMSIS NN operations是应用针对ARM平台进行特定优化的算子(主要针对Cortex M4内核以上的平台, 对于特定平台有特定加速). **有关注意事项请参照第四部分!!**

- 本软件包目前在树莓派4平台上实现成功运行, 其他平台还有待测试. 欢迎大家在其他平台(例如STM32)上移植本软件包, 来实现自己的idea. 对于手边有有树莓派4的同学可以移步到仓库链接: https://github.com/QingChuanWS/raspi4-tfliteMicro

- Tensorflow Lite Micro整个框架功能较为复杂, API较多, 请先参考[introduction.md](introduction.md), 然后通过[user-guide.md](user-guide.md)来学习基本的部署流程, 在此基础之上再考虑自定义开发的问题.

*  API 手册可以访问这个[链接](docs/api.md), 其中提供了目前支持算子的情况
* 更多文档位于 [`/docs`](/docs) 下，使用前 **务必查看**

## 4、注意事项 

- 目前的CMSIS NN算子优化主要针对ARM Cortex M4以上的内核进行计算优化, 所以不推荐M4以下的MCU应用本选项. 同时基于CMSIS NN的算子优化目前只针对M系列的MCU, 对于其他其他内核型号的MCU暂不支持优化
- 目前CMSIS NN算子还处在测试阶段, 可能存在问题.
- 以集成语音demo的Tensorflow Lite Micro框架为例, **本软件包在编译之后大约会占用690KB Flash空间, 28K RAM空间** (平台数据 : 树莓派4 Cortex A72内核 64位, gcc-arm-8.3交叉工具链), 所以暂时不推荐硬件资源过于紧凑的MCU使用本软件包.(未来会针对资源紧凑型MCU进行定制优化)
- 本软件包在运行时会占用16KB RAM空间, 同时自带的语音识别案例在运行时总共占用22KB内存, **请注意通过menuconfig来修改主函数栈的大小以及内存管理算法 !**

## 5、联系方式 & 感谢

* 维护：QingChuanWS
* 主页：https://github.com/QingChuanWS
* 欢迎各位RT-Threader试用本软件包并提出自己的建议, 我会认真听取并不断改进本软件包. 你的支持就是我最大的动力
