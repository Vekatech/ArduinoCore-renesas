#include "Arduino.h"
#include "pinmux.inc"

extern "C" const PinMuxCfg_t g_pin_cfg[] = {
  // Digital
  { BSP_IO_PORT_03_PIN_01,  P301 }, /* (0)   D0                     |  SCI2_[RX|SCL] / IRQ6 / PWM4_B         */
  { BSP_IO_PORT_03_PIN_02,  P302 }, /* (1)   D1                     |  SCI2_[TX|SDA] / IRQ5 / PWM4_A         */
  { BSP_IO_PORT_01_PIN_11,  P111 }, /* (2)   D2                     |  SCK0 / PWM3_A / IRQ4                  */
  { BSP_IO_PORT_01_PIN_10,  P110 }, /* (3)   D3                     |  MISO0 / SCI9_[RX|SCL] / PWM1_B /IRQ3  */
  { BSP_IO_PORT_01_PIN_09,  P109 }, /* (4)   D4                     |  MOSI0 / SCI9_[TX|SDA] / PWM1_A        */
  // Analog
  { BSP_IO_PORT_00_PIN_14,  P014 }, /* (5)   D5 / A0                |  DAC0                                  */
  { BSP_IO_PORT_00_PIN_15,  P015 }, /* (6)   D6 / A1                |  DAC1 / IRQ13                          */
  { BSP_IO_PORT_00_PIN_01,  P001 }, /* (7)   D7 / A2                |  IRQ7                                  */
  { BSP_IO_PORT_00_PIN_02,  P002 }, /* (8)   D8 / A3                |  IRQ8                                  */
  { BSP_IO_PORT_00_PIN_13,  P013 }, /* (9)   D9 / A4                |                                        */
  // Additional digital pins
  { BSP_IO_PORT_02_PIN_06,  P206 }, /* (10)  D10                    |  CS0 / IRQ0                            */
  { BSP_IO_PORT_01_PIN_00,  P100 }, /* (11)  D11                    |  SCI0_[RX|MISO|SCL] / PWM5_B / IRQ2    */
  // Additional digital pads (extension solder pads)
  { BSP_IO_PORT_01_PIN_01,  P101 }, /* (12)  D12                    |  SCI0_[TX|MOSI|SDA] / PWM5_A / IRQ1    */
  { BSP_IO_PORT_01_PIN_04,  P104 }, /* (13)  D13                    |  IRQ1 / PWM1_B                         */
  { BSP_IO_PORT_01_PIN_02,  P102 }, /* (14)  D14                    |  CAN0_RX / SCI0_[SCK] / PWM2_B         */
  { BSP_IO_PORT_01_PIN_03,  P103 }, /* (15)  D15                    |  CAN0_TX / SCI0_[SS] / PWM2_A          */
  { BSP_IO_PORT_04_PIN_08,  P408 }, /* (16)  D16                    |  SCI3_[RX|SCL] / IRQ7 / PWM6_B         */
  { BSP_IO_PORT_04_PIN_09,  P409 }, /* (17)  D17                    |  SCI3_[TX|SDA] / IRQ6                  */
  //
  /// ############################ INTERNAL STUFF ############################
  // Control signals
  { BSP_IO_PORT_00_PIN_00,  P000 }, /* (18)  BATT_LVL               |                                        */
  { BSP_IO_PORT_02_PIN_01,  P201 }, /* (19)  LED_BUILTIN / BTN_USER |                                        */
  { BSP_IO_PORT_01_PIN_12,  P112 }, /* (20)  RGB_DATA               |                                        */
  { BSP_IO_PORT_04_PIN_02,  P402 }, /* (21)  EN_BATT_LVL            |                                        */
  { BSP_IO_PORT_05_PIN_00,  P500 }, /* (22)  EN_RGB_LED             |                                        */
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

  // bootloader configures LED_BUILTIN as output, deconfigure it to avoid spurious signals
  pinMode(LED_BUILTIN, INPUT);
}
