//
// Created by bo on 2021/11/27.
//

#ifndef AVPLAYER_SPLITE_UTIL_H
#define AVPLAYER_SPLITE_UTIL_H
#include <iostream>
#include <cstdlib>
#include <fstream>

class SpliteUtil {
public:
    SpliteUtil();

    ~SpliteUtil();

    enum YUV_FORMAT {
        YUV420P,YUV444,NV21,NV12
    };

    static void  parseYUVFile(std::string filepath, YUV_FORMAT format, int width, int height);

    /**
     * 加载yuv文件，返回 char*指针
     * @param yuvFilePath
     * @param width
     * @param height
     * @return
     */
    static char *       loadFile(const char *yuvFilePath, int width, int height);

    static  char * loadYUV420P(char *fileContent, int width, int height);

    static void loadYUV444();

    static void loadNV12();

    static void loadNV21();
};




#endif //AVPLAYER_SPLITE_UTIL_H
