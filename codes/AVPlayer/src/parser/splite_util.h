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

    static  char *      toGray(char *fileContent, int width, int height);

    /**
     * YUV文件亮度调整
     * @param fileContent
     * @param width
     * @param height
     * @return
     */
    static char*        changeLumaForYUV420P(char *fileContent, int width, int height, float factor);

    /**
     * 添加简单的边框效果
     * @param fileContent
     * @param width
     * @param height
     * @param border
     * @return
     */
    static char*        addBorderForYUV420P(char *fileContent, int width, int height, int border);
};




#endif //AVPLAYER_SPLITE_UTIL_H
