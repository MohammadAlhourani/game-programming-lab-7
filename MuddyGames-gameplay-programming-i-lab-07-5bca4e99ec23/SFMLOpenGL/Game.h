#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "MyVector3.h"
#include "MyMatrix3.h"

using namespace std;
using namespace sf;


class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();                                     
	void update();
	void draw();
	void unload();

	GLuint index;
	Clock clock;
	Time elapsed;

	MyVector3 faces[6][4] = { { {1.0f, 1.0f, -15.0f} , {-1.0f, 1.0f, -15.0f}, {-1.0f, -1.0f, -15.0f}, {1.0f, -1.0f, -15.0f} }, // back face
								{ { -1.0f, 1.0f, -5.0f }, { -1.0f, 1.0f, -15.0f },{ -1.0f, -1.0f, -15.0f },{ -1.0f, -1.0f, -5.0f } }, //left face
								{ { 1.0f, 1.0f, -5.0f }, { 1.0f, 1.0f, -15.0f }, { 1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -5.0f } }, // right face
								{ { 1.0f, -1.0f, -5.0f }, { -1.0f, -1.0f, -5.0f },{ -1.0f, -1.0f, -15.0f },{ 1.0f, -1.0f, -15.0f } }, // bottom face
								{ { 1.0f, 1.0f, -5.0f }, { -1.0f, 1.0f, -5.0f },{ -1.0f, 1.0f, -15.0f },{ 1.0f, 1.0f, -15.0f } }, // top face
								{ { 1.0f, 1.0f, -5.0f }, { -1.0f, 1.0f, -5.0f },{ -1.0f, -1.0f, -5.0f },{ 1.0f, -1.0f, -5.0f } } // front face

	};

	float rotationAngle = 0.0f;
};