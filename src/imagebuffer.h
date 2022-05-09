#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

#include <vector>
#include <cinttypes>
#include <string>
#include <functional>

#include "image_files.h"



class ImageBuffer {
public:

    ImageBuffer(size_t w, size_t h, bool clip = false, uint32_t fillcolor = 0);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t get_width() const;

    [[nodiscard]] size_t get_height() const;

    [[nodiscard]] uint32_t get_fillcolor() const;

    void set_fillcolor(uint32_t color);

    [[nodiscard]] bool get_clip() const;

    void set_clip(bool c);

    void resize(size_t w, size_t h);


    [[nodiscard]] bool is_inside(size_t x, size_t y) const;

    uint32_t get_pixel(size_t x, size_t y) const;

    void set_pixel(size_t x, size_t y, uint32_t color);

    void clear();

    void fill_rect(size_t x, size_t y, size_t w, size_t h, uint32_t color);

    void fill_circle(int x, int y, int r, uint32_t color);

    void draw_rect(size_t x, size_t y, size_t w, size_t h, uint32_t color);

    void draw_line(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);

    void draw_circle(int32_t x, int32_t y, int32_t r, uint32_t color);

    void move(size_t x, size_t y);

    void line_to(size_t x, size_t y, uint32_t color);


    typedef std::function<uint32_t (size_t, size_t, const ImageBuffer&)> filter_func_t ;
    ImageBuffer filter(filter_func_t func);



    void drop(const std::string &filename, FILE_TYPES type);

private:

    size_t width;
    size_t height;
    uint32_t fill_color;

    size_t cursor_x = 0;
    size_t cursor_y = 0;
    bool clip;
private:
    std::vector<uint32_t> buffer;
};


#endif //IMAGEBUFFER_H