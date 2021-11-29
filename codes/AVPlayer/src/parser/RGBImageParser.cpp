//
// Created by bo on 2021/11/29.
//
#include "header/RGBImageParser.h"



YUVFileData *RGBImageParser::loadFile() {
    YUVFileData* data = new YUVFileData;
    data->data = IImageParser::loadFile("resources/out_rgb24_900x1016.rgb", 900, 1016);
    data->width = 900;
    data->height = 1016;
    data->format = SDL_PIXELFORMAT_RGB24;
    data->pin = data->width * 3; //一行像素占的空间，单位：字节

    yuvFileData = data;
    return data;
}
