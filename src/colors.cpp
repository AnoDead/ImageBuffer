#include "colors.h"
#include <cinttypes>

namespace COLORS{
        RGBA_DATA::RGBA_DATA(const uint32_t color){
            *this = unpack(color);
        }

        RGBA_DATA::RGBA_DATA(const uint8_t r,const uint8_t g, const uint8_t b,const uint8_t a):
        r(r), g(g), b(b), a(a){}


        RGBA_DATA RGBA_DATA::operator=(const RGBA_DATA& rhv){
            r = rhv.r;
            g = rhv.g;
            b = rhv.b;
            a = rhv.a;
            return *this;
        }


        RGBA_DATA RGBA_DATA::operator+(const RGBA_DATA& rhv) const{
            return RGBA_DATA(r + rhv.r, g + rhv.g, b + rhv.b, a + rhv.a);
        }

        RGBA_DATA RGBA_DATA::operator-(const RGBA_DATA& rhv) const{
            return RGBA_DATA(r  - rhv.r, g - rhv.g, b - rhv.b, a - rhv.a);
        }

        RGBA_DATA::operator uint32_t() const{
            return pack();
        }


        RGBA_DATA RGBA_DATA::invert() const{
            return pack() ^ 0x00ffffff;
        }

        uint32_t RGBA_DATA::pack() const{
            return (a<<24) + (b<<16) + (g<<8) + r;
        }





        uint32_t pack(const RGBA_DATA& data){
            return data.pack();
        }

        RGBA_DATA unpack(const uint32_t color){
            auto* data = (RGBA_DATA*)&color;
            return *data;
        }

        RGBA_DATA rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
            return RGBA_DATA(r, g, b, a);
        }

        uint32_t rgba_r(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
            return (a<<24) + (b<<16) + (g<<8) + r;
        }
    
};
