#include <iostream>
#include "SDLActivity.hpp"

int main() {
    std::cout << "start!" << sizeof (char) <<"||||||" << std::endl;
    CApp app;
    return app.OnExecute();
}
