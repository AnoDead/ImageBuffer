#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

#include <vector>
#include <cinttypes>
#include <string>
#include <functional>

#include "image_files.h"
#include "colors.h"

using namespace COLORS;


class ImageBuffer {
public:

    ImageBuffer(size_t w, size_t h, bool clip = false, RGBA_DATA fillcolor = COLORS::WHITE);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t get_width() const;

    [[nodiscard]] size_t get_height() const;

    [[nodiscard]] RGBA_DATA get_fillcolor() const;

    void set_fillcolor(RGBA_DATA color);

    [[nodiscard]] bool get_clip() const;

    void set_clip(bool c);

    void resize(size_t w, size_t h);


    [[nodiscard]] bool is_inside(size_t x, size_t y) const;

    RGBA_DATA get_pixel(size_t x, size_t y) const;

    void set_pixel(size_t x, size_t y, RGBA_DATA color);

    void clear();

    void fill_rect(size_t x, size_t y, size_t w, size_t h, RGBA_DATA color);

    void fill_circle(int x, int y, int r, RGBA_DATA color);

    void draw_rect(size_t x, size_t y, size_t w, size_t h, RGBA_DATA color);

    void draw_line(int32_t x1, int32_t y1, int32_t x2, int32_t y2, RGBA_DATA color);

    void draw_circle(int32_t x, int32_t y, int32_t r, RGBA_DATA color);

    void move(size_t x, size_t y);

    void line_to(size_t x, size_t y, RGBA_DATA color);


    typedef std::function<RGBA_DATA (size_t, size_t, const ImageBuffer&)> filter_func_t ;
    ImageBuffer filter(filter_func_t func);



    void drop(const std::string &filename, FILE_TYPES type);

private:

    size_t width;
    size_t height;

    RGBA_DATA fill_color;

    size_t cursor_x = 0;
    size_t cursor_y = 0;
    bool clip;
private:
    std::vector<RGBA_DATA> buffer;
};


#endif //IMAGEBUFFER_H