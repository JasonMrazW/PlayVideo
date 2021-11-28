//
// Created by bo on 2021/11/27.
//

#include "splite_util.h"

/**
 * parse yuvfile，splite to Y、U、V
 * @param filepath
 * @param format
 * @param width
 * @param height
 */
void SpliteUtil::parseYUVFile(std::string filepath, YUV_FORMAT format, int width, int height) {
    //load yuv file content to memory
    char *fileContent = loadFile(filepath.c_str(), width, height);

    switch (format) {
        case YUV420P:
            toGray(fileContent, width, height);
        case YUV444:
            //loadYUV444();
        case NV12:
            //loadNV12();
        case NV21:
            //loadNV21();
            break;
    }

}

char *SpliteUtil::loadFile(const char *yuvFilePath, int width, int height) {


    //read file
    std::ifstream ifstream;
    ifstream.open(yuvFilePath, std::ios::in | std::ios::binary);
    // read yuv file to binary data
    // default yuv420p
    ifstream.seekg(0,std::ios_base::end);
    int length = ifstream.tellg();
    if (length < 0) {
        return NULL;
    }
    ifstream.seekg(0, std::ios_base::beg);
    int frameSize = width * height * 3/2;
    char* buffer = new char[length];
    ifstream.read(buffer, length);
    //close file
    ifstream.close();

    return buffer;
}

/**
 * 420p数据组织格式
 * Y:1个字节，U：0.5个字节，V:0.5个字节
 * planer组织模式，所有的Y，然后是U
 * @param fileContent
 * @param width
 * @param height
 */
char * SpliteUtil::toGray(char *fileContent, int width, int height) {
    // Y分量所占得大小：width * height
    int y_length = width * height;
    // U、V 分量共同占有得大小：width * height
    int uv_length = width * height;

    int fileLength = strlen(fileContent);
    for (int i = y_length; i < fileLength; ++i) {
        //至为128即为初始值
        fileContent[i] = 128;
    }

    return fileContent;
}

/**
 * 调整YUV图片的亮度
 * @param fileContent
 * @param width
 * @param height
 * @param factor
 * @return
 */
char *SpliteUtil::changeLumaForYUV420P(char *fileContent, int width, int height, float factor) {
    int y_length = width * height;
    for (int i = 0; i < y_length; ++i) {
        fileContent[i] = fileContent[i] * factor;
    }
    return fileContent;
}


