cmake_minimum_required(VERSION 3.16)
project(DemoMultichannelLED C)

set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER arduino)
set(AVR_UPLOADTOOL_PORT /dev/cu.usbmodem1413401)

set(AVR_MCU atmega328p)
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0xc3)
set(MCU_SPEED "16000000UL")

add_avr_executable(DemoMultichannelLED main.c)
