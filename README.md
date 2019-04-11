![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Ozone_2 Click

- **CIC Prefix**  : OZONE2
- **Author**      : MikroE Team
- **Verison**     : 1.0.0
- **Date**        : Mar 2018.

---


### Software Support

We provide a library for the Ozone_2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2177/ozone-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library carries functions for initialization and reading digital value from MCP3351. Coversion of value 
to PPM is not covered by the library because it depends on measurement environment.

Key functions :

- ``` uint32_t ozone2_read() ``` - Reads digital value from MCP3351 ADC circuit

**Examples Description**

The application is composed of three sections :

- System Initialization - GPIO and SPI module initialization    
- Application Initialization - SPI Driver initialization    
- Application Task - reading raw digital value from ADC each one second and displaying it via UART terminal

```.c
void applicationTask()
{
    readValue = ozone2_read();
    LongWordToStr(readValue,text);
    mikrobus_logWrite("Read Value: ",_LOG_TEXT);
    mikrobus_logWrite(text,_LOG_LINE);
    Delay_ms(1000);
}
```

Keep on mind that this is raw measurement which should be converted to exact Ozone PPM value using 
formulas provided by circuit producer. Conversion to PPM depends on few conditions - more details 
can be found on datasheet.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2177/ozone-2-click) page.

mikroE Libraries used in the example:

- UART
- SPI
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
