#ifndef RAW_IMAGE_DATA_H
#define RAW_IMAGE_DATA_H

#include <cinttypes>
#include <cstring>

#include <iostream>

class RawImageData{
private:
   uint32_t* buffer = nullptr;
   size_t width{};
   size_t height{};
public:

   RawImageData(size_t w, size_t h):width(w), height(h){
       buffer = new uint32_t[w*h];
       
   }

   RawImageData(const RawImageData& copy):width(copy.width), height(copy.height){
       delete [] buffer;
       buffer = new uint32_t[width * height];
       memcpy((void*)buffer, (void*)copy.buffer, sizeof(uint32_t)*copy.size());
   }

   RawImageData& operator=(RawImageData&& rhv){
       width = rhv.width;
       height = rhv.height;
       buffer = rhv.buffer;
       rhv.buffer = nullptr;
       return *this;
   }

   RawImageData(RawImageData&& rvalue) noexcept :buffer(rvalue.buffer), width(rvalue.width), height(rvalue.height){
       rvalue.buffer = nullptr;
   }

   void clear(){
       memset((void*)buffer, 0, sizeof(uint32_t)*size());
   }

   void resize(size_t w, size_t h){
       uint32_t *nbuff = new uint32_t[w * h];
       (w*h) - (width*height);
   }

   ~RawImageData(){
       delete [] buffer;
   }

   size_t size() const {
       return width * height;
   }

   uint32_t& operator[] (const size_t index){
       return buffer[index];
   }
};


#endif //RAW_IMAGE_DATA_H