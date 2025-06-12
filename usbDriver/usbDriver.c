/**
 * Linux USB driver 
 */

#include<linux/init.h>
#include<linux/module.h>
#include<linux/usb.h>
#include<linux/kernel.h>
#include<linux/fs.h>
/*define vendor id and product id (find it by lsusb -v) this way make it more easy*/
#define USB_VENDOR 0x14cd
#define USB_PRODUCT 0x1212


static int usb_open (struct inode *inode, struct file *file){
    printk(KERN_INFO "USB : open fops called \n");
    return 0 ;
}
static int usb_close (struct inode *inode, struct file *file){
    printk(KERN_ALERT "USB  : File close fops called \n");
    return 0;
}
static ssize_t usb_read (struct file *file, char __user *userbuf, size_t len, loff_t *off){
    printk(KERN_INFO "USB : Read called \n");
    return 0;
}
static ssize_t usb_write(struct file *file, const char __user *userbuf, size_t len, loff_t *off){
    printk(KERN_INFO " USB : write called\n");
    return 0;
}

static struct file_operations fops={
    .owner      = THIS_MODULE,
    .open       = usb_open,
    .read       = usb_read,
    .write      = usb_write,
    .release    = usb_close   
};
/*this is the usb class driver struct there are things we need to add inside this structure used inside registering device*/
struct usb_class_driver usb_driver={
    .name           = "customusbDriver%d",
    .fops           = &fops,
    .minor_base     = 192
};
/**
 * @brief this function called as the probe function when we load our usb,inside we need to add the interface
 * and register the usb device , careful about the print statements kinda tricky
 * issue 1 : not registering the usb and getting minor number probably due to other drivers . working on it 
 * @param usb_interface structure , device id structure
 */
static int usb_dev_probe (struct usb_interface *intf,const struct usb_device_id *id)
{
    struct usb_host_interface* usb_interface_desc ;
    int ret ;
    usb_interface_desc = intf->cur_altsetting ;
    printk(KERN_INFO "USB : usb probed %d :(%04X:%04X)\n" , usb_interface_desc->desc.bInterfaceNumber , id->idVendor,id->idProduct);
    printk(KERN_INFO "USB : usb end points : %02x\n",usb_interface_desc->desc.bNumEndpoints);
    printk(KERN_INFO "USB : usb interface class : %02x\n",usb_interface_desc->desc.bInterfaceClass);

    ret = usb_register_dev(intf,&usb_driver);
    if(ret){
       printk(KERN_ERR "USB : Error with registering and getting minor number \n");
    } else {
        printk(KERN_DEBUG "USB : Registered and got minor number : %d \n",intf->minor);
    }
    return 0;
}
/**
 * @brief function called when the usb device is disconnected we just deregister here
 * @param usb_interface structure
 */
static void usb_dev_disconnect (struct usb_interface *intf){
    usb_deregister_dev(intf,&usb_driver);
    printk(KERN_INFO "USB : disconnected usb device \n");
}

static int usb_dev_resume (struct usb_interface *intf){
   return 0;
}

/**
 * @brief usb device id structure holds the id table like vendor is and product id of our usb device
 * so our kernal or code knows which device should use this driver
 */
static struct usb_device_id usb_dev_idtable[] ={
    {
    USB_DEVICE(USB_VENDOR,USB_PRODUCT)
    },
    {}
};

/**
 * @brief this structure holds usb_driver functions we need to add all the driver operations over here
 * this will be used in usb_register operation not usb_register_dev op
 */
static struct usb_driver usb_dev_driver ={
    .name = "adix usb driver",
    .probe = usb_dev_probe,
    .disconnect = usb_dev_disconnect,
    .id_table = usb_dev_idtable,
    .supports_autosuspend  = 1,
    .resume = usb_dev_resume
}; 

static int __init usb_init(void){
    printk(KERN_INFO "USB : initializing driver \n");
    usb_register(&usb_dev_driver);
    return 0;
}
static void __exit usb_exit(void){
    printk(KERN_INFO "USB : module is exiting\n");
    usb_deregister(&usb_dev_driver);
}


module_init(usb_init);
module_exit(usb_exit);
MODULE_DEVICE_TABLE(usb,usb_dev_idtable);
MODULE_AUTHOR("Adin N S <adinnavakumar22@gmail.com>");
MODULE_DESCRIPTION("Simple linux driver module");
MODULE_LICENSE("GPL");

