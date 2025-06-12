source _names.sh
MODULE_NAME="usbDriver"
MODULE_PATH="/lib/modules/$(uname -r)/kernel/drivers/acpi"
MODULE_LOAD_DIR="/etc/modules-load.d"
#set -e means evac as soon as possible upon fail
set -e
#checking for sudo permission if we rn with sudo EUID will be 0 .
if [[ "$EUID" != 0 ]]; then           #this is tough spaces are very crazy over here
    echo " run as root to continue"
    exit 1
fi

echo "starting installation of $MODULE_NAME now . . ."

echo "starting build..."
#clearng make files and cooking again
make clean && make

echo "updating module dependancies. . ."
depmod -a

#inserting the module using modprobe 
echo "Loading $MODULE_NAME  module now ..."
modprobe $MODULE_NAME


#adding the auto load configuration inside the modules drivers folder structure
echo "adding module autoconfiguration"
echo "$MODULE_NAME" > "$MODULE_LOAD_DIR/$MODULE_NAME.conf"

echo "Installation completed successfully!"
echo "Module will be loaded automatically on next boot."





