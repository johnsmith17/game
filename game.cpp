// game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int screen_x = 640;
int screen_y = 400;

bool GameOver = false;



struct Player
{
	float pos_x;
	float pos_y;
	float spd_y;
	float height  = 40;
	float width = 10;
	int score = 0;

	void UpdatePos()
	{

		pos_y += spd_y;
	}

};

struct Ball
{

	float pos_x;
	float pos_y;
	float spd_x;
	float spd_y;
	float size = 10;

	void Check_wall_collision()
	{
		if ((pos_y < 0) || ((pos_y+size) > screen_y))
		{
			spd_y = -spd_y;
		}

		if ((pos_x < 0) || ((pos_x + size) > screen_x))
		{
			pos_y = screen_y / 2;
			pos_x = screen_x / 2;
		}
	}

	
	void UpdatePos()
	{
		pos_x += spd_x;
		pos_y += spd_y;
	}
	
};


int main()
{
	cout << " LEVA STRAN : W/S , DESNA STRAN : PUSCICE ZA GOR/DOL ";
	RenderWindow window(VideoMode(screen_x, screen_y), "Pong");
	window.setFramerateLimit(60);


	Ball ball;
	ball.pos_x = screen_x / 2;
	ball.pos_y = screen_y / 2;
	ball.spd_x = 5.0;
	ball.spd_y = 2.0;

	Player player1;
	player1.pos_x = 0;
	player1.pos_y = (screen_y / 2) -20;
	player1.spd_y = 0;


	Player player2;
	player2.pos_x = screen_x - player2.width;
	player2.pos_y = (screen_y / 2) -20;
	player2.spd_y = 0;


	RectangleShape ball_sprite(Vector2f(ball.size, ball.size));

	RectangleShape player1_sprite(Vector2f(player1.width, player1.height));

	RectangleShape player2_sprite(Vector2f(player2.width, player2.height));
	

	while (window.isOpen())  // main loop
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
			window.close();
			}
		}

		if (((ball.pos_y + ball.size) > (player1.pos_y)) && ((ball.pos_y) < (player1.pos_y))) {
			if (ball.pos_x < player1.width) {
				ball.spd_x = -ball.spd_x;
			}
		}

		if (((ball.pos_y) < (player1.pos_y + player1.height)) && ((ball.pos_y + ball.size) > (player1.pos_y + player1.height))) {
			if (ball.pos_x < player1.width) {
				ball.spd_x = -ball.spd_x;
			}
		}

		if ((ball.pos_y > player1.pos_y) && ((ball.pos_y + ball.size) < (player1.pos_y + player1.height))) {
			if (ball.pos_x < player1.width) {
				ball.spd_x = -ball.spd_x;
			}
		}


		if (((ball.pos_y + ball.size) > (player2.pos_y)) && ((ball.pos_y) < (player2.pos_y))) {
			if ((ball.pos_x + ball.size) > (player2.pos_x)) {
				ball.spd_x = -ball.spd_x;
			}
		}

		if (((ball.pos_y) < (player2.pos_y + player2.height)) && ((ball.pos_y + ball.size) > (player2.pos_y + player2.height))) {
			if ((ball.pos_x + ball.size) > (player2.pos_x)) {
				ball.spd_x = -ball.spd_x;
			}
		}

		if ((ball.pos_y > player2.pos_y) && ((ball.pos_y + ball.size) < (player2.pos_y + player2.height))) {
			if ((ball.pos_x + ball.size) > (player2.pos_x)) {
				ball.spd_x = -ball.spd_x;
			}
		}

		
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player1.spd_y = -8;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player1.spd_y = 8;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			player2.spd_y = -8;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			player2.spd_y = 8;
		}

		player1.UpdatePos();
		player2.UpdatePos();
		player1.spd_y = 0;
		player2.spd_y = 0;
		
		ball.UpdatePos();
		ball.Check_wall_collision();
		

		ball_sprite.setPosition(ball.pos_x, ball.pos_y);
		player1_sprite.setPosition(player1.pos_x, player1.pos_y);
		player2_sprite.setPosition(player2.pos_x, player2.pos_y);

		window.clear();
		window.draw(ball_sprite);
		window.draw(player1_sprite);
		window.draw(player2_sprite);
		window.display();

		
	}

	//p.s. aljaž je papak

	return 0;
}