#include <GLFW/glfw3.h>
#include <iostream>

class point {
protected:
    GLfloat x, y;
    GLfloat color[3]{1.0f,1.0f,1.0f};

public:
    point() : x(0.0f), y(0.0f) {}

    point(GLfloat x, GLfloat y) : x(x), y(y) {}

    ~point() {}

    void draw() 
    {
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

class Line : public point 
{
protected:
    GLfloat dx, dy;
    GLfloat angle;

public:
    Line() : point(0.0f, 0.0f), dx(0.0f), dy(0.0f), angle(0.0f) {}
    Line(GLfloat x, GLfloat y, GLfloat dxx, GLfloat dyy) : point(x, y), dx(dxx), dy(dyy), angle(0.0f) {}
    ~Line() {}

    void draw() 
    {
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
        glVertex2f(0.0f, 0.0f);
        glVertex2f(dx - x, dy - y);
        glEnd();

        glPopMatrix();
    }
};

class Square : public Line {
public:
    Square() : Line(0.1f, 0.1f, 0.2f, 0.1f), size(0.1f) {}

    Square(GLfloat x, GLfloat y, GLfloat size) : Line(x, y, x + size, y), size(size) {}

    ~Square() {}

    void draw() 
    {
        glColor3f(color[0], color[1], color[2]);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y - size);
        glVertex2f(x, y - size);
        glEnd();
    }

    void move(GLfloat dx, GLfloat dy) 
    {
        x = dx;
        y = dy;
    }

    void rotate(GLfloat angle) 
    {
        // Rotate the square by angle
    }

private:
    GLfloat size;
};

int main() {
    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        point p(0.0f,0.8f);
        p.draw();
        p.move(0.5f, 0.5f);
        p.draw();
        
        Line l(0.0f, 0.0f, 0.8f, 0.8f);
        l.draw();
        l.move(0.0f, 0.0f, 0.0f, 0.1f);
        l.draw();
        l.rotate(97);
        l.rotate(10);
        
        Square s;
        s.draw();
        s.move(-0.5f, -0.5f);
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
