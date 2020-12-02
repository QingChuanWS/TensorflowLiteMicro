# Tensorflow Lite Micro Software Package

[Chinese Version](./README.md) | English Version

## 1. Introduction

The Tensorflow Lite Micro software package (TFLu) is an embedded inference framework for RT-Thread real-time operating system transplantation. It mainly solves the problem of deployment based on the Tensorflow Lite framework in embedded systems with resource constraints such as resources, power consumption, and performance.

Platforms currently planned to be optimized:

- [x] Raspberry Pi 4 (Cortex A72 core, 64-bit, gcc-arm-8.3 cross tool chain): RAM 28K, Flash 690K Repository link: https://github.com/QingChuanWS/raspi4-tfliteMicro

- [x] ART-Pi (STM32H750, 32-bit, gcc-arm-none-eabi-9-2019): RAM 25K, Flash 542K

- [ ] Nucleo-STM32L496(STM32L496, 32-bit, gcc-arm-none-eabi-9-2019)

- [ ] Kendryte K210 (K210, 64-bit, riscv architecture)

### 1.1 Directory structure
| Name        | Description                                                  |
| ----------- | :----------------------------------------------------------- |
| docs        | Document                                                     |
| examples    | Tensorflow Lite Micro offical audio demo                     |
| tensorflow  | Tensorflow Lite Micro library                                |
| third_party | Third party libraries on which tensorflow Lite micro depends |


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

After successfully downloading Tensorflow Lite Micro package:

- First, perform configuration through menuconfig in RT-Thread's env tool, where the configuration options in menuconfig are: 

```
RT-Thread online packages
    miscellaneous packages --->
        [*] Tensorflow Lite Micro: a lightweight deep learning end-test inference framework for RT-Thread operating system.
            Version(latest) --->
            Select Offical Example(Enable Tensorflow Lite Micro aduio example) --->
            Select Tensorflow Lite Operations Type (Using Tensorflow Lite reference operations)  --->
```

Among them, there are two options in Select Offical Example:

```
(X) Enable Tensorflow Lite Micro audio example
( ) No Tensorflow Lite Micro example
```

Note: The audio example is an audio example carried by the official implementation. No example does not integrate the example file and only uses the Tensorflow Lite Micro standard framework.

- If you choose the audio example, please copy the audio_main.cc file in the example folder to the Application directory of the project, then compile, burn/download to see the effect.

There are two options in Select Tensorflow Lite Operations Type:

```
(X) Using Tensorflow Lite reference operations
( ) Using Tensorflow Lite CMSIS NN operations 
```

Note: Reference operation is a general-purpose operator using TFLMicro (the operator is isolated from the platform, and has good portability), CMSIS NN operations is the application of the CMSIS library to accelerate the op of the platform with the ARM core. **For precautions, please refer to fourth part!!**

- The whole framework of Tensorflow Lite Micro has more complicated functions and various APIs. Please refer to [introduction.md](introduction.md) in the document first, and then use [user-guide.md](user-guide.md) to understand the basics Deep learning end-test deployment process. After having the above foundation, you can try to develop your own end-test deployment tasks.

* The API manual can visit this [link](docs/api.md), which provides the current support for operators
* More documents are located under [`/docs`](/docs), **Be sure to check** before use

## 4. Matters needing attention

- About `Using Tensorflow Lite CMSIS NN operations` option:
  - At present, CMSIS's optimization of operators is mainly for the calculation and optimization of cores above ARM Cortex M4 (which are equipped with DSP, FPU and other hardware acceleration components). It is not recommended to apply this option to MCUs below M4.
  - Currently, the operator optimization of CMSIS only supports M series MCUs, ARM A series, R series does not recommend this option.
  - At present, the CMSIS NN operator is still in the testing stage, and there may be problems.
- This software package occupies 16KB RAM space at runtime, and the built-in speech recognition case occupies a total of 22KB memory at runtime. **Please pay attention to modify the size of the main function stack and the memory management algorithm through menuconfig!**



## 5. Contact & Thanks

* Maintenance: QingChuanWS
* Homepage: https://github.com/QingChuanWS
* Welcome to RT-Threader to try this package and make your own suggestions. I will listen carefully and continue to improve this package. Your support is my biggest motivation
