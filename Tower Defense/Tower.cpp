/* 
 * File:   Tower.cpp
 * Author: samu_b
 * 
 * Created on October 1, 2014, 5:30 PM
 */

#include <stddef.h>
#include<iostream>
#include "Tower.h"
#include "Critter.h"
#include "MapEntity.h"

Tower::Tower() {
}

Tower::Tower(int cost, int range, int power, int initialLevelUpCost, int fireRate, int maxNumOfEffects, char dispChar, std::string name)  {

	this->setDisplayChar(dispChar);
	this->initialDisplayChar = dispChar;
	this->name = name;

    if (cost < 0)
        this->cost = 0;
    else
        this->cost = cost;

    if (range < 0)
        this->range = 0;
    else
        this->range = range;

    if (power < 0)
        this->power = 0;
    else
        this->power = power;

    if (fireRate < 0)
        this->fireRate = 0;
    else
        this->fireRate = fireRate;

    if (maxNumOfEffects < 1) {
        this->maxNumOfEffects = 0;
		this->effects = NULL;
    } else {
        this->maxNumOfEffects = maxNumOfEffects;
        this->effects = new Effect*[maxNumOfEffects];
        for(int i = 0; i < maxNumOfEffects; i++){
            this->effects[i] = NULL;
        }
    }

    if (initialLevelUpCost < 0)
        this->currentLevelUpCost = 0;
    else
        this->currentLevelUpCost = initialLevelUpCost;

    this->hitChanceCounter = 0;
    this->level = 1;
    this->currentCritter = NULL;
    this->currentRefundCost = static_cast<int> (cost * REFUND_RATIO);

}

Tower::Tower(const Tower& orig) {

	this->name = orig.name;
    this->cost = orig.cost;
    this->range = orig.range;
    this->power = orig.power;
    this->fireRate = orig.fireRate;
	this->maxNumOfEffects = orig.maxNumOfEffects;
	if (orig.maxNumOfEffects != 0) {
		this->effects = new Effect*[orig.maxNumOfEffects];
		for (int i = 0; i < orig.maxNumOfEffects; i++){
			this->effects[i] = new Effect(*orig.effects[i]);
		}
	}else{
		this->effects = NULL;
    }
    
    this->currentLevelUpCost = orig.currentLevelUpCost;
    this->hitChanceCounter = 0;
    this->level = orig.level;
    this->currentCritter = NULL;
    this->currentRefundCost = orig.currentRefundCost;
	this->setDisplayChar(orig.getDisplayChar());
	this->initialDisplayChar = orig.initialDisplayChar;
}

Critter* Tower::GetCurrentCritter() const {
    return currentCritter;
}

//This is public and only implemented for the sake of this exercise. 
//It is obviously a security issue, because the effects could be modified.
Effect** Tower::GetEffects() const {
    return effects;
}

int Tower::GetMaxNumOfEffects() const {
    return maxNumOfEffects;
}

int Tower::GetHitChanceCounter() const {
    return hitChanceCounter;
}

void Tower::SetCurrentRefundCost(int currentRefundCost) {
    this->currentRefundCost = currentRefundCost;
}

int Tower::GetCurrentRefundCost() const {
    return currentRefundCost;
}

int Tower::GetCurrentLevelUpCost() const {
    return currentLevelUpCost;
}

int Tower::GetLevel() const {
    return level;
}

int Tower::GetPower() const {
    return power;
}

int Tower::GetRange() const {
    return range;
}

int Tower::GetCost() const {
    return cost;
}

void Tower::SetInitialDisplayChar(char c){
	this->initialDisplayChar = c;
}

Tower::~Tower() {
	for (int i = 0; i < this->maxNumOfEffects; i++){
		delete this->effects[i];
	}
	if (effects != NULL){
		delete[] effects;

	}
}

bool Tower::TryToAttackCritter(CritterGroup& cg) {

    //If the tower is not attacking or if the critter it was attacking is dead
	bool res = false;
    if (this->NeedNewTarget()) {
       
        if (this->FindFirstCritterInRange(cg)) {
            res = this->AttackCritter(*this->currentCritter);
        }
    } else {
        res =  AttackCritter(*this->currentCritter);
    }

	//Reset the current critter to NULL to have a proper view
	if (this->GetCurrentCritter() != NULL && this->GetCurrentCritter()->GetState() == CritterState::Dead){
		this->SetCurrentCritter(NULL);
	}

	//Not to abuse the notofications to the view
	if (!res){
		if (this->getDisplayChar() != this->initialDisplayChar){
			this->setDisplayChar(this->initialDisplayChar);
		}
	}
	return res;
}

bool Tower::AttackCritter(Critter& crit) {
    if (this->CanTowerHit()) {
		this->setDisplayChar('*');
        this->ApplyEffectsAndDamage(crit);
		if (crit.GetState() == CritterState::Dead){
			this->currentCritter = NULL;
		}

        return true;
    } else {

        return false;
    }

}

bool Tower::CanTowerHit() {
    return !(this->hitChanceCounter++ % this->fireRate);
}

bool Tower::NeedNewTarget() const {
    return (this->currentCritter == NULL || this->currentCritter->GetState() == CritterState::Dead || ! this->isInRange(*this->currentCritter, this->range));
}

bool Tower::FindFirstCritterInRange(CritterGroup& cg) {
    
    Critter** critLst = cg.GetCritters();
    int maxCrit = cg.GetMaxNumOfCritters();
    for (int i = 0; i < maxCrit; i++) {
		if (critLst[i] != NULL){
			if (critLst[i]->GetState() != CritterState::Dead && this->isInRange(*critLst[i], this->range)) {
				this->hitChanceCounter = 0;
				this->currentCritter = *(critLst + i);
				return true;
			}
		}
    }
	return false;
}

void Tower::ApplyEffectsAndDamage(Critter& crit) {
    for (int i = 0; i < this->maxNumOfEffects; i++) {
        
        if (this->effects[i] != NULL) {
            this->effects[i]->ApplyEffect(crit);
        }
    }
    crit.ApplyDamage(this->power);
}

bool Tower::AddEffect(const Effect& eff) {

    if (this->effects != NULL) {
        for (int i = 0; i < this->maxNumOfEffects; i++) {
            if (this->effects[i] == NULL) {
                this->effects[i] = new Effect(eff);
                return true;
            }
        }
    }

    return false;

}

bool Tower::CanBuy(int amount) {
    return (amount >= this->cost);
}

bool Tower::TryToLevelUp(int amount){
    
    if(amount < this->currentLevelUpCost || this->level == MAX_LEVEL){
        return false;
    }else{
        this->level++;
        this->power += LEVEL_UP_MODIFIER;
        
        for (int i = 0; i < this->maxNumOfEffects; i++){
            if (this->effects[i] != NULL){
                this->effects[i]->LevelUp();
            }
        }
        
        this->currentLevelUpCost = static_cast<int>(this->currentLevelUpCost * LEVEL_RATIO);
        this->currentRefundCost = static_cast<int>(this->currentRefundCost * LEVEL_RATIO);
        
		//Notify only if the level up succeded
		Notify();

        return true;
    }
    
}

void Tower::SetCurrentCritter(Critter* c){
	this->currentCritter = c;
	Notify();
}

