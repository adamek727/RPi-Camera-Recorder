#include "SingleCamera/Application.hpp"
#include <chrono>

void Application::run() {

    storage_handler_.initialize_storage_space();

    while (true) {

        auto start = std::chrono::high_resolution_clock::now();

        auto frame = camera_.get_frame();
        storage_handler_.save_image(frame, camera_.get_frame_number());

        while (true) {
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
            if (duration >= (1/settings_.fps() * 1000)) {break;}
        }

        if (cv::waitKey(1) == 0) {
            break;
        }
    }
}