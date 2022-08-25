#ifndef PHOTOMETAINFO_H
#define PHOTOMETAINFO_H

#include <QString>
#include <QPair>

const int POINT_COUNT = 29;

struct Rect {
    double x,y;
    double h,w;
//    Rect():x(0),y(0),h(0),w(0){}
    Rect(double x_ = 0, double y_ = 0,
            double h_ = 0, double w_ = 0):x(x_),y(y_),h(h_),w(w_){}
    double x2(){return x + w;}
    double y2(){return y + h;}
};

struct PhotoMetaInfo {
    PhotoMetaInfo();

    QString fullFileName;
    Rect rectangle;

    QString maskType;
    double maskValue;

    QPair<double,double> points[POINT_COUNT];
};

#endif // PHOTOMETAINFO_H
