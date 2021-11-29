#include <iostream>
#include "SDLActivity.hpp"
#include "parser/YUVImageParser.h"

int main() {
    std::cout << "start!" << sizeof (char) <<"||||||" << std::endl;
    CApp app;
    IImageParser *parser = new YUVImageParser;
    parser->loadFile();
    return app.OnExecute(parser);
}
