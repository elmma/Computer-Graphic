#include <string>
#include <cmath>
#include <random>
#include <sstream>
#include <algorithm> 
#include <string.h>
#include <fstream>
#include <iostream>

#include "utility_0.h"

//-------------------------------------
//          implementation
// ------------------------------------

Draw::Draw(int w_in=500, int h_in=500){
    w = w_in;
    h = h_in;
    canv = new Color[w*h];
    memset(canv,0,w*h*sizeof(*canv));
}

Draw::~Draw(){
    delete[] canv;
}

Color & Draw::get_canv(int x, int y){
    return canv[x*h + y];
}

// generate img by w x h , output with filename
// if success, return true; otherwise return false
bool Draw::gen_output(string filename){
    ofstream output;
    output.open(filename);
    if(output.fail()) {
        cerr << "error when writing file\n";
        return false;
    }
    // writing
    output << "P3\n" ;
    output << "# generate image of size " << w << "x" << h << "\n";
    output << w << " " << h << "\n";
    output << "255\n";
    output << canvas_out();
    output.close();
   
    return true;
}

// convert canvas data to string for output
string Draw::canvas_out(){
    stringstream ss;
    string out = "";

    // output stream
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            Color tmp = get_canv(x,y);
            ss << static_cast<int>(tmp.r * 255) << " ";
            ss << static_cast<int>(tmp.g * 255) << " ";
            ss << static_cast<int>(tmp.b * 255) << " ";
            ss << "\n";
        }
    }
    out = ss.str();
    return out;
}
