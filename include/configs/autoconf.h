/*
 * Automatically generated C config: don't edit
 * Linux Kernel Configuration
 * Mon Nov 14 09:02:39 2022
 */
#define CONFIG_FMT1_REG 0xF8003800
#define CONFIG_BOOTSTRAP_TEXT_BASE 0x80200000
#define CONFIG_GRX500_CS0_ONLY 1
#define CONFIG_NAND_FLASH_128M 1
#define CONFIG_GRX500_ROM_HEADER_BCH_CAP 40
#define CONFIG_USE_DEFAULT_PREBOOT 1
#define CONFIG_ZLIB 1
#define CONFIG_ENV_OVERWRITE 1
#define CONFIG_NFSARGS "setenv bootargs root=/dev/nfs rw nfsroot=$(serverip):$(rootpath)"
#define CONFIG_GRX500_PHY3 1
#define CONFIG_FULLIMAGE "fullimage.img"
#define CONFIG_DRIVER_GRX500 1
#define CONFIG_GRX500_DDR3 1
#define CONFIG_MTD_PARTITIONS 1
#define CONFIG_GZIP 1
#define CONFIG_UPDATE_UBOOT "tftpboot $(loadaddr) $(tftppath)$(u-boot);erase b0000000 b001ffff;cp.b $(loadaddr) b0000000 $(filesize);reset"
#define CONFIG_MTDIDS "nand0=ifx_nand"
#define CONFIG_ROOT_PATH "/mnt/full_fs"
#define CONFIG_IFX_MEMORY_SIZE 64
#define CONFIG_ADDMISC "setenv bootargs $(bootargs) console=$(console),$(baudrate) ethaddr=$(ethaddr) phym=$(phym) mem=$(mem) panic=1 mtdparts=$(mtdparts)"
#define CONFIG_USE_DEFAULT_MTDPARTS 1
#define CONFIG_CMD_SAVEENV 1
#define CONFIG_GRX500_ADDITIVE_LATENCY 1
#define CONFIG_NAND_ECC_SOFT 1
#define CONFIG_GRX500_1ST_SR0_VALUE 24
#define CONFIG_NAND_PRELOAD_TEXT_BASE 0xa0010000
#define CONFIG_FLASH_FLASH "run flashargs addip addmisc; bootm $(kernel_addr)"
#define CONFIG_NAND_U_BOOT 1
#define CONFIG_LANTIQ_UART 1
#define CONFIG_GRX500_CPU_600M 1
#define CONFIG_MTDPARTS "ifx_nand:64k(uboot),-(rootfs)"
#define CONFIG_RESET_UBOOT_CONFIG "nand erase $(f_ubootconfig_addr) $(f_ubootconfig_range)"
#define CONFIG_TOTALIMAGE "totalimage.img"
#define CONFIG_ENV_SIZE 0x4000
#define CONFIG_NAND_FLASH 1
#define CONFIG_UPDATE_BOOTLOADER "update_uboot;update gphyfirmware"
#define CONFIG_NAND_BLOCK_SIZE 0x20000
#define CONFIG_TFTPPATH ""
#define CONFIG_GRX500_PHY2 1
#define CONFIG_GRX500_2ND_SR1_VALUE 24
#define CONFIG_GRX500_BL8 1
#define CONFIG_UPDATE_BOOTCORE "tftpboot $(loadaddr) $(tftppath)$(bootcore);nand erase 200000 40000;nand write $(loadaddr) 200000 40000"
#define CONFIG_TOS_128M 1
#define CONFIG_PHYM "32M"
#define CONFIG_TFTP_LOAD_ADDRESS "0x80800000"
#define CONFIG_GRX500_GPHY_FW_EMBEDDED 1
#define CONFIG_UPDATE_FULLIMAGE "tftpboot $(loadaddr) $(tftppath)$(fullimage);upgrade $(loadaddr) $(filesize)"
#define CONFIG_ADDIP "setenv bootargs $(bootargs) ip=$(ipaddr):$(serverip):$(gatewayip):$(netmask):$(hostname):$(netdev):on"
#define CONFIG_BOOT_FROM_NAND 1
#define CONFIG_GRX500_PHY5 1
#define CONFIG_GRX500_CBM_FREQ_200M 1
#define CONFIG_NET_NFS "tftp $(loadaddr) $(tftppath)$(bootfile);run nfsargs addip addmisc;bootm"
#define CONFIG_MII 1
#define CONFIG_CMD_NAND 1
#define CONFIG_CONSOLE "ttyS1"
#define CONFIG_NET_FLASH "tftp $(loadaddr) $(tftppath)$(bootfile); run flashargs addip addmisc; bootm"
#define CONFIG_MEM "31M"
#define CONFIG_NAND_PAGE_SIZE 0x800
#define CONFIG_DDR_512M 1
#define CONFIG_BOOTDELAY 5
#define CONFIG_UPDATE_NANDBOOT "tftp $(loadaddr) $(tftppath)u-boot-nand.bin; nand erase clean 0 0x08000000; nand write $(loadaddr) 0 $(filesize)"
#define CONFIG_OS_LZMA 1
#define CONFIG_ROOTFSMTD "/dev/mtdblock2"
#define CONFIG_IP_ADDRESS "192.168.1.1"
#define CONFIG_BOOTCOMMAND "run flash_flash"
#define CONFIG_CMD_LOADB 1
#define CONFIG_CMD_RUN 1
#define CONFIG_UPDATE_GPHYFIRMWARE "tftpboot $(loadaddr) $(tftppath)gphy_firmware.img;nand write.partial $(loadaddr) 24000 10000"
#define CONFIG_CMD_MEMORY 1
#define CONFIG_NETWORK_VIA_LAN 1
#define CONFIG_NUMBER_OF_MAC_RESERVED "2"
#define CONFIG_CMD_ECHO 1
#define CONFIG_RBTREE 1
#define CONFIG_RAMARGS "setenv bootargs root=/dev/ram rw"
#define CONFIG_CMD_MTDPARTS 1
#define CONFIG_BOOTFILE "uImage"
#define CONFIG_MTD_DEVICE 1
#define CONFIG_NAND_SPL_TEXT_BASE 0xa0001000
#define CONFIG_GRX500_667M_CL9 1
#define CONFIG_CMD_UBI 1
#define CONFIG_UPDATE_KERNEL "tftpboot $(loadaddr) $(tftppath)$(bootfile);upgrade $(loadaddr) $(filesize)"
#define CONFIG_UPDATE_TOTALIMAGE "tftpboot $(loadaddr) $(tftppath)$(totalimage);upgrade $(loadaddr) $(filesize)"
#define CONFIG_UPDATE_ROOTFS "tftpboot $(loadaddr) $(tftppath)$(rootfs); upgrade $(loadaddr) $(filesize)"
#define CONFIG_CMD_UPGRADE 1
#define CONFIG_BAUDRATE 9600
#define CONFIG_CONFIG_REMOVE_GZIP 1
#define CONFIG_GRX500_PHY4 1
#define CONFIG_FLASH_NFS "run nfsargs addip addmisc;bootm $(kernel_addr)"
#define CONFIG_ENV_IS_IN_NAND 1
#define CONFIG_ETHERNET_DEVICE "eth0"
#define CONFIG_GRX500_256Mx16 1
#define CONFIG_BOOT_CORE "bootcore"
#define CONFIG_SYS_NO_FLASH 1
#define CONFIG_GRX500_MIPS_ENDIAN_BE 1
#define CONFIG_NAND_SPL_BLOCK_SIZE 0x6000
#define CONFIG_GRX500_2ND_SR0_VALUE 24
#define CONFIG_NET_RAM "tftp $(loadaddr) $(tftppath)$(bootfile); run ramargs addip addmisc; bootm"
#define CONFIG_UBI_WL_THRESHOLD 4096
#define CONFIG_NAND_FLASH_SIZE 128
#define CONFIG_RESET_SYSCONFIG "run ubi_init;ubi remove sysconfig;ubi remove sysconfigA;ubi remove sysconfigB"
#define CONFIG_RAM_TEXT_BASE 0xA0400000
#define CONFIG_RUN_BOOTCORE "nand read 0xA0400000 $(tftppath)$(bootcore);secboot load_os 0x8E000000 0xA0400000 0x200000"
#define CONFIG_SERVER_IP_ADDRESS "192.168.1.2"
#define CONFIG_NAND_LANTIQ 1
#define CONFIG_U_BOOT "u-boot.ltq"
#define CONFIG_CMD_NET 1
#define CONFIG_GRX500_1ST_SR1_VALUE 24
#define CONFIG_CROSS_COMPILE_UCLIBC 1
#define CONFIG_GRX500_DDR_CTRL_333M 1
#define CONFIG_LANTIQ_UBOOT_grx500 1
#define CONFIG_RESET_DDR_CONFIG "nand write.partial 80400000 $(f_ddrconfig_addr) $(f_ddrconfig_size)"
#define CONFIG_FIRMWARE "firmware.img"
#define CONFIG_GRX500_GPHY_FW_ADDR 0xa0220000
#define CONFIG_IFX_UBOOT_OPTIMIZED 1
#define CONFIG_UBI_INIT "ubi part data;setenv kernelA_vol_id 0;setenv rootfsA_vol_id 1;setenv firmwareA_vol_id 2;setenv kernelB_vol_id 3;setenv rootfsB_vol_id 4;setenv firmwareB_vol_id 5;setenv setbank check_image$(update_chk);run $(setbank)"
#define CONFIG_LZMA 1
#define CONFIG_UPDATE_FIRMWARE "tftpboot $(loadaddr) $(tftppath)$(firmware);upgrade $(loadaddr) $(filesize)"
#define CONFIG_NUMBER_OF_MAC_SUPPORTED "32"
#define CONFIG_CONFIG_IFX_MIPS 1
#define CONFIG_FLASHARGS "setenv bootargs root=$(rootfsmtd) ro rootfstype=squashfs init=/etc/preinit"
#define CONFIG_GRX500_A11 1
#define CONFIG_ETHERNET_ADDRESS "00:E0:92:00:01:40"
#define CONFIG_ROOTFS "rootfs.img"
#define CONFIG_LZO 1
