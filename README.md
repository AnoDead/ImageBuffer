# ImageBuffer
### Simple sandbox for experimenting with images
   Create ImageBuffer object

```cpp
    ...
    ImageBuffer image(1024, 1024, true);
    ...
```
Draw somthing...
```cpp
    ...
    auto size = image.get_width() / 10;

    for(int i=0; i<11; i++)
        for (int j=0; j<11; j++)
            image.draw_circle(j*size, i*size, size/4, COLORS::GREEN);
    
    image.drop("image1.jpeg", FILE_TYPES::JPEG);
    ...
```
... and drop on disk
## image1.jpeg
![image1](https://user-images.githubusercontent.com/15130595/167449800-171132b3-62e4-4136-b1a4-00ec955cba76.jpeg)
... draw more
```cpp
    ...
    size = image.get_width() / 5;
    for(int i=0; i<6; i++)
        for (int j=0; j<6; j++)
            image.fill_circle(j*size, i*size, size/3, COLORS::MAGENTA);
            
    image.drop("image2.jpeg", FILE_TYPES::JPEG);
    ...
```
... and drop
## image2.jpeg
![image2](https://user-images.githubusercontent.com/15130595/167453115-f1b22a47-113f-4448-ae9e-9980cc7632a1.jpeg)

define your filter callback,that will be called for the each pixel...
```cpp
...
RGBA_DATA blur(size_t x, size_t y, const ImageBuffer& buff){
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
...
image.filter(blur).drop("blur.jpeg", FILE_TYPES::JPEG);
...
```
... passing blur filter to ImageBuffer::filter(), and drop 
## blur.jpeg
![blur](https://user-images.githubusercontent.com/15130595/167453171-bec49703-40cd-4151-8409-bd6c60d97632.jpeg)
... invert filter 
```cpp
...
uint32_t invert(size_t x, size_t y, const ImageBuffer& buffer){
    return buffer.get_pixel(x, y).invert();
}
...
  image.filter(blur).filter(invert).drop("invert.jpeg", FILE_TYPES::JPEG);
...
```
## invert.jpeg
![invert](https://user-images.githubusercontent.com/15130595/167453243-c20162f0-f3b5-4d6f-ae58-a45b27887951.jpeg)
