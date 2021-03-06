.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* Rx */
.set Rx__0__INTTYPE, CYREG_PICU12_INTTYPE6
.set Rx__0__MASK, 0x40
.set Rx__0__PC, CYREG_PRT12_PC6
.set Rx__0__PORT, 12
.set Rx__0__SHIFT, 6
.set Rx__AG, CYREG_PRT12_AG
.set Rx__BIE, CYREG_PRT12_BIE
.set Rx__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Rx__BYP, CYREG_PRT12_BYP
.set Rx__DM0, CYREG_PRT12_DM0
.set Rx__DM1, CYREG_PRT12_DM1
.set Rx__DM2, CYREG_PRT12_DM2
.set Rx__DR, CYREG_PRT12_DR
.set Rx__INP_DIS, CYREG_PRT12_INP_DIS
.set Rx__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Rx__MASK, 0x40
.set Rx__PORT, 12
.set Rx__PRT, CYREG_PRT12_PRT
.set Rx__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Rx__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Rx__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Rx__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Rx__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Rx__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Rx__PS, CYREG_PRT12_PS
.set Rx__SHIFT, 6
.set Rx__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Rx__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Rx__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Rx__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Rx__SLW, CYREG_PRT12_SLW

/* Tx */
.set Tx__0__INTTYPE, CYREG_PICU12_INTTYPE7
.set Tx__0__MASK, 0x80
.set Tx__0__PC, CYREG_PRT12_PC7
.set Tx__0__PORT, 12
.set Tx__0__SHIFT, 7
.set Tx__AG, CYREG_PRT12_AG
.set Tx__BIE, CYREG_PRT12_BIE
.set Tx__BIT_MASK, CYREG_PRT12_BIT_MASK
.set Tx__BYP, CYREG_PRT12_BYP
.set Tx__DM0, CYREG_PRT12_DM0
.set Tx__DM1, CYREG_PRT12_DM1
.set Tx__DM2, CYREG_PRT12_DM2
.set Tx__DR, CYREG_PRT12_DR
.set Tx__INP_DIS, CYREG_PRT12_INP_DIS
.set Tx__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set Tx__MASK, 0x80
.set Tx__PORT, 12
.set Tx__PRT, CYREG_PRT12_PRT
.set Tx__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set Tx__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set Tx__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set Tx__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set Tx__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set Tx__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set Tx__PS, CYREG_PRT12_PS
.set Tx__SHIFT, 7
.set Tx__SIO_CFG, CYREG_PRT12_SIO_CFG
.set Tx__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set Tx__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set Tx__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set Tx__SLW, CYREG_PRT12_SLW

/* PWM_PWMHW */
.set PWM_PWMHW__CAP0, CYREG_TMR0_CAP0
.set PWM_PWMHW__CAP1, CYREG_TMR0_CAP1
.set PWM_PWMHW__CFG0, CYREG_TMR0_CFG0
.set PWM_PWMHW__CFG1, CYREG_TMR0_CFG1
.set PWM_PWMHW__CFG2, CYREG_TMR0_CFG2
.set PWM_PWMHW__CNT_CMP0, CYREG_TMR0_CNT_CMP0
.set PWM_PWMHW__CNT_CMP1, CYREG_TMR0_CNT_CMP1
.set PWM_PWMHW__PER0, CYREG_TMR0_PER0
.set PWM_PWMHW__PER1, CYREG_TMR0_PER1
.set PWM_PWMHW__PM_ACT_CFG, CYREG_PM_ACT_CFG3
.set PWM_PWMHW__PM_ACT_MSK, 0x01
.set PWM_PWMHW__PM_STBY_CFG, CYREG_PM_STBY_CFG3
.set PWM_PWMHW__PM_STBY_MSK, 0x01
.set PWM_PWMHW__RT0, CYREG_TMR0_RT0
.set PWM_PWMHW__RT1, CYREG_TMR0_RT1
.set PWM_PWMHW__SR0, CYREG_TMR0_SR0

/* UART_BUART */
.set UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG, CYREG_B1_UDB08_09_ACTL
.set UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG, CYREG_B1_UDB08_09_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG, CYREG_B1_UDB08_09_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG, CYREG_B1_UDB08_09_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG, CYREG_B1_UDB08_09_CTL
.set UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG, CYREG_B1_UDB08_09_MSK
.set UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG, CYREG_B1_UDB08_09_MSK
.set UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG, CYREG_B1_UDB08_09_MSK
.set UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG, CYREG_B1_UDB08_09_MSK
.set UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG, CYREG_B1_UDB08_ACTL
.set UART_BUART_sRX_RxBitCounter__CONTROL_REG, CYREG_B1_UDB08_CTL
.set UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG, CYREG_B1_UDB08_ST_CTL
.set UART_BUART_sRX_RxBitCounter__COUNT_REG, CYREG_B1_UDB08_CTL
.set UART_BUART_sRX_RxBitCounter__COUNT_ST_REG, CYREG_B1_UDB08_ST_CTL
.set UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG, CYREG_B1_UDB08_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG, CYREG_B1_UDB08_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter__PERIOD_REG, CYREG_B1_UDB08_MSK
.set UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG, CYREG_B1_UDB08_09_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG, CYREG_B1_UDB08_09_ST
.set UART_BUART_sRX_RxBitCounter_ST__MASK_REG, CYREG_B1_UDB08_MSK
.set UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG, CYREG_B1_UDB08_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG, CYREG_B1_UDB08_MSK_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG, CYREG_B1_UDB08_ACTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG, CYREG_B1_UDB08_ST_CTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG, CYREG_B1_UDB08_ST_CTL
.set UART_BUART_sRX_RxBitCounter_ST__STATUS_REG, CYREG_B1_UDB08_ST
.set UART_BUART_sRX_RxShifter_u0__A0_A1_REG, CYREG_B1_UDB11_A0_A1
.set UART_BUART_sRX_RxShifter_u0__A0_REG, CYREG_B1_UDB11_A0
.set UART_BUART_sRX_RxShifter_u0__A1_REG, CYREG_B1_UDB11_A1
.set UART_BUART_sRX_RxShifter_u0__D0_D1_REG, CYREG_B1_UDB11_D0_D1
.set UART_BUART_sRX_RxShifter_u0__D0_REG, CYREG_B1_UDB11_D0
.set UART_BUART_sRX_RxShifter_u0__D1_REG, CYREG_B1_UDB11_D1
.set UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG, CYREG_B1_UDB11_ACTL
.set UART_BUART_sRX_RxShifter_u0__F0_F1_REG, CYREG_B1_UDB11_F0_F1
.set UART_BUART_sRX_RxShifter_u0__F0_REG, CYREG_B1_UDB11_F0
.set UART_BUART_sRX_RxShifter_u0__F1_REG, CYREG_B1_UDB11_F1
.set UART_BUART_sRX_RxSts__3__MASK, 0x08
.set UART_BUART_sRX_RxSts__3__POS, 3
.set UART_BUART_sRX_RxSts__4__MASK, 0x10
.set UART_BUART_sRX_RxSts__4__POS, 4
.set UART_BUART_sRX_RxSts__5__MASK, 0x20
.set UART_BUART_sRX_RxSts__5__POS, 5
.set UART_BUART_sRX_RxSts__MASK, 0x38
.set UART_BUART_sRX_RxSts__MASK_REG, CYREG_B1_UDB11_MSK
.set UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG, CYREG_B1_UDB11_ACTL
.set UART_BUART_sRX_RxSts__STATUS_REG, CYREG_B1_UDB11_ST
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG, CYREG_B1_UDB09_10_A0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG, CYREG_B1_UDB09_10_A1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG, CYREG_B1_UDB09_10_D0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG, CYREG_B1_UDB09_10_D1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG, CYREG_B1_UDB09_10_ACTL
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG, CYREG_B1_UDB09_10_F0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG, CYREG_B1_UDB09_10_F1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG, CYREG_B1_UDB09_A0_A1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG, CYREG_B1_UDB09_A0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG, CYREG_B1_UDB09_A1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG, CYREG_B1_UDB09_D0_D1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG, CYREG_B1_UDB09_D0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG, CYREG_B1_UDB09_D1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG, CYREG_B1_UDB09_ACTL
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG, CYREG_B1_UDB09_F0_F1
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG, CYREG_B1_UDB09_F0
.set UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG, CYREG_B1_UDB09_F1
.set UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG, CYREG_B0_UDB09_10_A0
.set UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG, CYREG_B0_UDB09_10_A1
.set UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG, CYREG_B0_UDB09_10_D0
.set UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG, CYREG_B0_UDB09_10_D1
.set UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB09_10_ACTL
.set UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG, CYREG_B0_UDB09_10_F0
.set UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG, CYREG_B0_UDB09_10_F1
.set UART_BUART_sTX_TxShifter_u0__A0_A1_REG, CYREG_B0_UDB09_A0_A1
.set UART_BUART_sTX_TxShifter_u0__A0_REG, CYREG_B0_UDB09_A0
.set UART_BUART_sTX_TxShifter_u0__A1_REG, CYREG_B0_UDB09_A1
.set UART_BUART_sTX_TxShifter_u0__D0_D1_REG, CYREG_B0_UDB09_D0_D1
.set UART_BUART_sTX_TxShifter_u0__D0_REG, CYREG_B0_UDB09_D0
.set UART_BUART_sTX_TxShifter_u0__D1_REG, CYREG_B0_UDB09_D1
.set UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG, CYREG_B0_UDB09_ACTL
.set UART_BUART_sTX_TxShifter_u0__F0_F1_REG, CYREG_B0_UDB09_F0_F1
.set UART_BUART_sTX_TxShifter_u0__F0_REG, CYREG_B0_UDB09_F0
.set UART_BUART_sTX_TxShifter_u0__F1_REG, CYREG_B0_UDB09_F1
.set UART_BUART_sTX_TxSts__0__MASK, 0x01
.set UART_BUART_sTX_TxSts__0__POS, 0
.set UART_BUART_sTX_TxSts__1__MASK, 0x02
.set UART_BUART_sTX_TxSts__1__POS, 1
.set UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB09_10_ACTL
.set UART_BUART_sTX_TxSts__16BIT_STATUS_REG, CYREG_B0_UDB09_10_ST
.set UART_BUART_sTX_TxSts__2__MASK, 0x04
.set UART_BUART_sTX_TxSts__2__POS, 2
.set UART_BUART_sTX_TxSts__3__MASK, 0x08
.set UART_BUART_sTX_TxSts__3__POS, 3
.set UART_BUART_sTX_TxSts__MASK, 0x0F
.set UART_BUART_sTX_TxSts__MASK_REG, CYREG_B0_UDB09_MSK
.set UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG, CYREG_B0_UDB09_ACTL
.set UART_BUART_sTX_TxSts__STATUS_REG, CYREG_B0_UDB09_ST

/* UART_IntClock */
.set UART_IntClock__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set UART_IntClock__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set UART_IntClock__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set UART_IntClock__CFG2_SRC_SEL_MASK, 0x07
.set UART_IntClock__INDEX, 0x01
.set UART_IntClock__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set UART_IntClock__PM_ACT_MSK, 0x02
.set UART_IntClock__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set UART_IntClock__PM_STBY_MSK, 0x02

/* UART_RXInternalInterrupt */
.set UART_RXInternalInterrupt__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set UART_RXInternalInterrupt__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set UART_RXInternalInterrupt__INTC_MASK, 0x01
.set UART_RXInternalInterrupt__INTC_NUMBER, 0
.set UART_RXInternalInterrupt__INTC_PRIOR_NUM, 7
.set UART_RXInternalInterrupt__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set UART_RXInternalInterrupt__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set UART_RXInternalInterrupt__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* UART_TXInternalInterrupt */
.set UART_TXInternalInterrupt__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set UART_TXInternalInterrupt__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set UART_TXInternalInterrupt__INTC_MASK, 0x02
.set UART_TXInternalInterrupt__INTC_NUMBER, 1
.set UART_TXInternalInterrupt__INTC_PRIOR_NUM, 7
.set UART_TXInternalInterrupt__INTC_PRIOR_REG, CYREG_NVIC_PRI_1
.set UART_TXInternalInterrupt__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set UART_TXInternalInterrupt__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Clock_1 */
.set Clock_1__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set Clock_1__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set Clock_1__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set Clock_1__CFG2_SRC_SEL_MASK, 0x07
.set Clock_1__INDEX, 0x00
.set Clock_1__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock_1__PM_ACT_MSK, 0x01
.set Clock_1__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock_1__PM_STBY_MSK, 0x01

/* Pin_LED */
.set Pin_LED__0__INTTYPE, CYREG_PICU2_INTTYPE1
.set Pin_LED__0__MASK, 0x02
.set Pin_LED__0__PC, CYREG_PRT2_PC1
.set Pin_LED__0__PORT, 2
.set Pin_LED__0__SHIFT, 1
.set Pin_LED__AG, CYREG_PRT2_AG
.set Pin_LED__AMUX, CYREG_PRT2_AMUX
.set Pin_LED__BIE, CYREG_PRT2_BIE
.set Pin_LED__BIT_MASK, CYREG_PRT2_BIT_MASK
.set Pin_LED__BYP, CYREG_PRT2_BYP
.set Pin_LED__CTL, CYREG_PRT2_CTL
.set Pin_LED__DM0, CYREG_PRT2_DM0
.set Pin_LED__DM1, CYREG_PRT2_DM1
.set Pin_LED__DM2, CYREG_PRT2_DM2
.set Pin_LED__DR, CYREG_PRT2_DR
.set Pin_LED__INP_DIS, CYREG_PRT2_INP_DIS
.set Pin_LED__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set Pin_LED__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set Pin_LED__LCD_EN, CYREG_PRT2_LCD_EN
.set Pin_LED__MASK, 0x02
.set Pin_LED__PORT, 2
.set Pin_LED__PRT, CYREG_PRT2_PRT
.set Pin_LED__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set Pin_LED__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set Pin_LED__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set Pin_LED__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set Pin_LED__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set Pin_LED__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set Pin_LED__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set Pin_LED__PS, CYREG_PRT2_PS
.set Pin_LED__SHIFT, 1
.set Pin_LED__SLW, CYREG_PRT2_SLW

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_BOOTLOADER_APPLICATIONS, 1
.set CYDEV_BOOTLOADER_CHECKSUM_BASIC, 0
.set CYDEV_BOOTLOADER_CHECKSUM_CRC, 1
.set CYDEV_BOOTLOADER_IO_COMP_CUSTOM_IO, 0
.set CyBtldr_Custom_Interface, CYDEV_BOOTLOADER_IO_COMP_CUSTOM_IO
.set CYDEV_BOOTLOADER_IO_COMP_UART, 1
.set CyBtldr_UART, CYDEV_BOOTLOADER_IO_COMP_UART
.set CYDEV_BOOTLOADER_IO_COMP, CYDEV_BOOTLOADER_IO_COMP_UART
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 19
.set CYDEV_CHIP_DIE_PSOC4A, 11
.set CYDEV_CHIP_DIE_PSOC5LP, 18
.set CYDEV_CHIP_DIE_TMA4, 2
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E161069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 11
.set CYDEV_CHIP_MEMBER_4C, 16
.set CYDEV_CHIP_MEMBER_4D, 7
.set CYDEV_CHIP_MEMBER_4E, 4
.set CYDEV_CHIP_MEMBER_4F, 12
.set CYDEV_CHIP_MEMBER_4G, 2
.set CYDEV_CHIP_MEMBER_4H, 10
.set CYDEV_CHIP_MEMBER_4I, 15
.set CYDEV_CHIP_MEMBER_4J, 8
.set CYDEV_CHIP_MEMBER_4K, 9
.set CYDEV_CHIP_MEMBER_4L, 14
.set CYDEV_CHIP_MEMBER_4M, 13
.set CYDEV_CHIP_MEMBER_4N, 6
.set CYDEV_CHIP_MEMBER_4O, 5
.set CYDEV_CHIP_MEMBER_4U, 3
.set CYDEV_CHIP_MEMBER_5A, 18
.set CYDEV_CHIP_MEMBER_5B, 17
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4C_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000003
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 1
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 1
.endif
