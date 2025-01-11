//
// Created by will on 1/10/2025.
//

#ifndef SNAKE_RAYLIB_APPLE_H
#define SNAKE_RAYLIB_APPLE_H

#include <functional>
#include <utility>
#include "raylib.h"

class AppleRenderComponent;
class Player;

class Apple {
public:
//    Apple(AppleRenderComponent *renderComponent_, Player *player, std::function<void()> updateScore)
//            : renderComponent_(renderComponent_), player_(player), updateScoreCallback_(std::move(updateScore)) {
//        initPosition();
//    };
    Apple(Player &player, std::function<void()> updateScore);
    ~Apple();
    void update();
    void initPosition();
    Vector2 getPosition();

private:
    
    bool checkForHeadCollision();
    
    AppleRenderComponent *renderComponent_;
    Player &player_;
    std::function<void()> updateScoreCallback_;
    Vector2 position_;
};


#endif //SNAKE_RAYLIB_APPLE_H
