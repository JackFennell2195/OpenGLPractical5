#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
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
	gluPerspective(47.0, window.getSize().x / 
		window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POINTS); {
	glVertex3f(0.0, 2.0, -7.0);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES); {
	glVertex3f(0.0, 2.0, -7.0);
	glVertex3f(-2.0, -2.0, -7.0);
	}
	glEnd();


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINE_STRIP); {
	glVertex3f(0.0, 2.0, -7.0);
	glVertex3f(-2.0, -2.0, -7.0);
	glVertex3f(2.0, -2.0, -7.0);
	glVertex3f(2.0, -2.0, -7.0);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINE_LOOP); {
	glVertex3f(0.0, 2.0, -7.0);
	glVertex3f(-2.0, -2.0, -7.0);
	glVertex3f(2.0, -2.0, -7.0);
	glVertex3f(2.0, -2.0, -7.0);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glBegin(GL_TRIANGLES); { 
		glVertex3f(0.0, 2.0, -6.0); 
		glVertex3f(-2.0, -2.0, -6.0); 
		glVertex3f(2.0, -2.0, -6.0); 
	} 
	glEnd(); 
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP); {
		glVertex3f(0.0, 2.0, -6.0);
		glVertex3f(-1.0, -1.0, -6.0);
		glVertex3f(1.0, -1.0, -6.0);
		glVertex3f(1.5, -2.5, -6.0);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN); {
	glVertex3f(0.0, 2.0, -6.0);
		glVertex3f(-1.0, -1.0, -6.0);
		glVertex3f(1.0, -1.0, -6.0);
		glVertex3f(1.5, -2.5, -6.0);
		glVertex3f(2.5, 2.5, -6.0);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUADS); {
	glVertex3f(0.0, 1.0, -7.5);
	glVertex3f(-2.0, -2.0, -7.5);
	glVertex3f(2.0, -2.0, -7.5);
	glVertex3f(2.0, 2.0, -7.5);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUAD_STRIP); {
	glVertex3f(0.0, 1.0, -7.5);
	glVertex3f(-2.0, -2.0, -7.5);
	glVertex3f(2.0, -2.0, -7.5);
	glVertex3f(2.0, 2.0, -7.5);
	glVertex3f(0.0, 2.0, -7.5);
	glVertex3f(-2.0, -2.0, -7.5);
	}
	glEnd();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON); {
	glVertex3f(0.0, 1.0, -7.5);
	glVertex3f(-2.0, -2.0, -7.5);
	glVertex3f(2.0, -2.0, -7.5);
	glVertex3f(2.0, 2.0, -7.5);
	glVertex3f(1.0, 0.0, -7.5);
	glVertex3f(-1.0, 0.0, -7.5);
	glVertex3f(1.0, 1.0, -7.5);
	glVertex3f(-1.0, -1.0, -7.5);
	glVertex3f(0.5, 0.5, -7.5);
	}
	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

