#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(float _x,float _y,int type);
        float getX();
        float getY();
        int getType();
        virtual ~Point();
    protected:
    private:
    float x;
    float y;
    int type;
};

#endif // POINT_H
