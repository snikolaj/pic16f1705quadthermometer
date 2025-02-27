/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
 [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "mcc_generated_files/system/system.h"
#include <stdio.h>

/*
    LCD Driver Defines and Functions
*/

// LCD commands
#define LCD_CLEAR           0x01
#define LCD_RETURN_HOME     0x02
#define LCD_ENTRY_MODE_SET  0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT    0x10
#define LCD_FUNCTION_SET    0x20
#define LCD_SET_CGRAM_ADDR  0x40
#define LCD_SET_DDRAM_ADDR  0x80

// Entry mode flags
#define LCD_ENTRY_RIGHT     0x00
#define LCD_ENTRY_LEFT      0x02
#define LCD_ENTRY_SHIFT_ON  0x01
#define LCD_ENTRY_SHIFT_OFF 0x00

// Display control flags
#define LCD_DISPLAY_ON      0x04
#define LCD_DISPLAY_OFF     0x00
#define LCD_CURSOR_ON       0x02
#define LCD_CURSOR_OFF      0x00
#define LCD_BLINK_ON        0x01
#define LCD_BLINK_OFF       0x00

// Function set flags
#define LCD_8BIT_MODE       0x10
#define LCD_4BIT_MODE       0x00
#define LCD_2LINE           0x08
#define LCD_1LINE           0x00
#define LCD_5x10DOTS        0x04
#define LCD_5x8DOTS         0x00

// Display positions
#define LCD_LINE1           0x00
#define LCD_LINE2           0x40

// Delay functions
static void LCD_Delay_ms(uint8_t ms) {
    for (uint8_t i = 0; i < ms; i++) {
        __delay_ms(1);
    }
}

static void LCD_Delay_us(uint8_t us) {
    for (uint8_t i = 0; i < us; i++) {
        __delay_us(1);
    }
}

// Function to pulse the EN pin
static void LCD_PulseEN(void) {
    EN_SetHigh();
    LCD_Delay_us(1);
    EN_SetLow();
    LCD_Delay_us(100); // Commands need time to execute
}

// Function to send 4 bits to the LCD
static void LCD_Send4Bits(uint8_t data) {
    // Set the 4 data lines
    D4_LAT = (data & 0x01) ? 1 : 0;
    D5_LAT = (data & 0x02) ? 1 : 0;
    D6_LAT = (data & 0x04) ? 1 : 0;
    D7_LAT = (data & 0x08) ? 1 : 0;
    
    // Pulse the EN pin
    LCD_PulseEN();
}

void LCD_SendCommand(uint8_t cmd) {
    RS_SetLow(); // Select command register
    
    // Send the high nibble first
    LCD_Send4Bits(cmd >> 4);
    
    // Send the low nibble
    LCD_Send4Bits(cmd & 0x0F);
    
    // If it's a clear or return home command, delay for execution time
    if (cmd == LCD_CLEAR || cmd == LCD_RETURN_HOME) {
        LCD_Delay_ms(2);
    }
}

void LCD_SendData(uint8_t data) {
    RS_SetHigh(); // Select data register
    
    // Send the high nibble first
    LCD_Send4Bits(data >> 4);
    
    // Send the low nibble
    LCD_Send4Bits(data & 0x0F);
    
    LCD_Delay_us(40); // Character write needs time
}

void LCD_Initialize(void) {
    // Configure pins as outputs
    RS_SetDigitalOutput();
    EN_SetDigitalOutput();
    D4_SetDigitalOutput();
    D5_SetDigitalOutput();
    D6_SetDigitalOutput();
    D7_SetDigitalOutput();
    
    // Initialize pins to low
    RS_SetLow();
    EN_SetLow();
    D4_SetLow();
    D5_SetLow();
    D6_SetLow();
    D7_SetLow();
    
    // Wait for LCD to power up
    LCD_Delay_ms(50);
    
    // Special initialization sequence for 4-bit mode
    // First, send 0x03 three times to ensure we're in 8-bit mode
    LCD_Send4Bits(0x03);
    LCD_Delay_ms(5);
    LCD_Send4Bits(0x03);
    LCD_Delay_ms(5);
    LCD_Send4Bits(0x03);
    LCD_Delay_ms(1);
    
    // Now switch to 4-bit mode
    LCD_Send4Bits(0x02);
    LCD_Delay_ms(1);
    
    // Now we can use regular command functions
    // Function set: 4-bit mode, 2 lines, 5x8 dots
    LCD_SendCommand(LCD_FUNCTION_SET | LCD_4BIT_MODE | LCD_2LINE | LCD_5x8DOTS);
    
    // Display control: display on, cursor off, blinking off
    LCD_SendCommand(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON | LCD_CURSOR_OFF | LCD_BLINK_OFF);
    
    // Entry mode set: increment cursor position, no display shift
    LCD_SendCommand(LCD_ENTRY_MODE_SET | LCD_ENTRY_LEFT | LCD_ENTRY_SHIFT_OFF);
    
    // Clear display
    LCD_SendCommand(LCD_CLEAR);
}

void LCD_Clear(void) {
    LCD_SendCommand(LCD_CLEAR);
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t address;
    
    // Calculate the DDRAM address based on row and column
    if (row == 0) {
        address = LCD_LINE1 + col;
    } else {
        address = LCD_LINE2 + col;
    }
    
    // Set the DDRAM address
    LCD_SendCommand(LCD_SET_DDRAM_ADDR | address);
}

void LCD_WriteString(const char *str) {
    while (*str) {
        LCD_SendData(*str++);
    }
}

void LCD_WriteFloat(float value, uint8_t decimalPlaces) {
    char buffer[16]; // Buffer for the converted string
    int intPart = (int)value;
    int fracPart;
    
    // Calculate the fractional part based on decimal places
    float multiplier = 1.0;
    for (uint8_t i = 0; i < decimalPlaces; i++) {
        multiplier *= 10.0;
    }
    fracPart = (int)((value - intPart) * multiplier);
    
    // Ensure the fractional part is positive
    if (fracPart < 0) {
        fracPart = -fracPart;
    }
    
    // Format the string based on the decimal places
    if (decimalPlaces > 0) {
        sprintf(buffer, "%d.%0*d", intPart, decimalPlaces, fracPart);
    } else {
        sprintf(buffer, "%d", intPart);
    }
    
    // Write the string to the LCD
    LCD_WriteString(buffer);
}

/*
    ADC and Main Application
*/

// Function to convert ADC reading to temperature in Celsius
// Fixed to properly handle the PIC's ADC and temperature sensor characteristics
// Added a -10 degree offset as requested
float ADC_ConvertToTemperature(adc_result_t adcValue) {
    // For a temperature sensor that outputs 10mV/K with 0K = 0V
    
    // Step 1: Calculate the Vref (4.096V) divided by 1023 (10-bit ADC resolution)
    // This gives us volts per ADC count
    const float volts_per_count = 4.096 / 1023.0;
    
    // Step 2: Convert ADC reading to voltage
    float voltage = (float)adcValue * volts_per_count;
    
    // Step 3: Convert voltage to Kelvin (10mV/K = 0.01V/K)
    // K = V / 0.01
    float kelvin = voltage / 0.01;
    
    // Step 4: Convert Kelvin to Celsius
    float celsius = kelvin - 273.15;
    
    // Step 5: Apply the requested offset of -10 degrees
    celsius = celsius - 10.0;
    
    // Return the temperature in Celsius with offset
    return celsius;
}

// Function to read and display temperature from an ADC channel
void SampleAndDisplayTemperature(adc_channel_t channel, const char* channelName, uint8_t row, uint8_t col) {
    adc_result_t adcValue;
    float temperature;
    char buffer[16];
    
    // Sample the ADC channel
    adcValue = ADC_GetConversion(channel);
    
    // For debugging - add raw ADC value display
    // Uncomment this section to see raw ADC values
    
    //LCD_SetCursor(row, col);
    //LCD_WriteString(channelName);
    //LCD_WriteString(":");
    //sprintf(buffer, "%4d", adcValue);
    //LCD_WriteString(buffer);
    //return;
    
    
    // Convert to temperature in Celsius
    temperature = ADC_ConvertToTemperature(adcValue);
    
    // Position cursor and display the channel name
    LCD_SetCursor(row, col);
    LCD_WriteString(channelName);
    LCD_WriteString(":");
    
    // Format the temperature string with no decimal places as requested
    sprintf(buffer, "% 4.0fC", temperature);
    
    // Write the formatted string to the LCD
    LCD_WriteString(buffer);
}

int main(void)
{
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    //INTERRUPT_GlobalInterruptEnable(); 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Initialize the FVR for ADC reference
    FVR_Initialize();
    
    // Wait for FVR to be ready
    while(!FVR_IsOutputReady());
    
    // Initialize the LCD
    LCD_Initialize();
    
    // Display welcome message
    LCD_Clear();
    LCD_SetCursor(0, 0);
    LCD_WriteString("Temperature");
    __delay_ms(1000);  // Display for 1 second
    LCD_Clear();

    while(1)
    {
        // Sample and display temperature for each channel
        SampleAndDisplayTemperature(ANIN0, "0", 0, 0);
        
        SampleAndDisplayTemperature(ANIN1, "1", 0, 8);
        
        SampleAndDisplayTemperature(ANIN2, "2", 1, 0);
        
        SampleAndDisplayTemperature(ANIN3, "3", 1, 8);
        
        // Wait 500ms before next sampling
        __delay_ms(500);
    }    
}