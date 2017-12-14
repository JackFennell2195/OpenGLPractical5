#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
{
	index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

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
	gluPerspective(43.0, window.getSize().x / 
		window.getSize().y, 3.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	 // Uncomment for Part 2
	 // ********************
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		//rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
	{
		glScalef(1.0001f, 1.0001f, 1.000000001f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		glTranslatef(0.01f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		glTranslatef(0.01f*-1, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		glRotatef(rotationAngle*-1, 0.0f, 0.0f, 1.0f);
	}
	 // ********************
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POINTS); {
	glVertex3f(-1.7, 1.7, -5.0);
	}
	glEnd();
	
	glBegin(GL_LINES); {
	glVertex3f(-1.6, 1.7, -5.0);
	glVertex3f(-1.2, 1.3, -5.0);
	}
	glEnd();

	
	glBegin(GL_LINE_STRIP); {
	glVertex3f(-1.2, 1.7, -5.0);
	glVertex3f(-0.7, 1.3, -5.0);
	glVertex3f(-0.7, 1.7, -5.0);
	}
	glEnd();

	
	glBegin(GL_LINE_LOOP); {
	glVertex3f(-0.65, 1.7, -5.0);
	glVertex3f(-0.2, 1.3, -5.0);
	glVertex3f(0.2,1.3, -5.0);
	glVertex3f(-0.2, 1.7, -5.0);
	}
	glEnd();

	glBegin(GL_TRIANGLES); { 
	glVertex3f(0.1, 1.7, -5.0);
	glVertex3f(0.5, 1.3, -5.0);
	glVertex3f(0.5, 1.7, -5.0);
	} 
	glEnd(); 
	
	
	glBegin(GL_TRIANGLE_STRIP); {
	glVertex3f(0.6, 1.7, -5.0);
	glVertex3f(0.9, 1.3, -5.0);
	glVertex3f(0.9, 1.7, -5.0);
	glVertex3f(1.3, 1.3, -5.0);
	}
	glEnd();

	
	glBegin(GL_TRIANGLE_FAN); {
	glVertex3f(-1.4, 0.6, -5.0);
	glVertex3f(-1.7, 0.9, -5.0);
	glVertex3f(-1.8, 0.6, -5.0);
	glVertex3f(-1.7, 0.3, -5.0);
	glVertex3f(-1.4, 0.15, -5.0);
	glVertex3f(-1.1, 0.3, -5.0);
	glVertex3f(-1.0, 0.6, -5.0);
	glVertex3f(-1.1, 0.9, -5.0);
	}
	glEnd();

	
	glBegin(GL_QUADS); {
	glVertex3f(-0.9, 1.2, -5.0);
	glVertex3f(-0.6, 1.2, -5.0);
	glVertex3f(-0.3, 0.8, -5.0);
	glVertex3f(-0.6, 0.8, -5.0);
	}
	glEnd();

	
	glBegin(GL_QUAD_STRIP); {
	glVertex3f(-0.2, 0.8, -5.0);
	glVertex3f(-0.1, 1.2, -5.0);
	glVertex3f(0.2, 0.8, -5.0);
	glVertex3f(0.1, 1.2, -5.0);
	glVertex3f(0.5, 0.8, -5.0);
	glVertex3f(0.6, 1.2, -5.0);
	}
	glEnd();

	
	glBegin(GL_POLYGON); {
	glVertex3f(1.1, 0.9, -5.0);
	glVertex3f(1.4, 1.1, -5.0);
	glVertex3f(1.7, 0.9, -5.0);
	glVertex3f(1.8, 0.6, -5.0);
	glVertex3f(1.7, 0.3, -5.0);
	glVertex3f(1.4, 0.15, -5.0);
	glVertex3f(1.1, 0.3, -5.0);
	glVertex3f(1.0, 0.6, -5.0);
	}
	glEnd();
	cout << "Drawing Primative " << current << endl;
	glCallList(current);
	
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

