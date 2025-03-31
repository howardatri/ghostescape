#include "player.h"
#include "core/scene.h"
#include "affiliate/sprite_anim.h"
#include "affiliate/collider.h"
#include "raw/stats.h"
void Player::init()
{
    Actor::init();
    max_speed_ = 500.0f;
    sprite_idle_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-idle.png", 2.0f);
    sprite_move_ = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-move.png", 2.0f);
    sprite_move_->setActive(false);

    collider_ = Collider::addColliderChild(this, sprite_idle_->getSize() / 2.0f);
    stats_ = Stats::addStatsChild(this);
}

void Player::handleEvents(SDL_Event& event)
{
    Actor::handleEvents(event);
}

void Player::update(float dt)
{
    Actor::update(dt);
    keyboardControl();
    velocity_ *= 0.9f;
    checkState();
    move(dt);
    syncCamera();
    //isAlive();// check if player is alive
}

void Player::render()
{
    Actor::render();
}

void Player::clean()
{
    Actor::clean();
}

void Player::keyboardControl()
{
    auto currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_W]){
        velocity_.y = -max_speed_;
    }
    if (currentKeyStates[SDL_SCANCODE_S]){
        velocity_.y = max_speed_;
    }
    if (currentKeyStates[SDL_SCANCODE_A]){
        velocity_.x = -max_speed_;
    }
    if (currentKeyStates[SDL_SCANCODE_D]){
        velocity_.x = max_speed_;
    }
}

void Player::syncCamera()
{
    game_.getCurrentScene()->setCameraPosition(position_ - game_.getScreenSize() / 2.0f);
}

void Player::checkState()
{
    
    if (velocity_.x < 0){
        sprite_move_->setFlip(true);
        sprite_idle_->setFlip(true);
    }else{
        sprite_move_->setFlip(false);
        sprite_idle_->setFlip(false);
    }
    
    bool new_is_moving = (glm::length(velocity_) > 0.1f);
    if (new_is_moving != is_moving_){
        is_moving_ = new_is_moving;
        changeState(is_moving_);
    }
}

void Player::changeState(bool is_moving)
{
    if (is_moving){
        sprite_idle_->setActive(false);
        sprite_move_->setActive(true);
        sprite_move_->setCurrentFrame(sprite_idle_->getCurrentFrame());
        sprite_move_->setFrameTimer(sprite_idle_->getFrameTimer());
        
    }else{
        sprite_idle_->setActive(true);
        sprite_move_->setActive(false);
        sprite_idle_->setCurrentFrame(sprite_move_->getCurrentFrame());
        sprite_idle_->setFrameTimer(sprite_move_->getFrameTimer());
    }
}
    