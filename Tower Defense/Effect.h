/* 
 * File:   Effect.h
 * Author: samu_b
 *
 * Created on October 1, 2014, 5:36 PM
 */

#ifndef EFFECT_H
#define	EFFECT_H

#include "Critter.h"



class Effect {
    
    
    
public:
    Effect();
    Effect(int sm, int hm, int ed, CritterType sa, EffectType et);
    Effect(const Effect& orig);
    virtual ~Effect();
    void ApplyEffect(Critter& ) const;
    void LevelUp();
	EffectType getType() const { return this->type; }


private:
    
    const int LEVEL_UP_MODIFIER  = 1;
    
    int level;
    int speedModifier;
    int healthModifier;
    int extraDamage;
    CritterType enhancedAgainst;
    EffectType type;
    
};

#endif	/* EFFECT_H */

