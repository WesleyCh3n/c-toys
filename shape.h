#ifndef SHAPE_H
#define SHAPE_H
#include <stdint.h>
#include <stdio.h>

struct ShapeVtbl;
typedef struct {
  struct ShapeVtbl const *pVtbl;
  uint16_t x;
  uint16_t y;
} Shape;

struct ShapeVtbl {
  uint32_t (*area)(Shape *const self);
  void (*draw)(Shape *const self);
};

void Shape_ctor(Shape *const self, uint16_t x, uint16_t y);
void Shape_moveby(Shape *const self, uint16_t dx, uint16_t dy);

static inline uint32_t Shape_area(Shape *const self) {
  printf("Shape area inline called\n");
  return self->pVtbl->area(self);
};

Shape const *LargestShape(Shape *shapes[], size_t nShapes);

#endif
