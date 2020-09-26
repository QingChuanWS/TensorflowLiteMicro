# Tensorflow Lite Micro

## 1、介绍

本软件包是针对RT-Thread内核的Tensorflow Lite嵌入式推理框架Tensorflow Lite Micro, 搭载了较为全面的Tensorflow Lite算子, 可以在性能较低的板子上实现基于Tensorflow Lite框架训练的模型的端测部署任务.

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

使用 hello package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite package
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 Tensorflow Lite Micro

在打开 hello package 后，当进行 bsp 编译时，它会被加入到 bsp 工程中进行编译。

* 完整的 API 手册可以访问这个[链接](docs/api.md)
* 更多文档位于 [`/docs`](/docs) 下，使用前 **务必查看**

## 4、注意事项

- 本工程需要较大的内存(1G以上)以及线程栈(主线程要求16k以上)支持, 目前只在树莓派4平台(内存4G)上测试运行通过, 其他平台还有待测试.

## 5、联系方式 & 感谢

* 维护：QingChuanWS
* 主页：https://github.com/QingChuanWS
