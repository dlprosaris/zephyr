// SPDX-License-Identifier: Apache-2.0

#include <zephyr/logging/log.h>

#include "icm42605.h"

#if ICM42605_BUS_I2C
LOG_MODULE_DECLARE(ICM42605, CONFIG_SENSOR_LOG_LEVEL);
int inv_i2c_bus_check(const union icm42605_bus *bus)
{
  return device_is_ready(bus->i2c.bus) ? 0 : -ENODEV;
}

int inv_i2c_single_write(const union icm42605_bus *bus, uint8_t reg, uint8_t data)
{
  return i2c_reg_write_byte_dt(&bus->i2c, reg, data);
}

int inv_i2c_read(const union icm42605_bus *bus, uint8_t reg, uint8_t *data, size_t len)
{
  return i2c_burst_read_dt(&bus->i2c, reg, data, len);
}

const struct icm42605_bus_io icm42605_bus_io_i2c = {
  .check = inv_i2c_bus_check,
  .write = inv_i2c_single_write,
  .read = inv_i2c_read,
};

#endif /* ICM42605_BUS_I2C */
