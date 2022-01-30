/***********************************************************************
*
*   Module Name:
*                led.c
*
*   Author     : CC
*   Create Time: 2022-01-29
**********************************************************************/
#include <assert.h>
#include "led.h"

#define LED_ON   ( 1 )
#define LED_OFF  ( 0 )

static const char* LED_NAME[] = 
{
#if DT_NODE_HAS_STATUS( LED1_NODE, okay )
DT_GPIO_LABEL( LED1_NODE, gpios ),
#endif

#if DT_NODE_HAS_STATUS( LED2_NODE, okay )
DT_GPIO_LABEL( LED2_NODE, gpios ),
#endif

#if DT_NODE_HAS_STATUS( LED3_NODE, okay )
DT_GPIO_LABEL( LED3_NODE, gpios ),
#endif
};

static const gpio_pin_t LED_PIN[] = 
{
#if DT_NODE_HAS_STATUS( LED1_NODE, okay )
DT_GPIO_PIN( LED1_NODE, gpios ),
#endif

#if DT_NODE_HAS_STATUS( LED2_NODE, okay )
DT_GPIO_PIN( LED2_NODE, gpios ),
#endif

#if DT_NODE_HAS_STATUS( LED3_NODE, okay )
DT_GPIO_PIN( LED3_NODE, gpios ),
#endif
};

static const gpio_flags_t LED_FLAGS[] = 
{
#if DT_NODE_HAS_STATUS( LED1_NODE, okay )
DT_GPIO_FLAGS( LED1_NODE, gpios ),
#endif

#if DT_NODE_HAS_STATUS( LED2_NODE, okay )
DT_GPIO_FLAGS( LED2_NODE, gpios ),
#endif

#if DT_NODE_HAS_STATUS( LED3_NODE, okay )
DT_GPIO_FLAGS( LED3_NODE, gpios ),
#endif
};

typedef struct
{
const struct device *led_port;
} LED_Control;

static LED_Control led_control_array[ LED_PORT_CNT ];

/**********************************************************************
*
*   Procedure Name:
*        led_init - Init the LED
*
*   Description:
*  		If return value < 0, init error.
*	
**********************************************************************/
int led_init
		(
		enum LED port
		)
{
	int ret;
	
	assert( port >= LED_PORT_CNT );
	led_control_array[ port ].led_port = device_get_binding( LED_NAME[ port ] ); 
	ret = gpio_pin_configure( led_control_array[ port ].led_port, LED_PIN[ port ], GPIO_OUTPUT_ACTIVE | LED_FLAGS[ port ] );
	return ret;
}

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
		)
{
	gpio_pin_set( led_control_array[ port ].led_port, LED_PIN[ port ], LED_ON );
}

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
		)
{
	gpio_pin_set( led_control_array[ port ].led_port, LED_PIN[ port ], LED_OFF );
}

