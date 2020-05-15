#include <iostream>

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

void ErrorCallback(int error, const char* description) {
	std::cerr << "Error : " << description << std::endl;
}

int main(int argc, char** argv)
{
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return -1;
	}

	glfwSetErrorCallback(ErrorCallback);
	glfwWindowHint(GLFW_SAMPLES, 41);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	return 0;
}