#include <GLFW/glfw3.h>
#include <iostream>

class Point {
public:
    GLfloat x, y;
    GLfloat color[3]{1,1,1};

    Point() 
    {
        x, y = 0.0f;
    }

    Point(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b) : x(x), y(y) //точка опр.координат и опр.цвета
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    ~Point() {}

    void draw() //рисуем точку
    {
        
        glPointSize(5);
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }

    void hide() //закрашиваем точку черным
    {
        color[0], color[1], color[2] = 0.0f;
    }

    void move(GLfloat dx, GLfloat dy) //меняем местоположение точки
    {
        x = dx;
        y = dy;
    }
};

class Line : public Point
{
public:
    GLfloat dx, dy;

    Line() 
    {
        x, y, dx, dy = 0;
        color[0], color[1], color[2] = 1;
    }

    Line(Point p, GLfloat dxx, GLfloat dyy) //линия по точке уже сущ. и точке (dx,dy)
    {
        x = p.x;
        y = p.y;

        dx = dxx;
        dy = dyy;

        color[0] = p.color[0];
        color[1] = p.color[1];
        color[2] = p.color[2];
    }

    Line(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy, GLfloat r, GLfloat g, GLfloat b) : Point(xx,yy,r,g,b)
    {
        dx = dxx;
        dy = dyy;
    }

    ~Line() {}

    void draw() //рисуем линию
    {
        
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(dx, dy);
        glEnd();
    }

    void move(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy) //двигаем линию, меняем координаты
    {
        x += xx; y += yy; dx += dxx; dy += dyy;
    }

    void rotate(GLfloat fi) //рисуем повернутную линию на угол
    {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(fi, x, y, 1.0f);
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(dx - x, dy - y);
        glEnd();

        glPopMatrix();
    }

    Line nangle(GLfloat fi) //изменяем координаты, чтобы повернуть линию
    {
        Line tmp;
        GLfloat A = 3.14 * fi / 180;
        tmp.x = x; tmp.y = x;
        tmp.dx = x * cos(A) - y * sin(A);
        tmp.dy = x * sin(A) + y * sin(A);
        return tmp;
    }

    void hide() //закрашиваем линию
    {
        color[0], color[1], color[2] = 0.0f;
    }
};

class Square : public Line //Квадрат
{
public:

    Square() 
    {
        x, y, dx, dy = 0;
    }

    Square(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy, GLfloat r, GLfloat g, GLfloat b) //по двум линиям и углу
    {
        x = xx; y = yy; dx = dxx; dy = dyy;
        color[0] = r; color[1] = g; color[2] = b;
    }

    void draw() //рисуем паралелограмм
    {
        
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + dx, y + dy);
        glVertex2f(x + dx - dy, y + dy + dx);
        glVertex2f(x - dy, y + dx);
        glEnd();
    }

    void rotate(GLfloat fi)
    {
        
        glPushMatrix();
        glRotatef(fi, 0, 0, 1);
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + dx, y + dy);
        glVertex2f(x + dx - dy, y + dy + dx);
        glVertex2f(x - dy, y + dx);
        glEnd();
        glPopMatrix();
    }
};

class Rect : virtual public Square //Прямоугольник
{
public:

    GLfloat hx, vx = 1; //horizontal and vertical ENLARGEMENT...of square

    Rect() : Square() {}

    Rect(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy, GLfloat hhx, GLfloat vvx, GLfloat r, GLfloat g, GLfloat b)
    {
        x = xx; y = yy; dx = dxx; dy = dyy;
        color[0] = r; color[1] = g; color[2] = b;
        hx = hhx; vx = vvx;
    }

    void draw()
    {
        
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + hx * dx, y + hx * dy);
        glVertex2f(x + hx * dx - vx * dy, y + hx * dy + vx * dx);
        glVertex2f(x - vx * dy, y + vx * dx);
        glEnd();
    }

    void rotate(GLfloat fi)
    {
        
        glPushMatrix();
        glRotatef(fi, 0, 0, 1);
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x + hx * dx, y + hx * dy);
        glVertex2f(x + hx * dx - vx * dy, y + hx * dy + vx * dx);
        glVertex2f(x - vx * dy, y + vx * dx);
        glEnd();
        glPopMatrix();
    }
};

class Rhomb : virtual public Square
{
public:
    GLfloat fi;
    GLfloat pi = 3.14f;
    GLfloat len, xi; //что это...

    Rhomb() : Square() {}

    Rhomb(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy, GLfloat ffi, GLfloat r, GLfloat g, GLfloat b)
    {
        x = xx; y = yy; dx = dxx; dy = dyy;
        color[0] = r; color[1] = g; color[2] = b;
        fi = ffi; len = sqrt(dx * dx + dy * dy);
        xi = int(asin(dy / len) * 180 / pi);
    }

    ~Rhomb() {}

    void draw()
    {
        if (fi == 90)
        {
            Square tmp(x, y, dx, dy, color[0], color[1], color[2]);
            tmp.draw();
        }
        else
        {
            GLfloat dxx = GLfloat((len * cos((xi + 180 - fi) * pi / 180)));
            GLfloat dyy = GLfloat((len * sin((xi + 180 - fi) * pi / 180)) + 1);

            glColor3f(color[0], color[1], color[2]);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);
            glVertex2f(x + dx, y + dy);
            glVertex2f(x + dx + dxx, y + dy + dyy);
            glVertex2f(x + dxx, y + dyy);
            glEnd();
        }
    }

    void rotate(GLfloat fifi)
    {
        GLfloat dxx = GLfloat((len * cos((xi + 180 - fi) * pi / 180)));
        GLfloat dyy = GLfloat((len * sin((xi + 180 - fi) * pi / 180)) + 1);
        glPushMatrix();
        glRotatef(fifi, 0, 0, 1);
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + dx, y + dy);
        glVertex2f(x + dx + dxx, y + dy + dyy);
        glVertex2f(x + dxx, y + dyy);
        glEnd();
        glPopMatrix();
    }
};

class Paral : public Rect, public Rhomb
{
public:
    Paral() : Square() {}

    Paral(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy, GLfloat ffi, GLfloat hhx, GLfloat vvx, GLfloat r, GLfloat g, GLfloat b)
    {
        x = xx; y = yy; dx = dxx; dy = dyy;
        color[0] = r; color[1] = g; color[2] = b;
        vx = vvx; hx = hhx;
        fi = ffi; len = sqrt(dx * dx + dy * dy);
        xi = int(asin(dy / len) * 180 / pi);
    }

    void draw()
    {
        if (fi == 90)
        {
            Rect racoon(x, y, dx, dy, hx, vx, color[0], color[1], color[2]);
            racoon.draw();
        }
        else
        {
            if (hx = vx = 1)
            {
                Rhomb rural(x, y, dx, dy, fi, color[0], color[1], color[2]);
                rural.draw();
            }
            else
            {
                int dxx = int((len * cos((xi + 180 - fi) * pi / 180)));//можно поиграться с модулем
                int dyy = int((len * sin((xi + 180 - fi) * pi / 180)) + 1);
                glColor3f(color[0], color[1], color[2]);
                glBegin(GL_LINE_LOOP);
                glVertex2f(x, y);
                glVertex2f(x + hx * dx, y + hx * dy);
                glVertex2f(x + hx * dx + vx * dxx, y + hx * dy + vx * dyy);
                glVertex2f(x + vx * dxx, y + vx * dyy);
                glEnd();
            }
        }
    }
};


int main() {
    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(800, 600, "Drawing shapes", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        

        //Точка
        Point p(0.0f, 0.0f, 1, 0, 0);
        p.draw();
        //Линия
        Line l(p, 0.6f, 0.5f);
        l.draw();
        //Квадрат
        Square ppap(0.0f, 0.0f,0.1f,0.3f,0.0f,1.0f,0.0f);
        ppap.draw();
        ppap.rotate(20);
        //Прямоугольник
        Rect hello(0.0f, 0.5f, 0.1f, -0.2f, 0.6f, 1.0f, 0.0f, 0.0f, 1.0f);
        hello.draw();
        hello.move(0.5f, 0.0f, 0.0f, 0.5f);
        hello.draw();
        //Ромб
        Rhomb rumba(-0.3f, 0.3f, -0.5f, -0.3f, 120, 0.5f, 0.5f, 1.0f);
        rumba.draw();
        //Паралеллограмм
        Paral pupa(-0.3f, 0.5f, -0.1f, -0.3f, 90.0f, 0.6f, 1.0f, 1.5f, 2.5f, 0.0f);
        pupa.draw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
