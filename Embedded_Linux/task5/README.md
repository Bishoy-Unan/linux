# SD_Card

- this step is done to work with Qemu only ( Virtual SD Card). 
- In this section it's required to have SD card with first partition to be FAT as pre configured in **U-boot Menuconfig** .
- In order to Emulate SD card to attached to Qemu following steps will be followed: (ONLY FOR NON PHYSICAL SD):

```bash
# Create a file with 1 GB filled with zeros
dd if=/dev/zero of=sd.img bs=1M count=1000
```

- at this step output file would be created at the current directory called "sd.img"

### Configure the Partition Table for the SD card

```bash
# for the VIRTUAL SD card
cfdisk sd.img
```

- at this step a configration menu would be opened and there is two options GPT and DOS, choose DOS.
- then configure the next table : 

| Partition Size | Partition Format | Bootable  |
| -------------- | ---------------- | --------- |
| `200 MB`       | `FAT 16`         | ***Yes*** |
| `300 MB`       | `Linux`          | ***No***  |

- don't forget to click **write** to save configrations.

### Loop Driver FOR Virtual usage ONLY

- To emulate the sd.img file as a sd card we need to attach it to **loop driver** to be as a **block storage**.

  ```bash
  # attach the sd.img to be treated as block storage
  sudo losetup -f --show --partscan sd.img
  
  # Running the upper command will show you
  # Which loop device the sd.img is connected
  # take it and assign it like down bellow command
  
  # Assign the Block device as global variable to be treated as MACRO
  export DISK=/dev/loop<x>
  ```

  

### Format Partition Table

- As pre configured from **cfdisk command** first partition is **FAT**

```bash
# Formating the first partition as FAT
sudo mkfs.vfat -F 16 -n boot ${DISK}p1
```

-  As pre configured from cfdisk Command second partition is linux

```
# format the created partition by ext4
sudo mkfs.ext4 -L rootfs ${DISK}p2
```

