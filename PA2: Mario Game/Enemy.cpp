#include "Enemy.h"

Enemy::Enemy() {
    wins = 0;
}

Enemy::~Enemy() {
}

bool Enemy::goomba() {
    // to ensure the random numbers being generated aren't repeated in a constant order
    int x = time(0);
    srand(x);
    // variable used to decide if Mario wins or not (rand num from 1-5)
    int randNum = 1 + rand() % 5;
    // runs if Mario lost
    if (randNum == 1) {
        wins = 0;
        return false;
    }
    // runs if Mario won
    else {
        // win count increases by 1
        wins += 1;
        return true;
    }
}

bool Enemy::koopa() {
    int x = time(0);
    srand(x);
    int randNum = 1 + rand() % 20;
    if (randNum <= 7) {
        wins = 0;
        return false;
    }
    else {
        wins += 1;
        return true;
    }
}

bool Enemy::regBoss() {
    int x = time(0);
    srand(x);
    int randNum = 1 + rand() % 5;
    if (randNum == 1) {
        wins = 0;
        return false;
    }
    else {
        wins += 1;
        return true;
    }
}

bool Enemy::finalBoss() {
    int x = time(0);
    srand(x);
    int randNum = 1 + rand() % 5;
    if (randNum == 1) {
        wins = 0;
        return false;
    }
    else {
        wins += 1;
        return true;
    }
} 

// checks if mario is on win streak of 7 or more wins
// if true, win count is reduced by 7, and function returns true
bool Enemy::winStreak() {
    if (wins >= 7) {
        wins -= 7;
        return true;
    }
    return false;
}