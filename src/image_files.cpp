#include "image_files.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb_image_write.h"

void drop_to(const std::string& filename, FILE_TYPES type, const std::vector<uint32_t> &image, const size_t w, const size_t h){
    switch (type)
    {
    case FILE_TYPES::PNG:
        stbi_write_png(filename.c_str(), w, h, 4, image.data(), 0 );
        break;
    case FILE_TYPES::JPEG:
        stbi_write_jpg(filename.c_str(), w, h, 4, image.data(), 400);
        break;
    case FILE_TYPES::BMP:
        stbi_write_bmp(filename.c_str(), w, h, 4, image.data());
        break;
    }
}