# Tensorflow Lite Micro 软件包

中文版 | [English Version](./README_en.md)

## 1、介绍

Tensorflow Lite Micro软件包(简称TFLu)是针对RT-Thread实时操作系统移植的嵌入式推理框架, 主要解决在资源, 功耗, 性能等资源受限的嵌入式系统中, 部署基于Tensorflow Lite框架实现深度学习模型任务

目前计划进行调优的平台 : 

- [x] 树莓派4 ( Cortex A72内核, 64位, gcc-arm-8.3交叉工具链 )  : RAM 28K, Flash 690K  仓库链接: https://github.com/QingChuanWS/raspi4-tfliteMicro

- [x] ART-Pi (STM32H750, 32位, gcc-arm-none-eabi-9-2019 ) : RAM 25K, Flash 542K

- [ ] Nucleo-STM32L496(STM32L496, 32位, gcc-arm-none-eabi-9-2019)

- [ ] Kendryte K210(K210, 64位, riscv架构)

### 1.1 目录结构

| 名称 | 说明 |
| ---- | :--- |
| docs  | 文档目录 |
| examples | Tensorflow Lite Micro示例 |
| third_party | Tensorflow Lite Micro依赖的第三方库 |
| tensorflow | Google Tensorflow Lite Micro推理框架 |

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

- 首先通过RT-Thread 的 env 工具中 menuconfig 进行功能配置, 其中在 menuconfig 中的配置选项为:

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite Micro: a lightweight deep learning end-test inference framework for RT-Thread operating system.
            Version(latest) --->
            Select Offical Example(Enable Tensorflow Lite Micro aduio example) --->
            Select Tensorflow Lite Operations Type (Using Tensorflow Lite reference operations)  --->
```

其中, Select Offical Example 中有两个选项:

```
(X) Enable Tensorflow Lite Micro audio example
( ) No Tensorflow Lite Micro example
```

注 : audio example 是执行官方携带的语音示例, No example 则是不集成 example 文件, 只使用 Tensorflow Lite Micro 标准框架. 

- 如果选择了语音示例, 请将example文件夹下的audio_main.cc文件拷贝到工程的Application目录中, 然后编译, 烧录/下载查看效果了

Select Tensorflow Lite Operations Type 中有两个选项:

```
(X) Using Tensorflow Lite reference operations
( ) Using Tensorflow Lite CMSIS NN operations 
```

注 : reference operation 是应用 TFLMicro 的通用算子(算子与平台隔离,可移植性好),  CMSIS NN operations 是应用CMSIS库对具有ARM内核的平台进行算子的加速. **有关注意事项请参照第四部分!!**

- Tensorflow Lite Micro整个框架功能较为复杂, 各类API比较多, 请先参考文档中[introduction.md](introduction.md), 然后通过 [user-guide.md](user-guide.md) 来了解基本的深度学习端测部署流程. 在有了以上基础之后, 就可以尝试开发自己端测部署任务了.

*  API 手册可以访问这个[链接](docs/api.md), 其中提供了目前支持算子的情况
* 更多文档位于 [`/docs`](/docs) 下，使用前 **务必查看**

## 4、注意事项 

- 关于`Using Tensorflow Lite CMSIS NN operations `选项:
  - 目前CMSIS对于算子的优化主要针对ARM Cortex M4以上的内核 ( 其搭载了DSP, FPU等硬件加速部件) 进行计算优化, 不推荐M4以下的MCU应用该选项. 
  - 目前CMSIS的算子优化目前只支持M系列的MCU, A系列, R系列不推荐应用该选项.
  - 目前CMSIS NN算子还处在测试阶段, 可能存在问题.
- 本软件包在运行时会占用16KB RAM空间, 同时自带的语音识别案例在运行时总共占用22KB内存, **请注意通过menuconfig来修改主函数栈的大小以及内存管理算法 !**

## 5、联系方式 & 感谢

* 维护：QingChuanWS
* 主页：https://github.com/QingChuanWS
* 欢迎各位RT-Threader试用本软件包并提出自己的建议, 我会认真听取并不断改进本软件包. 你的支持就是我最大的动力
