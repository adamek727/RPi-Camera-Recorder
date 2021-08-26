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

    if (settings_.roi_enable()) {
        frame = frame(cv::Range(settings_.roi_left_top_y(), settings_.roi_right_bottom_y()),
                      cv::Range(settings_.roi_left_top_x(), settings_.roi_right_bottom_x()));
    }
    return frame;
}


void Camera::open_camera() {
    std::cout << "Opening camera" << std::endl;
    cap_.open(camera_index_);


    std::cout << "width: " << settings_.camera_width() << std::endl;
    cap_.set(CV_CAP_PROP_FRAME_WIDTH, settings_.camera_width());
    std::cout << "height: " << settings_.camera_height() << std::endl;
    cap_.set(CV_CAP_PROP_FRAME_HEIGHT, settings_.camera_height());
    std::cout << "fps: " << settings_.camera_fps() << std::endl;
    cap_.set(CV_CAP_PROP_FPS, settings_.camera_fps());

    std::stringstream ss;
    ss << "v4l2-ctl -d /dev/video" << camera_index_ << " -c auto_exposure=1 -c exposure_time_absolute=" << settings_.camera_exposition();
    std::cout << ss.str() << std::endl;
    system(ss.str().c_str());

    std::cout << "Camera online" << std::endl;
    cap_.grab();
}