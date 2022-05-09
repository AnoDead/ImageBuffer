#ifndef IMAGE_FILES_H
#define IMAGE_FILES_H

#include <string>
#include <vector>

enum class FILE_TYPES{
    PNG,
    JPEG,
    BMP
};

void drop_to(const std::string& filename, FILE_TYPES type, const std::vector<uint32_t> &image, const size_t w, const size_t h);

#endif //IMAGE_FILES_H