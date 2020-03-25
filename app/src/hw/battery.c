#include "zephyr.h"
#include <device.h>
#include <drivers/gpio.h>
#include "battery.h"

uint16_t battery_voltage = 50;
uint8_t battery_percent = 50;

struct device* charging_dev;

void battery_init()
{

  charging_dev = device_get_binding("GPIO_0");
  gpio_pin_configure(charging_dev, 12, GPIO_DIR_IN);
}

void battery_loop()
{

}

bool battery_get_charging()
{
  u32_t res = 0U;
  gpio_pin_read(charging_dev, 12, &res);
  return res!=1U;
}

uint8_t battery_get_percent()
{

    u32_t res = 0U;
    gpio_pin_read(charging_dev, 12, &res);
    if(res != 1U){
      battery_percent = 100;
    }
    else{
      battery_percent = 0;
    }
    return battery_percent;
}

uint16_t battery_get_voltage()
{
    return battery_voltage;
}
