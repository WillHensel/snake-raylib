//
// Created by will on 1/8/2025.
//

#include <gtest/gtest.h>
#include "../src/Player.h"

TEST(PlayerTests, MoveForward) {
    Player player{};

    ASSERT_EQ(player.getHeadPos().x, 0);
    ASSERT_EQ(player.getHeadPos().y, 0);
    
    player.moveForward();
    
    ASSERT_EQ(player.getHeadPos().x, -1);
    ASSERT_EQ(player.getHeadPos().y, 0);
}

TEST(PlayerTests, AddTail) {
    Player player{};

    ASSERT_EQ(player.getCellCount(), 1);
    
    player.addTail();
    
    ASSERT_EQ(player.getCellCount(), 2);
    
    ASSERT_EQ(player.getHeadPos().x, player.getTailPos().x);
    ASSERT_EQ(player.getHeadPos().y, player.getTailPos().y);
}

TEST(PlayerTests, AddTailAndMoveForward) {
    Player player{};

    ASSERT_EQ(player.getCellCount(), 1);

    player.addTail();

    ASSERT_EQ(player.getCellCount(), 2);

    ASSERT_EQ(player.getHeadPos().x, player.getTailPos().x);
    ASSERT_EQ(player.getHeadPos().y, player.getTailPos().y);
    
    player.moveForward();
    
    ASSERT_EQ(player.getHeadPos().x, player.getTailPos().x - 1);
    ASSERT_EQ(player.getHeadPos().y, player.getTailPos().y);
    
    player.moveForward();
    ASSERT_EQ(player.getHeadPos().x, player.getTailPos().x - 1);
    ASSERT_EQ(player.getHeadPos().y, player.getTailPos().y);
}
