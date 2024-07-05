/*
 * Copyright (c) 2020 TDK Invensense
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SENSOR_ICM42605_ICM42605_SPI_H_
#define ZEPHYR_DRIVERS_SENSOR_ICM42605_ICM42605_SPI_H_

#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include "icm42605.h"

int inv_spi_bus_check(const union icm42605_bus *bus);
int inv_spi_single_write(const union icm42605_bus *bus, uint8_t reg, uint8_t data);
int inv_spi_read(const union icm42605_bus *bus, uint8_t reg, uint8_t *data, size_t len);

#endif /* __SENSOR_ICM42605_ICM42605_SPI__ */
