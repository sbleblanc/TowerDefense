/* 
 * File:   Critter.cpp
 * Author: samu_b
 * 
 * Created on October 8, 2014, 6:36 PM
 */

#include "Critter.h"

Critter::Critter() {
	state = CritterState::Alive;
	this->currentEffectType = EffectType::None;
}
Critter::Critter(int hp, int speed) : healthPoints(hp), speed(speed), state(CritterState::Alive), currentEffectType(EffectType::None){

}

Critter::Critter(const Critter& orig) {
}

Critter::~Critter() {
}

void Critter::ApplyDamage(int dmgAmount){
    

    this->healthPoints -= dmgAmount;
    if (this->healthPoints <= 0){
        this->state = CritterState::Dead;
    }
}

CritterState Critter::GetState() const {
    return state;
}

int Critter::GetHP() const{
	return this->healthPoints;
}

void Critter::Move(Direction d){

	switch (d){
	case Direction::RIGHT:
		this->SetPosition(this->getX() + this->speed, this->getY());
		break;
	}

}

void Critter::SetEffectType(EffectType et){
	this->currentEffectType = et;
}

void Critter::SetSpeed(int sp){
	this->speed = sp;
	if (this->speed < 1){
		this->speed = 1;
	}
}
