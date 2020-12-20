#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <cstdint>
#include <string>

namespace MyGraphics {

    struct Vector2i {
        Vector2i(const int x = 0, const int y = 0);
        const int x;
        const int y;
    };

    struct Color {
        Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha);
        Color(const uint32_t color);

        uint32_t getColor() const;

        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
    };

    struct Image {
    private:
        std::vector<uint8_t> pixels;
        Vector2i size;

    public:
        Image(const Vector2i& size, const Color& color);
  
        void setPixel(const Vector2i& position, const Color& color);
        Color getPixel(const Vector2i& position);
  
        uint8_t* getArray();
        Vector2i getSize();
    };

    struct Texture {
        Texture(const std::string& filePath, const Vector2i& size);

        std::string filePath;
        Vector2i size;
    };

    struct Text {
        Text(const std::string& text, const std::string& fontPath);

        std::string text;
        std::string fontPath;
    };

}

#endif //__DATA_HPP__
