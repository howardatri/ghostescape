#include "stats.h"

Stats *Stats::addStatsChild(Actor *parent, float max_health, float max_mana, float damage, float mana_regen)
{
    Stats *stats = new Stats();
    stats->parent_ = parent;
    stats->max_health_ = max_health;
    stats->max_mana_ = max_mana;
    stats->damage_ = damage;
    stats->mana_regen_ = mana_regen;
    stats->health_ = max_health;
    stats->mana_ = max_mana;
    parent->addChild(stats);
    return stats;
}

void Stats::update(float dt)
{
    Object::update(dt);
    regenMana(dt);
    if(is_invisible_) { // if invisible, decrease invisible timer
        invisible_timer_ += dt;
        if(invisible_timer_ >=invisible_time_) { // if invisible timer is over, become visible again
            is_invisible_ = false;
            invisible_timer_ = 0.0f;
        }
    }
}

void Stats::takeDamage(float damage)
{
    if (is_invisible_) return; // if invisible, ignore damage

    health_ -= damage;
    if (health_ < 0) {
        health_ = 0;
        is_alive_ = false;
    }
    SDL_Log("Stats health: %f", health_);
    is_invisible_ = true; // become invisible after taking damage
    invisible_timer_ = 0.0f; // reset invisible timer
}

bool Stats::canUseMana(float mana_cost)
{
    return mana_ >= mana_cost;
}

void Stats::useMana(float mana_cost)
{
    mana_ -= mana_cost;
    if (mana_ < 0) {
        mana_ = 0;
    }
}

void Stats::regenMana(float dt)
{
    mana_ += mana_regen_ * dt;
    if (mana_ > max_mana_) mana_ = max_mana_;
}
