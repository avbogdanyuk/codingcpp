#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class point {
protected:

    GLFWwindow* window;
    float x, y;
    float color[3] {1,1,1}; //базовый цвет - белый

public:

    point(); //точка белого цвета (0, 0)
    point(float xx, float yy, float r, float g, float b); //точка цвет(r,g,b) коорд.(xx,yy)
    ~point() //диструктор
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void draw() {
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);

            glBegin(GL_POINTS);
            glColor3f(color[0], color[1], color[2]);
            glVertex2f(0.0f, 0.0f);
            glEnd();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

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

    //основа
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

    //основа
    x = xx; y = yy;
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

int main() {
    point point(0,0,1,0,0);
    point.draw();

    return 0;
}
