cmake_minimum_required(VERSION 3.13.1)

set(BOARD rpi_pico) 

find_package(Zephyr) 

project(blinky) 

FILE(GLOB SRC_FILES "src/*c") 
target_sources(app PRIVATE ${SRC_FILES})
