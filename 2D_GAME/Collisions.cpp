//#include <SFML/Graphics.hpp>
//#include "NPC.h"
//#include "Player.h"

namespace collision
{
    template<class T1, class T2>
    bool isIntersection(T1& obj1, T2& obj2) {
        return obj1.right() >= obj2.left() && obj1.left() <= obj2.right()
            && obj1.down() >= obj2.up() && obj1.up() <= obj2.down();
    }

    //void testCollision(int ) { //Paddle& paddle, Ball& ball
    //    if (!isIntersection(paddle, ball)) return;

    //    ball.speed.y = -ballSpeed;

    //    if (ball.x() < paddle.x()) ball.speed.x = -ballSpeed;
    //    else ball.speed.x = ballSpeed;
    //}

    //void testCollision() { //Brick& block, Ball& ball
    //    if (!isIntersection(block, ball)) return;

    //    block.isDestroiyed = true;

    //    float oll = ball.right() - block.left();
    //    float olr = block.right() - ball.left();
    //    float olu = ball.down() - block.up();
    //    float old = block.down() - ball.up();

    //    bool bfl = abs(oll) < abs(olr);
    //    bool bfu = abs(olu) < abs(old);

    //    bool mOX = bfl ? oll : olr;
    //    bool mOY = bfu ? olu : old;

    //    if (abs(mOX) < abs(mOY)) ball.speed.x = bfl ? -ballSpeed : ballSpeed;
    //    else ball.speed.y = bfu ? -ballSpeed : ballSpeed;
    //}
}
