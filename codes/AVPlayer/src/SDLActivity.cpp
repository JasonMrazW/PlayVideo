//
//  SDLActivity.cpp
//  AVProject
//
//  Created by bo on 2021/11/26.
//

#include "SDLActivity.hpp"


// ============================================================================
// [Defines & Constants]
// ============================================================================
#define APPTITLE         "SDL2 Template Program"

const int SCREEN_WIDTH     = 800;
const int SCREEN_HEIGHT    = 600;

const int file_width = 970;
const int file_height = 583;
const char * filePath = "resources/out_bg_yuv420p.yuv";


CApp::CApp() :
    running(false)
{
}

CApp::~CApp()
{
    OnCleanup();
}

int CApp::OnInit()
{
    // Initialize the SDL library.
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
        return APP_FAILED;
    }
    
    window = SDL_CreateWindow(APPTITLE,
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    if (window != NULL) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        char * temp = SpliteUtil::loadFile(filePath, file_width, file_height);

        yuvData = SpliteUtil::toGray(temp, file_width, file_height);
//        yuvData = SpliteUtil::changeLumaForYUV420P(temp, file_width, file_height, 0.2);
//        yuvData = SpliteUtil::addBorderForYUV420P(temp, file_width, file_height, 50);


        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING, file_width, file_height);
    }
    
    // Success
    return APP_OK;
}

void CApp::OnCleanup()
{
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != NULL)    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

int CApp::OnExecute()
{
    // Initialize application.
    int state = OnInit();
    if (state != APP_OK) {
        return state;
    }
    
    // Enter the SDL event loop.
    SDL_Event event;

    running = true;
    
    while (running)
    {
        while (SDL_PollEvent(&event)) {
            OnEvent(&event);
        }
        
        OnUpdate();
        OnRender();
    }
    
    return state;
}

void CApp::OnEvent(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_QUIT:
            running = false;
            break;
            
        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        default:
            break;
    }
}

void CApp::OnUpdate()
{
    // Update your game logic here
}

void CApp::OnRender()
{
    SDL_UpdateTexture(texture, nullptr, yuvData, file_width);

    SDL_RenderClear(renderer);
    // Do your drawing here
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    
    SDL_RenderPresent(renderer);
}

