#pragma once
#include "Person.h"

class Player :
    public Person
{
public:
    Player(int , int, string, int, vector<RectangleShape>);
    void Attack();
};

