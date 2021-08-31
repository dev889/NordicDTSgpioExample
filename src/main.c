/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "valve1" alias. */
#define VALVE_NODE DT_ALIAS(valve1)

#if DT_NODE_HAS_STATUS(VALVE_NODE, okay)
#define VALVE_LABEL	DT_GPIO_LABEL(VALVE_NODE, gpios)
#define VALVE_PIN	DT_GPIO_PIN(VALVE_NODE, gpios)
#define VALVE_FLAGS	DT_GPIO_FLAGS(VALVE_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported valve1: led0 devicetree alias is not defined"
#endif

void main(void)
{
	const struct device *devValve1;
	bool valve_is_on = true;
	int ret;

	devValve1 = device_get_binding(VALVE_LABEL);
	if (devValve1 == NULL) {
		return;
	}

	ret = gpio_pin_configure(devValve1, VALVE_PIN, GPIO_OUTPUT_ACTIVE | VALVE_FLAGS);
	if (ret < 0) {
		return;
	}

	while (1) {
		gpio_pin_set(devValve1, VALVE_PIN, (int)valve_is_on);
		valve_is_on = !valve_is_on;
		k_msleep(SLEEP_TIME_MS);
	}
}
