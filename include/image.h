#include <vector>
using std::vector;

#include "pixel.h"

#ifndef IMAGE_H
#define IMAGE_H

#define matrix vector<vector<Pixel>>

class Image {
protected:
    int number_rows;                            // number of rows 
    int number_cols;                             // number of columns 
    int max_color;                            // number of gray levels 
    matrix pixels;                     //2D array

public:
    Image();                           //constructor
    Image(int numRows, int numCols, int maxColor);   //constructor
    ~Image();                      
  /*Image(const Image& oldImage);            
    void operator=(const Image&);*/              

    int getNumberRows();
    void setNumberRows(int numRows);
    int getNumberCols();
    void setNumberCols(int numCols);
    int getMaxColor();
    void setMaxColor(int maxColor);
    matrix getPixels();
    void setPixels(matrix pix);
};

#endif