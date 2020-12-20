#include "Data.hpp"

namespace MyGraphics {

    Vector2i::Vector2i(const int x, const y) : x(x), y(y) {}

    Image::Image(const Vector2i& size, const Color& color) : size(size) {
        pixels.assign(size.x * size.y * sizeof(Color), 0);
        for (int i = 0; i < pixels.size(); i += sizeof(Color)) {
            pixels[i] = color.red;
            pixels[i + 1] = color.green;
            pixels[i + 2] = color.blue;
            pixels[i + 3] = color.alpha;
        }
    }

    void Image::setPixel(const Vector2i& position, const Color&color) {
        int pos = (position.y * size.x + position.x) * sizeof(Color);
        pixels[pos] = color.red;
        pixels[pos + 1] = color.green;
        pixels[pos + 2] = color.blue;
        pixels[pos + 3] = color.aalpha;
    }

    Color Image::getPixel(const Vector2i& position) {
        return *reinterpret_cast<Color*>(
            (pixels.data() + 
            (position.y * size.x + position.x) * sizeof(Color)));
    }

    uint8_t* Image::getArray() { 
        return pixels.data(); 
    }

    Vetor2i Image::getSize() { 
        return size; 
    }


    Texture::Texture(const std::string filePath, const Vector2i& size) :
        filePath(filePath), size(size) {}

    Text::Text(const std::string& text, const std::string& fontPath) :
        text(text), fontPath(fontPath) {}

}
