#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "affiliate/sprite_anim.h"

class Enemy : public Actor
{
    enum class State{
        NORMAL,
        HURT,
        DIE
    };
    State current_state_ = State::NORMAL;
    
    Player* target_ = nullptr;
    SpriteAnim* anim_normal_ = nullptr;
    SpriteAnim* anim_hurt_ = nullptr;
    SpriteAnim* anim_die_ = nullptr;

    SpriteAnim* current_anim_ = nullptr;

    float timer_ = 0.0f;

public:
    virtual void init();
    virtual void update(float dt) override;  // override the update function from Actor

    void aim_target(Player* target);

    void checkState();
    void changeState(State new_state);
    void remove();

    // getters and setters
    Player* get_target() { return target_; }
    void set_target(Player* target) { target_ = target; }
};








#endif // ENEMY_H