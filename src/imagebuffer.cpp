
#include <cassert>
#include <cmath>

#include "imagebuffer.h"
#include "image_files.h"

// void ImageBuffer::drop(const std::string &filename, FILE_TYPES type) {
//     // drop_ppm_image(filename, buffer, width, height);
//     drop_to(filename, type, buffer, width, height);
// }


ImageBuffer::ImageBuffer(size_t w, size_t h, bool clip, uint32_t fillcolor) :
        buffer(w * h, fillcolor), width(w), height(h), clip(clip), fill_color(fillcolor) {
}

size_t ImageBuffer::size() const{
    return width * height;
}

size_t ImageBuffer::get_width() const { return width; }

size_t ImageBuffer::get_height() const { return height; }

uint32_t ImageBuffer::get_fillcolor() const { return fill_color; }

void ImageBuffer::set_fillcolor(uint32_t color) { fill_color = color; }

bool ImageBuffer::get_clip() const { return clip; }

void ImageBuffer::set_clip(bool c) { clip = c; }

void ImageBuffer::resize(size_t w, size_t h) {
    width = w;
    height = h;
    // buffer.resize(w * h);
}


bool ImageBuffer::is_inside(size_t x, size_t y) const {
    return (x >= 0 && x < width) && (y >= 0 && y < height);
}


uint32_t ImageBuffer::get_pixel(size_t x, size_t y) const{
    assert(is_inside(x, y));
    return buffer[x + y * width];
}


void ImageBuffer::set_pixel(size_t x, size_t y, uint32_t color) {

    if (clip && !is_inside(x, y)){
        return;
    }
    size_t index = x + y * width;
    assert(is_inside(x, y));
    buffer[index] = color;
}


void ImageBuffer::clear() {
    for (auto &i: buffer)
        i = fill_color;
}


void ImageBuffer::fill_rect(size_t x, size_t y, size_t w, size_t h, uint32_t color) {
    for (size_t i=0; i<w; i++) {
        for (size_t j=0; j<h; j++) {
            size_t cx = x+i;
            size_t cy = y+j;
            if (cx>=width || cy>=height) continue; 
            set_pixel(cx, cy, color);
        }
    }
}

void ImageBuffer::fill_circle(int x, int y, int r, uint32_t color) {
    for (int cy = y - r; cy < y + r; cy++)
        for (int cx = x - r; cx < x + r; cx++)
            if (pow(cx - x, 2) + pow(cy - y, 2) <= pow(r, 2))
                set_pixel(cx, cy, color);

}


void ImageBuffer::draw_rect(size_t x, size_t y, size_t w, size_t h, uint32_t color) {
    move(x, y);
    line_to(x + w, y, color);
    line_to(x + w, y + h, color);
    line_to(x, y + h, color);
    line_to(x, y, color);
    move(0, 0);
}


void ImageBuffer::move(size_t x, size_t y) {
    cursor_x = x;
    cursor_y = y;
}


void ImageBuffer::line_to(size_t x, size_t y, uint32_t color) {
    draw_line(cursor_x, cursor_y, x, y, color);
    move(x, y);
}


void ImageBuffer::draw_line(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color) {
    float dX, dY, L;
    L = std::max(abs(x2 - x1), abs(y2 - y1));
    dX = (x2 - x1) / L;
    dY = (y2 - y1) / L;
    float cx(x1), cy(y1);
    for (int i(0); i < L; i++) {
        set_pixel(cx, cy, color);
        cx += dX;
        cy += dY;
    }
}


void ImageBuffer::draw_circle(int32_t x, int32_t y, int32_t r, uint32_t color) {
    move(x + cos(0) * r, y + sin(0) * r);
    for (int i = 0; i < 360; i++) {
        auto cx = x + cos(i * M_PI / 180) * r;
        auto cy = y + sin(i * M_PI / 180) * r;
        line_to(cx, cy, color);
    }
}

#include "image_files.h"

void ImageBuffer::drop(const std::string &filename, FILE_TYPES type) {
    // drop_ppm_image(filename, buffer, width, height);
    drop_to(filename, type, buffer, width, height);
}

ImageBuffer ImageBuffer::filter(filter_func_t func) {
    ImageBuffer buffer(width, height, clip, fill_color);
    for (size_t y = 0; y < height; y++)
        for (size_t x = 0; x < width; x++)
            buffer.set_pixel(x, y, func(x, y, *this));
    return std::move(buffer);
}