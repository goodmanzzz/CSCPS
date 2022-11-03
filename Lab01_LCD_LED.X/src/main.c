#include <xc.h>
#include <p33Fxxxx.h>
//do not change the order of the following 2 definitions
#define FCY 12800000UL 
#include <libpic30.h>

#include "lcd.h"
#include "led.h"

/* Configuration of the Chip */
// Initial Oscillator Source Selection = Primary (XT, HS, EC) Oscillator with PLL
#pragma config FNOSC = PRIPLL
// Primary Oscillator Mode Select = XT Crystal Oscillator mode
#pragma config POSCMD = XT
// Watchdog Timer Enable = Watchdog Timer enabled/disabled by user software
// (LPRC can be disabled by clearing the SWDTEN bit in the RCON register)
#pragma config FWDTEN = OFF

int main(){
//Init LCD and LEDs
    lcd_initialize();
    led_init();
	
    // Clear the Screen and reset the cursor
    lcd_clear();
    lcd_locate(0, 0);
    
    // Print Hello World
    lcd_printf("Group Members:\n");
    lcd_locate(0, 1);
    lcd_printf("* Xiongzun Zhou\n");
    lcd_locate(0, 2);
    lcd_printf("* Bo He\n");
    lcd_locate(0, 3);
    lcd_printf("* Ke Wang\n");
    uint32_t counter;
 //   int a[30];
 //   int i;
    uint32_t n;
    for(counter=0;counter<1590;counter++){ 
        lcd_locate(0, 7);
        lcd_printf("Counter = %lu", counter+1);
        n = counter; 
        /* Method 1
         * for(i=0;n>0;i++)    
            { 
            a[i] = n % 2;    
            n = n / 2; 
            } 
        lcd_locate(0, 6);
        lcd_printf(" %d", a[0]);
        if(a[0]==1) 
            SETLED(LED5_PORT);
        else if(a[0]==0)
            CLEARLED(LED5_PORT);
        if(a[1]==1) 
            SETLED(LED4_PORT);
        else if(a[1]==0)
            CLEARLED(LED4_PORT);
        if(a[2]==1) 
            SETLED(LED3_PORT);
        else if(a[2]==0)
            CLEARLED(LED3_PORT);
        if(a[3]==1) 
            SETLED(LED2_PORT);
        else if(a[3]==0)
            CLEARLED(LED2_PORT);
        if(a[4]==1) 
            SETLED(LED1_PORT);
        else if(a[4]==0)
            CLEARLED(LED1_PORT);
        */
        
        ////Method 2
        //LEDPORT = ((n & BV(0)) >> 0 << LED5)|((n & BV(1)) >> 1 << LED4)|((n & BV(2)) >> 2 << LED3)|((n & BV(3)) >> 3 << LED2)|((n & BV(4)) >> 4 << LED1);
        //Nop();
        
        /* Method 3
        LED5_PORT = (n & BV(0)) >> 0; Nop();
        LED4_PORT = (n & BV(1)) >> 1; Nop();
        LED3_PORT = (n & BV(2)) >> 2; Nop();
        LED2_PORT = (n & BV(3)) >> 3; Nop();
        LED1_PORT = (n & BV(4)) >> 4; Nop();
        */
        
        //Method 4
        if((n & BV(0)) == 0)
            CLEARLED(LED5_PORT);
        else
            SETLED(LED5_PORT);
    

        if((n & BV(1)) == 0)
            CLEARLED(LED4_PORT);
        else
            SETLED(LED4_PORT);
    
        if((n & BV(2)) == 0)
            CLEARLED(LED3_PORT);
        else
            SETLED(LED3_PORT);
    

        if((n & BV(3)) == 0)
            CLEARLED(LED2_PORT);
        else
            SETLED(LED2_PORT);
    
        if((n & BV(4)) == 0)
            CLEARLED(LED1_PORT);
        else
            SETLED(LED1_PORT);
        
        __delay_ms(100);
         
    }
 
    
    // Stop
    while(1)
        ;
}

