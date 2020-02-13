#include "utility_1a.h"

using namespace std;

// --------------------Point3D------------------------
ostream& operator <<(ostream &os, const Point3D &pt){
    return os<<"("<< pt.x << ", " << pt.y << ", " 
        << pt.z <<")"; 
}
Point3D Point3D::operator-() const{
    return Point3D(-x,-y,-z);
}
Point3D Point3D::operator+(const Point3D &pt)const{
    return Point3D(x+pt.x,y+pt.y,z+pt.z);
}
Point3D Point3D::operator-(const Point3D &pt)const{
    return -pt + *this;
}
Point3D Point3D::operator*(const double &c) const{
    return Point3D(x*c,y*c,z*c);
}
Point3D operator*(const double &c, const Point3D &pt){
    return Point3D(pt.x*c,pt.y*c,pt.z*c);
}

// --------------------Vector3D------------------------
Vector3D Vector3D::operator*(const double &c) const{
    return Vector3D(locate,orient*c);
}
Vector3D Vector3D::operator-() const{
    return *this * (-1);
}
Vector3D operator*(const double &c, const Vector3D &v){
    return v*c;
}
ostream& operator <<(ostream& os, const Vector3D &v){
    return os<< v.locate << "+" << v.orient << endl;
}