#include <iostream>

#include "SingleCamera/Application.hpp"
#include "YamlService/YamlService.hpp"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Missing argument" << std::endl;
        std::cerr << "Usage: SingleCamera <path_to_config>" << std::endl;
        return -1;
    }

    auto yaml = YamlService(std::string(argv[1]));

    auto settings = Settings{
        yaml.getUInt32Value({"camera", "width"}),
        yaml.getUInt32Value({"camera", "height"}),
        yaml.getFloatValue({"camera", "fps"}),
        0.0f,
        yaml.getInt32Value({"camera", "exposition"}),
        0.0f,

        yaml.getBoolValue({"roi", "enable"}),
        yaml.getUInt32Value({"roi", "left_top_x"}),
        yaml.getUInt32Value({"roi", "left_top_y"}),
        yaml.getUInt32Value({"roi", "right_bottom_x"}),
        yaml.getUInt32Value({"roi", "right_bottom_y"}),

        yaml.getBoolValue({"debug", "imshow"}),
    };

    auto app = Application(settings);
    app.run();
    return 0;
}
