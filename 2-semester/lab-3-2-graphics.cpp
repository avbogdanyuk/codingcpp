#include <GLFW/glfw3.h>
#include <iostream>

class Point {
public:
    GLfloat x, y;
    GLfloat color[3]{1,1,1};

    Point() : x(0.0f), y(0.0f) {}

    Point(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b) : x(x), y(y)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    ~Point() {}

    void draw() 
    {
        glPointSize(5);
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }

    void hide()
    {
        color[0], color[1], color[2] = 0.0f;
    }

    void move(GLfloat dx, GLfloat dy) 
    {
        x = dx;
        y = dy;
    }
};

class Line : public Point 
{
public:
    GLfloat dx, dy;
    GLfloat angle;

    Line() {}

    Line(Point p, GLfloat dxx, GLfloat dyy) 
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
    
    void draw() 
    {
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(dx, dy);
        glEnd();
    }
    
    void move(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy)
    {
        x = xx;
        y = yy;
        dx = dxx;
        dy = dyy;
    }

    void rotate(GLfloat fi)
    {
        angle += fi;
        glPushMatrix();
        glTranslatef(x, x, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(dx - x, dy - y);
        glEnd();

        glPopMatrix();
    }

    void hide()
    {
        color[0], color[1], color[2] = 0.0f;
    }
};

class Paral : public Line
{
public:
    int angle;
    Line a;
    Line b;

    Paral(Line l1, Line l2, int aangle)
    {
        a = l1;
        b = l2;
        angle = aangle;
    }

    void draw()
    {
        a.draw();
        b.draw();
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
        
        Point p(0.0f,0.0f, 1,0,0);
        p.draw();

        Line l(p, 0.3f, 0.5f);
        l.draw();
        l.rotate(90);

        Line l1(p, 0.45f, 0.6f);
        //l1.draw();

        Paral ppap(l,l1,45);
        //ppap.draw();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
