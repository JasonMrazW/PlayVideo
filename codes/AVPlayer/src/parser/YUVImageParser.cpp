//
// Created by bo on 2021/11/29.
//

#include "YUVImageParser.h"
const int tmp_file_width = 970;
const int tmp_file_height = 583;
const char * tmp_filePath = "resources/out_bg_yuv420p.yuv";

YUVImageParser::YUVImageParser() {

}
YUVFileData *YUVImageParser::loadFile() {
    YUVFileData *fileData = new YUVFileData();
    fileData->data = loadFile(tmp_filePath, tmp_file_width, tmp_file_height);
    fileData->width = tmp_file_width;
    fileData->height = tmp_file_height;
    fileData->format = SDL_PIXELFORMAT_IYUV;

    yuvFileData = fileData;
    return fileData;
}

char *YUVImageParser::loadFile(const char *yuvFilePath, int width, int height) {


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
char * YUVImageParser::toGray(char *fileContent, int width, int height) {
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
char *YUVImageParser::changeLumaForYUV420P(char *fileContent, int width, int height, float factor) {
    int y_length = width * height;
    for (int i = 0; i < y_length; ++i) {
        fileContent[i] = fileContent[i] * factor;
    }
    return fileContent;
}

/**
 * 添加简单的边框效果
 * @param fileContent
 * @param width
 * @param height
 * @param border
 * @return
 */
char *YUVImageParser::addBorderForYUV420P(char *fileContent, int width, int height, int border) {
    //逐行扫描
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            if (i<border || i > (height-border) || j < border || j > (width-border)) {
                fileContent[i*width + j] = 255;
            }
        }
    }
    return fileContent;
}
