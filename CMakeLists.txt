###############################################################################
# file: CMakeLists.txt
# author: Brendan Berg
# MIT License
# Copyright (c) 2020 Brendan Berg
#
# This is a makefile for the demo project for the multichannel_led library. It
# utilizes a custom AVR toolchain on GitHub by the user mkleemann. The file
# can be obtained here:
#   https://github.com/mkleemann/cmake-avr
# The generic-gcc-avr.cmake file can be added as a toolchain file in the CLion
# preferences or as a command line argument with the command:
#   cmake -DCMAKE_BUILD_TYPE=Release
#         -DCMAKE_TOOLCHAIN_FILE=/path/to/generic-gcc-avr.cmake
###############################################################################

cmake_minimum_required(VERSION 3.16)

# TODO: create custom toolchain file as git submodule


###############################################################################
# upload options
###############################################################################
set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER arduino)
set(AVR_UPLOADTOOL_PORT /dev/cu.usbmodem1413401)
set(AVR_UPLOADTOOL_BAUDRATE 115200)


###############################################################################
# mcu options
###############################################################################
set(AVR_MCU atmega328p)
set(AVR_H_FUSE 0xff)
set(AVR_L_FUSE 0xde)
set(AVR_E_FUSE 0x05)
set(MCU_SPEED "16000000UL")


###############################################################################
# output chosen options
###############################################################################
# TODO: outsource to custom toolchain file
message(STATUS "Current uploadtool is: ${AVR_UPLOADTOOL}")
message(STATUS "Current programmer is: ${AVR_PROGRAMMER}")
message(STATUS "Current upload port is: ${AVR_UPLOADTOOL_PORT}")
message(STATUS "Current uploadtool options are: ${AVR_UPLOADTOOL_OPTIONS}")
message(STATUS "Current MCU is set to: ${AVR_MCU}")
message(STATUS "Current high fuse is set to: ${AVR_H_FUSE}")
message(STATUS "Current low fuse is set to: ${AVR_L_FUSE}")
message(STATUS "Current extended fuse is set to: ${AVR_E_FUSE}")
message(STATUS "Current clock frequency is set to: ${MCU_SPEED}")


###############################################################################
# include locations
###############################################################################
# TODO: outsource to custom toolchain file
set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_FIND_ROOT_PATH}/include")
set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_FIND_ROOT_PATH}/lib")


###############################################################################
# build system
###############################################################################
# TODO: outsource to custom toolchain file
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_C_FLAGS_RELEASE "-Os")
    set(CMAKE_CXX_FLAGS_RELEASE "-Os")
endif(CMAKE_BUILD_TYPE MATCHES Release)

add_definitions("-DF_CPU=${MCU_SPEED}")
add_definitions("-fpack-struct")
add_definitions("-fshort-enums")
add_definitions("-Wall")
add_definitions("-Werror")
add_definitions("-pedantic")
add_definitions("-pedantic-errors")
add_definitions("-funsigned-char")
add_definitions("-funsigned-bitfields")
add_definitions("-ffunction-sections")
add_definitions("-c")
add_definitions("-std=gnu99")


###############################################################################
# project files
###############################################################################
project(DemoMultichannelLED C)

add_avr_executable(DemoMultichannelLED main.c)

include_directories(multichannel_led)
add_subdirectory(multichannel_led)
avr_target_link_libraries(DemoMultichannelLED multichannel_led)

avr_generate_fixed_targets()
