#include <iostream>

#include "SingleCamera/Application.hpp"

int main() {

    auto settings = Settings{
//        4056,
//        3040,
        2560,
        1440,
        1,
    };

    auto app = Application(settings);
    app.run();
    return 0;
}
