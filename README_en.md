# Tensorflow Lite Micro Software Package

[Chinese Version](./README.md) | English Version

## 1. Introduction

This software package is the Tensorflow Lite embedded inference framework Tensorflow Lite Micro software package for the RT-Thread ecosystem . Through this software package, the end deployment task of the deep learning model trained based on the Tensorflow Lite framework can be realized in the embedded system.

### 1.1 Directory structure
| Name        | Description                                              |
| ----------- | :------------------------------------------------ |
| docs        | Document                                          |
| examples    | Tensorflow Lite Micro offical voice demo |
| fixedpoint  | Fixed-point quantization library required by Tensorflow Lite Micro library           |
| flatbuffers | Model interpretation library flatbuffer required by Tensorflow Lite Micro library |
| ruy         | Matrix acceleration library required by Tensorflow Lite Micro library ruy        |
| tensorflow  | Tensorflow Lite Micro library                       |


### 1.2 License

Tensorflow Lite Micro package complies with the LGPLv2.1 license, please refer to the `LICENSE` file for details.

### 1.3 Dependency

RT-Thread 3.0+

## 2. How to open Tensorflow Lite Micro

To use Tensorflow Lite Micro package, you need to select it in the package manager of RT-Thread. The specific path is as follows:

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite Micro: a lightweight deep learning end-test inference framework for RT-Thread operating system.
```

Then let the RT-Thread package manager automatically update, or use the `pkgs --update` command to update the package to the BSP.

## 3. Use Tensorflow Lite Micro

After successfully downloading the Tensorflow Lite Micro package:

- Change the package folder name of `TensorflowLiteMicro_xxx` (where `xxx` is the package version number) downloaded under the `packages` file to `TensorflowLiteMicro` (that is, remove the version number, so as not to affect compilation)
- Function configuration through menuconfig, the configuration options in menuconfig are:

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite Micro: a lightweight deep learning end-test inference framework for RT-Thread operating system.
            Version(latest) --->
            Select Offical Example(Enable Tensorflow Lite Micro aduio example) --->
```

Among them, there are two options in Select Offical Example:

```
(X) Enable Tensorflow Lite Micro audio example
( ) No Tensorflow Lite Micro example
```

Among them, audio example is to implement the official audio demo, No example does not integrate the example file, only uses the Tensorflow Lite Micro standard framework. **For the precautions of the menucofing option, please refer to the 4. Precautions section**

- The whole framework of Tensorflow Lite Micro has more complicated functions and many APIs. Please refer to [introduction.md](introduction.md) first, and then use [user-guide.md](user-guide.md) to learn the basic deployment process, on this basis, consider the issue of custom development.

* The API manual can visit this [link](docs/api.md), which provides the current support for operators
* More documents are located under [`/docs`](/docs), **Be sure to check** before use

## 4. Matters needing attention

- If the audio example option is selected in the menuconfig, the software package will use the self main function, and the user needs to manually delete all main functions except `packages/TensorflowLiteMicro/example/audio_main.cc`

- If No example is selected, the system does not have main function, users can design the main function according to their own needs to call the Tensorflow Lite Micro framework

- **This software package will occupy approximately 480KB Flash space and 92KB RAM space after compilation**, so it is not recommended for MCU systems with few hardware resources to use this software package
- This software package occupies 16KB RAM space when running, and the built-in voice recognition case occupies a total of 22KB memory when running. **You need to modify the size of the main function stack and the memory management algorithm through menuconfig! **

- This software package currently only runs successfully on the Raspberry Pi 4 platform, other platforms have yet to be tested. Raspberry Pi 4 porting  repositories link: https://github.com/QingChuanWS/raspi4-tfliteMicro

## 5. Contact & Thanks

* Maintenance: QingChuanWS
* Homepage: https://github.com/QingChuanWS
