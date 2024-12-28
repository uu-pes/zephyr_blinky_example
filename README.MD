# Zephyr Blinky Example on Raspberry Pi Pico 

This is an example application illustrating the use of the **Zephyr RTOS** on the Raspberry Pi Pico board for the course **1DT106 Programming Embedded Systems** at Uppsala University.
The application is based on the [official Blinky example](https://github.com/zephyrproject-rtos/zephyr/tree/main/samples/basic/blinky) for Zephyr.

## Introduction 

A typical Zephyr application has 3 parts: 

- CMakeLists.txt 
- src/main.c 
- prj.conf 

In the CMakeLists.txt file we instruct the build system on how to construct our application.
It is similar to what you have already seen when building applications with the Pico C/C++ SDK. 

In prj.conf we can define different configuration variables, which determine which parts of the Zephyr operating system will be available to us. 

Our main application code goes into standard .c files, usually in their own subdirectory. 

## Device tree 

Since we are using the Maker Pi Pico board, which does not have dedicated board support yet, we must define the board layout ourself in a **device tree overlay**.
For more information on the device tree you can consult the [official devicetree standard](https://www.devicetree.org) or have a look at the [Zephyr documentation](https://docs.zephyrproject.org/latest/build/dts/index.html) detailing how the device tree is used for configuring Zephyr applications.

For this simple application we only need to add a simple LED node into the device tree.


## Building 

We assume you have `west` and Zephyr installed, which can be done following the [Zephyr getting started tutorial](https://docs.zephyrproject.org/latest/develop/getting_started/index.html).
To build the application you can issue the following command on a terminal: 

```bash 
west build 
```

In case you get an error saying that `build` is not one of the available commands, you might miss some environment variables. You can always load those into the current session in the following way: 

```bash 
source ZEPHYR_PROJECT_DIR/zephyr/zephyr-env.sh 
``` 

where `ZEPHYR_PROJECT_DIR` is the directory of where you installed the Zephyr operating system.
Once successful, building will create a `build` folder where the application binary is in `build/zephyr/zephyr.uf2`.

## Loading and running

Loading the application onto the device can be done by connecting to the device via USB with Bootsel pressed, and then running:

```bash
picotool load build/zephyr/zephyr.uf2 
```

Press the run button!

## Some things to try/explore

**Second task.** Define a second task which flashes LED at GP1.
This will require updating the overlay.

**No alias.** Update the application so that it refers to the LED node without using aliases.
You might check the [node identifier section](https://docs.zephyrproject.org/latest/build/dts/api-usage.html#node-identifiers) on the Zephyr website.

**Full DTS.** We only have provided an overlay.
This overlay and other other DTSes, including the one for RP20240 uC (found in `${ZEPHYR_BASE}/boards/raspberrypi/rpi_pico/rpi_pico.dts`), are combined into one big DTS in `build/zephyr/zephyr.dts`.
Are you able to find the nodes from the overlay in this big DTS?