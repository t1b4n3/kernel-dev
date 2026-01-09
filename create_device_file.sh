#!/bin/sh



# get device number : grep <kernel module> /proc/devices


device_file="$1"
device_number="$2"


mknod /dev/$device_file c $device_number 0