//
//  SDLActivity.hpp
//  AVProject
//
//  Created by bo on 2021/11/26.
//

#ifndef SDLActivity_hpp
#define SDLActivity_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <fstream>

// ============================================================================
// [CApp]
// ============================================================================
// This is just a sample SDL application class to test that the app works.
class CApp
{
public:

    // Application state
    enum APP_STATE
    {
        APP_OK = 0,
        APP_FAILED = 1
    };

    CApp();
    ~CApp();
    
    // Run application, called by your code.
    int             OnExecute();

private:
    
    // Whether the application is running.
    bool             running;

    SDL_Window*        window;
    SDL_Renderer*    renderer;
    SDL_Surface*     surface;
    SDL_Texture*     texture;
    char*           yuvData;

    // Initialize application
    int             OnInit();
    
    // Clean up the application
    void             OnCleanup();

    // Called to process SDL event.
    void             OnEvent(SDL_Event* event);

    // Called to update game logic
    void            OnUpdate();
    
    // Called to render the app.
    void             OnRender();

    static char * loadYuvData(char *yuvFilePath, int width, int height);
};

#endif /* SDLActivity_hpp */
