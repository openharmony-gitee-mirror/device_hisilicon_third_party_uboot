/*
 * hi3516ev200.h
 *
 * Declaration of Header Files Related to the Chip.
 *
 * Copyright (c) 2020 HiSilicon (Shanghai) Technologies CO., LIMITED.
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __HI3516EV200_H
#define __HI3516EV200_H

#include <linux/sizes.h>
#include <asm/arch/platform.h>

#define CONFIG_SYS_CACHELINE_SIZE   64

/* base on needs #define CONFIG_REMAKE_ELF */

#define CONFIG_SUPPORT_RAW_INITRD

#define CONFIG_BOARD_EARLY_INIT_F

/* Physical Memory Map */

/* CONFIG_SYS_TEXT_BASE needs to align with where ATF loads bl33.bin */
#define CONFIG_SYS_TEXT_BASE        0x40800000
#define CONFIG_SYS_TEXT_BASE_ORI        0x40700000

#define PHYS_SDRAM_1            0x40000000
#define PHYS_SDRAM_1_SIZE       0x4000000

#define CONFIG_SYS_SDRAM_BASE       PHYS_SDRAM_1


#define CONFIG_SYS_INIT_SP_ADDR     0x04014000

#define CONFIG_SYS_LOAD_ADDR        (CONFIG_SYS_SDRAM_BASE + 0x80000)
#define CONFIG_SYS_GBL_DATA_SIZE    128

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY       0x1800000

#define CONFIG_SYS_TIMER_RATE       CFG_TIMER_CLK
#define CONFIG_SYS_TIMER_COUNTER    (CFG_TIMERBASE + REG_TIMER_VALUE)
#define CONFIG_SYS_TIMER_COUNTS_DOWN


/* Generic Interrupt Controller Definitions */
#define GICD_BASE           0xf6801000
#define GICC_BASE           0xf6802000

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN       (CONFIG_ENV_SIZE + SZ_128K)

/* PL011 Serial Configuration */
#define CONFIG_PL011_CLOCK      24000000

#define CONFIG_PL01x_PORTS  \
	{(void *)UART0_REG_BASE, (void *)UART1_REG_BASE, \
	(void *)UART2_REG_BASE}

#define CONFIG_CUR_UART_BASE    UART0_REG_BASE

/* Flash Memory Configuration v100 */
#ifdef CONFIG_HIFMC
#define CONFIG_HIFMC_REG_BASE       FMC_REG_BASE
#define CONFIG_HIFMC_BUFFER_BASE    FMC_MEM_BASE
#define CONFIG_HIFMC_MAX_CS_NUM     1
#endif

#ifdef CONFIG_HIFMC_SPI_NOR
#define CONFIG_CMD_SF
#define CONFIG_SPI_NOR_MAX_CHIP_NUM 1
#define CONFIG_SPI_NOR_QUIET_TEST
#endif

#ifndef CONFIG_MINI_BOOT

#ifdef CONFIG_HIFMC_SPI_NAND
#define CONFIG_CMD_NAND
#define CONFIG_SPI_NAND_MAX_CHIP_NUM    1
#define CONFIG_SYS_MAX_NAND_DEVICE  CONFIG_SPI_NAND_MAX_CHIP_NUM
#define CONFIG_SYS_NAND_MAX_CHIPS   CONFIG_SPI_NAND_MAX_CHIP_NUM
#define CONFIG_SYS_NAND_BASE        FMC_MEM_BASE
#endif

#define CONFIG_SYS_FAULT_ECHO_LINK_DOWN
/*-----------------------------------------------------------------------
 * HIETH driver
 -----------------------------------------------------------------------*/
/* default is hieth-switch-fabric */
#ifdef CONFIG_HISFV300_ETH
#define INNER_PHY
#define HISFV_MII_MODE              0
#define HISFV_RMII_MODE             1
#define HIETH_MII_RMII_MODE_U           HISFV_MII_MODE
#define HIETH_MII_RMII_MODE_D           HISFV_MII_MODE
#define HISFV_PHY_U             0
#define HISFV_PHY_D             2
#endif /* CONFIG_HISFV300_ETH */

/*
base on needs #ifdef  CONFIG_HIMCI
base on needs #define CONFIG_HIMCI_MAX_FREQ           50000000
base on needs #define CONFIG_MMC_POWER_OFF_TIMEOUT    5
base on needs #define CONFIG_MMC_POWER_ON_TIMEROUT    40
base on needs #define CONFIG_MMC_RESET_LOW_TIMEOUT    10
base on needs #define CONFIG_MMC_RESET_HIGH_TIMEROUT  300
*/
#define CONFIG_MISC_INIT_R

/* Command line configuration */
#define CONFIG_MENU
#define CONFIG_CMD_UNZIP
#define CONFIG_CMD_ENV

#define CONFIG_MTD_PARTITIONS

/* BOOTP options */
#define CONFIG_BOOTP_BOOTFILESIZE

/* Initial environment variables */

/*
 * Defines where the kernel and FDT will be put in RAM
 */

/* Assume we boot with root on the seventh partition of eMMC */
#define CONFIG_BOOTARGS "console=ttyAMA0,115200n8 root=/dev/mtdblock2 rw"
#define CONFIG_SYS_USB_XHCI_MAX_ROOT_PORTS 2
#define BOOT_TARGET_DEVICES(func) \
	func(USB, usb, 0) \
	func(MMC, mmc, 1) \
	func(DHCP, dhcp, na)
#include <config_distro_bootcmd.h>

/* allow change env */
#define  CONFIG_ENV_OVERWRITE

#define CONFIG_COMMAND_HISTORY

#endif

/* env in flash instead of CFG_ENV_IS_NOWHERE */
#define CONFIG_ENV_OFFSET       0x80000      /* environment starts here */

#define CONFIG_ENV_VARS_UBOOT_CONFIG

/* kernel parameter list phy addr */
#define CFG_BOOT_PARAMS         (CONFIG_SYS_SDRAM_BASE + 0x0100)

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE       1024    /* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE       (CONFIG_SYS_CBSIZE + \
		    sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_BARGSIZE     CONFIG_SYS_CBSIZE
#define CONFIG_SYS_MAXARGS      64  /* max command args */

#define CONFIG_SYS_NO_FLASH

#define CONFIG_DDR_TRAINING_V2

/* base on needs #define DDR_SCRAMB_ENABLE */

#define CONFIG_PRODUCTNAME "hi3516ev200"

/* the flag for auto update. 1:enable; 0:disable */
#define CONFIG_AUTO_UPDATE          1

#if (CONFIG_AUTO_UPDATE == 1)
#define CONFIG_AUTO_UPDATE_ADAPTATION   1
/* base on needs #define CONFIG_AUTO_SD_UPDATE     1 */
/* base on needs #define CONFIG_AUTO_USB_UPDATE    1 */
#define CONFIG_AUTO_OTA_UPDATE    1
#ifndef CONFIG_MINI_BOOT
#define CONFIG_FS_FAT 1
#define CONFIG_FS_FAT_MAX_CLUSTSIZE 65536
#endif
#endif

/*---------------------------------------------------------------------
 * OTA update
 * get OTA package from SD card--need CONFIG_AUTO_SD_UPDATE
 * verify OTA package--need CONFIG_CIPHER_ENABLE
 * delete OTA package--need CONFIG_FAT_WRITE
 * ---------------------------------------------------------------------*/
#ifdef CONFIG_AUTO_OTA_UPDATE

#define CONFIG_AUTO_SD_UPDATE     1
#define CONFIG_CIPHER_ENABLE
#define CONFIG_FAT_WRITE          1

#endif /* CONFIG_AUTO_OTA_UPDATE */

/*---------------------------------------------------------------------
 * sdcard system updae
 * ---------------------------------------------------------------------*/
#ifdef CONFIG_AUTO_SD_UPDATE

#ifndef CONFIG_SDHCI
#define CONFIG_MMC_WRITE  1
#define CONFIG_MMC_QUIRKS  1
#define CONFIG_MMC_HW_PARTITIONING  1
#define CONFIG_MMC_HS400_ES_SUPPORT  1
#define CONFIG_MMC_HS400_SUPPORT  1
#define CONFIG_MMC_HS200_SUPPORT  1
#define CONFIG_MMC_VERBOSE  1
#define CONFIG_MMC_SDHCI  1
#define CONFIG_MMC_SDHCI_ADMA  1
#endif

#ifndef CONFIG_MMC
#define CONFIG_MMC      1
#endif

#endif

/* SD/MMC configuration */
#ifdef CONFIG_MMC
#define CONFIG_SUPPORT_EMMC_BOOT
#define CONFIG_GENERIC_MMC
#define CONFIG_CMD_MMC
#define CONFIG_SYS_MMC_ENV_DEV  0
#define CONFIG_EXT4_SPARSE
#define CONFIG_SDHCI
#define CONFIG_HISI_SDHCI
#define CONFIG_HISI_SDHCI_MAX_FREQ  150000000
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_FS_EXT4
#define CONFIG_SDHCI_ADMA
#endif

#ifndef CONFIG_HIFMC
#define CONFIG_EMMC
#endif

#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_CMDLINE_TAG

#define HIGZIP_HEAD_SIZE   0X10
#define HEAD_MAGIC_NUM0 0X70697A67 /* 'g''z''i''p' */
#define HEAD_MAGIC_NUM0_OFFSET 0X8
#define HEAD_MAGIC_NUM1 0X64616568 /* 'h''e''a''d' */
#define HEAD_MAGIC_NUM1_OFFSET 0XC
#define COMPRESSED_SIZE_OFFSET      0X0
#define UNCOMPRESSED_SIZE_OFFSET    0X4

/* base on needs #define CONFIG_OSD_ENABLE */ /* For VO */
#define CONFIG_CIPHER_ENABLE

#define CONFIG_CMD_UGZIP

/* base on needs #define CONFIG_AUDIO_ENABLE */

/* base on needs #definee CONFIG_EDMA_PLL_TRAINNING */

#define CONFIG_OSD_ENABLE
#endif /* __HI3516EV200_H */
