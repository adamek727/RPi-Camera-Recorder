#pragma once

#include <iostream>

class Settings {
public:

    Settings(size_t width, size_t height, float fps) :
            width_{width},
            height_{height},
            fps_{fps} {

    }

    size_t width() const  {return width_;};
    size_t height() const {return height_;};
    size_t fps() const {return fps_;};

private:

    size_t width_;
    size_t height_;
    float fps_;
};
