//
// Created by bo on 2021/11/29.
//

#ifndef AVPLAYER_YUVIMAGEPARSER_H
#define AVPLAYER_YUVIMAGEPARSER_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "header/IImageParser.h"
#include <SDL_pixels.h>

class YUVImageParser : public IImageParser{
public:
    YUVImageParser();

    YUVFileData* loadFile() {
        return NULL;
    }
    /**
     * 加载yuv文件，返回 char*指针
     * @param yuvFilePath
     * @param width
     * @param height
     * @return
     */
    static char *       loadFile(const char *yuvFilePath, int width, int height);

    char *      toGray(char *fileContent, int width, int height);

    /**
     * YUV文件亮度调整
     * @param fileContent
     * @param width
     * @param height
     * @return
     */
    char*        changeLumaForYUV420P(char *fileContent, int width, int height, float factor);

    /**
     * 添加简单的边框效果
     * @param fileContent
     * @param width
     * @param height
     * @param border
     * @return
     */
    char*        addBorderForYUV420P(char *fileContent, int width, int height, int border);
};

#endif //AVPLAYER_YUVIMAGEPARSER_H
