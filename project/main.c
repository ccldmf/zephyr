/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "./modules/led/led.h"

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000


void main(void)
{
	int ret;
	
	ret = led_init( LED1 );
	if( ret < 0 )
	{
		printk("LED Init Fail\n");
	}
	
	ret = led_init( LED2 );
	if( ret < 0 )
	{
		printk("LED Init Fail\n");
	}
	
	ret = led_init( LED3 );
	if( ret < 0 )
	{
		printk("LED Init Fail\n");
	}

	while (1) {
		led_off( LED1 );
		led_on( LED2 );
		led_off( LED3 );
		k_msleep(SLEEP_TIME_MS);
		led_on( LED1 );
		led_off( LED2 );
		led_on( LED3 );
		k_msleep(SLEEP_TIME_MS);
	}
}
