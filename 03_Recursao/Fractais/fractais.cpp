#define XPAINT
#include "xpaint.h"
#include <iostream>

void draw_line(int size) {
    if (size < 6)
        return;
    x_pen_walk(size);
    x_pen_rotate(-55);
    draw_line(size - 5);
}

int main() {
    x_open(920, 560, "Rosa_negra");
    x_pen_set_thick(3);
    x_pen_set_angle(90);
    x_pen_set_pos(185, 450);
    draw_line(275);
    x_save();
    x_close();
}