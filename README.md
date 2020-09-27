# Tensorflow Lite Micro

## 1、介绍

本软件包是针对RT-Thread内核的Tensorflow Lite嵌入式推理框架Tensorflow Lite Micro软件包. 通过软件包可以实现在嵌入式系统中实现基于Tensorflow Lite框架训练的深度学习模型的端测部署任务.

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
        [*] Tensorflow Lite Micro package
```

然后让 RT-Thread 的包管理器自动更新，或者使用 `pkgs --update` 命令更新包到 BSP 中。

## 3、使用 Tensorflow Lite Micro

在打开 Tensorflow Lite Micro package 后，当进行 bsp 编译时，它会被加入到 bsp 工程中进行编译。

* 完整的 API 手册可以访问这个[链接](docs/api.md)
* 更多文档位于 [`/docs`](/docs) 下，使用前 **务必查看**

## 4、注意事项

- 本软件包在运行时会占用16KB内存, 同时自带的语音识别案例在运行时总共占用22KB内存
- 本软件包目前只在树莓派4平台上实现成功运行, 其他平台还有待测试.

## 5、联系方式 & 感谢

* 维护：QingChuanWS
* 主页：https://github.com/QingChuanWS
