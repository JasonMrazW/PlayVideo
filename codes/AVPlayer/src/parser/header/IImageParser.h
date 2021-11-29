//
// Created by bo on 2021/11/29.
//

#ifndef AVPLAYER_IIMAGEPARSER_H
#define AVPLAYER_IIMAGEPARSER_H
#include "YUVFileData.h"

class IImageParser {
public:
    IImageParser() {

    }

    ~IImageParser() {
        yuvFileData = NULL;
    }

    YUVFileData *yuvFileData;

    virtual YUVFileData* loadFile() {
        return NULL;
    }
};

#endif //AVPLAYER_IIMAGEPARSER_H
