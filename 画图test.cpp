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

    // 定义折线的数据点
    std::vector<float> points = {
        100, 300,
        200, 100,
        300, 500,
        400, 200,
        500, 400,
        600, 300
    };

    // 设置线条颜色
    glColor3f(1.0f, 0.0f, 0.0f);

    // 绘制折线
    drawLine(points);

    glFlush();
}

int main() {
    // 初始化GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "折线图", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // 设置当前上下文
    glfwMakeContextCurrent(window);

    // 循环渲染
    while (!glfwWindowShouldClose(window)) {
        // 渲染场景
        renderScene();

        // 交换缓冲区
        glfwSwapBuffers(window);

        // 检查事件
        glfwPollEvents();
    }

    // 终止GLFW
    glfwTerminate();

    return 0;
}

