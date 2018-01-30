#include <iostream>
using std::cout;

#include <fstream>
#include <vector>

#include "../include/ppmreader.h"
#include "../include/ppmwriter.h"
#include "../include/pixel.h"


/*void readImage(std::string file_name) {
    Pixel p;
    int number_cols, number_rows, max_gray_levels;
    std::string header;
    int R, G, B;
 
 
    file >> header >> number_cols >> number_rows >> max_gray_levels;
    matrix pix(number_cols,std::vector<Pixel>(number_rows, p)); 
     
    for(int i = 0; i < number_cols; i++) {
        for(int j = 0; j < number_rows; j++){
            file >> R >> G >> B;
            pix[i][j].setR(R);
            pix[i][j].setG(G);
            pix[i][j].setB(B);
        }
    }

    file.close();

    for(int i = 0; i < number_cols; i++) {
        for(int j = 0; j < number_rows; j++){
            std::cout << pix[i][j].getR() << " ";
            std::cout << pix[i][j].getG() << " ";
            std::cout << pix[i][j].getB() << " ";
            std::cout << std::endl;
        }
    }

  
}*/

PPMReader::PPMReader(string f_name) {
    filename = f_name;
}

Image PPMReader::readFile() {
    int number_cols, number_rows, max_color;
    std::string header;
    int R, G, B;
    Pixel p;

    image_file.open(filename, std::ios::binary);

    if (!image_file) {
        std::cout << "Can't read image: " << filename << std::endl;
        exit(1);
    }

    image_file >> header >> number_cols >> number_rows >> max_color;
    Image ppm_image(number_cols,number_rows,max_color);
    matrix pixels(number_cols,vector<Pixel>(number_rows, p));

    for(int i = 0; i < number_cols; ++i) {
        for(int j = 0; j < number_rows; ++j){
            image_file >> R >> G >> B;
            pixels[i][j].setR(R);
            pixels[i][j].setG(G);
            pixels[i][j].setB(B);
        }
    }

    ppm_image.setPixels(pixels);
    image_file.close();

    return ppm_image;
}

