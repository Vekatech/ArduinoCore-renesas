#pragma once

#define PIN(X,Y) (X * 16 + Y)

// Pin count
// ----
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (35u)
#define NUM_ANALOG_INPUTS    (9u)
#define NUM_ANALOG_OUTPUTS   (2u)

#define PIN_A0   (14u)
#define PIN_A1   (15u)
#define PIN_A2   (16u)
#define PIN_A3   (17u)
#define PIN_A4   (18u)
#define PIN_A5   (19u)
#define PIN_A6   (20u)
#define PIN_A7   (21u)
#define PIN_A8   (22u)

#define DAC8_HOWMANY (0)
#define DAC12_HOWMANY (2)
#define DAC      PIN_A0
#define DAC1     PIN_A7
#define IS_DAC(x)   (x == DAC || x == DAC1)
#define DAC_ADDRESS_12_CH0          R_DAC_BASE
// TODO: check if true
#define DAC_ADDRESS_12_CH1          (R_DAC_BASE+2)

#undef A0
#undef A1
#undef A2
#undef A3
#undef A4
#undef A5
#undef A6
#undef A7
#undef A8
#undef A9


static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
static const uint8_t A8 = PIN_A8;

// Digital pins
// -----------
#define PIN_D0   (0u)
#define PIN_D1   (1u)
#define PIN_D2   (2u)
#define PIN_D3   (3u)
#define PIN_D4   (4u)
#define PIN_D5   (5u)
#define PIN_D6   (6u)
#define PIN_D7   (7u)
#define PIN_D8   (8u)
#define PIN_D9   (9u)
#define PIN_D10  (10u)
#define PIN_D11  (11u)
#define PIN_D12  (12u)
#define PIN_D13  (13u)
#define PIN_D14  (14u)
#define PIN_D15  (15u)
#define PIN_D16  (16u)
#define PIN_D17  (17u)
#define PIN_D18  (18u)
#define PIN_D19  (19u)
#define PIN_D20  (20u)
#define PIN_D21  (21u)
#define PIN_D22  (22u)
#define PIN_D23  (23u)
#define PIN_D24  (24u)
#define PIN_D25  (25u)
#define PIN_D26  (26u)
#define PIN_D27  (27u)
#define PIN_D28  (28u)
#define PIN_D29  (29u)
#define PIN_D30  (30u)
#define PIN_D31  (31u)
#define PIN_D32  (32u)
#define PIN_D33  (33u)
#define PIN_D34  (34u)

#undef D0
#undef D1
#undef D2
#undef D3
#undef D4
#undef D5
#undef D6
#undef D7
#undef D8
#undef D9
#undef D10
#undef D11
#undef D12
#undef D13
#undef D14
#undef D15
#undef D16
#undef D17
#undef D18
#undef D19
#undef D20
#undef D21
#undef D22
#undef D23
#undef D24
#undef D25
#undef D26
#undef D27
#undef D28
#undef D29
#undef D30
#undef D31
#undef D32
#undef D33
#undef D34


static const uint8_t D0 = PIN_D0;
static const uint8_t D1 = PIN_D1;
static const uint8_t D2 = PIN_D2;
static const uint8_t D3 = PIN_D3;
static const uint8_t D4 = PIN_D4;
static const uint8_t D5 = PIN_D5;
static const uint8_t D6 = PIN_D6;
static const uint8_t D7 = PIN_D7;
static const uint8_t D8 = PIN_D8;
static const uint8_t D9 = PIN_D9;
static const uint8_t D10 = PIN_D10;
static const uint8_t D11 = PIN_D11;
static const uint8_t D12 = PIN_D12;
static const uint8_t D13 = PIN_D13;
static const uint8_t D14 = PIN_D14;
static const uint8_t D15 = PIN_D15;
static const uint8_t D16 = PIN_D16;
static const uint8_t D17 = PIN_D17;
static const uint8_t D18 = PIN_D18;
static const uint8_t D19 = PIN_D19;
static const uint8_t D20 = PIN_D20;
static const uint8_t D21 = PIN_D21;
static const uint8_t D22 = PIN_D22;
static const uint8_t D23 = PIN_D23;
static const uint8_t D24 = PIN_D24;
static const uint8_t D25 = PIN_D25;
static const uint8_t D26 = PIN_D26;
static const uint8_t D27 = PIN_D27;
static const uint8_t D28 = PIN_D28;
static const uint8_t D29 = PIN_D29;
static const uint8_t D30 = PIN_D30;
static const uint8_t D31 = PIN_D31;
static const uint8_t D32 = PIN_D32;
static const uint8_t D33 = PIN_D33;
static const uint8_t D34 = PIN_D34;

// LEDs
// ----
#define PIN_LED     PIN_D31
#define LED_BUILTIN PIN_LED
#define LED_USER    PIN_D34

#define DI0         PIN_D33

/****** RTC CORE DEFINES *******/
#define RTC_HOWMANY       1

/****** UART CORE DEFINES ******/

/* TODO: add CTS/RTS pins */
#define SERIAL_HOWMANY      3
#define UART1_TX_PIN        1
#define UART1_RX_PIN        0
#define UART2_TX_PIN        36
#define UART2_RX_PIN        35
#define UART2_RTS_PIN       37
#define UART2_CTS_PIN       38
#define UART3_TX_PIN        29
#define UART3_RX_PIN        34


#define SERIAL_PORT_HARDWARE Serial1

/****** WIRE CORE DEFINES ******/

#define WIRE_HOWMANY            2
#define WIRE_INTERFACES_COUNT   WIRE_HOWMANY
#define WIRE_SDA_PIN            23
#define WIRE_SCL_PIN            24
#define ALT_WIRE_SDA_PIN        27
#define ALT_WIRE_SCL_PIN        28
#define WIRE1_SDA_PIN           29
#define WIRE1_SCL_PIN           34

/* J1: Not a Qwiic Connector (SDA & SCL are crossed!)
   Pin 1: GND
   Pin 2: VCC
   Pin 3: SCL <- D24 <- WIRE_SCL_PIN (P100) <- SCL0 <- SCI
   Pin 4: SDA <- D23 <- WIRE_SDA_PIN (P101) <- SDA0 <- SCI
*/
static const uint8_t SDA = WIRE_SDA_PIN;
static const uint8_t SCL = WIRE_SCL_PIN;

/* J2: Qwiic Connector
   Pin 1: GND
   Pin 2: VCC
   Pin 3: SDA <- D27 <- ALT_WIRE_SDA_PIN (P411) <- SDA0 <- SCI
   Pin 4: SCL <- D28 <- ALT_WIRE_SCL_PIN (P410) <- SCL0 <- SCI
*/
//static const uint8_t SDA = ALT_WIRE_SDA_PIN;
//static const uint8_t SCL = ALT_WIRE_SCL_PIN;

/****** SPI CORE DEFINES ******/

#define SPI_HOWMANY       2

#define PIN_SPI_MOSI      11
#define PIN_SPI_MISO      12
#define PIN_SPI_SCK       13
#define PIN_SPI_CS        10
#define FORCE_SPI_MODE    (MODE_SPI)

#define PIN_SPI1_MOSI     29
#define PIN_SPI1_MISO     34
#define PIN_SPI1_SCK      28
#define PIN_SPI1_CS       27
#define FORCE_SPI1_MODE   (MODE_SCI)

static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;
static const uint8_t CS  =  PIN_SPI_CS;
static const uint8_t SS  =  PIN_SPI_CS;

/****** CAN CORE DEFINES ******/

#define CAN_HOWMANY     1

#define PIN_CAN0_TX       (4)
#define PIN_CAN0_RX       (5)
#define PIN_CAN0_STBY     (-1)

/****** GTP CORE DEFINES *******/

#define GTP32_HOWMANY     4
#define GTP16_HOWMANY     4
#define GPT_HOWMANY       8

/****** AGT CORE DEFINES *******/
#define AGT_HOWMANY       6

#define EXT_INTERRUPTS_HOWMANY 11

#define AR_INTERNAL_VOLTAGE     1.18f

#define USB_VID           (0x2341)
#define USB_PID           (0x0069)
#define USB_NAME          "VK-RA4M2-NANO"

/* EEPROM DEFINES */

#define ARDUINO_FLASH_TYPE  HP_FLASH
#define FLASH_BASE_ADDRESS  0x08000000
#define FLASH_TOTAL_SIZE    0x2000
#define FLASH_BLOCK_SIZE    0x40

#define RTC_CLOCK_SOURCE RTC_CLOCK_SOURCE_LOCO
