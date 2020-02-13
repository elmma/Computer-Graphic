#include <iostream>

#include "utility_0.h"

using namespace std;

//-----------------------------------------------
// basic point element for 3D world
class Point3D{
public:
    Point3D();
    Point3D(double a,double b,double c):x(a), y(b), z(c){}

// operator overloading
    Point3D operator-() const;  // negation
    Point3D operator+(const Point3D &) const;  // add
    Point3D operator-(const Point3D &) const;  // sub
    Point3D operator*(const double&) const;  // scale
    friend Point3D operator*(const double&, const Point3D&);
    friend ostream& operator<<(ostream&, const Point3D&);

public: // for convenience
    double x;
    double y;
    double z;
};

//------------------------------------------------
// basic vector element for 3D world with starting point
// feature starting point and direction
// can calculate basic vector operation here
class Vector3D{
public:
    Vector3D(Point3D dir):locate(), orient(dir){}    // origin
    Vector3D(Point3D st,Point3D dir):locate(st), orient(dir){}

// operator overloading
    Vector3D operator*(const double&) const;  // scale
    Vector3D operator-() const;  // negate the orient
    friend Vector3D operator*(const double&, const Vector3D&);
    friend ostream& operator<<(ostream&, const Vector3D&);

public: // for convenience
    Point3D locate;
    Point3D orient; // maybe wierd, but make sense
};


//---------------------------------------------
class Object3D{
public :
    Object3D(double a,double b,double c):center(Point3D(a,b,c),Point3D()){}
    Object3D(Point3D st):center(st,Point3D()){}
    Object3D(Point3D st,Point3D dir):center(st,dir){}

protected:
    Vector3D center;  // here we assume basically no orientation
};

class Sphere : public Object3D{
public :
    Sphere(double a,double b,double c, double r): Object3D(a,b,c),radius(r){}
    Sphere(Point3D c, double r) : Object3D(c),radius(r){}

protected:
    double radius;
};

class Cylinder : public Object3D{
public :
    Cylinder(Point3D st,Point3D dir, double r) : Object3D(st,dir),radius(r){}

protected:
    double radius;
};


//-----------------------------------------------------------
class World3D{
public :

private :
    int w;  // width
    int h;  // height
    double *canv;   // canvas for output, assumed range : 0 ~ 1
};