#include "src/imagebuffer.h"
#include "src/colors.h"


uint32_t gradient(size_t x, size_t y,const ImageBuffer& b){
    float r = (float)(x + y * b.get_width()) / b.size();
    return COLORS::rgba_r(r*255, 0, 0);
}

uint32_t blur(size_t x, size_t y, const ImageBuffer& buff){
    float r(0), g(0), b(0);

    int radius = 8;
    for (int i=-radius; i<radius+1; i++){
        for (int j=-radius; j<radius+1; j++){
            uint32_t color = 0;
            color  = buff.is_inside(x + j, y + i) ?  buff.get_pixel(x+ j, y +i): COLORS::WHITE ;
            r += COLORS::unpack(color).r;
            g += COLORS::unpack(color).g;
            b += COLORS::unpack(color).b;
        }
    }
    auto d = (radius + radius +1) * (radius + radius + 1);
    return COLORS::rgba_r(r/d, g/d, b/d);
}

uint32_t invert(size_t x, size_t y, const ImageBuffer& buffer){
    return buffer.get_pixel(x, y) ^ 0x00ffffff;
}


int main(){
    const size_t w(512), h(512);
    ImageBuffer image(w, h, false, COLORS::WHITE);

    image.fill_circle(200, 200, 100, COLORS::BLACK);
    image.fill_rect(0, 0, 200, 200, COLORS::OCEAN);

    auto result_image = image.filter(blur).filter(blur);
    result_image.drop("res.png", FILE_TYPES::PNG);
    image.drop("pic.png", FILE_TYPES::PNG);
}