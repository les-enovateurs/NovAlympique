#include "../include/Point.h"

Point::Point(float _x,float _y,int _type):x(_x),y(_y),type(_type)
{
    //ctor
}

float Point::getX()
{
    return x;
}

float Point::getY()
{
    return y;
}

int Point::getType()
{
    return type;
}

Point::~Point()
{
    //dtor
}
