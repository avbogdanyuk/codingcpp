#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

//прога для того, чтобы нарисовать линию

class point
{
protected:

    float x, y;
    int c1, c2, c3; //c1,c2,c3 - red, green, blue

public:

    point();
    point(float xx, float yy, int cc1, int cc2, int cc3);
    ~point()
    {
        cout << "Point destroyed" << endl;
    }
    void draw(); //рисуем точку
    void hide(); //закрашиваем черным
    void move(int dxx, int dyy); //двигаем на вектор
};


point::point()
{
    x, y = 0;
    //c1, c2, c3 = 1;
}

point::point(float xx, float yy, int cc1, int cc2, int cc3)
{
    x = xx; y = yy; cc1 = c1; cc2 = c2; cc3 = c3;
}

void point::draw()
{
    glLineWidth(2.0);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void point::hide()
{
    c1, c2, c3 = 0;
}


int mainpepep()
{
    //Инициализируем библиотеку GLFW
    if (!glfwInit()) return 0;

    //Создаем окно
    GLFWwindow* window = glfwCreateWindow(680, 480, "Line Drawing", NULL, NULL);

    //Если окно не создалось, то ошибка => завершаем работу программы
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return 0;
    }

    //Чтобы рисунок отображался в окне
    glfwMakeContextCurrent(window);

    //Цикл работает, пока пользователь не закроет окно
    while (glfwWindowShouldClose(window) == NULL)
    {
        //Рисуем точку с (-0.5, -0.5) до (0.5, 0.5)
        //Цвета RGB
        glColor3f(1, 1, 1);
        glBegin(GL_POINTS);
        glVertex2f(-0.5f, -0.5f);
        //glVertex2f(0.5f, 0.5f);
        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }


    //Завершаем работу с GLFW
    glfwTerminate();

    return 0;
}

int main()
{
    if (glfwInit() == NULL) return 0;

    GLFWwindow* window = glfwCreateWindow(640, 480, "Drawing", NULL, NULL);

    if (window == NULL)
    {
        glfwTerminate();
        return 0;
    }

    glfwMakeContextCurrent(window);

    point p;

    while (glfwWindowShouldClose(window) == NULL)
    {
        p.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
