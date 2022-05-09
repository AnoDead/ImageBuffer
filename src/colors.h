#ifndef COLORS_H
#define COLORS_H

#include <cinttypes>

namespace COLORS{

    struct RGBA_DATA{
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        RGBA_DATA(const uint8_t r = 0,const uint8_t g = 0,const uint8_t b= 0,const uint8_t a = 255);
        RGBA_DATA operator-(const RGBA_DATA& rhv) const;
        RGBA_DATA operator+(const RGBA_DATA& rhv) const;

        uint32_t pack() const;
        RGBA_DATA invert() const;
    };

    uint32_t pack(const RGBA_DATA& data);

    RGBA_DATA unpack(const uint32_t color);

    RGBA_DATA rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255);

    uint32_t rgba_r(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255);


    [[maybe_unused]] const uint32_t WHITE =     rgba_r(255, 255, 255);
    [[maybe_unused]] const uint32_t BLACK =     rgba_r(0, 0, 0);

    [[maybe_unused]] const uint32_t RED   =     rgba_r(255, 0, 0);
    [[maybe_unused]] const uint32_t GREEN =     rgba_r(0, 255, 0);
    [[maybe_unused]] const uint32_t BLUE  =     rgba_r(0, 0, 255);
    [[maybe_unused]] const uint32_t YELLOW  =   rgba_r(255, 255, 0);
    [[maybe_unused]] const uint32_t MAGENTA  =  rgba_r(255, 0, 255);
    [[maybe_unused]] const uint32_t CYAN  =     rgba_r(0, 255, 255);

    [[maybe_unused]] const uint32_t ORANGE  =   rgba_r(255, 125, 0);
    [[maybe_unused]] const uint32_t RASPBERRY = rgba_r(255, 0, 125);
    [[maybe_unused]] const uint32_t VIOLET  =   rgba_r(125, 0, 255);
    [[maybe_unused]] const uint32_t OCEAN  =    rgba_r(0, 125, 255);
};


#endif //COLORS_H
