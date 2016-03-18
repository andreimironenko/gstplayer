#!/bin/bash

script_path=$(dirname $0)
script=$(basename $0)

printf "%s\n" "script_path=$script_path"
source ${script_path}/localenv.conf

printf "%s\n" "Starting remove.sh script"

printf "%s\n" "Setting up network configuration in the u-boot"
fw_setenv kernel-ip "dhcp"
fw_setenv uboot-ip  "dhcp"
fw_setenv ipaddr 
fw_setenv gatewayip 
fw_setenv netmask 
fw_setenv serverip 

printf "%s\n" "The remove.sh script has completed"
