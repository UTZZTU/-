#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

void drawLine(std::vector<float> points) {
    glBegin(GL_LINE_STRIP);
    for (size_t i = 0; i < points.size(); i += 2) {
        glVertex2f(points[i], points[i + 1]);
    }
    glEnd();
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // �������ߵ����ݵ�
    std::vector<float> points = {
        100, 300,
        200, 100,
        300, 500,
        400, 200,
        500, 400,
        600, 300
    };

    // ����������ɫ
    glColor3f(1.0f, 0.0f, 0.0f);

    // ��������
    drawLine(points);

    glFlush();
}

int main() {
    // ��ʼ��GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // ��������
    GLFWwindow* window = glfwCreateWindow(800, 600, "����ͼ", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // ���õ�ǰ������
    glfwMakeContextCurrent(window);

    // ѭ����Ⱦ
    while (!glfwWindowShouldClose(window)) {
        // ��Ⱦ����
        renderScene();

        // ����������
        glfwSwapBuffers(window);

        // ����¼�
        glfwPollEvents();
    }

    // ��ֹGLFW
    glfwTerminate();

    return 0;
}

