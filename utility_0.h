#include <string>

using namespace std;

// utility class for generating img
// in this HW we do not draw by itself
// instead, we use 3D-coordinate to draw

struct Color{
    double r;
    double g;
    double b;
};

class Draw{
public :
    ~Draw();
    Draw(int, int);
    Color &get_canv(int, int);

    bool gen_output(string);    
    string canvas_out();

private :
    int w;  // width
    int h;  // height
    Color *canv;   // canvas for output, assumed range : 0 ~ 1
};


