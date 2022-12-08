#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
using namespace sf;

int main()
{
	srand(time(nullptr));
	speedx = rand() % 20 - 10;
	speedy = rand() % 20 - 10;
	RectangleShape rect(Vector2f(ax, ay));
	RectangleShape rect1(Vector2f(ax, ay));
	CircleShape circle(r);

	rect.setFillColor(Left_Bat_Color);
	rect1.setFillColor(Right_Bat_Color);
	circle.setFillColor(Circle_Color);

	rect.setPosition(Bat_Ofset, size / 2 - ay / 2);
	rect1.setPosition(size - Bat_Ofset - ax, size / 2 - ay / 2);
	circle.setPosition(size / 2 - r, size / 2 - r);

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(size, size), "SFML Works!");
	window.setFramerateLimit(FPS);

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//���������� �������� ����

		circle.move(speedx, speedy);
		if (circle.getPosition().x + 2 * r > size ||
			circle.getPosition().x < 0) {
			speedx = -speedx;
		}

		if (circle.getPosition().y + 2 * r > size ||
			circle.getPosition().y < 0) {
			speedy = -speedy;
		}
		//������� �������
		//������
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rect1.move(0, -BatDy);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rect1.move(0, BatDy);
		}
		//�����
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			rect.move(0, -BatDy);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			rect.move(0, BatDy);
		}

		//������� �������
		//�����
		if (rect.getPosition().y + ay > size){
			rect.move(0, -BatDy);
		}
		if (rect.getPosition().y  < 0) {
			rect.move(0, BatDy);
		}

		//������
		if (rect1.getPosition().y + ay > size) {
			rect1.move(0, -BatDy);
		}
		if (rect1.getPosition().y < 0) {
			rect1.move(0, BatDy);
		}

		// ��������� �������� � ���� 
		window.clear();
		window.draw(rect);
		window.draw(rect1);
		window.draw(circle);
		window.display();

	}

	return 0;
}