cmake_minimum_required(VERSION 3.16)
project(DemoMultichannelLED C)

set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER arduino)
set(AVR_UPLOADTOOL_PORT /dev/cu.usbmodem1413401)

set(AVR_MCU atmega328p)
set(AVR_H_FUSE 0xff)
set(AVR_L_FUSE 0xde)
set(AVR_L_FUSE 0x05)
set(MCU_SPEED "16000000UL")

message(STATUS "Current uploadtool is: ${AVR_UPLOADTOOL}")
message(STATUS "Current programmer is: ${AVR_PROGRAMMER}")
message(STATUS "Current upload port is: ${AVR_UPLOADTOOL_PORT}")
message(STATUS "Current uploadtool options are: ${AVR_UPLOADTOOL_OPTIONS}")
message(STATUS "Current MCU is set to: ${AVR_MCU}")
message(STATUS "Current high fuse is set to: ${AVR_H_FUSE}")
message(STATUS "Current low fuse is set to: ${AVR_L_FUSE}")
message(STATUS "Current extended fuse is set to: ${AVR_E_FUSE}")
message(STATUS "Current clock frequency is set to: ${MCU_SPEED}")

add_avr_executable(DemoMultichannelLED main.c)
