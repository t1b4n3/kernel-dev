#!/bin/sh

device_file="$1"
device_number="$2"


mknod /dev/$device_file c $device_number 0