#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class point
{
protected:

    GLFWwindow* window;
    float x, y;
    float color[3]{ 1,1,1 }; //базовый цвет - белый

public:

    point(); //точка белого цвета (0, 0)
    point(float xx, float yy, float r, float g, float b); //точка цвет(r,g,b) коорд.(xx,yy)
    ~point() {}//диструктор
    void draw(); //рисуем
    point hide(); //закрашиваем черным
    point move(float dxx, float dyy);
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

    x = 0; y = 0;
}

point::point(float xx, float yy, float r, float g, float b)
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
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    return *this;
}

point point::move(float dxx, float dyy)
{
    point tmp;
    tmp.x = x + dxx; tmp.y = y + dyy;
    tmp.color[0] = color[0];
    tmp.color[1] = color[1];
    tmp.color[2] = color[2];
    return tmp;
}

class tline //: public point
{
protected:
    GLFWwindow* window;
    float dx, dy,x,y;
public:
    tline();
    tline(float xx, float yy, float dxx, float dyy);
    ~tline() {}
    void draw();
    tline hide();
    tline move(float dxx, float dyy);
    tline rotate(double fi);
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

tline::tline(float xx, float yy, float dxx, float dyy)
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
        glColor3f(0, 1, 1);
        glVertex2f(x, y);
        glVertex2f(dx, dy);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main() 
{
    cout << "Welcome to simulator of madness. ENJOY AS LONG AS YOU CAN";
    point p1(0, 0, 1, 0, 0);
    p1.draw();
    //p1.hide().draw();
    p1.move(0.1,0.2).draw();

    tline t1(0.1,0.1,0.2,-0.3);
    t1.draw();
    return 0;
}
