#This code is partially inspired from https://github.com/agnath18K/acpi_ec/blob/main/install.sh

#source _names.sh #for some reason this is not working idk why, im just gonna use it inside the code 
#these variables holds the names
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
#echo message
echo "starting uninstallation of $MODULE_NAME now . . ."
#check if the module is loaded 

echo "checking module is loaded.."
#by running this type of lsmod we can get accurate result based on our module name
if lsmod | grep -q "^$MODULE_NAME" ; then
    echo "module is loaded , unloading . . ."
    modprobe -rq $MODULE_NAME
    echo "Module unloaded"
else 
    echo "module is not loaded"
fi

#remove the autoconfiguraton from the module.conf folder
echo "Removing auto configuration .. "
rm -f "$MODULE_LOAD_DIR/$MODULE_NAME.conf"

echo "removing module"
#calling the uinstall target inside make
make uninstall

echo "updating dependancies"
depmod -a

echo "Uninstallation completed successfully!"