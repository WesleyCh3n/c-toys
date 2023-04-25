#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include <stdio.h>

typedef struct {
  Shape super; // NOTE: this order affect pointer casting
  uint16_t width;
  uint16_t height;
} Rectangle;

void Rectangle_ctor(Rectangle *const self, uint16_t x, uint16_t y,
                    uint16_t width, uint16_t height);
void Rectangle_log(Rectangle *const self);
#endif
