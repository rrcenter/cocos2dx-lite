#pragma once

/**
 
 #define CCGIF_CPP
 #include "ccgif.hpp"
 
 */

#include "platform/CCImage.h"

void ccgifBegin(const std::string& filepath, const std::string& firstFile, int delay = 100);
void ccgifBegin(const std::string& filepath, int width, int height, int delay = 100);
void ccgifAdd(const std::string& file);
void ccgifAdd(cocos2d::Image& img);
void ccgifEnd();

#ifdef CCGIF_CPP

#include "gif.h" // Only RGBA8 is currently supported as an input format. (The alpha is ignored.)
GifWriter _ccgif_writer;
int _ccgif_width = 0;
int _ccgif_height = 0;
int _ccgif_delay = 100;

void ccgifBegin(const std::string& filepath, const std::string& firstFile, int delay)
{
    cocos2d::Image img;
    img.initWithImageFile(firstFile);
    ccgifBegin(filepath, img.getWidth(), img.getHeight(), delay);
    ccgifAdd(img);
}
void ccgifBegin(const std::string& filepath, int width, int height, int delay)
{
    _ccgif_width = width;
    _ccgif_height = height;
    _ccgif_delay = delay;
    GifBegin(&_ccgif_writer, filepath.c_str(), width, height, delay);
}
void ccgifAdd(const std::string& filepath)
{
    cocos2d::Image img;
    img.initWithImageFile(filepath);
    ccgifAdd(img);
}
void ccgifAdd(cocos2d::Image& img)
{
    GifWriteFrame(&_ccgif_writer, img.getData(), img.getWidth(), img.getHeight(), _ccgif_delay);
}
void ccgifEnd()
{
    GifEnd(&_ccgif_writer);
}

#endif // CCGIF_CPP
