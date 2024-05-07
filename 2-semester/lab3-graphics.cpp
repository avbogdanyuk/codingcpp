#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class point
{
protected:

    GLFWwindow* window;
    GLfloat x, y;
    GLfloat color[3]{ 1,1,1 }; //базовый цвет - белый

public:

    point(); //точка белого цвета (0, 0)
    point(GLfloat xx, GLfloat yy, GLfloat r, GLfloat g, GLfloat b); //точка цвет(r,g,b) коорд.(xx,yy)
    ~point() {}//диструктор
    void draw(); //рисуем
    point hide(); //закрашиваем черным
    point move(GLfloat dxx, GLfloat dyy);
};

point::point()
{
    //Инициализируем библиотеку GLFW
    if (glfwInit() == NULL)
    {
        cout << "Failed to initialize GLFW" << endl;
        exit(1);
    }

    window = glfwCreateWindow(640, 480, "Drawing", NULL, NULL);

    if (window == NULL) //If window creation fails, NULL will be returned
    {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window); //отображение рисунка

    x = 0.0f; y = 0.0f;
}

point::point(GLfloat xx, GLfloat yy, GLfloat r, GLfloat g, GLfloat b)
{
    //Инициализируем библиотеку GLFW
    if (glfwInit() == NULL)
    {
        cout << "Failed to initialize GLFW" << endl;
        exit(1);
    }

    window = glfwCreateWindow(640, 480, "Drawing", NULL, NULL);

    if (window == NULL) //If window creation fails, NULL will be returned
    {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window); //отображение рисунка

    x = xx; y = yy;
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

void point::draw()
{
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glPointSize(7);
        glBegin(GL_POINTS);
        glColor3f(color[0], color[1], color[2]);
        glVertex2f(x, y);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

point point::hide() //OpenGL забывает об рисунке, когда он уже был нарисован, поэтому в hide нет смысла
{
    color[0] = 0.0f;
    color[1] = 0.0f;
    color[2] = 0.0f;
    return *this;
}

point point::move(GLfloat dxx, GLfloat dyy)
{
    point tmp;
    tmp.x = x + dxx; tmp.y = y + dyy;
    tmp.color[0] = color[0];
    tmp.color[1] = color[1];
    tmp.color[2] = color[2];
    return tmp;
}

class tline : public point
{
protected:
    GLFWwindow* window;
    GLfloat dx, dy;
public:
    tline();
    tline(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy);
    ~tline() {}
    void draw();
    tline hide();
    tline move(GLfloat dxx, GLfloat dyy);
    void rotate(double fi);
};

tline::tline()
{
    //Инициализируем библиотеку GLFW
    if (glfwInit() == NULL)
    {
        cout << "Failed to initialize GLFW" << endl;
        exit(1);
    }

    window = glfwCreateWindow(640, 480, "Drawing", NULL, NULL);

    if (window == NULL) //If window creation fails, NULL will be returned
    {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window); //отображение рисунка

    x, y, dx, dy = 0;
}

tline::tline(GLfloat xx, GLfloat yy, GLfloat dxx, GLfloat dyy)
{
    //Инициализируем библиотеку GLFW
    if (glfwInit() == NULL)
    {
        cout << "Failed to initialize GLFW" << endl;
        exit(1);
    }

    window = glfwCreateWindow(640, 480, "Drawing", NULL, NULL);

    if (window == NULL) //If window creation fails, NULL will be returned
    {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window); //отображение рисунка

    x = xx; y = yy; dx = dxx; dy = dyy;
}

void tline::draw()
{
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glPointSize(2);
        glBegin(GL_LINES);
        glColor3f(color[0], color[1], color[2]);
        glVertex2f(x, y);
        glVertex2f(dx, dy);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

tline tline::hide()
{
    color[0] = 0.0f;
    color[1] = 0.0f;
    color[2] = 0.0f;
    return *this;
}

tline tline::move(GLfloat dxx, GLfloat dyy)
{
    tline tmp;
    tmp.x = x+dxx;
    tmp.y = y+dyy;
    tmp.dx = dx+dxx;
    tmp.dy = dy+dyy;
    return tmp;
}

void tline::rotate(double fi)
{
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glPointSize(2);
        glBegin(GL_LINES);
        glColor3f(color[0], color[1], color[2]);
        glVertex2f(x, y);
        glVertex2f(dx, dy);
        glEnd();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();             // save the current GL_MODELVIEW matrix 
        glRotatef(60, 0, 1, 0);  // rotate your object
        //drawObjectAHere();          // draw object A
        glPopMatrix();              // restore the GL_MODELVIEW matrix

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main() 
{
    cout << "Welcome to simulator of madness. ENJOY AS LONG AS YOU CAN";

    //ТОЧКА
    point p1(0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    p1.draw();
    //p1.hide().draw();
    p1.move(0.1f,0.2f).draw();

    //ЛИНИЯ
    tline t1(0.0f, 0.0f, 0.1f, 0.1f);
    //t1.hide().draw();
    //t1.draw();
    //t1.move(0.3f, 0.4f).draw();
    t1.rotate(2);
    //КВАДРАТ
    return 0;
}
