#!/bin/bash

#variable name holder dont want thr $ sign
MODULE_NAME="usbDriver"
MODULE_PATH="/lib/modules/$(uname -r)/kernel/drivers/acpi"
MODULE_LOAD_DIR="/etc/modules-load.d"

export MODULE_NAME
export MODULE_PATH
export MODULE_LOAD_DIR