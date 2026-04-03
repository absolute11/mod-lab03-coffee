// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, OnChangesStateToWait) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, OffChangesStateToOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, CoinChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(20);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, CoinAddsCash) {
    Automata a;
    a.on();
    a.coin(20);
    a.coin(15);
    EXPECT_EQ(a.cash, 35);
}

TEST(AutomataTest, ChoiceChangesStateToCheck) {
    Automata a;
    a.on();
    a.coin(30);
    a.choice(3);
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(AutomataTest, CheckReturnsTrueWhenEnoughCash) {
    Automata a;
    a.on();
    a.coin(35);
    a.choice(1);
    EXPECT_TRUE(a.check());
}

TEST(AutomataTest, CheckReturnsFalseWhenNotEnoughCash) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(1);
    EXPECT_FALSE(a.check());
}

TEST(AutomataTest, CookChangesStateToCook) {
    Automata a;
    a.on();
    a.coin(35);
    a.choice(1);
    a.cook();
    EXPECT_EQ(a.getState(), COOK);
}

TEST(AutomataTest, FinishChangesStateToWait) {
    Automata a;
    a.on();
    a.coin(35);
    a.choice(1);
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CancelResetsToWait) {
    Automata a;
    a.on();
    a.coin(20);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CancelResetsCash) {
    Automata a;
    a.on();
    a.coin(20);
    a.cancel();
    EXPECT_EQ(a.cash, 0);
}
