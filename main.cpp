#include "src/imagebuffer.h"
#include "src/colors.h"

using COLORS::RGBA_DATA;

uint32_t gradient(size_t x, size_t y,const ImageBuffer& b){
    float r = (float)(x + y * b.get_width()) / b.size();
    return RGBA_DATA(r*255, 0, 0);
}

uint32_t blur(size_t x, size_t y, const ImageBuffer& buff){
    float r(0), g(0), b(0);

    int radius = 5;
    for (int i=-radius; i<radius+1; i++){
        for (int j=-radius; j<radius+1; j++){
            RGBA_DATA color;
            if(buff.is_inside(x + j, y + i)){ 
            color  =  buff.get_pixel(x+ j, y +i);
            r += color.r;
            g += color.g;
            b += color.b;}
        }
    }
    auto d = (radius + radius +1) * (radius + radius + 1);
    return RGBA_DATA(r/d, g/d, b/d);
}

uint32_t invert(size_t x, size_t y, const ImageBuffer& buffer){
    return buffer.get_pixel(x, y).invert();
}

int main(){
    ImageBuffer image(1024, 1024, true);

    auto size = image.get_width() / 10;

    for(int i=0; i<11; i++)
        for (int j=0; j<11; j++)
            image.draw_circle(j*size, i*size, size/4, COLORS::GREEN);
    
    image.drop("image1.jpeg", FILE_TYPES::JPEG);

    size = image.get_width() / 5;
    for(int i=0; i<6; i++)
        for (int j=0; j<6; j++)
            image.fill_circle(j*size, i*size, size/3, COLORS::MAGENTA);

    image.drop("image2.jpeg", FILE_TYPES::JPEG);

    image.filter(blur).drop("blur.jpeg", FILE_TYPES::JPEG);
    image.filter(blur).filter(invert).drop("invert.jpeg", FILE_TYPES::JPEG);
}