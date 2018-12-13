#include <Game.h>

bool updatable = false;



Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		for (int x = 0; x < 4; x++)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(faces[0][x].x, faces[0][x].y, faces[0][x].z);
		}

		for (int x = 0; x < 4; x++)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(faces[1][x].x, faces[1][x].y, faces[1][x].z);
		}

		for (int x = 0; x < 4; x++)
		{
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(faces[2][x].x, faces[2][x].y, faces[2][x].z);
		}

		for (int x = 0; x < 4; x++)
		{
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(faces[3][x].x, faces[3][x].y, faces[3][x].z);
		}

		for (int x = 0; x < 4; x++)
		{
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(faces[4][x].x, faces[4][x].y, faces[4][x].z);
		}

		for (int x = 0; x < 4; x++)
		{
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(faces[5][x].x, faces[5][x].y, faces[5][x].z);
		}
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		glNewList(index, GL_COMPILE);
		glBegin(GL_QUADS);
		{
			for (int x = 0; x < 4; x++)
			{
				glColor3f(0.0f, 1.0f, 0.0f);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					faces[0][x] = MyMatrix3::rotationZ(rotationAngle) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					faces[0][x] = MyMatrix3::rotationZ(-rotationAngle) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					faces[0][x] = MyMatrix3::rotationX(rotationAngle) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					faces[0][x] = MyMatrix3::rotationX(-rotationAngle) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					faces[0][x] = MyMatrix3::translation(MyVector3(0.001, 0.0, 0.0)) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					faces[0][x] = MyMatrix3::translation(MyVector3(-0.001, 0.0, 0.0)) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					faces[0][x] = MyMatrix3::scale(1.01) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					faces[0][x] = MyMatrix3::scale(0.99) * MyVector3(faces[0][x].x, faces[0][x].y, faces[0][x].z);
				}

				glVertex3f(faces[0][x].x, faces[0][x].y, faces[0][x].z);
			}

			for (int x = 0; x < 4; x++)
			{
				glColor3f(1.0f, 0.0f, 0.0f);
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					faces[1][x] = MyMatrix3::rotationZ(rotationAngle) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					faces[1][x] = MyMatrix3::rotationZ(-rotationAngle) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					faces[1][x] = MyMatrix3::rotationX(rotationAngle) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					faces[1][x] = MyMatrix3::rotationX(-rotationAngle) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					faces[1][x] = MyMatrix3::translation(MyVector3(0.001, 0.0, 0.0)) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					faces[1][x] = MyMatrix3::translation(MyVector3(-0.001, 0.0, 0.0)) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					faces[1][x] = MyMatrix3::scale(1.01) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					faces[1][x] = MyMatrix3::scale(0.99) * MyVector3(faces[1][x].x, faces[1][x].y, faces[1][x].z);
				}

				glVertex3f(faces[1][x].x, faces[1][x].y, faces[1][x].z);
			}

			for (int x = 0; x < 4; x++)
			{
				glColor3f(1.0f, 1.0f, 0.0f);
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					faces[2][x] = MyMatrix3::rotationZ(rotationAngle) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					faces[2][x] = MyMatrix3::rotationZ(-rotationAngle) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					faces[2][x] = MyMatrix3::rotationX(rotationAngle) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					faces[2][x] = MyMatrix3::rotationX(-rotationAngle) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					faces[2][x] = MyMatrix3::translation(MyVector3(0.001, 0.0, 0.0)) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					faces[2][x] = MyMatrix3::translation(MyVector3(-0.001, 0.0, 0.0)) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					faces[2][x] = MyMatrix3::scale(1.01) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					faces[2][x] = MyMatrix3::scale(0.99) * MyVector3(faces[2][x].x, faces[2][x].y, faces[2][x].z);
				}
				glVertex3f(faces[2][x].x, faces[2][x].y, faces[2][x].z);
			}

			for (int x = 0; x < 4; x++)
			{
				glColor3f(1.0f, 0.0f, 1.0f);
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					faces[3][x] = MyMatrix3::rotationZ(rotationAngle) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					faces[3][x] = MyMatrix3::rotationZ(-rotationAngle) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					faces[3][x] = MyMatrix3::rotationX(rotationAngle) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					faces[3][x] = MyMatrix3::rotationX(-rotationAngle) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					faces[3][x] = MyMatrix3::translation(MyVector3(0.001, 0.0, 0.0)) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					faces[3][x] = MyMatrix3::translation(MyVector3(-0.001, 0.0, 0.0)) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					faces[3][x] = MyMatrix3::scale(1.01) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					faces[3][x] = MyMatrix3::scale(0.99) * MyVector3(faces[3][x].x, faces[3][x].y, faces[3][x].z);
				}
				glVertex3f(faces[3][x].x, faces[3][x].y, faces[3][x].z);
			}

			for (int x = 0; x < 4; x++)
			{
				glColor3f(0.0f, 1.0f, 1.0f);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					faces[4][x] = MyMatrix3::rotationZ(rotationAngle) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					faces[4][x] = MyMatrix3::rotationZ(-rotationAngle) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					faces[4][x] = MyMatrix3::rotationX(rotationAngle) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					faces[4][x] = MyMatrix3::rotationX(-rotationAngle) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					faces[4][x] = MyMatrix3::translation(MyVector3(0.001, 0.0, 0.0)) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					faces[4][x] = MyMatrix3::translation(MyVector3(-0.001, 0.0, 0.0)) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					faces[4][x] = MyMatrix3::scale(1.01) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					faces[4][x] = MyMatrix3::scale(0.99) * MyVector3(faces[4][x].x, faces[4][x].y, faces[4][x].z);
				}
				glVertex3f(faces[4][x].x, faces[4][x].y, faces[4][x].z);
			}

			for (int x = 0; x < 4; x++)
			{
				glColor3f(0.0f, 0.0f, 1.0f);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					faces[5][x] = MyMatrix3::rotationZ(rotationAngle) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					faces[5][x] = MyMatrix3::rotationZ(-rotationAngle) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					faces[5][x] = MyMatrix3::rotationX(rotationAngle) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					faces[5][x] = MyMatrix3::rotationX(-rotationAngle) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					faces[5][x] = MyMatrix3::translation(MyVector3(0.001, 0.0, 0.0)) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					faces[5][x] = MyMatrix3::translation(MyVector3(-0.001, 0.0, 0.0)) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					faces[5][x] = MyMatrix3::scale(1.01) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					faces[5][x] = MyMatrix3::scale(0.99) * MyVector3(faces[5][x].x, faces[5][x].y, faces[5][x].z);
				}
				glVertex3f(faces[5][x].x, faces[5][x].y, faces[5][x].z);
			}
		}
		glEnd();
		glEndList();

		rotationAngle = 0.0005f;
	}
	
	//cout << "Update up" << endl;
}

void Game::draw()
{
//	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
//	cout << "Cleaning up" << endl;
}

