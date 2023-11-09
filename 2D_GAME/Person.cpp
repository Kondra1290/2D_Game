#include "Person.h"

Person::Person(int pX, int pY, string name, int health) {
	shape.setPosition(pX, pY);
	shape.setSize(Vector2f(50.f, 50.f));
	shape.setOrigin(shape.getSize().x / 2.f, shape.getSize().y / 2.f);

	this->name = name;
	this->health = health;
}

Person::Person(int pX, int pY, string name, int health, vector<RectangleShape> invetnory) :
	Person(pX, pY, name, health)
{
	this->inventory = invetnory;
}

Person::Person(int pX, int pY, string name, int health, vector<RectangleShape> invetnory, TypeOfPerson type) :
	Person(pX, pY, name, health, invetnory)
{
	this->type = type;
}

RectangleShape Person::getShape()				{ return shape; }
string		   Person::getName()				{ return name; }
float		   Person::getHealth()				{ return health; }
void		   Person::setHealth(float value)	{ health -= value; }
TypeOfPerson   Person::getType()				{ return type; }

void Person::Move(float destination, float speed, float way) {
	

	/*if (Keyboard::isKeyPressed(Keyboard::A) && )				this->speed.x = -speed;
	else if (Keyboard::isKeyPressed(Keyboard::D) && right())	this->speed.x = speed;
	else if (Keyboard::isKeyPressed(Keyboard::W) && up())		this->speed.y = -speed;
	else if (Keyboard::isKeyPressed(Keyboard::S) && down())		this->speed.y = speed;
	else {
		this->speed.x = 0;
		this->speed.y = 0;
	}*/

	float distX = destination - x();
	float distY = destination - y();

	/*if (Keyboard::isKeyPressed(Keyboard::A)	&& left())			shape.move(-speed, 0.f);
	else if (Keyboard::isKeyPressed(Keyboard::D) && right())	shape.move(speed, 0.f);
	else if (Keyboard::isKeyPressed(Keyboard::W) && up())		shape.move(0.f, -speed);
	else if (Keyboard::isKeyPressed(Keyboard::S) && down())		shape.move(0.f, speed);*/

	if (Keyboard::isKeyPressed(Keyboard::A)	&& left())			shape.move(-speed, 0.f);
	else if (Keyboard::isKeyPressed(Keyboard::D) && right())	shape.move(speed, 0.f);
	else if (Keyboard::isKeyPressed(Keyboard::W) && up())		shape.move(0.f, -speed);
	else if (Keyboard::isKeyPressed(Keyboard::S) && down())		shape.move(0.f, speed);

	//shape.setPosition();
}


float Person::Rotare(Vector2f pos) {
	float dX = pos.x - x();//вектор , колинеарный прямой, которая пересекает спрайт и курсор
	float dY = pos.y - y();//он же, координата y
	float rotation = (atan2(dY, dX)) * 180 / 3.14159265;//получаем угол в радианах и переводим его в градусы
	shape.setRotation(rotation);//поворачиваем спрайт на эти градусы
	return rotation;
}

float Person::x() { return shape.getPosition().x; }
float Person::y() { return shape.getPosition().y; }
float Person::left() { return x() - shape.getSize().x / 2.f; }
float Person::right() { return x() + shape.getSize().x / 2.f; }
float Person::up() { return y() - shape.getSize().y / 2.f; }
float Person::down() { return y() + shape.getSize().y / 2.f; }