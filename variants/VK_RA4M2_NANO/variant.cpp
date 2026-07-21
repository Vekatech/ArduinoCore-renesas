#include "Arduino.h"
#include "pinmux.inc"

extern "C" const PinMuxCfg_t g_pin_cfg[] = {
  // Digital
  { BSP_IO_PORT_03_PIN_01,  P301 }, /* (0)   D0                 |  UART1_RX[SCI2] / IRQ6 / PWM4_B      */
  { BSP_IO_PORT_03_PIN_02,  P302 }, /* (1)   D1                 |  UART1_TX[SCI2] / IRQ5 / PWM4_A      */
  { BSP_IO_PORT_01_PIN_05,  P105 }, /* (2)   D2                 |  IRQ0 / PWM1_A                       */
  { BSP_IO_PORT_01_PIN_04,  P104 }, /* (3)   D3                 |  IRQ1 / PWM1_B                       */
  { BSP_IO_PORT_01_PIN_03,  P103 }, /* (4)   D4                 |  CAN0_TX / PWM2_A                    */
  { BSP_IO_PORT_01_PIN_02,  P102 }, /* (5)   D5                 |  CAN0_RX / PWM2_B                    */
  { BSP_IO_PORT_01_PIN_06,  P106 }, /* (6)   D6                 |                                      */
  { BSP_IO_PORT_01_PIN_07,  P107 }, /* (7)   D7                 |                                      */
  { BSP_IO_PORT_03_PIN_04,  P304 }, /* (8)   D8                 |  IRQ9 / PWM7_A                       */
  { BSP_IO_PORT_03_PIN_03,  P303 }, /* (9)   D9                 |         PWM7_B                       */
  { BSP_IO_PORT_01_PIN_12,  P112 }, /* (10)  D10                |  SS0 / PWM3_B                        */
  { BSP_IO_PORT_01_PIN_09,  P109 }, /* (11)  D11                |  MOSI0 / PWM1_A                      */
  { BSP_IO_PORT_01_PIN_10,  P110 }, /* (12)  D12                |  MISO0 / PWM1_B /IRQ3                */
  { BSP_IO_PORT_01_PIN_11,  P111 }, /* (13)  D13                |  SCK0 / PWM3_A / IRQ4                */
  // Analog
  { BSP_IO_PORT_00_PIN_14,  P014 }, /* (14)  D14 / A0           |  DAC0                                */
  { BSP_IO_PORT_00_PIN_00,  P000 }, /* (15)  D15 / A1           |  IRQ6                                */
  { BSP_IO_PORT_00_PIN_01,  P001 }, /* (16)  D16 / A2           |  IRQ7                                */
  { BSP_IO_PORT_00_PIN_02,  P002 }, /* (17)  D17 / A3           |  IRQ8                                */
  { BSP_IO_PORT_00_PIN_04,  P004 }, /* (18)  D18 / A4           |  IRQ9                                */
  { BSP_IO_PORT_00_PIN_03,  P003 }, /* (19)  D19 / A5           |                                      */
  { BSP_IO_PORT_00_PIN_13,  P013 }, /* (20)  D20 / A6           |                                      */
  { BSP_IO_PORT_00_PIN_15,  P015 }, /* (21)  D21 / A7           |  DAC1/IRQ13                          */
  { BSP_IO_PORT_05_PIN_00,  P500 }, /* (22)  D22 / A8           |                                      */
  // Additional digital pins
  { BSP_IO_PORT_01_PIN_01,  P101 }, /* (23)  D23                |  QWIIK_SDA[SCI0] / PWM5_A / IRQ1     */
  { BSP_IO_PORT_01_PIN_00,  P100 }, /* (24)  D24                |  QWIIK_SCL[SCI0] / PWM5_B / IRQ2     */
  { BSP_IO_PORT_02_PIN_01,  P201 }, /* (25)  D25                |                                      */
  { BSP_IO_PORT_04_PIN_00,  P400 }, /* (26)  D26                |  IRQ0 / PWM6_A                       */
  { BSP_IO_PORT_04_PIN_11,  P411 }, /* (27)  D27                |  SCI3_[SS] / IRQ4 / QWIIK_SDA[SCI0]  */
  { BSP_IO_PORT_04_PIN_10,  P410 }, /* (28)  D28                |  SCI3_[SCK] / IRQ5 / QWIIK_SCL[SCI0] */
  { BSP_IO_PORT_04_PIN_09,  P409 }, /* (29)  D29                |  SCI3_[TX|MOSI|SDA] / IRQ6           */
  { BSP_IO_PORT_01_PIN_13,  P113 }, /* (30)  D30                |  PWM2_A                              */
  { BSP_IO_PORT_02_PIN_08,  P208 }, /* (31)  D31 / LED_BUILTIN  |                                      */
  { BSP_IO_PORT_02_PIN_07,  P207 }, /* (32)  D32                |                                      */
  { BSP_IO_PORT_02_PIN_00,  P200 }, /* (33)  D33 (input only!)  |                                      */
  { BSP_IO_PORT_04_PIN_08,  P408 }, /* (34)  D34 / LED_USER     |  SCI3_[RX|MISO|SCL] / IRQ7 / PWM6_B  */
  //
  /// ############################ INTERNAL STUFF ############################
  // DA14531MOD UART
  { BSP_IO_PORT_02_PIN_06,  P206 }, /* (35)  BLE_TX -> MCU_RX   |  UART2_RX[SCI4]                      */
  { BSP_IO_PORT_02_PIN_05,  P205 }, /* (36)  BLE_RX <- MCU_TX   |  UART2_TX[SCI4]                      */
  { BSP_IO_PORT_04_PIN_01,  P401 }, /* (37)  BLE_CTS <- MCU_RTS |  UART2_RTS[SCI4]                     */
  { BSP_IO_PORT_04_PIN_02,  P402 }, /* (38)  BLE_RTS -> MCU_CTS |  UART2_CTS[SCI4]                     */
};

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_pin_cfg) / sizeof(g_pin_cfg[0]));
    }
}

int32_t getPinIndex(bsp_io_port_pin_t p) {
  int max_index = PINS_COUNT;
  int rv = -1;
  for(int i = 0; i < max_index; i++) {
    if(g_pin_cfg[i].pin == p) {
      rv = i;
      break;
    }
  }
  return rv;
}

void initVariant() {

  //(void) R_IOPORT_Open(&g_ioport_ctrl, &g_bsp_pin_cfg);

  // bootloader configures LED_BUILTIN as output, deconfigure it to avoid spurious signals
  pinMode(LED_BUILTIN, INPUT);
}
