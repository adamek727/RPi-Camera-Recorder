#pragma once

#include "Settings.hpp"
#include "StorageHandler.hpp"
#include "Camera.hpp"

class Application {
public:

    Application() = delete;
    Application(const Settings& settings) :
            settings_{settings},
            camera_(0, settings) {


    }

    void run();

private:

    const Settings& settings_;
    StorageHandler storage_handler_;
    Camera camera_;
};
