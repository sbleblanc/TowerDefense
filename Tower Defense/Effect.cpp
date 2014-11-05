/* 
 * File:   Effect.cpp
 * Author: samu_b
 * 
 * Created on October 1, 2014, 5:36 PM
 */

#include "Effect.h"

Effect::Effect() {
}

Effect::Effect(int sm, int hm, int ed, CritterType sa, EffectType et) {
    if (sm < 0)
        this->speedModifier = 0;
    else
        this->speedModifier = sm;

    if (hm < 0)
        this->healthModifier = hm;
    else
        this->healthModifier = hm;

    if (ed < 0)
        this->extraDamage = 0;
    else
        this->extraDamage = ed;

    this->type = et;
    this->enhancedAgainst = sa;
    this->level =1;
}

Effect::Effect(const Effect& orig) {
    this->enhancedAgainst = orig.enhancedAgainst;
    this->extraDamage = orig.extraDamage;
    this->healthModifier = orig.healthModifier;
    this->speedModifier = orig.speedModifier;
    this->type = orig.type;

}

Effect::~Effect() {
}

//I'm doing this operation in Effect because I wasn't able to include Effect.h in my critter source files (I don't know why, but when I do it, all hell breaks loose)
void Effect::ApplyEffect(Critter& crit) const {
	if (crit.GetEffectType() != this->type){
		crit.SetEffectType(this->type);
		//would modify every critter states depending on the effect applied. Here, in that case, only Slow will exist (for now)
		crit.SetSpeed(crit.GetSpeed() - this->speedModifier);
	}
	

}

void Effect::LevelUp() {

    switch (this->type) {
        case EffectType::Slow:
            this->speedModifier += LEVEL_UP_MODIFIER;
            break;
    }
    this->level++;
}

