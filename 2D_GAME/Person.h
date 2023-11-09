#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "TypeOfPerson.cpp"
using namespace sf;
using namespace std;

enum class TypeOfPerson {
	PLAYER,
	ENEMY,
	NETRAL,
	FRIEND
};

class Person
{
protected:
	RectangleShape shape;
	string name;
	vector<RectangleShape> inventory;
	TypeOfPerson type;
	Vector2f pos;
	float health;
	Vector2f speed{3.f, 3.f};

public:
	Person(int, int, string, int);
	Person(int, int, string, int, vector<RectangleShape>);
	Person(int, int, string, int, vector<RectangleShape>, TypeOfPerson);

	void Move(float, float, float);
	float Rotare(Vector2f);

	RectangleShape getShape();
	string getName();
	float getHealth();
	void setHealth(float);
	TypeOfPerson getType();

	float x();
	float y();
	float left();
	float right();
	float up();
	float down();
};

