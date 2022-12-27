#ifndef BSP_H
#define BSP_H
/******************************************************************************
       Copyright (c) 2002, Infineon Technologies.  All rights reserved.

                               No Warranty
   Because the program is licensed free of charge, there is no warranty for 
   the program, to the extent permitted by applicable law.  Except when     
   otherwise stated in writing the copyright holders and/or other parties   
   provide the program "as is" without warranty of any kind, either         
   expressed or implied, including, but not limited to, the implied         
   warranties of merchantability and fitness for a particular purpose. The  
   entire risk as to the quality and performance of the program is with     
   you.  should the program prove defective, you assume the cost of all     
   necessary servicing, repair or correction.                               
                                                                            
   In no event unless required by applicable law or agreed to in writing    
   will any copyright holder, or any other party who may modify and/or      
   redistribute the program as permitted above, be liable to you for        
   damages, including any general, special, incidental or consequential     
   damages arising out of the use or inability to use the program           
   (including but not limited to loss of data or data being rendered        
   inaccurate or losses sustained by you or third parties or a failure of   
   the program to operate with any other programs), even if such holder or  
   other party has been advised of the possibility of such damages. 
******************************************************************************/
#define BSP_PLATFORM            "VR9"
//#define u32 unsigned long
//#define u16 unsigned short
//#define u8  unsigned char

#define KSEG1 0xa0000000

/***********************************************************************/
/*  Module      :  CSS register address and bits                       */
/***********************************************************************/
#define CSS_BASE   (KSEG1+0x1F400000)
#define CSS_DDR_ECHO_DLL0  ((volatile u32*)(CSS_BASE + 0x0420))
#define CSS_DDR_ECHO_DLL1  ((volatile u32*)(CSS_BASE + 0x0428))


/***********************************************************************/
/*  Module      :  WDT register address and bits                       */
/***********************************************************************/

#define BSP_BIU_WDT                           (KSEG1+0x1F880000)

/***Watchdog Timer Control Register ***/
#define BSP_BIU_WDT_CR                   ((volatile u32*)(BSP_BIU_WDT + 0x03F0))
#define BSP_BIU_WDT_CR_GEN               (1 << 31)
#define BSP_BIU_WDT_CR_DSEN              (1 << 30)
#define BSP_BIU_WDT_CR_LPEN              (1 << 29)
#define BSP_BIU_WDT_CR_PWL_GET(value)    (((value) >> 26) & ((1 << 2) - 1))
#define BSP_BIU_WDT_CR_PWL_SET(value)    (((( 1 << 2) - 1) & (value)) << 26)
#define BSP_BIU_WDT_CR_CLKDIV_GET(value) (((value) >> 24) & ((1 << 2) - 1))
#define BSP_BIU_WDT_CR_CLKDIV_SET(value) (((( 1 << 2) - 1) & (value)) << 24)
#define BSP_BIU_WDT_CR_PW_GET(value)     (((value) >> 16) & ((1 << 8) - 1))
#define BSP_BIU_WDT_CR_PW_SET(value)     (((( 1 << 8) - 1) & (value)) << 16)
#define BSP_BIU_WDT_CR_RELOAD_GET(value) (((value) >> 0) & ((1 << 16) - 1))
#define BSP_BIU_WDT_CR_RELOAD_SET(value) (((( 1 << 16) - 1) & (value)) << 0)

/***Watchdog Timer Status Register***/
#define BSP_BIU_WDT_SR                   ((volatile u32*)(BSP_BIU_WDT + 0x03F8))
#define BSP_BIU_WDT_SR_EN                (1 << 31)
#define BSP_BIU_WDT_SR_AE                (1 << 30)
#define BSP_BIU_WDT_SR_PRW               (1 << 29)
#define BSP_BIU_WDT_SR_EXP               (1 << 28)
#define BSP_BIU_WDT_SR_PWD               (1 << 27)
#define BSP_BIU_WDT_SR_DS                (1 << 26)
#define BSP_BIU_WDT_SR_VALUE_GET(value)  (((value) >> 0) & ((1 << 16) - 1))
#define BSP_BIU_WDT_SR_VALUE_SET(value)  (((( 1 << 16) - 1) & (value)) << 0)

/***********************************************************************/
/*  Module      :  RCU register address and bits                       */
/***********************************************************************/
#define BSP_RCU_BASE_ADDR 		(0xBF203000)

#define BSP_RCU_REQ 			(0x0010 + BSP_RCU_BASE_ADDR) /* will remove this, pls use BSP_RCU_RST_REQ */

#define BSP_RCU_RST_REQ              ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0010))
#define BSP_RCU_RST_STAT             ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0014))
#define BSP_RCU_USB1_CFG             ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0018))
#define BSP_GPHY_FW_ADD0             ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0020))
#define BSP_RCU_RST_STAT2             ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0024))
#define BSP_RCU_USB2_CFG            ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0034))
#define BSP_RCU_USB1_ANA1           ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0038))
#define BSP_RCU_USB2_ANA1           ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x003C))
#define BSP_RCU_USB1_ANA2           ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0040))
#define BSP_RCU_USB2_ANA2           ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0044))
#define BSP_RCU_RST_REQ2             ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0048))
#define BSP_GPHY_FW_ADD1             ((volatile u32*)(BSP_RCU_BASE_ADDR + 0x0068))

#define BSP_RST_ALL                  (0x40000000)
/***Reset Request Register***/ 
#define BSP_RCU_RST_REQ_CPU0                 (1 << 31)
#define BSP_RCU_RST_REQ_CPU1                 (1 << 3)
#define BSP_RCU_RST_REQ_CPUSUB               (1 << 29)
#define BSP_RCU_RST_REQ_HRST                 (1 << 28)
#define BSP_RCU_RST_REQ_WDT0                 (1 << 27)
#define BSP_RCU_RST_REQ_WDT1                 (1 << 26)
#define BSP_RCU_RST_REQ_CFG_GET(value)       (((value) >> 23) & ((1 << 3) - 1))
#define BSP_RCU_RST_REQ_CFG_SET(value)       (((( 1 << 3) - 1) & (value)) << 23)
#define BSP_RCU_RST_REQ_SWTBOOT              (1 << 22)
#define BSP_RCU_RST_REQ_DMA                  (1 << 21)
#define BSP_RCU_RST_REQ_ARC_JTAG              (1 << 20)
#define BSP_RCU_RST_REQ_ETHPHY0              (1 << 19)
#define BSP_RCU_RST_REQ_CPU0_BR              (1 << 18)

#define BSP_RCU_RST_REQ_AFE			(1 << 11)
#define BSP_RCU_RST_REQ_DFE			(1 << 7)

/* CPU0, CPU1, CPUSUB, HRST, WDT0, WDT1, DMA, ETHPHY1, ETHPHY0 */
#define BSP_RCU_RST_REQ_ALL                  BSP_RST_ALL

#define BSP_RCU_STAT		        (0x0014 + BSP_RCU_BASE_ADDR) 
#define BSP_RCU_RST_SR	        ( (volatile u32 *)(BSP_RCU_STAT))/* will remove this, pls use BSP_RCU_RST_STAT */

#define BSP_RCU_PCIE_RDY	        ( (volatile u32 *)(BSP_RCU_BASE_ADDR+0x28))
#define BSP_RCU_MON                  (0x0030 + BSP_RCU_BASE_ADDR)

#define BSP_RCU_AHB_ENDIAN           (0x004C + BSP_RCU_BASE_ADDR) 
#define BSP_RC_AHB_BE_PCIE_M         (1 << 0)
#define BSP_RC_AHB_BE_MIPS_M         (1 << 1)
#define BSP_RC_AHB_BE_USIF           (1 << 2)
#define BSP_RC_AHB_BE_MIPS_S         (1 << 3)
#define BSP_RC_AHB_BE_PCIE_S         (1 << 4)
#define BSP_RC_AHB_BE_PCIE_DBI       (1 << 5)
#define BSP_RC_AHB_BE_PDI            (1 << 7)


/***********************************************************************/
/*  Module      :  BCU  register address and bits                       */
/***********************************************************************/

#define BSP_BCU_BASE_ADDR 			(KSEG1+0x1E100000)

/***BCU Control Register (0010H)***/
#define BSP_BCU_CON                          ((volatile u32*)(0x0010 + BSP_BCU_BASE_ADDR))
#define BSP_BCU_BCU_CON_SPC (value)                (((( 1 << 8) - 1) & (value)) << 24)
#define BSP_BCU_BCU_CON_SPE                              (1 << 19)
#define BSP_BCU_BCU_CON_PSE                              (1 << 18)
#define BSP_BCU_BCU_CON_DBG                              (1 << 16)
#define BSP_BCU_BCU_CON_TOUT (value)               (((( 1 << 16) - 1) & (value)) << 0)


/***BCU Error Control Capture Register (0020H)***/
#define BSP_BCU_ECON                         ((volatile u32*)(0x0014 + BSP_BCU_BASE_ADDR))
#define BSP_BCU_BCU_ECON_TAG (value)                (((( 1 << 4) - 1) & (value)) << 24)
#define BSP_BCU_BCU_ECON_RDN                              (1 << 23)
#define BSP_BCU_BCU_ECON_WRN                              (1 << 22)
#define BSP_BCU_BCU_ECON_SVM                              (1 << 21)
#define BSP_BCU_BCU_ECON_ACK (value)                (((( 1 << 2) - 1) & (value)) << 19)
#define BSP_BCU_BCU_ECON_ABT                              (1 << 18)
#define BSP_BCU_BCU_ECON_RDY                              (1 << 17)
#define BSP_BCU_BCU_ECON_TOUT                             (1 << 16)
#define BSP_BCU_BCU_ECON_ERRCNT (value)             (((( 1 << 16) - 1) & (value)) << 0)
#define BSP_BCU_BCU_ECON_OPC (value)                (((( 1 << 4) - 1) & (value)) << 28)

/***BCU Error Address Capture Register (0024 H)***/
#define BSP_BCU_EADD 			((volatile u32*)(0x0020 + BSP_BCU_BASE_ADDR))

/***BCU Error Data Capture Register (0028H)***/
#define BSP_BCU_EDAT 			((volatile u32*)(0x0024 + BSP_BCU_BASE_ADDR))
#define BSP_BCU_IRNEN 			((volatile u32*)(0x00F4 + BSP_BCU_BASE_ADDR))
#define BSP_BCU_IRNICR 			((volatile u32*)(0x00F8 + BSP_BCU_BASE_ADDR))
#define BSP_BCU_IRNCR 			((volatile u32*)(0x00FC + BSP_BCU_BASE_ADDR))


/***********************************************************************/
/*  Module      :  MBC register address and bits                       */
/***********************************************************************/

#define BSP_MBC                          (0xBF103000)
/***********************************************************************/


/***Mailbox CPU Configuration Register***/
#define BSP_MBC_MBC_CFG                      ((volatile u32*)(BSP_MBC+ 0x0080))
#define BSP_MBC_MBC_CFG_SWAP (value)               (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_MBC_MBC_CFG_RES                              (1 << 5)
#define BSP_MBC_MBC_CFG_FWID (value)               (((( 1 << 4) - 1) & (value)) << 1)
#define BSP_MBC_MBC_CFG_SIZE                            (1 << 0)

/***Mailbox CPU Interrupt Status Register***/
#define BSP_MBC_MBC_ISR                      ((volatile u32*)(BSP_MBC+ 0x0084))
#define BSP_MBC_MBC_ISR_B3DA                            (1 << 31)
#define BSP_MBC_MBC_ISR_B2DA                            (1 << 30)
#define BSP_MBC_MBC_ISR_B1E                              (1 << 29)
#define BSP_MBC_MBC_ISR_B0E                              (1 << 28)
#define BSP_MBC_MBC_ISR_WDT                              (1 << 27)
#define BSP_MBC_MBC_ISR_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Mask Register***/
#define BSP_MBC_MBC_MSK                      ((volatile u32*)(BSP_MBC+ 0x0088))
#define BSP_MBC_MBC_MSK_B3DA                            (1 << 31)
#define BSP_MBC_MBC_MSK_B2DA                            (1 << 30)
#define BSP_MBC_MBC_MSK_B1E                              (1 << 29)
#define BSP_MBC_MBC_MSK_B0E                              (1 << 28)
#define BSP_MBC_MBC_MSK_WDT                              (1 << 27)
#define BSP_MBC_MBC_MSK_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Mask 01 Register***/
#define BSP_MBC_MBC_MSK01                    ((volatile u32*)(BSP_MBC+ 0x008C))
#define BSP_MBC_MBC_MSK01_B3DA                            (1 << 31)
#define BSP_MBC_MBC_MSK01_B2DA                            (1 << 30)
#define BSP_MBC_MBC_MSK01_B1E                              (1 << 29)
#define BSP_MBC_MBC_MSK01_B0E                              (1 << 28)
#define BSP_MBC_MBC_MSK01_WDT                              (1 << 27)
#define BSP_MBC_MBC_MSK01_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Mask 10 Register***/
#define BSP_MBC_MBC_MSK10                    ((volatile u32*)(BSP_MBC+ 0x0090))
#define BSP_MBC_MBC_MSK10_B3DA                            (1 << 31)
#define BSP_MBC_MBC_MSK10_B2DA                            (1 << 30)
#define BSP_MBC_MBC_MSK10_B1E                              (1 << 29)
#define BSP_MBC_MBC_MSK10_B0E                              (1 << 28)
#define BSP_MBC_MBC_MSK10_WDT                              (1 << 27)
#define BSP_MBC_MBC_MSK10_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Short Command Register***/
#define BSP_MBC_MBC_CMD                      ((volatile u32*)(BSP_MBC+ 0x0094))
#define BSP_MBC_MBC_CMD_CS270 (value)             (((( 1 << 28) - 1) & (value)) << 0)

/***Mailbox CPU Input Data of Buffer 0***/
#define BSP_MBC_MBC_ID0                      ((volatile u32*)(BSP_MBC+ 0x0000))
#define BSP_MBC_MBC_ID0_INDATA

/***Mailbox CPU Input Data of Buffer 1***/
#define BSP_MBC_MBC_ID1                      ((volatile u32*)(BSP_MBC+ 0x0020))
#define BSP_MBC_MBC_ID1_INDATA

/***Mailbox CPU Output Data of Buffer 2***/
#define BSP_MBC_MBC_OD2                      ((volatile u32*)(BSP_MBC+ 0x0040))
#define BSP_MBC_MBC_OD2_OUTDATA

/***Mailbox CPU Output Data of Buffer 3***/
#define BSP_MBC_MBC_OD3                      ((volatile u32*)(BSP_MBC+ 0x0060))
#define BSP_MBC_MBC_OD3_OUTDATA

/***Mailbox CPU Control Register of Buffer 0***/
#define BSP_MBC_MBC_CR0                      ((volatile u32*)(BSP_MBC+ 0x0004))
#define BSP_MBC_MBC_CR0_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Control Register of Buffer 1***/
#define BSP_MBC_MBC_CR1                      ((volatile u32*)(BSP_MBC+ 0x0024))
#define BSP_MBC_MBC_CR1_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Control Register of Buffer 2***/
#define BSP_MBC_MBC_CR2                      ((volatile u32*)(BSP_MBC+ 0x0044))
#define BSP_MBC_MBC_CR2_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Control Register of Buffer 3***/
#define BSP_MBC_MBC_CR3                      ((volatile u32*)(BSP_MBC+ 0x0064))
#define BSP_MBC_MBC_CR3_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Free Space of Buffer 0***/
#define BSP_MBC_MBC_FS0                      ((volatile u32*)(BSP_MBC+ 0x0008))
#define BSP_MBC_MBC_FS0_FS

/***Mailbox CPU Free Space of Buffer 1***/
#define BSP_MBC_MBC_FS1                      ((volatile u32*)(BSP_MBC+ 0x0028))
#define BSP_MBC_MBC_FS1_FS

/***Mailbox CPU Free Space of Buffer 2***/
#define BSP_MBC_MBC_FS2                      ((volatile u32*)(BSP_MBC+ 0x0048))
#define BSP_MBC_MBC_FS2_FS

/***Mailbox CPU Free Space of Buffer 3***/
#define BSP_MBC_MBC_FS3                      ((volatile u32*)(BSP_MBC+ 0x0068))
#define BSP_MBC_MBC_FS3_FS

/***Mailbox CPU Data Available in Buffer 0***/
#define BSP_MBC_MBC_DA0                      ((volatile u32*)(BSP_MBC+ 0x000C))
#define BSP_MBC_MBC_DA0_DA

/***Mailbox CPU Data Available in Buffer 1***/
#define BSP_MBC_MBC_DA1                      ((volatile u32*)(BSP_MBC+ 0x002C))
#define BSP_MBC_MBC_DA1_DA

/***Mailbox CPU Data Available in Buffer 2***/
#define BSP_MBC_MBC_DA2                      ((volatile u32*)(BSP_MBC+ 0x004C))
#define BSP_MBC_MBC_DA2_DA

/***Mailbox CPU Data Available in Buffer 3***/
#define BSP_MBC_MBC_DA3                      ((volatile u32*)(BSP_MBC+ 0x006C))
#define BSP_MBC_MBC_DA3_DA

/***Mailbox CPU Input Absolute Pointer of Buffer 0***/
#define BSP_MBC_MBC_IABS0                    ((volatile u32*)(BSP_MBC+ 0x0010))
#define BSP_MBC_MBC_IABS0_IABS

/***Mailbox CPU Input Absolute Pointer of Buffer 1***/
#define BSP_MBC_MBC_IABS1                    ((volatile u32*)(BSP_MBC+ 0x0030))
#define BSP_MBC_MBC_IABS1_IABS

/***Mailbox CPU Input Absolute Pointer of Buffer 2***/
#define BSP_MBC_MBC_IABS2                    ((volatile u32*)(BSP_MBC+ 0x0050))
#define BSP_MBC_MBC_IABS2_IABS

/***Mailbox CPU Input Absolute Pointer of Buffer 3***/
#define BSP_MBC_MBC_IABS3                    ((volatile u32*)(BSP_MBC+ 0x0070))
#define BSP_MBC_MBC_IABS3_IABS

/***Mailbox CPU Input Temporary Pointer of Buffer 0***/
#define BSP_MBC_MBC_ITMP0                    ((volatile u32*)(BSP_MBC+ 0x0014))
#define BSP_MBC_MBC_ITMP0_ITMP

/***Mailbox CPU Input Temporary Pointer of Buffer 1***/
#define BSP_MBC_MBC_ITMP1                    ((volatile u32*)(BSP_MBC+ 0x0034))
#define BSP_MBC_MBC_ITMP1_ITMP

/***Mailbox CPU Input Temporary Pointer of Buffer 2***/
#define BSP_MBC_MBC_ITMP2                    ((volatile u32*)(BSP_MBC+ 0x0054))
#define BSP_MBC_MBC_ITMP2_ITMP

/***Mailbox CPU Input Temporary Pointer of Buffer 3***/
#define BSP_MBC_MBC_ITMP3                    ((volatile u32*)(BSP_MBC+ 0x0074))
#define BSP_MBC_MBC_ITMP3_ITMP

/***Mailbox CPU Output Absolute Pointer of Buffer 0***/
#define BSP_MBC_MBC_OABS0                    ((volatile u32*)(BSP_MBC+ 0x0018))
#define BSP_MBC_MBC_OABS0_OABS

/***Mailbox CPU Output Absolute Pointer of Buffer 1***/
#define BSP_MBC_MBC_OABS1                    ((volatile u32*)(BSP_MBC+ 0x0038))
#define BSP_MBC_MBC_OABS1_OABS

/***Mailbox CPU Output Absolute Pointer of Buffer 2***/
#define BSP_MBC_MBC_OABS2                    ((volatile u32*)(BSP_MBC+ 0x0058))
#define BSP_MBC_MBC_OABS2_OABS

/***Mailbox CPU Output Absolute Pointer of Buffer 3***/
#define BSP_MBC_MBC_OABS3                    ((volatile u32*)(BSP_MBC+ 0x0078))
#define BSP_MBC_MBC_OABS3_OABS

/***Mailbox CPU Output Temporary Pointer of Buffer 0***/
#define BSP_MBC_MBC_OTMP0                    ((volatile u32*)(BSP_MBC+ 0x001C))
#define BSP_MBC_MBC_OTMP0_OTMP

/***Mailbox CPU Output Temporary Pointer of Buffer 1***/
#define BSP_MBC_MBC_OTMP1                    ((volatile u32*)(BSP_MBC+ 0x003C))
#define BSP_MBC_MBC_OTMP1_OTMP

/***Mailbox CPU Output Temporary Pointer of Buffer 2***/
#define BSP_MBC_MBC_OTMP2                    ((volatile u32*)(BSP_MBC+ 0x005C))
#define BSP_MBC_MBC_OTMP2_OTMP

/***Mailbox CPU Output Temporary Pointer of Buffer 3***/
#define BSP_MBC_MBC_OTMP3                    ((volatile u32*)(BSP_MBC+ 0x007C))
#define BSP_MBC_MBC_OTMP3_OTMP

/***DSP Control Register***/
#define BSP_MBC_DCTRL                        ((volatile u32*)(BSP_MBC+ 0x00A0))
#define BSP_MBC_DCTRL_BA                              (1 << 0)
#define BSP_MBC_DCTRL_BMOD (value)               (((( 1 << 3) - 1) & (value)) << 1)
#define BSP_MBC_DCTRL_IDL                              (1 << 4)
#define BSP_MBC_DCTRL_RES                              (1 << 15)

/***DSP Status Register***/
#define BSP_MBC_DSTA                         ((volatile u32*)(BSP_MBC+ 0x00A4))
#define BSP_MBC_DSTA_IDLE                            (1 << 0)
#define BSP_MBC_DSTA_PD                              (1 << 1)

/***DSP Test 1 Register***/
#define BSP_MBC_DTST1                        ((volatile u32*)(BSP_MBC+ 0x00A8))
#define BSP_MBC_DTST1_ABORT                          (1 << 0)
#define BSP_MBC_DTST1_HWF32                          (1 << 1)
#define BSP_MBC_DTST1_HWF4M                          (1 << 2)
#define BSP_MBC_DTST1_HWFOP                          (1 << 3)


/***********************************************************************/
/*  Module      :  MEI register address and bits                       */
/***********************************************************************/
#define MEI_SPACE_ACCESS	0xBE116000

/***	Register address offsets, relative to MEI_SPACE_ADDRESS ***/
#define MEI_DATA_XFR				((volatile u32*)(0x0000 + MEI_SPACE_ACCESS))
#define	MEI_VERSION				((volatile u32*)(0x0004 + MEI_SPACE_ACCESS))	
#define	MEI_ARC_GP_STAT				((volatile u32*)(0x0008 + MEI_SPACE_ACCESS))	
#define MEI_DATA_XFR_STAT			((volatile u32*)(0x000C + MEI_SPACE_ACCESS))
#define	MEI_XFR_ADDR				((volatile u32*)(0x0010 + MEI_SPACE_ACCESS))	
#define MEI_MAX_WAIT				((volatile u32*)(0x0014 + MEI_SPACE_ACCESS))
#define	MEI_TO_ARC_INT				((volatile u32*)(0x0018 + MEI_SPACE_ACCESS))
#define	ARC_TO_MEI_INT				((volatile u32*)(0x001C + MEI_SPACE_ACCESS))
#define	ARC_TO_MEI_INT_MASK			((volatile u32*)(0x0020 + MEI_SPACE_ACCESS))
#define	MEI_DEBUG_WAD				((volatile u32*)(0x0024 + MEI_SPACE_ACCESS))	
#define MEI_DEBUG_RAD				((volatile u32*)(0x0028 + MEI_SPACE_ACCESS))	
#define	MEI_DEBUG_DATA				((volatile u32*)(0x002C + MEI_SPACE_ACCESS))	
#define	MEI_DEBUG_DEC				((volatile u32*)(0x0030 + MEI_SPACE_ACCESS))
#define MEI_CONFIG				((volatile u32*)(0x0034 + MEI_SPACE_ACCESS))
#define	MEI_RST_CONTROL				((volatile u32*)(0x0038 + MEI_SPACE_ACCESS))	
#define	MEI_DBG_MASTER				((volatile u32*)(0x003C + MEI_SPACE_ACCESS))	
#define	MEI_CLK_CONTROL				((volatile u32*)(0x0040 + MEI_SPACE_ACCESS))
#define	MEI_BIST_CONTROL			((volatile u32*)(0x0044 + MEI_SPACE_ACCESS))
#define	MEI_BIST_STAT				((volatile u32*)(0x0048 + MEI_SPACE_ACCESS))
#define MEI_XDATA_BASE_SH			((volatile u32*)(0x004c + MEI_SPACE_ACCESS))
#define MEI_XDATA_BASE				((volatile u32*)(0x0050 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR_BASE			((volatile u32*)(0x0054 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR0				((volatile u32*)(0x0054 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR1				((volatile u32*)(0x0058 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR2				((volatile u32*)(0x005C + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR3				((volatile u32*)(0x0060 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR4				((volatile u32*)(0x0064 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR5				((volatile u32*)(0x0068 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR6				((volatile u32*)(0x006C + MEI_SPACE_ACCESS)))
#define MEI_XMEM_BAR7				((volatile u32*)(0x0070 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR8				((volatile u32*)(0x0074 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR9				((volatile u32*)(0x0078 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR10				((volatile u32*)(0x007C + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR11				((volatile u32*)(0x0080 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR12				((volatile u32*)(0x0084 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR13				((volatile u32*)(0x0088 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR14				((volatile u32*)(0x008C + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR15				((volatile u32*)(0x0090 + MEI_SPACE_ACCESS))
#define MEI_XMEM_BAR16				((volatile u32*)(0x0094 + MEI_SPACE_ACCESS))


/***********************************************************************/
/*  Module      :  SSC1 register address and bits                      */
/***********************************************************************/

#define BSP_SSC1                       	(KSEG1+0x1e100800) 
/***********************************************************************/
/***SSC Clock Control Register***/
#define BSP_SSC_CLC                      	(0x0000)
#define BSP_SSC_CLC_RMC(value)               (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_SSC_CLC_DISS                     (1 << 1)
#define BSP_SSC_CLC_DISR                     (1 << 0)
/***SSC Port Input Selection Register***/
#define BSP_SSC_PISEL                        (0x0004)
/***SSC Identification Register***/
#define BSP_SSC_ID                           (0x0008)
/***Control Register (Programming Mode)***/
#define BSP_SSC_CON                  		(0x0010)
#define BSP_SSC_CON_RUEN                            (1 << 12)
#define BSP_SSC_CON_TUEN                              (1 << 11)
#define BSP_SSC_CON_AEN                              (1 << 10)
#define BSP_SSC_CON_REN                              (1 << 9)
#define BSP_SSC_CON_TEN                              (1 << 8)
#define BSP_SSC_CON_LB                              (1 << 7)
#define BSP_SSC_CON_PO                              (1 << 6)
#define BSP_SSC_CON_PH                              (1 << 5)
#define BSP_SSC_CON_HB                              (1 << 4)
#define BSP_SSC_CON_BM(value)                	(((( 1 << 5) - 1) & (value)) << 16)
#define BSP_SSC_CON_RX_OFF                          (1 << 1)
#define BSP_SSC_CON_TX_OFF                          (1 << 0)
/***SCC Status Register***/
#define BSP_SSC_STATE                  (0x0014)
#define BSP_SSC_STATE_EN                              (1 << 0)
#define BSP_SSC_STATE_MS                              (1 << 1)
#define BSP_SSC_STATE_BSY                              (1 << 13)
#define BSP_SSC_STATE_RUE                              (1 << 12)
#define BSP_SSC_STATE_TUE                              (1 << 11)
#define BSP_SSC_STATE_AE                              (1 << 10)
#define BSP_SSC_STATE_RE                              (1 << 9)
#define BSP_SSC_STATE_TE                              (1 << 8)
#define BSP_SSC_STATE_BC(value)                (((( 1 << 5) - 1) & (value)) << 16)
/***SSC Write Hardware Modified Control Register***/
#define BSP_SSC_WHBSTATE                   ( 0x0018)
#define BSP_SSC_WHBSTATE_SETBE                          (1 << 15)
#define BSP_SSC_WHBSTATE_SETPE                          (1 << 14)
#define BSP_SSC_WHBSTATE_SETRE                          (1 << 13)
#define BSP_SSC_WHBSTATE_SETTE                          (1 << 12)
#define BSP_SSC_WHBSTATE_CLRBE                          (1 << 11)
#define BSP_SSC_WHBSTATE_CLRPE                          (1 << 10)
#define BSP_SSC_WHBSTATE_CLRRE                          (1 << 9)
#define BSP_SSC_WHBSTATE_CLRTE                          (1 << 8)
/***SSC Transmitter Buffer Register***/
#define BSP_SSC_TB                       (0x0020)
#define BSP_SSC_TB_TB_VALUE(value)          (((( 1 << 16) - 1) & (value)) << 0)
/***SSC Receiver Buffer Register***/
#define BSP_SSC_RB                       (0x0024)
#define BSP_SSC_RB_RB_VALUE(value)          (((( 1 << 16) - 1) & (value)) << 0)
/***SSC Receive FIFO Control Register***/
#define BSP_SSC_RXFCON                   (0x0030)
#define BSP_SSC_RXFCON_RXFITL(value)             (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_SSC_RXFCON_RXTMEN                        (1 << 2)
#define BSP_SSC_RXFCON_RXFLU                          (1 << 1)
#define BSP_SSC_RXFCON_RXFEN                          (1 << 0)
/***SSC Transmit FIFO Control Register***/
#define BSP_SSC_TXFCON                   ( 0x0034)
#define BSP_SSC_TXFCON_RXFITL(value)             (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_SSC_TXFCON_TXTMEN                        (1 << 2)
#define BSP_SSC_TXFCON_TXFLU                          (1 << 1)
#define BSP_SSC_TXFCON_TXFEN                          (1 << 0)
/***SSC FIFO Status Register***/
#define BSP_SSC_FSTAT                    (0x0038)
#define BSP_SSC_FSTAT_TXFFL(value)              (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_SSC_FSTAT_RXFFL(value)              (((( 1 << 6) - 1) & (value)) << 0)
/***SSC Baudrate Timer Reload Register***/
#define BSP_SSC_BR                       (0x0040)
#define BSP_SSC_BR_BR_VALUE(value)          (((( 1 << 16) - 1) & (value)) << 0)
#define BSP_SSC_BRSTAT                       (0x0044)
#define BSP_SSC_SFCON                        (0x0060)
#define BSP_SSC_SFSTAT                       (0x0064)
#define BSP_SSC_GPOCON                       (0x0070)
#define BSP_SSC_GPOSTAT                      (0x0074)
#define BSP_SSC_WHBGPOSTAT                   (0x0078)
#define BSP_SSC_RXREQ                        (0x0080)
#define BSP_SSC_RXCNT                        (0x0084) 
/*DMA Registers in Bus Clock Domain*/ 
#define BSP_SSC_DMA_CON                      (0x00EC)
/*interrupt Node Registers in Bus Clock Domain*/
#define BSP_SSC_IRNEN                        (0x00F4)
#define BSP_SSC_IRNCR                        (0x00F8)
#define BSP_SSC_IRNICR                       (0x00FC)
#define BSP_SSC_IRN_FIR			0x8
#define BSP_SSC_IRN_EIR			0x4
#define BSP_SSC_IRN_RIR			0x2
#define BSP_SSC_IRN_TIR			0x1


#define	BSP_SSC1_CLC			((volatile u32*)(BSP_SSC1+BSP_SSC_CLC))
#define	BSP_SSC1_ID			((volatile u32*)(BSP_SSC1+BSP_SSC_ID))
#define	BSP_SSC1_CON			((volatile u32*)(BSP_SSC1+BSP_SSC_CON))
#define	BSP_SSC1_STATE			((volatile u32*)(BSP_SSC1+BSP_SSC_STATE))
#define	BSP_SSC1_WHBSTATE			((volatile u32*)(BSP_SSC1+BSP_SSC_WHBSTATE))
#define	BSP_SSC1_TB			((volatile u32*)(BSP_SSC1+BSP_SSC_TB))
#define	BSP_SSC1_RB			((volatile u32*)(BSP_SSC1+BSP_SSC_RB))
#define	BSP_SSC1_FSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_FSTAT))
#define	BSP_SSC1_PISEL			((volatile u32*)(BSP_SSC1+BSP_SSC_PISEL))
#define	BSP_SSC1_RXFCON			((volatile u32*)(BSP_SSC1+BSP_SSC_RXFCON))
#define	BSP_SSC1_TXFCON			((volatile u32*)(BSP_SSC1+BSP_SSC_TXFCON))
#define	BSP_SSC1_BR			((volatile u32*)(BSP_SSC1+BSP_SSC_BR))
#define	BSP_SSC1_BRSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_BRSTAT))
#define	BSP_SSC1_SFCON			((volatile u32*)(BSP_SSC1+BSP_SSC_SFCON))
#define	BSP_SSC1_SFSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_SFSTAT))
#define	BSP_SSC1_GPOCON			((volatile u32*)(BSP_SSC1+BSP_SSC_GPOCON))
#define	BSP_SSC1_GPOSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_GPOSTAT))
#define	BSP_SSC1_WHBGPOSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_WHBGPOSTAT))
#define	BSP_SSC1_RXREQ			((volatile u32*)(BSP_SSC1+BSP_SSC_RXREQ))
#define	BSP_SSC1_RXCNT			((volatile u32*)(BSP_SSC1+BSP_SSC_RXCNT))
#define	BSP_SSC1_DMA_CON			((volatile u32*)(BSP_SSC1+BSP_SSC_DMA_CON))
#define	BSP_SSC1_IRNEN			((volatile u32*)(BSP_SSC1+BSP_SSC_IRNEN))
#define	BSP_SSC1_IRNICR			((volatile u32*)(BSP_SSC1+BSP_SSC_IRNICR))
#define	BSP_SSC1_IRNCR			((volatile u32*)(BSP_SSC1+BSP_SSC_IRNCR))

/***********************************************************************/
/*  Module      :  GPIO register address and bits                       */
/***********************************************************************/
#define BSP_GPIO                     (0xBE100B00)
/***Port 0 Data Output Register (0010H)***/
#define BSP_GPIO_P0_OUT              ((volatile u32 *)(BSP_GPIO+ 0x0010))
/***Port 1 Data Output Register (0040H)***/
#define BSP_GPIO_P1_OUT              ((volatile u32 *)(BSP_GPIO+ 0x0040))
/***Port 2 Data Output Register (0070H)***/
#define BSP_GPIO_P2_OUT              ((volatile u32 *)(BSP_GPIO+ 0x0070))
/***Port 3 Data Output Register (00A0H)***/
#define BSP_GPIO_P3_OUT              ((volatile u32 *)(BSP_GPIO+ 0x00A0))
/***Port 0 Data Input Register (0014H)***/
#define BSP_GPIO_P0_IN               ((volatile u32 *)(BSP_GPIO+ 0x0014))
/***Port 1 Data Input Register (0044H)***/
#define BSP_GPIO_P1_IN               ((volatile u32 *)(BSP_GPIO+ 0x0044))
/***Port 2 Data Input Register (0074H)***/
#define BSP_GPIO_P2_IN               ((volatile u32 *)(BSP_GPIO+ 0x0074))
/***Port 3 Data Input Register (00A4H)***/
#define BSP_GPIO_P3_IN               ((volatile u32 *)(BSP_GPIO+ 0x00A4))
/***Port 0 Direction Register (0018H)***/
#define BSP_GPIO_P0_DIR              ((volatile u32 *)(BSP_GPIO+ 0x0018))
/***Port 1 Direction Register (0048H)***/
#define BSP_GPIO_P1_DIR              ((volatile u32 *)(BSP_GPIO+ 0x0048))
/***Port 2 Direction Register (0078H)***/
#define BSP_GPIO_P2_DIR              ((volatile u32 *)(BSP_GPIO+ 0x0078))
/***Port 3 Direction Register (00A8H)***/
#define BSP_GPIO_P3_DIR              ((volatile u32 *)(BSP_GPIO+ 0x00A8))
/***Port 0 Alternate Function Select Register 0 (001C H) ***/
#define BSP_GPIO_P0_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x001C))
/***Port 1 Alternate Function Select Register 0 (004C H) ***/
#define BSP_GPIO_P1_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x004C))
/***Port 2 Alternate Function Select Register 0 (007C H) ***/
#define BSP_GPIO_P2_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x007C))
/***Port 3 Alternate Function Select Register 0 (00AC H) ***/
#define BSP_GPIO_P3_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x00AC))
/***Port 0 Alternate Function Select Register 1 (0020 H) ***/
#define BSP_GPIO_P0_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0020))
/***Port 1 Alternate Function Select Register 0 (0050 H) ***/
#define BSP_GPIO_P1_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0050))
/***Port 2 Alternate Function Select Register 1 (0080 H) ***/
#define BSP_GPIO_P2_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0080))
/***Port 3 Alternate Function Select Register 0 (0064 H) ***/
#define BSP_GPIO_P3_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0064))
/***Port 0 Open Drain Control Register (0024H)***/
#define BSP_GPIO_P0_OD               ((volatile u32 *)(BSP_GPIO+ 0x0024))
/***Port 1 Open Drain Control Register (0054H)***/
#define BSP_GPIO_P1_OD               ((volatile u32 *)(BSP_GPIO+ 0x0054))
/***Port 2 Open Drain Control Register (0084H)***/
#define BSP_GPIO_P2_OD               ((volatile u32 *)(BSP_GPIO+ 0x0084))
/***Port 3 Open Drain Control Register (0034H)***/
#define BSP_GPIO_P3_OD               ((volatile u32 *)(BSP_GPIO+ 0x0034))
/***Port 0 Input Schmitt-Trigger Off Register (0028 H) ***/
#define BSP_GPIO_P0_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0028))
/***Port 1 Input Schmitt-Trigger Off Register (0058 H) ***/
#define BSP_GPIO_P1_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0058))
/***Port 2 Input Schmitt-Trigger Off Register (0088 H) ***/
#define BSP_GPIO_P2_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0088))
/***Port 3 Input Schmitt-Trigger Off Register (0094 H) ***/
//#define BSP_GPIO_P3_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0094))
/***Port 0 Pull Up/Pull Down Select Register (002C H)***/
#define BSP_GPIO_P0_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x002C))
/***Port 1 Pull Up/Pull Down Select Register (005C H)***/
#define BSP_GPIO_P1_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x005C))
/***Port 2 Pull Up/Pull Down Select Register (008C H)***/
#define BSP_GPIO_P2_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x008C))
/***Port 3 Pull Up/Pull Down Select Register (0038 H)***/
#define BSP_GPIO_P3_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x0038))
/***Port 0 Pull Up Device Enable Register (0030 H)***/
#define BSP_GPIO_P0_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x0030))
/***Port 1 Pull Up Device Enable Register (0060 H)***/
#define BSP_GPIO_P1_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x0060))
/***Port 2 Pull Up Device Enable Register (0090 H)***/
#define BSP_GPIO_P2_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x0090))
/***Port 3 Pull Up Device Enable Register (003C H)***/
#define BSP_GPIO_P3_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x003C))

/***********************************************************************/
/*  Module      :  CGU register address and bits                       */
/***********************************************************************/
#if 0
#define BSP_CGU                          (0xBF103000)

/* CGU Interface clock */
#define BSP_CGU_CLKFSR                         ((volatile u32*)(BSP_CGU+ 0x0010))
#define BSP_IF_CLK                             ((volatile u32*)(BSP_CGU+ 0x0024))
/***CGU PCIE Clock Control Register**/
#define BSP_CGU_PCICR                          ((volatile u32*)(BSP_CGU+ 0x0034))
#define CLOCK_60M                60000000
#define CLOCK_83M                83333333
#define CLOCK_111M               111111111
#define CLOCK_133M               133333333
#define CLOCK_167M               166666667             
#define CLOCK_333M               333333333
#endif

#define BSP_CGU_OFFSET  (0xBF103000)
#define BSP_PLL0_CFG    ((volatile u32*)(BSP_CGU_OFFSET + 0x0004))
#define BSP_PLL1_CFG    ((volatile u32*)(BSP_CGU_OFFSET + 0x0008))
#define BSP_CGU_SYS     ((volatile u32*)(BSP_CGU_OFFSET + 0x000C))
#define BSP_CGU_CLKFSR  ((volatile u32*)(BSP_CGU_OFFSET + 0x0010))
#define BSP_CGU_CLKGSR  ((volatile u32*)(BSP_CGU_OFFSET + 0x0014))
#define BSP_CGU_CLKGCR0 ((volatile u32*)(BSP_CGU_OFFSET + 0x0018))
#define BSP_CGU_CLKGCR1 ((volatile u32*)(BSP_CGU_OFFSET + 0x001C))
#define BSP_CGU_UPDATE  ((volatile u32*)(BSP_CGU_OFFSET + 0x0020))
#define BSP_IF_CLK      ((volatile u32*)(BSP_CGU_OFFSET + 0x0024))
#define BSP_CGU_DDR     ((volatile u32*)(BSP_CGU_OFFSET + 0x0028))
#define BSP_CGU_CT1SR   ((volatile u32*)(BSP_CGU_OFFSET + 0x002C))
#define BSP_CGU_CT_KVAL ((volatile u32*)(BSP_CGU_OFFSET + 0x0030))
#define BSP_CGU_PCMCR   ((volatile u32*)(BSP_CGU_OFFSET + 0x0034))
#define BSP_PCI_CR      ((volatile u32*)(BSP_CGU_OFFSET + 0x0038))
#define BSP_GPHY1_Cfg   ((volatile u32*)(BSP_CGU_OFFSET + 0x0040))
#define BSP_GPHY0_Cfg   ((volatile u32*)(BSP_CGU_OFFSET + 0x004C))
#define BSP_PLL2_CFG    ((volatile u32*)(BSP_CGU_OFFSET + 0x0060))

/***********************************************************************/
/*  Module      :  MCD register address and bits                       */
/***********************************************************************/
#define BSP_MCD                          		(KSEG1+0x1F106000)

/***Manufacturer Identification Register***/ 
#define BSP_MCD_MANID                        	((volatile u32*)(BSP_MCD+ 0x0024))
#define BSP_MCD_MANID_MANUF(value)              	(((( 1 << 11) - 1) & (value)) << 5)

/***Chip Identification Register***/ 
#define BSP_MCD_CHIPID                       	((volatile u32*)(BSP_MCD+ 0x0028))
#define BSP_MCD_CHIPID_VERSION_GET(value)             (((value) >> 28) & ((1 << 4) - 1))
#define BSP_MCD_CHIPID_VERSION_SET(value)             (((( 1 << 4) - 1) & (value)) << 28)
#define BSP_MCD_CHIPID_PART_NUMBER_GET(value)         (((value) >> 12) & ((1 << 16) - 1))
#define BSP_MCD_CHIPID_PART_NUMBER_SET(value)         (((( 1 << 16) - 1) & (value)) << 12)
#define BSP_MCD_CHIPID_MANID_GET(value)               (((value) >> 1) & ((1 << 11) - 1))
#define BSP_MCD_CHIPID_MANID_SET(value)               (((( 1 << 11) - 1) & (value)) << 1)

#define BSP_CHIPID_STANDARD				0x00EB
#define BSP_CHIPID_YANGTSE				0x00ED

/***Redesign Tracing Identification Register***/ 
#define BSP_MCD_RTID                         	((volatile u32*)(BSP_MCD+ 0x002C))
#define BSP_MCD_RTID_LC                              (1 << 15)
#define BSP_MCD_RTID_RIX(value)                	(((( 1 << 3) - 1) & (value)) << 0)

	         
/***********************************************************************/
/*  Module      :  EBU register address and bits                       */
/***********************************************************************/

#define BSP_EBU                          (0xBE105300)

/***********************************************************************/
#define EBU_ADDR_SEL_0     (volatile u32*)(BSP_EBU + 0x20)
#define EBU_ADDR_SEL_1     (volatile u32*)(BSP_EBU + 0x24)
#define EBU_CON_0          (volatile u32*)(BSP_EBU + 0x60)
#define EBU_CON_1          (volatile u32*)(BSP_EBU + 0x64)


/***EBU Clock Control Register***/
#define BSP_EBU_CLC                      ((volatile u32*)(BSP_EBU+ 0x0000))
#define BSP_EBU_CLC_DISS                            (1 << 1)
#define BSP_EBU_CLC_DISR                            (1 << 0)

/***EBU Global Control Register***/
#define BSP_EBU_CON                      ((volatile u32*)(BSP_EBU+ 0x0010))
#define BSP_EBU_CON_DTACS (value)              (((( 1 << 3) - 1) & (value)) << 20)
#define BSP_EBU_CON_DTARW (value)              (((( 1 << 3) - 1) & (value)) << 16)
#define BSP_EBU_CON_TOUTC (value)              (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_EBU_CON_ARBMODE (value)            (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_EBU_CON_ARBSYNC                      (1 << 5)
#define BSP_EBU_CON_1                              (1 << 3)

/***EBU Address Select Register 0***/
#define BSP_EBU_ADDSEL0                  ((volatile u32*)(BSP_EBU+ 0x0020))
#define BSP_EBU_ADDSEL0_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL0_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL0_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL0_REGEN                          (1 << 0)

/***EBU Address Select Register 1***/
#define BSP_EBU_ADDSEL1                  ((volatile u32*)(BSP_EBU+ 0x0024))
#define BSP_EBU_ADDSEL1_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL1_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL1_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL1_REGEN                          (1 << 0)

/***EBU Address Select Register 2***/
#define BSP_EBU_ADDSEL2                  ((volatile u32*)(BSP_EBU+ 0x0028))
#define BSP_EBU_ADDSEL2_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL2_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL2_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL2_REGEN                          (1 << 0)

/***EBU Address Select Register 3***/
#define BSP_EBU_ADDSEL3                  ((volatile u32*)(BSP_EBU+ 0x0028))
#define BSP_EBU_ADDSEL3_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL3_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL3_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL3_REGEN                          (1 << 0)

/***EBU Bus Configuration Register 0***/
#define BSP_EBU_BUSCON0                  ((volatile u32*)(BSP_EBU+ 0x0060))
#define BSP_EBU_BUSCON0_WRDIS                          (1 << 31)
#define BSP_EBU_BUSCON0_ALEC (value)               (((( 1 << 2) - 1) & (value)) << 29)
#define BSP_EBU_BUSCON0_BCGEN (value)              (((( 1 << 2) - 1) & (value)) << 27)
#define BSP_EBU_BUSCON0_AGEN (value)               (((( 1 << 2) - 1) & (value)) << 24)
#define BSP_EBU_BUSCON0_CMULTR (value)             (((( 1 << 2) - 1) & (value)) << 22)
#define BSP_EBU_BUSCON0_WAIT (value)               (((( 1 << 2) - 1) & (value)) << 20)
#define BSP_EBU_BUSCON0_WAITINV                      (1 << 19)
#define BSP_EBU_BUSCON0_SETUP                          (1 << 18)
#define BSP_EBU_BUSCON0_PORTW (value)              (((( 1 << 2) - 1) & (value)) << 16)
#define BSP_EBU_BUSCON0_WAITRDC (value)            (((( 1 << 7) - 1) & (value)) << 9)
#define BSP_EBU_BUSCON0_WAITWRC (value)            (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_EBU_BUSCON0_HOLDC (value)              (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_EBU_BUSCON0_RECOVC (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_EBU_BUSCON0_CMULT (value)              (((( 1 << 2) - 1) & (value)) << 0)

/***EBU Bus Configuration Register 1***/
#define BSP_EBU_BUSCON1                  ((volatile u32*)(BSP_EBU+ 0x0064))
#define BSP_EBU_BUSCON1_WRDIS                          (1 << 31)
#define BSP_EBU_BUSCON1_ALEC (value)               (((( 1 << 2) - 1) & (value)) << 29)
#define BSP_EBU_BUSCON1_BCGEN (value)              (((( 1 << 2) - 1) & (value)) << 27)
#define BSP_EBU_BUSCON1_AGEN (value)               (((( 1 << 2) - 1) & (value)) << 24)
#define BSP_EBU_BUSCON1_CMULTR (value)             (((( 1 << 2) - 1) & (value)) << 22)
#define BSP_EBU_BUSCON1_WAIT (value)               (((( 1 << 2) - 1) & (value)) << 20)
#define BSP_EBU_BUSCON1_WAITINV                      (1 << 19)
#define BSP_EBU_BUSCON1_SETUP                          (1 << 18)
#define BSP_EBU_BUSCON1_PORTW (value)              (((( 1 << 2) - 1) & (value)) << 16)
#define BSP_EBU_BUSCON1_WAITRDC (value)            (((( 1 << 7) - 1) & (value)) << 9)
#define BSP_EBU_BUSCON1_WAITWRC (value)            (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_EBU_BUSCON1_HOLDC (value)              (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_EBU_BUSCON1_RECOVC (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_EBU_BUSCON1_CMULT (value)              (((( 1 << 2) - 1) & (value)) << 0)

/***EBU Bus Configuration Register 2***/
#define BSP_EBU_BUSCON2                  ((volatile u32*)(BSP_EBU+ 0x0068))
#define BSP_EBU_BUSCON2_WRDIS                          (1 << 31)
#define BSP_EBU_BUSCON2_ALEC (value)               (((( 1 << 2) - 1) & (value)) << 29)
#define BSP_EBU_BUSCON2_BCGEN (value)              (((( 1 << 2) - 1) & (value)) << 27)
#define BSP_EBU_BUSCON2_AGEN (value)               (((( 1 << 2) - 1) & (value)) << 24)
#define BSP_EBU_BUSCON2_CMULTR (value)             (((( 1 << 2) - 1) & (value)) << 22)
#define BSP_EBU_BUSCON2_WAIT (value)               (((( 1 << 2) - 1) & (value)) << 20)
#define BSP_EBU_BUSCON2_WAITINV                      (1 << 19)
#define BSP_EBU_BUSCON2_SETUP                          (1 << 18)
#define BSP_EBU_BUSCON2_PORTW (value)              (((( 1 << 2) - 1) & (value)) << 16)
#define BSP_EBU_BUSCON2_WAITRDC (value)            (((( 1 << 7) - 1) & (value)) << 9)
#define BSP_EBU_BUSCON2_WAITWRC (value)            (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_EBU_BUSCON2_HOLDC (value)              (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_EBU_BUSCON2_RECOVC (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_EBU_BUSCON2_CMULT (value)              (((( 1 << 2) - 1) & (value)) << 0)

#define BSP_EBU_PCC_CON                  ((volatile u32*)(BSP_EBU+ 0x0090))
#define BSP_EBU_PCC_STAT                  ((volatile u32*)(BSP_EBU+ 0x0094))
#define BSP_EBU_PCC_ISTAT                  ((volatile u32*)(BSP_EBU+ 0x00A0))
#define BSP_EBU_PCC_IEN                  ((volatile u32*)(BSP_EBU+ 0x00A4))
/***********************************************************************/
/*  Module      :  SDRAM register address and bits                     */
/***********************************************************************/

#define BSP_SDRAM                        (0xBF800000)
/***********************************************************************/


/***MC Access Error Cause Register***/
#define BSP_SDRAM_MC_ERRCAUSE                  ((volatile u32*)(BSP_SDRAM+ 0x0100))
#define BSP_SDRAM_MC_ERRCAUSE_ERR                              (1 << 31)
#define BSP_SDRAM_MC_ERRCAUSE_PORT (value)               (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_SDRAM_MC_ERRCAUSE_CAUSE (value)              (((( 1 << 2) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_ERRCAUSE_Res (value)                (((( 1 << NaN) - 1) & (value)) << NaN)

/***MC Access Error Address Register***/
#define BSP_SDRAM_MC_ERRADDR                   ((volatile u32*)(BSP_SDRAM+ 0x0108))
#define BSP_SDRAM_MC_ERRADDR_ADDR

/***MC I/O General Purpose Register***/
#define BSP_SDRAM_MC_IOGP                      ((volatile u32*)(BSP_SDRAM+ 0x0800))
#define BSP_SDRAM_MC_IOGP_GPR6 (value)               (((( 1 << 4) - 1) & (value)) << 28)
#define BSP_SDRAM_MC_IOGP_GPR5 (value)               (((( 1 << 4) - 1) & (value)) << 24)
#define BSP_SDRAM_MC_IOGP_GPR4 (value)               (((( 1 << 4) - 1) & (value)) << 20)
#define BSP_SDRAM_MC_IOGP_GPR3 (value)               (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_SDRAM_MC_IOGP_GPR2 (value)               (((( 1 << 4) - 1) & (value)) << 12)
#define BSP_SDRAM_MC_IOGP_CPS                              (1 << 11)
#define BSP_SDRAM_MC_IOGP_CLKDELAY (value)          (((( 1 << 3) - 1) & (value)) << 8)
#define BSP_SDRAM_MC_IOGP_CLKRAT (value)             (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_IOGP_RDDEL (value)              (((( 1 << 4) - 1) & (value)) << 0)

/***MC Self Refresh Register***/
#define BSP_SDRAM_MC_SELFRFSH                  ((volatile u32*)(BSP_SDRAM+ 0x0A00))
#define BSP_SDRAM_MC_SELFRFSH_PWDS                            (1 << 1)
#define BSP_SDRAM_MC_SELFRFSH_PWD                              (1 << 0)
#define BSP_SDRAM_MC_SELFRFSH_Res (value)                (((( 1 << 30) - 1) & (value)) << 2)

/***MC Enable Register***/
#define BSP_SDRAM_MC_CTRLENA                   ((volatile u32*)(BSP_SDRAM+ 0x1000))
#define BSP_SDRAM_MC_CTRLENA_ENA                              (1 << 0)
#define BSP_SDRAM_MC_CTRLENA_Res (value)                (((( 1 << 31) - 1) & (value)) << 1)

/***MC Mode Register Setup Code***/
#define BSP_SDRAM_MC_MRSCODE                   ((volatile u32*)(BSP_SDRAM+ 0x1008))
#define BSP_SDRAM_MC_MRSCODE_UMC (value)                (((( 1 << 5) - 1) & (value)) << 7)
#define BSP_SDRAM_MC_MRSCODE_CL (value)                (((( 1 << 3) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_MRSCODE_WT                              (1 << 3)
#define BSP_SDRAM_MC_MRSCODE_BL (value)                (((( 1 << 3) - 1) & (value)) << 0)

/***MC Configuration Data-word Width Register***/
#define BSP_SDRAM_MC_CFGDW                    ((volatile u32*)(BSP_SDRAM+ 0x1010))
#define BSP_SDRAM_MC_CFGDW_DW (value)                (((( 1 << 4) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_CFGDW_Res (value)                (((( 1 << 28) - 1) & (value)) << 4)

/***MC Configuration Physical Bank 0 Register***/
#define BSP_SDRAM_MC_CFGPB0                    ((volatile u32*)(BSP_SDRAM+ 0x1018))
#define BSP_SDRAM_MC_CFGPB0_MCSEN0 (value)             (((( 1 << 4) - 1) & (value)) << 12)
#define BSP_SDRAM_MC_CFGPB0_BANKN0 (value)             (((( 1 << 4) - 1) & (value)) << 8)
#define BSP_SDRAM_MC_CFGPB0_ROWW0 (value)              (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_CFGPB0_COLW0 (value)              (((( 1 << 4) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_CFGPB0_Res (value)                (((( 1 << 16) - 1) & (value)) << 16)

/***MC Latency Register***/
#define BSP_SDRAM_MC_LATENCY                   ((volatile u32*)(BSP_SDRAM+ 0x1038))
#define BSP_SDRAM_MC_LATENCY_TRP (value)                (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_SDRAM_MC_LATENCY_TRAS (value)               (((( 1 << 4) - 1) & (value)) << 12)
#define BSP_SDRAM_MC_LATENCY_TRCD (value)               (((( 1 << 4) - 1) & (value)) << 8)
#define BSP_SDRAM_MC_LATENCY_TDPL (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_LATENCY_TDAL (value)               (((( 1 << 4) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_LATENCY_Res (value)                (((( 1 << 12) - 1) & (value)) << 20)

/***MC Refresh Cycle Time Register***/
#define BSP_SDRAM_MC_TREFRESH                  ((volatile u32*)(BSP_SDRAM+ 0x1040))
#define BSP_SDRAM_MC_TREFRESH_TREF (value)               (((( 1 << 13) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_TREFRESH_Res (value)                (((( 1 << 19) - 1) & (value)) << 13)


/***********************************************************************/
/*  Module      :  GPTC register address and bits                       */
/***********************************************************************/

#define BSP_GPTC                   (KSEG1 + 0x1E100A00)
#define BSP_GPTC_CLC               ((volatile u32*) (BSP_GPTC + 0x0000))
#define BSP_GPTC_ID                ((volatile u32*) (BSP_GPTC + 0x0008))
#define BSP_GPTC_IRNEN             ((volatile u32*) (BSP_GPTC + 0x00F4))
#define BSP_GPTC_IRNICR    		((volatile u32*) (BSP_GPTC + 0x00F8)
#define BSP_GPTC_IRNCR             ((volatile u32*) (BSP_GPTC + 0x00FC))

#define BSP_GPTC_CON_1A    ((volatile u32*) (BSP_GPTC + 0x0010))
#define BSP_GPTC_RUN_1A    ((volatile u32*) (BSP_GPTC + 0x0018))
#define BSP_GPTC_RELOAD_1A ((volatile u32*) (BSP_GPTC + 0x0020))
#define BSP_GPTC_COUNT_1A  ((volatile u32*) (BSP_GPTC + 0x0028))

#define BSP_GPTC_CON_1B    ((volatile u32*) (BSP_GPTC + 0x0014))
#define BSP_GPTC_RUN_1B    ((volatile u32*) (BSP_GPTC + 0x001C))
#define BSP_GPTC_RELOAD_1B ((volatile u32*) (BSP_GPTC + 0x0024))
#define BSP_GPTC_COUNT_1B  ((volatile u32*) (BSP_GPTC + 0x002C))

#define BSP_GPTC_CON_2A    ((volatile u32*) (BSP_GPTC + 0x0030))
#define BSP_GPTC_RUN_2A    ((volatile u32*) (BSP_GPTC + 0x0038))
#define BSP_GPTC_RELOAD_2A ((volatile u32*) (BSP_GPTC + 0x0040))
#define BSP_GPTC_COUNT_2A  ((volatile u32*) (BSP_GPTC + 0x0048))

#define BSP_GPTC_CON_2B    ((volatile u32*) (BSP_GPTC + 0x0034))
#define BSP_GPTC_RUN_2B    ((volatile u32*) (BSP_GPTC + 0x003C))
#define BSP_GPTC_RELOAD_2B ((volatile u32*) (BSP_GPTC + 0x0044))
#define BSP_GPTC_COUNT_2B  ((volatile u32*) (BSP_GPTC + 0x004C))

#define BSP_GPTC_CON_3A    ((volatile u32*) (BSP_GPTC + 0x0050))
#define BSP_GPTC_RUN_3A    ((volatile u32*) (BSP_GPTC + 0x0058))
#define BSP_GPTC_RELOAD_3A ((volatile u32*) (BSP_GPTC + 0x0060))
#define BSP_GPTC_COUNT_3A  ((volatile u32*) (BSP_GPTC + 0x0068))

#define BSP_GPTC_CON_3B    ((volatile u32*) (BSP_GPTC + 0x0054))
#define BSP_GPTC_RUN_3B    ((volatile u32*) (BSP_GPTC + 0x005C))
#define BSP_GPTC_RELOAD_3B ((volatile u32*) (BSP_GPTC + 0x0064))
#define BSP_GPTC_COUNT_3B  ((volatile u32*) (BSP_GPTC + 0x006C))



/***********************************************************************/
/*  Module      :  GPTU register address and bits                      */
/***********************************************************************/

#define BSP_GPTU                         (0x1E100A00 + KSEG1)
/***********************************************************************/

#define BSP_GPTU_CLC                       ((volatile u32*)(BSP_GPTU+ 0x0000))
#define BSP_GPTU_ID                        ((volatile u32*)(BSP_GPTU+ 0x0008))
#define BSP_GPTU_CON1_A                    ((volatile u32*)(BSP_GPTU+ 0x0010))
#define BSP_GPTU_CON1_B                    ((volatile u32*)(BSP_GPTU+ 0x0014))
#define BSP_GPTU_RUN1_A                    ((volatile u32*)(BSP_GPTU+ 0x0018))
#define BSP_GPTU_RUN1_B                    ((volatile u32*)(BSP_GPTU+ 0x001C))
#define BSP_GPTU_RELOAD1_A                 ((volatile u32*)(BSP_GPTU+ 0x0020))
#define BSP_GPTU_RELOAD1_B                 ((volatile u32*)(BSP_GPTU+ 0x0024))
#define BSP_GPTU_COUNT1_A                  ((volatile u32*)(BSP_GPTU+ 0x0028))
#define BSP_GPTU_COUNT1_B                  ((volatile u32*)(BSP_GPTU+ 0x002C))
#define BSP_GPTU_CON2_A                    ((volatile u32*)(BSP_GPTU+ 0x0030))
#define BSP_GPTU_CON2_B                    ((volatile u32*)(BSP_GPTU+ 0x0034))
#define BSP_GPTU_RUN2_A                    ((volatile u32*)(BSP_GPTU+ 0x0038))
#define BSP_GPTU_RUN2_B                    ((volatile u32*)(BSP_GPTU+ 0x003C))
#define BSP_GPTU_RELOAD2_A                 ((volatile u32*)(BSP_GPTU+ 0x0040))
#define BSP_GPTU_RELOAD2_B                 ((volatile u32*)(BSP_GPTU+ 0x0044))
#define BSP_GPTU_COUNT2_A                  ((volatile u32*)(BSP_GPTU+ 0x0048))
#define BSP_GPTU_COUNT2_B                  ((volatile u32*)(BSP_GPTU+ 0x004C))
#define BSP_GPTU_CON3_A                    ((volatile u32*)(BSP_GPTU+ 0x0050))
#define BSP_GPTU_CON3_B                    ((volatile u32*)(BSP_GPTU+ 0x0054))
#define BSP_GPTU_RUN3_A                    ((volatile u32*)(BSP_GPTU+ 0x0058))
#define BSP_GPTU_RUN3_B                    ((volatile u32*)(BSP_GPTU+ 0x005C))
#define BSP_GPTU_RELOAD3_A                 ((volatile u32*)(BSP_GPTU+ 0x0060))
#define BSP_GPTU_RELOAD3_B                 ((volatile u32*)(BSP_GPTU+ 0x0064))
#define BSP_GPTU_COUNT3_A                  ((volatile u32*)(BSP_GPTU+ 0x0068))
#define BSP_GPTU_COUNT3_B                  ((volatile u32*)(BSP_GPTU+ 0x006C))
#define BSP_GPTU_COUNT3_A                  ((volatile u32*)(BSP_GPTU+ 0x0068))
#define BSP_GPTU_COUNT3_B                  ((volatile u32*)(BSP_GPTU+ 0x006C))
#define BSP_GPTU_IRNEN                     ((volatile u32 *)(0xBE100AF4))
#define BSP_GPTU_IRNICR                    ((volatile u32 *)(0xBE100AF8))
#define BSP_GPTU_IRNCR                     ((volatile u32 *)(0xBE100AFC))


/***GPT Clock Control Register***/
#define BSP_GPTU_GPT_CLC                      ((volatile u32*)(BSP_GPTU+ 0x0000))
#define BSP_GPTU_GPT_CLC_RMC (value)                (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_GPTU_GPT_CLC_DISS                            (1 << 1)
#define BSP_GPTU_GPT_CLC_DISR                            (1 << 0)

/***GPT Timer 3 Control Register***/
#define BSP_GPTU_GPT_T3CON                    ((volatile u32*)(BSP_GPTU+ 0x0014))
#define BSP_GPTU_GPT_T3CON_T3RDIR                        (1 << 15)
#define BSP_GPTU_GPT_T3CON_T3CHDIR                      (1 << 14)
#define BSP_GPTU_GPT_T3CON_T3EDGE                        (1 << 13)
#define BSP_GPTU_GPT_T3CON_BPS1 (value)               (((( 1 << 2) - 1) & (value)) << 11)
#define BSP_GPTU_GPT_T3CON_T3OTL                          (1 << 10)
#define BSP_GPTU_GPT_T3CON_T3UD                            (1 << 7)
#define BSP_GPTU_GPT_T3CON_T3R                              (1 << 6)
#define BSP_GPTU_GPT_T3CON_T3M (value)                (((( 1 << 3) - 1) & (value)) << 3)
#define BSP_GPTU_GPT_T3CON_T3I (value)                (((( 1 << 3) - 1) & (value)) << 0)

/***GPT Write Hardware Modified Timer 3 Control Register
If set and clear bit are written concurrently with 1, the associated bit is not changed.***/
#define BSP_GPTU_GPT_WHBT3CON                 ((volatile u32*)(BSP_GPTU+ 0x004C))
#define BSP_GPTU_GPT_WHBT3CON_SETT3CHDIR                (1 << 15)
#define BSP_GPTU_GPT_WHBT3CON_CLRT3CHDIR                (1 << 14)
#define BSP_GPTU_GPT_WHBT3CON_SETT3EDGE                  (1 << 13)
#define BSP_GPTU_GPT_WHBT3CON_CLRT3EDGE                  (1 << 12)
#define BSP_GPTU_GPT_WHBT3CON_SETT3OTL                  (1 << 11)
#define BSP_GPTU_GPT_WHBT3CON_CLRT3OTL                  (1 << 10)

/***GPT Timer 2 Control Register***/
#define BSP_GPTU_GPT_T2CON                    ((volatile u32*)(BSP_GPTU+ 0x0010))
#define BSP_GPTU_GPT_T2CON_TxRDIR                        (1 << 15)
#define BSP_GPTU_GPT_T2CON_TxCHDIR                      (1 << 14)
#define BSP_GPTU_GPT_T2CON_TxEDGE                        (1 << 13)
#define BSP_GPTU_GPT_T2CON_TxIRDIS                      (1 << 12)
#define BSP_GPTU_GPT_T2CON_TxRC                            (1 << 9)
#define BSP_GPTU_GPT_T2CON_TxUD                            (1 << 7)
#define BSP_GPTU_GPT_T2CON_TxR                              (1 << 6)
#define BSP_GPTU_GPT_T2CON_TxM (value)                (((( 1 << 3) - 1) & (value)) << 3)
#define BSP_GPTU_GPT_T2CON_TxI (value)                (((( 1 << 3) - 1) & (value)) << 0)

/***GPT Timer 4 Control Register***/
#define BSP_GPTU_GPT_T4CON                    ((volatile u32*)(BSP_GPTU+ 0x0018))
#define BSP_GPTU_GPT_T4CON_TxRDIR                        (1 << 15)
#define BSP_GPTU_GPT_T4CON_TxCHDIR                      (1 << 14)
#define BSP_GPTU_GPT_T4CON_TxEDGE                        (1 << 13)
#define BSP_GPTU_GPT_T4CON_TxIRDIS                      (1 << 12)
#define BSP_GPTU_GPT_T4CON_TxRC                            (1 << 9)
#define BSP_GPTU_GPT_T4CON_TxUD                            (1 << 7)
#define BSP_GPTU_GPT_T4CON_TxR                              (1 << 6)
#define BSP_GPTU_GPT_T4CON_TxM (value)                (((( 1 << 3) - 1) & (value)) << 3)
#define BSP_GPTU_GPT_T4CON_TxI (value)                (((( 1 << 3) - 1) & (value)) << 0)

/***GPT Write HW Modified Timer 2 Control Register If set
 and clear bit are written concurrently with 1, the associated bit is not changed.***/
#define BSP_GPTU_GPT_WHBT2CON                 ((volatile u32*)(BSP_GPTU+ 0x0048))
#define BSP_GPTU_GPT_WHBT2CON_SETTxCHDIR                (1 << 15)
#define BSP_GPTU_GPT_WHBT2CON_CLRTxCHDIR                (1 << 14)
#define BSP_GPTU_GPT_WHBT2CON_SETTxEDGE                  (1 << 13)
#define BSP_GPTU_GPT_WHBT2CON_CLRTxEDGE                  (1 << 12)

/***GPT Write HW Modified Timer 4 Control Register If set
 and clear bit are written concurrently with 1, the associated bit is not changed.***/
#define BSP_GPTU_GPT_WHBT4CON                 ((volatile u32*)(BSP_GPTU+ 0x0050))
#define BSP_GPTU_GPT_WHBT4CON_SETTxCHDIR                (1 << 15)
#define BSP_GPTU_GPT_WHBT4CON_CLRTxCHDIR                (1 << 14)
#define BSP_GPTU_GPT_WHBT4CON_SETTxEDGE                  (1 << 13)
#define BSP_GPTU_GPT_WHBT4CON_CLRTxEDGE                  (1 << 12)

/***GPT Capture Reload Register***/
#define BSP_GPTU_GPT_CAPREL                   ((volatile u32*)(BSP_GPTU+ 0x0030))
#define BSP_GPTU_GPT_CAPREL_CAPREL (value)             (((( 1 << 16) - 1) & (value)) << 0)

/***GPT Timer 2 Register***/
#define BSP_GPTU_GPT_T2                       ((volatile u32*)(BSP_GPTU+ 0x0034))
#define BSP_GPTU_GPT_T2_TVAL (value)               (((( 1 << 16) - 1) & (value)) << 0)

/***GPT Timer 3 Register***/
#define BSP_GPTU_GPT_T3                       ((volatile u32*)(BSP_GPTU+ 0x0038))
#define BSP_GPTU_GPT_T3_TVAL (value)               (((( 1 << 16) - 1) & (value)) << 0)

/***GPT Timer 4 Register***/
#define BSP_GPTU_GPT_T4                       ((volatile u32*)(BSP_GPTU+ 0x003C))
#define BSP_GPTU_GPT_T4_TVAL (value)               (((( 1 << 16) - 1) & (value)) << 0)

/***GPT Timer 5 Register***/
#define BSP_GPTU_GPT_T5                       ((volatile u32*)(BSP_GPTU+ 0x0040))
#define BSP_GPTU_GPT_T5_TVAL (value)               (((( 1 << 16) - 1) & (value)) << 0)

/***GPT Timer 6 Register***/
#define BSP_GPTU_GPT_T6                       ((volatile u32*)(BSP_GPTU+ 0x0044))
#define BSP_GPTU_GPT_T6_TVAL (value)               (((( 1 << 16) - 1) & (value)) << 0)

/***GPT Timer 6 Control Register***/
#define BSP_GPTU_GPT_T6CON                    ((volatile u32*)(BSP_GPTU+ 0x0020))
#define BSP_GPTU_GPT_T6CON_T6SR                            (1 << 15)
#define BSP_GPTU_GPT_T6CON_T6CLR                          (1 << 14)
#define BSP_GPTU_GPT_T6CON_BPS2 (value)               (((( 1 << 2) - 1) & (value)) << 11)
#define BSP_GPTU_GPT_T6CON_T6OTL                          (1 << 10)
#define BSP_GPTU_GPT_T6CON_T6UD                            (1 << 7)
#define BSP_GPTU_GPT_T6CON_T6R                              (1 << 6)
#define BSP_GPTU_GPT_T6CON_T6M (value)                (((( 1 << 3) - 1) & (value)) << 3)
#define BSP_GPTU_GPT_T6CON_T6I (value)                (((( 1 << 3) - 1) & (value)) << 0)

/***GPT Write HW Modified Timer 6 Control Register If set
 and clear bit are written concurrently with 1, the associated bit is not changed.***/
#define BSP_GPTU_GPT_WHBT6CON                 ((volatile u32*)(BSP_GPTU+ 0x0054))
#define BSP_GPTU_GPT_WHBT6CON_SETT6OTL                  (1 << 11)
#define BSP_GPTU_GPT_WHBT6CON_CLRT6OTL                  (1 << 10)

/***GPT Timer 5 Control Register***/
#define BSP_GPTU_GPT_T5CON                    ((volatile u32*)(BSP_GPTU+ 0x001C))
#define BSP_GPTU_GPT_T5CON_T5SC                            (1 << 15)
#define BSP_GPTU_GPT_T5CON_T5CLR                          (1 << 14)
#define BSP_GPTU_GPT_T5CON_CI (value)                (((( 1 << 2) - 1) & (value)) << 12)
#define BSP_GPTU_GPT_T5CON_T5CC                            (1 << 11)
#define BSP_GPTU_GPT_T5CON_CT3                              (1 << 10)
#define BSP_GPTU_GPT_T5CON_T5RC                            (1 << 9)
#define BSP_GPTU_GPT_T5CON_T5UDE                          (1 << 8)
#define BSP_GPTU_GPT_T5CON_T5UD                            (1 << 7)
#define BSP_GPTU_GPT_T5CON_T5R                              (1 << 6)
#define BSP_GPTU_GPT_T5CON_T5M (value)                (((( 1 << 3) - 1) & (value)) << 3)
#define BSP_GPTU_GPT_T5CON_T5I (value)                (((( 1 << 3) - 1) & (value)) << 0)


/***********************************************************************/
/*  Module      :  IOM register address and bits                       */
/***********************************************************************/

#define BSP_IOM                          (0xBF105000)
/***********************************************************************/


/***Receive FIFO***/
#define BSP_IOM_RFIFO                        ((volatile u32*)(BSP_IOM+ 0x0000))
#define BSP_IOM_RFIFO_RXD (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Transmit FIFO***/
#define BSP_IOM_XFIFO                        ((volatile u32*)(BSP_IOM+ 0x0000))
#define BSP_IOM_XFIFO_TXD (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Interrupt Status Register HDLC***/
#define BSP_IOM_ISTAH                        ((volatile u32*)(BSP_IOM+ 0x0080))
#define BSP_IOM_ISTAH_RME                              (1 << 7)
#define BSP_IOM_ISTAH_RPF                              (1 << 6)
#define BSP_IOM_ISTAH_RFO                              (1 << 5)
#define BSP_IOM_ISTAH_XPR                              (1 << 4)
#define BSP_IOM_ISTAH_XMR                              (1 << 3)
#define BSP_IOM_ISTAH_XDU                              (1 << 2)

/***Interrupt Mask Register HDLC***/
#define BSP_IOM_MASKH                        ((volatile u32*)(BSP_IOM+ 0x0080))
#define BSP_IOM_MASKH_RME                              (1 << 7)
#define BSP_IOM_MASKH_RPF                              (1 << 6)
#define BSP_IOM_MASKH_RFO                              (1 << 5)
#define BSP_IOM_MASKH_XPR                              (1 << 4)
#define BSP_IOM_MASKH_XMR                              (1 << 3)
#define BSP_IOM_MASKH_XDU                              (1 << 2)

/***Status Register***/
#define BSP_IOM_STAR                         ((volatile u32*)(BSP_IOM+ 0x0084))
#define BSP_IOM_STAR_XDOV                            (1 << 7)
#define BSP_IOM_STAR_XFW                              (1 << 6)
#define BSP_IOM_STAR_RACI                            (1 << 3)
#define BSP_IOM_STAR_XACI                            (1 << 1)

/***Command Register***/
#define BSP_IOM_CMDR                         ((volatile u32*)(BSP_IOM+ 0x0084))
#define BSP_IOM_CMDR_RMC                              (1 << 7)
#define BSP_IOM_CMDR_RRES                            (1 << 6)
#define BSP_IOM_CMDR_XTF                              (1 << 3)
#define BSP_IOM_CMDR_XME                              (1 << 1)
#define BSP_IOM_CMDR_XRES                            (1 << 0)

/***Mode Register***/
#define BSP_IOM_MODEH                        ((volatile u32*)(BSP_IOM+ 0x0088))
#define BSP_IOM_MODEH_MDS2                            (1 << 7)
#define BSP_IOM_MODEH_MDS1                            (1 << 6)
#define BSP_IOM_MODEH_MDS0                            (1 << 5)
#define BSP_IOM_MODEH_RAC                              (1 << 3)
#define BSP_IOM_MODEH_DIM2                            (1 << 2)
#define BSP_IOM_MODEH_DIM1                            (1 << 1)
#define BSP_IOM_MODEH_DIM0                            (1 << 0)

/***Extended Mode Register***/
#define BSP_IOM_EXMR                         ((volatile u32*)(BSP_IOM+ 0x008C))
#define BSP_IOM_EXMR_XFBS                            (1 << 7)
#define BSP_IOM_EXMR_RFBS (value)               (((( 1 << 2) - 1) & (value)) << 5)
#define BSP_IOM_EXMR_SRA                              (1 << 4)
#define BSP_IOM_EXMR_XCRC                            (1 << 3)
#define BSP_IOM_EXMR_RCRC                            (1 << 2)
#define BSP_IOM_EXMR_ITF                              (1 << 0)

/***SAPI1 Register***/
#define BSP_IOM_SAP1                         ((volatile u32*)(BSP_IOM+ 0x0094))
#define BSP_IOM_SAP1_SAPI1 (value)              (((( 1 << 6) - 1) & (value)) << 2)
#define BSP_IOM_SAP1_MHA                              (1 << 0)

/***Receive Frame Byte Count Low***/
#define BSP_IOM_RBCL                         ((volatile u32*)(BSP_IOM+ 0x0098))
#define BSP_IOM_RBCL_RBC(value)              (1 << value)


/***SAPI2 Register***/
#define BSP_IOM_SAP2                         ((volatile u32*)(BSP_IOM+ 0x0098))
#define BSP_IOM_SAP2_SAPI2 (value)              (((( 1 << 6) - 1) & (value)) << 2)
#define BSP_IOM_SAP2_MLA                              (1 << 0)

/***Receive Frame Byte Count High***/
#define BSP_IOM_RBCH                         ((volatile u32*)(BSP_IOM+ 0x009C))
#define BSP_IOM_RBCH_OV                              (1 << 4)
#define BSP_IOM_RBCH_RBC11                          (1 << 3)
#define BSP_IOM_RBCH_RBC10                          (1 << 2)
#define BSP_IOM_RBCH_RBC9                            (1 << 1)
#define BSP_IOM_RBCH_RBC8                            (1 << 0)

/***TEI1 Register 1***/
#define BSP_IOM_TEI1                         ((volatile u32*)(BSP_IOM+ 0x009C))
#define BSP_IOM_TEI1_TEI1 (value)               (((( 1 << 7) - 1) & (value)) << 1)
#define BSP_IOM_TEI1_EA                              (1 << 0)

/***Receive Status Register***/
#define BSP_IOM_RSTA                         ((volatile u32*)(BSP_IOM+ 0x00A0))
#define BSP_IOM_RSTA_VFR                              (1 << 7)
#define BSP_IOM_RSTA_RDO                              (1 << 6)
#define BSP_IOM_RSTA_CRC                              (1 << 5)
#define BSP_IOM_RSTA_RAB                              (1 << 4)
#define BSP_IOM_RSTA_SA1                              (1 << 3)
#define BSP_IOM_RSTA_SA0                              (1 << 2)
#define BSP_IOM_RSTA_TA                              (1 << 0)
#define BSP_IOM_RSTA_CR                              (1 << 1)

/***TEI2 Register***/
#define BSP_IOM_TEI2                         ((volatile u32*)(BSP_IOM+ 0x00A0))
#define BSP_IOM_TEI2_TEI2 (value)               (((( 1 << 7) - 1) & (value)) << 1)
#define BSP_IOM_TEI2_EA                              (1 << 0)

/***Test Mode Register HDLC***/
#define BSP_IOM_TMH                          ((volatile u32*)(BSP_IOM+ 0x00A4))
#define BSP_IOM_TMH_TLP                              (1 << 0)

/***Command/Indication Receive 0***/
#define BSP_IOM_CIR0                         ((volatile u32*)(BSP_IOM+ 0x00B8))
#define BSP_IOM_CIR0_CODR0 (value)              (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_IOM_CIR0_CIC0                            (1 << 3)
#define BSP_IOM_CIR0_CIC1                            (1 << 2)
#define BSP_IOM_CIR0_SG                              (1 << 1)
#define BSP_IOM_CIR0_BAS                              (1 << 0)

/***Command/Indication Transmit 0***/
#define BSP_IOM_CIX0                         ((volatile u32*)(BSP_IOM+ 0x00B8))
#define BSP_IOM_CIX0_CODX0 (value)              (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_IOM_CIX0_TBA2                            (1 << 3)
#define BSP_IOM_CIX0_TBA1                            (1 << 2)
#define BSP_IOM_CIX0_TBA0                            (1 << 1)
#define BSP_IOM_CIX0_BAC                              (1 << 0)

/***Command/Indication Receive 1***/
#define BSP_IOM_CIR1                         ((volatile u32*)(BSP_IOM+ 0x00BC))
#define BSP_IOM_CIR1_CODR1 (value)              (((( 1 << 6) - 1) & (value)) << 2)

/***Command/Indication Transmit 1***/
#define BSP_IOM_CIX1                         ((volatile u32*)(BSP_IOM+ 0x00BC))
#define BSP_IOM_CIX1_CODX1 (value)              (((( 1 << 6) - 1) & (value)) << 2)
#define BSP_IOM_CIX1_CICW                            (1 << 1)
#define BSP_IOM_CIX1_CI1E                            (1 << 0)

/***Controller Data Access Reg. (CH10)***/
#define BSP_IOM_CDA10                        ((volatile u32*)(BSP_IOM+ 0x0100))
#define BSP_IOM_CDA10_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Controller Data Access Reg. (CH11)***/
#define BSP_IOM_CDA11                        ((volatile u32*)(BSP_IOM+ 0x0104))
#define BSP_IOM_CDA11_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Controller Data Access Reg. (CH20)***/
#define BSP_IOM_CDA20                        ((volatile u32*)(BSP_IOM+ 0x0108))
#define BSP_IOM_CDA20_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Controller Data Access Reg. (CH21)***/
#define BSP_IOM_CDA21                        ((volatile u32*)(BSP_IOM+ 0x010C))
#define BSP_IOM_CDA21_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH10)***/
#define BSP_IOM_CDA_TSDP10                   ((volatile u32*)(BSP_IOM+ 0x0110))
#define BSP_IOM_CDA_TSDP10_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP10_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH11)***/
#define BSP_IOM_CDA_TSDP11                   ((volatile u32*)(BSP_IOM+ 0x0114))
#define BSP_IOM_CDA_TSDP11_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP11_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH20)***/
#define BSP_IOM_CDA_TSDP20                   ((volatile u32*)(BSP_IOM+ 0x0118))
#define BSP_IOM_CDA_TSDP20_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP20_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH21)***/
#define BSP_IOM_CDA_TSDP21                   ((volatile u32*)(BSP_IOM+ 0x011C))
#define BSP_IOM_CDA_TSDP21_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP21_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH10)***/
#define BSP_IOM_CO_TSDP10                    ((volatile u32*)(BSP_IOM+ 0x0120))
#define BSP_IOM_CO_TSDP10_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP10_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH11)***/
#define BSP_IOM_CO_TSDP11                    ((volatile u32*)(BSP_IOM+ 0x0124))
#define BSP_IOM_CO_TSDP11_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP11_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH20)***/
#define BSP_IOM_CO_TSDP20                    ((volatile u32*)(BSP_IOM+ 0x0128))
#define BSP_IOM_CO_TSDP20_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP20_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH21)***/
#define BSP_IOM_CO_TSDP21                    ((volatile u32*)(BSP_IOM+ 0x012C))
#define BSP_IOM_CO_TSDP21_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP21_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Ctrl. Reg. Contr. Data Access CH1x***/
#define BSP_IOM_CDA1_CR                      ((volatile u32*)(BSP_IOM+ 0x0138))
#define BSP_IOM_CDA1_CR_EN_TBM                        (1 << 5)
#define BSP_IOM_CDA1_CR_EN_I1                          (1 << 4)
#define BSP_IOM_CDA1_CR_EN_I0                          (1 << 3)
#define BSP_IOM_CDA1_CR_EN_O1                          (1 << 2)
#define BSP_IOM_CDA1_CR_EN_O0                          (1 << 1)
#define BSP_IOM_CDA1_CR_SWAP                            (1 << 0)

/***Ctrl. Reg. Contr. Data Access CH1x***/
#define BSP_IOM_CDA2_CR                      ((volatile u32*)(BSP_IOM+ 0x013C))
#define BSP_IOM_CDA2_CR_EN_TBM                        (1 << 5)
#define BSP_IOM_CDA2_CR_EN_I1                          (1 << 4)
#define BSP_IOM_CDA2_CR_EN_I0                          (1 << 3)
#define BSP_IOM_CDA2_CR_EN_O1                          (1 << 2)
#define BSP_IOM_CDA2_CR_EN_O0                          (1 << 1)
#define BSP_IOM_CDA2_CR_SWAP                            (1 << 0)

/***Control Register B-Channel Data***/
#define BSP_IOM_BCHA_CR                      ((volatile u32*)(BSP_IOM+ 0x0144))
#define BSP_IOM_BCHA_CR_EN_BC2                        (1 << 4)
#define BSP_IOM_BCHA_CR_EN_BC1                        (1 << 3)

/***Control Register B-Channel Data***/
#define BSP_IOM_BCHB_CR                      ((volatile u32*)(BSP_IOM+ 0x0148))
#define BSP_IOM_BCHB_CR_EN_BC2                        (1 << 4)
#define BSP_IOM_BCHB_CR_EN_BC1                        (1 << 3)

/***Control Reg. for HDLC and CI1 Data***/
#define BSP_IOM_DCI_CR                       ((volatile u32*)(BSP_IOM+ 0x014C))
#define BSP_IOM_DCI_CR_DPS_CI1                      (1 << 7)
#define BSP_IOM_DCI_CR_EN_CI1                        (1 << 6)
#define BSP_IOM_DCI_CR_EN_D                            (1 << 5)

/***Control Reg. for HDLC and CI1 Data***/
#define BSP_IOM_DCIC_CR                      ((volatile u32*)(BSP_IOM+ 0x014C))
#define BSP_IOM_DCIC_CR_DPS_CI0                      (1 << 7)
#define BSP_IOM_DCIC_CR_EN_CI0                        (1 << 6)
#define BSP_IOM_DCIC_CR_DPS_D                          (1 << 5)

/***Control Reg. Serial Data Strobe x***/
#define BSP_IOM_SDS_CR                       ((volatile u32*)(BSP_IOM+ 0x0154))
#define BSP_IOM_SDS_CR_ENS_TSS                      (1 << 7)
#define BSP_IOM_SDS_CR_ENS_TSS_1                  (1 << 6)
#define BSP_IOM_SDS_CR_ENS_TSS_3                  (1 << 5)
#define BSP_IOM_SDS_CR_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Control Register IOM Data***/
#define BSP_IOM_IOM_CR                       ((volatile u32*)(BSP_IOM+ 0x015C))
#define BSP_IOM_IOM_CR_SPU                              (1 << 7)
#define BSP_IOM_IOM_CR_CI_CS                          (1 << 5)
#define BSP_IOM_IOM_CR_TIC_DIS                      (1 << 4)
#define BSP_IOM_IOM_CR_EN_BCL                        (1 << 3)
#define BSP_IOM_IOM_CR_CLKM                            (1 << 2)
#define BSP_IOM_IOM_CR_Res                              (1 << 1)
#define BSP_IOM_IOM_CR_DIS_IOM                      (1 << 0)

/***Synchronous Transfer Interrupt***/
#define BSP_IOM_STI                          ((volatile u32*)(BSP_IOM+ 0x0160))
#define BSP_IOM_STI_STOV21                        (1 << 7)
#define BSP_IOM_STI_STOV20                        (1 << 6)
#define BSP_IOM_STI_STOV11                        (1 << 5)
#define BSP_IOM_STI_STOV10                        (1 << 4)
#define BSP_IOM_STI_STI21                          (1 << 3)
#define BSP_IOM_STI_STI20                          (1 << 2)
#define BSP_IOM_STI_STI11                          (1 << 1)
#define BSP_IOM_STI_STI10                          (1 << 0)

/***Acknowledge Synchronous Transfer Interrupt***/
#define BSP_IOM_ASTI                         ((volatile u32*)(BSP_IOM+ 0x0160))
#define BSP_IOM_ASTI_ACK21                          (1 << 3)
#define BSP_IOM_ASTI_ACK20                          (1 << 2)
#define BSP_IOM_ASTI_ACK11                          (1 << 1)
#define BSP_IOM_ASTI_ACK10                          (1 << 0)

/***Mask Synchronous Transfer Interrupt***/
#define BSP_IOM_MSTI                         ((volatile u32*)(BSP_IOM+ 0x0164))
#define BSP_IOM_MSTI_STOV21                        (1 << 7)
#define BSP_IOM_MSTI_STOV20                        (1 << 6)
#define BSP_IOM_MSTI_STOV11                        (1 << 5)
#define BSP_IOM_MSTI_STOV10                        (1 << 4)
#define BSP_IOM_MSTI_STI21                          (1 << 3)
#define BSP_IOM_MSTI_STI20                          (1 << 2)
#define BSP_IOM_MSTI_STI11                          (1 << 1)
#define BSP_IOM_MSTI_STI10                          (1 << 0)

/***Configuration Register for Serial Data Strobes***/
#define BSP_IOM_SDS_CONF                    ((volatile u32*)(BSP_IOM+ 0x0168))
#define BSP_IOM_SDS_CONF_SDS_BCL                      (1 << 0)

/***Monitoring CDA Bits***/
#define BSP_IOM_MCDA                         ((volatile u32*)(BSP_IOM+ 0x016C))
#define BSP_IOM_MCDA_MCDA21 (value)             (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_IOM_MCDA_MCDA20 (value)             (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_IOM_MCDA_MCDA11 (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_IOM_MCDA_MCDA10 (value)             (((( 1 << 2) - 1) & (value)) << 0)

/***********************************************************************/
/*  Module      :  ASC0 register address and bits                      */
/***********************************************************************/
#define BSP_ASC0                          (KSEG1+0x1E100400)
/***********************************************************************/
#define BSP_ASC0_TBUF                        ((volatile u32*)(BSP_ASC0 + 0x0020))
#define BSP_ASC0_RBUF                        ((volatile u32*)(BSP_ASC0 + 0x0024))
#define BSP_ASC0_FSTAT                       ((volatile u32*)(BSP_ASC0 + 0x0048))
#define BSP_ASC0_FSTAT_TXFREE_GET(value)     (((value) >> 24) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_TXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 24)
#define BSP_ASC0_FSTAT_RXFREE_GET(value)     (((value) >> 16) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_RXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 16)
#define BSP_ASC0_FSTAT_TXFFL_GET(value)      (((value) >> 8) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_TXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_ASC0_FSTAT_RXFFL_GET(value)      (((value) >> 0) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_RXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 0)


/***********************************************************************/
/*  Module      :  ASC1 register address and bits                      */
/***********************************************************************/

#define BSP_ASC1                          (KSEG1+0x1E100C00)


/***********************************************************************/
/*  Module      :  ASC0 register address and bits                      */
/***********************************************************************/
#define VR9_ASC0                               (KSEG1 | 0x1E100400)
/***********************************************************************/
#define VR9_ASC0_TBUF                          ((volatile u32*)(VR9_ASC0 + 0x0020))
#define VR9_ASC0_RBUF                          ((volatile u32*)(VR9_ASC0 + 0x0024))
#define VR9_ASC0_FSTAT                         ((volatile u32*)(VR9_ASC0 + 0x0048))


/***********************************************************************/
/*  Module      :  ASC1 register address and bits                      */
/***********************************************************************/
#define VR9_DMA_BASE                           0xBE104100
#define VR9_ASC1                               (KSEG1 | 0x1E100C00)
/***********************************************************************/
#define VR9_ASC1_TBUF                          ((volatile u32*)(VR9_ASC1 + 0x0020))
#define VR9_ASC1_RBUF                          ((volatile u32*)(VR9_ASC1 + 0x0024))
#define VR9_ASC1_FSTAT                         ((volatile u32*)(VR9_ASC1 + 0x0048))


/***********************************************************************/
/***ASC Clock Control Register***/ 
#define BSP_ASC1_CLC                      ((volatile u32*)(BSP_ASC1+ 0x0000))
#define BSP_ASC1_CLC_RMC(value)                (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_ASC1_CLC_DISS                            (1 << 1)
#define BSP_ASC1_CLC_DISR                            (1 << 0)		

/***ASC Port Input Select Register***/ 
#define BSP_ASC1_PISEL                    ((volatile u32*)(BSP_ASC1+ 0x0004))
#define BSP_ASC1_PISEL                    ((volatile u32*)(BSP_ASC1+ 0x0004))
#define BSP_ASC1_PISEL_RIS                              (1 << 0)
      
/***ASC Control Register***/ 
#define BSP_ASC1_CON                      ((volatile u32*)(BSP_ASC1+ 0x0010))
#define BSP_ASC1_CON_BEN                              (1 << 20)
#define BSP_ASC1_CON_TOEN                              (1 << 20)
#define BSP_ASC1_CON_ROEN                              (1 << 19)
#define BSP_ASC1_CON_RUEN                              (1 << 18)
#define BSP_ASC1_CON_FEN                              (1 << 17)
#define BSP_ASC1_CON_PAL                              (1 << 16)
#define BSP_ASC1_CON_R                              (1 << 15)
#define BSP_ASC1_CON_ACO                             (1 << 14)
#define BSP_ASC1_CON_LB                              (1 << 13)
#define BSP_ASC1_CON_ERCLK                             (1 << 10)
#define BSP_ASC1_CON_FDE                              (1 << 9)
#define BSP_ASC1_CON_BRS                              (1 << 8)
#define BSP_ASC1_CON_STP                              (1 << 7)
#define BSP_ASC1_CON_SP                              (1 << 6)
#define BSP_ASC1_CON_ODD                              (1 << 5)
#define BSP_ASC1_CON_PEN                              (1 << 4)
#define BSP_ASC1_CON_M(value)                (((( 1 << 3) - 1) & (value)) << 0)
 
/***ASC Staus Register***/ 
#define BSP_ASC1_STATE                      ((volatile u32*)(BSP_ASC1+ 0x0014))
/***ASC Write Hardware Modified Control Register***/ 
#define BSP_ASC1_WHBSTATE                   ((volatile u32*)(BSP_ASC1+ 0x0018))
#define BSP_ASC1_WHBSTATE_SETBE                          (1 << 113)
#define BSP_ASC1_WHBSTATE_SETTOE                          (1 << 12)
#define BSP_ASC1_WHBSTATE_SETROE                          (1 << 11)
#define BSP_ASC1_WHBSTATE_SETRUE                          (1 << 10)
#define BSP_ASC1_WHBSTATE_SETFE                          (1 << 19)
#define BSP_ASC1_WHBSTATE_SETPE                          (1 << 18)
#define BSP_ASC1_WHBSTATE_CLRBE                          (1 << 17)
#define BSP_ASC1_WHBSTATE_CLRTOE                          (1 << 6)
#define BSP_ASC1_WHBSTATE_CLRROE                          (1 << 5)
#define BSP_ASC1_WHBSTATE_CLRRUE                          (1 << 4)
#define BSP_ASC1_WHBSTATE_CLRFE                          (1 << 3)
#define BSP_ASC1_WHBSTATE_CLRPE                          (1 << 2)
#define BSP_ASC1_WHBSTATE_SETREN                        (1 << 1)
#define BSP_ASC1_WHBSTATE_CLRREN                        (1 << 0)
      
/***ASC Baudrate Timer/Reload Register***/ 
#define BSP_ASC1_BG                      ((volatile u32*)(BSP_ASC1+ 0x0050))
#define BSP_ASC1_BG_BR_VALUE(value)          (((( 1 << 13) - 1) & (value)) << 0)
      
/***ASC Fractional Divider Register***/ 
#define BSP_ASC1_FDV                      ((volatile u32*)(BSP_ASC1+ 0x0018))
#define BSP_ASC1_FDV_FD_VALUE(value)          (((( 1 << 9) - 1) & (value)) << 0)
      
/***ASC Transmit Buffer Register***/ 
#define BSP_ASC1_TBUF                    ((volatile u32*)(BSP_ASC1+ 0x0020))
#define BSP_ASC1_TBUF_TD_VALUE(value)          (((( 1 << 9) - 1) & (value)) << 0)
      
/***ASC Receive Buffer Register***/ 
#define BSP_ASC1_RBUF                    ((volatile u32*)(BSP_ASC1+ 0x0024))
#define BSP_ASC1_RBUF_RD_VALUE(value)          (((( 1 << 9) - 1) & (value)) << 0)
      
/***ASC Autobaud Control Register***/ 
#define BSP_ASC1_ABCON                    ((volatile u32*)(BSP_ASC1+ 0x0030))
#define BSP_ASC1_ABCON_RXINV                          (1 << 11)
#define BSP_ASC1_ABCON_TXINV                          (1 << 10)
#define BSP_ASC1_ABCON_ABEM(value)               (((( 1 << 2) - 1) & (value)) << 8)
#define BSP_ASC1_ABCON_FCDETEN                      (1 << 4)
#define BSP_ASC1_ABCON_ABDETEN                      (1 << 3)
#define BSP_ASC1_ABCON_ABSTEN                        (1 << 2)
#define BSP_ASC1_ABCON_AUREN                          (1 << 1)
#define BSP_ASC1_ABCON_ABEN                            (1 << 0)
      
/***Receive FIFO Control Register***/ 
#define BSP_ASC1_RXFCON                       ((volatile u32*)(BSP_ASC1+ 0x0040))
#define BSP_ASC1_RXFCON_RXFITL(value)             (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_ASC1_RXFCON_RXFFLU                        (1 << 1)
#define BSP_ASC1_RXFCON_RXFEN                          (1 << 0)
      
/***Transmit FIFO Control Register***/ 
#define BSP_ASC1_TXFCON                       ((volatile u32*)(BSP_ASC1+ 0x0044))
#define BSP_ASC1_TXFCON_TXFITL(value)             (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_ASC1_TXFCON_TXFFLU                        (1 << 1)
#define BSP_ASC1_TXFCON_TXFEN                          (1 << 0)
      
/***FIFO Status Register***/ 
#define BSP_ASC1_FSTAT                        ((volatile u32*)(BSP_ASC1+ 0x0048))
#define BSP_ASC1_FSTAT_TXFFL(value)              (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_ASC1_FSTAT_RXFFL(value)              (((( 1 << 6) - 1) & (value)) << 0)
#define BSP_ASC1_FSTAT_TXFREE_GET(value)     (((value) >> 24) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_TXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 24)
#define BSP_ASC1_FSTAT_RXFREE_GET(value)     (((value) >> 16) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_RXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 16)
#define BSP_ASC1_FSTAT_TXFFL_GET(value)      (((value) >> 8) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_TXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_ASC1_FSTAT_RXFFL_GET(value)      (((value) >> 0) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_RXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 0)
      
/***ASC Autobaud Status Register***/ 
#define BSP_ASC1_ABSTAT                   ((volatile u32*)(BSP_ASC1+ 0x0034))
#define BSP_ASC1_ABSTAT_DETWAIT                      (1 << 4)
#define BSP_ASC1_ABSTAT_SCCDET                        (1 << 3)
#define BSP_ASC1_ABSTAT_SCSDET                        (1 << 2)
#define BSP_ASC1_ABSTAT_FCCDET                        (1 << 1)
#define BSP_ASC1_ABSTAT_FCSDET                        (1 << 0)
      
/***ASC Write HW Modified Autobaud Status Register***/ 
#define BSP_ASC1_WHBABSTAT                 ((volatile u32*)(BSP_ASC1+ 0x003C))
#define BSP_ASC1_WHBABSTAT_SETDETWAIT                (1 << 9)
#define BSP_ASC1_WHBABSTAT_CLRDETWAIT                (1 << 8)
#define BSP_ASC1_WHBABSTAT_SETSCCDET                  (1 << 7)
#define BSP_ASC1_WHBABSTAT_CLRSCCDET                  (1 << 6)
#define BSP_ASC1_WHBABSTAT_SETSCSDET                  (1 << 5)
#define BSP_ASC1_WHBABSTAT_CLRSCSDET                  (1 << 4)
#define BSP_ASC1_WHBABSTAT_SETFCCDET                  (1 << 3)
#define BSP_ASC1_WHBABSTAT_CLRFCCDET                  (1 << 2)
#define BSP_ASC1_WHBABSTAT_SETFCSDET                  (1 << 1)
#define BSP_ASC1_WHBABSTAT_CLRFCSDET                  (1 << 0)
      
/***ASC IRNCR0 **/
#define BSP_ASC1_IRNREN			((volatile u32*)(BSP_ASC1+ 0x00F4))
#define BSP_ASC1_IRNICR			((volatile u32*)(BSP_ASC1+ 0x00FC))
/***ASC IRNCR1 **/
#define BSP_ASC1_IRNCR			((volatile u32*)(BSP_ASC1+ 0x00F8))
#define ASC_IRNCR_TIR	0x1
#define ASC_IRNCR_RIR	0x2
#define ASC_IRNCR_EIR	0x4

/***ASC Modem Control Register***/
#define ASC_MODCTL                      ((volatile u32*)(BSP_ASC1+ 0x0060))
#define ASC_MODCTL_RTSFC                (1 << 5)
#define ASC_MODCTL_CTSFC                (1 << 4)
#define ASC_MODCTL_RTSSET               (1 << 18)
#define ASC_MODCTL_RTSCLR               (1 << 19)


/***********************************************************************/
/*  Module      :  Debug register address and bits                     */
/***********************************************************************/

#define BSP_Debug                        (0xBF106000)
/***********************************************************************/


/***MCD Break Bus Switch Register***/
#define BSP_Debug_MCD_BBS                      ((volatile u32*)(BSP_Debug+ 0x0000))
#define BSP_Debug_MCD_BBS_BTP1                            (1 << 19)
#define BSP_Debug_MCD_BBS_BTP0                            (1 << 18)
#define BSP_Debug_MCD_BBS_BSP1                            (1 << 17)
#define BSP_Debug_MCD_BBS_BSP0                            (1 << 16)
#define BSP_Debug_MCD_BBS_BT5EN                          (1 << 15)
#define BSP_Debug_MCD_BBS_BT4EN                          (1 << 14)
#define BSP_Debug_MCD_BBS_BT5                              (1 << 13)
#define BSP_Debug_MCD_BBS_BT4                              (1 << 12)
#define BSP_Debug_MCD_BBS_BS5EN                          (1 << 7)
#define BSP_Debug_MCD_BBS_BS4EN                          (1 << 6)
#define BSP_Debug_MCD_BBS_BS5                              (1 << 5)
#define BSP_Debug_MCD_BBS_BS4                              (1 << 4)

/***MCD Multiplexer Control Register***/
#define BSP_Debug_MCD_MCR                      ((volatile u32*)(BSP_Debug+ 0x0008))
#define BSP_Debug_MCD_MCR_MUX5                            (1 << 4)
#define BSP_Debug_MCD_MCR_MUX4                            (1 << 3)
#define BSP_Debug_MCD_MCR_MUX1                            (1 << 0)


/***********************************************************************/
/*  Module      :  SRAM register address and bits                      */
/***********************************************************************/

#define BSP_SRAM                         (0xBF980000)
/***********************************************************************/


/***SRAM Size Register***/
#define BSP_SRAM_SRAM_SIZE                    ((volatile u32*)(BSP_SRAM+ 0x0800))
#define BSP_SRAM_SRAM_SIZE_SIZE (value)               (((( 1 << 23) - 1) & (value)) << 0)

/***********************************************************************/
/*  Module      :  BIU register address and bits                       */
/***********************************************************************/

#define BSP_BIU                          (0xBFA80000)
/***********************************************************************/


/***BIU Identification Register***/
#define BSP_BIU_BIU_ID                       ((volatile u32*)(BSP_BIU+ 0x0000))
#define BSP_BIU_BIU_ID_ARCH                            (1 << 16)
#define BSP_BIU_BIU_ID_ID (value)                (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_BIU_BIU_ID_REV (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***BIU Access Error Cause Register***/
#define BSP_BIU_BIU_ERRCAUSE                 ((volatile u32*)(BSP_BIU+ 0x0100))
#define BSP_BIU_BIU_ERRCAUSE_ERR                              (1 << 31)
#define BSP_BIU_BIU_ERRCAUSE_PORT (value)               (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_BIU_BIU_ERRCAUSE_CAUSE (value)              (((( 1 << 2) - 1) & (value)) << 0)

/***BIU Access Error Address Register***/
#define BSP_BIU_BIU_ERRADDR                  ((volatile u32*)(BSP_BIU+ 0x0108))
#define BSP_BIU_BIU_ERRADDR_ADDR


/***********************************************************************/
/*  Module      :  ICU register address and bits                       */
/***********************************************************************/

#define BSP_ICU                         (KSEG1 | 0x1F880200)
#define BSP_ICU1			(KSEG1 | 0x1F880300)
/***********************************************************************/
#define BSP_ICU_IM0_ISR                      ((volatile u32*)(BSP_ICU + 0x0000))
#define BSP_ICU_IM0_IER                      ((volatile u32*)(BSP_ICU + 0x0008))
#define BSP_ICU_IM0_IOSR                     ((volatile u32*)(BSP_ICU + 0x0010))
#define BSP_ICU_IM0_IRSR                     ((volatile u32*)(BSP_ICU + 0x0018))
#define BSP_ICU_IM0_IMR                      ((volatile u32*)(BSP_ICU + 0x0020))
#define BSP_ICU_IM0_IMR_IID                  (1 << 31)
#define BSP_ICU_IM0_IMR_IN_GET(value)        (((value) >> 0) & ((1 << 5) - 1))
#define BSP_ICU_IM0_IMR_IN_SET(value)        (((( 1 << 5) - 1) & (value)) << 0)
#define BSP_ICU_IM0_IR(value)                (1 << (value))

#define BSP_ICU_IM1_ISR                      ((volatile u32*)(BSP_ICU + 0x0028))
#define BSP_ICU_IM1_IER                      ((volatile u32*)(BSP_ICU + 0x0030))
#define BSP_ICU_IM1_IOSR                     ((volatile u32*)(BSP_ICU + 0x0038))
#define BSP_ICU_IM1_IRSR                     ((volatile u32*)(BSP_ICU + 0x0040))
#define BSP_ICU_IM1_IMR                      ((volatile u32*)(BSP_ICU + 0x0048))
#define BSP_ICU_IM1_IMR_IID                  (1 << 31)
#define BSP_ICU_IM1_IMR_IN_GET(value)        (((value) >> 0) & ((1 << 5) - 1))
#define BSP_ICU_IM1_IMR_IN_SET(value)        (((( 1 << 5) - 1) & (value)) << 0)
#define BSP_ICU_IM1_IR(value)                (1 << (value))

#define BSP_ICU_IM2_ISR                      ((volatile u32*)(BSP_ICU + 0x0050))
#define BSP_ICU_IM2_IER                      ((volatile u32*)(BSP_ICU + 0x0058))
#define BSP_ICU_IM2_IOSR                     ((volatile u32*)(BSP_ICU + 0x0060))
#define BSP_ICU_IM2_IRSR                     ((volatile u32*)(BSP_ICU + 0x0068))
#define BSP_ICU_IM2_IMR                      ((volatile u32*)(BSP_ICU + 0x0070))
#define BSP_ICU_IM2_IMR_IID                  (1 << 31)
#define BSP_ICU_IM2_IMR_IN_GET(value)        (((value) >> 0) & ((1 << 5) - 1))
#define BSP_ICU_IM2_IMR_IN_SET(value)        (((( 1 << 5) - 1) & (value)) << 0)
#define BSP_ICU_IM2_IR(value)                (1 << (value))

#define BSP_ICU_IM3_ISR                      ((volatile u32*)(BSP_ICU + 0x0078))
#define BSP_ICU_IM3_IER                      ((volatile u32*)(BSP_ICU + 0x0080))
#define BSP_ICU_IM3_IOSR                     ((volatile u32*)(BSP_ICU + 0x0088))
#define BSP_ICU_IM3_IRSR                     ((volatile u32*)(BSP_ICU + 0x0090))
#define BSP_ICU_IM3_IMR                      ((volatile u32*)(BSP_ICU + 0x0098))
#define BSP_ICU_IM3_IMR_IID                  (1 << 31)
#define BSP_ICU_IM3_IMR_IN_GET(value)        (((value) >> 0) & ((1 << 5) - 1))
#define BSP_ICU_IM3_IMR_IN_SET(value)        (((( 1 << 5) - 1) & (value)) << 0)
#define BSP_ICU_IM3_IR(value)                (1 << (value))

#define BSP_ICU_IM4_ISR                      ((volatile u32*)(BSP_ICU + 0x00A0))
#define BSP_ICU_IM4_IER                      ((volatile u32*)(BSP_ICU + 0x00A8))
#define BSP_ICU_IM4_IOSR                     ((volatile u32*)(BSP_ICU + 0x00B0))
#define BSP_ICU_IM4_IRSR                     ((volatile u32*)(BSP_ICU + 0x00B8))
#define BSP_ICU_IM4_IMR                      ((volatile u32*)(BSP_ICU + 0x00C0))
#define BSP_ICU_IM4_IMR_IID                  (1 << 31)
#define BSP_ICU_IM4_IMR_IN_GET(value)        (((value) >> 0) & ((1 << 5) - 1))
#define BSP_ICU_IM4_IMR_IN_SET(value)        (((( 1 << 5) - 1) & (value)) << 0)
#define BSP_ICU_IM4_IR(value)                (1 << (value))

#define BSP_ICU_IM5_ISR                      ((volatile u32*)(BSP_ICU + 0x00C8))
#define BSP_ICU_IM5_IER                      ((volatile u32*)(BSP_ICU + 0x00D0))
#define BSP_ICU_IM5_IOSR                     ((volatile u32*)(BSP_ICU + 0x00D8))
#define BSP_ICU_IM5_IRSR                     ((volatile u32*)(BSP_ICU + 0x00E0))
#define BSP_ICU_IM5_IMR                      ((volatile u32*)(BSP_ICU + 0x00E8))
#define BSP_ICU_IM5_IMR_IID                  (1 << 31)
#define BSP_ICU_IM5_IMR_IN_GET(value)        (((value) >> 0) & ((1 << 5) - 1))
#define BSP_ICU_IM5_IMR_IN_SET(value)        (((( 1 << 5) - 1) & (value)) << 0)
#define BSP_ICU_IM5_IR(value)                (1 << (value))

/***Interrupt Vector Value Register***/
#define BSP_ICU_IM_VEC                      ((volatile u32*)(BSP_ICU+ 0x00f0))

/***Interrupt Vector Value Mask***/
#define BSP_ICU_IM0_VEC_MASK                0x0000001f
#define BSP_ICU_IM1_VEC_MASK                0x000003e0
#define BSP_ICU_IM2_VEC_MASK                0x00007c00
#define BSP_ICU_IM3_VEC_MASK                0x000f8000
#define BSP_ICU_IM4_VEC_MASK                0x01f00000

#define BSP_ICU_IM0_ISR_IR(value)          (1<<(value))                 
#define BSP_ICU_IM0_IER_IR(value)          (1<<(value))                 
#define BSP_ICU_IM1_ISR_IR(value)          (1<<(value))                 
#define BSP_ICU_IM1_IER_IR(value)          (1<<(value))                 
#define BSP_ICU_IM2_ISR_IR(value)          (1<<(value))                 
#define BSP_ICU_IM2_IER_IR(value)          (1<<(value))                 
#define BSP_ICU_IM3_ISR_IR(value)          (1<<(value))                 
#define BSP_ICU_IM3_IER_IR(value)          (1<<(value))                 
#define BSP_ICU_IM4_ISR_IR(value)          (1<<(value))                 
#define BSP_ICU_IM4_IER_IR(value)          (1<<(value))                 
#define BSP_ICU_IM5_ISR_IR(value)          (1<<(value))                 
#define BSP_ICU_IM5_IER_IR(value)          (1<<(value))                 

/***DMA Interrupt Mask Value***/
#define BSP_DMA_H_MASK			0x00000fff
                                                                                       
/***External Interrupt Control Register***/
//#define BSP_ICU_EIU                    (KSEG1+0x1f101000)
#define BSP_ICU_EIU                    (0xbf101000)
#define BSP_ICU_EIU_EXIN_C                ((volatile u32*)(BSP_ICU_EIU+ 0x0000))                                                                                    
#define BSP_ICU_EIU_INIC                  ((volatile u32*)(BSP_ICU_EIU+ 0x0004))                                                                                       
#define BSP_ICU_EIU_INC                   ((volatile u32*)(BSP_ICU_EIU+ 0x0008))                                                                                       
#define BSP_ICU_EIU_INEN                   ((volatile u32*)(BSP_ICU_EIU+ 0x000c))

#define BSP_ICU_YIELDEN0		((volatile u32*)(BSP_ICU_EIU+ 0x0010))   
#define BSP_ICU_YIELDEN1		((volatile u32*)(BSP_ICU_EIU+ 0x0014))    
#define BSP_ICU_YIELDEN2		((volatile u32*)(BSP_ICU_EIU+ 0x0018))    

#define BSP_ICU_NMI_CR                     ((volatile u32*)(BSP_ICU_EIU + 0xF0))
#define BSP_ICU_NMI_SR                     ((volatile u32*)(BSP_ICU_EIU + 0xF4))

/***********************************************************************/
/*  Module      :  MPS register address and bits                       */
/***********************************************************************/

#define BSP_MPS                          (KSEG1+0x1F107000)
/***********************************************************************/

#define BSP_MPS_MANID_REG			((volatile u32*)(BSP_MPS + 0x340))
#define BSP_MPS_CHIPID                       ((volatile u32*)(BSP_MPS + 0x0344))
#define BSP_MPS_CHIPID_VERSION_GET(value)    (((value) >> 28) & ((1 << 4) - 1))
#define BSP_MPS_CHIPID_VERSION_SET(value)    (((( 1 << 4) - 1) & (value)) << 28)
#define BSP_MPS_CHIPID_PARTNUM_GET(value)    (((value) >> 12) & ((1 << 16) - 1))
#define BSP_MPS_CHIPID_PARTNUM_SET(value)    (((( 1 << 16) - 1) & (value)) << 12)
#define BSP_MPS_CHIPID_MANID_GET(value)      (((value) >> 1) & ((1 << 10) - 1))
#define BSP_MPS_CHIPID_MANID_SET(value)      (((( 1 << 10) - 1) & (value)) << 1)
#define BSP_MPS_CHIP_CONFIG_REG			((volatile u32 *)(BSP_MPS + 0x350))


/* voice channel 0 ... 3 interrupt enable register */
#define BSP_MPS_VC0ENR ((volatile u32*)(BSP_MPS + 0x0000))
#define BSP_MPS_VC1ENR ((volatile u32*)(BSP_MPS + 0x0004))
#define BSP_MPS_VC2ENR ((volatile u32*)(BSP_MPS + 0x0008))
#define BSP_MPS_VC3ENR ((volatile u32*)(BSP_MPS + 0x000C))
/* voice channel 0 ... 3 interrupt status read register */
#define BSP_MPS_RVC0SR ((volatile u32*)(BSP_MPS + 0x0010))
#define BSP_MPS_RVC1SR ((volatile u32*)(BSP_MPS + 0x0014))
#define BSP_MPS_RVC2SR ((volatile u32*)(BSP_MPS + 0x0018))
#define BSP_MPS_RVC3SR ((volatile u32*)(BSP_MPS + 0x001C))
/* voice channel 0 ... 3 interrupt status set register */
#define BSP_MPS_SVC0SR ((volatile u32*)(BSP_MPS + 0x0020))
#define BSP_MPS_SVC1SR ((volatile u32*)(BSP_MPS + 0x0024))
#define BSP_MPS_SVC2SR ((volatile u32*)(BSP_MPS + 0x0028))
#define BSP_MPS_SVC3SR ((volatile u32*)(BSP_MPS + 0x002C))
/* voice channel 0 ... 3 interrupt status clear register */
#define BSP_MPS_CVC0SR ((volatile u32*)(BSP_MPS + 0x0030))
#define BSP_MPS_CVC1SR ((volatile u32*)(BSP_MPS + 0x0034))
#define BSP_MPS_CVC2SR ((volatile u32*)(BSP_MPS + 0x0038))
#define BSP_MPS_CVC3SR ((volatile u32*)(BSP_MPS + 0x003C))
/* common status 0 and 1 read register */
#define BSP_MPS_RAD0SR ((volatile u32*)(BSP_MPS + 0x0040))
#define BSP_MPS_RAD1SR ((volatile u32*)(BSP_MPS + 0x0044))
/* common status 0 and 1 set register */
#define BSP_MPS_SAD0SR ((volatile u32*)(BSP_MPS + 0x0048))
#define BSP_MPS_SAD1SR ((volatile u32*)(BSP_MPS + 0x004C))
/* common status 0 and 1 clear register */
#define BSP_MPS_CAD0SR ((volatile u32*)(BSP_MPS + 0x0050))
#define BSP_MPS_CAD1SR ((volatile u32*)(BSP_MPS + 0x0054))
/* common status 0 and 1 enable register */
#define BSP_MPS_AD0ENR ((volatile u32*)(BSP_MPS + 0x0058))
#define BSP_MPS_AD1ENR ((volatile u32*)(BSP_MPS + 0x005C))
/* notification enable register */
#define BSP_MPS_CPU0_NFER ((volatile u32*)(BSP_MPS + 0x0060))
#define BSP_MPS_CPU1_NFER ((volatile u32*)(BSP_MPS + 0x0064))
/* CPU to CPU interrup request register */
#define BSP_MPS_CPU0_2_CPU1_IRR ((volatile u32*)(BSP_MPS + 0x0070))
#define BSP_MPS_CPU0_2_CPU1_IER ((volatile u32*)(BSP_MPS + 0x0074))
/* Global interrupt request and request enable register */
#define BSP_MPS_GIRR ((volatile u32*)(BSP_MPS + 0x0078))
#define BSP_MPS_GIER ((volatile u32*)(BSP_MPS + 0x007C))

#define BSP_MPS_SRAM ((volatile u32*)(KSEG1 + 0x1F200000))

#define BSP_MPS_VCPU_FW_AD ((volatile u32*)(KSEG1 + 0x1F2001E0))

 
/************************************************************************/
/*   Module       :   DEU register address and bits        		*/
/************************************************************************/
//#define BSP_DEU_BASE_ADDR               (0xBE102000)
#define BSP_DEU_BASE_ADDR               (KSEG1 + 0x1E103100)
/*   DEU Control Register */
#define BSP_DEU_CLK                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0000))
#define BSP_DEU_ID                      ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0008))

/*   DEU control register */
#define BSP_DES_CON                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0010))
#define BSP_DES_IHR                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0014))
#define BSP_DES_ILR                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0018))
#define BSP_DES_K1HR                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x001C))
#define BSP_DES_K1LR                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0020))
#define BSP_DES_K3HR                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0024))
#define BSP_DES_K3LR                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0028))
#define BSP_DES_IVHR                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x002C))
#define BSP_DES_IVLR                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0030))
#define BSP_DES_OHR                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0040))
#define BSP_DES_OLR                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0050))

/* AES DEU register */
#define BSP_AES_CON 			   ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0050))
#define BSP_AES_ID3R                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0054))
#define BSP_AES_ID2R                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0058))
#define BSP_AES_ID1R                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x005C))
#define BSP_AES_ID0R                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0060))

/* AES Key register */
#define BSP_AES_K7R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0064))
#define BSP_AES_K6R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0068))
#define BSP_AES_K5R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x006C))
#define BSP_AES_K4R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0070))
#define BSP_AES_K3R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0074))
#define BSP_AES_K2R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0078))
#define BSP_AES_K1R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x007C))
#define BSP_AES_K0R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0080))

/* AES vector register */
#define BSP_AES_IV3R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0084))
#define BSP_AES_IV2R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0088))
#define BSP_AES_IV1R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x008C))
#define BSP_AES_IV0R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0090))
#define BSP_AES_0D3R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0094))
#define BSP_AES_0D2R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x0098))
#define BSP_AES_OD1R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x009C))
#define BSP_AES_OD0R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00A0))

/* hash control registe */
#define BSP_HASH_CON                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00B0))
#define BSP_HASH_MR                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00B4))
#define BSP_HASH_D1R                    ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00B8 ))
#define BSP_HASH_D2R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00BC ))
#define BSP_HASH_D3R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00C0 ))
#define BSP_HASH_D4R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00C4))
#define BSP_HASH_D5R                     ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00C8))

#define BSP_CON                         ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00EC))

#define BSP_DEU_IRNEN                         ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00F4))
#define BSP_DEU_IRNCR                         ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00F8))
#define BSP_DEU_IRNICR                         ((volatile u32 *)(BSP_DEU_BASE_ADDR + 0x00FC))


/***********************************************************************/
/*  Module      :  PCI register address and bits                       */
/***********************************************************************/
#define PCI_CONFIG_SPACE		(KSEG1+0x17000000)
#define PCI_MEM_BASE			(KSEG1+0x18000000)
#define PCI_IO_BASE			    (KSEG1+0x1B000000)
#define PCI_CONTROLLER_REG		(KSEG1+0x1E105400)

/***********************************************************************/
/*  Module      :  PCIE register address and bits                       */
/***********************************************************************/
#define PCIE_CFG_BASE			(KSEG1+0x1D000000)
#define PCIE_CFG_PHY_BASE       0x1D000000
#define PCIE_MEM_BASE			(KSEG1+0x1C000000)
#define PCIE_MEM_PHY_BASE       0x1C000000
#define PCIE_MEM_PHY_END        0x1CFFFFFF
#define PCIE_IO_BASE			(KSEG1+0x1D800000)
#define PCIE_IO_PHY_BASE        0x1D800000
#define PCIE_IO_PHY_END         0x1D8FFFFF
#define PCIE_CONFIGURATION_REGISTERS	(KSEG1+0x1D900000)
#define PCIE_APP_LOGIC_REG		(KSEG1+0x1E100900)
#define PCIE_MSI_PHY_BASE	    0x1F600000
#define PCIE_MSI_PHY_END	    0x1F6FFFFF
#define PCIE_PDI_BASE           (KSEG1 + 0x1F106800)
#define PCIE_PDI_PHY_BASE        0x1F106800
#define PCIE_PDI_SIZE            0x400

/* Port Interrupt Controller registers for PCIe */
#define BSP_PIC_BASE			(KSEG1 + 0x1F700000)
#define BSP_PIC_BIG_ENDIAN		1
#define BSP_PIC_LITTLE_ENDIAN	0
/* MSI PIC lookup table */
#define BSP_MSI_PIC_INT_LINE_SHIFT      28
#define BSP_MSI_PIC_INT_LINE_MASK       (3 << BSP_MSI_PIC_INT_LINE_SHIFT)
#define BSP_MSI_PIC_MSG_ADDR_SHIFT      16
#define BSP_MSI_PIC_MSG_ADDR_MASK       (0xFFF << BSP_MSI_PIC_MSG_ADDR_SHIFT)
#define BSP_MSI_PIC_MSG_DATA_MASK      0xFFFF

#define MSI_PATTTERN     0xAB00
#define IFX_NUM_MSI_IRQS 16
/* PCI Capability ID */
#define PCI_PM_CAPID			1
#define PCI_AGP_CAPID			2
#define PCI_VPD_CAPID			3
#define PCI_SLOT_ID_CAPID		4
#define PCI_MSI_CAPID			5
#define PCI_CPCI_CAPID			6
#define PCI_PCIX_CAPID			7
#define PCI_VENDOR_CAPID		9
#define PCI_CPCI_CENTRAL_RESOURCE_CAPID	0xB
#define PCI_HOTPLUG_CAPID		0xC
#define PCIE_PCIE_CAPID			0x10
#define PCI_MSIX_CAPID			0x11

/* PCIe Extended Capability ID */
#define PCIE_AER_CAPID			1
#define PCIE_VC_CAPID			2
#define PCIE_DEV_SERIAL_NUM_CAPID	3
#define PCIE_POWER_BUDGET_CAPID		4
#define PCIE_MFVC_CAPID2		8
#define PCIE_MFVC_VC_CAPID		9
#define PCIE_RCRB_CAPID			0xA
#define PCIE_VENDOR_CAPID		0xB
#define PCIE_ACS_CAPID			0xD

/* PCIe Port Logic Registers */
#define PCIE_PORT_LOGIC_BASE		(PCIE_CFG_BASE + 0x700)
#define PCIE_PL_ACK_LAT_REPLAY_TIMER	(PCIE_PORT_LOGIC_BASE + 0)
#define PCIE_PL_OTHER_MESSAGE		(PCIE_PORT_LOGIC_BASE + 4)
#define PCIE_PL_PORT_FORCE_LINK		(PCIE_PORT_LOGIC_BASE + 8)
#define PCIE_PL_ACK_FREQUENCY		(PCIE_PORT_LOGIC_BASE + 0xC)
#define PCIE_PL_LINK_CONTROL		(PCIE_PORT_LOGIC_BASE + 0x10)
#define PCIE_PL_LANE_SKEW		(PCIE_PORT_LOGIC_BASE + 0x14)
#define PCIE_PL_SYMBOL_NUMBER		(PCIE_PORT_LOGIC_BASE + 0x18)
#define PCIE_PL_SYMB_TIMER_FILTER_MASK	(PCIE_PORT_LOGIC_BASE + 0x1C)
#define PCIE_PL_FILTER_MASK_REG2	(PCIE_PORT_LOGIC_BASE + 0x20)
#define PCIE_PL_DEBUG0			(PCIE_PORT_LOGIC_BASE + 0x28)
#define PCIE_PL_DEBUG1			(PCIE_PORT_LOGIC_BASE + 0x2C)
#define PCIE_PL_TX_POSTED_FC_CRED_STS	(PCIE_PORT_LOGIC_BASE + 0x30)
#define PCIE_PL_TX_NPOSTED_FC_CRED_STS 	(PCIE_PORT_LOGIC_BASE + 0x34)
#define PCIE_PL_TX_COMPLETE_FC_CRED_STS	(PCIE_PORT_LOGIC_BASE + 0x38)
#define PCIE_PL_QUEUE_STATUS		(PCIE_PORT_LOGIC_BASE + 0x3C)
#define PCIE_PL_VC_TX_ARB1		(PCIE_PORT_LOGIC_BASE + 0x40)
#define PCIE_PL_VC_TX_ARB2		(PCIE_PORT_LOGIC_BASE + 0x44)

#define PCIE_PL_VC0_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x48)
#define PCIE_PL_VC0_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x4C)
#define PCIE_PL_VC0_COMPLETLE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x50)
#define RADM_CPL_QMODE_VC_MASK			(7 << 21)
#define RADM_CPL_QMODE_VC_BYPASS		(1 << 23)
#define RADM_CPL_QMODE_VC_CUT_THROUGH		(1 << 22)
#define RADM_CPL_QMODE_VC_STORE_AND_FORWARD	(1 << 21)

#define PCIE_PL_VC1_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x54)
#define PCIE_PL_VC1_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x58)
#define PCIE_PL_VC1_COMPLETE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x5C)

#define PCIE_PL_VC2_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x60)
#define PCIE_PL_VC2_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x64)
#define PCIE_PL_VC2_COMPLETE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x68)

#define PCIE_PL_VC3_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x6C)
#define PCIE_PL_VC3_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x70)
#define PCIE_PL_VC3_COMPLETE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x74)

#define PCIE_PL_VC4_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x78)
#define PCIE_PL_VC4_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x7C)
#define PCIE_PL_VC4_COMPLETE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x80)

#define PCIE_PL_VC5_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x84)
#define PCIE_PL_VC5_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x88)
#define PCIE_PL_VC5_COMPLETE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x8C)

#define PCIE_PL_VC6_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x90)
#define PCIE_PL_VC6_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x94)
#define PCIE_PL_VC7_COMPLETE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x98)

#define PCIE_PL_VC7_POSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0x9C)
#define PCIE_PL_VC7_NPOSTED_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0xA0)
#define PCIE_PL_VC6_COMPLETE_RX_QUEUE_CTRL	(PCIE_PORT_LOGIC_BASE + 0xA4)

#define PCIE_PL_VC0_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xA8)
#define PCIE_PL_VC0_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xAC)
#define PCIE_PL_VC0_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xB0)

#define PCIE_PL_VC1_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xB4)
#define PCIE_PL_VC1_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xB8)
#define PCIE_PL_VC1_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xBC)

#define PCIE_PL_VC2_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xC0)
#define PCIE_PL_VC2_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xC4)
#define PCIE_PL_VC2_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xC8)

#define PCIE_PL_VC3_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xCC)
#define PCIE_PL_VC3_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xD0)
#define PCIE_PL_VC3_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xD4)

#define PCIE_PL_VC4_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xD8)
#define PCIE_PL_VC4_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xDC)
#define PCIE_PL_VC4_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xE0)

#define PCIE_PL_VC5_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xE4)
#define PCIE_PL_VC5_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xE8)
#define PCIE_PL_VC5_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xEC)

#define PCIE_PL_VC6_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xF0)
#define PCIE_PL_VC6_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xF4)
#define PCIE_PL_VC6_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0xF8)

#define PCIE_PL_VC7_POSTED_BUFFER_DEPTH		(PCIE_PORT_LOGIC_BASE + 0xFC)
#define PCIE_PL_VC7_NPOSTED_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0x100)
#define PCIE_PL_VC7_COMPLETE_BUFFER_DEPTH	(PCIE_PORT_LOGIC_BASE + 0x104)

#define PCIE_PL_GEN2				(PCIE_PORT_LOGIC_BASE + 0x10C)
#define PCIE_PL_PHY_STATUS			(PCIE_PORT_LOGIC_BASE + 0x110)
#define PCIE_PL_PHY_CONTROL			(PCIE_PORT_LOGIC_BASE + 0x114)
/* PCIe APPLICATION REGISTER ADDRESS MAP */
#define PCIE_RC_CCR			(PCIE_APP_LOGIC_REG + 0x10)
#define PCIE_RC_DR			(PCIE_APP_LOGIC_REG + 0x14)
#define PCIE_PHY_SR			(PCIE_APP_LOGIC_REG + 0x18)
#define PCIE_EM_CR			(PCIE_APP_LOGIC_REG + 0x1C)
#define PCIE_IR_SR			(PCIE_APP_LOGIC_REG + 0x20)
#define PCIE_MSG_CR			(PCIE_APP_LOGIC_REG + 0x30)
#define PCIE_VDM_DR			(PCIE_APP_LOGIC_REG + 0x34)
#define PCIE_VDM_RID			(PCIE_APP_LOGIC_REG + 0x38)
#define PCIE_ASPM_CR			(PCIE_APP_LOGIC_REG + 0x40)
#define PCIE_VM_MSG_DW0			(PCIE_APP_LOGIC_REG + 0x50)
#define PCIE_VM_MSG_DW1			(PCIE_APP_LOGIC_REG + 0x54)
#define PCIE_VM_MSG_DW2			(PCIE_APP_LOGIC_REG + 0x58)
#define PCIE_VM_MSG_DW3			(PCIE_APP_LOGIC_REG + 0x5C)
#define PCIE_VM_MSG_REQR		(PCIE_APP_LOGIC_REG + 0x60)
#define PCIE_AHB_CTRL                       (PCIE_APP_LOGIC_REG + 0x78)
#define PCIE_AHB_CTRL_BUS_ERROR_SUPPRESS     0x00000001 
#define PCIE_IRNEN			(PCIE_APP_LOGIC_REG + 0xF4)
#define PCIE_IRNCR			(PCIE_APP_LOGIC_REG + 0xF8)
#define PCIE_IRNICR			(PCIE_APP_LOGIC_REG + 0xFC)

/* PCIe CONTROLLER REGISTER ADDRESS MAP */
#define PCIE_VDID			(PCIE_CONFIGURATION_REGISTERS + 0)
#define PCIE_PCICMDSTS			(PCIE_CONFIGURATION_REGISTERS + 4)
#define PCIE_CCRID			(PCIE_CONFIGURATION_REGISTERS + 8)
#define PCIE_CLSLTHTBR			(PCIE_CONFIGURATION_REGISTERS + 0x0C)
#define PCIE_BAR0			(PCIE_CONFIGURATION_REGISTERS + 0x10)
#define PCIE_BAR1			(PCIE_CONFIGURATION_REGISTERS + 0x14)
#define PCIE_BNR			(PCIE_CONFIGURATION_REGISTERS + 0x18)
#define PCIE_IOBLSECS			(PCIE_CONFIGURATION_REGISTERS + 0x1C)
#define PCIE_MBML			(PCIE_CONFIGURATION_REGISTERS + 0x20)
#define PCIE_PMBL			(PCIE_CONFIGURATION_REGISTERS + 0x24)
#define PCIE_PMBU32			(PCIE_CONFIGURATION_REGISTERS + 0x28)
#define PCIE_PMLU32			(PCIE_CONFIGURATION_REGISTERS + 0x2C)
#define PCIE_IO_BANDL			(PCIE_CONFIGURATION_REGISTERS + 0x30)
#define PCIE_CPR			(PCIE_CONFIGURATION_REGISTERS + 0x34)
#define PCIE_EBBAR			(PCIE_CONFIGURATION_REGISTERS + 0x38)
#define PCIE_INTRBCTRL			(PCIE_CONFIGURATION_REGISTERS + 0x3C)
#define PCIE_PM_CAPR			(PCIE_CONFIGURATION_REGISTERS + 0x40)
#define PCIE_PM_CSR			(PCIE_CONFIGURATION_REGISTERS + 0x44)
#define PCIE_MCAPR			(PCIE_CONFIGURATION_REGISTERS + 0x50)
#define PCIE_MA				(PCIE_CONFIGURATION_REGISTERS + 0x54)
/* PCIE_MUA not supported !!! */
//#define PCIE_MUA			(PCIE_CONFIGURATION_REGISTERS + 0x58)
#define PCIE_MD				(PCIE_CONFIGURATION_REGISTERS + 0x58)
#define PCIE_XCAP			(PCIE_CONFIGURATION_REGISTERS + 0x70)
#define PCIE_DCAP			(PCIE_CONFIGURATION_REGISTERS + 0x74)
#define PCIE_DCTLSTS			(PCIE_CONFIGURATION_REGISTERS + 0x78)
#define PCIE_LCAP			(PCIE_CONFIGURATION_REGISTERS + 0x7C)
#define PCIE_LCTLSTS			(PCIE_CONFIGURATION_REGISTERS + 0x80)
#define PCIE_SLCAP			(PCIE_CONFIGURATION_REGISTERS + 0x84)
#define PCIE_SLCTLSTS			(PCIE_CONFIGURATION_REGISTERS + 0x88)
#define PCIE_RCTLCAP			(PCIE_CONFIGURATION_REGISTERS + 0x8C)
#define PCIE_RSTS			(PCIE_CONFIGURATION_REGISTERS + 0x90)
#define PCIE_ENHANCED_CAP		(PCIE_CONFIGURATION_REGISTERS + 0x100)
#define PCIE_UES_R			(PCIE_CONFIGURATION_REGISTERS + 0x104)
#define PCIE_UEMR			(PCIE_CONFIGURATION_REGISTERS + 0x108)
#define PCIE_UESR			(PCIE_CONFIGURATION_REGISTERS + 0x10C)
#define PCIE_CESR			(PCIE_CONFIGURATION_REGISTERS + 0x110)
#define PCIE_CEMR			(PCIE_CONFIGURATION_REGISTERS + 0x114)
#define PCIE_AEC_CR			(PCIE_CONFIGURATION_REGISTERS + 0x118)
#define PCIE_HLR1			(PCIE_CONFIGURATION_REGISTERS + 0x11C)
#define PCIE_HLR2			(PCIE_CONFIGURATION_REGISTERS + 0x120)
#define PCIE_HLR3			(PCIE_CONFIGURATION_REGISTERS + 0x124)
#define PCIE_HLR4			(PCIE_CONFIGURATION_REGISTERS + 0x128)
#define PCIE_RECR			(PCIE_CONFIGURATION_REGISTERS + 0x12C)
#define PCIE_RESR			(PCIE_CONFIGURATION_REGISTERS + 0x130)
#define PCIE_ESIR			(PCIE_CONFIGURATION_REGISTERS + 0x134)
#define PCIE_VC_ECH			(PCIE_CONFIGURATION_REGISTERS + 0x140)
#define PCIE_PVC1			(PCIE_CONFIGURATION_REGISTERS + 0x144)
#define PCIE_PVC2			(PCIE_CONFIGURATION_REGISTERS + 0x148)
#define PCIE_PVCCRSR			(PCIE_CONFIGURATION_REGISTERS + 0x14C)
#define PCIE_VC0_RC			(PCIE_CONFIGURATION_REGISTERS + 0x150)
#define PCIE_VC0_RC0			(PCIE_CONFIGURATION_REGISTERS + 0x154)
#define PCIE_VC0_RSR0			(PCIE_CONFIGURATION_REGISTERS + 0x158)
#define PCIE_ALTRT			(PCIE_CONFIGURATION_REGISTERS + 0x700)
#define PCIE_OMR			(PCIE_CONFIGURATION_REGISTERS + 0x704)
#define PCIE_PFLR			(PCIE_CONFIGURATION_REGISTERS + 0x708)
#define PCIE_AFR			(PCIE_CONFIGURATION_REGISTERS + 0x70C)
#define PCIE_PLCR			(PCIE_CONFIGURATION_REGISTERS + 0x710)
#define PCIE_LSR			(PCIE_CONFIGURATION_REGISTERS + 0x714)
#define PCIE_SNR			(PCIE_CONFIGURATION_REGISTERS + 0x718)
#define PCIE_STRFMR			(PCIE_CONFIGURATION_REGISTERS + 0x71C)
#define PCIE_FMR2			(PCIE_CONFIGURATION_REGISTERS + 0x720)
#define PCIE_DBR0			(PCIE_CONFIGURATION_REGISTERS + 0x728)
#define PCIE_DBR1			(PCIE_CONFIGURATION_REGISTERS + 0x72C)
#define PCIE_TPFCS			(PCIE_CONFIGURATION_REGISTERS + 0x730)
#define PCIE_TNPFCS			(PCIE_CONFIGURATION_REGISTERS + 0x734)
#define PCIE_TCFCS			(PCIE_CONFIGURATION_REGISTERS + 0x738)
#define PCIE_QSR			(PCIE_CONFIGURATION_REGISTERS + 0x73C)
#define PCIE_VCTAR1			(PCIE_CONFIGURATION_REGISTERS + 0x740)
#define PCIE_VCTAR2			(PCIE_CONFIGURATION_REGISTERS + 0x744)
#define PCIE_VC0_PRQCR			(PCIE_CONFIGURATION_REGISTERS + 0x748)
#define PCIE_VC0_NPRQCR			(PCIE_CONFIGURATION_REGISTERS + 0x74C)
#define PCIE_VC0_CRQCR			(PCIE_CONFIGURATION_REGISTERS + 0x750)
#define PCIE_VC0_PBD			(PCIE_CONFIGURATION_REGISTERS + 0x7A8)
#define PCIE_VC0_NPBD			(PCIE_CONFIGURATION_REGISTERS + 0x7AC)
#define PCIE_VC0_CBD			(PCIE_CONFIGURATION_REGISTERS + 0x7B0)
#define PCIE_PHYSR			(PCIE_CONFIGURATION_REGISTERS + 0x810)
#define PCIE_PHYCR			(PCIE_CONFIGURATION_REGISTERS + 0x814)

/* PCIE_RESR */
#define PCIE_RESR_ADVANCED_ERR_INT_MSG_NUM_MASK	(0x1F << 27)
#define PCIE_RESR_FATAL_ERR_MSG_RECEIVED	(1 << 6)
#define PCIR_RESR_NON_FATAL_ERR_MSG_RECEIVED	(1 << 5)
#define PCIE_RESR_FIRST_RX_UNCORRECTABLE_ERR_IS_FATAL	(1 << 4)
#define PCIE_RESR_MULTIPLE_ERR_RX		(1 << 3)
#define PCIE_RESR_ERR_RX			(1 << 2)
#define PCIE_RESR_MULTIPLE_CORRECTABLE_ERR	(1 << 1)
#define PCIE_RESR_CORRECTABLE_ERR_RX		1

/* PCIE_INTRBCTRL */
#define PCIE_INTRBCTRL_RESET_SECONDARY	(1 << 22)
#define PCIE_INTRBCTRL_VGA_16BIT_DECODE	(1 << 20)
#define PCIE_INTRBCTRL_VGA_ENABLE	(1 << 19)
#define PCIE_INTRBCTRL_ISA_ENABLE	(1 << 18)
#define PCIE_INTRBCTRL_SERR_ENABLE	(1 << 17)
#define PCIE_INTRBCTRL_PARITY_ERR_RES	(1 << 16)
#define PCIE_INTRBCTRL_INT_PIN_MASK	(0xFF << 8)

/* PCIE_MCAPR */
#define PCIE_MCAPR_ADDR64		(1 << 23)
#define PCIE_MCAPR_MME_MASK		(7 << 20)
#define PCIE_MCAPR_MME_CAPABLE_MASK	(7 << 17)
#define PCIE_MCAPR_MM_CAP_SHIFT		17
#define PCIE_MCAPR_MSI_ENABLE		(1 << 16)
#define PCIE_MCAPR_MSI_CAP_POINTER_MASK	(0xFF << 8)
#define PCIE_MCAPR_MSI_CAP_ID_MASK	0xFF

/* PCIE_MA */
#define PCIE_MESSAGE_ADDRESS_MASK	0xFFFFFFFC
/* PCIE_MD */
#define PCIE_MESSAGE_DATA_MASK		0xFFFF
/* PCIE_XCAP */
#define PCIE_CAP_INT_MESSAGE_NUM_MASK	(0x1F << 25)
#define PCIE_CAP_SLOT_IMPLEMENTED	(1 << 24)
#define PCIE_CAP_NEXT_CAP_POINTER_MASK	(0xFF << 8)
#define PCIE_CAP_ID			0xFF
/* PCIE_DCAP */
#define PCIE_DCAP_ROLE_BASE_ERR_ENABLE	(1 << 15)
#define PCIE_DCAP_DP_L1_LATENCY_MASK	(7 << 9)
#define PCIE_DCAP_DP_L0S_LATENCY_MASK	(7 << 6)
#define PCIE_DCAP_EXTENDED_TAG_FILED	(1 << 5)
#define PCIE_DCAP_PHANTOM_FUNC_MASK	(3 << 3)
#define PCIE_DCAP_MAX_PAYLOAD_SIZE_MASK	7

/* PCIE_DCTLSTS */
#define PCIE_DCTLSTS_UNSUPPORTED_REQ	(1 << 19)
#define PCIE_DCTLSTS_FATAL_ERROR	(1 << 18)
#define PCIE_DCTLSTS_NONFATAL_ERROR	(1 << 17)
#define PCIE_DCTLSTS_CORRECTABLE_ERROR	(1 << 16)
#define PCIE_DCTLSTS_MAX_READ_SIZE_MASK	(7 << 12)
#define PCIE_DCTLSTS_MAX_PAYLOAD_SIZE_MASK	(7 << 5)
#define PCIE_DCTLSTS_RELAXED_ORDERING_EN	(1 << 4)
#define PCIE_DCTLSYS_UNSUPPORTED_REQ_EN	(1 << 3)
#define PCIE_DCTLSTS_FATAL_ERROR_ENABLE	(1 << 2)
#define PCIE_DCTLSTS_NONFATAL_ERR_EN	(1 << 1)
#define PCIE_DCTLSTS_CORRECTABLE_ERR_EN	1

/* PCIE_LCTLSTS */
#define PCIE_LCTLSTS_RETRAIN_PENDING	(1 << 27)
#define PCIE_LCTLSTS_RETRIAN_LINK	(1 << 5)
#define PCIE_LCTLSTS_LINK_DISABLE	(1 << 4)
#define PCIE_LCTLSTS_RCB128		(1 << 3)
#define PCIE_LCTLSTS_ACTIVE_PM_MASK	3
#define PCIE_LCTLSTS_ACTIVE_PM_DISABLED	0
#define PCIE_LCTLSTS_ACTIVE_PM_L0S	1
#define PCIE_LCTLSTS_ACTIVE_PM_L1	2
#define PCIE_LCTLSTS_ACTIVE_PM_L1L0S	3

/* PCIE_RCTLCAP */
#define PCIE_RCTLCAP_PME_INT_ENABLE	(1 << 3)
#define PCIE_RCTLCAP_SYSERR_ON_FATALERR	(1 << 2)
#define PCIE_RCTLCAP_SYSERR_ON_NONFATAL_ERR	(1 << 1)
#define PCIE_RCTLCAP_SYSERR_ON_CORRECTABLE_ERR	1

/* PCIE_RSTS */
#define PCIE_RSTS_PME_PENDING		(1 << 17)
#define PCIE_RSTS_PME_STATUS		(1 << 16)
#define PCIE_RSTS_PME_REQUESTOR_ID_MAKS	0xFFFF

/* PCIE_UEMR/PCIE_UESR */
#define PCIE_UNSUPPORTED_REQUEST	(1 << 20)
#define PCIE_ECRC			(1 << 19)
#define PCIE_MALFORNED_TLP		(1 << 18)
#define PCIE_RECEIVER_OVERFLOW		(1 << 17)
#define PCIE_UNEXPECTED_COMPLETION	(1 << 16)
#define PCIE_COMPLETOR_ABORT		(1 << 15)
#define PCIE_COMPLETION_TIMEOUT		(1 << 14)
#define PCIE_FLOW_CONTROL_PROTOCOL_ERR	(1 << 13)
#define PCIE_POISONED_TLP		(1 << 12)
#define PCIE_SURPRISED_DOWN_ERROR	(1 << 5)
#define PCIE_DATA_LINK_PROTOCOL_ERR	(1 << 4)

/* PCIE_CESR */
#define PCIE_ADVISORY_NONFTAL_ERROR	(1 << 13)
#define PCIE_REPLAY_TIMER_TIMEOUT_ERROR	(1 << 12)
#define PCIE_REPLAY_NUM_ROLLOVER	(1 << 8)
#define PCIE_BAD_DLLP			(1 << 7)
#define PCIE_BAD_TLP			(1 << 6)
#define PCIE_RECEIVOR_ERROR		1

/* PCIE_AEC_CR */
#define PCIE_AECCR_ECRC_ENABLE		(1 << 8)
#define PCIE_AECCR_ECRC_CAPABLE		(1 << 7)
#define PCIE_AECCR_ECRC_GENERATE_ENABLE	(1 << 6)
#define PCIE_AECCR_ECRC_GENERATE_CAP	(1 << 5)
#define PCIE_AECCR_FIRST_ERROR_MASK	0x1F

/* PCIE_RECR */
#define PCIE_RECR_FATAL_ERR_REPORT_EN	(1 << 2)
#define PCIE_RECR_NONFATAL_ERR_REPORT_EN	(1 << 1)
#define PCIE_RECR_CORRECTABLE_ERR_REPORT_EN	1

/* PCIE_ESIR */
#define PCIE_ESIR_FATAL_NONFATAL_SOURCE_ID_MASK	0xFFFF0000
#define PCIE_ESIR_CORRECTABLE_ERR_SOURCE_ID_MASK	0xFFFF

/* PCIE_PVC1 */
#define PCIE_PVC1_PORT_ARB_TABLE_ENTRY_SIZE_MASK	(3 << 10)
#define PCIE_PVC1_REFERENCE_CLOCK_MASK	(3 << 8)
#define PCIE_PVC1_LOW_PRIORITY_EXT_VC_COUNT_MASK	(7 << 4)
#define PCIE_PVC1_EXT_VC_COUNT_MASK	7

/* PCIE_PVC2 */
#define PCIE_PVC2_VC_ARBITRATION_SCHEME_MASK	0xF
#define PCIE_PVC2_VC_ARB_16P_WRR		1
#define PCIE_PVC2_VC_ARB_32P_WRR		2
#define PCIE_PVC2_VC_ARB_64P_WRR		4
#define PCIE_PVC2_VC_ARB_128P_WRR		8

/* PCIE_VC0_RC */
#define PCIE_VC0RC_MAXIMUM_TIME_SLOTS_MASK	(0x7F << 16)
#define PCIE_VC0RC_REJECT_SNOOP		(1 << 15)
#define PCIE_VC0RC_PORT_ARBITRATION_SCHEME_MASK	0xFF
#define PCIE_VC0RC_PORT_ARB_HARDWARE_FIXED	1
#define PCIE_VC0RC_PORT_ARB_32P_WRR		2
#define PCIE_VC0RC_PORT_ARB_64P_WRR		4
#define PCIE_VC0RC_PORT_ARB_128P_WRR		8
#define PCIE_VC0RC_PORT_ARB_TB_128P_WRR		0x10
#define PCIE_VC0RC_PORT_ARB_TB_256P_WRR		0x20

/* PCIE_VC0_RC0 */
#define PCIE_VC0_RC0_TRANSACTION_CLASS_MASK	0xFF

/* PCIE_VC0_RSR0 */
#define PCIE_VC0_RSR0_VC_NEG_PENDING		(1 << 17)

/* PCIE_PFLR */
#define PCIE_PFLR_LINK_STATE_MASK		(0x3F << 16)
#define PCIE_PFLR_FORCE_LINK			(1 << 15)
#define PCIE_PFLR_LINK_NUMBER_MASK		0xFF

/* PCIE_AFR */
#define PCIE_AFR_L1_ENTRY_LATENCY_MASK		(7 << 27)
#define PCIE_AFR_L0S_ENTRY_LATENCY_MASK		(7 << 24)
#define PCIE_AFR_CN_FTS_MASK			(0xFF << 16)
#define PCIE_AFR_NFTS_MASK			(0xFF << 9)
#define PCIE_AFR_AF_MASK			0xFF

/* PCIE_PLCR */
#define PCIE_PLCR_CORRUPTED_CRC_ENABLE		(1 << 25)
#define PCIE_PLCR_LINK_MODE_MASK		(0x3F << 16)
#define PCIE_PLCR_FAST_LINK_SIMULATION_ENABLE	(1 << 7)
#define PCIE_PLCR_DLL_LINK_ENABLE		(1 << 5)
#define PCIE_PLCR_LTSSM_HOT_RESET		(1 << 3)
#define PCIE_PLCR_LOOPBACK_ENABLE		(1 << 2)
#define PCIE_PLCR_SCRAMBLE_DISABLE		(1 << 1)
#define PCIE_PLCR_OTHER_MESSAGE_REQUEST		1

/* PCIE_LSR */
#define PCIE_LSR_LAN_DESKEW_DISABLE		(1 << 31)
#define PCIE_LSR_ACKNAK_DISABLE			(1 << 25)
#define PCIE_LSR_FLOW_CONTROL_DISABLE		(1 << 24)
#define PCIE_LSR_LANE_SKEW_NUMNER_MASK		0xFFFFFF

/* PCIE_SNR */
#define PCIE_SNR_FLOW_CONTROL_TIMER_MASK	(0x1F << 24)
#define PCIE_SNR_ACKNAL_LATENCY_TIMER_MASK	(0x1F << 19)
#define PCIE_SNR_REPLAY_TIMER_MASK		(0x1F << 14)
#define PCIE_SNR_SKP_MASK			(0x7  << 8)
#define PCIE_SNR_TS_MASK			0xF

/* PCIE_STRFMR */
#define PCIE_STRFMR_RX_CFG_REQUEST_ENABLE	(1 << 31)
#define PCIE_STRFMR_RX_IO_REQUEST_ENABLE	(1 << 30)
#define PCIE_STRFMR_RX_MESSAGE_TLP_NO_DROP	(1 << 29)
#define PCIE_STRFMR_CPL_TLP_CRC_ERR_OK		(1 << 28)
#define PCIE_STRFMR_TLP_CRC_ERR_OK		(1 << 27)
#define PCIE_STRFMR_CPL_LENGTH_MISMATCH_ERR_OK	(1 << 26)
#define PCIE_STRFMR_CPL_ATTR_MISMATCH_ERR_OK	(1 << 25)
#define PCIE_STRFMR_CPL_TRAFFIC_CLASS_MISMATCH_OK	(1 << 24)
#define PCIE_STRFMR_CPL_FUNC_MISMATCH_OK	(1 << 23)
#define PCIE_STRFMR_CPL_REQUESTOR_ID_MISMATCH_OK	(1 << 22)
#define PCIE_STRFMR_CPL_TAG_ERR_RULES_OK	(1 << 21)
#define PCIE_STRFMR_LOCKED_REQUEST_OK		(1 << 20)
#define PCIE_STRFMR_TYPE1_CFG_REQUEST_OK	(1 << 19)
#define PCIE_STRFMR_BAR_MATCH_OK		(1 << 18)
#define PCIE_STRFMR_POISONED_TLP_OK		(1 << 17)
#define PCIE_STRFMR_TLP_FUNC_MISMATCH_OK	(1 << 16)
#define PCIE_STRFMR_FLOW_CONTROL_WATCHDOG_DISABLE	(1 << 15)
#define PCIE_STRFMR_SKIP_INTERVAL_MASK		0x7FF

/* PCIE_FMR2 */
#define PCIE_FMR2_VENDOR_MSG1_PASSED_TO_TRGT1	(1 << 1)
#define PCIE_FMR2_VENDOR_MSG0_PASSED_TO_TRGT1	1

/* PCIE_VC0_PRQCR */
#define PCIE_VC0_RX_QUEUES_STRICT_ORDERING	(1 << 31)
#define PCIE_VC0_TLP_TYPE_ORDERING_PCIE_BASE1_1	(1 << 30)
#define PCIE_VC0_POSTED_TLP_QUEUE_MODE_MASK	(7 << 21)
#define PCIE_VC0_POSTED_TLP_QUEUE_BYPASS	4
#define PCIE_VC0_POSTED_TLP_QUEUE_CUT_THROUGH	2
#define PCIE_VC0_POSTED_TLP_QUEUE_STORE_AND_FORWARD	1
#define PCIE_VC0_POSTED_HEADER_CREDITS_MASK	(0xFF << 12)
#define PCIE_VC0_POSTED_DATA_CREDITS_MASK	0xFFF

/* PCIE_VC0_NPRQCR */
#define PCIE_VC0_NONPOSTED_TLP_QUEU_MODE_MASK	(7 << 21)
#define PCIE_VC0_NONPOSTED_HEADER_CREDITS_MASK	(0xFF << 12)
#define PCIE_VC0_NONPOSTED_DATA_CREDITS_MASK	0xFFF

/* PCIE_VC0_CRQCR */
#define PCIE_VC0_CPL_QUEUE_MODE_MASK		(7 << 21)
#define PCIE_VC0_CPL_HEDER_CREDITS_MASK		(0xFF << 12)
#define PCIE_VC0_CPL_DATA_CREDITS_MASK		0xFFF

/* PCIE_VC0_PBD */
#define PCIE_VC0_POSTED_HEADER_QUEUE_DEPTH_MASK	(0x3FF << 16)
#define PCIE_VC0_PASTED_DATA_QUEUE_DEPTH_MASK	0x3FFF

/* PCIE_VC0_NPBD */
#define PCIE_VC0_NONPOSTED_HEADER_QUEUE_DEPTH_MASK	(0x3FF << 16)
#define PCIE_VC0_NONPOSTED_DATA_QUEUE_DEPTH_MASK	0x3FFF

/* PCIE_VC0_CBD */
#define PCIE_VC0_CPL_HEADER_QUEUE_DEPTH_MASK	(0x3FF << 16)
#define PCIE_VC0_CPL_DATA_QUEUE_DEPTH_MASK	0x3FFF

/* PCIE_RC_CCR */
#define PCIE_RC_CCR_LTSSM_ENABLE	1

/* PCIE_RC_DR */
#define PCIE_RC_DR_AUX_POWER_ENABLED	(1 << 14)
#define PCIE_RC_DR_PME_EVENT_ENABLED	(1 << 13)
#define PCIE_RC_DR_PM_STATE_ENABLED	(1 << 12)
#define PCIE_RC_DR_PM_DSTATE_MASK	(7 << 9)
#define PCIE_RC_DR_LTSSM_STATE_MASK	(0x1F << 4)
#define PCIE_RC_DR_CURRENT_POWER_STATE_MASK	(7 << 1)
#define PCIE_RC_DR_DLL_UP		1

/* PCIE_PHY_SR */
#define PCIE_PHY_SR_LINK_UP			1

/* PCIE_IR_SR */
#define PCIE_IRSR_AE_INT_MSG_NUM_MASK	(0x1F << 27)
#define PCIE_IRSR_INT_MSG_NUM		(0x1F << 9)
#define PCIE_IRSR_AHB_BR_LOOKUP_ERROR_MASK	(3 << 4)
#define PCIE_IRSR_HOTPLUG_MSI		(1 << 3)
#define PCIE_IRSR_HOTPLUG_PME_WAKE	(1 << 2)
#define PCIE_IRSR_MSI_CAUSED_BY_PME	(1 << 1)

/* PCIE_MSG_CR */
#define PCIE_MSG_CR_GENERATE_UNLOCK_MSG	(1 << 1)
#define PCIE_MSG_CR_GENERATE_PME_OFF_MSG	1

/* PCIE_VDM_RID */
#define PCIE_VDM_REQUEST_ID_MASK	0xFFFF

/* PCIE_ASPM_CR */
#define PCIE_ASPM_CR_ENTER_L1		(1 << 2)
#define PCIE_ASPM_CR_EXIT_L1		(1 << 1)
#define PCIE_ASPM_CR_HOT_RESET		1

/* PCIE_VM_MSG_DW0 */
#define PCIE_VM_MSG_LENGTH_MASK		(0x3FF << 22)
#define PCIE_VM_MSG_TLP_DIGEST_SET	(1 << 21)
#define PCIE_VM_MSG_TLP_POISON_SET	(1 << 20)
#define PCIE_VM_MSG_ATTRIBUTE_MASK	(3 << 18)
#define PCIE_VM_MSG_TRAFFIC_CLASS_MASk	(7 << 12)
#define PCIE_VM_MSG_FORMAT_MASK		(3 << 5)
#define PCIE_VM_MSG_HEADER_TYPE_MASK	0x1F

/* PCIE_VM_MSG_DW1 */
#define PCIE_VM_MSG_HEADER_TAG_MASK	(0xFF << 24)
#define PCIE_VM_MSG_HEADER_CODE_MASK	(0xFF << 16)
#define PCIE_VM_MSG_FUNCTION_NUM_MASK	(0x7 << 8)

/* PCIE_VM_MSG_REQR */
#define PCIE_VENDOR_MESSAGE_REQUEST	1

/* PCIE_IRNEN */
#define PCIE_IRNEN_BEACON		(1 << 16)
#define PCIE_IRNEN_INTD			(1 << 15)
#define PCIE_IRNEN_INTC			(1 << 14)
#define PCIE_IRNEN_INTB			(1 << 13)
#define PCIE_IRNEN_INTA			(1 << 12)
#define PCIE_IRNEN_AHB_BR_FATAL_ERR	(1 << 11)
#define PCIE_IRNEN_RESET_REQUEST	(1 << 10)
#define PCIE_IRNEN_RX_PME_TURNOFF_ACK	(1 << 9)
#define PCIE_IRNEN_RX_PME_MSG		(1 << 8)
#define PCIE_IRNEN_RX_FATAL_ERR_MSG	(1 << 7)
#define PCIE_IRNEN_RX_NON_FATAL_ERR_MSG	(1 << 6)
#define PCIE_IRNEN_RX_CORRECTABLE_ERR_MSG	(1 << 5)
#define PCIE_IRNEN_RX_VDM_MSG		(1 << 4)
#define PCIE_IRNEN_HOTPLUG_INT		(1 << 3)
#define PCIE_IRNEN_PME_INT		(1 << 2)
#define PCIE_IRNEN_AER_MSIX_INT		(1 << 1)
#define PCIR_IRNEN_AER_REPORT_INT	1

/* Maximum payload size supported */
#define PCIE_MAX_PAYLOAD_128		0
#define PCIE_MAX_PAYLOAD_256		1
#define PCIE_MAX_PAYLOAD_512		2
#define PCIE_MAX_PAYLOAD_1024		3
#define PCIE_MAX_PAYLOAD_2048		4
#define PCIE_MAX_PAYLOAD_4096		5

#define PCIE_PVCCRSR_LOAD_VC_ARB_TABLE	1
/* PCIe PDI PHY register definition */
#define PCIE_PHY_TX1_CTRL1       (PCIE_PDI_BASE + (0x30 << 1))
#define PCIE_PHY_TX1_CTRL2       (PCIE_PDI_BASE + (0x31 << 1))
#define PCIE_PHY_TX1_CTRL3       (PCIE_PDI_BASE + (0x32 << 1))
#define PCIE_PHY_TX1_A_CTRL1     (PCIE_PDI_BASE + (0x33 << 1))
#define PCIE_PHY_TX1_A_CTRL2     (PCIE_PDI_BASE + (0x34 << 1))

#define PCIE_PHY_TX2_CTRL2       (PCIE_PDI_BASE + (0x39 << 1))
#define PCIE_PHY_TX2_A_CTRL1     (PCIE_PDI_BASE + (0x3B << 1))
#define PCIE_PHY_TX2_A_CTRL2     (PCIE_PDI_BASE + (0x3C << 1))

#define PCIE_PHY_RX1_CTRL1       (PCIE_PDI_BASE + (0x50 << 1))
#define PCIE_PHY_RX1_CDR         (PCIE_PDI_BASE + (0x52 << 1))
#define PCIE_PHY_RX1_EI          (PCIE_PDI_BASE + (0x53 << 1))

#define	PCIE_PHY_PLL_CTRL1	     (PCIE_PDI_BASE + (0x22 << 1))
#define	PCIE_PHY_PLL_CTRL2       (PCIE_PDI_BASE + (0x23 << 1))
#define	PCIE_PHY_PLL_CTRL3	     (PCIE_PDI_BASE + (0x24 << 1))
#define	PCIE_PHY_PLL_CTRL4	     (PCIE_PDI_BASE + (0x25 << 1))
#define	PCIE_PHY_PLL_CTRL5	     (PCIE_PDI_BASE + (0x26 << 1))
#define	PCIE_PHY_PLL_CTRL6	     (PCIE_PDI_BASE + (0x27 << 1))
#define	PCIE_PHY_PLL_CTRL7	     (PCIE_PDI_BASE + (0x28 << 1))
#define	PCIE_PHY_PLL_A_CTRL1	 (PCIE_PDI_BASE + (0x29 << 1))
#define	PCIE_PHY_PLL_A_CTRL2	 (PCIE_PDI_BASE + (0x2A << 1))
#define	PCIE_PHY_PLL_A_CTRL3	 (PCIE_PDI_BASE + (0x2B << 1))
#define	PCIE_PHY_PLL_STATUS      (PCIE_PDI_BASE + (0x2C << 1))
/* PCI CONTROLLER REGISTER ADDRESS MAP */
#define PCI_CR_CLK_CTRL_REG         	(PCI_CONTROLLER_REG + 0x0000)
#define PCI_CR_PCI_ID_REG	        (PCI_CONTROLLER_REG + 0x0004)
#define PCI_CR_SFT_RST_REG	        (PCI_CONTROLLER_REG + 0x0010)
#define PCI_CR_PCI_FPI_ERR_ADDR_REG 	(PCI_CONTROLLER_REG + 0x0014)
#define PCI_CR_FPI_PCI_ERR_ADDR_REG 	(PCI_CONTROLLER_REG + 0x0018)
#define PCI_CR_FPI_ERR_TAG_REG	    	(PCI_CONTROLLER_REG + 0x001C)
#define PCI_CR_PCI_IRR_REG	        (PCI_CONTROLLER_REG + 0x0020)
#define PCI_CR_PCI_IRA_REG	        (PCI_CONTROLLER_REG + 0x0024)
#define PCI_CR_PCI_IRM_REG	        (PCI_CONTROLLER_REG + 0x0028)
#define PCI_CR_PCI_EOI_REG	        (PCI_CONTROLLER_REG + 0x002C)
#define PCI_CR_PCI_MOD_REG 	        (PCI_CONTROLLER_REG + 0x0030)
#define PCI_CR_DV_ID_REG	        (PCI_CONTROLLER_REG + 0x0034)
#define PCI_CR_SUBSYS_ID_REG	    	(PCI_CONTROLLER_REG + 0x0038)
#define PCI_CR_PCI_PM_REG           	(PCI_CONTROLLER_REG + 0x003C)
#define PCI_CR_CLASS_CODE1_REG      	(PCI_CONTROLLER_REG + 0x0040)
#define PCI_CR_BAR11MASK_REG	    	(PCI_CONTROLLER_REG + 0x0044)
#define PCI_CR_BAR12MASK_REG        	(PCI_CONTROLLER_REG + 0x0048)
#define PCI_CR_BAR13MASK_REG        	(PCI_CONTROLLER_REG + 0x004C)
#define PCI_CR_BAR14MASK_REG        	(PCI_CONTROLLER_REG + 0x0050)
#define PCI_CR_BAR15MASK_REG        	(PCI_CONTROLLER_REG + 0x0054)
#define PCI_CR_BAR16MASK_REG        	(PCI_CONTROLLER_REG + 0x0058)
#define PCI_CR_CIS_PT1_REG	        (PCI_CONTROLLER_REG + 0x005C)
#define PCI_CR_SUBSYS_ID1_REG	    	(PCI_CONTROLLER_REG + 0x0060)
#define PCI_CR_PCI_ADDR_MAP11_REG   	(PCI_CONTROLLER_REG + 0x0064)
#define PCI_CR_PCI_ADDR_MAP12_REG   	(PCI_CONTROLLER_REG + 0x0068)
#define PCI_CR_PCI_ADDR_MAP13_REG   	(PCI_CONTROLLER_REG + 0x006C)
#define PCI_CR_PCI_ADDR_MAP14_REG   	(PCI_CONTROLLER_REG + 0x0070)
#define PCI_CR_PCI_ADDR_MAP15_REG   	(PCI_CONTROLLER_REG + 0x0074)
#define PCI_CR_PCI_ADDR_MAP16_REG   	(PCI_CONTROLLER_REG + 0x0078)
#define PCI_CR_FPI_SEG_EN_REG       	(PCI_CONTROLLER_REG + 0x007C)
#define PCI_CR_PC_ARB_REG	        (PCI_CONTROLLER_REG + 0x0080)
#define PCI_CR_BAR21MASK_REG	    	(PCI_CONTROLLER_REG + 0x0084)
#define PCI_CR_BAR22MASK_REG        	(PCI_CONTROLLER_REG + 0x0088)
#define PCI_CR_BAR23MASK_REG        	(PCI_CONTROLLER_REG + 0x008C)
#define PCI_CR_BAR24MASK_REG        	(PCI_CONTROLLER_REG + 0x0090)
#define PCI_CR_BAR25MASK_REG        	(PCI_CONTROLLER_REG + 0x0094)
#define PCI_CR_BAR26MASK_REG        	(PCI_CONTROLLER_REG + 0x0098)
#define PCI_CR_CIS_PT2_REG	        (PCI_CONTROLLER_REG + 0x009C)
#define PCI_CR_SUBSYS_ID2_REG	    	(PCI_CONTROLLER_REG + 0x00A0)
#define PCI_CR_PCI_ADDR_MAP21_REG   	(PCI_CONTROLLER_REG + 0x00A4)
#define PCI_CR_PCI_ADDR_MAP22_REG   	(PCI_CONTROLLER_REG + 0x00A8)
#define PCI_CR_PCI_ADDR_MAP23_REG   	(PCI_CONTROLLER_REG + 0x00AC)
#define PCI_CR_PCI_ADDR_MAP24_REG   	(PCI_CONTROLLER_REG + 0x00B0)
#define PCI_CR_PCI_ADDR_MAP25_REG   	(PCI_CONTROLLER_REG + 0x00B4)
#define PCI_CR_PCI_ADDR_MAP26_REG   	(PCI_CONTROLLER_REG + 0x00B8)
#define PCI_CR_FPI_ADDR_MASK_REG    	(PCI_CONTROLLER_REG + 0x00BC)
#define PCI_CR_FCI_ADDR_MAP0_REG    	(PCI_CONTROLLER_REG + 0x00C0)
#define PCI_CR_FCI_ADDR_MAP1_REG    	(PCI_CONTROLLER_REG + 0x00C4)
#define PCI_CR_FCI_ADDR_MAP2_REG    	(PCI_CONTROLLER_REG + 0x00C8)
#define PCI_CR_FCI_ADDR_MAP3_REG    	(PCI_CONTROLLER_REG + 0x00CC)
#define PCI_CR_FCI_ADDR_MAP4_REG    	(PCI_CONTROLLER_REG + 0x00D0)
#define PCI_CR_FCI_ADDR_MAP5_REG    	(PCI_CONTROLLER_REG + 0x00D4)
#define PCI_CR_FCI_ADDR_MAP6_REG    	(PCI_CONTROLLER_REG + 0x00D8)
#define PCI_CR_FCI_ADDR_MAP7_REG    	(PCI_CONTROLLER_REG + 0x00DC)
#define PCI_CR_FCI_ADDR_MAP11lo_REG 	(PCI_CONTROLLER_REG + 0x00E0)
#define PCI_CR_FCI_ADDR_MAP11hg_REG 	(PCI_CONTROLLER_REG + 0x00E4)
#define PCI_CR_FCI_BURST_LENGTH_REG 	(PCI_CONTROLLER_REG + 0x00E8)
#define PCI_CR_PCI_SET_SERR_REG     	(PCI_CONTROLLER_REG + 0x00EC)
#define PCI_CR_DMA_FPI_ST_ADDR_REG  	(PCI_CONTROLLER_REG + 0x00F0)
#define PCI_CR_DMA_PCI_ST_ADDR_REG  	(PCI_CONTROLLER_REG + 0x00F4)
#define PCI_CR_DMA_TRAN_CNT_REG     	(PCI_CONTROLLER_REG + 0x00F8)
#define PCI_CR_DMA_TRAN_CTL_REG     	(PCI_CONTROLLER_REG + 0x00FC)

/* PCI CONFIGURATION SPACE REGISTER Base Address */
#define EXT_PCIE1_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x0800
#define EXT_PCIE2_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x1000
#define EXT_PCIE3_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x1800
#define EXT_PCIE4_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x2000
#define EXT_PCIE5_CONFIG_SPACE_BASE_ADDR   	PCIE_CFG_BASE + 0x2800
#define EXT_PCIE6_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x3000
#define EXT_PCIE7_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x3800
#define EXT_PCIE8_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x4000
#define EXT_PCIE9_CONFIG_SPACE_BASE_ADDR    	PCIE_CFG_BASE + 0x4800
#define EXT_PCIE10_CONFIG_SPACE_BASE_ADDR   	PCIE_CFG_BASE + 0x5000
#define EXT_PCIE11_CONFIG_SPACE_BASE_ADDR   	PCIE_CFG_BASE + 0x5800
#define EXT_PCIE12_CONFIG_SPACE_BASE_ADDR   	PCIE_CFG_BASE + 0x6000
#define EXT_PCIE13_CONFIG_SPACE_BASE_ADDR   	PCIE_CFG_BASE + 0x6800
#define EXT_PCIE14_CONFIG_SPACE_BASE_ADDR   	PCIE_CFG_BASE + 0x7000
#define EXT_PCIE15_CONFIG_SPACE_BASE_ADDR   	PCIE_CFG_BASE + 0x7800
#define EXT_PCIE_CARDBUS_CONFIG_SPACE_BASE_ADDR  	PCIE_CFG_BASE + 0XF000

/* PCI CONFIGURATION SPACE REGISTER Base Address */
#define EXT_PCI1_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x0800
#define EXT_PCI2_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x1000
#define EXT_PCI3_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x1800
#define EXT_PCI4_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x2000
#define EXT_PCI5_CONFIG_SPACE_BASE_ADDR   	PCI_CONFIG_SPACE + 0x2800
#define EXT_PCI6_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x3000
#define EXT_PCI7_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x3800
#define EXT_PCI8_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x4000
#define EXT_PCI9_CONFIG_SPACE_BASE_ADDR    	PCI_CONFIG_SPACE + 0x4800
#define EXT_PCI10_CONFIG_SPACE_BASE_ADDR   	PCI_CONFIG_SPACE + 0x5000
#define EXT_PCI11_CONFIG_SPACE_BASE_ADDR   	PCI_CONFIG_SPACE + 0x5800
#define EXT_PCI12_CONFIG_SPACE_BASE_ADDR   	PCI_CONFIG_SPACE + 0x6000
#define EXT_PCI13_CONFIG_SPACE_BASE_ADDR   	PCI_CONFIG_SPACE + 0x6800
#define EXT_PCI14_CONFIG_SPACE_BASE_ADDR   	PCI_CONFIG_SPACE + 0x7000
#define EXT_PCI15_CONFIG_SPACE_BASE_ADDR   	PCI_CONFIG_SPACE + 0x7800
#define EXT_PCI_CARDBUS_CONFIG_SPACE_BASE_ADDR  	PCI_CONFIG_SPACE + 0XF000

/* PCIE CONFIGURATION SPACE REGISTER ADDRESS MAP */
#define PCIE_CS_DEV_VEN_ID_REG        (PCIE_CFG_BASE + 0x0000)
#define PCIE_CS_STS_CMD_REG	         (PCIE_CFG_BASE + 0x0004)
#define PCIE_CS_CL_CODE_REVIDG        (PCIE_CFG_BASE + 0x0008)
#define PCIE_CS_BST_HT_LT_CLS_REG     (PCIE_CFG_BASE + 0x000C)
#define PCIE_CS_BASE_ADDR1_REG	     (PCIE_CFG_BASE + 0x0010)
#define PCIE_CS_BASE_ADDR2_REG        (PCIE_CFG_BASE + 0x0014)
#define PCIE_CS_BASE_ADDR3_REG        (PCIE_CFG_BASE + 0x0018)
#define PCIE_CS_BASE_ADDR4_REG        (PCIE_CFG_BASE + 0x001C)
#define PCIE_CS_BASE_ADDR5_REG        (PCIE_CFG_BASE + 0x0020)
#define PCIE_CS_BASE_ADDR6_REG        (PCIE_CFG_BASE + 0x0024)
#define PCIE_CS_CARDBUS_CIS_PT_REG    (PCIE_CFG_BASE + 0x0028)
#define PCIE_CS_SUBSYS_VEN_ID_REG     (PCIE_CFG_BASE + 0x002C)
#define PCIE_CS_EXROM_BAS_ADDR_REG    (PCIE_CFG_BASE + 0x0030)
#define PCIE_CS_RES1_REG	             (PCIE_CFG_BASE + 0x0034)
#define PCIE_CS_RES2_REG	             (PCIE_CFG_BASE + 0x0038)
#define PCIE_CS_LAT_GNT_INTR_REG      (PCIE_CFG_BASE + 0x003C)
#define PCIE_CS_PM_PT_CPID_REG        (PCIE_CFG_BASE + 0x0040)
#define PCIE_CS_DAT_PMCSR_PM_REG	     (PCIE_CFG_BASE + 0x0044)
#define PCIE_CS_RES3_REG              (PCIE_CFG_BASE + 0x0048)
#define PCIE_CS_RES4_REG              (PCIE_CFG_BASE + 0x004C)
#define PCIE_CS_ERR_ADDR_PCIE_FPI_REG  (PCIE_CFG_BASE + 0x0050)
#define PCIE_CS_ERR_ADDR_FPI_PCIE_REG  (PCIE_CFG_BASE + 0x0054)
#define PCIE_CS_ERR_TAG_FPI_PCIE_REG   (PCIE_CFG_BASE + 0x0058)
#define PCIE_CS_PC_ARB_REG	         (PCIE_CFG_BASE + 0x005C)
#define PCIE_CS_FPI_PCIE_INT_STS_REG   (PCIE_CFG_BASE + 0x0060)
#define PCIE_CS_FPI_PCIE_INT_ACK_REG   (PCIE_CFG_BASE + 0x0064)
#define PCIE_CS_FPI_PCIE_INT_MASK_REG  (PCIE_CFG_BASE + 0x0068)
#define PCIE_CS_CARDBUS_CTL_STS_REG   (PCIE_CFG_BASE + 0x006C)

// PCIE CONTROLLER ADDRESS SPACE
#define PCIE_CA_PR_OFFSET 0xB8000000
#define PCIE_CA_PR_END    0xBBFFFFFF

// PCIE CONTROLLER REGISTER ADDRESS MASK
#define PCIE_CR_CLK_CTRL_MSK              0x82000000
#define PCIE_CR_PCIE_ID_MSK	    	     0x00000000
#define PCIE_CR_SFT_RST_MSK	    	     0x00000002
#define PCIE_CR_PCIE_FPI_ERR_ADDR_MSK 	 0x00000000
#define PCIE_CR_FCI_PCIE_ERR_ADDR_MSK 	 0x00000000
#define PCIE_CR_FPI_ERR_TAG_MSK	    	 0x00000000
#define PCIE_CR_PCIE_IRR_MSK	    	     0x07013B2F
#define PCIE_CR_PCIE_IRA_MSK	    	     0x07013B2F
#define PCIE_CR_PCIE_IRM_MSK	    	     0x07013B2F
#define PCIE_CR_PCIE_EOI_MSK	    	     0x07013B2F
#define PCIE_CR_PCIE_MOD_MSK 	    	     0x1107070F
#define PCIE_CR_DV_ID_MSK	    	     0x00000000
#define PCIE_CR_SUBSYS_ID_MSK	    	 0x00000000
#define PCIE_CR_PCIE_PM_MSK           	 0x0000001F
#define PCIE_CR_CLASS_CODE1_MSK      	 0x00000000
#define PCIE_CR_BAR11MASK_MSK	    	 0x8FFFFFF8
#define PCIE_CR_BAR12MASK_MSK        	 0x80001F08
#define PCIE_CR_BAR13MASK_MSK        	 0x8FF00008
#define PCIE_CR_BAR14MASK_MSK        	 0x8FFFFF08
#define PCIE_CR_BAR15MASK_MSK        	 0x8FFFFF08
#define PCIE_CR_BAR16MASK_MSK        	 0x8FFFFFF9
#define PCIE_CR_CIS_PT1_MSK	    	     0x03FFFFFF
#define PCIE_CR_SUBSYS_ID1_MSK	    	 0x00000000
#define PCIE_CR_PCIE_ADDR_MAP11_MSK   	 0x7FFF0001
#define PCIE_CR_PCIE_ADDR_MAP12_MSK   	 0x7FFFFF01
#define PCIE_CR_PCIE_ADDR_MAP13_MSK   	 0x7FF00001
#define PCIE_CR_PCIE_ADDR_MAP14_MSK   	 0x7FFFFF01
#define PCIE_CR_PCIE_ADDR_MAP15_MSK   	 0x7FF00001
#define PCIE_CR_PCIE_ADDR_MAP16_MSK   	 0x7FF00001
#define PCIE_CR_FPI_SEG_EN_MSK       	 0x000003FF
#define PCIE_CR_CLASS_CODE2_MSK      	 0x00000000
#define PCIE_CR_BAR21MASK_MSK	    	 0x800F0008
#define PCIE_CR_BAR22MASK_MSK        	 0x807F0008
#define PCIE_CR_BAR23MASK_MSK        	 0x8FF00008
#define PCIE_CR_BAR24MASK_MSK        	 0x8FFFFF08
#define PCIE_CR_BAR25MASK_MSK        	 0x8FFFFF08
#define PCIE_CR_BAR26MASK_MSK        	 0x8FFFFFF9
#define PCIE_CR_CIS_PT2_MSK	    	     0x03FFFFFF
#define PCIE_CR_SUBSYS_ID2_MSK	    	 0x00000000
#define PCIE_CR_PCIE_ADDR_MAP21_MSK   	 0x7FFE0001
#define PCIE_CR_PCIE_ADDR_MAP22_MSK   	 0x7FFF0001
#define PCIE_CR_PCIE_ADDR_MAP23_MSK   	 0x7FF00001
#define PCIE_CR_PCIE_ADDR_MAP24_MSK   	 0x7FFFFF01
#define PCIE_CR_PCIE_ADDR_MAP25_MSK   	 0x7FFFFF01
#define PCIE_CR_PCIE_ADDR_MAP26_MSK   	 0x7FF00001
#define PCIE_CR_FPI_ADDR_MASK_MSK    	 0x00070000
#define PCIE_CR_FCI_ADDR_MAP0_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP1_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP2_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP3_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP4_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP5_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP6_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP7_MSK    	 0xFFF00000
#define PCIE_CR_FCI_ADDR_MAP11lo_MSK 	 0xFFFF0000
#define PCIE_CR_FCI_ADDR_MAP11hg_MSK 	 0xFFF00000
#define PCIE_CR_FCI_BURST_LENGTH_MSK 	 0x00000303
#define PCIE_CR_PCIE_SET_SERR_MSK     	 0x00000001
#define PCIE_CR_DMA_FPI_ST_ADDR_MSK  	 0xFFFFFFFF
#define PCIE_CR_DMA_PCIE_ST_ADDR_MSK  	 0xFFFFFFFF
#define PCIE_CR_DMA_TRAN_CNT_MSK     	 0x000003FF
#define PCIE_CR_DMA_TRAN_CTL_MSK     	 0x00000003

#define BSP_PCIE			PCIE_CR_PR_OFFSET
#define BSP_PCIE_CFG_BASE      		PCIE_CFG_BASE
#define BSP_PCIE_MEM_BASE      		PCIE_MEM_BASE

#define CLOCK_CONTROL           		PCI_CONTROLLER_REG + 0x00000000
#define ARB_CTRL_bit                    1
#define EBU_PCI_ARBITER_AUTOSWITCH		(1 << 1)
#define PCI_FPI_BUS_ERROR			    (1 << 3)
#define IDENTIFICATION         			PCI_CONTROLLER_REG + 0x00000004
#define SOFTRESET               		PCI_CONTROLLER_REG + 0x00000010
#define PCI_FPI_ERROR_ADDRESS   		PCI_CONTROLLER_REG + 0x00000014
#define FPI_PCI_ERROR_ADDRESS   		PCI_CONTROLLER_REG + 0x00000018
#define FPI_ERROR_TAG           		PCI_CONTROLLER_REG + 0x0000001c
#define IRR                     		PCI_CONTROLLER_REG + 0x00000020
#define IRA_IR                  		PCI_CONTROLLER_REG + 0x00000024
#define IRM                     		PCI_CONTROLLER_REG + 0x00000028
#define DMA_COMPLETE_BIT      			0
#define PCI_POWER_CHANGE_BIT  			16
#define PCI_MASTER0_BROKEN_INT_BIT   		24
#define PCI_MASTER1_BROKEN_INT_BIT   		25
#define PCI_MASTER2_BROKEN_INT_BIT   		26
#define SWAPPER                     		PCI_CONTROLLER_REG + 0x0000002c
#define PCI_MODE                		PCI_CONTROLLER_REG + 0x00000030
#define PCI_MODE_cfgok_bit                      24
//#define PCI_MODE_CONFIGURATION_OK		(1 << 24)
#define DEVICE_VENDOR_ID        		PCI_CONTROLLER_REG + 0x00000034
#define SUBSYSTEM_VENDOR_ID     		PCI_CONTROLLER_REG + 0x00000038
#define POWER_MANAGEMENT        		PCI_CONTROLLER_REG + 0x0000003c
#define CLASS_CODE1             		PCI_CONTROLLER_REG + 0x00000040
#define BAR11_MASK              		PCI_CONTROLLER_REG + 0x00000044
#define BAR12_MASK              		PCI_CONTROLLER_REG + 0x00000048
#define BAR13_MASK              		PCI_CONTROLLER_REG + 0x0000004c
#define BAR14_MASK              		PCI_CONTROLLER_REG + 0x00000050
#define BAR15_MASK              		PCI_CONTROLLER_REG + 0x00000054
#define BAR16_MASK              		PCI_CONTROLLER_REG + 0x00000058
#define CARDBUS_CIS_POINTER1    		PCI_CONTROLLER_REG + 0x0000005c
#define SUBSYSTEM_ID1          			PCI_CONTROLLER_REG + 0x00000060
#define PCI_ADDRESS_MAP_11      		PCI_CONTROLLER_REG + 0x00000064
#define PCI_ADDRESS_MAP_12      		PCI_CONTROLLER_REG + 0x00000068
#define PCI_ADDRESS_MAP_13      		PCI_CONTROLLER_REG + 0x0000006c
#define PCI_ADDRESS_MAP_14      		PCI_CONTROLLER_REG + 0x00000070
#define PCI_ADDRESS_MAP_15      		PCI_CONTROLLER_REG + 0x00000074
#define PCI_ADDRESS_MAP_16      		PCI_CONTROLLER_REG + 0x00000078
#define FPI_SEGMENT_ENABLE     			PCI_CONTROLLER_REG + 0x0000007c
#define CLASS_CODE2             		PCI_CONTROLLER_REG + 0x00000080
#define BAR21_MASK              		PCI_CONTROLLER_REG + 0x00000084
#define BAR22_MASK              		PCI_CONTROLLER_REG + 0x00000088
#define BAR23_MASK              		PCI_CONTROLLER_REG + 0x0000008c
#define BAR24_MASK              		PCI_CONTROLLER_REG + 0x00000090
#define BAR25_MASK              		PCI_CONTROLLER_REG + 0x00000094
#define BAR26_MASK              		PCI_CONTROLLER_REG + 0x00000098
#define CARDBUS_CIS_POINTER2    		PCI_CONTROLLER_REG + 0x0000009c
#define SUBSYSTEM_ID2           		PCI_CONTROLLER_REG + 0x000000a0
#define PCI_ADDRESS_MAP_21      		PCI_CONTROLLER_REG + 0x000000a4
#define PCI_ADDRESS_MAP_22      		PCI_CONTROLLER_REG + 0x000000a8
#define PCI_ADDRESS_MAP_23      		PCI_CONTROLLER_REG + 0x000000ac
#define PCI_ADDRESS_MAP_24      		PCI_CONTROLLER_REG + 0x000000b0
#define PCI_ADDRESS_MAP_25      		PCI_CONTROLLER_REG + 0x000000b4
#define PCI_ADDRESS_MAP_26      		PCI_CONTROLLER_REG + 0x000000b8
#define FPI_ADDRESS_MASK11LOW   		PCI_CONTROLLER_REG + 0x000000bc
#define FPI_ADDRESS_MAP_0       		PCI_CONTROLLER_REG + 0x000000c0
#define FPI_ADDRESS_MAP_1       		PCI_CONTROLLER_REG + 0x000000c4
#define FPI_ADDRESS_MAP_2       		PCI_CONTROLLER_REG + 0x000000c8
#define FPI_ADDRESS_MAP_3       		PCI_CONTROLLER_REG + 0x000000cc
#define FPI_ADDRESS_MAP_4       		PCI_CONTROLLER_REG + 0x000000d0
#define FPI_ADDRESS_MAP_5       		PCI_CONTROLLER_REG + 0x000000d4
#define FPI_ADDRESS_MAP_6       		PCI_CONTROLLER_REG + 0x000000d8
#define FPI_ADDRESS_MAP_7       		PCI_CONTROLLER_REG + 0x000000dc
#define FPI_ADDRESS_MAP_11LOW   		PCI_CONTROLLER_REG + 0x000000e0
#define FPI_ADDRESS_MAP_11HIGH  		PCI_CONTROLLER_REG + 0x000000e4
#define FPI_BURST_LENGTH        		PCI_CONTROLLER_REG + 0x000000e8
#define SET_PCI_SERR            		PCI_CONTROLLER_REG + 0x000000ec
#define DMA_FPI_START_ADDR      		PCI_CONTROLLER_REG + 0x000000f0
#define DMA_PCI_START_ADDR      		PCI_CONTROLLER_REG + 0x000000f4
#define DMA_TRANSFER_COUNT      		PCI_CONTROLLER_REG + 0x000000f8
#define DMA_CONTROL_STATUS      		PCI_CONTROLLER_REG + 0x000000fc
#define DMA_PCI_WRITE 				0x0
#define DMA_PCI_READ  				0x2
#define DMA_PCI_TRANSFER_START 			0x1

#define EXT_PCI_BAR1_ADDR                  	0x10
#define EXT_PCI_BAR2_ADDR                  	0x14
#define EXT_PCI_BAR3_ADDR                  	0x18
#define EXT_PCI_BAR4_ADDR                  	0x1C
#define EXT_PCI_BAR5_ADDR                  	0x20
#define EXT_PCI_BAR6_ADDR                  	0x24

#define DEVICE_ID_VECDOR_ID_ADDR    		PCI_CONFIG_SPACE + 0x0
#define STATUS_COMMAND_ADDR         		PCI_CONFIG_SPACE + 0x4
#define SPECIAL_CYCLE_ENABLE_BIT		3
#define BUS_MASTER_ENABLE_BIT       		2
#define MEM_SPACE_ENABLE_BIT       		1
#define IO_SPACE_ENABLE_BIT       		0
#define CLASS_CODE_REVISION_ADDR    		PCI_CONFIG_SPACE + 0x8
#define BIST_HEADER_TYPE_LATENCY_CAHCE_ADDR 	PCI_CONFIG_SPACE + 0xC
#define BAR1_ADDR                   		PCI_CONFIG_SPACE + 0x10
#define BAR2_ADDR                   		PCI_CONFIG_SPACE + 0x14
#define BAR3_ADDR                   		PCI_CONFIG_SPACE + 0x18
#define BAR4_ADDR                   		PCI_CONFIG_SPACE + 0x1C
#define BAR3_ADDR                   		PCI_CONFIG_SPACE + 0x18
#define BAR4_ADDR                   		PCI_CONFIG_SPACE + 0x1C
#define BAR5_ADDR                   		PCI_CONFIG_SPACE + 0x20
#define BAR6_ADDR                   		PCI_CONFIG_SPACE + 0x24
#define CARDBUS_CIS_POINTER_ADDR    		PCI_CONFIG_SPACE + 0x28
#define SUBSYSTEM_ID_VENDOR_ID_ADDR 		PCI_CONFIG_SPACE + 0x2C
#define EXPANSION_ROM_BASE_ADDR     		PCI_CONFIG_SPACE + 0x30
#define CAPABILITIES_POINTER_ADDR   		PCI_CONFIG_SPACE + 0x34
#define RESERVED_0x38               		PCI_CONFIG_SPACE + 0x38
#define MAX_LAT_MIN_GNT_INT_PIN_LINE_ADDR 	PCI_CONFIG_SPACE + 0x3C
#define POWER_MNGT_NEXT_POINTER_CAP_ID_ADDR  	PCI_CONFIG_SPACE + 0x40
#define POWER_MANAGEMENT_CTRL_STATUS_ADDR  	PCI_CONFIG_SPACE + 0x44
#define RESERVED_0x48               		PCI_CONFIG_SPACE + 0x48
#define RESERVED_0x4C               		PCI_CONFIG_SPACE + 0x4C
#define ERROR_ADDR_PCIE_FPI_ADDR     		PCI_CONFIG_SPACE + 0x50
#define ERROR_ADdR_FPI_PCIE_ADDR     		PCI_CONFIG_SPACE + 0x54
#define ERROR_TAG_FPI_PCIE_ADDR      		PCI_CONFIG_SPACE + 0x58
#define PCI_ARB_CTRL_STATUS_ADDR    		PCI_CONFIG_SPACE + 0x80

#define INTERNAL_ARB_ENABLE_BIT         	0
#define ARB_SCHEME_BIT                  	1
#define PCI_MASTER0_PRIOR_2BITS         	2
#define PCI_MASTER1_PRIOR_2BITS         	4
#define PCI_MASTER2_PRIOR_2BITS         	6
#define PCI_MASTER0_REQ_MASK_2BITS      	8
#define PCI_MASTER_0_REQEST_MASK		(3 << 8)
#define PCI_MASTER_1_REQEST_MASK		(3 << 10)
#define PCI_MASTER_2_REQEST_MASK		(3 << 12)
#define PCI_MASTER1_REQ_MASK_2BITS      	10
#define PCI_MASTER2_REQ_MASK_2BITS      	12
#define PCI_MASTER0_GNT_MASK_2BITS      	14
#define PCI_MASTER1_GNT_MASK_2BITS      	16
#define PCI_MASTER2_GNT_MASK_2BITS      	18
#define PCI_ARBITER_PORT_0			(1 << 16)
#define PCI_ARBITER_PORT_1			(1 << 17)
#define PCI_ARBITER_PORT_2			(1 << 18)
#define PCI_ARBITER_PORT_3			(1 << 19)
#define PCI_ARBITER_ENABLE			1
#define PCI_ARBITER_SCHEME_BIT                 	(1 << 1)
#define FPI_PCI_INT_STATUS_ADDR     		PCI_CONFIG_SPACE + 0x60
#define FPI_PCI_INT_ACK_ADDR        		PCI_CONFIG_SPACE + 0x64
#define FPI_PCI_INT_MASK_ADDR       		PCI_CONFIG_SPACE + 0x68
#define CARDBUS_CTRL_STATUS_ADDR    		PCI_CONFIG_SPACE + 0x6C
#define CARDBUS_CFRAME_ENABLE           	0

#define CLOCK_CONTROL_default                	0x00000000
#define CLOCK_CONTROL_mask                   	0x00000003

#define IDENTIFICATION_default               	0x0011C002
#define IDENTIFICATION_mask                  	0x00000000

#define SOFTRESET_default                    	0x00000000
// SOFTRESET bit 0 is writable but will be reset to 0 after software reset is over
#define SOFTRESET_mask                       	0x00000000

#define PCIE_FPI_ERROR_ADDRESS_default        	0xFFFFFFFF
#define PCIE_FPI_ERROR_ADDRESS_mask           	0x00000000

#define FPI_PCIE_ERROR_ADDRESS_default        	0xFFFFFFFF
#define FPI_PCIE_ERROR_ADDRESS_mask           	0x00000000

#define FPI_ERROR_TAG_default                	0x0000000F
#define FPI_ERROR_TAG_mask                   	0x00000000

#define IRR_default                          	0x00000000
#define IRR_mask                             	0x07013b2F
                                                                                                             
#define IRA_IR_default                       	0x00000000
#define IRA_IR_mask                          	0x07013b2F
                                                                                                             
#define IRM_default                          	0x00000000
#define IRM_mask                             	0xFFFFFFFF
                                                                                                             
#define EOI_default                          	0x00000000
#define EOI_mask                             	0x00000000
                                                                                                             
#define PCIE_MODE_default                     	0x01000103
#define PCIE_MODE_mask                        	0x1107070F
                                                                                                             
#define DEVICE_VENDOR_ID_default             	0x000C15D1
#define DEVICE_VENDOR_ID_mask                	0xFFFFFFFF
                                                                                                             
#define SUBSYSTEM_VENDOR_ID_default          	0x000015D1
#define SUBSYSTEM_VENDOR_ID_mask             	0x0000FFFF
                                                                                                             
#define POWER_MANAGEMENT_default             	0x0000001B
#define POWER_MANAGEMENT_mask                	0x0000001F
                                                                                                             
#define CLASS_CODE1_default                  	0x00028000
#define CLASS_CODE1_mask                     	0x00FFFFFF
                                                                                                             
#define BAR11_MASK_default                   	0x0FF00008
#define BAR11_MASK_mask                      	0x8FF00008
                                                                                                             
#define BAR12_MASK_default                   	0x80001800
#define BAR12_MASK_mask                      	0x80001F08
                                                                                                             
#define BAR13_MASK_default                   	0x8FF00008
#define BAR13_MASK_mask                      	0x8FF00008
                                                                                                             
#define BAR14_MASK_default                   	0x8F000000
#define BAR14_MASK_mask                      	0x8FFFFF08
                                                                                                             
#define BAR15_MASK_default                   	0x80000000
#define BAR15_MASK_mask                      	0x8FFFFF08
                                                                                                             
#define BAR16_MASK_default                   	0x80000001
// bit 0 and bit 3 is mutually exclusive
#define BAR16_MASK_mask                      	0x8FFFFFF9
                                                                                                             
#define CARDBUS_CIS_POINTER1_default         	0x00000000
#define CARDBUS_CIS_POINTER1_mask            	0x03FFFFFF
                                                                                                             
#define SUBSYSTEM_ID1_default                	0x0000000C
#define SUBSYSTEM_ID1_mask                   	0x0000FFFF
                                                                                                             
#define PCIE_ADDRESS_MAP_11_default           	0x18000000
#define PCIE_ADDRESS_MAP_11_mask              	0x7FFFFFF1
                                                                                                             
#define PCIE_ADDRESS_MAP_12_default           	0x18100000
#define PCIE_ADDRESS_MAP_12_mask              	0x7FFFFF01
                                                                                                             
#define PCIE_ADDRESS_MAP_13_default           	0x18200000
#define PCIE_ADDRESS_MAP_13_mask              	0x7FF00001
                                                                                                             
#define PCIE_ADDRESS_MAP_14_default           	0x70000000
#define PCIE_ADDRESS_MAP_14_mask              	0x7FFFFF01
                                             	                                                                
#define PCIE_ADDRESS_MAP_15_default           	0x00000001
#define PCIE_ADDRESS_MAP_15_mask              	0x7FFFFF01
                                                                                                             
#define PCIE_ADDRESS_MAP_16_default           	0x60000000
#define PCIE_ADDRESS_MAP_16_mask              	0x7FF00001
                                                                                                             
#define FPI_SEGMENT_ENABLE_default           	0x000003FF
#define FPI_SEGMENT_ENABLE_mask              	0x000003FF
                                                                                                             
#define CLASS_CODE2_default                  	0x00FF0000
#define CLASS_CODE2_mask                     	0x00FFFFFF
                                                                                                             
#define BAR21_MASK_default                   	0x80000008
#define BAR21_MASK_mask                      	0x8FFFFFF8
                                                                                                             
#define BAR22_MASK_default                   	0x80000008
#define BAR22_MASK_mask                      	0x80001F08
                                                                                                             
#define BAR23_MASK_default                   	0x80000008
#define BAR23_MASK_mask                      	0x8FF00008
                                                                                                             
#define BAR24_MASK_default                   	0x8FE00000
#define BAR24_MASK_mask                      	0x8FFFFF08
                                                                                                             
#define BAR25_MASK_default                   	0x8FFFF000
#define BAR25_MASK_mask                      	0x8FFFFF08
                                                                                                             
#define BAR26_MASK_default                   	0x8FFFFFE1
#define BAR26_MASK_mask                      	0x8FFFFFF1
                                                                                                             
#define CARDBUS_CIS_POINTER2_default         	0x00000000
#define CARDBUS_CIS_POINTER2_mask            	0x03FFFFFF

#define SUBSYSTEM_ID2_default                	0x0000000C
#define SUBSYSTEM_ID2_mask                   	0x0000FFFF
                                                                                                             
#define PCIE_ADDRESS_MAP_21_default           	0x3FE00000
#define PCIE_ADDRESS_MAP_21_mask              	0x7FFFFFF1
                                                                                                             
#define PCIE_ADDRESS_MAP_22_default           	0x68000000
#define PCIE_ADDRESS_MAP_22_mask             	0x7FFFFF01
                                                                                                             
#define PCIE_ADDRESS_MAP_23_default           	0x20000000
#define PCIE_ADDRESS_MAP_23_mask              	0x7FF00001
                                                                                                             
#define PCIE_ADDRESS_MAP_24_default           	0x70000001
#define PCIE_ADDRESS_MAP_24_mask              	0x7FFFFF01
                                                                                                             
#define PCIE_ADDRESS_MAP_25_default           	0x78000001
#define PCIE_ADDRESS_MAP_25_mask              	0x7FFFFF01
                                                                                                             
#define PCIE_ADDRESS_MAP_26_default           	0x20000000
#define PCIE_ADDRESS_MAP_26_mask              	0x7FF00001
                                                                                                             
#define FPI_ADDRESS_MASK11LOW_default        	0x00000000
#define FPI_ADDRESS_MASK11LOW_mask           	0x00070000
                                                                                                             
#define FPI_ADDRESS_MAP_0_default            	0x00000000
#define FPI_ADDRESS_MAP_0_mask               	0xFFF00000
                                                                                                             
#define FPI_ADDRESS_MAP_1_default            	0x10000000
#define FPI_ADDRESS_MAP_1_mask               	0xFFF00000
                                                                                                             
#define FPI_ADDRESS_MAP_2_default            	0x20000000
#define FPI_ADDRESS_MAP_2_mask               	0xFFF00000

#define FPI_ADDRESS_MAP_3_default            	0x30000000
#define FPI_ADDRESS_MAP_3_mask               	0xFFF00000
                                                                                                             
#define FPI_ADDRESS_MAP_4_default            	0x40000000
#define FPI_ADDRESS_MAP_4_mask               	0xFFF00000
                                                                                                             
#define FPI_ADDRESS_MAP_5_default            	0x50000000
#define FPI_ADDRESS_MAP_5_mask               	0xFFF00000
                                                                                                             
#define FPI_ADDRESS_MAP_6_default            	0x60000000
#define FPI_ADDRESS_MAP_6_mask               	0xFFF00000
                                                                                                             
#define FPI_ADDRESS_MAP_7_default            	0x70000000
#define FPI_ADDRESS_MAP_7_mask               	0xFFF00000
                                                                                                             
#define FPI_ADDRESS_MAP_11LOW_default        	0xB0000000
#define FPI_ADDRESS_MAP_11LOW_mask           	0xFFFF0000
                                                                                                             
#define FPI_ADDRESS_MAP_11HIGH_default       	0xB8000000
#define FPI_ADDRESS_MAP_11HIGH_mask          	0xFFF80000
                                                                                                             
#define FPI_BURST_LENGTH_default             	0x00000000
#define FPI_BURST_LENGTH_mask                	0x00000303
                                                                                                             
#define SET_PCIE_SERR_default                 	0x00000000
#define SET_PCIE_SERR_mask                    	0x00000000
                                                                                                             
#define DMA_FPI_START_ADDRESS_default        	0x00000000
#define DMA_FPI_START_ADDRESS_mask           	0xFFFFFFFF
                                                                                                             
#define DMA_PCIE_START_ADDRESS_default        	0x00000000
#define DMA_PCIE_START_ADDRESS_mask           	0xFFFFFFFF
                                                                                                             
#define DMA_TRANSFER_COUNT_default           	0x00000000
#define DMA_TRANSFER_COUNT_mask              	0x0000FFFF

#define DMA_CONTROL_STATUS_default           	0x00000000
#define DMA_CONTROL_STATUS_mask              	0x00000000   // bit 0,1 is writable

                                                                                                             
/***********************************************************************/
/*  Module      :  PMU register address and bits                       */
/***********************************************************************/
#define BSP_PMU_BASE_ADDR 				(KSEG1+0x1F102000)

#define BSP_PMU_PWCSR                   ((volatile u32*)(BSP_PMU_BASE_ADDR + 0x0100))
#define BSP_PMU_PWDCR                   ((volatile u32*)(BSP_PMU_BASE_ADDR + 0x001C))
#define BSP_PMU_PWDCR1                  ((volatile u32*)(BSP_PMU_BASE_ADDR + 0x0024))
#define BSP_PMU_PWDSR 					((volatile u32*)(BSP_PMU_BASE_ADDR + 0x0020))
#define BSP_PMU_PWDSR1 			        ((volatile u32*)(BSP_PMU_BASE_ADDR + 0x0028))

// Mask
#define BSP_PMU_PWDCR_MSK    0x03FFFFFF
#define BSP_PMU_SR_MSK       0x03FFFFFF
//SDRAM
#define BSP_SDRAM_PMU_PWDCR (0xA0EA0F90)

/***PM Global Enable Register 0 ***/
#define BSP_PMU_USB0_PHY		(1 << 0)
#define BSP_PMU_FPIS            (1 << 1)
#define BSP_PMU_DFEV0			(1 << 2)
#define BSP_PMU_DEV1			(1 << 3)
#define BSP_PMU_PCI			    (1 << 4)
#define BSP_PMU_DMA             (1 << 5)
#define BSP_PMU_USB0			(1 << 6)
#define BSP_PMU_USIF			(1 << 7)
#define BSP_PMU_SPI			    (1 << 8)
#define BSP_PMU_DSL			    (1 << 9)
#define BSP_PMU_EBU			    (1 << 10)
#define BSP_PMU_LEDC			(1 << 11)
#define BSP_PMU_GPTC			(1 << 12)
#define BSP_PMU_AHBS			(1 << 13)
#define BSP_PMU_FPIM            (1 << 14)
#define BSP_PMU_AHBM            (1 << 15)
#define BSP_PMU_SDIO			(1 << 16)
#define BSP_PMU_UART1			(1 << 17)
#define BSP_PMU_PPE_QSB         (1 << 18)
#define BSP_PMU_SSL01           (1 << 19)
#define BSP_PMU_DEU			    (1 << 20)
#define BSP_PMU_PPE_TC			(1 << 21)
#define BSP_PMU_PPE_EMA			(1 << 22)
#define BSP_PMU_PPE_DPLUS		(1 << 23)
#define BSP_PMU_PPE_DPSS		(1 << 24)
#define BSP_PMU_TDM			    (1 << 25)
#define BSP_PMU_USB1_PHY		(1 << 26)
#define BSP_PMU_USB1			(1 << 27)
#define BSP_PMU_SWITCH			(1 << 28)
#define BSP_PMU_PPE_TOP         (1 << 29)
#define BSP_PMU_GPHY            (1 << 30)
#define BSP_PMU_PCIE0_EN        (1 << 31)

/* PMU Control Register 1 */
#define BSP_PMU_PCIE_PHY         (1 << 0) /* Not used */
#define BSP_PMU_PCIE_CON         (1 << 1)
#define BSP_PMU_AHB_ARC          (1 << 2)
#define BSP_PMU_HSNAND           (1 << 3)
#define BSP_PMU_PDI              (1 << 4)
#define BSP_PMU_MSI              (1 << 5)
#define BSP_PMU_CKE              (1 << 6)

/***PM Control Register***/
#define BSP_PMU_PM_CR_AWEN                            (1 << 31)
#define BSP_PMU_PM_CR_SWRST                          (1 << 30)
#define BSP_PMU_PM_CR_SWCR                            (1 << 2)
#define BSP_PMU_PM_CR_CRD (value)                (((( 1 << 2) - 1) & (value)) << 0)
                                                                                                                                                             

/***********************************************************************/
/*  Module      :  MBC register address and bits                       */
/***********************************************************************/

#define BSP_MBC                          (0xBF103000)
/***********************************************************************/


/***Mailbox CPU Configuration Register***/
#define BSP_MBC_MBC_CFG                      ((volatile u32*)(BSP_MBC+ 0x0080))
#define BSP_MBC_MBC_CFG_SWAP (value)               (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_MBC_MBC_CFG_RES                              (1 << 5)
#define BSP_MBC_MBC_CFG_FWID (value)               (((( 1 << 4) - 1) & (value)) << 1)
#define BSP_MBC_MBC_CFG_SIZE                            (1 << 0)

/***Mailbox CPU Interrupt Status Register***/
#define BSP_MBC_MBC_ISR                      ((volatile u32*)(BSP_MBC+ 0x0084))
#define BSP_MBC_MBC_ISR_B3DA                            (1 << 31)
#define BSP_MBC_MBC_ISR_B2DA                            (1 << 30)
#define BSP_MBC_MBC_ISR_B1E                              (1 << 29)
#define BSP_MBC_MBC_ISR_B0E                              (1 << 28)
#define BSP_MBC_MBC_ISR_WDT                              (1 << 27)
#define BSP_MBC_MBC_ISR_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Mask Register***/
#define BSP_MBC_MBC_MSK                      ((volatile u32*)(BSP_MBC+ 0x0088))
#define BSP_MBC_MBC_MSK_B3DA                            (1 << 31)
#define BSP_MBC_MBC_MSK_B2DA                            (1 << 30)
#define BSP_MBC_MBC_MSK_B1E                              (1 << 29)
#define BSP_MBC_MBC_MSK_B0E                              (1 << 28)
#define BSP_MBC_MBC_MSK_WDT                              (1 << 27)
#define BSP_MBC_MBC_MSK_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Mask 01 Register***/
#define BSP_MBC_MBC_MSK01                    ((volatile u32*)(BSP_MBC+ 0x008C))
#define BSP_MBC_MBC_MSK01_B3DA                            (1 << 31)
#define BSP_MBC_MBC_MSK01_B2DA                            (1 << 30)
#define BSP_MBC_MBC_MSK01_B1E                              (1 << 29)
#define BSP_MBC_MBC_MSK01_B0E                              (1 << 28)
#define BSP_MBC_MBC_MSK01_WDT                              (1 << 27)
#define BSP_MBC_MBC_MSK01_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Mask 10 Register***/
#define BSP_MBC_MBC_MSK10                    ((volatile u32*)(BSP_MBC+ 0x0090))
#define BSP_MBC_MBC_MSK10_B3DA                            (1 << 31)
#define BSP_MBC_MBC_MSK10_B2DA                            (1 << 30)
#define BSP_MBC_MBC_MSK10_B1E                              (1 << 29)
#define BSP_MBC_MBC_MSK10_B0E                              (1 << 28)
#define BSP_MBC_MBC_MSK10_WDT                              (1 << 27)
#define BSP_MBC_MBC_MSK10_DS260 (value)             (((( 1 << 27) - 1) & (value)) << 0)

/***Mailbox CPU Short Command Register***/
#define BSP_MBC_MBC_CMD                      ((volatile u32*)(BSP_MBC+ 0x0094))
#define BSP_MBC_MBC_CMD_CS270 (value)             (((( 1 << 28) - 1) & (value)) << 0)

/***Mailbox CPU Input Data of Buffer 0***/
#define BSP_MBC_MBC_ID0                      ((volatile u32*)(BSP_MBC+ 0x0000))
#define BSP_MBC_MBC_ID0_INDATA

/***Mailbox CPU Input Data of Buffer 1***/
#define BSP_MBC_MBC_ID1                      ((volatile u32*)(BSP_MBC+ 0x0020))
#define BSP_MBC_MBC_ID1_INDATA

/***Mailbox CPU Output Data of Buffer 2***/
#define BSP_MBC_MBC_OD2                      ((volatile u32*)(BSP_MBC+ 0x0040))
#define BSP_MBC_MBC_OD2_OUTDATA

/***Mailbox CPU Output Data of Buffer 3***/
#define BSP_MBC_MBC_OD3                      ((volatile u32*)(BSP_MBC+ 0x0060))
#define BSP_MBC_MBC_OD3_OUTDATA

/***Mailbox CPU Control Register of Buffer 0***/
#define BSP_MBC_MBC_CR0                      ((volatile u32*)(BSP_MBC+ 0x0004))
#define BSP_MBC_MBC_CR0_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Control Register of Buffer 1***/
#define BSP_MBC_MBC_CR1                      ((volatile u32*)(BSP_MBC+ 0x0024))
#define BSP_MBC_MBC_CR1_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Control Register of Buffer 2***/
#define BSP_MBC_MBC_CR2                      ((volatile u32*)(BSP_MBC+ 0x0044))
#define BSP_MBC_MBC_CR2_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Control Register of Buffer 3***/
#define BSP_MBC_MBC_CR3                      ((volatile u32*)(BSP_MBC+ 0x0064))
#define BSP_MBC_MBC_CR3_RDYABTFLS (value)          (((( 1 << 3) - 1) & (value)) << 0)

/***Mailbox CPU Free Space of Buffer 0***/
#define BSP_MBC_MBC_FS0                      ((volatile u32*)(BSP_MBC+ 0x0008))
#define BSP_MBC_MBC_FS0_FS

/***Mailbox CPU Free Space of Buffer 1***/
#define BSP_MBC_MBC_FS1                      ((volatile u32*)(BSP_MBC+ 0x0028))
#define BSP_MBC_MBC_FS1_FS

/***Mailbox CPU Free Space of Buffer 2***/
#define BSP_MBC_MBC_FS2                      ((volatile u32*)(BSP_MBC+ 0x0048))
#define BSP_MBC_MBC_FS2_FS

/***Mailbox CPU Free Space of Buffer 3***/
#define BSP_MBC_MBC_FS3                      ((volatile u32*)(BSP_MBC+ 0x0068))
#define BSP_MBC_MBC_FS3_FS

/***Mailbox CPU Data Available in Buffer 0***/
#define BSP_MBC_MBC_DA0                      ((volatile u32*)(BSP_MBC+ 0x000C))
#define BSP_MBC_MBC_DA0_DA

/***Mailbox CPU Data Available in Buffer 1***/
#define BSP_MBC_MBC_DA1                      ((volatile u32*)(BSP_MBC+ 0x002C))
#define BSP_MBC_MBC_DA1_DA

/***Mailbox CPU Data Available in Buffer 2***/
#define BSP_MBC_MBC_DA2                      ((volatile u32*)(BSP_MBC+ 0x004C))
#define BSP_MBC_MBC_DA2_DA

/***Mailbox CPU Data Available in Buffer 3***/
#define BSP_MBC_MBC_DA3                      ((volatile u32*)(BSP_MBC+ 0x006C))
#define BSP_MBC_MBC_DA3_DA

/***Mailbox CPU Input Absolute Pointer of Buffer 0***/
#define BSP_MBC_MBC_IABS0                    ((volatile u32*)(BSP_MBC+ 0x0010))
#define BSP_MBC_MBC_IABS0_IABS

/***Mailbox CPU Input Absolute Pointer of Buffer 1***/
#define BSP_MBC_MBC_IABS1                    ((volatile u32*)(BSP_MBC+ 0x0030))
#define BSP_MBC_MBC_IABS1_IABS

/***Mailbox CPU Input Absolute Pointer of Buffer 2***/
#define BSP_MBC_MBC_IABS2                    ((volatile u32*)(BSP_MBC+ 0x0050))
#define BSP_MBC_MBC_IABS2_IABS

/***Mailbox CPU Input Absolute Pointer of Buffer 3***/
#define BSP_MBC_MBC_IABS3                    ((volatile u32*)(BSP_MBC+ 0x0070))
#define BSP_MBC_MBC_IABS3_IABS

/***Mailbox CPU Input Temporary Pointer of Buffer 0***/
#define BSP_MBC_MBC_ITMP0                    ((volatile u32*)(BSP_MBC+ 0x0014))
#define BSP_MBC_MBC_ITMP0_ITMP

/***Mailbox CPU Input Temporary Pointer of Buffer 1***/
#define BSP_MBC_MBC_ITMP1                    ((volatile u32*)(BSP_MBC+ 0x0034))
#define BSP_MBC_MBC_ITMP1_ITMP

/***Mailbox CPU Input Temporary Pointer of Buffer 2***/
#define BSP_MBC_MBC_ITMP2                    ((volatile u32*)(BSP_MBC+ 0x0054))
#define BSP_MBC_MBC_ITMP2_ITMP

/***Mailbox CPU Input Temporary Pointer of Buffer 3***/
#define BSP_MBC_MBC_ITMP3                    ((volatile u32*)(BSP_MBC+ 0x0074))
#define BSP_MBC_MBC_ITMP3_ITMP

/***Mailbox CPU Output Absolute Pointer of Buffer 0***/
#define BSP_MBC_MBC_OABS0                    ((volatile u32*)(BSP_MBC+ 0x0018))
#define BSP_MBC_MBC_OABS0_OABS

/***Mailbox CPU Output Absolute Pointer of Buffer 1***/
#define BSP_MBC_MBC_OABS1                    ((volatile u32*)(BSP_MBC+ 0x0038))
#define BSP_MBC_MBC_OABS1_OABS

/***Mailbox CPU Output Absolute Pointer of Buffer 2***/
#define BSP_MBC_MBC_OABS2                    ((volatile u32*)(BSP_MBC+ 0x0058))
#define BSP_MBC_MBC_OABS2_OABS

/***Mailbox CPU Output Absolute Pointer of Buffer 3***/
#define BSP_MBC_MBC_OABS3                    ((volatile u32*)(BSP_MBC+ 0x0078))
#define BSP_MBC_MBC_OABS3_OABS

/***Mailbox CPU Output Temporary Pointer of Buffer 0***/
#define BSP_MBC_MBC_OTMP0                    ((volatile u32*)(BSP_MBC+ 0x001C))
#define BSP_MBC_MBC_OTMP0_OTMP

/***Mailbox CPU Output Temporary Pointer of Buffer 1***/
#define BSP_MBC_MBC_OTMP1                    ((volatile u32*)(BSP_MBC+ 0x003C))
#define BSP_MBC_MBC_OTMP1_OTMP

/***Mailbox CPU Output Temporary Pointer of Buffer 2***/
#define BSP_MBC_MBC_OTMP2                    ((volatile u32*)(BSP_MBC+ 0x005C))
#define BSP_MBC_MBC_OTMP2_OTMP

/***Mailbox CPU Output Temporary Pointer of Buffer 3***/
#define BSP_MBC_MBC_OTMP3                    ((volatile u32*)(BSP_MBC+ 0x007C))
#define BSP_MBC_MBC_OTMP3_OTMP

/***DSP Control Register***/
#define BSP_MBC_DCTRL                        ((volatile u32*)(BSP_MBC+ 0x00A0))
#define BSP_MBC_DCTRL_BA                              (1 << 0)
#define BSP_MBC_DCTRL_BMOD (value)               (((( 1 << 3) - 1) & (value)) << 1)
#define BSP_MBC_DCTRL_IDL                              (1 << 4)
#define BSP_MBC_DCTRL_RES                              (1 << 15)

/***DSP Status Register***/
#define BSP_MBC_DSTA                         ((volatile u32*)(BSP_MBC+ 0x00A4))
#define BSP_MBC_DSTA_IDLE                            (1 << 0)
#define BSP_MBC_DSTA_PD                              (1 << 1)

/***DSP Test 1 Register***/
#define BSP_MBC_DTST1                        ((volatile u32*)(BSP_MBC+ 0x00A8))
#define BSP_MBC_DTST1_ABORT                          (1 << 0)
#define BSP_MBC_DTST1_HWF32                          (1 << 1)
#define BSP_MBC_DTST1_HWF4M                          (1 << 2)
#define BSP_MBC_DTST1_HWFOP                          (1 << 3)


/***********************************************************************/
/*  Module      :  SSC1 register address and bits                      */
/***********************************************************************/
#define BSP_SSC1                       	(KSEG1+0x1e100800) 
/***********************************************************************/
/***SSC Clock Control Register***/
#define BSP_SSC_CLC                      	(0x0000)
#define BSP_SSC_CLC_RMC(value)               (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_SSC_CLC_DISS                     (1 << 1)
#define BSP_SSC_CLC_DISR                     (1 << 0)
/***SSC Port Input Selection Register***/
#define BSP_SSC_PISEL                        (0x0004)
/***SSC Identification Register***/
#define BSP_SSC_ID                           (0x0008)
/***Control Register (Programming Mode)***/
#define BSP_SSC_CON                  		(0x0010)
#define BSP_SSC_CON_RUEN                            (1 << 12)
#define BSP_SSC_CON_TUEN                              (1 << 11)
#define BSP_SSC_CON_AEN                              (1 << 10)
#define BSP_SSC_CON_REN                              (1 << 9)
#define BSP_SSC_CON_TEN                              (1 << 8)
#define BSP_SSC_CON_LB                              (1 << 7)
#define BSP_SSC_CON_PO                              (1 << 6)
#define BSP_SSC_CON_PH                              (1 << 5)
#define BSP_SSC_CON_HB                              (1 << 4)
#define BSP_SSC_CON_BM(value)                	(((( 1 << 5) - 1) & (value)) << 16)
#define BSP_SSC_CON_RX_OFF                          (1 << 1)
#define BSP_SSC_CON_TX_OFF                          (1 << 0)
/***SCC Status Register***/
#define BSP_SSC_STATE                  (0x0014)
#define BSP_SSC_STATE_EN                              (1 << 0)
#define BSP_SSC_STATE_MS                              (1 << 1)
#define BSP_SSC_STATE_BSY                              (1 << 13)
#define BSP_SSC_STATE_RUE                              (1 << 12)
#define BSP_SSC_STATE_TUE                              (1 << 11)
#define BSP_SSC_STATE_AE                              (1 << 10)
#define BSP_SSC_STATE_RE                              (1 << 9)
#define BSP_SSC_STATE_TE                              (1 << 8)
#define BSP_SSC_STATE_BC(value)                (((( 1 << 5) - 1) & (value)) << 16)
/***SSC Write Hardware Modified Control Register***/
#define BSP_SSC_WHBSTATE                   ( 0x0018)
#define BSP_SSC_WHBSTATE_SETBE                          (1 << 15)
#define BSP_SSC_WHBSTATE_SETPE                          (1 << 14)
#define BSP_SSC_WHBSTATE_SETRE                          (1 << 13)
#define BSP_SSC_WHBSTATE_SETTE                          (1 << 12)
#define BSP_SSC_WHBSTATE_CLRBE                          (1 << 11)
#define BSP_SSC_WHBSTATE_CLRPE                          (1 << 10)
#define BSP_SSC_WHBSTATE_CLRRE                          (1 << 9)
#define BSP_SSC_WHBSTATE_CLRTE                          (1 << 8)
/***SSC Transmitter Buffer Register***/
#define BSP_SSC_TB                       (0x0020)
#define BSP_SSC_TB_TB_VALUE(value)          (((( 1 << 16) - 1) & (value)) << 0)
/***SSC Receiver Buffer Register***/
#define BSP_SSC_RB                       (0x0024)
#define BSP_SSC_RB_RB_VALUE(value)          (((( 1 << 16) - 1) & (value)) << 0)
/***SSC Receive FIFO Control Register***/
#define BSP_SSC_RXFCON                   (0x0030)
#define BSP_SSC_RXFCON_RXFITL(value)             (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_SSC_RXFCON_RXTMEN                        (1 << 2)
#define BSP_SSC_RXFCON_RXFLU                          (1 << 1)
#define BSP_SSC_RXFCON_RXFEN                          (1 << 0)
/***SSC Transmit FIFO Control Register***/
#define BSP_SSC_TXFCON                   ( 0x0034)
#define BSP_SSC_TXFCON_RXFITL(value)             (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_SSC_TXFCON_TXTMEN                        (1 << 2)
#define BSP_SSC_TXFCON_TXFLU                          (1 << 1)
#define BSP_SSC_TXFCON_TXFEN                          (1 << 0)
/***SSC FIFO Status Register***/
#define BSP_SSC_FSTAT                    (0x0038)
#define BSP_SSC_FSTAT_TXFFL(value)              (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_SSC_FSTAT_RXFFL(value)              (((( 1 << 6) - 1) & (value)) << 0)
/***SSC Baudrate Timer Reload Register***/
#define BSP_SSC_BR                       (0x0040)
#define BSP_SSC_BR_BR_VALUE(value)          (((( 1 << 16) - 1) & (value)) << 0)
#define BSP_SSC_BRSTAT                       (0x0044)
#define BSP_SSC_SFCON                        (0x0060)
#define BSP_SSC_SFSTAT                       (0x0064)
#define BSP_SSC_GPOCON                       (0x0070)
#define BSP_SSC_GPOSTAT                      (0x0074)
#define BSP_SSC_WHBGPOSTAT                   (0x0078)
#define BSP_SSC_RXREQ                        (0x0080)
#define BSP_SSC_RXCNT                        (0x0084) 
/*DMA Registers in Bus Clock Domain*/ 
#define BSP_SSC_DMA_CON                      (0x00EC)
/*interrupt Node Registers in Bus Clock Domain*/
#define BSP_SSC_IRNEN                        (0x00F4)
#define BSP_SSC_IRNCR                        (0x00F8)
#define BSP_SSC_IRNICR                       (0x00FC)
#define BSP_SSC_IRN_FIR			0x8
#define BSP_SSC_IRN_EIR			0x4
#define BSP_SSC_IRN_RIR			0x2
#define BSP_SSC_IRN_TIR			0x1


#define	BSP_SSC1_CLC			((volatile u32*)(BSP_SSC1+BSP_SSC_CLC))
#define	BSP_SSC1_ID			((volatile u32*)(BSP_SSC1+BSP_SSC_ID))
#define	BSP_SSC1_CON			((volatile u32*)(BSP_SSC1+BSP_SSC_CON))
#define	BSP_SSC1_STATE			((volatile u32*)(BSP_SSC1+BSP_SSC_STATE))
#define	BSP_SSC1_WHBSTATE			((volatile u32*)(BSP_SSC1+BSP_SSC_WHBSTATE))
#define	BSP_SSC1_TB			((volatile u32*)(BSP_SSC1+BSP_SSC_TB))
#define	BSP_SSC1_RB			((volatile u32*)(BSP_SSC1+BSP_SSC_RB))
#define	BSP_SSC1_FSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_FSTAT))
#define	BSP_SSC1_PISEL			((volatile u32*)(BSP_SSC1+BSP_SSC_PISEL))
#define	BSP_SSC1_RXFCON			((volatile u32*)(BSP_SSC1+BSP_SSC_RXFCON))
#define	BSP_SSC1_TXFCON			((volatile u32*)(BSP_SSC1+BSP_SSC_TXFCON))
#define	BSP_SSC1_BR			((volatile u32*)(BSP_SSC1+BSP_SSC_BR))
#define	BSP_SSC1_BRSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_BRSTAT))
#define	BSP_SSC1_SFCON			((volatile u32*)(BSP_SSC1+BSP_SSC_SFCON))
#define	BSP_SSC1_SFSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_SFSTAT))
#define	BSP_SSC1_GPOCON			((volatile u32*)(BSP_SSC1+BSP_SSC_GPOCON))
#define	BSP_SSC1_GPOSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_GPOSTAT))
#define	BSP_SSC1_WHBGPOSTAT			((volatile u32*)(BSP_SSC1+BSP_SSC_WHBGPOSTAT))
#define	BSP_SSC1_RXREQ			((volatile u32*)(BSP_SSC1+BSP_SSC_RXREQ))
#define	BSP_SSC1_RXCNT			((volatile u32*)(BSP_SSC1+BSP_SSC_RXCNT))
#define	BSP_SSC1_DMA_CON			((volatile u32*)(BSP_SSC1+BSP_SSC_DMA_CON))
#define	BSP_SSC1_IRNEN			((volatile u32*)(BSP_SSC1+BSP_SSC_IRNEN))
#define	BSP_SSC1_IRNICR			((volatile u32*)(BSP_SSC1+BSP_SSC_IRNICR))
#define	BSP_SSC1_IRNCR			((volatile u32*)(BSP_SSC1+BSP_SSC_IRNCR))

/***********************************************************************/
/*  Module      :  GPIO register address and bits                       */
/***********************************************************************/
#define BSP_GPIO                     (0xBE100B00)
/***Port 0 Data Output Register (0010H)***/
#define BSP_GPIO_P0_OUT              ((volatile u32 *)(BSP_GPIO+ 0x0010))
/***Port 1 Data Output Register (0040H)***/
#define BSP_GPIO_P1_OUT              ((volatile u32 *)(BSP_GPIO+ 0x0040))
/***Port 2 Data Output Register (0070H)***/
#define BSP_GPIO_P2_OUT              ((volatile u32 *)(BSP_GPIO+ 0x0070))
/***Port 3 Data Output Register (00A0H)***/
#define BSP_GPIO_P3_OUT              ((volatile u32 *)(BSP_GPIO+ 0x00A0))
/***Port 0 Data Input Register (0014H)***/
#define BSP_GPIO_P0_IN               ((volatile u32 *)(BSP_GPIO+ 0x0014))
/***Port 1 Data Input Register (0044H)***/
#define BSP_GPIO_P1_IN               ((volatile u32 *)(BSP_GPIO+ 0x0044))
/***Port 2 Data Input Register (0074H)***/
#define BSP_GPIO_P2_IN               ((volatile u32 *)(BSP_GPIO+ 0x0074))
/***Port 3 Data Input Register (00A4H)***/
#define BSP_GPIO_P3_IN               ((volatile u32 *)(BSP_GPIO+ 0x00A4))
/***Port 0 Direction Register (0018H)***/
#define BSP_GPIO_P0_DIR              ((volatile u32 *)(BSP_GPIO+ 0x0018))
/***Port 1 Direction Register (0048H)***/
#define BSP_GPIO_P1_DIR              ((volatile u32 *)(BSP_GPIO+ 0x0048))
/***Port 2 Direction Register (0078H)***/
#define BSP_GPIO_P2_DIR              ((volatile u32 *)(BSP_GPIO+ 0x0078))
/***Port 3 Direction Register (00A8H)***/
#define BSP_GPIO_P3_DIR              ((volatile u32 *)(BSP_GPIO+ 0x00A8))
/***Port 0 Alternate Function Select Register 0 (001C H) ***/
#define BSP_GPIO_P0_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x001C))
/***Port 1 Alternate Function Select Register 0 (004C H) ***/
#define BSP_GPIO_P1_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x004C))
/***Port 2 Alternate Function Select Register 0 (007C H) ***/
#define BSP_GPIO_P2_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x007C))
/***Port 3 Alternate Function Select Register 0 (00AC H) ***/
#define BSP_GPIO_P3_ALTSEL0          ((volatile u32 *)(BSP_GPIO+ 0x00AC))
/***Port 0 Alternate Function Select Register 1 (0020 H) ***/
#define BSP_GPIO_P0_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0020))
/***Port 1 Alternate Function Select Register 0 (0050 H) ***/
#define BSP_GPIO_P1_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0050))
/***Port 2 Alternate Function Select Register 1 (0080 H) ***/
#define BSP_GPIO_P2_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0080))
/***Port 3 Alternate Function Select Register 0 (0064 H) ***/
#define BSP_GPIO_P3_ALTSEL1          ((volatile u32 *)(BSP_GPIO+ 0x0064))
/***Port 0 Open Drain Control Register (0024H)***/
#define BSP_GPIO_P0_OD               ((volatile u32 *)(BSP_GPIO+ 0x0024))
/***Port 1 Open Drain Control Register (0054H)***/
#define BSP_GPIO_P1_OD               ((volatile u32 *)(BSP_GPIO+ 0x0054))
/***Port 2 Open Drain Control Register (0084H)***/
#define BSP_GPIO_P2_OD               ((volatile u32 *)(BSP_GPIO+ 0x0084))
/***Port 3 Open Drain Control Register (0034H)***/
#define BSP_GPIO_P3_OD               ((volatile u32 *)(BSP_GPIO+ 0x0034))
/***Port 0 Input Schmitt-Trigger Off Register (0028 H) ***/
#define BSP_GPIO_P0_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0028))
/***Port 1 Input Schmitt-Trigger Off Register (0058 H) ***/
#define BSP_GPIO_P1_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0058))
/***Port 2 Input Schmitt-Trigger Off Register (0088 H) ***/
#define BSP_GPIO_P2_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0088))
/***Port 3 Input Schmitt-Trigger Off Register (0094 H) ***/
//#define BSP_GPIO_P3_STOFF            ((volatile u32 *)(BSP_GPIO+ 0x0094))
/***Port 0 Pull Up/Pull Down Select Register (002C H)***/
#define BSP_GPIO_P0_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x002C))
/***Port 1 Pull Up/Pull Down Select Register (005C H)***/
#define BSP_GPIO_P1_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x005C))
/***Port 2 Pull Up/Pull Down Select Register (008C H)***/
#define BSP_GPIO_P2_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x008C))
/***Port 3 Pull Up/Pull Down Select Register (0038 H)***/
#define BSP_GPIO_P3_PUDSEL           ((volatile u32 *)(BSP_GPIO+ 0x0038))
/***Port 0 Pull Up Device Enable Register (0030 H)***/
#define BSP_GPIO_P0_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x0030))
/***Port 1 Pull Up Device Enable Register (0060 H)***/
#define BSP_GPIO_P1_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x0060))
/***Port 2 Pull Up Device Enable Register (0090 H)***/
#define BSP_GPIO_P2_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x0090))
/***Port 3 Pull Up Device Enable Register (003C H)***/
#define BSP_GPIO_P3_PUDEN            ((volatile u32 *)(BSP_GPIO+ 0x003C))



#define BSP_LED_CON0            ((volatile u32 *)(BSP_GPIO+ 0x00B0))
#define BSP_LED_CON1            ((volatile u32 *)(BSP_GPIO+ 0x00B4))
#define BSP_LED_CPU0            ((volatile u32 *)(BSP_GPIO+ 0x00B8))
#define BSP_LED_CPU1            ((volatile u32 *)(BSP_GPIO+ 0x00BC))
#define BSP_LED_AR              ((volatile u32 *)(BSP_GPIO+ 0x00C0))


/***********************************************************************/
/*  Module      :  MCD register address and bits                       */
/***********************************************************************/
#define BSP_MCD                          		(KSEG1+0x1F106000)

/***Manufacturer Identification Register***/ 
#define BSP_MCD_MANID                        	((volatile u32*)(BSP_MCD+ 0x0024))
#define BSP_MCD_MANID_MANUF(value)              	(((( 1 << 11) - 1) & (value)) << 5)

/***Chip Identification Register***/ 
#define BSP_MCD_CHIPID                       	((volatile u32*)(BSP_MCD+ 0x0028))
#define BSP_MCD_CHIPID_VERSION_GET(value)             (((value) >> 28) & ((1 << 4) - 1))
#define BSP_MCD_CHIPID_VERSION_SET(value)             (((( 1 << 4) - 1) & (value)) << 28)
#define BSP_MCD_CHIPID_PART_NUMBER_GET(value)         (((value) >> 12) & ((1 << 16) - 1))
#define BSP_MCD_CHIPID_PART_NUMBER_SET(value)         (((( 1 << 16) - 1) & (value)) << 12)
#define BSP_MCD_CHIPID_MANID_GET(value)               (((value) >> 1) & ((1 << 11) - 1))
#define BSP_MCD_CHIPID_MANID_SET(value)               (((( 1 << 11) - 1) & (value)) << 1)

#define BSP_CHIPID_STANDARD				0x00EB
#define BSP_CHIPID_YANGTSE				0x00ED

/***Redesign Tracing Identification Register***/ 
#define BSP_MCD_RTID                         	((volatile u32*)(BSP_MCD+ 0x002C))
#define BSP_MCD_RTID_LC                              (1 << 15)
#define BSP_MCD_RTID_RIX(value)                	(((( 1 << 3) - 1) & (value)) << 0)

	         
/***********************************************************************/
/*  Module      :  EBU register address and bits                       */
/***********************************************************************/

#define BSP_EBU                          (0xBE105300)
#define BSP_EBU_ADDR_SEL0     (volatile u32*)(BSP_EBU + 0x20)
#define BSP_EBU_ADDR_SEL1     (volatile u32*)(BSP_EBU + 0x24)
#define BSP_EBU_ADDR_SEL2     (volatile u32*)(BSP_EBU + 0x28)
#define BSP_EBU_ADDR_SEL3     (volatile u32*)(BSP_EBU + 0x2C)
#define BSP_EBU_CON0          (volatile u32*)(BSP_EBU + 0x60)
#define BSP_EBU_CON1          (volatile u32*)(BSP_EBU + 0x64)
#define BSP_EBU_CON2          (volatile u32*)(BSP_EBU + 0x68)
#define BSP_EBU_CON3          (volatile u32*)(BSP_EBU + 0x6C)
#define BSP_EBU_NAND_CON       (volatile u32*)(BSP_EBU + 0xB0)
#define BSP_EBU_NAND_WAIT      (volatile u32*)(BSP_EBU + 0xB4)
#define BSP_EBU_NAND_ECC0      (volatile u32*)(BSP_EBU + 0xB8)
#define BSP_EBU_NAND_ECC_AC    (volatile u32*)(BSP_EBU + 0xBC)

#define EBU_ADDR_SEL0     (volatile u32*)(BSP_EBU + 0x20)
#define EBU_ADDR_SEL1     (volatile u32*)(BSP_EBU + 0x24)
#define EBU_ADDR_SEL2     (volatile u32*)(BSP_EBU + 0x28)
#define EBU_ADDR_SEL3     (volatile u32*)(BSP_EBU + 0x2C)
#define EBU_CON0          (volatile u32*)(BSP_EBU + 0x60)
#define EBU_CON1          (volatile u32*)(BSP_EBU + 0x64)
#define EBU_CON2          (volatile u32*)(BSP_EBU + 0x68)
#define EBU_CON3          (volatile u32*)(BSP_EBU + 0x6C)
#define EBU_NAND_CON       (volatile u32*)(BSP_EBU + 0xB0)
#define EBU_NAND_WAIT      (volatile u32*)(BSP_EBU + 0xB4)
#define EBU_NAND_ECC0      (volatile u32*)(BSP_EBU + 0xB8)
#define EBU_NAND_ECC_AC    (volatile u32*)(BSP_EBU + 0xBC)



/***EBU Clock Control Register***/
#define BSP_EBU_CLC                      ((volatile u32*)(BSP_EBU+ 0x0000))
#define BSP_EBU_CLC_DISS                            (1 << 1)
#define BSP_EBU_CLC_DISR                            (1 << 0)

/***EBU Global Control Register***/
#define BSP_EBU_CON                      ((volatile u32*)(BSP_EBU+ 0x0010))
#define BSP_EBU_CON_DTACS (value)              (((( 1 << 3) - 1) & (value)) << 20)
#define BSP_EBU_CON_DTARW (value)              (((( 1 << 3) - 1) & (value)) << 16)
#define BSP_EBU_CON_TOUTC (value)              (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_EBU_CON_ARBMODE (value)            (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_EBU_CON_ARBSYNC                      (1 << 5)
#define BSP_EBU_CON_1                              (1 << 3)

/***EBU Address Select Register 0***/
#define BSP_EBU_ADDSEL0                  ((volatile u32*)(BSP_EBU+ 0x0020))
#define BSP_EBU_ADDSEL0_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL0_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL0_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL0_REGEN                          (1 << 0)

/***EBU Address Select Register 1***/
#define BSP_EBU_ADDSEL1                  ((volatile u32*)(BSP_EBU+ 0x0024))
#define BSP_EBU_ADDSEL1_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL1_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL1_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL1_REGEN                          (1 << 0)

/***EBU Address Select Register 2***/
#define BSP_EBU_ADDSEL2                  ((volatile u32*)(BSP_EBU+ 0x0028))
#define BSP_EBU_ADDSEL2_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL2_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL2_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL2_REGEN                          (1 << 0)

/***EBU Address Select Register 3***/
#define BSP_EBU_ADDSEL3                  ((volatile u32*)(BSP_EBU+ 0x0028))
#define BSP_EBU_ADDSEL3_BASE (value)               (((( 1 << 20) - 1) & (value)) << 12)
#define BSP_EBU_ADDSEL3_MASK (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_EBU_ADDSEL3_MIRRORE                      (1 << 1)
#define BSP_EBU_ADDSEL3_REGEN                          (1 << 0)

/***EBU Bus Configuration Register 0***/
#define BSP_EBU_BUSCON0                  ((volatile u32*)(BSP_EBU+ 0x0060))
#define BSP_EBU_BUSCON0_WRDIS                          (1 << 31)
#define BSP_EBU_BUSCON0_ALEC (value)               (((( 1 << 2) - 1) & (value)) << 29)
#define BSP_EBU_BUSCON0_BCGEN (value)              (((( 1 << 2) - 1) & (value)) << 27)
#define BSP_EBU_BUSCON0_AGEN (value)               (((( 1 << 2) - 1) & (value)) << 24)
#define BSP_EBU_BUSCON0_CMULTR (value)             (((( 1 << 2) - 1) & (value)) << 22)
#define BSP_EBU_BUSCON0_WAIT (value)               (((( 1 << 2) - 1) & (value)) << 20)
#define BSP_EBU_BUSCON0_WAITINV                      (1 << 19)
#define BSP_EBU_BUSCON0_SETUP                          (1 << 18)
#define BSP_EBU_BUSCON0_PORTW (value)              (((( 1 << 2) - 1) & (value)) << 16)
#define BSP_EBU_BUSCON0_WAITRDC (value)            (((( 1 << 7) - 1) & (value)) << 9)
#define BSP_EBU_BUSCON0_WAITWRC (value)            (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_EBU_BUSCON0_HOLDC (value)              (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_EBU_BUSCON0_RECOVC (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_EBU_BUSCON0_CMULT (value)              (((( 1 << 2) - 1) & (value)) << 0)

/***EBU Bus Configuration Register 1***/
#define BSP_EBU_BUSCON1                  ((volatile u32*)(BSP_EBU+ 0x0064))
#define BSP_EBU_BUSCON1_WRDIS                          (1 << 31)
#define BSP_EBU_BUSCON1_ALEC (value)               (((( 1 << 2) - 1) & (value)) << 29)
#define BSP_EBU_BUSCON1_BCGEN (value)              (((( 1 << 2) - 1) & (value)) << 27)
#define BSP_EBU_BUSCON1_AGEN (value)               (((( 1 << 2) - 1) & (value)) << 24)
#define BSP_EBU_BUSCON1_CMULTR (value)             (((( 1 << 2) - 1) & (value)) << 22)
#define BSP_EBU_BUSCON1_WAIT (value)               (((( 1 << 2) - 1) & (value)) << 20)
#define BSP_EBU_BUSCON1_WAITINV                      (1 << 19)
#define BSP_EBU_BUSCON1_SETUP                          (1 << 18)
#define BSP_EBU_BUSCON1_PORTW (value)              (((( 1 << 2) - 1) & (value)) << 16)
#define BSP_EBU_BUSCON1_WAITRDC (value)            (((( 1 << 7) - 1) & (value)) << 9)
#define BSP_EBU_BUSCON1_WAITWRC (value)            (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_EBU_BUSCON1_HOLDC (value)              (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_EBU_BUSCON1_RECOVC (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_EBU_BUSCON1_CMULT (value)              (((( 1 << 2) - 1) & (value)) << 0)

/***EBU Bus Configuration Register 2***/
#define BSP_EBU_BUSCON2                  ((volatile u32*)(BSP_EBU+ 0x0068))
#define BSP_EBU_BUSCON2_WRDIS                          (1 << 31)
#define BSP_EBU_BUSCON2_ALEC (value)               (((( 1 << 2) - 1) & (value)) << 29)
#define BSP_EBU_BUSCON2_BCGEN (value)              (((( 1 << 2) - 1) & (value)) << 27)
#define BSP_EBU_BUSCON2_AGEN (value)               (((( 1 << 2) - 1) & (value)) << 24)
#define BSP_EBU_BUSCON2_CMULTR (value)             (((( 1 << 2) - 1) & (value)) << 22)
#define BSP_EBU_BUSCON2_WAIT (value)               (((( 1 << 2) - 1) & (value)) << 20)
#define BSP_EBU_BUSCON2_WAITINV                      (1 << 19)
#define BSP_EBU_BUSCON2_SETUP                          (1 << 18)
#define BSP_EBU_BUSCON2_PORTW (value)              (((( 1 << 2) - 1) & (value)) << 16)
#define BSP_EBU_BUSCON2_WAITRDC (value)            (((( 1 << 7) - 1) & (value)) << 9)
#define BSP_EBU_BUSCON2_WAITWRC (value)            (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_EBU_BUSCON2_HOLDC (value)              (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_EBU_BUSCON2_RECOVC (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_EBU_BUSCON2_CMULT (value)              (((( 1 << 2) - 1) & (value)) << 0)

#define BSP_EBU_BUSCON3                            ((volatile u32*)(BSP_EBU+ 0x006C))

/* Other EBU Register */
#define BSP_EBU_ID			            ((volatile u32*)(BSP_EBU+ 0x0008))
#define BSP_EBU_EMU_ADDR			    ((volatile u32*)(BSP_EBU+ 0x0080))
#define BSP_EBU_EMU_BC			    ((volatile u32*)(BSP_EBU+ 0x0084))
#define BSP_EBU_EMU_CON		            ((volatile u32*)(BSP_EBU+ 0x0088))

/* EBU PC CARD Register */
#define BSP_EBU_PCC_CON		            ((volatile u32*)(BSP_EBU+ 0x0090))
#define BSP_EBU_PCC_STAT		            ((volatile u32*)(BSP_EBU+ 0x0094))
#define BSP_EBU_PCC_ISTAT		            ((volatile u32*)(BSP_EBU+ 0x00A0))
#define BSP_EBU_PCC_IEN		            ((volatile u32*)(BSP_EBU+ 0x00A4))
#define BSP_EBU_PCC_INT_OUT		            ((volatile u32*)(BSP_EBU+ 0x00A8))
#define BSP_EBU_PCC_IRS		            ((volatile u32*)(BSP_EBU+ 0x00AC))

/***********************************************************************/
/*  Module      :  HSNAND register address and bits                      */
/***********************************************************************/
#define BSP_HSNAND_BASE                         (KSEG1+0x1E100400)
/***********************************************************************/

#define BSP_NDAC_CTRL1                       ((volatile u32*)(BSP_HSNAND_BASE + 0x0010))
#define BSP_NDAC_CTRL2                       ((volatile u32*)(BSP_HSNAND_BASE + 0x0014))
#define BSP_BASE_A                     ((volatile u32*)(BSP_HSNAND_BASE + 0x0018))
#define BSP_RX_CNT                      ((volatile u32*)(BSP_HSNAND_BASE + 0x001C))
#define BSP_DPLUS_CTRL                       ((volatile u32*)(BSP_HSNAND_BASE + 0x0020))
#define BSP_INTR_MASK_CTRL                   ((volatile u32*)(BSP_HSNAND_BASE + 0x0024))
#define BSP_INTR_MASK_STAT                    ((volatile u32*)(BSP_HSNAND_BASE + 0x0028))
#define BSP_HSMD_CTRL                     ((volatile u32*)(BSP_HSNAND_BASE + 0x0030))
#define BSP_CS_BASE_A                 ((volatile u32*)(BSP_HSNAND_BASE + 0x0034))
#define BSP_ND_INFO                  ((volatile u32*)(BSP_HSNAND_BASE + 0x0038))


/***********************************************************************/
/*  Module      :  SDRAM register address and bits                     */
/***********************************************************************/

#define BSP_SDRAM                        (0xBF800000)
/***********************************************************************/


/***MC Access Error Cause Register***/
#define BSP_SDRAM_MC_ERRCAUSE                  ((volatile u32*)(BSP_SDRAM+ 0x0100))
#define BSP_SDRAM_MC_ERRCAUSE_ERR                              (1 << 31)
#define BSP_SDRAM_MC_ERRCAUSE_PORT (value)               (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_SDRAM_MC_ERRCAUSE_CAUSE (value)              (((( 1 << 2) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_ERRCAUSE_Res (value)                (((( 1 << NaN) - 1) & (value)) << NaN)

/***MC Access Error Address Register***/
#define BSP_SDRAM_MC_ERRADDR                   ((volatile u32*)(BSP_SDRAM+ 0x0108))
#define BSP_SDRAM_MC_ERRADDR_ADDR

/***MC I/O General Purpose Register***/
#define BSP_SDRAM_MC_IOGP                      ((volatile u32*)(BSP_SDRAM+ 0x0800))
#define BSP_SDRAM_MC_IOGP_GPR6 (value)               (((( 1 << 4) - 1) & (value)) << 28)
#define BSP_SDRAM_MC_IOGP_GPR5 (value)               (((( 1 << 4) - 1) & (value)) << 24)
#define BSP_SDRAM_MC_IOGP_GPR4 (value)               (((( 1 << 4) - 1) & (value)) << 20)
#define BSP_SDRAM_MC_IOGP_GPR3 (value)               (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_SDRAM_MC_IOGP_GPR2 (value)               (((( 1 << 4) - 1) & (value)) << 12)
#define BSP_SDRAM_MC_IOGP_CPS                              (1 << 11)
#define BSP_SDRAM_MC_IOGP_CLKDELAY (value)          (((( 1 << 3) - 1) & (value)) << 8)
#define BSP_SDRAM_MC_IOGP_CLKRAT (value)             (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_IOGP_RDDEL (value)              (((( 1 << 4) - 1) & (value)) << 0)

/***MC Self Refresh Register***/
#define BSP_SDRAM_MC_SELFRFSH                  ((volatile u32*)(BSP_SDRAM+ 0x0A00))
#define BSP_SDRAM_MC_SELFRFSH_PWDS                            (1 << 1)
#define BSP_SDRAM_MC_SELFRFSH_PWD                              (1 << 0)
#define BSP_SDRAM_MC_SELFRFSH_Res (value)                (((( 1 << 30) - 1) & (value)) << 2)

/***MC Enable Register***/
#define BSP_SDRAM_MC_CTRLENA                   ((volatile u32*)(BSP_SDRAM+ 0x1000))
#define BSP_SDRAM_MC_CTRLENA_ENA                              (1 << 0)
#define BSP_SDRAM_MC_CTRLENA_Res (value)                (((( 1 << 31) - 1) & (value)) << 1)

/***MC Mode Register Setup Code***/
#define BSP_SDRAM_MC_MRSCODE                   ((volatile u32*)(BSP_SDRAM+ 0x1008))
#define BSP_SDRAM_MC_MRSCODE_UMC (value)                (((( 1 << 5) - 1) & (value)) << 7)
#define BSP_SDRAM_MC_MRSCODE_CL (value)                (((( 1 << 3) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_MRSCODE_WT                              (1 << 3)
#define BSP_SDRAM_MC_MRSCODE_BL (value)                (((( 1 << 3) - 1) & (value)) << 0)

/***MC Configuration Data-word Width Register***/
#define BSP_SDRAM_MC_CFGDW                    ((volatile u32*)(BSP_SDRAM+ 0x1010))
#define BSP_SDRAM_MC_CFGDW_DW (value)                (((( 1 << 4) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_CFGDW_Res (value)                (((( 1 << 28) - 1) & (value)) << 4)

/***MC Configuration Physical Bank 0 Register***/
#define BSP_SDRAM_MC_CFGPB0                    ((volatile u32*)(BSP_SDRAM+ 0x1018))
#define BSP_SDRAM_MC_CFGPB0_MCSEN0 (value)             (((( 1 << 4) - 1) & (value)) << 12)
#define BSP_SDRAM_MC_CFGPB0_BANKN0 (value)             (((( 1 << 4) - 1) & (value)) << 8)
#define BSP_SDRAM_MC_CFGPB0_ROWW0 (value)              (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_CFGPB0_COLW0 (value)              (((( 1 << 4) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_CFGPB0_Res (value)                (((( 1 << 16) - 1) & (value)) << 16)

/***MC Latency Register***/
#define BSP_SDRAM_MC_LATENCY                   ((volatile u32*)(BSP_SDRAM+ 0x1038))
#define BSP_SDRAM_MC_LATENCY_TRP (value)                (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_SDRAM_MC_LATENCY_TRAS (value)               (((( 1 << 4) - 1) & (value)) << 12)
#define BSP_SDRAM_MC_LATENCY_TRCD (value)               (((( 1 << 4) - 1) & (value)) << 8)
#define BSP_SDRAM_MC_LATENCY_TDPL (value)               (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_SDRAM_MC_LATENCY_TDAL (value)               (((( 1 << 4) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_LATENCY_Res (value)                (((( 1 << 12) - 1) & (value)) << 20)

/***MC Refresh Cycle Time Register***/
#define BSP_SDRAM_MC_TREFRESH                  ((volatile u32*)(BSP_SDRAM+ 0x1040))
#define BSP_SDRAM_MC_TREFRESH_TREF (value)               (((( 1 << 13) - 1) & (value)) << 0)
#define BSP_SDRAM_MC_TREFRESH_Res (value)                (((( 1 << 19) - 1) & (value)) << 13)




/***********************************************************************/
/*  Module      :  IOM register address and bits                       */
/***********************************************************************/

#define BSP_IOM                          (0xBF105000)
/***********************************************************************/


/***Receive FIFO***/
#define BSP_IOM_RFIFO                        ((volatile u32*)(BSP_IOM+ 0x0000))
#define BSP_IOM_RFIFO_RXD (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Transmit FIFO***/
#define BSP_IOM_XFIFO                        ((volatile u32*)(BSP_IOM+ 0x0000))
#define BSP_IOM_XFIFO_TXD (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Interrupt Status Register HDLC***/
#define BSP_IOM_ISTAH                        ((volatile u32*)(BSP_IOM+ 0x0080))
#define BSP_IOM_ISTAH_RME                              (1 << 7)
#define BSP_IOM_ISTAH_RPF                              (1 << 6)
#define BSP_IOM_ISTAH_RFO                              (1 << 5)
#define BSP_IOM_ISTAH_XPR                              (1 << 4)
#define BSP_IOM_ISTAH_XMR                              (1 << 3)
#define BSP_IOM_ISTAH_XDU                              (1 << 2)

/***Interrupt Mask Register HDLC***/
#define BSP_IOM_MASKH                        ((volatile u32*)(BSP_IOM+ 0x0080))
#define BSP_IOM_MASKH_RME                              (1 << 7)
#define BSP_IOM_MASKH_RPF                              (1 << 6)
#define BSP_IOM_MASKH_RFO                              (1 << 5)
#define BSP_IOM_MASKH_XPR                              (1 << 4)
#define BSP_IOM_MASKH_XMR                              (1 << 3)
#define BSP_IOM_MASKH_XDU                              (1 << 2)

/***Status Register***/
#define BSP_IOM_STAR                         ((volatile u32*)(BSP_IOM+ 0x0084))
#define BSP_IOM_STAR_XDOV                            (1 << 7)
#define BSP_IOM_STAR_XFW                              (1 << 6)
#define BSP_IOM_STAR_RACI                            (1 << 3)
#define BSP_IOM_STAR_XACI                            (1 << 1)

/***Command Register***/
#define BSP_IOM_CMDR                         ((volatile u32*)(BSP_IOM+ 0x0084))
#define BSP_IOM_CMDR_RMC                              (1 << 7)
#define BSP_IOM_CMDR_RRES                            (1 << 6)
#define BSP_IOM_CMDR_XTF                              (1 << 3)
#define BSP_IOM_CMDR_XME                              (1 << 1)
#define BSP_IOM_CMDR_XRES                            (1 << 0)

/***Mode Register***/
#define BSP_IOM_MODEH                        ((volatile u32*)(BSP_IOM+ 0x0088))
#define BSP_IOM_MODEH_MDS2                            (1 << 7)
#define BSP_IOM_MODEH_MDS1                            (1 << 6)
#define BSP_IOM_MODEH_MDS0                            (1 << 5)
#define BSP_IOM_MODEH_RAC                              (1 << 3)
#define BSP_IOM_MODEH_DIM2                            (1 << 2)
#define BSP_IOM_MODEH_DIM1                            (1 << 1)
#define BSP_IOM_MODEH_DIM0                            (1 << 0)

/***Extended Mode Register***/
#define BSP_IOM_EXMR                         ((volatile u32*)(BSP_IOM+ 0x008C))
#define BSP_IOM_EXMR_XFBS                            (1 << 7)
#define BSP_IOM_EXMR_RFBS (value)               (((( 1 << 2) - 1) & (value)) << 5)
#define BSP_IOM_EXMR_SRA                              (1 << 4)
#define BSP_IOM_EXMR_XCRC                            (1 << 3)
#define BSP_IOM_EXMR_RCRC                            (1 << 2)
#define BSP_IOM_EXMR_ITF                              (1 << 0)

/***SAPI1 Register***/
#define BSP_IOM_SAP1                         ((volatile u32*)(BSP_IOM+ 0x0094))
#define BSP_IOM_SAP1_SAPI1 (value)              (((( 1 << 6) - 1) & (value)) << 2)
#define BSP_IOM_SAP1_MHA                              (1 << 0)

/***Receive Frame Byte Count Low***/
#define BSP_IOM_RBCL                         ((volatile u32*)(BSP_IOM+ 0x0098))
#define BSP_IOM_RBCL_RBC(value)              (1 << value)


/***SAPI2 Register***/
#define BSP_IOM_SAP2                         ((volatile u32*)(BSP_IOM+ 0x0098))
#define BSP_IOM_SAP2_SAPI2 (value)              (((( 1 << 6) - 1) & (value)) << 2)
#define BSP_IOM_SAP2_MLA                              (1 << 0)

/***Receive Frame Byte Count High***/
#define BSP_IOM_RBCH                         ((volatile u32*)(BSP_IOM+ 0x009C))
#define BSP_IOM_RBCH_OV                              (1 << 4)
#define BSP_IOM_RBCH_RBC11                          (1 << 3)
#define BSP_IOM_RBCH_RBC10                          (1 << 2)
#define BSP_IOM_RBCH_RBC9                            (1 << 1)
#define BSP_IOM_RBCH_RBC8                            (1 << 0)

/***TEI1 Register 1***/
#define BSP_IOM_TEI1                         ((volatile u32*)(BSP_IOM+ 0x009C))
#define BSP_IOM_TEI1_TEI1 (value)               (((( 1 << 7) - 1) & (value)) << 1)
#define BSP_IOM_TEI1_EA                              (1 << 0)

/***Receive Status Register***/
#define BSP_IOM_RSTA                         ((volatile u32*)(BSP_IOM+ 0x00A0))
#define BSP_IOM_RSTA_VFR                              (1 << 7)
#define BSP_IOM_RSTA_RDO                              (1 << 6)
#define BSP_IOM_RSTA_CRC                              (1 << 5)
#define BSP_IOM_RSTA_RAB                              (1 << 4)
#define BSP_IOM_RSTA_SA1                              (1 << 3)
#define BSP_IOM_RSTA_SA0                              (1 << 2)
#define BSP_IOM_RSTA_TA                              (1 << 0)
#define BSP_IOM_RSTA_CR                              (1 << 1)

/***TEI2 Register***/
#define BSP_IOM_TEI2                         ((volatile u32*)(BSP_IOM+ 0x00A0))
#define BSP_IOM_TEI2_TEI2 (value)               (((( 1 << 7) - 1) & (value)) << 1)
#define BSP_IOM_TEI2_EA                              (1 << 0)

/***Test Mode Register HDLC***/
#define BSP_IOM_TMH                          ((volatile u32*)(BSP_IOM+ 0x00A4))
#define BSP_IOM_TMH_TLP                              (1 << 0)

/***Command/Indication Receive 0***/
#define BSP_IOM_CIR0                         ((volatile u32*)(BSP_IOM+ 0x00B8))
#define BSP_IOM_CIR0_CODR0 (value)              (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_IOM_CIR0_CIC0                            (1 << 3)
#define BSP_IOM_CIR0_CIC1                            (1 << 2)
#define BSP_IOM_CIR0_SG                              (1 << 1)
#define BSP_IOM_CIR0_BAS                              (1 << 0)

/***Command/Indication Transmit 0***/
#define BSP_IOM_CIX0                         ((volatile u32*)(BSP_IOM+ 0x00B8))
#define BSP_IOM_CIX0_CODX0 (value)              (((( 1 << 4) - 1) & (value)) << 4)
#define BSP_IOM_CIX0_TBA2                            (1 << 3)
#define BSP_IOM_CIX0_TBA1                            (1 << 2)
#define BSP_IOM_CIX0_TBA0                            (1 << 1)
#define BSP_IOM_CIX0_BAC                              (1 << 0)

/***Command/Indication Receive 1***/
#define BSP_IOM_CIR1                         ((volatile u32*)(BSP_IOM+ 0x00BC))
#define BSP_IOM_CIR1_CODR1 (value)              (((( 1 << 6) - 1) & (value)) << 2)

/***Command/Indication Transmit 1***/
#define BSP_IOM_CIX1                         ((volatile u32*)(BSP_IOM+ 0x00BC))
#define BSP_IOM_CIX1_CODX1 (value)              (((( 1 << 6) - 1) & (value)) << 2)
#define BSP_IOM_CIX1_CICW                            (1 << 1)
#define BSP_IOM_CIX1_CI1E                            (1 << 0)

/***Controller Data Access Reg. (CH10)***/
#define BSP_IOM_CDA10                        ((volatile u32*)(BSP_IOM+ 0x0100))
#define BSP_IOM_CDA10_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Controller Data Access Reg. (CH11)***/
#define BSP_IOM_CDA11                        ((volatile u32*)(BSP_IOM+ 0x0104))
#define BSP_IOM_CDA11_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Controller Data Access Reg. (CH20)***/
#define BSP_IOM_CDA20                        ((volatile u32*)(BSP_IOM+ 0x0108))
#define BSP_IOM_CDA20_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Controller Data Access Reg. (CH21)***/
#define BSP_IOM_CDA21                        ((volatile u32*)(BSP_IOM+ 0x010C))
#define BSP_IOM_CDA21_CDA (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH10)***/
#define BSP_IOM_CDA_TSDP10                   ((volatile u32*)(BSP_IOM+ 0x0110))
#define BSP_IOM_CDA_TSDP10_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP10_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH11)***/
#define BSP_IOM_CDA_TSDP11                   ((volatile u32*)(BSP_IOM+ 0x0114))
#define BSP_IOM_CDA_TSDP11_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP11_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH20)***/
#define BSP_IOM_CDA_TSDP20                   ((volatile u32*)(BSP_IOM+ 0x0118))
#define BSP_IOM_CDA_TSDP20_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP20_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH21)***/
#define BSP_IOM_CDA_TSDP21                   ((volatile u32*)(BSP_IOM+ 0x011C))
#define BSP_IOM_CDA_TSDP21_DPS                              (1 << 7)
#define BSP_IOM_CDA_TSDP21_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH10)***/
#define BSP_IOM_CO_TSDP10                    ((volatile u32*)(BSP_IOM+ 0x0120))
#define BSP_IOM_CO_TSDP10_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP10_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH11)***/
#define BSP_IOM_CO_TSDP11                    ((volatile u32*)(BSP_IOM+ 0x0124))
#define BSP_IOM_CO_TSDP11_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP11_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH20)***/
#define BSP_IOM_CO_TSDP20                    ((volatile u32*)(BSP_IOM+ 0x0128))
#define BSP_IOM_CO_TSDP20_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP20_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Time Slot and Data Port Sel. (CH21)***/
#define BSP_IOM_CO_TSDP21                    ((volatile u32*)(BSP_IOM+ 0x012C))
#define BSP_IOM_CO_TSDP21_DPS                              (1 << 7)
#define BSP_IOM_CO_TSDP21_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Ctrl. Reg. Contr. Data Access CH1x***/
#define BSP_IOM_CDA1_CR                      ((volatile u32*)(BSP_IOM+ 0x0138))
#define BSP_IOM_CDA1_CR_EN_TBM                        (1 << 5)
#define BSP_IOM_CDA1_CR_EN_I1                          (1 << 4)
#define BSP_IOM_CDA1_CR_EN_I0                          (1 << 3)
#define BSP_IOM_CDA1_CR_EN_O1                          (1 << 2)
#define BSP_IOM_CDA1_CR_EN_O0                          (1 << 1)
#define BSP_IOM_CDA1_CR_SWAP                            (1 << 0)

/***Ctrl. Reg. Contr. Data Access CH1x***/
#define BSP_IOM_CDA2_CR                      ((volatile u32*)(BSP_IOM+ 0x013C))
#define BSP_IOM_CDA2_CR_EN_TBM                        (1 << 5)
#define BSP_IOM_CDA2_CR_EN_I1                          (1 << 4)
#define BSP_IOM_CDA2_CR_EN_I0                          (1 << 3)
#define BSP_IOM_CDA2_CR_EN_O1                          (1 << 2)
#define BSP_IOM_CDA2_CR_EN_O0                          (1 << 1)
#define BSP_IOM_CDA2_CR_SWAP                            (1 << 0)

/***Control Register B-Channel Data***/
#define BSP_IOM_BCHA_CR                      ((volatile u32*)(BSP_IOM+ 0x0144))
#define BSP_IOM_BCHA_CR_EN_BC2                        (1 << 4)
#define BSP_IOM_BCHA_CR_EN_BC1                        (1 << 3)

/***Control Register B-Channel Data***/
#define BSP_IOM_BCHB_CR                      ((volatile u32*)(BSP_IOM+ 0x0148))
#define BSP_IOM_BCHB_CR_EN_BC2                        (1 << 4)
#define BSP_IOM_BCHB_CR_EN_BC1                        (1 << 3)

/***Control Reg. for HDLC and CI1 Data***/
#define BSP_IOM_DCI_CR                       ((volatile u32*)(BSP_IOM+ 0x014C))
#define BSP_IOM_DCI_CR_DPS_CI1                      (1 << 7)
#define BSP_IOM_DCI_CR_EN_CI1                        (1 << 6)
#define BSP_IOM_DCI_CR_EN_D                            (1 << 5)

/***Control Reg. for HDLC and CI1 Data***/
#define BSP_IOM_DCIC_CR                      ((volatile u32*)(BSP_IOM+ 0x014C))
#define BSP_IOM_DCIC_CR_DPS_CI0                      (1 << 7)
#define BSP_IOM_DCIC_CR_EN_CI0                        (1 << 6)
#define BSP_IOM_DCIC_CR_DPS_D                          (1 << 5)

/***Control Reg. Serial Data Strobe x***/
#define BSP_IOM_SDS_CR                       ((volatile u32*)(BSP_IOM+ 0x0154))
#define BSP_IOM_SDS_CR_ENS_TSS                      (1 << 7)
#define BSP_IOM_SDS_CR_ENS_TSS_1                  (1 << 6)
#define BSP_IOM_SDS_CR_ENS_TSS_3                  (1 << 5)
#define BSP_IOM_SDS_CR_TSS (value)                (((( 1 << 4) - 1) & (value)) << 0)

/***Control Register IOM Data***/
#define BSP_IOM_IOM_CR                       ((volatile u32*)(BSP_IOM+ 0x015C))
#define BSP_IOM_IOM_CR_SPU                              (1 << 7)
#define BSP_IOM_IOM_CR_CI_CS                          (1 << 5)
#define BSP_IOM_IOM_CR_TIC_DIS                      (1 << 4)
#define BSP_IOM_IOM_CR_EN_BCL                        (1 << 3)
#define BSP_IOM_IOM_CR_CLKM                            (1 << 2)
#define BSP_IOM_IOM_CR_Res                              (1 << 1)
#define BSP_IOM_IOM_CR_DIS_IOM                      (1 << 0)

/***Synchronous Transfer Interrupt***/
#define BSP_IOM_STI                          ((volatile u32*)(BSP_IOM+ 0x0160))
#define BSP_IOM_STI_STOV21                        (1 << 7)
#define BSP_IOM_STI_STOV20                        (1 << 6)
#define BSP_IOM_STI_STOV11                        (1 << 5)
#define BSP_IOM_STI_STOV10                        (1 << 4)
#define BSP_IOM_STI_STI21                          (1 << 3)
#define BSP_IOM_STI_STI20                          (1 << 2)
#define BSP_IOM_STI_STI11                          (1 << 1)
#define BSP_IOM_STI_STI10                          (1 << 0)

/***Acknowledge Synchronous Transfer Interrupt***/
#define BSP_IOM_ASTI                         ((volatile u32*)(BSP_IOM+ 0x0160))
#define BSP_IOM_ASTI_ACK21                          (1 << 3)
#define BSP_IOM_ASTI_ACK20                          (1 << 2)
#define BSP_IOM_ASTI_ACK11                          (1 << 1)
#define BSP_IOM_ASTI_ACK10                          (1 << 0)

/***Mask Synchronous Transfer Interrupt***/
#define BSP_IOM_MSTI                         ((volatile u32*)(BSP_IOM+ 0x0164))
#define BSP_IOM_MSTI_STOV21                        (1 << 7)
#define BSP_IOM_MSTI_STOV20                        (1 << 6)
#define BSP_IOM_MSTI_STOV11                        (1 << 5)
#define BSP_IOM_MSTI_STOV10                        (1 << 4)
#define BSP_IOM_MSTI_STI21                          (1 << 3)
#define BSP_IOM_MSTI_STI20                          (1 << 2)
#define BSP_IOM_MSTI_STI11                          (1 << 1)
#define BSP_IOM_MSTI_STI10                          (1 << 0)

/***Configuration Register for Serial Data Strobes***/
#define BSP_IOM_SDS_CONF                    ((volatile u32*)(BSP_IOM+ 0x0168))
#define BSP_IOM_SDS_CONF_SDS_BCL                      (1 << 0)

/***Monitoring CDA Bits***/
#define BSP_IOM_MCDA                         ((volatile u32*)(BSP_IOM+ 0x016C))
#define BSP_IOM_MCDA_MCDA21 (value)             (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_IOM_MCDA_MCDA20 (value)             (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_IOM_MCDA_MCDA11 (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_IOM_MCDA_MCDA10 (value)             (((( 1 << 2) - 1) & (value)) << 0)

/***********************************************************************/
/*  Module      :  ASC0 register address and bits                      */
/***********************************************************************/
#define BSP_ASC0                          (KSEG1+0x1E100400)
/***********************************************************************/
#define BSP_ASC0_TBUF                        ((volatile u32*)(BSP_ASC0 + 0x0020))
#define BSP_ASC0_RBUF                        ((volatile u32*)(BSP_ASC0 + 0x0024))
#define BSP_ASC0_FSTAT                       ((volatile u32*)(BSP_ASC0 + 0x0048))
#define BSP_ASC0_FSTAT_TXFREE_GET(value)     (((value) >> 24) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_TXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 24)
#define BSP_ASC0_FSTAT_RXFREE_GET(value)     (((value) >> 16) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_RXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 16)
#define BSP_ASC0_FSTAT_TXFFL_GET(value)      (((value) >> 8) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_TXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_ASC0_FSTAT_RXFFL_GET(value)      (((value) >> 0) & ((1 << 6) - 1))
#define BSP_ASC0_FSTAT_RXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 0)



#define BSP_ASC1_FSTAT_TXFREE_GET(value)     (((value) >> 24) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_TXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 24)
#define BSP_ASC1_FSTAT_RXFREE_GET(value)     (((value) >> 16) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_RXFREE_SET(value)     (((( 1 << 6) - 1) & (value)) << 16)
#define BSP_ASC1_FSTAT_TXFFL_GET(value)      (((value) >> 8) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_TXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 8)
#define BSP_ASC1_FSTAT_RXFFL_GET(value)      (((value) >> 0) & ((1 << 6) - 1))
#define BSP_ASC1_FSTAT_RXFFL_SET(value)      (((( 1 << 6) - 1) & (value)) << 0)

/***ASC Modem Control Register***/
#define ASC_MODCTL                      ((volatile u32*)(BSP_ASC1+ 0x0060))
#define ASC_MODCTL_RTSFC               	(1 << 5)
#define ASC_MODCTL_CTSFC                (1 << 4)
#define ASC_MODCTL_RTSSET		(1 << 18)
#define ASC_MODCTL_RTSCLR		(1 << 19)
/***********************************************************************/
/*  Module      :  DMA register address and bits                       */
/***********************************************************************/
#define BSP_DMA_OFFSET 0xBE104100
/***********************************************************************/
#define BSP_DMA_CLC                   ((volatile u32*)(BSP_DMA_OFFSET + 0x0000))
#define BSP_DMA_ID                    ((volatile u32*)(BSP_DMA_OFFSET + 0x0008))
#define BSP_DMA_CTRL                  ((volatile u32*)(BSP_DMA_OFFSET + 0x0010))

#define BSP_DMA_PS                    ((volatile u32*)(BSP_DMA_OFFSET + 0x0040))
#define BSP_DMA_PCTRL                 ((volatile u32*)(BSP_DMA_OFFSET + 0x0044))
#define BSP_DMA_IRNEN                 ((volatile u32*)(BSP_DMA_OFFSET + 0x00F4))
#define BSP_DMA_IRNCR                 ((volatile u32*)(BSP_DMA_OFFSET + 0x00F8))
#define BSP_DMA_IRNICR                ((volatile u32*)(BSP_DMA_OFFSET + 0x00FC))

#define BSP_DMA_CS                    ((volatile u32*)(BSP_DMA_OFFSET + 0x0018))
#define BSP_DMA_CCTRL                 ((volatile u32*)(BSP_DMA_OFFSET + 0x001C))
#define BSP_DMA_CDBA                  ((volatile u32*)(BSP_DMA_OFFSET + 0x0020))
#define BSP_DMA_CGBL                  ((volatile u32*)(BSP_DMA_OFFSET + 0x0030))
#define BSP_DMA_CIE                   ((volatile u32*)(BSP_DMA_OFFSET + 0x002C))
#define BSP_DMA_CIS                   ((volatile u32*)(BSP_DMA_OFFSET + 0x0028))
#define BSP_DMA_CDLEN                 ((volatile u32*)(BSP_DMA_OFFSET + 0x0024))
#define BSP_DMA_CPOLL                 ((volatile u32*)(BSP_DMA_OFFSET + 0x0014))

//mask def
#define BSP_DMA_CLC_MASK 0x0000003F
#define BSP_DMA_ID_MASK 0x00000000
#define BSP_DMA_CTRL_MASK 0x00000000

#define BSP_DMA_PS_MASK 0x00000007
#define BSP_DMA_PCTRL_MASK 0x00017C7C
#define BSP_DMA_IRNEN_MASK 0x000FFFFF
#define BSP_DMA_IRNCR_MASK 0x000FFFFF
#define BSP_DMA_IRNICR_MASK 0x00F0FFFF

#define BSP_DMA_CS_MASK 0x0000001F
#define BSP_DMA_CCTRL_MASK 0x00020601
#define BSP_DMA_CDBA_MASK 0x0FFFFFF8
#define BSP_DMA_CIE_MASK 0x0000007E
#define BSP_DMA_CIS_MASK 0x0000007E
#define BSP_DMA_CDLEN_MASK 0x000000FF
#define BSP_DMA_CPOLL_MASK 0x8000FFF0

#define BSP_DMA_DES_BASE 0x00010000 
#define BSP_DMA_DATA_BASE 0x00100000
#define BSP_DMA_CPOLL_MASK 0x8000FFF0

#define BSP_DMA                          (0xBF108000)
/***********************************************************************/


/***DMA RX Channel 0 Command Register***/
#define BSP_DMA_DMA_RXCCR0                   ((volatile u32*)(BSP_DMA+ 0x0800))
#define BSP_DMA_DMA_RXCCR0_LBE                              (1 << 31)
#define BSP_DMA_DMA_RXCCR0_HPEN                            (1 << 30)
#define BSP_DMA_DMA_RXCCR0_INIT                            (1 << 2)
#define BSP_DMA_DMA_RXCCR0_OFF                              (1 << 1)
#define BSP_DMA_DMA_RXCCR0_HR                              (1 << 0)

/***DMA RX Channel 1 Command Register***/
#define BSP_DMA_DMA_RXCCR1                   ((volatile u32*)(BSP_DMA+ 0x0804))
#define BSP_DMA_DMA_RXCCR1_LBE                              (1 << 31)
#define BSP_DMA_DMA_RXCCR1_HPEN                            (1 << 30)
#define BSP_DMA_DMA_RXCCR1_INIT                            (1 << 2)
#define BSP_DMA_DMA_RXCCR1_OFF                              (1 << 1)
#define BSP_DMA_DMA_RXCCR1_HR                              (1 << 0)

/***DMA Receive Interrupt Status Register***/
#define BSP_DMA_DMA_RXISR                    ((volatile u32*)(BSP_DMA+ 0x0808))
#define BSP_DMA_DMA_RXISR_RDERRx (value)             (((( 1 << 2) - 1) & (value)) << 8)
#define BSP_DMA_DMA_RXISR_CMDCPTx (value)            (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_DMA_DMA_RXISR_EOPx (value)               (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_DMA_DMA_RXISR_CPTx (value)               (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_DMA_DMA_RXISR_HLDx (value)               (((( 1 << 2) - 1) & (value)) << 0)

/***DMA Receive Interrupt Mask Register***/
#define BSP_DMA_DMA_RXIMR                    ((volatile u32*)(BSP_DMA+ 0x080C))
#define BSP_DMA_DMA_RXIMR_RDERRx (value)             (((( 1 << 2) - 1) & (value)) << 8)
#define BSP_DMA_DMA_RXIMR_CMDCPTx (value)            (((( 1 << 2) - 1) & (value)) << 6)
#define BSP_DMA_DMA_RXIMR_EOPx (value)               (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_DMA_DMA_RXIMR_CPTx (value)               (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_DMA_DMA_RXIMR_HLDx (value)               (((( 1 << 2) - 1) & (value)) << 0)

/***DMA First Receive Descriptor Addr. for Rx Channel 0
***/
#define BSP_DMA_DMA_RXFRDA0                  ((volatile u32*)(BSP_DMA+ 0x0810))
#define BSP_DMA_DMA_RXFRDA0_RXFRDA (value)             (((( 1 << 28) - 1) & (value)) << 0)

/***DMA First Receive Descriptor Addr. for Rx Channel 1
***/
#define BSP_DMA_DMA_RXFRDA1                  ((volatile u32*)(BSP_DMA+ 0x0814))
#define BSP_DMA_DMA_RXFRDA1_RXFRDA (value)             (((( 1 << 28) - 1) & (value)) << 0)

/***DMA Receive Channel Polling Time***/
#define BSP_DMA_DMA_RXPOLL                   ((volatile u32*)(BSP_DMA+ 0x0818))
#define BSP_DMA_DMA_RXPOLL_BSZ1 (value)               (((( 1 << 2) - 1) & (value)) << 30)
#define BSP_DMA_DMA_RXPOLL_BSZ0 (value)               (((( 1 << 2) - 1) & (value)) << 28)
#define BSP_DMA_DMA_RXPOLL_RXPOLLTIME (value)         (((( 1 << 8) - 1) & (value)) << 0)

/***DMA TX Channel 0 Command Register (Voice Port)***/
#define BSP_DMA_DMA_TXCCR0                   ((volatile u32*)(BSP_DMA+ 0x0880))
#define BSP_DMA_DMA_TXCCR0_LBE                              (1 << 31)
#define BSP_DMA_DMA_TXCCR0_HPEN                            (1 << 30)
#define BSP_DMA_DMA_TXCCR0_HR                              (1 << 2)
#define BSP_DMA_DMA_TXCCR0_OFF                              (1 << 1)
#define BSP_DMA_DMA_TXCCR0_INIT                            (1 << 0)

/***DMA TX Channel 1 Command Register (Mangmt Port)***/
#define BSP_DMA_DMA_TXCCR1                   ((volatile u32*)(BSP_DMA+ 0x0884))
#define BSP_DMA_DMA_TXCCR1_LBE                              (1 << 31)
#define BSP_DMA_DMA_TXCCR1_HPEN                            (1 << 30)
#define BSP_DMA_DMA_TXCCR1_HR                              (1 << 2)
#define BSP_DMA_DMA_TXCCR1_OFF                              (1 << 1)
#define BSP_DMA_DMA_TXCCR1_INIT                            (1 << 0)

/***DMA TX Channel 2 Command Register (SSC Port)***/
#define BSP_DMA_DMA_TXCCR2                   ((volatile u32*)(BSP_DMA+ 0x0888))
#define BSP_DMA_DMA_TXCCR2_LBE                              (1 << 31)
#define BSP_DMA_DMA_TXCCR2_HPEN                            (1 << 30)
#define BSP_DMA_DMA_TXCCR2_HBF                              (1 << 29)
#define BSP_DMA_DMA_TXCCR2_HR                              (1 << 2)
#define BSP_DMA_DMA_TXCCR2_OFF                              (1 << 1)
#define BSP_DMA_DMA_TXCCR2_INIT                            (1 << 0)

/***DMA First Receive Descriptor Addr. for Tx Channel 0
***/
#define BSP_DMA_DMA_TXFRDA0                  ((volatile u32*)(BSP_DMA+ 0x08A0))
#define BSP_DMA_DMA_TXFRDA0_TXFRDA (value)             (((( 1 << 28) - 1) & (value)) << 0)

/***DMA First Receive Descriptor Addr. for Tx Channel 1
***/
#define BSP_DMA_DMA_TXFRDA1                  ((volatile u32*)(BSP_DMA+ 0x08A4))
#define BSP_DMA_DMA_TXFRDA1_TXFRDA (value)             (((( 1 << 28) - 1) & (value)) << 0)

/***DMA First Receive Descriptor Addr. for Tx Channel 2
***/
#define BSP_DMA_DMA_TXFRDA2                  ((volatile u32*)(BSP_DMA+ 0x08A8))
#define BSP_DMA_DMA_TXFRDA2_TXFRDA (value)             (((( 1 << 28) - 1) & (value)) << 0)

/***DMA Transmit Channel Arbitration Register***/
#define BSP_DMA_DMA_TXWGT                    ((volatile u32*)(BSP_DMA+ 0x08C0))
#define BSP_DMA_DMA_TXWGT_TX2PR (value)              (((( 1 << 2) - 1) & (value)) << 4)
#define BSP_DMA_DMA_TXWGT_TX1PRI (value)             (((( 1 << 2) - 1) & (value)) << 2)
#define BSP_DMA_DMA_TXWGT_TX0PRI (value)             (((( 1 << 2) - 1) & (value)) << 0)

/***DMA Transmit Channel Polling Time***/
#define BSP_DMA_DMA_TXPOLL                   ((volatile u32*)(BSP_DMA+ 0x08C4))
#define BSP_DMA_DMA_TXPOLL_BSZ2 (value)               (((( 1 << 2) - 1) & (value)) << 30)
#define BSP_DMA_DMA_TXPOLL_BSZ1 (value)               (((( 1 << 2) - 1) & (value)) << 28)
#define BSP_DMA_DMA_TXPOLL_BSZ0 (value)               (((( 1 << 2) - 1) & (value)) << 26)
#define BSP_DMA_DMA_TXPOLL_TXPOLLTIME (value)         (((( 1 << 8) - 1) & (value)) << 0)

/***DMA Transmit Interrupt Status Register***/
#define BSP_DMA_DMA_TXISR                    ((volatile u32*)(BSP_DMA+ 0x08C8))
#define BSP_DMA_DMA_TXISR_RDERRx (value)             (((( 1 << 3) - 1) & (value)) << 12)
#define BSP_DMA_DMA_TXISR_HLDx (value)               (((( 1 << 3) - 1) & (value)) << 9)
#define BSP_DMA_DMA_TXISR_CPTx (value)               (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_DMA_DMA_TXISR_EOPx (value)               (((( 1 << 3) - 1) & (value)) << 3)
#define BSP_DMA_DMA_TXISR_CMDCPTx (value)            (((( 1 << 3) - 1) & (value)) << 0)

/***DMA Transmit Interrupt Mask Register***/
#define BSP_DMA_DMA_TXIMR                    ((volatile u32*)(BSP_DMA+ 0x08CC))
#define BSP_DMA_DMA_TXIMR_RDERRx (value)             (((( 1 << 3) - 1) & (value)) << 12)
#define BSP_DMA_DMA_TXIMR_HLDx (value)               (((( 1 << 3) - 1) & (value)) << 9)
#define BSP_DMA_DMA_TXIMR_CPTx (value)               (((( 1 << 3) - 1) & (value)) << 6)
#define BSP_DMA_DMA_TXIMR_EOPx (value)               (((( 1 << 3) - 1) & (value)) << 3)
#define BSP_DMA_DMA_TXIMR_CMDCPTx (value)            (((( 1 << 3) - 1) & (value)) << 0)

/***********************************************************************/
/*  Module      :  Debug register address and bits                     */
/***********************************************************************/

#define BSP_Debug                        (0xBF106000)
/***********************************************************************/


/***MCD Break Bus Switch Register***/
#define BSP_Debug_MCD_BBS                      ((volatile u32*)(BSP_Debug+ 0x0000))
#define BSP_Debug_MCD_BBS_BTP1                            (1 << 19)
#define BSP_Debug_MCD_BBS_BTP0                            (1 << 18)
#define BSP_Debug_MCD_BBS_BSP1                            (1 << 17)
#define BSP_Debug_MCD_BBS_BSP0                            (1 << 16)
#define BSP_Debug_MCD_BBS_BT5EN                          (1 << 15)
#define BSP_Debug_MCD_BBS_BT4EN                          (1 << 14)
#define BSP_Debug_MCD_BBS_BT5                              (1 << 13)
#define BSP_Debug_MCD_BBS_BT4                              (1 << 12)
#define BSP_Debug_MCD_BBS_BS5EN                          (1 << 7)
#define BSP_Debug_MCD_BBS_BS4EN                          (1 << 6)
#define BSP_Debug_MCD_BBS_BS5                              (1 << 5)
#define BSP_Debug_MCD_BBS_BS4                              (1 << 4)

/***MCD Multiplexer Control Register***/
#define BSP_Debug_MCD_MCR                      ((volatile u32*)(BSP_Debug+ 0x0008))
#define BSP_Debug_MCD_MCR_MUX5                            (1 << 4)
#define BSP_Debug_MCD_MCR_MUX4                            (1 << 3)
#define BSP_Debug_MCD_MCR_MUX1                            (1 << 0)


/***********************************************************************/
/*  Module      :  SRAM register address and bits                      */
/***********************************************************************/

#define BSP_SRAM                         (0xBF980000)
/***********************************************************************/


/***SRAM Size Register***/
#define BSP_SRAM_SRAM_SIZE                    ((volatile u32*)(BSP_SRAM+ 0x0800))
#define BSP_SRAM_SRAM_SIZE_SIZE (value)               (((( 1 << 23) - 1) & (value)) << 0)

/***********************************************************************/
/*  Module      :  BIU register address and bits                       */
/***********************************************************************/

#define BSP_BIU                          (0xBFA80000)
/***********************************************************************/


/***BIU Identification Register***/
#define BSP_BIU_BIU_ID                       ((volatile u32*)(BSP_BIU+ 0x0000))
#define BSP_BIU_BIU_ID_ARCH                            (1 << 16)
#define BSP_BIU_BIU_ID_ID (value)                (((( 1 << 8) - 1) & (value)) << 8)
#define BSP_BIU_BIU_ID_REV (value)                (((( 1 << 8) - 1) & (value)) << 0)

/***BIU Access Error Cause Register***/
#define BSP_BIU_BIU_ERRCAUSE                 ((volatile u32*)(BSP_BIU+ 0x0100))
#define BSP_BIU_BIU_ERRCAUSE_ERR                              (1 << 31)
#define BSP_BIU_BIU_ERRCAUSE_PORT (value)               (((( 1 << 4) - 1) & (value)) << 16)
#define BSP_BIU_BIU_ERRCAUSE_CAUSE (value)              (((( 1 << 2) - 1) & (value)) << 0)

/***BIU Access Error Address Register***/
#define BSP_BIU_BIU_ERRADDR                  ((volatile u32*)(BSP_BIU+ 0x0108))
#define BSP_BIU_BIU_ERRADDR_ADDR


/***********************************************************************/
/*  Module      :  MPS register address and bits                       */
/***********************************************************************/

#define BSP_MPS                          (KSEG1+0x1F107000)
/***********************************************************************/

#define BSP_MPS_CHIPID                       ((volatile u32*)(BSP_MPS + 0x0344))
#define BSP_MPS_CHIPID_VERSION_GET(value)    (((value) >> 28) & ((1 << 4) - 1))
#define BSP_MPS_CHIPID_VERSION_SET(value)    (((( 1 << 4) - 1) & (value)) << 28)
#define BSP_MPS_CHIPID_PARTNUM_GET(value)    (((value) >> 12) & ((1 << 16) - 1))
#define BSP_MPS_CHIPID_PARTNUM_SET(value)    (((( 1 << 16) - 1) & (value)) << 12)
#define BSP_MPS_CHIPID_MANID_GET(value)      (((value) >> 1) & ((1 << 10) - 1))
#define BSP_MPS_CHIPID_MANID_SET(value)      (((( 1 << 10) - 1) & (value)) << 1)


/* voice channel 0 ... 3 interrupt enable register */
#define BSP_MPS_VC0ENR ((volatile u32*)(BSP_MPS + 0x0000))
#define BSP_MPS_VC1ENR ((volatile u32*)(BSP_MPS + 0x0004))
#define BSP_MPS_VC2ENR ((volatile u32*)(BSP_MPS + 0x0008))
#define BSP_MPS_VC3ENR ((volatile u32*)(BSP_MPS + 0x000C))
/* voice channel 0 ... 3 interrupt status read register */
#define BSP_MPS_RVC0SR ((volatile u32*)(BSP_MPS + 0x0010))
#define BSP_MPS_RVC1SR ((volatile u32*)(BSP_MPS + 0x0014))
#define BSP_MPS_RVC2SR ((volatile u32*)(BSP_MPS + 0x0018))
#define BSP_MPS_RVC3SR ((volatile u32*)(BSP_MPS + 0x001C))
/* voice channel 0 ... 3 interrupt status set register */
#define BSP_MPS_SVC0SR ((volatile u32*)(BSP_MPS + 0x0020))
#define BSP_MPS_SVC1SR ((volatile u32*)(BSP_MPS + 0x0024))
#define BSP_MPS_SVC2SR ((volatile u32*)(BSP_MPS + 0x0028))
#define BSP_MPS_SVC3SR ((volatile u32*)(BSP_MPS + 0x002C))
/* voice channel 0 ... 3 interrupt status clear register */
#define BSP_MPS_CVC0SR ((volatile u32*)(BSP_MPS + 0x0030))
#define BSP_MPS_CVC1SR ((volatile u32*)(BSP_MPS + 0x0034))
#define BSP_MPS_CVC2SR ((volatile u32*)(BSP_MPS + 0x0038))
#define BSP_MPS_CVC3SR ((volatile u32*)(BSP_MPS + 0x003C))
/* common status 0 and 1 read register */
#define BSP_MPS_RAD0SR ((volatile u32*)(BSP_MPS + 0x0040))
#define BSP_MPS_RAD1SR ((volatile u32*)(BSP_MPS + 0x0044))
/* common status 0 and 1 set register */
#define BSP_MPS_SAD0SR ((volatile u32*)(BSP_MPS + 0x0048))
#define BSP_MPS_SAD1SR ((volatile u32*)(BSP_MPS + 0x004C))
/* common status 0 and 1 clear register */
#define BSP_MPS_CAD0SR ((volatile u32*)(BSP_MPS + 0x0050))
#define BSP_MPS_CAD1SR ((volatile u32*)(BSP_MPS + 0x0054))
/* common status 0 and 1 enable register */
#define BSP_MPS_AD0ENR ((volatile u32*)(BSP_MPS + 0x0058))
#define BSP_MPS_AD1ENR ((volatile u32*)(BSP_MPS + 0x005C))
/* notification enable register */
#define BSP_MPS_CPU0_NFER ((volatile u32*)(BSP_MPS + 0x0060))
#define BSP_MPS_CPU1_NFER ((volatile u32*)(BSP_MPS + 0x0064))
/* CPU to CPU interrup request register */
#define BSP_MPS_CPU0_2_CPU1_IRR ((volatile u32*)(BSP_MPS + 0x0070))
#define BSP_MPS_CPU0_2_CPU1_IER ((volatile u32*)(BSP_MPS + 0x0074))
/* Global interrupt request and request enable register */
#define BSP_MPS_GIRR ((volatile u32*)(BSP_MPS + 0x0078))
#define BSP_MPS_GIER ((volatile u32*)(BSP_MPS + 0x007C))


#define BSP_MPS_CPU0_SMP0 ((volatile u32*)(BSP_MPS + 0x00100))

#define BSP_MPS_CPU1_SMP0 ((volatile u32*)(BSP_MPS + 0x00200))
 
 
/************************************************************************/
/*   Module       :   PPE register address and bits        		*/
/************************************************************************/
#if AR9
#define BSP_PPE32_BASE  0xBE180000
#else
#define BSP_PPE32_BASE  0xBE200000
#endif

#define BSP_PPE32_DEBUG_BREAK_TRACE_REG   (BSP_PPE32_BASE + (0x0000 * 4))
#define BSP_PPE32_INT_MASK_STATUS_REG     (BSP_PPE32_BASE + (0x0030 * 4))
#define BSP_PPE32_INT_RESOURCE_REG        (BSP_PPE32_BASE + (0x0040 * 4))
#define BSP_PPE32_CDM_CODE_MEM_B0         (BSP_PPE32_BASE + (0x1000 * 4))
#define BSP_PPE32_CDM_CODE_MEM_B1         (BSP_PPE32_BASE + (0x11000 * 4))
#define BSP_PPE32_DATA_MEM_MAP_REG_BASE   (BSP_PPE32_BASE + (0xD000 * 4))

/* Shared Buffer register */

#define BSP_PPE32_SB_MST_SEL           ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0304 * 4)))


#define BSP_PPE_BASE_ADDR                (BSP_PPE32_BASE)
#define BSP_PPE_PP32_DEBUG_REG_ADDR(x)          ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x0900) << 2)))
#define BSP_PPE_PPM_INT_REG_ADDR(x)             ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x0030) << 2)))
#define BSP_PPE_PP32_INTERNAL_RES_ADDR(x)       ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x0040) << 2)))
#define BSP_PPE_PPE_CLOCK_CONTROL_ADDR(x)       ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x0100) << 2)))
#define BSP_PPE_CDM_CODE_MEMORY_RAM0_ADDR(x)    ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x1000) << 2)))
#define BSP_PPE_CDM_CODE_MEMORY_RAM1_ADDR(x)    ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x2000) << 2)))
#define BSP_PPE_REG_ADDR(x)                     ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0xD000) << 2)))
#define BSP_PPE_PP32_DATA_MEMORY_RAM1_ADDR(x)   ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x5000) << 2)))
#define BSP_PPE_PPM_INT_UNIT_ADDR(x)            ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x6000) << 2)))
#define BSP_PPE_PPM_TIMER0_ADDR(x)              ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x6100) << 2)))
#define BSP_PPE_PPM_TASK_IND_REG_ADDR(x)        ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x6200) << 2)))
#define BSP_PPE_PPS_BRK_ADDR(x)                 ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x6300) << 2)))
#define BSP_PPE_PPM_TIMER1_ADDR(x)              ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x6400) << 2)))
#define BSP_PPE_SB_RAM0_ADDR(x)                 ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x8000) << 2)))
#define BSP_PPE_SB_RAM1_ADDR(x)                 ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0x9000) << 2)))
#define BSP_PPE_SB_RAM2_ADDR(x)                 ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0xA000) << 2)))
#define BSP_PPE_SB_RAM3_ADDR(x)                 ((volatile u32*)(BSP_PPE_BASE_ADDR + (((x) + 0xB000) << 2)))

#define BSP_PPE_PP32_SLEEP                      BSP_PPE_REG_ADDR(0x0010) /* PP32 Power Saving Register */
#define BSP_PPE_CDM_CFG                         BSP_PPE_REG_ADDR(0x0100) /* Code/Data Memory (CDM) Register */

/* Mailbox Registers */
#define BSP_PPE_MBOX_IGU0_ISRS                  BSP_PPE_REG_ADDR(0x0200)
#define BSP_PPE_MBOX_IGU0_ISRC                  BSP_PPE_REG_ADDR(0x0201)
#define BSP_PPE_MBOX_IGU0_ISR                   BSP_PPE_REG_ADDR(0x0202)
#define BSP_PPE_MBOX_IGU0_IER                   BSP_PPE_REG_ADDR(0x0203)
#define BSP_PPE_MBOX_IGU1_ISRS0                 BSP_PPE_REG_ADDR(0x0204)
#define BSP_PPE_MBOX_IGU1_ISRC0                 BSP_PPE_REG_ADDR(0x0205)
#define BSP_PPE_MBOX_IGU1_ISR0                  BSP_PPE_REG_ADDR(0x0206)
#define BSP_PPE_MBOX_IGU1_IER0                  BSP_PPE_REG_ADDR(0x0207)
#define BSP_PPE_MBOX_IGU1_ISRS1                 BSP_PPE_REG_ADDR(0x0208)
#define BSP_PPE_MBOX_IGU1_ISRC1                 BSP_PPE_REG_ADDR(0x0209)
#define BSP_PPE_MBOX_IGU1_ISR1                  BSP_PPE_REG_ADDR(0x020A)
#define BSP_PPE_MBOX_IGU1_IER1                  BSP_PPE_REG_ADDR(0x020B)
#define BSP_PPE_MBOX_IGU1_ISRS2                 BSP_PPE_REG_ADDR(0x020C)
#define BSP_PPE_MBOX_IGU1_ISRC2                 BSP_PPE_REG_ADDR(0x020D)
#define BSP_PPE_MBOX_IGU1_ISR2                  BSP_PPE_REG_ADDR(0x020E)
#define BSP_PPE_MBOX_IGU1_IER2                  BSP_PPE_REG_ADDR(0x020F)
#define BSP_PPE_MBOX_IGU2_ISRS                  BSP_PPE_REG_ADDR(0x0210)
#define BSP_PPE_MBOX_IGU2_ISRC                  BSP_PPE_REG_ADDR(0x0211)
#define BSP_PPE_MBOX_IGU2_ISR                   BSP_PPE_REG_ADDR(0x0212)
#define BSP_PPE_MBOX_IGU2_IER                   BSP_PPE_REG_ADDR(0x0213)
#define BSP_PPE_MBOX_IGU3_ISRS                  BSP_PPE_REG_ADDR(0x0214)
#define BSP_PPE_MBOX_IGU3_ISRC                  BSP_PPE_REG_ADDR(0x0215)
#define BSP_PPE_MBOX_IGU3_ISR                   BSP_PPE_REG_ADDR(0x0216)
#define BSP_PPE_MBOX_IGU3_IER                   BSP_PPE_REG_ADDR(0x0217)
#define BSP_PPE_MBOX_IGU4_ISRS                  BSP_PPE_REG_ADDR(0x0218)
#define BSP_PPE_MBOX_IGU4_ISRC                  BSP_PPE_REG_ADDR(0x0219)
#define BSP_PPE_MBOX_IGU4_ISR                   BSP_PPE_REG_ADDR(0x021A)
#define BSP_PPE_MBOX_IGU4_IER                   BSP_PPE_REG_ADDR(0x021B)
/*
 *    Shared Buffer (SB) Registers
 */
#define BSP_PPE_SB_MST_PRI0                     BSP_PPE_REG_ADDR(0x0300)
#define BSP_PPE_SB_MST_PRI1                     BSP_PPE_REG_ADDR(0x0301)
#define BSP_PPE_SB_MST_PRI2                     BSP_PPE_REG_ADDR(0x0302)
#define BSP_PPE_SB_MST_PRI3                     BSP_PPE_REG_ADDR(0x0303)
#define BSP_PPE_SB_MST_PRI4                     BSP_PPE_REG_ADDR(0x0304)
#define BSP_PPE_SB_MST_SEL                      BSP_PPE_REG_ADDR(0x0305)
/*
 *    RTHA Registers
 */
#define BSP_PPE_RFBI_CFG                        BSP_PPE_REG_ADDR(0x0400)
#define BSP_PPE_RBA_CFG0                        BSP_PPE_REG_ADDR(0x0404)
#define BSP_PPE_RBA_CFG1                        BSP_PPE_REG_ADDR(0x0405)
#define BSP_PPE_RCA_CFG0                        BSP_PPE_REG_ADDR(0x0408)
#define BSP_PPE_RCA_CFG1                        BSP_PPE_REG_ADDR(0x0409)
#define BSP_PPE_RDES_CFG0                       BSP_PPE_REG_ADDR(0x040C)
#define BSP_PPE_RDES_CFG1                       BSP_PPE_REG_ADDR(0x040D)
#define BSP_PPE_SFSM_STATE0                     BSP_PPE_REG_ADDR(0x0410)
#define BSP_PPE_SFSM_STATE1                     BSP_PPE_REG_ADDR(0x0411)
#define BSP_PPE_SFSM_DBA0                       BSP_PPE_REG_ADDR(0x0412)
#define BSP_PPE_SFSM_DBA1                       BSP_PPE_REG_ADDR(0x0413)
#define BSP_PPE_SFSM_CBA0                       BSP_PPE_REG_ADDR(0x0414)
#define BSP_PPE_SFSM_CBA1                       BSP_PPE_REG_ADDR(0x0415)
#define BSP_PPE_SFSM_CFG0                       BSP_PPE_REG_ADDR(0x0416)
#define BSP_PPE_SFSM_CFG1                       BSP_PPE_REG_ADDR(0x0417)
#define BSP_PPE_SFSM_PGCNT0                     BSP_PPE_REG_ADDR(0x041C)
#define BSP_PPE_SFSM_PGCNT1                     BSP_PPE_REG_ADDR(0x041D)
/*
 *    TTHA Registers
 */
#define BSP_PPE_FFSM_DBA0                       BSP_PPE_REG_ADDR(0x0508)
#define BSP_PPE_FFSM_DBA1                       BSP_PPE_REG_ADDR(0x0509)
#define BSP_PPE_FFSM_CFG0                       BSP_PPE_REG_ADDR(0x050A)
#define BSP_PPE_FFSM_CFG1                       BSP_PPE_REG_ADDR(0x050B)
#define BSP_PPE_FFSM_IDLE_HEAD_BC0              BSP_PPE_REG_ADDR(0x050E)
#define BSP_PPE_FFSM_IDLE_HEAD_BC1              BSP_PPE_REG_ADDR(0x050F)
#define BSP_PPE_FFSM_PGCNT0                     BSP_PPE_REG_ADDR(0x0514)
#define BSP_PPE_FFSM_PGCNT1                     BSP_PPE_REG_ADDR(0x0515)
/*
 *    ETOP MDIO Registers
 */
#define BSP_PPE32_ETOP_MDIO_CFG           ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0600 * 4)))
#define BSP_PPE32_ETOP_MDIO_ACC           ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0601 * 4)))
#define BSP_PPE32_ETOP_CFG                ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0602 * 4)))
#define BSP_PPE32_ETOP_IG_VLAN_COS        ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0603 * 4)))
#define BSP_PPE32_ETOP_IG_DSCP_COS3       ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0604 * 4)))
#define BSP_PPE32_ETOP_IG_DSCP_COS2       ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0605 * 4)))
#define BSP_PPE32_ETOP_IG_DSCP_COS1       ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0606 * 4)))
#define BSP_PPE32_ETOP_IG_DSCP_COS0       ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0607 * 4)))
#define BSP_PPE32_ETOP_IG_PLEN_CTRL       ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0608 * 4)))
#define BSP_PPE32_ETOP_ISR                ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x060A * 4)))
#define BSP_PPE32_ETOP_IER                ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x060B * 4)))
#define BSP_PPE32_ETOP_VPID               ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x060C * 4)))

/* ENET0 Register */
#define BSP_PPE32_ENET0S_MAC_CFG		((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0610 * 4)))
#define BSP_PPE32_ENET0S_DBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0612 * 4)))
#define BSP_PPE32_ENET0S_CBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0613 * 4)))
#define BSP_PPE32_ENET0S_CFG            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0614 * 4)))
#define BSP_PPE32_ENET0S_CoS_CFG          	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0618 * 4)))
#define BSP_PPE32_ENET0S_IG_PKTDROP          ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0619 * 4)))
#define BSP_PPE32_ENET0S_IG_PKTERR           ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x061A * 4)))

#define BSP_PPE32_ENET0F_DBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0630 * 4)))
#define BSP_PPE32_ENET0F_CBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0631 * 4)))
#define BSP_PPE32_ENET0F_CFG            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0632 * 4)))
#define BSP_PPE32_ENET0F_EG_PKTCOL           ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x063C * 4)))
#define BSP_PPE32_ENET0F_EG_PKTDROP          ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x063D * 4)))


/* ENET1 Register */
#define BSP_PPE32_ENET1S_MAC_CFG            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0650 * 4)))
#define BSP_PPE32_ENET1S_DBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0652 * 4)))
#define BSP_PPE32_ENET1S_CBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0653 * 4)))
#define BSP_PPE32_ENET1S_CFG            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0654 * 4)))
#define BSP_PPE32_ENET1S_CoS_CFG          	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0658 * 4)))
#define BSP_PPE32_ENET1S_IG_PKTDROP          ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0659 * 4)))
#define BSP_PPE32_ENET1S_IG_PKTERR           ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x065A * 4)))

#define BSP_PPE32_ENET1F_DBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0670 * 4)))
#define BSP_PPE32_ENET1F_CBA            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0671 * 4)))
#define BSP_PPE32_ENET1F_CFG            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0672 * 4)))
#define BSP_PPE32_ENET1F_EG_PKTCOL           ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x067C * 4)))
#define BSP_PPE32_ENET1F_EG_PKTDROP          ((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x067D * 4)))


/* DPLUS Register */
#define BSP_PPE32_DPLUS_TXDB            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0700 * 4)))
#define BSP_PPE32_DPLUS_TXCB            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0701 * 4)))
#define BSP_PPE32_DPLUS_TXCFG            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0702 * 4)))
#define BSP_PPE32_DPLUS_TXPGCNT            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0703 * 4)))
#define BSP_PPE32_DPLUS_RXDB            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0710 * 4)))
#define BSP_PPE32_DPLUS_RXCB            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0711 * 4)))
#define BSP_PPE32_DPLUS_RXCFG            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0712 * 4)))
#define BSP_PPE32_DPLUS_RXPGCNT            	((volatile u32 *)(BSP_PPE32_DATA_MEM_MAP_REG_BASE + (0x0713 * 4)))

/* Sharebuff SB RAM2 control data */

#define BSP_PPE32_SB_DATABASE  	((BSP_PPE32_BASE + (0x9100 * 4)))
#define BSP_PPE32_SB_CTRLBASE  	((BSP_PPE32_BASE + (0x9b00 * 4)))

#define BSP_PPE32_SB2_DATABASE  	((BSP_PPE32_BASE + (0x8C00 * 4)))
#define BSP_PPE32_SB2_CTRLBASE  	((BSP_PPE32_BASE + (0x92E0 * 4)))
#define BSP_PPE_ETOP_MDIO_CFG                   BSP_PPE_REG_ADDR(0x0600)
#define BSP_PPE_ETOP_MDIO_ACC                   BSP_PPE_REG_ADDR(0x0601)
#define BSP_PPE_ETOP_CFG                        BSP_PPE_REG_ADDR(0x0602)
#define BSP_PPE_ETOP_IG_VLAN_COS                BSP_PPE_REG_ADDR(0x0603)
#define BSP_PPE_ETOP_IG_DSCP_COS3               BSP_PPE_REG_ADDR(0x0604)
#define BSP_PPE_ETOP_IG_DSCP_COS2               BSP_PPE_REG_ADDR(0x0605)
#define BSP_PPE_ETOP_IG_DSCP_COS1               BSP_PPE_REG_ADDR(0x0606)
#define BSP_PPE_ETOP_IG_DSCP_COS0               BSP_PPE_REG_ADDR(0x0607)
#define BSP_PPE_ETOP_IG_PLEN_CTRL0              BSP_PPE_REG_ADDR(0x0608)
#define BSP_PPE_ETOP_IG_PLEN_CTRL1              BSP_PPE_REG_ADDR(0x0609)
#define BSP_PPE_ETOP_ISR                        BSP_PPE_REG_ADDR(0x060A)
#define BSP_PPE_ETOP_IER                        BSP_PPE_REG_ADDR(0x060B)
#define BSP_PPE_ETOP_VPID                       BSP_PPE_REG_ADDR(0x060C)
#define BSP_PPE_ENET_MAC_CFG                    BSP_PPE_REG_ADDR(0x0610)
//#######################################################################################
#define BSP_PPE_DMRX_DBA                        BSP_PPE_REG_ADDR(0x0612)
#define BSP_PPE_DMRX_CBA                        BSP_PPE_REG_ADDR(0x0613)
#define BSP_PPE_DMRX_CFG                        BSP_PPE_REG_ADDR(0x0614)
#define BSP_PPE_DMRX_PGCNT                     BSP_PPE_REG_ADDR(0x0615)
#define BSP_PPE_DMRX_PGCNT_DSRC_PP32	   (0x00020000)
#define BSP_PPE_DMRX_PGCNT_DVAL_SHIFT	   (9)
#define BSP_PPE_DMRX_PGCNT_DCMD	           (0x00000100) 
#define BSP_PPE_DMRX_PKTCNT                    BSP_PPE_REG_ADDR(0x0616)
#define BSP_PPE_DMRX_PKTCNT_DSRC_PP32	   (0x00000200)
#define BSP_PPE_DMRX_PKTCNT_DCMD	           (0x00000100) 
#define BSP_PPE_DMRX_PKTCNT_UPKT	           (0x000000FF) 
//########################################################################################
#define BSP_PPE_ENETS_BUF_CTRL                  BSP_PPE_REG_ADDR(0x0617)
#define BSP_PPE_ENETS_COS_CFG                   BSP_PPE_REG_ADDR(0x0618)
#define BSP_PPE_ENETS_IGDROP                    BSP_PPE_REG_ADDR(0x0619)
#define BSP_PPE_ENETF_DBA                       BSP_PPE_REG_ADDR(0x0630)
#define BSP_PPE_ENETF_CBA                       BSP_PPE_REG_ADDR(0x0631)
#define BSP_PPE_ENETF_CFG                       BSP_PPE_REG_ADDR(0x0632)
#define BSP_PPE_ENETF_PGCNT                     BSP_PPE_REG_ADDR(0x0633)
#define BSP_PPE_ENETF_PGCNT_ISRC_PP32	   (0x00020000)
#define BSP_PPE_ENETF_PGCNT_IVAL_SHIFT	   (9)
#define BSP_PPE_ENETF_PGCNT_ICMD	           (0x00000100) 
#define BSP_PPE_ENETF_PKTCNT                    BSP_PPE_REG_ADDR(0x0634)
#define BSP_PPE_ENETF_PKTCNT_ISRC_PP32	   (0x00000200)
#define BSP_PPE_ENETF_PKTCNT_ICMD	           (0x00000100) 
#define BSP_PPE_ENETF_PKTCNT_VPKT	           (0x000000FF) 
#define BSP_PPE_ENETF_HFCTRL                    BSP_PPE_REG_ADDR(0x0635)
#define BSP_PPE_ENETF_TXCTRL                    BSP_PPE_REG_ADDR(0x0636)
#define BSP_PPE_ENETF_VLCOS0                    BSP_PPE_REG_ADDR(0x0638)
#define BSP_PPE_ENETF_VLCOS1                    BSP_PPE_REG_ADDR(0x0639)
#define BSP_PPE_ENETF_VLCOS2                    BSP_PPE_REG_ADDR(0x063A)
#define BSP_PPE_ENETF_VLCOS3                    BSP_PPE_REG_ADDR(0x063B)
#define BSP_PPE_ENETF_EGERR                     BSP_PPE_REG_ADDR(0x063C)
#define BSP_PPE_ENETF_EGDROP                    BSP_PPE_REG_ADDR(0x063D)
/*
 *    DPLUS Registers
 */
#define BSP_PPE_DPLUS_TXDB                      BSP_PPE_REG_ADDR(0x0700)
#define BSP_PPE_DPLUS_TXCB                      BSP_PPE_REG_ADDR(0x0701)
#define BSP_PPE_DPLUS_TXCFG                     BSP_PPE_REG_ADDR(0x0702)
#define BSP_PPE_DPLUS_TXPGCNT                   BSP_PPE_REG_ADDR(0x0703)
//####################################################################################
#define BSP_PPE_DSRX_DBA                        BSP_PPE_REG_ADDR(0x0710)
#define BSP_PPE_DSRX_CBA                        BSP_PPE_REG_ADDR(0x0711)
#define BSP_PPE_DSRX_CFG                        BSP_PPE_REG_ADDR(0x0712)
#define BSP_PPE_DSRX_PGCNT                      BSP_PPE_REG_ADDR(0x0713)
/*
 *    BMC Registers
 */
#define BSP_PPE_BMC_CMD3                        BSP_PPE_REG_ADDR(0x0800)
#define BSP_PPE_BMC_CMD2                        BSP_PPE_REG_ADDR(0x0801)
#define BSP_PPE_BMC_CMD1                        BSP_PPE_REG_ADDR(0x0802)
#define BSP_PPE_BMC_CMD0                        BSP_PPE_REG_ADDR(0x0803)
#define BSP_PPE_BMC_CFG0                        BSP_PPE_REG_ADDR(0x0804)
#define BSP_PPE_BMC_CFG1                        BSP_PPE_REG_ADDR(0x0805)
#define BSP_PPE_BMC_POLY0                       BSP_PPE_REG_ADDR(0x0806)
#define BSP_PPE_BMC_POLY1                       BSP_PPE_REG_ADDR(0x0807)
#define BSP_PPE_BMC_CRC0                        BSP_PPE_REG_ADDR(0x0808)
#define BSP_PPE_BMC_CRC1                        BSP_PPE_REG_ADDR(0x0809)
/*
 *    SLL Registers
 */
#define BSP_PPE_SLL_CMD1                        BSP_PPE_REG_ADDR(0x0900)
#define BSP_PPE_SLL_CMD0                        BSP_PPE_REG_ADDR(0x0901)
#define BSP_PPE_SLL_KEY0                        BSP_PPE_REG_ADDR(0x0910)
#define BSP_PPE_SLL_KEY1                        BSP_PPE_REG_ADDR(0x0911)
#define BSP_PPE_SLL_KEY2                        BSP_PPE_REG_ADDR(0x0912)
#define BSP_PPE_SLL_KEY3                        BSP_PPE_REG_ADDR(0x0913)
#define BSP_PPE_SLL_KEY4                        BSP_PPE_REG_ADDR(0x0914)
#define BSP_PPE_SLL_KEY5                        BSP_PPE_REG_ADDR(0x0915)
#define BSP_PPE_SLL_RESULT                      BSP_PPE_REG_ADDR(0x0920)
/*
 *    EMA Registers
 */
#define BSP_PPE_EMA_CMD2                        BSP_PPE_REG_ADDR(0x0A00)
#define BSP_PPE_EMA_CMD1                        BSP_PPE_REG_ADDR(0x0A01)
#define BSP_PPE_EMA_CMD0                        BSP_PPE_REG_ADDR(0x0A02)
#define BSP_PPE_EMA_CMDCFG                      BSP_PPE_REG_ADDR(0x0A00)#
#define BSP_PPE_EMA_DATACFG                     BSP_PPE_REG_ADDR(0x0A01)
#define BSP_PPE_EMA_CMDCNT                      BSP_PPE_REG_ADDR(0x0A02)
#define BSP_PPE_EMA_DATACNT                     BSP_PPE_REG_ADDR(0x0A03)
#define BSP_PPE_EMA_ISR                         BSP_PPE_REG_ADDR(0x0A04)
#define BSP_PPE_EMA_IER                         BSP_PPE_REG_ADDR(0x0A05)
#define BSP_PPE_EMA_CFG                         BSP_PPE_REG_ADDR(0x0A06)
/*
 *    UTPS Registers
 */
#define BSP_PPE_UTP_TXCA0                       BSP_PPE_REG_ADDR(0x0B00)
#define BSP_PPE_UTP_TXNA0                       BSP_PPE_REG_ADDR(0x0B01)
#define BSP_PPE_UTP_TXCA1                       BSP_PPE_REG_ADDR(0x0B02)
#define BSP_PPE_UTP_TXNA1                       BSP_PPE_REG_ADDR(0x0B03)
#define BSP_PPE_UTP_RXCA0                       BSP_PPE_REG_ADDR(0x0B10)
#define BSP_PPE_UTP_RXNA0                       BSP_PPE_REG_ADDR(0x0B11)
#define BSP_PPE_UTP_RXCA1                       BSP_PPE_REG_ADDR(0x0B12)
#define BSP_PPE_UTP_RXNA1                       BSP_PPE_REG_ADDR(0x0B13)
#define BSP_PPE_UTP_CFG                         BSP_PPE_REG_ADDR(0x0B20)
#define BSP_PPE_UTP_ISR                         BSP_PPE_REG_ADDR(0x0B30)
#define BSP_PPE_UTP_IER                         BSP_PPE_REG_ADDR(0x0B31)
/*
 *    QSB Registers
 */
#define BSP_PPE_QSB_RELOG                       BSP_PPE_REG_ADDR(0x0C00)
#define BSP_PPE_QSB_EMIT0                       BSP_PPE_REG_ADDR(0x0C01)
#define BSP_PPE_QSB_EMIT1                       BSP_PPE_REG_ADDR(0x0C02)
#define BSP_PPE_QSB_ICDV                        BSP_PPE_REG_ADDR(0x0C07)
#define BSP_PPE_QSB_SBL                         BSP_PPE_REG_ADDR(0x0C09)
#define BSP_PPE_QSB_CFG                         BSP_PPE_REG_ADDR(0x0C0A)
#define BSP_PPE_QSB_RTM                         BSP_PPE_REG_ADDR(0x0C0B)
#define BSP_PPE_QSB_RTD                         BSP_PPE_REG_ADDR(0x0C0C)
#define BSP_PPE_QSB_RAMAC                       BSP_PPE_REG_ADDR(0x0C0D)
#define BSP_PPE_QSB_ISTAT                       BSP_PPE_REG_ADDR(0x0C0E)
#define BSP_PPE_QSB_IMR                         BSP_PPE_REG_ADDR(0x0C0F)
#define BSP_PPE_QSB_SRC                         BSP_PPE_REG_ADDR(0x0C10)
/*
 *    DSP User Registers
 */
#define BSP_PPE_DREG_A_VERSION                  BSP_PPE_REG_ADDR(0x0D00)
#define BSP_PPE_DREG_A_CFG                      BSP_PPE_REG_ADDR(0x0D01)
#define BSP_PPE_DREG_AT_CTRL                    BSP_PPE_REG_ADDR(0x0D02)
#define BSP_PPE_DREG_AR_CTRL                    BSP_PPE_REG_ADDR(0x0D08)
#define BSP_PPE_DREG_A_UTPCFG                   BSP_PPE_REG_ADDR(0x0D0E)
#define BSP_PPE_DREG_A_STATUS                   BSP_PPE_REG_ADDR(0x0D0F)
#define BSP_PPE_DREG_AT_CFG0                    BSP_PPE_REG_ADDR(0x0D20)
#define BSP_PPE_DREG_AT_CFG1                    BSP_PPE_REG_ADDR(0x0D21)
#define BSP_PPE_DREG_FB_SIZE0                   BSP_PPE_REG_ADDR(0x0D22)
#define BSP_PPE_DREG_FB_SIZE1                   BSP_PPE_REG_ADDR(0x0D23)
#define BSP_PPE_DREG_AT_CELL0                   BSP_PPE_REG_ADDR(0x0D24)
#define BSP_PPE_DREG_AT_CELL1                   BSP_PPE_REG_ADDR(0x0D25)
#define BSP_PPE_DREG_AT_IDLE_CNT0               BSP_PPE_REG_ADDR(0x0D26)
#define BSP_PPE_DREG_AT_IDLE_CNT1               BSP_PPE_REG_ADDR(0x0D27)
#define BSP_PPE_DREG_AT_IDLE0                   BSP_PPE_REG_ADDR(0x0D28)
#define BSP_PPE_DREG_AT_IDLE1                   BSP_PPE_REG_ADDR(0x0D29)
#define BSP_PPE_DREG_AR_CFG0                    BSP_PPE_REG_ADDR(0x0D60)
#define BSP_PPE_DREG_AR_CFG1                    BSP_PPE_REG_ADDR(0x0D61)
#define BSP_PPE_DREG_AR_FB_START0               BSP_PPE_REG_ADDR(0x0D62)
#define BSP_PPE_DREG_AR_FB_START1               BSP_PPE_REG_ADDR(0x0D63)
#define BSP_PPE_DREG_AR_FB_END0                 BSP_PPE_REG_ADDR(0x0D64)
#define BSP_PPE_DREG_AR_FB_END1                 BSP_PPE_REG_ADDR(0x0D65)
#define BSP_PPE_DREG_AR_ATM_STAT0               BSP_PPE_REG_ADDR(0x0D66)
#define BSP_PPE_DREG_AR_ATM_STAT1               BSP_PPE_REG_ADDR(0x0D67)
#define BSP_PPE_DREG_AR_CELL0                   BSP_PPE_REG_ADDR(0x0D68)
#define BSP_PPE_DREG_AR_CELL1                   BSP_PPE_REG_ADDR(0x0D69)
#define BSP_PPE_DREG_AR_IDLE_CNT0               BSP_PPE_REG_ADDR(0x0D6A)
#define BSP_PPE_DREG_AR_IDLE_CNT1               BSP_PPE_REG_ADDR(0x0D6B)
#define BSP_PPE_DREG_AR_AIIDLE_CNT0             BSP_PPE_REG_ADDR(0x0D6C)
#define BSP_PPE_DREG_AR_AIIDLE_CNT1             BSP_PPE_REG_ADDR(0x0D6D)
#define BSP_PPE_DREG_AR_BE_CNT0                 BSP_PPE_REG_ADDR(0x0D6E)
#define BSP_PPE_DREG_AR_BE_CNT1                 BSP_PPE_REG_ADDR(0x0D6F)
#define BSP_PPE_DREG_AR_HEC_CNT0                BSP_PPE_REG_ADDR(0x0D70)
#define BSP_PPE_DREG_AR_HEC_CNT1                BSP_PPE_REG_ADDR(0x0D71)
#define BSP_PPE_DREG_AR_CD_CNT0                 BSP_PPE_REG_ADDR(0x0D72)
#define BSP_PPE_DREG_AR_CD_CNT1                 BSP_PPE_REG_ADDR(0x0D73)
#define BSP_PPE_DREG_AR_IDLE0                   BSP_PPE_REG_ADDR(0x0D74)
#define BSP_PPE_DREG_AR_IDLE1                   BSP_PPE_REG_ADDR(0x0D75)
#define BSP_PPE_DREG_AR_DELIN0                  BSP_PPE_REG_ADDR(0x0D76)
#define BSP_PPE_DREG_AR_DELIN1                  BSP_PPE_REG_ADDR(0x0D77)
#define BSP_PPE_DREG_RESV0                      BSP_PPE_REG_ADDR(0x0D78)
#define BSP_PPE_DREG_RESV1                      BSP_PPE_REG_ADDR(0x0D79)
#define BSP_PPE_DREG_RX_MIB_CMD0                BSP_PPE_REG_ADDR(0x0D80)
#define BSP_PPE_DREG_RX_MIB_CMD1                BSP_PPE_REG_ADDR(0x0D81)
#define BSP_PPE_DREG_AR_OVDROP_CNT0             BSP_PPE_REG_ADDR(0x0D98)
#define BSP_PPE_DREG_AR_OVDROP_CNT1             BSP_PPE_REG_ADDR(0x0D99)


/***********************************************************************/
/*  SDIO Register                                                      */
/***********************************************************************/

//SDIO base address
#define SDIO_OFFSET  0xBE102000

// Configuration and Status Register in Bus clock domain for SDIO-TOPSPIN/IRN/DMA_IF Block
#define SDIO_CLC	(SDIO_OFFSET + 0x1000)
#define SDIO_ID  	(SDIO_OFFSET + 0x1004)
#define SDIO_CTRL	(SDIO_OFFSET + 0x1008)

// Configuration and Status Register in Kernel clock domain for SDIO-PL180
#define SDIO_MCIPOWER        (SDIO_OFFSET+0x0000)
#define SDIO_MCICLOCK        (SDIO_OFFSET+0x0004)
#define SDIO_MCIARGUMENT     (SDIO_OFFSET+0x0008)
#define SDIO_MMCCOMMAND      (SDIO_OFFSET+0x000C)
#define SDIO_MCIRESPCMD      (SDIO_OFFSET+0x0010)
#define SDIO_MCIRESPONSE0    (SDIO_OFFSET+0x0014) 
#define SDIO_MCIRESPONSE1    (SDIO_OFFSET+0x0018)
#define SDIO_MCIRESPONSE2    (SDIO_OFFSET+0x001C)
#define SDIO_MCIRESPONSE3    (SDIO_OFFSET+0x0020)
#define SDIO_MCIDATATIMER    (SDIO_OFFSET+0x0024)
#define SDIO_MCIDATALENGTH   (SDIO_OFFSET+0x0028) 
#define SDIO_MCIDATACTRL     (SDIO_OFFSET+0x002C)
#define SDIO_MCIDATACNT      (SDIO_OFFSET+0x0030)
#define SDIO_MCISTATUS       (SDIO_OFFSET+0x0034)
#define SDIO_MCICLEAR        (SDIO_OFFSET+0x0038)
#define SDIO_MCIMASK0        (SDIO_OFFSET+0x003C)
#define SDIO_MCIMASK1        (SDIO_OFFSET+0x0040)
#define SDIO_MCISELECT       (SDIO_OFFSET+0x0044) 
#define SDIO_MCIFIFOCNT      (SDIO_OFFSET+0x0048)

#define SDIO_MCIFIFO_0       (SDIO_OFFSET+0x0080)
#define SDIO_MCIFIFO_1       (SDIO_OFFSET+0x0084)
#define SDIO_MCIFIFO_2       (SDIO_OFFSET+0x0088)
#define SDIO_MCIFIFO_3       (SDIO_OFFSET+0x008C)
#define SDIO_MCIFIFO_4       (SDIO_OFFSET+0x0090)
#define SDIO_MCIFIFO_5       (SDIO_OFFSET+0x0094)
#define SDIO_MCIFIFO_6       (SDIO_OFFSET+0x0098)
#define SDIO_MCIFIFO_7       (SDIO_OFFSET+0x009C)
#define SDIO_MCIFIFO_8       (SDIO_OFFSET+0x00A0)
#define SDIO_MCIFIFO_9       (SDIO_OFFSET+0x00A4)
#define SDIO_MCIFIFO_10      (SDIO_OFFSET+0x00A8)
#define SDIO_MCIFIFO_11      (SDIO_OFFSET+0x00AC)
#define SDIO_MCIFIFO_12      (SDIO_OFFSET+0x00B0)
#define SDIO_MCIFIFO_13      (SDIO_OFFSET+0x00B4)
#define SDIO_MCIFIFO_14      (SDIO_OFFSET+0x00B8)
#define SDIO_MCIFIFO_15      (SDIO_OFFSET+0x00BC)

#define SDIO_MCITCR          (SDIO_OFFSET+0x0100)
#define SDIO_MCIITIP         (SDIO_OFFSET+0x0104)
#define SDIO_MCIITOP         (SDIO_OFFSET+0x0108)

#define SDIO_MCIPERIPHID0    (SDIO_OFFSET+0x0FE0) 
#define SDIO_MCIPERIPHID1    (SDIO_OFFSET+0x0FE4)
#define SDIO_MCIPERIPHID2    (SDIO_OFFSET+0x0FE8)
#define SDIO_MCIPERIPHID3    (SDIO_OFFSET+0x0FEC)
#define SDIO_MCIPCELLID0     (SDIO_OFFSET+0x0FF0)
#define SDIO_MCIPCELLID1     (SDIO_OFFSET+0x0FF4)
#define SDIO_MCIPCELLID2     (SDIO_OFFSET+0x0FF8)
#define SDIO_MCIPCELLID3     (SDIO_OFFSET+0x0FFC)

// Interrupt Register in Bus Clock Domain for SDIO
#define SDIO_IMSC	(SDIO_OFFSET + 0x1010)
#define SDIO_RIS	(SDIO_OFFSET + 0x100C)
#define SDIO_MIS	(SDIO_OFFSET + 0x1014)
#define SDIO_ICR	(SDIO_OFFSET + 0x1018)
#define SDIO_ISR	(SDIO_OFFSET + 0x101C)

// DMA Register in Bus Clock Domain for SDIO 
#define SDIO_DMACON (SDIO_OFFSET + 0x1020)

//Address Hole in SDIO address space

#define SDIO_RSVD_ADDR0 (SDIO_OFFSET + 0x10F0)

// Configuration and Status Mask
#define SDIO_CLC_MASK             0x00000F3F	
#define SDIO_ID_MASK              0xFFFFC0FF	
#define SDIO_CTRL_MASK	          0x00000013
#define SDIO_MCIPOWER_MASK        0x000000FF
#define SDIO_MCICLOCK_MASK        0x00000FFF
#define SDIO_MCIARGUMENT_MASK     0xFFFFFFFF
#define SDIO_MMCCOMMAND_MASK      0x000007FF
#define SDIO_MCIRESPCMD_MASK      0x00000000
#define SDIO_MCIRESPONSE0_MASK    0x00000000
#define SDIO_MCIRESPONSE1_MASK    0x00000000
#define SDIO_MCIRESPONSE2_MASK    0x00000000
#define SDIO_MCIRESPONSE3_MASK    0x00000000
#define SDIO_MCIDATATIMER_MASK    0xFFFFFFFF
#define SDIO_MCIDATALENGTH_MASK   0x0000FFFF
#define SDIO_MCIDATACTRL_MASK     0x000000FF
#define SDIO_MCIDATACNT_MASK      0x00000000
#define SDIO_MCISTATUS_MASK       0x00000000
#define SDIO_MCICLEAR_MASK        0x000007FF
#define SDIO_MCIMASK0_MASK        0x003FFFFF
#define SDIO_MCIMASK1_MASK        0x003FFFFF
#define SDIO_MCISELECT_MASK       0x0000000F 
#define SDIO_MCIFIFOCNT_MASK      0x00000000 

#define SDIO_MCIFIFO_0_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_1_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_2_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_3_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_4_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_5_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_6_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_7_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_8_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_9_MASK       0xFFFFFFFF 
#define SDIO_MCIFIFO_10_MASK      0xFFFFFFFF 
#define SDIO_MCIFIFO_11_MASK      0xFFFFFFFF 
#define SDIO_MCIFIFO_12_MASK      0xFFFFFFFF 
#define SDIO_MCIFIFO_13_MASK      0xFFFFFFFF 
#define SDIO_MCIFIFO_14_MASK      0xFFFFFFFF 
#define SDIO_MCIFIFO_15_MASK      0xFFFFFFFF 
                       
#define SDIO_MCITCR_MASK          0x0000000F 
#define SDIO_MCIITIP_MASK         0x0000003F
#define SDIO_MCIITOP_MASK         0x00000FFF

#define SDIO_MCIPERIPHID0_MASK    0x00000000
#define SDIO_MCIPERIPHID1_MASK    0x00000000
#define SDIO_MCIPERIPHID2_MASK    0x00000000
#define SDIO_MCIPERIPHID3_MASK    0x00000000
#define SDIO_MCIPCELLID0_MASK     0x00000000
#define SDIO_MCIPCELLID1_MASK     0x00000000
#define SDIO_MCIPCELLID2_MASK     0x00000000
#define SDIO_MCIPCELLID3_MASK     0x00000000

// dma reg mask
#define SDIO_DMACON_MASK          0x0000000F
// interrupt reg mask
#define SDIO_IMSC_MASK	          0x00000007
#define SDIO_RIS_MASK	          0x00000007
#define SDIO_MIS_MASK	          0x00000007
#define SDIO_ICR_MASK	          0x00000007
#define SDIO_ISR_MASK	          0x00000007

/* Danube AFE Register */
#define BSP_AFE_CHIP_ID	0x0
#define BSP_AFE_PD		0x1
#define BSP_AFE_SOFT_RST	0x2
#define BSP_AFE_CLK_CTL	0x3
#define BSP_AFE_TX_CFG	0x4
#define BSP_AFE_AGC		0x5
#define BSP_AFE_HYB_CONF_0	0x6
#define BSP_AFE_HYB_CONF_1	0x7
#define BSP_AFE_HYB_CONF_2	0x8
#define BSP_AFE_HPF_EQ	0x9
#define BSP_AFE_RX_DFC	0xa
#define BSP_AFE_TX_DFC	0xb
#define BSP_AFE_STATUS	0xc
#define BSP_AFE_LOOPS	0x40
#define BSP_AFE_ADC_OPT0	0x46
#define BSP_AFE_ADC_OPT1	0x47
#define BSP_AFE_RXAA		0x50


/* Danube PCM Register */

#define BSP_PCM_CFG	 (volatile u32 *)(0xBF100014)
#define BSP_PCM_CTRLR (volatile u32 *)(0xBF100000)
#define BSP_PCM_CTRLX (volatile u32 *)(0xBF100004)
#define BSP_PCM_STATR (volatile u32 *)(0xBF100008)
#define BSP_PCM_STATX (volatile u32 *)(0xBF10000C)
#define BSP_PCM_FREQ	 (volatile u32 *)(0xBF100010)
#define BSP_PCM_EN	 (volatile u32 *)(0xBF100018)
#define BSP_PCM_TEST	 (volatile u32 *)(0xBF10001C)
#define BSP_PCM_MODE	 (volatile u32 *)(0xBF100020)
#define BSP_PCM_STAT	 (volatile u32 *)(0xBF100024)
#define BSP_PCM_CFG0	 (volatile u32 *)(0xBF100028)
#define BSP_PCM_CFG1	 (volatile u32 *)(0xBF10002C)
#define BSP_PCM_CFG2	 (volatile u32 *)(0xBF100030)
#define BSP_PCM_CFG3	 (volatile u32 *)(0xBF100034)
#define BSP_PCM_CFG4	 (volatile u32 *)(0xBF100038)
#define BSP_PCM_CFG5	 (volatile u32 *)(0xBF10003C)
#define BSP_PCM_CFG6	 (volatile u32 *)(0xBF100040)
#define BSP_PCM_CFG7	 (volatile u32 *)(0xBF100044)
#define BSP_PCM_CFG8	 (volatile u32 *)(0xBF100048)
#define BSP_PCM_CFG9	 (volatile u32 *)(0xBF10004C)
#define BSP_PCM_DATA0 (volatile u32 *)(0xBF100068)
#define BSP_PCM_DATA1 (volatile u32 *)(0xBF10006C)
#define BSP_PCM_DATA2 (volatile u32 *)(0xBF100070)
#define BSP_PCM_DATA3 (volatile u32 *)(0xBF100074)
#define BSP_PCM_DATA4 (volatile u32 *)(0xBF100078)
#define BSP_PCM_DATA5 (volatile u32 *)(0xBF10007C)
#define BSP_PCM_DATA6 (volatile u32 *)(0xBF100080)
#define BSP_PCM_DATA7 (volatile u32 *)(0xBF100084)
#define BSP_PCM_DATA8 (volatile u32 *)(0xBF100088)
#define BSP_PCM_DATA9 (volatile u32 *)(0xBF10008C)

/* BSP GPORT SWITCH Register */
#define BSP_SWITCH	  		(0xBE108000)

#define BSP_SWITCH_PS	  		(BSP_SWITCH + 0x000)
#define BSP_SWITCH_P0_CTL		(BSP_SWITCH + 0x004)
#define BSP_SWITCH_P1_CTL		(BSP_SWITCH + 0x008)
#define BSP_SWITCH_P2_CTL		(BSP_SWITCH + 0x00C)
#define BSP_SWITCH_P0_VLAN		(BSP_SWITCH + 0x010)
#define BSP_SWITCH_P1_VLAN		(BSP_SWITCH + 0x014)
#define BSP_SWITCH_P2_VLAN		(BSP_SWITCH + 0x018)
#define BSP_SWITCH_P0_INCTL		(BSP_SWITCH + 0x020)
#define BSP_SWITCH_P1_INCTL		(BSP_SWITCH + 0x024)
#define BSP_SWITCH_P2_INCTL		(BSP_SWITCH + 0x028)
#define BSP_SWITCH_DF_PORTMAP		(BSP_SWITCH + 0x02C)
#define BSP_SWITCH_P0_ECS_Q32		(BSP_SWITCH + 0x030)
#define BSP_SWITCH_P0_ECS_Q10		(BSP_SWITCH + 0x034)
#define BSP_SWITCH_P0_ECW_Q32		(BSP_SWITCH + 0x038)
#define BSP_SWITCH_P0_ECW_Q10		(BSP_SWITCH + 0x03C)
#define BSP_SWITCH_P1_ECS_Q32		(BSP_SWITCH + 0x040)
#define BSP_SWITCH_P1_ECS_Q10		(BSP_SWITCH + 0x044)
#define BSP_SWITCH_P1_ECW_Q32		(BSP_SWITCH + 0x048)
#define BSP_SWITCH_P1_ECW_Q10		(BSP_SWITCH + 0x04C)
#define BSP_SWITCH_P2_ECS_Q32		(BSP_SWITCH + 0x050)
#define BSP_SWITCH_P2_ECS_Q10		(BSP_SWITCH + 0x054)
#define BSP_SWITCH_P2_ECW_Q32		(BSP_SWITCH + 0x058)
#define BSP_SWITCH_P2_ECW_Q10		(BSP_SWITCH + 0x05C)
#define BSP_SWITCH_INT_ENA		(BSP_SWITCH + 0x060)
#define BSP_SWITCH_INT_ST		(BSP_SWITCH + 0x064)
#define BSP_SWITCH_GCTL0		(BSP_SWITCH + 0x068)
#define BSP_SWITCH_GCTL1		(BSP_SWITCH + 0x06C)
#define BSP_SWITCH_ARP			(BSP_SWITCH + 0x070)
#define BSP_SWITCH_STRM_CTL		(BSP_SWITCH + 0x074)
#define BSP_SWITCH_RGMII_CTL		(BSP_SWITCH + 0x078)
#define BSP_SWITCH_1P_PRT		(BSP_SWITCH + 0x07C)
#define BSP_SWITCH_GBKT_SZBS		(BSP_SWITCH + 0x080)
#define BSP_SWITCH_GBKT_SZEBS		(BSP_SWITCH + 0x084)
#define BSP_SWITCH_BF_TH		(BSP_SWITCH + 0x088)
#define BSP_SWITCH_PMAC_HD_CTL		(BSP_SWITCH + 0x08C)
#define BSP_SWITCH_PMAC_SA1		(BSP_SWITCH + 0x090)
#define BSP_SWITCH_PMAC_SA2		(BSP_SWITCH + 0x094)
#define BSP_SWITCH_PMAC_DA1		(BSP_SWITCH + 0x098)
#define BSP_SWITCH_PMAC_DA2		(BSP_SWITCH + 0x09C)
#define BSP_SWITCH_PMAC_VLAN		(BSP_SWITCH + 0x0A0)
#define BSP_SWITCH_PMAC_TX_IPG		(BSP_SWITCH + 0x0A4)
#define BSP_SWITCH_PMAC_RX_IPG		(BSP_SWITCH + 0x0A8)
#define BSP_SWITCH_ADR_TB_CTL0		(BSP_SWITCH + 0x0AC)
#define BSP_SWITCH_ADR_TB_CTL1		(BSP_SWITCH + 0x0B0)
#define BSP_SWITCH_ADR_TB_CTL2		(BSP_SWITCH + 0x0B4)
#define BSP_SWITCH_ADR_TB_ST0		(BSP_SWITCH + 0x0B8)
#define BSP_SWITCH_ADR_TB_ST1		(BSP_SWITCH + 0x0BC)
#define BSP_SWITCH_ADR_TB_ST2		(BSP_SWITCH + 0x0C0)
#define BSP_SWITCH_RMON_CTL		(BSP_SWITCH + 0x0C4)
#define BSP_SWITCH_RMON_ST		(BSP_SWITCH + 0x0C8)
#define BSP_SWITCH_MDIO_CTL		(BSP_SWITCH + 0x0CC)
#define BSP_SWITCH_MDIO_DATA		(BSP_SWITCH + 0x0D0)
#define BSP_SWITCH_TP_FLT_ACT		(BSP_SWITCH + 0x0D4)
#define BSP_SWITCH_PRTCL_FLT_ACT	(BSP_SWITCH + 0x0D8)
#define BSP_SWITCH_P0_PCDU_CTRL		(BSP_SWITCH + 0x0E4)
#define BSP_SWITCH_P1_PCDU_CTRL		(BSP_SWITCH + 0x0E8)
#define BSP_SWITCH_VLAN_FLT0		(BSP_SWITCH + 0x100)
#define BSP_SWITCH_VLAN_FLT1		(BSP_SWITCH + 0x104)
#define BSP_SWITCH_VLAN_FLT2		(BSP_SWITCH + 0x108)
#define BSP_SWITCH_VLAN_FLT3		(BSP_SWITCH + 0x10C)
#define BSP_SWITCH_VLAN_FLT4		(BSP_SWITCH + 0x110)
#define BSP_SWITCH_VLAN_FLT5		(BSP_SWITCH + 0x114)
#define BSP_SWITCH_VLAN_FLT6		(BSP_SWITCH + 0x118)
#define BSP_SWITCH_VLAN_FLT7		(BSP_SWITCH + 0x11C)
#define BSP_SWITCH_VLAN_FLT8		(BSP_SWITCH + 0x120)
#define BSP_SWITCH_VLAN_FLT9		(BSP_SWITCH + 0x124)
#define BSP_SWITCH_VLAN_FLT10		(BSP_SWITCH + 0x128)
#define BSP_SWITCH_VLAN_FLT11		(BSP_SWITCH + 0x12C)
#define BSP_SWITCH_VLAN_FLT12		(BSP_SWITCH + 0x130)
#define BSP_SWITCH_VLAN_FLT13		(BSP_SWITCH + 0x134)
#define BSP_SWITCH_VLAN_FLT14		(BSP_SWITCH + 0x138)
#define BSP_SWITCH_VLAN_FLT15		(BSP_SWITCH + 0x13C)
#define BSP_SWITCH_TP_FLT10		(BSP_SWITCH + 0x140)
#define BSP_SWITCH_TP_FLT32		(BSP_SWITCH + 0x144)
#define BSP_SWITCH_TP_FLT54		(BSP_SWITCH + 0x148)
#define BSP_SWITCH_TP_FLT76		(BSP_SWITCH + 0x14C)
#define BSP_SWITCH_DFSRV_MAP0		(BSP_SWITCH + 0x150)
#define BSP_SWITCH_DFSRV_MAP1		(BSP_SWITCH + 0x154)
#define BSP_SWITCH_DFSRV_MAP2		(BSP_SWITCH + 0x158)
#define BSP_SWITCH_DFSRV_MAP3		(BSP_SWITCH + 0x15C)
#define BSP_SWITCH_TCP_PF0		(BSP_SWITCH + 0x160)
#define BSP_SWITCH_TCP_PF1		(BSP_SWITCH + 0x164)
#define BSP_SWITCH_TCP_PF2		(BSP_SWITCH + 0x168)
#define BSP_SWITCH_TCP_PF3		(BSP_SWITCH + 0x16C)
#define BSP_SWITCH_TCP_PF4		(BSP_SWITCH + 0x170)
#define BSP_SWITCH_TCP_PF5		(BSP_SWITCH + 0x174)
#define BSP_SWITCH_TCP_PF6		(BSP_SWITCH + 0x178)
#define BSP_SWITCH_TCP_PF7		(BSP_SWITCH + 0x17C)
#define BSP_SWITCH_RA_03_00		(BSP_SWITCH + 0x180)
#define BSP_SWITCH_RA_07_04		(BSP_SWITCH + 0x184)
#define BSP_SWITCH_RA_0B_08		(BSP_SWITCH + 0x188)
#define BSP_SWITCH_RA_0F_0C		(BSP_SWITCH + 0x18C)
#define BSP_SWITCH_RA_13_10		(BSP_SWITCH + 0x190)
#define BSP_SWITCH_RA_17_14		(BSP_SWITCH + 0x194)
#define BSP_SWITCH_RA_1B_18		(BSP_SWITCH + 0x198)
#define BSP_SWITCH_RA_1F_1C		(BSP_SWITCH + 0x19C)
#define BSP_SWITCH_RA_23_20		(BSP_SWITCH + 0x1A0)
#define BSP_SWITCH_RA_27_24		(BSP_SWITCH + 0x1A4)
#define BSP_SWITCH_RA_2B_28		(BSP_SWITCH + 0x1A8)
#define BSP_SWITCH_RA_2F_2C		(BSP_SWITCH + 0x1AC)
#define BSP_SWITCH_F0			(BSP_SWITCH + 0x1B0)
#define BSP_SWITCH_F1			(BSP_SWITCH + 0x1B4)

#define ADDR_BASE_ETHSW_PDI 0xBE108000
#define ADDR_MULT_ETHSW_PDI 4 
#define ADDR_MACRO_ETHSW_PDI(a) (a) 
#define ADDR_BASE_ETHSW_VR9_PDI 0xBE108000    //Need to be modified as per the User Requirements
#define ADDR_MULT_ETHSW_VR9_PDI 4    //Need to be modified as per the User Requirements
#define ADDR_MACRO_ETHSW_VR9_PDI(a) (a)  //Need to be modified as per User Requirements

//***********************************************************
//Register File Address
//***********************************************************
  //Register File : ETHSW_TOP_PDI
  //This chapter provides the registers that are needed to control the toplevel functions of the Ethernet switch module.
# define ADR_ETHSW_TOP_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x000)))

  //Register File : ETHSW_BM_PDI
  //This chapter provides the common registers that are needed to control the Ethernet Switch Buffer Manager.
# define ADR_ETHSW_BM_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x040)))

  //Register File : ETHSW_BM_PORT_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x080)))

  //Register File : ETHSW_BM_PORT_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x082)))

  //Register File : ETHSW_BM_PORT_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x084)))

  //Register File : ETHSW_BM_PORT_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x086)))

  //Register File : ETHSW_BM_PORT_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x088)))

  //Register File : ETHSW_BM_PORT_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08A)))

  //Register File : ETHSW_BM_PORT_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per switch port.
# define ADR_ETHSW_BM_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08C)))

  //Register File : ETHSW_BM_QUEUE_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x100)))

  //Register File : ETHSW_BM_QUEUE_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x102)))

  //Register File : ETHSW_BM_QUEUE_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x104)))

  //Register File : ETHSW_BM_QUEUE_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x106)))

  //Register File : ETHSW_BM_QUEUE_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x108)))

  //Register File : ETHSW_BM_QUEUE_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10A)))

  //Register File : ETHSW_BM_QUEUE_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10C)))

  //Register File : ETHSW_BM_QUEUE_PDI_7
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10E)))

  //Register File : ETHSW_BM_QUEUE_PDI_8
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x110)))

  //Register File : ETHSW_BM_QUEUE_PDI_9
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x112)))

  //Register File : ETHSW_BM_QUEUE_PDI_10
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x114)))

  //Register File : ETHSW_BM_QUEUE_PDI_11
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x116)))

  //Register File : ETHSW_BM_QUEUE_PDI_12
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x118)))

  //Register File : ETHSW_BM_QUEUE_PDI_13
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_13	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11A)))

  //Register File : ETHSW_BM_QUEUE_PDI_14
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_14	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11C)))

  //Register File : ETHSW_BM_QUEUE_PDI_15
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_15	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11E)))

  //Register File : ETHSW_BM_QUEUE_PDI_16
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_16	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x120)))

  //Register File : ETHSW_BM_QUEUE_PDI_17
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_17	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x122)))

  //Register File : ETHSW_BM_QUEUE_PDI_18
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_18	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x124)))

  //Register File : ETHSW_BM_QUEUE_PDI_19
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_19	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x126)))

  //Register File : ETHSW_BM_QUEUE_PDI_20
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_20	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x128)))

  //Register File : ETHSW_BM_QUEUE_PDI_21
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_21	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12A)))

  //Register File : ETHSW_BM_QUEUE_PDI_22
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_22	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12C)))

  //Register File : ETHSW_BM_QUEUE_PDI_23
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_23	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12E)))

  //Register File : ETHSW_BM_QUEUE_PDI_24
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_24	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x130)))

  //Register File : ETHSW_BM_QUEUE_PDI_25
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_25	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x132)))

  //Register File : ETHSW_BM_QUEUE_PDI_26
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_26	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x134)))

  //Register File : ETHSW_BM_QUEUE_PDI_27
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_27	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x136)))

  //Register File : ETHSW_BM_QUEUE_PDI_28
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_28	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x138)))

  //Register File : ETHSW_BM_QUEUE_PDI_29
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_29	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13A)))

  //Register File : ETHSW_BM_QUEUE_PDI_30
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_30	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13C)))

  //Register File : ETHSW_BM_QUEUE_PDI_31
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager queues.
# define ADR_ETHSW_BM_QUEUE_PDI_31	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13E)))

  //Register File : ETHSW_BM_SHAPER_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x140)))

  //Register File : ETHSW_BM_SHAPER_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x145)))

  //Register File : ETHSW_BM_SHAPER_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14A)))

  //Register File : ETHSW_BM_SHAPER_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14F)))

  //Register File : ETHSW_BM_SHAPER_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x154)))

  //Register File : ETHSW_BM_SHAPER_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x159)))

  //Register File : ETHSW_BM_SHAPER_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15E)))

  //Register File : ETHSW_BM_SHAPER_PDI_7
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x163)))

  //Register File : ETHSW_BM_SHAPER_PDI_8
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x168)))

  //Register File : ETHSW_BM_SHAPER_PDI_9
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16D)))

  //Register File : ETHSW_BM_SHAPER_PDI_10
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x172)))

  //Register File : ETHSW_BM_SHAPER_PDI_11
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x177)))

  //Register File : ETHSW_BM_SHAPER_PDI_12
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17C)))

  //Register File : ETHSW_BM_SHAPER_PDI_13
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_13	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x181)))

  //Register File : ETHSW_BM_SHAPER_PDI_14
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_14	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x186)))

  //Register File : ETHSW_BM_SHAPER_PDI_15
  //This chapter provides the registers that are needed to control the Ethernet Switch Buffer Manager per rate shaper.
# define ADR_ETHSW_BM_SHAPER_PDI_15	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18B)))

  //Register File : ETHSW_PCE_PDI
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x440)))

  //Register File : ETHSW_PCE_PORT_PDI_0
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x480)))

  //Register File : ETHSW_PCE_PORT_PDI_1
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48A)))

  //Register File : ETHSW_PCE_PORT_PDI_2
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x494)))

  //Register File : ETHSW_PCE_PORT_PDI_3
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49E)))

  //Register File : ETHSW_PCE_PORT_PDI_4
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A8)))

  //Register File : ETHSW_PCE_PORT_PDI_5
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B2)))

  //Register File : ETHSW_PCE_PORT_PDI_6
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BC)))

  //Register File : ETHSW_PCE_PORT_PDI_7
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C6)))

  //Register File : ETHSW_PCE_PORT_PDI_8
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D0)))

  //Register File : ETHSW_PCE_PORT_PDI_9
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DA)))

  //Register File : ETHSW_PCE_PORT_PDI_10
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E4)))

  //Register File : ETHSW_PCE_PORT_PDI_11
  //This chapter provides the registers that are needed per switch port to control the Ethernet Parser and Classification Engine.
# define ADR_ETHSW_PCE_PORT_PDI_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EE)))

  //Register File : ETHSW_PCE_METER_PDI_0
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x580)))

  //Register File : ETHSW_PCE_METER_PDI_1
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x587)))

  //Register File : ETHSW_PCE_METER_PDI_2
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58E)))

  //Register File : ETHSW_PCE_METER_PDI_3
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x595)))

  //Register File : ETHSW_PCE_METER_PDI_4
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59C)))

  //Register File : ETHSW_PCE_METER_PDI_5
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A3)))

  //Register File : ETHSW_PCE_METER_PDI_6
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AA)))

  //Register File : ETHSW_PCE_METER_PDI_7
  //This chapter provides the registers that are needed to control the Ethernet Parser and Classification Engine metering instances.
# define ADR_ETHSW_PCE_METER_PDI_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B1)))

  //Register File : ETHSW_MACS_TOP_PDI
  //Not Specified
# define ADR_ETHSW_MACS_TOP_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C0)))

  //Register File : ETHSW_MAC_PDI_0
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x900)))

  //Register File : ETHSW_MAC_PDI_1
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90C)))

  //Register File : ETHSW_MAC_PDI_2
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x918)))

  //Register File : ETHSW_MAC_PDI_3
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x924)))

  //Register File : ETHSW_MAC_PDI_4
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x930)))

  //Register File : ETHSW_MAC_PDI_5
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93C)))

  //Register File : ETHSW_MAC_PDI_6
  //This chapter provides the registers that are needed to control a single Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x948)))

  //Register File : ETHSW_FDMA_PDI
  //This chapter provides the registers that are needed to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA40)))

  //Register File : ETHSW_FDMA_PORT_PDI_0
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA80)))

  //Register File : ETHSW_FDMA_PORT_PDI_1
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA86)))

  //Register File : ETHSW_FDMA_PORT_PDI_2
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8C)))

  //Register File : ETHSW_FDMA_PORT_PDI_3
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA92)))

  //Register File : ETHSW_FDMA_PORT_PDI_4
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA98)))

  //Register File : ETHSW_FDMA_PORT_PDI_5
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9E)))

  //Register File : ETHSW_FDMA_PORT_PDI_6
  //This chapter provides the registers that are needed per port to control the Ethernet Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA4)))

  //Register File : ETHSW_SDMA_PDI
  //This chapter provides the registers that are needed to globally control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PDI	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB40)))

  //Register File : ETHSW_SDMA_PORT_PDI_0
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC0)))

  //Register File : ETHSW_SDMA_PORT_PDI_1
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC6)))

  //Register File : ETHSW_SDMA_PORT_PDI_2
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCC)))

  //Register File : ETHSW_SDMA_PORT_PDI_3
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD2)))

  //Register File : ETHSW_SDMA_PORT_PDI_4
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD8)))

  //Register File : ETHSW_SDMA_PORT_PDI_5
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDE)))

  //Register File : ETHSW_SDMA_PORT_PDI_6
  //This chapter provides the registers that are needed per port to control the Ethernet Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE4)))


//***********************************************************
//Register Address 
//***********************************************************

  //Register : ETHSW_SWRES
  //This register controls software reset functions of reset of configuration setting and RAM contents pointers, reset of HW without configuration setting and RAM contents pointers.
# define ADR_ETHSW_TOP_PDI_ETHSW_SWRES	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x000)))

  //Register : ETHSW_CLK
  //This register controls clock gating and frequency dividing functions of the Ethernet switch.
# define ADR_ETHSW_TOP_PDI_ETHSW_CLK	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x001)))

  //Register : ETHSW_DBG
  //This register controls the debug functions of the Ethernet switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_DBG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x002)))

  //Register : ETHSW_SSB_MODE
  //This register is used to access memory locations in the shared segment buffer.
  //It provides the access mode and the MSB part of the target address.
# define ADR_ETHSW_TOP_PDI_ETHSW_SSB_MODE	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x003)))

  //Register : ETHSW_SSB_ADDR
  //This register is used to access memory locations in the shared segment buffer.
  //It provides the LSB part of the target address.
# define ADR_ETHSW_TOP_PDI_ETHSW_SSB_ADDR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x004)))

  //Register : ETHSW_SSB_DATA
  //This register is used to access memory locations in the shared segment buffer.
  //It provides the 16 data bits to be read from or written to the target location.
# define ADR_ETHSW_TOP_PDI_ETHSW_SSB_DATA	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x005)))

  //Register : ETHSW_CAP_0
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x006)))

  //Register : ETHSW_CAP_1
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x007)))

  //Register : ETHSW_CAP_2
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x008)))

  //Register : ETHSW_CAP_3
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x009)))

  //Register : ETHSW_CAP_4
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00A)))

  //Register : ETHSW_CAP_5
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00B)))

  //Register : ETHSW_CAP_6
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00C)))

  //Register : ETHSW_CAP_7
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00D)))

  //Register : ETHSW_CAP_8
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00E)))

  //Register : ETHSW_CAP_9
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x00F)))

  //Register : ETHSW_CAP_10
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x010)))

  //Register : ETHSW_CAP_11
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x011)))

  //Register : ETHSW_CAP_12
  //This register is used to indicate the physical capabilities of the implemented switch macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_CAP_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x012)))

  //Register : ETHSW_VERSION
  //This register is used to indicate the implemented design version of the macro block.
# define ADR_ETHSW_TOP_PDI_ETHSW_VERSION	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x013)))

  //Register : ETHSW_IER
  //This register is used to enable or disable individual interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
  //There are global enable bits for interrupts generated by BM, PCE, SDMA, and MAC in addition to individual enable bits the related modules. To enable an interrupt, it must be enabled on module and top level.
# define ADR_ETHSW_TOP_PDI_ETHSW_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x014)))

  //Register : ETHSW_ISR
  //This register provides global interrupt status information.
  //If an interrupt is indicated for a block, the interrupt source can be read from the interrupt status register(s) located in the related submodule.
# define ADR_ETHSW_TOP_PDI_ETHSW_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x015)))

  //Register : ETHSW_SPARE_0
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x016)))

  //Register : ETHSW_SPARE_1
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x017)))

  //Register : ETHSW_SPARE_2
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x018)))

  //Register : ETHSW_SPARE_3
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x019)))

  //Register : ETHSW_SPARE_4
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01A)))

  //Register : ETHSW_SPARE_5
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01B)))

  //Register : ETHSW_SPARE_6
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01C)))

  //Register : ETHSW_SPARE_7
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01D)))

  //Register : ETHSW_SPARE_8
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_8	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01E)))

  //Register : ETHSW_SPARE_9
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_9	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x01F)))

  //Register : ETHSW_SPARE_10
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_10	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x020)))

  //Register : ETHSW_SPARE_11
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_11	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x021)))

  //Register : ETHSW_SPARE_12
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_12	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x022)))

  //Register : ETHSW_SPARE_13
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_13	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x023)))

  //Register : ETHSW_SPARE_14
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_14	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x024)))

  //Register : ETHSW_SPARE_15
  //This register is used for Metalfixes.
# define ADR_ETHSW_TOP_PDI_ETHSW_SPARE_15	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x025)))

  //Register : BM_RAM_VAL_3
  //This register provides the value part 3 ("Bit [63:48]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x040)))

  //Register : BM_RAM_VAL_2
  //This register provides the value part 2 ("Bit [47:32]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x041)))

  //Register : BM_RAM_VAL_1
  //This register provides the value part 1 ("Bit [31:16]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x042)))

  //Register : BM_RAM_VAL_0
  //This register provides the value part 0 ("Bit [15:0]").
# define ADR_ETHSW_BM_PDI_BM_RAM_VAL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x043)))

  //Register : BM_RAM_ADDR
  //This register provides the address of an entry within a selected table to be accessed.
# define ADR_ETHSW_BM_PDI_BM_RAM_ADDR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x044)))

  //Register : BM_RAM_CTRL
  //This register is used to handle the access to multiple RAMs.
# define ADR_ETHSW_BM_PDI_BM_RAM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x045)))

  //Register : BM_FSQM_GCTRL
  //This register is used to configure the Free Segment Queue Manager (FSQM).
# define ADR_ETHSW_BM_PDI_BM_FSQM_GCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x046)))

  //Register : BM_CONS_SEG
  //This register contains the number of consumed segments.
# define ADR_ETHSW_BM_PDI_BM_CONS_SEG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x047)))

  //Register : BM_CONS_PKT
  //This register contains the number of consumed packet pointers.
# define ADR_ETHSW_BM_PDI_BM_CONS_PKT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x048)))

  //Register : BM_GCTRL
  //This register is used to initialize parts of the Buffer Manager.
  //The reset bits are set by software to initialize the related circuit and must be reset by software to enable the function again.
# define ADR_ETHSW_BM_PDI_BM_GCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x049)))

  //Register : BM_QUEUE_GCTRL
  //This register is used to configure the Queue Manager.
# define ADR_ETHSW_BM_PDI_BM_QUEUE_GCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04A)))

  //Register : BM_WRED_RTH_0
  //This register is used to provide the WRED threshold values for frames marked "red".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_RTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04B)))

  //Register : BM_WRED_RTH_1
  //This register is used to provide the WRED threshold values for frames marked "red".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_RTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04C)))

  //Register : BM_WRED_YTH_0
  //This register is used to provide the WRED threshold values for frames marked "yellow".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_YTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04D)))

  //Register : BM_WRED_YTH_1
  //This register is used to provide the WRED threshold values for frames marked "yellow".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_YTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04E)))

  //Register : BM_WRED_GTH_0
  //This register is used to provide the WRED threshold values for frames marked "green".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_GTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x04F)))

  //Register : BM_WRED_GTH_1
  //This register is used to provide the WRED threshold values for frames marked "green".
  //If between the thresholds, frames are dropped with the configured Pmin and Pmax probabilities.
# define ADR_ETHSW_BM_PDI_BM_WRED_GTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x050)))

  //Register : BM_DROP_GTH_0
  //This register is used to configure the thresholds regarding available packet pointer for packet ACM drop.
  //ACM drop is done if number of consumed packet pointer for a red marked packet is above THR_FQ threshold value.
# define ADR_ETHSW_BM_PDI_BM_DROP_GTH_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x051)))

  //Register : BM_DROP_GTH_1
  //This register is used to configure the thresholds regarding available packet pointer for packet ACM drop.
  //ACM drop is done if number of consumed packet pointer for a yellow marked packet is above THY_FQ threshold value.
# define ADR_ETHSW_BM_PDI_BM_DROP_GTH_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x052)))

  //Register : BM_DROP_GTH_2
  //This register is used to configure the thresholds regarding available packet pointer for packet ACM drop.
  //ACM drop is done if number of consumed packet pointer for a green marked packet is above THG_FQ threshold value.
# define ADR_ETHSW_BM_PDI_BM_DROP_GTH_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x053)))

  //Register : BM_IER
  //This register is used to enable or disable global BM interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_BM_PDI_BM_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x054)))

  //Register : BM_ISR
  //This register provides interrupt status summary of all port-related BM interrupts (see the BM_PISR_n registers) and interrupts that are related to the buffer manager's toplevel.
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
# define ADR_ETHSW_BM_PDI_BM_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x055)))

  //Register : BM_CISEL
  //RMON Counter event interrupts can be enabled for a single port only. This register is used to select the port to be observed.
# define ADR_ETHSW_BM_PDI_BM_CISEL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x056)))

  //Register : BM_DEBUG_CTRL
  //This register is used to configure the debug multiplexer.
# define ADR_ETHSW_BM_PDI_BM_DEBUG_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x057)))

  //Register : BM_DEBUG_VAL
  //This register is used to read data for debugging issues.
# define ADR_ETHSW_BM_PDI_BM_DEBUG_VAL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x058)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_0_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x080)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_0_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x081)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_1_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x082)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_1_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x083)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_2_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x084)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_2_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x085)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_3_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x086)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_3_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x087)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_4_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x088)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_4_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x089)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_5_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08A)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_5_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08B)))

  //Register : BM_PCFG
  //This register provides port-related configurations.
# define ADR_ETHSW_BM_PORT_PDI_6_BM_PCFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08C)))

  //Register : BM_RMON_CTRL
  //This register is used to initialize the RMON counter values (set to zero).
# define ADR_ETHSW_BM_PORT_PDI_6_BM_RMON_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x08D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_0_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x100)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_0_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x101)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_1_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x102)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_1_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x103)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_2_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x104)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_2_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x105)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_3_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x106)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_3_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x107)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_4_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x108)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_4_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x109)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_5_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_5_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_6_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_6_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_7_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_7_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x10F)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_8_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x110)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_8_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x111)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_9_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x112)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_9_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x113)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_10_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x114)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_10_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x115)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_11_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x116)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_11_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x117)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_12_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x118)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_12_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x119)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_13_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_13_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_14_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_14_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_15_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_15_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x11F)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_16_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x120)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_16_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x121)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_17_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x122)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_17_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x123)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_18_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x124)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_18_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x125)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_19_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x126)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_19_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x127)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_20_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x128)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_20_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x129)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_21_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_21_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_22_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_22_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_23_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_23_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x12F)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_24_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x130)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_24_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x131)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_25_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x132)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_25_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x133)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_26_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x134)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_26_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x135)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_27_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x136)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_27_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x137)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_28_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x138)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_28_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x139)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_29_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13A)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_29_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13B)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_30_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13C)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_30_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13D)))

  //Register : PQM_DP
  //This register is used to define per-queue drop probability profiles for each queue.
# define ADR_ETHSW_BM_QUEUE_PDI_31_PQM_DP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13E)))

  //Register : PQM_RS
  //This register is used to select the rate shaper(s) for each queue. By default, all rate shapers are disabled.
# define ADR_ETHSW_BM_QUEUE_PDI_31_PQM_RS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x13F)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x140)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x141)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x142)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x143)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_0_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x144)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x145)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x146)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x147)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x148)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_1_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x149)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14A)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14B)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14C)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14D)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_2_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14E)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x14F)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x150)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x151)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x152)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_3_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x153)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x154)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x155)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x156)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x157)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_4_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x158)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x159)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15A)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15B)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15C)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_5_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15D)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15E)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x15F)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x160)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x161)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_6_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x162)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x163)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x164)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x165)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x166)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_7_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x167)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x168)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x169)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16A)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16B)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_8_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16C)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16D)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16E)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x16F)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x170)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_9_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x171)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x172)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x173)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x174)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x175)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_10_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x176)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x177)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x178)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x179)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17A)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_11_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17B)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17C)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17D)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17E)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x17F)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_12_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x180)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x181)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x182)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x183)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x184)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_13_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x185)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x186)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x187)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x188)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x189)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_14_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18A)))

  //Register : RS_CTRL
  //This register is used to control the rate shapers.
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18B)))

  //Register : RS_CBS
  //This register is used to control the rate shaper's Committed Burst Size (CBS).
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18C)))

  //Register : RS_IBS
  //This register is used to control the rate shaper's Instantaneous Burst Size (IBS).
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18D)))

  //Register : RS_CIR_EXP
  //This register is used to set the rate shaper's rate exponent value.
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18E)))

  //Register : RS_CIR_MANT
  //This register is used to set the rate shaper's rate mantissa value.
# define ADR_ETHSW_BM_SHAPER_PDI_15_RS_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x18F)))

  //Register : PCE_TBL_KEY_7
  //This register provides the data ("key") to a selected table at the selected address (Bit [127:112]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x440)))

  //Register : PCE_TBL_KEY_6
  //This register provides the data ("key") to a selected table at the selected address (Bit [111:96]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x441)))

  //Register : PCE_TBL_KEY_5
  //This register provides the data ("key") to a selected table at the selected address (Bit [95:80]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x442)))

  //Register : PCE_TBL_KEY_4
  //This register provides the data ("key") to a selected table at the selected address (Bit [79:64]).
  //This register is used to access the traffic flow table.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x443)))

  //Register : PCE_TBL_KEY_3
  //This register provides the data ("key") to a selected table at the selected address (Bit [63:48]).
  //This register is used to access the traffic flow table, the MAC bridging table, and the IP Destination/Source Address tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x444)))

  //Register : PCE_TBL_KEY_2
  //This register provides the data ("key") to a selected table at the selected address (Bit [47:32]).
  //This register is used to access the traffic flow table, the MAC bridging table, the MAC Source/Destination Address table, and the IP Destination/Source Address tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x445)))

  //Register : PCE_TBL_KEY_1
  //This register provides the data ("key") to a selected table at the selected address (Bit [31:16]).
  //This register is used to access the traffic flow table, the MAC bridging table, the MAC Source/Destination Address table, the multicast HW/SW tables, and the IP Destination/Source Address tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x446)))

  //Register : PCE_TBL_KEY_0
  //This register provides the data ("key") to a selected table at the selected address (Bit [15:0]).
  //This register is used to access any of the tables that provides a key.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_KEY_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x447)))

  //Register : PCE_TBL_MASK_0
  //This register provides the mask associated with an entry to be written.
  //This register is also used as forth data register for parser microcode accesses.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_MASK_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x448)))

  //Register : PCE_TBL_VAL_4
  //This register provides the value that is associated with the key (Bit [79:64]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x449)))

  //Register : PCE_TBL_VAL_3
  //This register provides the value that is associated with the key (Bit [63:48]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44A)))

  //Register : PCE_TBL_VAL_2
  //This register provides the value that is associated with the key ("Bit [47:32]").
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44B)))

  //Register : PCE_TBL_VAL_1
  //This register provides the value that is associated with the key (Bit [31:16]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44C)))

  //Register : PCE_TBL_VAL_0
  //This register provides the value that is associated with the key (Bit [15:0]).
# define ADR_ETHSW_PCE_PDI_PCE_TBL_VAL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44D)))

  //Register : PCE_TBL_ADDR
  //This register provides the address within a selected table to be written to ("tbl_entry_addr_wrd").
# define ADR_ETHSW_PCE_PDI_PCE_TBL_ADDR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44E)))

  //Register : PCE_TBL_CTRL
  //This register is used to handle the access to multiple look-up tables.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x44F)))

  //Register : PCE_TBL_STAT
  //This register is used to handle the access to multiple look-up tables. It indicates the filling level (empty or full) and ongoing accesses.
# define ADR_ETHSW_PCE_PDI_PCE_TBL_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x450)))

  //Register : PCE_AGE_0
  //This register is used to configure the MAC table aging counter's exponent values.
  //The aging time is calculated from PCE_AGE_0.EXP and PCE_AGE_1.MANT according to the formula:
  //Aging Time = (MANT+1) x 2^(EXP+1) x 1.31 ms
  //For a default aging time of 300 s the values of MANT = 0xDF85 and EXP = 0x10 are selected.
# define ADR_ETHSW_PCE_PDI_PCE_AGE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x451)))

  //Register : PCE_AGE_1
  //This register is used to configure the MAC table aging counter's mantissa value.
  //Aging Time = (MANT+1) x 2^(EXP+1) x 1.31 ms
# define ADR_ETHSW_PCE_PDI_PCE_AGE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x452)))

  //Register : PCE_PMAP_1
  //This register is used to define the handling of monitored ports.
# define ADR_ETHSW_PCE_PDI_PCE_PMAP_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x453)))

  //Register : PCE_PMAP_2
  //This register is used to define default port maps for multicast frames.
# define ADR_ETHSW_PCE_PDI_PCE_PMAP_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x454)))

  //Register : PCE_PMAP_3
  //This register is used to define the default port map for unknown unicast frames.
# define ADR_ETHSW_PCE_PDI_PCE_PMAP_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x455)))

  //Register : PCE_GCTRL_0
  //This register is used to provide global control settings.
# define ADR_ETHSW_PCE_PDI_PCE_GCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x456)))

  //Register : PCE_GCTRL_1
  //This register is used to provide global control settings.
# define ADR_ETHSW_PCE_PDI_PCE_GCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x457)))

  //Register : PCE_TCM_GLOB_CTRL
  //This register is used to configure general srTCM setting).
# define ADR_ETHSW_PCE_PDI_PCE_TCM_GLOB_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x458)))

  //Register : PCE_IGMP_CTRL
  //This register is used to configure the IGMP function.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x459)))

  //Register : PCE_IGMP_DRPM
  //This register is used to configure the IGMP port map.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_DRPM	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45A)))

  //Register : PCE_IGMP_AGE_0
  //This register is used to configure the IGMP group aging time.
  //The aging time is calculated from PCE_IGMP_AGE_0.EXP and PCE_IGMP_AGE_1.MANT according to the formula:
  //Aging Time = (MANT+1) x 2^(EXP+8+1) x 40 ns
  //For a default aging time of about 100 ms the values of MANT = 0x98 and EXP = 0x05 are selected.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_AGE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45B)))

  //Register : PCE_IGMP_AGE_1
  //This register is used to configure the IGMP snooped router port aging time.
  //This timer uses the programmed Group Aging time to increment. If the timer expires and no query or router advertisement messages are snooped on a port, the port is removed from the snooped router port map.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_AGE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45C)))

  //Register : PCE_IGMP_STAT
  //This register is used to indicate IGMP status information.
# define ADR_ETHSW_PCE_PDI_PCE_IGMP_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45D)))

  //Register : WOL_GLB_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function globally.
# define ADR_ETHSW_PCE_PDI_WOL_GLB_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45E)))

  //Register : WOL_DA_0
  //This register provides the lower two byte of the WoL MAC destination address.
# define ADR_ETHSW_PCE_PDI_WOL_DA_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x45F)))

  //Register : WOL_DA_1
  //This register provides the medium two byte of the WoL MAC destination address.
# define ADR_ETHSW_PCE_PDI_WOL_DA_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x460)))

  //Register : WOL_DA_2
  //This register provides the higher two byte of the WoL MAC destination address.
# define ADR_ETHSW_PCE_PDI_WOL_DA_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x461)))

  //Register : WOL_PW_0
  //This register provides the lower two byte of the WoL password.
# define ADR_ETHSW_PCE_PDI_WOL_PW_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x462)))

  //Register : WOL_PW_1
  //This register provides the medium two byte of the WoL password.
# define ADR_ETHSW_PCE_PDI_WOL_PW_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x463)))

  //Register : WOL_PW_2
  //This register provides the higher two byte of the WoL password.
# define ADR_ETHSW_PCE_PDI_WOL_PW_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x464)))

  //Register : PCE_IER_0
  //This register is used to enable or disable global PCE interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PDI_PCE_IER_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x465)))

  //Register : PCE_IER_1
  //This register is used to enable or disable global PCE interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PDI_PCE_IER_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x466)))

  //Register : PCE_ISR_0
  //This register provides interrupt status summary of all port-related PCE interrupts (see the PCE_PISR_n registers).
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
  //There is no global PCE interrupt enable register, this is covered by the port-related interrupt enable registers (see PCE_PIEN_n).
# define ADR_ETHSW_PCE_PDI_PCE_ISR_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x467)))

  //Register : PCE_ISR_1
  //This register provides interrupt status summary of all port-related PCE interrupts (see the PCE_PISR_n registers).
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
  //There is no global PCE interrupt enable register, this is covered by the port-related interrupt enable registers (see PCE_PIEN_n).
# define ADR_ETHSW_PCE_PDI_PCE_ISR_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x468)))

  //Register : PARSER_STAT
  //This register provides information of the parser's status which can be used for debugging.
# define ADR_ETHSW_PCE_PDI_PARSER_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x469)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x480)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x481)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x482)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x483)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_0_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x484)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x485)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x486)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x487)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x488)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_0_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x489)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48A)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48B)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48C)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48D)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_1_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48E)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x48F)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x490)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x491)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x492)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_1_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x493)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x494)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x495)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x496)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x497)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_2_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x498)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x499)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49A)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49B)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49C)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_2_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49D)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49E)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x49F)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A0)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A1)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_3_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A2)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A3)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A4)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A5)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A6)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_3_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A7)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A8)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4A9)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AA)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AB)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_4_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AC)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AD)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AE)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4AF)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B0)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_4_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B1)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B2)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B3)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B4)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B5)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_5_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B6)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B7)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B8)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4B9)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BA)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_5_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BB)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BC)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BD)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BE)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4BF)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_6_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C0)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C1)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C2)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C3)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C4)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_6_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C5)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C6)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C7)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C8)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4C9)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_7_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CA)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CB)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CC)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CD)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CE)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_7_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4CF)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D0)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D1)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D2)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D3)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_8_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D4)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D5)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D6)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D7)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D8)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_8_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4D9)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DA)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DB)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DC)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DD)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_9_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DE)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4DF)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E0)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E1)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E2)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_9_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E3)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E4)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E5)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E6)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E7)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_10_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E8)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4E9)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EA)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EB)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EC)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_10_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4ED)))

  //Register : PCE_PCTRL_0
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EE)))

  //Register : PCE_PCTRL_1
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4EF)))

  //Register : PCE_PCTRL_2
  //This per-port register is used to define the port properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F0)))

  //Register : PCE_PCTRL_3
  //This per-port register is used to configure the mirroring functions.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PCTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F1)))

  //Register : WOL_CTRL
  //This register is used to configure the Wake-on-LAN (WoL) function per port.
# define ADR_ETHSW_PCE_PORT_PDI_11_WOL_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F2)))

  //Register : PCE_VCTRL
  //This per-port register is used to define the port's VLAN properties.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_VCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F3)))

  //Register : PCE_DEFPVID
  //This register is used to provide the default Port VID (PVID).
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_DEFPVID	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F4)))

  //Register : PCE_PSTAT
  //This register is used to provide per-port PCE-related status information.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F5)))

  //Register : PCE_PIER
  //This register is used to enable or disable interrupts per port.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F6)))

  //Register : PCE_PISR
  //This register provides interrupt status information.
  //An interrupt is cleared by writing a 1 to the related bit position(s).
# define ADR_ETHSW_PCE_PORT_PDI_11_PCE_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x4F7)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x580)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x581)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x582)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x583)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x584)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x585)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_0_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x586)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x587)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x588)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x589)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58A)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58B)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58C)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_1_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58D)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58E)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x58F)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x590)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x591)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x592)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x593)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_2_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x594)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x595)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x596)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x597)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x598)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x599)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59A)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_3_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59B)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59C)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59D)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59E)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x59F)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A0)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A1)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_4_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A2)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A3)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A4)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A5)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A6)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A7)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A8)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_5_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5A9)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AA)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AB)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AC)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AD)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AE)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5AF)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_6_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B0)))

  //Register : PCE_TCM_CTRL
  //This register is used to configure the single-rate Three-color Markers (srTCM).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B1)))

  //Register : PCE_TCM_STAT
  //This register is used to indicate the status of the single-rate Three-color Markers (srTCM).
  //Status bits are set once an event is detected and must be cleared by software through writing a 1 to the related status bit.
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_STAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B2)))

  //Register : PCE_TCM_CBS
  //This register is used to define the Committed Burst Size (CBS).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B3)))

  //Register : PCE_TCM_EBS
  //This register is used to define the Excess Burst Size (EBS).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_EBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B4)))

  //Register : PCE_TCM_IBS
  //This register is used to define the Instantaneous Burst Size (IBS).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_IBS	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B5)))

  //Register : PCE_TCM_CIR_MANT
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CIR_MANT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B6)))

  //Register : PCE_TCM_CIR_EXP
  //This register is used to define the Constant Information Rate (CIR).
# define ADR_ETHSW_PCE_METER_PDI_7_PCE_TCM_CIR_EXP	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x5B7)))

  //Register : MAC_TEST
  //This register is used to select test functions.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_TEST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C0)))

  //Register : MAC_PFAD_CFG
  //This register is used to configure if a common MAC source address is used for transmitted Pause frames on all Ethernet ports or if individual addresses are used.
  //The MAC source address is defined by registers MAC_PFSA_0, MAC_PFSA_1, and MAC_PFSA_2.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFAD_CFG	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C1)))

  //Register : MAC_PFSA_0
  //This register is used to configure the Pause frame source address.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFSA_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C2)))

  //Register : MAC_PFSA_1
  //This register is used to configure the Pause frame source address.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFSA_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C3)))

  //Register : MAC_PFSA_2
  //This register is used to configure the Pause frame source address.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_PFSA_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C4)))

  //Register : MAC_FLEN
  //This register is used to configure the maximum frame length for Jumbo frames.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_FLEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C5)))

  //Register : MAC_VLAN_ETYPE_0
  //This register is used to configure the Ethertype to detect an outer VLAN tag.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_VLAN_ETYPE_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C6)))

  //Register : MAC_VLAN_ETYPE_1
  //This register is used to configure the Ethertype to detect an inner VLAN tag.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_VLAN_ETYPE_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C7)))

  //Register : MAC_IER
  //This register is used to enable or disable all MAC interrupts per port.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C8)))

  //Register : MAC_ISR
  //This register collects the interrupt status information that is provided per port.
# define ADR_ETHSW_MACS_TOP_PDI_MAC_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x8C9)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_0_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x900)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_0_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x901)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_0_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x902)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x903)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x904)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x905)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x906)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x907)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x908)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_0_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x909)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_0_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90A)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_0_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90B)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_1_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90C)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_1_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90D)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_1_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90E)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x90F)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x910)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x911)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x912)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x913)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x914)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_1_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x915)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_1_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x916)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_1_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x917)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_2_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x918)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_2_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x919)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_2_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91A)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91B)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91C)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91D)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91E)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x91F)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x920)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_2_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x921)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_2_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x922)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_2_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x923)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_3_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x924)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_3_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x925)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_3_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x926)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x927)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x928)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x929)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92A)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92B)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92C)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_3_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92D)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_3_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92E)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_3_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x92F)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_4_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x930)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_4_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x931)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_4_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x932)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x933)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x934)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x935)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x936)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x937)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x938)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_4_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x939)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_4_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93A)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_4_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93B)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_5_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93C)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_5_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93D)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_5_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93E)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x93F)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x940)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x941)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x942)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x943)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x944)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_5_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x945)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_5_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x946)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_5_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x947)))

  //Register : MAC_PSTAT
  //This register provides information about the current status of the Ethernet MAC. Additionally, status information of the attached Ethernet PHY are provided in the same register. PHY status information is retrieved by using the auto-polling process.
# define ADR_ETHSW_MAC_PDI_6_MAC_PSTAT	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x948)))

  //Register : MAC_PISR
  //This register provides information about the current status of the Ethernet MAC and generates an interrupt.
  //The each interrupt status bit can be individually cleared by writing a 1 value to the related bit position.
  //Multiple bits can be cleared through a single write access.
# define ADR_ETHSW_MAC_PDI_6_MAC_PISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x949)))

  //Register : MAC_PIER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_MAC_PDI_6_MAC_PIER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94A)))

  //Register : MAC_CTRL_0
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94B)))

  //Register : MAC_CTRL_1
  //This register is used to configure the Ethernet MAC.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94C)))

  //Register : MAC_CTRL_2
  //This register is used to configure the maximum frame length to be received.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94D)))

  //Register : MAC_CTRL_3
  //This register is used to configure the frame handling in half-duplex mode.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94E)))

  //Register : MAC_CTRL_4
  //This register is used to configure the LPI function.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x94F)))

  //Register : MAC_CTRL_5
  //This register is used to configure the Jam pattern size.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x950)))

  //Register : MAC_CTRL_6
  //This register is used to configure the internal buffer configuration.
# define ADR_ETHSW_MAC_PDI_6_MAC_CTRL_6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x951)))

  //Register : MAC_BUFST
  //This register is used to indicate the internal buffer status.
# define ADR_ETHSW_MAC_PDI_6_MAC_BUFST	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x952)))

  //Register : MAC_TESTEN
  //This register is used to select MAC-related test functions.
# define ADR_ETHSW_MAC_PDI_6_MAC_TESTEN	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0x953)))

  //Register : FDMA_CTRL
  //This register controls global functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PDI_FDMA_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA40)))

  //Register : FDMA_STETYPE
  //This register defines the Ethertype value to be used for egress frames that shall carry the special tag.
# define ADR_ETHSW_FDMA_PDI_FDMA_STETYPE	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA41)))

  //Register : FDMA_VTETYPE
  //This register defines the Ethertype value to be used for egress frames that shall carry a VLAN tag.
# define ADR_ETHSW_FDMA_PDI_FDMA_VTETYPE	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA42)))

  //Register : FDMA_STAT_0
  //This register displays status information of the Fetch DMA.
# define ADR_ETHSW_FDMA_PDI_FDMA_STAT_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA43)))

  //Register : FDMA_IER
  //This register is used to enable or disable global FDMA interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_FDMA_PDI_FDMA_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA44)))

  //Register : FDMA_ISR
  //This register provides interrupt status summary of all port-related FDMA interrupts (see the FDMA_PISR_n registers).
  //As long as at least one of the port's individual interrupt bits is active, the port interrupt status bit of the related port is set.
  //If all interrupts of a port are inactive (cleared), the related port interrupt status bit is cleared.
# define ADR_ETHSW_FDMA_PDI_FDMA_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA45)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA80)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA81)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA82)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA83)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA84)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_0_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA85)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA86)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA87)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA88)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA89)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8A)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_1_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8B)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8C)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8D)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8E)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA8F)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA90)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_2_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA91)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA92)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA93)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA94)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA95)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA96)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_3_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA97)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA98)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA99)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9A)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9B)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9C)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_4_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9D)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9E)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xA9F)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA0)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA1)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA2)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_5_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA3)))

  //Register : FDMA_PCTRL
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA4)))

  //Register : FDMA_PRIO
  //This register controls per-port functions of the Fetch DMA.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA5)))

  //Register : FDMA_PSTAT0
  //This register provides FDMA status information per port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA6)))

  //Register : FDMA_PSTAT1
  //This register the FDMA status, related to a port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA7)))

  //Register : FDMA_TSTAMP0
  //This register holds the lower part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA8)))

  //Register : FDMA_TSTAMP1
  //This register holds the higher part of the last egress time stamp used on this port.
# define ADR_ETHSW_FDMA_PORT_PDI_6_FDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xAA9)))

  //Register : SDMA_CTRL
  //This register controls global functions of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_CTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB40)))

  //Register : SDMA_FCTHR1
  //This register indicates the value of THR1, used to stop the back-pressure (flow control) .
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 1 standard MTU for 7 ports is available before the flow control generated again.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB41)))

  //Register : SDMA_FCTHR2
  //This register indicates the value of THR2, used to start the back-pressure (flow control) for non-conforming ports.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 2 standard MTUs for 7 ports are available for the flow control latency.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB42)))

  //Register : SDMA_FCTHR3
  //This register indicates the value of THR3, used to start the back-pressure (flow control) for all ports that use this threshold.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 2 standard MTUs for 7 ports are available for the flow control latency.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR3	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB43)))

  //Register : SDMA_FCTHR4
  //This register indicates the value of THR4, used to start the back-pressure (flow control) for all ports that use this threshold.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting makes sure that at least 2 standard MTUs for 7 ports are available for the flow control latency.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR4	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB44)))

  //Register : SDMA_FCTHR5
  //This register indicates the value of THR5, used to control the tail drop function if the frame buffer is full.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting assumes tail-drop when buffer is full.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR5	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB45)))

  //Register : SDMA_FCTHR6
  //This register indicates the value of THR6, used to control the tail drop function if the frame buffer is full.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting assumes tail-drop when buffer is full.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR6	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB46)))

  //Register : SDMA_FCTHR7
  //This register indicates the value of THR7, used to control the tail drop function if the number of available pointers (packet descriptors) is less than this threshold.
  //The value to be selected depends on the number of active ports and the maximum frame size. 
  //The default setting assumes tail-drop when buffer is full.
# define ADR_ETHSW_SDMA_PDI_SDMA_FCTHR7	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB47)))

  //Register : SDMA_STAT_0
  //This register displays status information of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_STAT_0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB48)))

  //Register : SDMA_STAT_1
  //This register displays status information of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_STAT_1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB49)))

  //Register : SDMA_STAT_2
  //This register displays status information of the Store DMA.
# define ADR_ETHSW_SDMA_PDI_SDMA_STAT_2	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB4A)))

  //Register : SDMA_IER
  //This register enables the activation of interrupts.
  //If disabled, the interrupt status bit can be set by the hardware but does not contribute to a hardware interrupt indication.
# define ADR_ETHSW_SDMA_PDI_SDMA_IER	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB4B)))

  //Register : SDMA_ISR
  //This register indicates interrupts caused by the Store DMA.
  //An interrupt status bit is cleared by writing a 1 to the related bit position, multiple bits can be cleared by a single write access.
# define ADR_ETHSW_SDMA_PDI_SDMA_ISR	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xB4C)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC0)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC1)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC2)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC3)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC4)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_0_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC5)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC6)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC7)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC8)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBC9)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCA)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_1_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCB)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCC)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCD)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCE)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBCF)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD0)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_2_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD1)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD2)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD3)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD4)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD5)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD6)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_3_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD7)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD8)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBD9)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDA)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDB)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDC)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_4_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDD)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDE)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBDF)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE0)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE1)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE2)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_5_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE3)))

  //Register : SDMA_PCTRL
  //This register defines the SDMA functions per ingress port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PCTRL	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE4)))

  //Register : SDMA_PRIO
  //This register controls per-port functions of the Store DMA.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PRIO	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE5)))

  //Register : SDMA_PSTAT0
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PSTAT0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE6)))

  //Register : SDMA_PSTAT1
  //This register the SDMA status, related to a port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_PSTAT1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE7)))

  //Register : SDMA_TSTAMP0
  //This register holds the lower part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_TSTAMP0	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE8)))

  //Register : SDMA_TSTAMP1
  //This register holds the higher part of the last ingress time stamp used on this port.
# define ADR_ETHSW_SDMA_PORT_PDI_6_SDMA_TSTAMP1	ADDR_MACRO_ETHSW_PDI(ADDR_BASE_ETHSW_PDI+(ADDR_MULT_ETHSW_PDI*(0xBE9)))

//Register File : ETHSW_MDIO_PDI
//This chapter provides the registers that are needed to control the MDIO Master Interface and global top level parameters.
# define ADR_ETHSW_MDIO_PDI	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC40)))

//Register File : ETHSW_MII_PDI
//This chapter provides the control registers of the xMII Interfaces.
//REMARK: 
//Selection between Port 5a and Port 5b: 
//If Port 5 XMIIMODE is programmed to RGMII the external Port 5a is selected else the internal Port 5b is selected
# define ADR_ETHSW_MII_PDI	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC76)))

//Register File : ETHSW_PMAC_PDI
//This chapter provides the registers that are needed to control the PMAC.
# define ADR_ETHSW_PMAC_PDI	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC2)))


//***********************************************************
//Register Address 
//***********************************************************

//Register : GLOB_CTRL
//This register is used to control global Switch Subsystem functions.
# define ADR_ETHSW_MDIO_PDI_GLOB_CTRL	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC40)))

//Register : MDIO_CTRL
//This register is used to access devices that are connected to the serial MDIO master interface, internally or externally.
//Each write access to this register starts a transmission, either read or write.
# define ADR_ETHSW_MDIO_PDI_MDIO_CTRL	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC48)))

//Register : MDIO_READ
//This register is used to read back data across the serial MDIO master interface, internally or externally.
# define ADR_ETHSW_MDIO_PDI_MDIO_READ	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC49)))

//Register : MDIO_WRITE
//This register is used to write data across the serial MDIO master interface, internally or externally.
# define ADR_ETHSW_MDIO_PDI_MDIO_WRITE	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC4A)))

//Register : MDC_CFG_0
//This register is used to control the MDC clock output and polling state machine.
# define ADR_ETHSW_MDIO_PDI_MDC_CFG_0	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC4B)))

//Register : MDC_CFG_1
//This register is used to configure clocking rate for the MDIO master interfaces.
# define ADR_ETHSW_MDIO_PDI_MDC_CFG_1	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC4C)))

//Register : PHY_ADDR_5
//This register is used to define the phy address of the port.
# define ADR_ETHSW_MDIO_PDI_PHY_ADDR_5	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC50)))

//Register : PHY_ADDR_4
//This register is used to define the phy address of the port.
# define ADR_ETHSW_MDIO_PDI_PHY_ADDR_4	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC51)))

//Register : PHY_ADDR_3
//This register is used to define the phy address of the port.
# define ADR_ETHSW_MDIO_PDI_PHY_ADDR_3	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC52)))

//Register : PHY_ADDR_2
//This register is used to define the phy address of the port.
# define ADR_ETHSW_MDIO_PDI_PHY_ADDR_2	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC53)))

//Register : PHY_ADDR_1
//This register is used to define the phy address of the port.
# define ADR_ETHSW_MDIO_PDI_PHY_ADDR_1	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC54)))

//Register : PHY_ADDR_0
//This register is used to define the phy address of the port.
# define ADR_ETHSW_MDIO_PDI_PHY_ADDR_0	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC55)))

//Register : MII_CFG_0
//This register controls the settings of the xMII Interface.
# define ADR_ETHSW_MII_PDI_MII_CFG_0	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC76)))

//Register : PCDU_0
//This register controls the settings of the receive and transmit clock delay (used for RGMII mode only).
# define ADR_ETHSW_MII_PDI_PCDU_0	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC77)))

//Register : MII_CFG_1
//This register controls the settings of the xMII Interface.
# define ADR_ETHSW_MII_PDI_MII_CFG_1	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC78)))

//Register : PCDU_1
//This register controls the settings of the receive and transmit clock delay (used for RGMII mode only).
# define ADR_ETHSW_MII_PDI_PCDU_1	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC79)))

//Register : MII_CFG_2
//This register controls the settings of the xMII Interface.
# define ADR_ETHSW_MII_PDI_MII_CFG_2	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC7A)))

//Register : MII_CFG_3
//This register controls the settings of the xMII Interface.
# define ADR_ETHSW_MII_PDI_MII_CFG_3	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC7C)))

//Register : MII_CFG_4
//This register controls the settings of the xMII Interface.
# define ADR_ETHSW_MII_PDI_MII_CFG_4	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC7E)))

//Register : MII_CFG_5
//This register controls the settings of the xMII Interface.
# define ADR_ETHSW_MII_PDI_MII_CFG_5	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC80)))

//Register : PCDU_5
//This register controls the settings of the receive and transmit clock delay (used for RGMII mode only).
# define ADR_ETHSW_MII_PDI_PCDU_5	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xC81)))

//Register : PMAC_HD_CTL
//This register provides the header control parameters for PMAC.
# define ADR_ETHSW_PMAC_PDI_PMAC_HD_CTL	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC2)))

//Register : PMAC_TL
//This register provides the header control parameters for PMAC.
# define ADR_ETHSW_PMAC_PDI_PMAC_TL	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC3)))

//Register : PMAC_SA1
//This register holds the upper 16-bits of the PMAC source address.
# define ADR_ETHSW_PMAC_PDI_PMAC_SA1	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC4)))

//Register : PMAC_SA2
//This register holds the middle 16-bits of the PMAC source address.
# define ADR_ETHSW_PMAC_PDI_PMAC_SA2	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC5)))

//Register : PMAC_SA3
//This register holds the lower 16-bits of the PMAC source address.
# define ADR_ETHSW_PMAC_PDI_PMAC_SA3	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC6)))

//Register : PMAC_DA1
//This register holds the upper 16-bits of the PMAC destination address.
# define ADR_ETHSW_PMAC_PDI_PMAC_DA1	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC7)))

//Register : PMAC_DA2
//This register holds the middle 16-bits of the PMAC destination address.
# define ADR_ETHSW_PMAC_PDI_PMAC_DA2	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC8)))

//Register : PMAC_DA3
//This register holds the lower 16-bits of the PMAC destination address.
# define ADR_ETHSW_PMAC_PDI_PMAC_DA3	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCC9)))

//Register : PMAC_VLAN
//This register provides the VLAN parameters for PMAC.
# define ADR_ETHSW_PMAC_PDI_PMAC_VLAN	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCCA)))

//Register : PMAC_TX_IPG
//This register holds value of the IPG in TX direction.
# define ADR_ETHSW_PMAC_PDI_PMAC_TX_IPG	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCCB)))

//Register : PMAC_RX_IPG
//This register holds value of the IPG in RX direction.
# define ADR_ETHSW_PMAC_PDI_PMAC_RX_IPG	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCCC)))

//Register : PMAC_ST_ETYPE
//This register holds the Ethertype value of the special tag.
# define ADR_ETHSW_PMAC_PDI_PMAC_ST_ETYPE	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCCD)))

//Register : PMAC_EWAN
//This register holds Ethernet WAN Group.
# define ADR_ETHSW_PMAC_PDI_PMAC_EWAN	ADDR_MACRO_ETHSW_VR9_PDI(ADDR_BASE_ETHSW_VR9_PDI+(ADDR_MULT_ETHSW_VR9_PDI*(0xCCE)))


/******************************************************************************************************************************/
/* VR9 SWITCH Register */
#define VR9_ETHSW_SS_BASE_ADDR                  (0xBE108000)



#define VR9_ETHSW_TOP   (VR9_ETHSW_SS_BASE_ADDR+( 0xC40 * 4) )

#define VR9_ETHSW_MAC   (VR9_ETHSW_SS_BASE_ADDR+(0x900*4))


#define VR9_ETHSW_SWRES         (VR9_ETHSW_SS_BASE_ADDR )
/*Hardware reset, reset all HW modules except for register settings  */
#define VR9_ETHSW_SWRES_R1      0x1     /*Bit< 1 >*/
/*Reset all registers */
#define VR9_ETHSW_SWRES_R0      0x0     /*Bit< 0 >*/

#define VR9_ETHSW_CLK           (VR9_ETHSW_SS_BASE_ADDR+ (0x1 * 4) )

#define VR9_ETHSW_BM_RAM_VAL_3  (VR9_ETHSW_SS_BASE_ADDR+ (0x40 * 4) )
#define VR9_ETHSW_BM_RAM_VAL_2  (VR9_ETHSW_SS_BASE_ADDR+ (0x41 * 4) )
#define VR9_ETHSW_BM_RAM_VAL_1  (VR9_ETHSW_SS_BASE_ADDR+ (0x42 * 4) )
#define VR9_ETHSW_BM_RAM_VAL_0  (VR9_ETHSW_SS_BASE_ADDR+ (0x43 * 4) )
#define VR9_ETHSW_BM_RAM_ADDR   (VR9_ETHSW_SS_BASE_ADDR+ (0x44 * 4) )
#define VR9_ETHSW_BM_RAM_CTRL   (VR9_ETHSW_SS_BASE_ADDR+ (0x45 * 4) )

#define VR9_ETHSW_BM_FSQM_GCTRL (VR9_ETHSW_SS_BASE_ADDR+ (0x46 * 4) )
#define VR9_ETHSW_BM_CONS_SEG   (VR9_ETHSW_SS_BASE_ADDR+ (0x47 * 4) )
#define VR9_ETHSW_BM_CONS_PKT   (VR9_ETHSW_SS_BASE_ADDR+ (0x48 * 4) )

#define VR9_ETHSW_BM_GCTRL      (VR9_ETHSW_SS_BASE_ADDR+ (0x49 * 4) )
#define VR9_ETHSW_BM_GCTRL_R_SRES(val)  ((val & 0x1 ) << 4 )
#define VR9_ETHSW_BM_QUEUE_GCTRL      (VR9_ETHSW_SS_BASE_ADDR+ (0x4A * 4) )

/*Buffer manager per port registrs*/
#define VR9_ETHSW_BM_PCFG       (VR9_ETHSW_SS_BASE_ADDR+ (0x80 * 4) )
#define VR9_ETHSW_BM_PCFG_CNTEN(val)    (((val & 0x1) << 0 ) )
#define VR9_ETHSW_BM_RMON_CTRL  (VR9_ETHSW_SS_BASE_ADDR+ (0x81 * 4) )

/*Rate shaper */

#define VR9_ETHSW_BM_QUEUE_PQM_DP        (VR9_ETHSW_SS_BASE_ADDR+ (0x100 * 4) )
#define VR9_ETHSW_BM_QUEUE_PQM_RS        (VR9_ETHSW_SS_BASE_ADDR+ (0x101 * 4) )
#define VR9_ETHSW_BM_SHAPER_RS_CTRL      (VR9_ETHSW_SS_BASE_ADDR+ (0x140 * 4) )
#define VR9_ETHSW_BM_SHAPER_RS_CBS       (VR9_ETHSW_SS_BASE_ADDR+ (0x141 * 4) )
#define VR9_ETHSW_BM_SHAPER_RS_IBS       (VR9_ETHSW_SS_BASE_ADDR+ (0x142 * 4) )
#define VR9_ETHSW_BM_SHAPER_RS_CIR_EXP   (VR9_ETHSW_SS_BASE_ADDR+ (0x143 * 4) )
#define VR9_ETHSW_BM_SHAPER_RS_CIR_MANT   (VR9_ETHSW_SS_BASE_ADDR+ (0x144 * 4) )

/* Metering */


#define VR9_ETHSW_PCE_TCM_CTRL          (VR9_ETHSW_SS_BASE_ADDR+(0x580*4))

#define VR9_ETHSW_PCE_TCM_STAT              (VR9_ETHSW_SS_BASE_ADDR+(0x581*4))
#define VR9_ETHSW_PCE_TCM_CBS      (VR9_ETHSW_SS_BASE_ADDR+(0x582*4))
#define VR9_ETHSW_PCE_TCM_EBS      (VR9_ETHSW_SS_BASE_ADDR+(0x583*4))
#define VR9_ETHSW_PCE_TCM_IBS      (VR9_ETHSW_SS_BASE_ADDR+(0x584*4))
#define VR9_ETHSW_PCE_TCM_CIR_MANT  (VR9_ETHSW_SS_BASE_ADDR+(0x585*4))
#define VR9_ETHSW_PCE_TCM_CIR_EXP   (VR9_ETHSW_SS_BASE_ADDR+(0x586*4))


/*WRED */
#define VR9_ETHSW_BM_WRED_RTH_0         (VR9_ETHSW_SS_BASE_ADDR+(0x04B*4))
#define VR9_ETHSW_BM_WRED_RTH_1         (VR9_ETHSW_SS_BASE_ADDR+(0x04C*4))
#define VR9_ETHSW_BM_WRED_YTH_0         (VR9_ETHSW_SS_BASE_ADDR+(0x04D*4))
#define VR9_ETHSW_BM_WRED_YTH_1         (VR9_ETHSW_SS_BASE_ADDR+(0x04E*4))
#define VR9_ETHSW_BM_WRED_GTH_0         (VR9_ETHSW_SS_BASE_ADDR+(0x04F*4))
#define VR9_ETHSW_BM_WRED_GTH_1         (VR9_ETHSW_SS_BASE_ADDR+(0x050*4))

/* MAC frame length register*/
#define VR9_ETHSW_MAC_FLEN      ( VR9_ETHSW_SS_BASE_ADDR + (0x8C5 *4))
/* fetch DMA port control */
#define VR9_ETHSW_FDMA_PCTRL_6          ( VR9_ETHSW_SS_BASE_ADDR + (0xAA4 *4))

/* SDMA registers */
#define VR9_ETHSW_SDMA_CTRL    ( VR9_ETHSW_SS_BASE_ADDR + (0xB40 *4))
#define VR9_ETHSW_SDMA_FCTHR1    ( VR9_ETHSW_SS_BASE_ADDR + (0xB41 *4))
#define VR9_ETHSW_SDMA_FCTHR2    ( VR9_ETHSW_SS_BASE_ADDR + (0xB42 *4))
#define VR9_ETHSW_SDMA_FCTHR3    ( VR9_ETHSW_SS_BASE_ADDR + (0xB43 *4))
#define VR9_ETHSW_SDMA_FCTHR4    ( VR9_ETHSW_SS_BASE_ADDR + (0xB44 *4))
#define VR9_ETHSW_SDMA_FCTHR5    ( VR9_ETHSW_SS_BASE_ADDR + (0xB45 *4))
#define VR9_ETHSW_SDMA_FCTHR6    ( VR9_ETHSW_SS_BASE_ADDR + (0xB46 *4))
#define VR9_ETHSW_SDMA_FCTHR7    ( VR9_ETHSW_SS_BASE_ADDR + (0xB47 *4))
#define VR9_ETHSW_SDMA_STAT0    ( VR9_ETHSW_SS_BASE_ADDR + (0xB48 *4))
#define VR9_ETHSW_SDMA_STAT1    ( VR9_ETHSW_SS_BASE_ADDR + (0xB49 *4))
#define VR9_ETHSW_SDMA_STAT2    ( VR9_ETHSW_SS_BASE_ADDR + (0xB4A *4))




/* Port Map Register */
#define VR9_ETHSW_PCE_PMAP_1    ( VR9_ETHSW_SS_BASE_ADDR + (0x453 *4))
#define VR9_ETHSW_PCE_PMAP_2    ( VR9_ETHSW_SS_BASE_ADDR + (0x454 *4))
#define VR9_ETHSW_PCE_PMAP_3    ( VR9_ETHSW_SS_BASE_ADDR + (0x455 *4))
#define VR9_ETHSW_PCE_GCTRL_0   ( VR9_ETHSW_SS_BASE_ADDR + (0x456 *4))
#define VR9_ETHSW_PCE_GCTRL_1   ( VR9_ETHSW_SS_BASE_ADDR + (0x457 *4))

/*Ethernet MAC registers */
/*MAC port status register*/
#define VR9_ETHSW_MAC_PSTAT     ( VR9_ETHSW_MAC  )
/*MAC interrupt status register*/
#define VR9_ETHSW_MAC_PISR      ( VR9_ETHSW_MAC+(0x1 *4 ))
/*MAC Interrupt enable reisgter */
#define VR9_ETHSW_MAC_PIER      ( VR9_ETHSW_MAC+(0x2 *4 ))
/*MAC control registers */
#define VR9_ETHSW_MAC_CTRL_0    ( VR9_ETHSW_MAC+(0x3 *4))
#define VR9_ETHSW_MAC_CTRL_1    ( VR9_ETHSW_MAC+(0x4 *4))
#define VR9_ETHSW_MAC_CTRL_2    ( VR9_ETHSW_MAC+(0x5 *4))
#define VR9_ETHSW_MAC_CTRL_3    ( VR9_ETHSW_MAC+(0x6 *4))
#define VR9_ETHSW_MAC_CTRL_4    ( VR9_ETHSW_MAC+(0x7 *4))
#define VR9_ETHSW_MAC_CTRL_5    ( VR9_ETHSW_MAC+(0x8 *4))
#define VR9_ETHSW_MAC_CTRL_6    ( VR9_ETHSW_MAC+(0x9 *4))

/*G<II/MII interface mode selection */
#define VR9_ETHSW_MAC_CTRL_GMII         0   /* <1:0>  interface mode selection */
#define VR9_ETHSW_MAC_CTRL_GMII_AUTO            0
#define VR9_ETHSW_MAC_CTRL_GMII_MII             1 /*MII/RMII interface mode at 10, 100 or 200 Mbit/s */
#define VR9_ETHSW_MAC_CTRL_GMII_GMII            2       /* GMII/RGMII interface mode at 1000 Mbit/s */

/*Full duplex control */
#define VR9_ETHSW_MAC_CTRL_FDUP         2 /*<3:2> full duplex control */
#define VR9_ETHSW_MAC_CTRL_FDUP_AUTO    0
#define VR9_ETHSW_MAC_CTRL_FDUP_EN      1
#define VR9_ETHSW_MAC_CTRL_FDUP_DIS     3

#define VR9_ETHSW_MAC_CTRL_FCON         4 /*<6:4> Flow control mode*/
#define VR9_ETHSW_MAC_CTRL_AUTO         0
#define VR9_ETHSW_MAC_CTRL_RX           1  /*Rx only */
#define VR9_ETHSW_MAC_CTRL_TX           2 /*Tx only */
#define VR9_ETHSW_MAC_CTRL_RXTX         3       /*Rx and Tx  */
#define VR9_ETHSW_MAC_CTRL_NONE         4       /*Disable*/

#define VR9_ETHSW_MAC_CTRL_FCS          7 /*<7> Tx Frame checksum generation */


/*MAC Rx/Tx buffer status register */
#define VR9_ETHSW_MAC_BUFST     ( VR9_ETHSW_MAC+(0xA *4))
/*MAC test enable register */
#define VR9_ETHSW_MAC_TESTEN    ( VR9_ETHSW_MAC+(0xB *4))

/*ETHSW_MDIO_PDI Registers*/
#define VR9_ETHSW_GLOB_CTRL             (VR9_ETHSW_TOP+0)
#define GLOB_CTRL_SE    15      /*Global switch macro enable*/
#define GLOB_CTRL_HWRES 1       /*Global Hardware reset */
#define GLOB_CTRL_SWRES 0       /*Global Software reset */

/*Switch Parse and Classification Engine registers*/
#define VR9_ETHSW_PCE_PCTRL_0           (VR9_ETHSW_SS_BASE_ADDR+(0x480*4))
#define VR9_ETHSW_PCE_PCTRL_1           (VR9_ETHSW_SS_BASE_ADDR+(0x481*4))
#define VR9_ETHSW_PCE_PCTRL_2           (VR9_ETHSW_SS_BASE_ADDR+(0x482*4))
#define VR9_ETHSW_PCE_PCTRL_3           (VR9_ETHSW_SS_BASE_ADDR+(0x483*4))
#define VR9_ETHSW_PCE_WOL_CTRL          (VR9_ETHSW_SS_BASE_ADDR+(0x484*4))
#define VR9_ETHSW_PCE_VCTRL             (VR9_ETHSW_SS_BASE_ADDR+(0x485*4))
#define VR9_ETHSW_PCE_DEFPVID           (VR9_ETHSW_SS_BASE_ADDR+(0x486*4))
#define VR9_ETHSW_PCE_PSTAT             (VR9_ETHSW_SS_BASE_ADDR+(0x487*4))
#define VR9_ETHSW_PCE_PIER              (VR9_ETHSW_SS_BASE_ADDR+(0x488*4))
#define VR9_ETHSW_PCE_PISR              (VR9_ETHSW_SS_BASE_ADDR+(0x489*4))

//#define VR9_ETHSW_SDMA_CTRL             (VR9_ETHSW_SS_BASE_ADDR+(0xB40*4))
//#define VR9_ETHSW_SDMA_FCTHR5           (VR9_ETHSW_SS_BASE_ADDR+(0xB45*4))
//#define VR9_ETHSW_SDMA_FCTHR6           (VR9_ETHSW_SS_BASE_ADDR+(0xB46*4))
#define VR9_ETHSW_FDMA_PCTRL_3          (VR9_ETHSW_SS_BASE_ADDR+(0xA92*4))
#define VR9_ETHSW_MDIO_CTRL             ( VR9_ETHSW_TOP + (0x8 * 4))
#define VR9_ETHSW_MDIO_READ             ( VR9_ETHSW_TOP + (0x9 * 4))
#define VR9_ETHSW_MDIO_WRITE            ( VR9_ETHSW_TOP + (0xa * 4))

#define VR9_ETHSW_MDC_CFG_0             ( VR9_ETHSW_TOP + (0xb  * 4))
#define VR9_ETHSW_CFG_0_PEN_0           0       /*Polling state machine enable */
#define VR9_ETHSW_CFG_0_PEN_1           1       /*Polling state machine enable */
#define VR9_ETHSW_CFG_0_PEN_2           2       /*Polling state machine enable */
#define VR9_ETHSW_CFG_0_PEN_3           3       /*Polling state machine enable */
#define VR9_ETHSW_CFG_0_PEN_4           4       /*Polling state machine enable */
#define VR9_ETHSW_CFG_0_PEN_5           5       /*Polling state machine enable */

#define VR9_ETHSW_MDC_CFG_1             ( VR9_ETHSW_TOP  + (0xc * 4))
#define VR9_ETHSW_CFG_1_RES             15      /*MDIO Hardware Reset*/
#define VR9_ETHSW_CFG_1_MCEN            8       /*MDC clock enable*/
#define VR9_ETHSW_CFG_1_FREQ            0       /*MDIO interface clock rate*/

#define VR9_ETHSW_PHY_ADDR_5            ( VR9_ETHSW_TOP  + (0x10 * 4))
#define VR9_ETHSW_PHY_ADDR_4            ( VR9_ETHSW_TOP  + (0x11 * 4))
#define VR9_ETHSW_PHY_ADDR_3            ( VR9_ETHSW_TOP  + (0x12 * 4))
#define VR9_ETHSW_PHY_ADDR_2            ( VR9_ETHSW_TOP  + (0x13 * 4))
#define VR9_ETHSW_PHY_ADDR_1            ( VR9_ETHSW_TOP  + (0x14 * 4))
#define VR9_ETHSW_PHY_ADDR_0            ( VR9_ETHSW_TOP  + (0x15 * 4))

#define VR9_ETHSW_MDIO_STAT_0           ( VR9_ETHSW_TOP  + (0x16 * 4))      
#define VR9_ETHSW_MDIO_STAT_1           ( VR9_ETHSW_TOP  + (0x17 * 4))
#define VR9_ETHSW_MDIO_STAT_2           ( VR9_ETHSW_TOP  + (0x18 * 4))
#define VR9_ETHSW_MDIO_STAT_3           ( VR9_ETHSW_TOP  + (0x19 * 4))
#define VR9_ETHSW_MDIO_STAT_4           ( VR9_ETHSW_TOP  + (0x1A * 4))
#define VR9_ETHSW_MDIO_STAT_5           ( VR9_ETHSW_TOP  + (0x1B * 4))

#define VR9_ETHSW_ANEG_EEE_0            ( VR9_ETHSW_TOP  + (0x1C * 4))
#define VR9_ETHSW_ANEG_EEE_1            ( VR9_ETHSW_TOP  + (0x1D * 4))
#define VR9_ETHSW_ANEG_EEE_2            ( VR9_ETHSW_TOP  + (0x1E * 4))
#define VR9_ETHSW_ANEG_EEE_3            ( VR9_ETHSW_TOP  + (0x1F * 4))
#define VR9_ETHSW_ANEG_EEE_4            ( VR9_ETHSW_TOP  + (0x20 * 4))
#define VR9_ETHSW_ANEG_EEE_5            ( VR9_ETHSW_TOP  + (0x21 * 4))


/*ETHSW_MII_PDI Registers*/
#define VR9_ETHSW_MII_CFG_0             ( VR9_ETHSW_TOP + (0x36 * 4))
#define VR9_ETHSW_PCDU_0                ( VR9_ETHSW_TOP + (0x37 * 4))
#define VR9_ETHSW_MII_CFG_1             ( VR9_ETHSW_TOP + (0x38 * 4))
#define VR9_ETHSW_PCDU_1                ( VR9_ETHSW_TOP + (0x39 * 4))
#define VR9_ETHSW_MII_CFG_2             ( VR9_ETHSW_TOP + (0x3a * 4))
#define VR9_ETHSW_MII_CFG_3             ( VR9_ETHSW_TOP + (0x3c * 4))
#define VR9_ETHSW_MII_CFG_4             ( VR9_ETHSW_TOP + (0x3e * 4))
#define VR9_ETHSW_MII_CFG_5             ( VR9_ETHSW_TOP + (0x40 * 4))
#define VR9_ETHSW_PCDU_5                ( VR9_ETHSW_TOP + (0x41 * 4))

#define VR9_ETHSW_MII_CFG_RES           15      /*Hardware reset */
#define VR9_ETHSW_MII_CFG_EN            14      /*xMII interface enable*/
#define VR9_ETHSW_MII_CFG_RMII          7       /* RMII Ref clock direction input(0)/output(1) */
#define VR9_ETHSW_MII_CFG_MIIRATE       4       /*<6:4> xMII port interface clock rate bit position*/
#define VR9_ETHSW_MII_CFG_MIIRATE_M2P5  0x0     /*xMII port interface clock rate 2.5MHz */
#define VR9_ETHSW_MII_CFG_MIIRATE_M25   0x1     /*xMII port interface clock rate 25MHz */
#define VR9_ETHSW_MII_CFG_MIIRATE_M125  0x2     /*xMII port interface clock rate 125MHz */
#define VR9_ETHSW_MII_CFG_MIIRATE_M50   0x3     /*xMII port interface clock rate 50MHz */
#define VR9_ETHSW_MII_CFG_MIIRATE_AUTO  0x4     /*xMII port interface clock rate, speed used from autopolling */

#define VR9_ETHSW_MII_CFG_MIIMODE       0x0     /*<3:0> xMII  interface mode */
#define VR9_ETHSW_MII_CFG_MIIMODE_MIIM  0x0     /*MII MAC mode */
#define VR9_ETHSW_MII_CFG_MIIMODE_MIIP  0x1     /*MII PHY  mode */
#define VR9_ETHSW_MII_CFG_MIIMODE_RMIIM 0x2     /*RMII MAC mode */
#define VR9_ETHSW_MII_CFG_MIIMODE_RMIIP 0x3     /*RMII PHY mode */
#define VR9_ETHSW_MII_CFG_MIIMODE_RGMII 0x4     /*RGMII mode */

#define VR9_ETHSW_PCDU_RXSEL_CLK        12      /*<13:12>input clock selection for Receive PCDU */
#define VR9_ETHSW_PCDU_RXSEL_CLK_AUTO   0x0     /*Auto, selection of input clock depends on speed*/
#define VR9_ETHSW_PCDU_RXSEL_CLK_RXCLK  0x1     /*input clock is RXCLK*/
#define VR9_ETHSW_PCDU_RXSEL_CLK_CLKREF 0x2     /*input clock is CLKREF (125MHz)*/

#define VR9_ETHSW_PCDU_RXINIT   11      /*Reset of Receive PCDU*/
#define VR9_ETHSW_PCDU_RXPD     10      /*Power down of Receive PCDU*/
#define VR9_ETHSW_PCDU_RXDLY    7       /*<9:7> Configure receive clock delay*/


#define VR9_ETHSW_PCDU_TXSEL_CLK        5       /*<6:5>input clock selection for Transmit PCDU */
#define VR9_ETHSW_PCDU_TXSEL_CLK_AUTO   0x0     /*Auto, selection of input clock depends on speed*/
#define VR9_ETHSW_PCDU_TXSEL_CLK_RXCLK  0x1     /*input clock is TXCLK*/
#define VR9_ETHSW_PCDU_TXSEL_CLK_CLKREF 0x2     /*input clock is CLKREF (125MHz)*/

#define VR9_ETHSW_PCDU_TXINIT   4       /*Reset of Transmit PCDU*/
#define VR9_ETHSW_PCDU_TXPD     3       /*Power down of Transmit PCDU*/
#define VR9_ETHSW_PCDU_TXDLY    0       /*<2:0> Configure receive clock delay*/

/*ETHSW_PMAC_PDI Registers*/
#define VR9_ETHSW_PMAC_HD_CTL           ( VR9_ETHSW_TOP + (0x82 * 4))
#define VR9_ETHSW_PMAC_HD_CTL_RST       8  /* Remove special tag */
#define VR9_ETHSW_PMAC_HD_CTL_AST       7  /* Add special tag */
#define VR9_ETHSW_PMAC_HD_CTL_RXSH      6  /* Add status header from DMA to PMAC */
#define VR9_ETHSW_PMAC_HD_CTL_RL2       5  /* Remove Layer 2 header */
#define VR9_ETHSW_PMAC_HD_CTL_RC        4  /* Remove CRC  for packets from PMAC to DMA*/
#define VR9_ETHSW_PMAC_HD_CTL_AS        3  /* Add status header from PMAC to DMA*/
#define VR9_ETHSW_PMAC_HD_CTL_AC        2  /* Add  CRC  for packets from DMA to PMAC*/
#define VR9_ETHSW_PMAC_HD_CTL_TAG       1  /* Add  Tag, enable the VLAN tag to packets comming from DMA to PMAC and going to the switch */
#define VR9_ETHSW_PMAC_HD_CTL_ADD       0  /* Add  header  tag for packets comming from DMA to PMAC and going to the swicth*/

#define VR9_ETHSW_PMAC_TL               ( VR9_ETHSW_TOP + (0x83 * 4))
#define VR9_ETHSW_PMAC_SA1              ( VR9_ETHSW_TOP + (0x84 * 4))
#define VR9_ETHSW_PMAC_SA2              ( VR9_ETHSW_TOP + (0x85 * 4))
#define VR9_ETHSW_PMAC_SA3              ( VR9_ETHSW_TOP + (0x86 * 4))
#define VR9_ETHSW_PMAC_DA1              ( VR9_ETHSW_TOP + (0x87 * 4))
#define VR9_ETHSW_PMAC_DA2              ( VR9_ETHSW_TOP + (0x88 * 4))
#define VR9_ETHSW_PMAC_DA3              ( VR9_ETHSW_TOP + (0x89 * 4))
#define VR9_ETHSW_PMAC_VLAN             ( VR9_ETHSW_TOP + (0x8a * 4))
#define VR9_ETHSW_PMAC_VLAN_PRI         13      /*<15:13> VLAN priority */
#define VR9_ETHSW_PMAC_VLAN_CFI         12      /* CFI of the interserted VLAN tag */
#define VR9_ETHSW_PMAC_VLAN_VLAN_ID     0       /* <11:0> VLAN id */

#define VR9_ETHSW_PMAC_RX_IPG           ( VR9_ETHSW_TOP + (0x8b * 4))
#define VR9_ETHSW_PMAC_ST_ETYPE         ( VR9_ETHSW_TOP + (0x8c * 4))
#define VR9_ETHSW_PMAC_EWAN             ( VR9_ETHSW_TOP + (0x8d * 4))

#define PDI_DCDC_BASE                 0xBF106A00
#define PDI_DCDC_PID_HI_B0            ((volatile u8*)(PDI_DCDC_BASE+ 0x0))
#define PDI_DCDC_PID_LO_B0            ((volatile u8*)(PDI_DCDC_BASE+ 0x01))
#define PDI_DCDC_PID_HI_B1            ((volatile u8*)(PDI_DCDC_BASE+ 0x02))
#define PDI_DCDC_PID_LO_B1            ((volatile u8*)(PDI_DCDC_BASE+ 0x03))
#define PDI_DCDC_PID_HI_B2            ((volatile u8*)(PDI_DCDC_BASE+ 0x04))
#define PDI_DCDC_PID_LO_B2            ((volatile u8*)(PDI_DCDC_BASE+ 0x05))
#define PDI_DCDC_CLK_SET0             ((volatile u8*)(PDI_DCDC_BASE+ 0x06)) 
#define PDI_DCDC_CLK_SET1             ((volatile u8*)(PDI_DCDC_BASE+ 0x07))
#define PDI_DCDC_PWM0                 ((volatile u8*)(PDI_DCDC_BASE+ 0x08))
#define PDI_DCDC_PWM1                 ((volatile u8*)(PDI_DCDC_BASE+ 0x09)) 
#define PDI_DCDC_BIAS_VREG            ((volatile u8*)(PDI_DCDC_BASE+ 0x0A)) 
#define PDI_DCDC_DIG_REF              ((volatile u8*)(PDI_DCDC_BASE+ 0x0B)) 
#define PDI_DCDC_GENERAL              ((volatile u8*)(PDI_DCDC_BASE+ 0x0C))
#define PDI_DCDC_ADC0                 ((volatile u8*)(PDI_DCDC_BASE+ 0x0D))
#define PDI_DCDC_ADC1                 ((volatile u8*)(PDI_DCDC_BASE+ 0x0E))
#define PDI_DCDC_ADC2                 ((volatile u8*)(PDI_DCDC_BASE+ 0x0F))
#define PDI_DCDC_CONF_TEST_ANA        ((volatile u8*)(PDI_DCDC_BASE+ 0x10)) 
#define PDI_DCDC_CONF_TEST_DIG        ((volatile u8*)(PDI_DCDC_BASE+ 0x11)) 
#define PDI_DCDC_DCDC_STATUS          ((volatile u8*)(PDI_DCDC_BASE+ 0x12)) 
#define PDI_DCDC_PID_STATUS           ((volatile u8*)(PDI_DCDC_BASE+ 0x13))
#define PDI_DCDC_DUTY_CYCLE           ((volatile u8*)(PDI_DCDC_BASE+ 0x14))
#define PDI_DCDC_NON_OV_DELAY         ((volatile u8*)(PDI_DCDC_BASE+ 0x15))
#define PDI_DCDC_ANALOG_GAIN          ((volatile u8*)(PDI_DCDC_BASE+ 0x16))
#define PDI_DCDC_DUTY_CYCLE_MAX_SAT   ((volatile u8*)(PDI_DCDC_BASE+ 0x17))
#define PDI_DCDC_DUTY_CYCLE_MIN_SAT   ((volatile u8*)(PDI_DCDC_BASE+ 0x18))
#define PDI_DCDC_DUTY_CYCLE_MAX       ((volatile u8*)(PDI_DCDC_BASE+ 0x19))
#define PDI_DCDC_DUTY_CYCLE_MIN       ((volatile u8*)(PDI_DCDC_BASE+ 0x1A))
#define PDI_DCDC_ERROR_MAX            ((volatile u8*)(PDI_DCDC_BASE+ 0x1B))
#define PDI_DCDC_ERROR_READ           ((volatile u8*)(PDI_DCDC_BASE+ 0x1C))
#define PDI_DCDC_DELAY_DEGLITCH       ((volatile u8*)(PDI_DCDC_BASE+ 0x1D)) 
#define PDI_DCDC_LATCH_CONTROL        ((volatile u8*)(PDI_DCDC_BASE+ 0x1E))
#define PDI_DCDC_OSC_CONF             ((volatile u8*)(PDI_DCDC_BASE+ 0x100))
#define PDI_DCDC_OSC_STATUS           ((volatile u8*)(PDI_DCDC_BASE+ 0x101))

/***********************************************************************/
#define BSP_REG32(addr)                 *((volatile u32 *)(addr))
#define BSP_REG16(addr)                 *((volatile u16 *)(addr))
#define BSP_REG8(addr)                  *((volatile u8 *)(addr))
#define REG32(addr)                 *((volatile u32 *)(addr))
#define REG16(addr)                 *((volatile u16 *)(addr))
#define REG8(addr)                  *((volatile u8 *)(addr))
/***********************************************************************/
#endif //BSP_H 
