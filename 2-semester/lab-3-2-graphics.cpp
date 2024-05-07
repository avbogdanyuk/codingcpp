//ВЫВОД ВСЕХ ТОЧЕК В ОДНОМ ОКНЕ

#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class point 
{
public:

    //GLFWwindow* window;
    float x, y;
    float color[3]{ 1,1,1 }; //базовый цвет - белый

public:

    point(); //точка белого цвета (0, 0)
    point(float xx, float yy, float r, float g, float b); //точка цвет(r,g,b) коорд.(xx,yy)
    ~point() //диструктор
    {}
    //void draw();
};

point::point()
{
    /*//Инициализируем библиотеку GLFW
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
    */
    x = 0; y = 0;
}

point::point(float xx, float yy, float r, float g, float b)
{
    /*//Инициализируем библиотеку GLFW
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
    */
    x = xx; y = yy;
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

/*void point::draw()
{
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);



        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}*/

int main() 
{
    if (glfwInit() == NULL)
    {
        cout << "Failed to initialize GLFW" << endl;
        exit(1);
    }

    GLFWwindow* window;

    window = glfwCreateWindow(640, 480, "Drawing", NULL, NULL);

    if (window == NULL) //If window creation fails, NULL will be returned
    {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        exit(1);
    }

    point p;
    point p1(0.12, 0.3, 1, 0, 0);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1, 0, 0);
        glBegin(GL_POINTS);
        glVertex2f(p.x, p.y);
        glColor3f(1, 1, 0);
        glVertex2f(p1.x, p1.y);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(-0.2, -0.2);
        glVertex2f(0.2, -0.1);
        glEnd();

        glfwMakeContextCurrent(window); //отображение рисунка

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //point1.draw();
    
    //p.draw();


    return 0;
}
