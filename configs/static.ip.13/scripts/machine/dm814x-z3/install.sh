#!/bin/bash

script_path=$(dirname $0)
script=$(basename $0)

printf "%s\n" "script_path=$script_path"
source ${script_path}/localenv.conf

printf "%s\n" "Starting install.sh script"

printf "%s\n" "Setting up the network configuration in u-boot"
fw_setenv kernel-ip "static"
fw_setenv uboot-ip  "static"
fw_setenv ipaddr "192.168.9.13"
fw_setenv gatewayip "192.168.9.2"
fw_setenv netmask "255.255.255.0"
fw_setenv serverip "192.168.9.2"

printf "%s\n" "The install.sh has completed"
