/***********************************************************************
*
*   Module Name:
*                led.h
*
*   Author     : CC
*   Create Time: 2022-01-29
**********************************************************************/
#ifndef _LED_H
#define _LED_H

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define LED1_NODE DT_ALIAS( led1 )
#define LED2_NODE DT_ALIAS( led2 )
#define LED3_NODE DT_ALIAS( led3 )

enum LED{
#if DT_NODE_HAS_STATUS( LED1_NODE, okay )
LED1,
#endif

#if DT_NODE_HAS_STATUS( LED2_NODE, okay )
LED2,
#endif

#if DT_NODE_HAS_STATUS( LED3_NODE, okay )
LED3,
#endif
LED_PORT_CNT
};

/**********************************************************************
*
*   Procedure Name:
*        led_init - Init the LED
*
*   Description:
*  
*
**********************************************************************/
int led_init
		(
		enum LED port
		);

/***********************************************************************
*
*   Procedure Name:
*        led_on - Turn on the LED
*
*   Description:
*  
*
**********************************************************************/
void led_on
		(
		enum LED port
		);

/***********************************************************************
*
*   Procedure Name:
*        led_off - Turn off the LED
*
*   Description:
*  
*
**********************************************************************/
void led_off
		(
		enum LED port
		);

#endif /* _LED_H */

