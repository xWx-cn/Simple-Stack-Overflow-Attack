# Simple-Stack-Overflow-Attack
## Hardwawre 
硬件环境：主机intel core i5芯片，NVIDA 4050 GPU，16GB内存；
         基于主机的硬件搭建了ubuntu虚拟机环境：
         4096MB内存；
         2处理器；

## Software
VirtualBox 虚拟机平台；ubuntu(64 bit)linux系统内置的gcc编译器、gdp调试工具。

## Basic implement
1’sudo apt-get install gcc-multilib，支持交叉编译cross-compiling，可以在64位处理器上处理32位程序
2’sudo sysctl -w kernel.randomize_va_space=0，代表关闭进程空间地址随机化功能
3’通过命令行参数关闭编译器器的一些保护工作
-fno-stack-protector：禁用栈保护（Canary）。
-z execstack：允许栈可执行（避免段错误）。
-no-pie：关闭地址随机化（Position Independent Executable）
final:
gcc -fno-stack-protector -z execstack -no-pie -o program code.c
