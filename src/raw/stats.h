#ifndef STATS_H
#define STATS_H

#include "../core/actor.h"

class Stats : public Object
{
protected:
    Actor* parent_=nullptr;
    float health_=100.0f;
    float max_health_=100.0f;
    float mana_=100.0f;
    float max_mana_=100.0f;
    float damage_=40.0f;
    float mana_regen_=10.0f;

    float invisible_time_ = 1.5f; // invisible time
    float invisible_timer_ = 0.0f; // invisible timer
    bool is_alive_ = true;
    bool is_invisible_ = false;

public:
    static Stats* addStatsChild(Actor* parent, float max_health =100.0f,  float max_mana=100.0f, float damage=40.0f, float mana_regen = 10.0f);
    virtual void update(float dt) override;
    bool canUseMana(float mana_cost);
    void useMana(float mana_cost) ;
    void regenMana(float dt);
    void takeDamage(float damage) ;

    // getters and setters
    float getHealth() { return health_; }
    void setHealth(float health) { health_ = health; }
    float getMaxHealth() { return max_health_; }
    void setMaxHealth(float max_health) { max_health_ = max_health; }
    float getMana() { return mana_;}
    void setMana(float mana) { mana_ = mana; }
    float getMaxMana() { return max_mana_; }
    void setMaxMana(float max_mana) { max_mana_ = max_mana; }
    float getDamage() { return damage_; }
    void setDamage(float damage) { damage_ = damage; }
    float getManaRegen() { return mana_regen_; }
    void setManaRegen(float mana_regen) { mana_regen_ = mana_regen; }
    void setAlive(bool is_alive) { is_alive_ = is_alive; }
    bool isAlive() { return is_alive_; }
    Actor* getParent() { return parent_; }
    void setParent(Actor* parent) { parent_ = parent; }
    void setInvisible(bool is_invisible) { is_invisible_ = is_invisible; }
    bool isInvisible() { return is_invisible_; }
    float getInvisibleTimer() { return invisible_timer_; }
    void setInvisibleTimer(float invisible_timer) { invisible_timer_ = invisible_timer; }

};



#endif // STATS_H