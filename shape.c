#include "shape.h"
#include <assert.h>
#include <stdio.h>

// static function only visible in same file(x) translation unit(v).
static uint32_t Shape_area_(Shape *const self) {
  printf("Shouled not be called");
  assert(0);
  return 0U;
}
// purely virtual function and should not be called.
static void Shape_draw_(Shape *const self) { assert(0); }

void Shape_ctor(Shape *const self, uint16_t x, uint16_t y) {
  static struct ShapeVtbl const vtbl = {&Shape_area_, &Shape_draw_};
  self->x = x;
  self->y = y;
  self->pVtbl = &vtbl;
}

void Shape_moveby(Shape *const self, uint16_t dx, uint16_t dy) {
  self->x += dx;
  self->y += dy;
}

Shape const *LargestShape(Shape *shapes[], size_t nShapes) {
  Shape const *s = NULL;
  uint32_t max = 0U;
  size_t i;
  for (i = 0U; i < nShapes; ++i) {
    uint32_t area = Shape_area(shapes[i]); /* virtual call */

    if (area > max) {
      max = area;
      s = shapes[i];
    }
  }
  return s; /* the largest shape in the array shapes[] */
}
