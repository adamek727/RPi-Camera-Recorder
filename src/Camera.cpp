#include "SingleCamera/Camera.hpp"


Camera::Camera(int camera_index, const Settings& settings) :
        camera_index_{camera_index},
        settings_{settings} {

    open_camera();
    if (!cap_.isOpened()) {
        std::cerr << "Unable to open camera " << camera_index << std::endl;
    }
    frame_counter_ = 0;
}


cv::Mat Camera::get_frame() {
    cv::Mat frame;

    if (!cap_.isOpened()) {
        open_camera();
    }
    if (!cap_.isOpened()) {
        std::cerr << "Camera " << camera_index_ << " is not opened"  << std::endl;
        return frame;
    }

    cap_.read(frame);
    frame_counter_ += 1;
    return frame;
}


void Camera::open_camera() {
    cap_.open(camera_index_);
    cap_.set(CV_CAP_PROP_FRAME_WIDTH, settings_.camera_width());
    cap_.set(CV_CAP_PROP_FRAME_HEIGHT, settings_.camera_height());
    cap_.set(CV_CAP_PROP_FPS, settings_.camera_fps());
    cap_.grab();
}