#pragma once

#include <iostream>

class Settings {
public:

    Settings(size_t camera_width,
             size_t camera_height,
             float camera_fps,
             float camera_gain,
             size_t camera_exposition,
             size_t roi_left_top_x,
             size_t roi_left_top_y,
             size_t roi_right_bottom_x,
             size_t roi_right_bottom_y,
             bool debug_imshow) :
            camera_width_ {camera_width},
            camera_height_ {camera_height},
            camera_fps_ {camera_fps},
            camera_gain_ {camera_gain},
            camera_exposition_ {camera_exposition},
            roi_left_top_x_ {roi_left_top_x},
            roi_left_top_y_ {roi_left_top_y},
            roi_right_bottom_x_ {roi_right_bottom_x},
            roi_right_bottom_y_ {roi_right_bottom_y},
            debug_imshow_ {debug_imshow} {

    }

    size_t camera_width() const  {return camera_width_;};
    size_t camera_height() const {return camera_height_;};
    size_t camera_fps() const {return camera_fps_;};
    float camera_gain() const {return camera_gain_;};
    size_t camera_exposition() const {return camera_exposition_;};
    size_t roi_left_top_x() const {return roi_left_top_x_;};
    size_t roi_left_top_y() const {return roi_left_top_y_;};
    size_t roi_right_bottom_x() const {return roi_right_bottom_x_;};
    size_t roi_right_bottom_y() const {return roi_right_bottom_y_;};
    bool debug_imshow() const {return debug_imshow_;};

private:

    size_t camera_width_;
    size_t camera_height_;
    float camera_fps_;
    float camera_gain_;
    size_t camera_exposition_;
    size_t roi_left_top_x_;
    size_t roi_left_top_y_;
    size_t roi_right_bottom_x_;
    size_t roi_right_bottom_y_;
    bool debug_imshow_;
};
