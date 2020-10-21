# Tensorflow Lite Micro 软件包

中文版 | [English Version](./README_en.md)

## 1、介绍

本软件包是针对RT-Thread内核的Tensorflow Lite嵌入式推理框架Tensorflow Lite Micro软件包. 通过本软件包可以实现在嵌入式系统中实现基于Tensorflow Lite框架训练的深度学习模型的端测部署任务.

### 1.1 目录结构

| 名称 | 说明 |
| ---- | :--- |
| docs  | 文档目录 |
| examples | Tensorflow Lite Micro自带语音历程, 并给出一些说明 |
| fixedpoint | Tensorflow Lite Micro库需要的定点量化库 |
| flatbuffers | Tensorflow Lite Micro库需要的模型解释库flatbuffer |
| ruy | Tensorflow Lite Micro库需要的矩阵加速库ruy |
| tensorflow | Tensorflow Lite Micro主体库 |

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

- 将下载在`packages`文件下的`TensorflowLiteMicro_xxx`(其中`xxx`为软件包版本号)软件包文件夹名更改为`TensorflowLiteMicro`(即去除版本号, 以免影响编译)
- 通过menuconfig进行功能配置, 其中在menuconfig中的配置选项为:

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite Micro: a lightweight deep learning end-test inference framework for RT-Thread operating system.
            Version(latest) --->
            Select Offical Example(Enable Tensorflow Lite Micro aduio example) --->
```

其中, Select Offical Example中有两个个选项:

```
(X) Enable Tensorflow Lite Micro audio example
( ) No Tensorflow Lite Micro example
```

其中audio example是执行官方携带的语音demo, No example则是不集成example文件, 只使用Tensorflow Lite Micro标准框架. **关于menucofing选项的注意事项请参照 4. 注意事项部分**

- Tensorflow Lite Micro整个框架功能较为复杂, API较多, 请先参考[introduction.md](introduction.md), 然后通过[user-guide.md](user-guide.md)来学习基本的部署流程, 在此基础之上再考虑自定义开发的问题.

*  API 手册可以访问这个[链接](docs/api.md), 其中提供了目前支持算子的情况
* 更多文档位于 [`/docs`](/docs) 下，使用前 **务必查看**

## 4、注意事项

- 如果在menuconfig中选择了audio example选项时, 软件包自带了main函数, 用户需要手动删除除了`packages/TensorflowLiteMicro/example/audio_main.cc`以外的所有main函数
- 如果选择的是No example时, 系统没有main函数, 用户可以根据自身需要设计main函数来调用Tensorflow Lite Micro框架  
- **本软件包在编译之后大约会占用480KB Flash空间, 92KB RAM空间**, 所以不推荐硬件资源不多的MCU系统使用本软件包
- 本软件包在运行时会占用16KB RAM空间, 同时自带的语音识别案例在运行时总共占用22KB内存,  **需要通过menuconfig来修改主函数栈的大小以及内存管理算法 ! **
- 本软件包目前只在树莓派4平台上实现成功运行, 其他平台还有待测试. 欢迎大家在其他平台上移植软件包并提出issue. 树莓派4移植仓库链接: https://github.com/QingChuanWS/raspi4-tfliteMicro

## 5、联系方式 & 感谢

* 维护：QingChuanWS
* 主页：https://github.com/QingChuanWS
