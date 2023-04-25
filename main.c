#include <stdio.h>

#include "rectangle.h"
#include "shape.h"

int main(int argc, char *argv[]) {
  Shape s1, s2;
  Shape_ctor(&s1, 0, 0);
  Shape_ctor(&s2, 1, 1);
  Shape_moveby(&s1, 1, 2);
  Shape_moveby(&s1, 3, 4);

  Rectangle r1, r2;
  Rectangle_ctor(&r1, 0, 0, 2, 2);
  Rectangle_ctor(&r2, 0, 0, 3, 4);
  printf("r1 area: %d\n", Shape_area((Shape *)&r1));

  Shape *rs[] = {(Shape *)&r1, (Shape *)&r2};
  const Shape *s = LargestShape(rs, 2);
  Rectangle_log((Rectangle *)s);

  return 0;
}
