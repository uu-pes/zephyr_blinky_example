# Zephyr Blinky Example on Raspberry Pi Pico 

This is an example application illustrating the use of the **Zephyr RTOS** on the Raspberry Pi Pico board for the course **1DT106 Programming Embedded Systems** at Uppsala University. 

## Introduction 

A typical Zephyr application has 3 parts: 

- CMakeLists.txt 
- src/main.c 
- prj.conf 

In the CMakeLists.txt file we instruct the build system on how to construct our application. It is similar to what you have already seen during when building applications with the Pico C/C++ SDK. 

In prj.conf we can define different configuration variables, which determine which parts of the Zephyr operating system will be available to us. 

Our main application code goes into standard .c files, usually in their own subdirectory. 

## Device tree 

Since we are using the Maker Pi Pico board, which does not have dedicated board support yet, we must define the board layout ourself in a **device tree overlay**. For more information on the device tree you can consult the [official devicetree standard](https://www.devicetree.org) or have a look at the [Zephyr documatation](https://docs.zephyrproject.org/latest/build/dts/index.html) detailing how the device tree is used for configuring Zephyr applications. 

For this simple application we only need to add a simple LED node into the device tree.

## Building 

To build the application you can issue the following command on a terminal: 

```bash 
west build 
```

In case you get an error saying that `build` is not one of the availabel commands, you might miss some environment variables. You can always load those into the current session in the following way: 

```bash 
source ZEPHYR_PROJECT_DIR/zephyr/zephyr-env.sh 
``` 

where `ZEPHYR_PROJECT_DIR` is the directory of where you installed the Zephyr operating system. 
