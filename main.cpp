#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>

void run()
{
	GLFWwindow *window = glfwCreateWindow(960, 540, u8"卡帕", nullptr, nullptr);
	if (!window)
		return;

	glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int x, int y)
	{

	});

	glfwMakeContextCurrent(window);

	auto error = glewInit();
	if (error != GLEW_OK)
	{
		printf("GLEW failed to initialize! Error: %s\n", glewGetErrorString(error));
		return;
	}

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(0, 1, 0);
		glVertex2f(0.5f, -0.5f);
		glColor3f(0, 0, 1);
		glVertex2f(0.0f, 0.5f);
		glEnd();

		glfwSwapBuffers(window);
	}


}

int main()
{
	if (!glfwInit())
		return 0;
	run();
	glfwTerminate();
	return 0;
}