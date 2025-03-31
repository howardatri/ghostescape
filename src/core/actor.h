#ifndef ACTOR_H
#define ACTOR_H

#include "object_world.h"

class Stats; // 前向声明

class Actor : public ObjectWorld
{
protected:
    Stats* stats_ = nullptr; // 角色的属性
    glm::vec2 velocity_ = glm::vec2(0, 0); // 速度
    float max_speed_ = 100.0f; // 最大速度大小

public:

    void move(float dt);    // 移动
    // getters and setters
    glm::vec2 getVelocity() const { return velocity_; }
    void setVelocity(const glm::vec2 &velocity) { velocity_ = velocity; }
    float getMaxSpeed() const { return max_speed_; }
    void setMaxSpeed(float max_speed) { max_speed_ = max_speed; }
    Stats* getStats() { return stats_; }
    void setStats(Stats* stats) { stats_ = stats; }
    void takeDamage(float damage);
    bool isAlive()const;
};






#endif // ACTOR_H