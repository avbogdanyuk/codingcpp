#include <GLFW/glfw3.h>
#include <iostream>

class Point {
protected:
    GLfloat x, y;
    GLfloat color[3]{1,1,1};

public:
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
protected:
    GLfloat dx, dy;
    GLfloat angle;

public:
    Line() : Point(0.0f, 0.0f, 1.0f, 1.0f, 1.0f), dx(0.0f), dy(0.0f), angle(0.0f) {}
    Line(GLfloat x, GLfloat y, GLfloat dxx, GLfloat dyy) : Point(x, y, color[0], color[1], color[2]), dx(dxx), dy(dyy), angle(0.0f) {}
    ~Line() {}

    void draw() 
    {
        glColor3f(1,1,1);
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

    void rotate(GLfloat fi) //функция и вращает и рисует
    {
        angle += fi;
        glPushMatrix();
        glTranslatef(x, x, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(dx - x, dy - y);
        glEnd();

        glPopMatrix();
    }

    void hide()
    {
        color[0], color[1], color[2] = 0.0f;
    }
};

class Square : public Line 
{
protected:
    GLfloat size;
public:
    Square() : Line(0.1f, 0.1f, 0.2f, 0.1f), size(0.1f) {}

    Square(GLfloat x, GLfloat y, GLfloat size) : Line(x, y, x + size, y), size(size) {}

    ~Square() {}

    void draw() 
    {
        glColor3f(1,1,1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(y, x + size);
        glVertex2f(y - size, x + size);
        glVertex2f(y - size,x);
        glEnd();
    }

    void move(GLfloat dx, GLfloat dy) 
    {
        x = dx;
        y = dy;
    }

    void rotate(GLfloat fi) 
    {
        angle += fi;

        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glColor3f(1, 1, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(y, x + size);
        glVertex2f(y - size, x + size);
        glVertex2f(y - size, x);
        glEnd();

        glPopMatrix();
    }
};

class Rectangle : public Square
{
protected: 

    GLfloat height, width;

public:
    Rectangle() : Square(), height(0.0f), width(0.0f) {}
    Rectangle(GLfloat x, GLfloat y, GLfloat height, GLfloat width) : Square(x,y,0.0f), height(height), width(width) {}
    ~Rectangle() {}
    void draw()
    {
        glColor3f(1, 1, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(y, x + width);
        glVertex2f(y - height, x + width);
        glVertex2f(y - height, x);
        glEnd();
    }
    void hide()
    {
        color[0], color[1], color[2] = 0.0f;
    }
    void rotate(GLfloat fi)
    {
        angle += fi;

        glPushMatrix();
        glTranslatef(x, y, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glColor3f(1, 1, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(y, x + width);
        glVertex2f(y - height, x + width);
        glVertex2f(y - height, x);
        glEnd();

        glPopMatrix();
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
        
        Point p(0.0f,0.8f, 1,0,0);
        p.draw();
        p.move(0.5f, 0.5f);
        p.draw();
        
        Line l(0.0f, 0.8f, 0.1f, 0.0f);
        l.draw();
        l.move(0.0f, 0.0f, 0.0f, 0.5f);
        l.draw();
        l.rotate(97);
        l.rotate(10);
        
        Square s(0.1f,0.1,0.3f);
        s.draw();
        s.move(0.1f, 0.1f);
        s.draw();
        s.rotate(90);
        
        Rectangle r(-0.1f, -0.1f, 0.4f, 0.6f);
        r.draw();
        r.rotate(90);
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
