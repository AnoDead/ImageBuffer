#include "imagebuffer.h"


int main(){
    const size_t w(512), h(512);
    ImageBuffer buffer(w, h);

    buffer.draw_rect(0, 0, w-1, h-1, COLOR::RED);

    buffer.fill_rect(0, 0, w/2, h/2, COLOR::rgba_r(123, 22, 200));
    buffer.fill_rect(w/2, 0, (w/2)-1, h/2, COLOR::rgba_r(2, 60, 200));


    buffer.draw_circle(512/2, 512/2, 200, COLOR::BLUE);
    buffer.draw_line(512/2, 0, 512/2, 511,COLOR::GREEN);
    buffer.draw_line(0, 512/2, 511, 512/2, COLOR::GREEN);
    buffer.fill_circle(w/2, h/2, 100, COLOR::RED);

    buffer.drop_to_ppm("example.ppm");
}