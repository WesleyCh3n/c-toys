#include "rectangle.h"
#include <stdio.h>

// static function only visible in same file.
static uint32_t Rectangle_area_(Shape *const self) {
  printf("Rect area impl called\n");
  Rectangle *self_ = (Rectangle *)self;
  return self_->width * self_->height;
}
// purely virtual function and should not be called.
static void Rectangle_draw_(Shape *const self) {}

void Rectangle_ctor(Rectangle *const self, uint16_t x, uint16_t y,
                    uint16_t width, uint16_t height) {
  static struct ShapeVtbl const vtbl = {&Rectangle_area_, &Rectangle_draw_};
  Shape_ctor(&self->super, x, y);
  self->super.pVtbl = &vtbl;
  self->width = width;
  self->height = height;
}

void Rectangle_log(Rectangle *const self) {
  printf("R x: %d, y: %d, w: %d, h: %d\n", self->super.x, self->super.y,
         self->width, self->height);
}
