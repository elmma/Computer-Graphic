#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "utility_1a.h"

using namespace std;

int main(int argc, char *argv[]){
    // // argument check -----------------------------------
    // // argc = 1 : error occur
    // // argc = 2 : only input file, output name by default
    // // argc = 3 : output file name given
    // // argc > 3 : ignore other args
    // if(argc==1) {
    //     cerr << "argument missing, exit unexpectedly\n";
    //     return 1;
    // } else if(argc>3)
    //     cerr << "too many argument, ignore other extra arguments\n";

    // string textname = argv[1];
    // string output_name = "output.ppm";  // default
    // ifstream input;

    // // output name set
    // if(argc>=3)
    //     output_name = argv[2] + string(".ppm");

    // // input file check ---------------------------------
    // // simple check
    // input.open(textname);
    // if(input.fail()) {
    //     cerr << "error when reading file\n";
    //     return 1;
    // }

    // /*------ it seems that there is some bug here ------*/
    // // try {
    // //     input.open(textname);
    // // }
    // // catch (ifstream::failure& e) {
    // //     cout << "Exception opening/reading file";
    // // }

    
    // // read input --------------------------------------
    // vector<string> input_arg;
    // string tmp;
    // while(input >> tmp){
    //     input_arg.push_back(tmp);
    // }
    // input.close();

    // // input arg check  --------------------------------------
    // // if width, height contain other symbol at tail, ignore
    // // if at head, raise an error
    // // e.g. width = 123abc -> get 123 ; height = abc123 -> error
    // int w = -1,h = -1;
    // if(input_arg.size()<3) {
    //     cerr << "input file : argument missing\n";
    //     return 1;
    // } else if(input_arg.size()>3){
    //     cerr << "input file : too many argument,ignore here\n";
    // }
    // if(input_arg[0] != "imsize") {
    //     cout << "invalid input keyword\n";
    //     return 1;
    // }
    // try {
    //     w = stoi(input_arg[1]);
    //     h = stoi(input_arg[2]);
    // }
    // catch (const invalid_argument& e) {
	//     cerr << "Invalid argument: " << e.what() << '\n';
    //     cerr << "bad image size\n";
    //     return 1;
    // }
    // if(w < 0 || h < 0) {
    //     cerr << "Invalid argument: negative width or height\n";
    //     return 1;
    // }

    // // output generation  --------------------------------------
    // bool flag;    
    // cout << "generate img with size : " << w << "x" << h << endl;
    // Draw drawer(w,h);

    // flag = drawer.gen_output(output_name);
    // if(!flag) {
    //     cerr << "error occured when generating img\n";
    //     return 1;
    // }

    //----------------test--------------------
    Point3D a = Point3D(1,2,3);
    Point3D b = Point3D(-2,-1,2);
    cout << a << "\n" << b << "\n" << a-b << endl;
    cout << 3*a << "\n" << b*(-2) << "\n" << endl;

    Vector3D v1 = Vector3D(a,b);
    cout << v1 << "\n" << -v1 << "\n" << v1*0.5 
            << "\n" << 2*v1 << endl;


    return 0;
}