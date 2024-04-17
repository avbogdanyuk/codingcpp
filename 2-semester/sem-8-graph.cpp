#include <iostream>
using namespace std;

class point
{
    protected:
    int y; int x; int color;
    
    public:
    point();
    point(int x, int y);
    ~point();
    
    void draw();
    void hide();
    void move(int dxx, int dyy);
}

class tline: public point
{
    protected:
    int dx; int dy;
    
    public:
    tline();
    tline(int xx, int yy, int dxx, int dyy);
    ~tlint();
    
    void draw();
    void hide();
    void move(int dxx, dyy);
}
