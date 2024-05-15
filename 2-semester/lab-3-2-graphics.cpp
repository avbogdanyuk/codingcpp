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

    ~Line() {}

    Line operator=(const Line& r) //оператор присваивания
    {
        x = r.x; y = r.x; dx = r.dx; dy = r.dy;
        color[0] = r.color[0];
        color[1] = r.color[1];
        color[2] = r.color[2];

        return *this;
    }

    Line operator-() //противоположная линия, вектор
    {
        GLfloat kx = x; GLfloat ky = y;
        x = dx; y = dy;
        dx = kx; dy = ky;

        return *this;
    }

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
        x = xx;
        y = yy;
        dx = dxx;
        dy = dyy;
    }

    void rotate(GLfloat fi) //рисуем повернутную линию на угол
    {
        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(fi, x, y, 1.0f);

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

class Paral : public Line //Параллелограм
{
public:
    Line a, b;
    int angle;

    Paral() 
    {
        Line l1, l2;
        a = l1; b = l2; angle = 0;
    }

    Paral(Line l1, Line l2, int aa) //по двум линиям и углу
    {
        a = l1; b = l2; angle = aa;
    }

    void draw() //рисуем паралелограмм
    {
        a.draw();
        b.draw();
        (-a).rotate(180 + angle);
        (-b).rotate(180 - angle);
        /*
        a.draw();
        b.draw();
        Point p(a.dx, a.dy, a.color[0], a.color[1], a.color[2]);
        Line c(p, a.dx+b.dx, a.dy+b.dy);
        c.draw();
        Point p1(b.dx, b.dy, b.color[0], b.color[1], b.color[2]);
        Line d(p1, a.dx + b.dx, a.dy + b.dy);
        d.draw();
        */
    }

    void hide()
    {
        a.hide();
        b.hide();
        (-a).hide();
        (-b).hide();
    }

    void move(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy)
    {
        x = xx; y = yy; dx = dxx; dy = dyy;
    }
};

class Rectan : public Paral
{
public:

    Rectan()
    {
        Paral pp;
    }

    Rectan(Line l1, Line l2) //Paral(Line l1, Line l2, int aangle)
    {
        a = l1, b = l2, angle = 90;
    }

    void draw()
    {
        Paral pp(a ,b ,angle);
        pp.draw();
    }
};

class Rhombus : public Paral
{
public:

    Rhombus()
    {
        Paral pp;
    }

    Rhombus(Line l1, GLfloat aangle)
    {
        a = b = l1; angle = aangle;
    }

    void draw()
    {
        Paral pp(a, a, angle);
        pp.draw();
    }
};

class Square : public Paral
{
public:
    Square(Line l1)
    {
        a = b = l1; angle = 90;
    }

    void draw()
    {
        Paral pp(a,a,90);
        pp.draw();
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
        glClear(GL_COLOR_BUFFER_BIT);

        Point p(0.0f, 0.0f, 1, 0, 0);
        p.draw();

        Line l(p, 0.6f, 0.5f);
        //(-l).draw();
        //l.draw();

        Line l1(p, 0.45f, 0.6f);
        //l1.draw();

        Paral ppap(l,l1,45);
        ppap.draw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
