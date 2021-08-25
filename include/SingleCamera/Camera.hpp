#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "Settings.hpp"

class Camera {
public:

    Camera() = delete;
    Camera(int camera_index, const Settings& settings);

    cv::Mat get_frame();
    size_t get_frame_number() const { return frame_counter_; }

private:

    void open_camera();

    int camera_index_;
    const Settings& settings_;
    cv::VideoCapture cap_;
    size_t frame_counter_;
};
