/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define ANIN0_TRIS                 TRISAbits.TRISA0
#define ANIN0_LAT                  LATAbits.LATA0
#define ANIN0_PORT                 PORTAbits.RA0
#define ANIN0_WPU                  WPUAbits.WPUA0
#define ANIN0_OD                   ODCONAbits.ODA0
#define ANIN0_ANS                  ANSELAbits.ANSA0
#define ANIN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ANIN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ANIN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ANIN0_GetValue()           PORTAbits.RA0
#define ANIN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ANIN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ANIN0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ANIN0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ANIN0_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define ANIN0_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define ANIN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define ANIN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)
// get/set IO_RA1 aliases
#define ANIN1_TRIS                 TRISAbits.TRISA1
#define ANIN1_LAT                  LATAbits.LATA1
#define ANIN1_PORT                 PORTAbits.RA1
#define ANIN1_WPU                  WPUAbits.WPUA1
#define ANIN1_OD                   ODCONAbits.ODA1
#define ANIN1_ANS                  ANSELAbits.ANSA1
#define ANIN1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define ANIN1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define ANIN1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define ANIN1_GetValue()           PORTAbits.RA1
#define ANIN1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define ANIN1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define ANIN1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define ANIN1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define ANIN1_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define ANIN1_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define ANIN1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define ANIN1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)
// get/set IO_RA2 aliases
#define ANIN2_TRIS                 TRISAbits.TRISA2
#define ANIN2_LAT                  LATAbits.LATA2
#define ANIN2_PORT                 PORTAbits.RA2
#define ANIN2_WPU                  WPUAbits.WPUA2
#define ANIN2_OD                   ODCONAbits.ODA2
#define ANIN2_ANS                  ANSELAbits.ANSA2
#define ANIN2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define ANIN2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define ANIN2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define ANIN2_GetValue()           PORTAbits.RA2
#define ANIN2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define ANIN2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define ANIN2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define ANIN2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define ANIN2_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define ANIN2_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define ANIN2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define ANIN2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RA4 aliases
#define ANIN3_TRIS                 TRISAbits.TRISA4
#define ANIN3_LAT                  LATAbits.LATA4
#define ANIN3_PORT                 PORTAbits.RA4
#define ANIN3_WPU                  WPUAbits.WPUA4
#define ANIN3_OD                   ODCONAbits.ODA4
#define ANIN3_ANS                  ANSELAbits.ANSA4
#define ANIN3_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ANIN3_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ANIN3_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ANIN3_GetValue()           PORTAbits.RA4
#define ANIN3_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ANIN3_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ANIN3_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define ANIN3_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define ANIN3_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define ANIN3_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define ANIN3_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define ANIN3_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RC0 aliases
#define RS_TRIS                 TRISCbits.TRISC0
#define RS_LAT                  LATCbits.LATC0
#define RS_PORT                 PORTCbits.RC0
#define RS_WPU                  WPUCbits.WPUC0
#define RS_OD                   ODCONCbits.ODC0
#define RS_ANS                  ANSELCbits.ANSC0
#define RS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RS_GetValue()           PORTCbits.RC0
#define RS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RS_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define RS_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
// get/set IO_RC1 aliases
#define EN_TRIS                 TRISCbits.TRISC1
#define EN_LAT                  LATCbits.LATC1
#define EN_PORT                 PORTCbits.RC1
#define EN_WPU                  WPUCbits.WPUC1
#define EN_OD                   ODCONCbits.ODC1
#define EN_ANS                  ANSELCbits.ANSC1
#define EN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define EN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define EN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define EN_GetValue()           PORTCbits.RC1
#define EN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define EN_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define EN_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define EN_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define EN_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define EN_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define D4_TRIS                 TRISCbits.TRISC2
#define D4_LAT                  LATCbits.LATC2
#define D4_PORT                 PORTCbits.RC2
#define D4_WPU                  WPUCbits.WPUC2
#define D4_OD                   ODCONCbits.ODC2
#define D4_ANS                  ANSELCbits.ANSC2
#define D4_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define D4_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define D4_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define D4_GetValue()           PORTCbits.RC2
#define D4_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define D4_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define D4_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define D4_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define D4_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define D4_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define D5_TRIS                 TRISCbits.TRISC3
#define D5_LAT                  LATCbits.LATC3
#define D5_PORT                 PORTCbits.RC3
#define D5_WPU                  WPUCbits.WPUC3
#define D5_OD                   ODCONCbits.ODC3
#define D5_ANS                  ANSELCbits.ANSC3
#define D5_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D5_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D5_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D5_GetValue()           PORTCbits.RC3
#define D5_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define D5_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define D5_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define D5_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define D5_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define D5_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define D5_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC4 aliases
#define D6_TRIS                 TRISCbits.TRISC4
#define D6_LAT                  LATCbits.LATC4
#define D6_PORT                 PORTCbits.RC4
#define D6_WPU                  WPUCbits.WPUC4
#define D6_OD                   ODCONCbits.ODC4
#define D6_ANS                  ANSELCbits.ANSC4
#define D6_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define D6_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define D6_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define D6_GetValue()           PORTCbits.RC4
#define D6_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define D6_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define D6_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define D6_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define D6_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)
#define D6_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
// get/set IO_RC5 aliases
#define D7_TRIS                 TRISCbits.TRISC5
#define D7_LAT                  LATCbits.LATC5
#define D7_PORT                 PORTCbits.RC5
#define D7_WPU                  WPUCbits.WPUC5
#define D7_OD                   ODCONCbits.ODC5
#define D7_ANS                  ANSELCbits.ANSC5
#define D7_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define D7_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define D7_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define D7_GetValue()           PORTCbits.RC5
#define D7_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define D7_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define D7_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define D7_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define D7_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define D7_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/