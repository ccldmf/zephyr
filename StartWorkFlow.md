## [构建流程介绍](https://docs.zephyrproject.org/latest/guides/build/index.html#)
zephyr构建工程的流程分为2个主要阶段：配置阶段和编译阶段。
* 配置阶段
	配置阶段由cmake驱动完成，通过cmake和python脚本处理dts,conf/Kconfig文件，cmake处理控制编译构建的makefile或者ninja文件，整个流程图如下：

![ConfigurationOverview](https://github.com/ccldmf/zephyr/blob/main/Picture/ConfigurationOverview.png)

* 编译阶段
	编译阶段会使用make或者ninjia读取配置阶段产生的makefile或者ninjia文件，控制进行编译，最后生成可执行文件。编译阶段分为4个子阶段：预编译，首次编译链接，二次编译链接，生成可执行文件。

## 启动流程简介
* reset.S
	zephyr在STM32F103C8T6的启动，依旧是先执行汇编代码进行一些基础的系统配置，然后跳转到C语言的main函数。这里	是从arch/arm/core/aarch32/cortex_m/reset.S 汇编文件开始的。主要执行以下几件事情：
	* 使处理器处于特权模式，并且MSP(main stack pointer)要只向SRAM的有效区域
	* 锁定除了CPU产生的NMI和硬件中断的任何中断，NMI中断已经在中断向量表里，此时引导程序不应该产生硬件中断
	* 使用PSP(process stack pointer)代替MSP
	* 跳转到z_arm_prep_c(),该函数将完成运行C之前的系统设置

![reset](https://github.com/ccldmf/zephyr/blob/main/Picture/reset.png)

* prep_c.c
	跳转到arch/arm/core/aarch32/prep_c.c中的z_arm_prep_c()函数，同样是执行底层的初始化工作，初始化C运行环境。主要是初始化.bss,拷贝.data等，最终执行z_cstart()

![prep](https://github.com/ccldmf/zephyr/blob/main/Picture/prep.png)
* z_cstart
	在kernel/init.c中的z_cstart()主要是用来初始化内核，到这里便和board无关了。执行 _SYS_INIT_LEVEL_PRE_KERNEL_1 与 _SYS_INIT_LEVEL_PRE_KERNEL_2 级别的初始化工作，然后初始化调度器，启动main线程(多线程模式下)或者跳转到bg_thread_main(不启用多线程)。

![cstart](https://github.com/ccldmf/zephyr/blob/main/Picture/cstart.png)
* bg_thread_main
	bg_thread_main将执行_SYS_INIT_LEVEL_POST_KERNEL 与 _SYS_INIT_LEVEL_APPLICATION 级别的初始化工作，然后跳转到 main()，这时调度器和内核服务均可以使用。

![main](https://github.com/ccldmf/zephyr/blob/main/Picture/main.png)

至此，整个系统已经完全运行起来。
