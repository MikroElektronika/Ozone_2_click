/*
Example for Ozone_2 Click

    Date          : mar 2018.
    Author        : MikroE Team

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - GPIO and SPI module initialization    
- Application Initialization - SPI Driver initialization    
- Application Task - reading ADC value and displaying it via UART

*/

#include "Click_Ozone_2_types.h"
#include "Click_Ozone_2_config.h"

uint32_t readValue;
char text[20];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_MISO_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_OZONE2_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
     ozone2_spiDriverInit( (T_OZONE2_P)&_MIKROBUS1_GPIO, (T_OZONE2_P)&_MIKROBUS1_SPI );
}

void applicationTask()
{
    readValue = ozone2_read();
    LongWordToStr(readValue,text);
    mikrobus_logWrite("Read Value: ",_LOG_TEXT);
    mikrobus_logWrite(text,_LOG_LINE);
    Delay_ms(1000);



}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
    	applicationTask();
    }
}