// becs.cc : Defines the entry point for the application.
//

#include <GLFW/glfw3.h>
#include "becs.hh"

#include "test.hh"

using namespace std;
using namespace becs;

int main()
{
	GLFWwindow* window;

	// init glfw
	if (!glfwInit()) return -1;

	// create window 
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	
	if (!window) {
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	
	// loop until window is closed
	while (!glfwWindowShouldClose(window)) {

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	
	glfwTerminate();
	
	
	Test::Hello();
	return 0;
}
