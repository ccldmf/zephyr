## 介绍
zephyr是一个微型内核，主要是用于资源受限的系统，比如简单的嵌入式环境，传感器以及智能手表等场景。目前它已经支援了很多开发板，包含了目前常用的架构开发板，比如：Arm,Intel x86, RISC-V等。

## 特点
* **Extensive suite of Kernel services[广泛的服务]**
	* 多线程服务：基于优先级，非抢占式的和具有可选时间片切换的轮询抢占式线程
	* 中断服务：编译时注册中断处理函数
	* 内存分配服务：动态分配和释放固定大小或者可变大小的内存块服务
	* 线程间同步服务：二元信号量，计数信号量和互斥信号量
	* 线程间数据传递服务：消息队列，增强消息队列和字节流
	* 电源管理服务：无滴答CPU空转和高级空转

* **Highly configurable / Modular for flexibility[高度可配置]**
	允许应用程序在需要时添加相应的功能。

* **Multiple Scheduling Algorithms[多个调度算法]**

* **Memory Protection**

* **Compile-time resource definition[编译时定义资源]**
	系统资源在编译时定义，以减少代码量。

## 源码结构
下面是zephyr的文件结构：

![zephyrFileStructure](https://github.com/ccldmf/zephyr/blob/main/Picture/zephyrFileStructure.png)
* arch
	架构相关的内核源文件，私有API以及平台相关代码
* boards
	board相关的代码和配置文件
* doc
	开发文档，材料机相关工具
* drivers
	设备驱动文件
* include
	所有(不包含lib目录)共有API的头文件
* kernel
	微内核代码，以及架构无关的微内核代码
* lib
	代码库，包括C库
* misc
	杂项
* net
	网络相关代码，包括蓝牙协议栈，网络协议栈
* samples
	示例应用程序
* tests
	各个功能模块的测试代码
* scripts
	编译，测试应用程序的脚本文件

## Ubuntu开发环境搭建
zephyr开发支持Windows,Linux, Mac三种开发环境，其中Linux推荐的是Ubuntu 18.04 LTS之上的版本，但是经过本人实际测试，在Ubuntu 18.04 LTS上搭建开发环境时，总是会遇到一些依赖库无法安装的问题，因此，建议选用较高一点的版本进行环境搭建，比如Ubuntu 20.04 LTS。环境搭建参看官网[Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html#getting-started-guide)

## STM32F103C8T6测试
开发环境搭建好了，便在STM32F103C8T6上试试跑马灯。zephyr已经又支持了该开发板，在boards/arm/stm32_mini_dev文件夹下有stm32_min_dev_black，这里有区分black和blue两种开发板，根据需要选择命令，需要输入对应的命令即可,命令如下：
```
west build -b stm32_min_dev_black samples/basic/blinky
```
build成功后，将设备连接值PC，这里使用的是ST-LINK V2连接，然后烧写可执行文件到设备：

```
west flash
```
开发板LED成功点亮。
