
#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>

#include "SingleCamera/StorageHandler.hpp"
#include "SingleCamera/Timestamp.hpp"

void StorageHandler::initialize_storage_space() {

    data_path_ = home_path_  + "Data/" + current_date_time() + '/';
    create_directory(data_path_);
}


void StorageHandler::save_image(cv::Mat frame, size_t frame_no) {


    std::stringstream path;
    path << data_path_ << std::setw(6) << std::setfill('0') << frame_no << ".jpg";
    std::cout << "saving image" << path.str() << std::endl;
    cv::imwrite(path.str(), frame);
}


void StorageHandler::create_directory(const std::string& path) {
    std::cout << "making directory: " << path << std::endl;
    std::filesystem::create_directory(path);
}