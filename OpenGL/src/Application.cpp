#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    std::cout << glGetString(GL_VERSION) << std::endl;

    GLenum err = glewInit();

    if (err != GLEW_OK) {
        std::cout << "GLEW did not init ok";
    }
    else {
        std::cout << "GLEW did init ok";
    }


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 1); 
        glVertex2f(-0.5, -0.5);
        glVertex2f(0, 0.5);
        glVertex2f(0.5, -0.5);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}