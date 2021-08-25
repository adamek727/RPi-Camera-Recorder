#pragma once

#include <filesystem>
#include <opencv2/opencv.hpp>

class StorageHandler {

public:

    StorageHandler() {
        home_path_ = std::string(getenv("HOME")) + "/";
    }

    void initialize_storage_space();
    void save_image(cv::Mat frame, size_t frame_no);

private:

    void create_directory(const std::string& path);

    std::string home_path_;
    std::string data_path_;
};

