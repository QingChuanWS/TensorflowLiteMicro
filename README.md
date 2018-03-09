# hello

RT-Thread上的演示用package。

## 介绍

这个是一个RT-Thread上的演示用package，用于演示一个package大致包括哪些东西，以及对应的一些模版文件。

### 目录结构

| 名称 | 说明 |
| ---- | ---- |
| doc | 文档目录 |
| example | 例子 |
| inc | 头文件目录 |
| src | 源代码目录 |

### 许可证

hello package遵循LGPLv2.1许可。

## 如何打开hello

使用hello package需要在RT-Thread的包管理器中选择它：

    RT-Thread online packages
        miscellaneous packages --->
            [*] A hello package

然后让RT-Thread的包管理器自动更新，或者使用`pkgs --update`命令更新包到BSP中。

## 使用hello

在打开hello package后，当进行bsp编译时，它会被加入到bsp工程中进行编译。

    [如果package需要做初始化，额外指出初始化步骤；或者指明对应导出的初始化宏]

* 完整的API手册可以访问这个[链接](doc/index.md)

## 注意事项

    [列出在使用这个package过程中需要注意的事项；列出可能出现的问题，以及解决办法]

## 联系方式 & 感谢

* 维护：Bernard Xiong
* 主页：N/A
