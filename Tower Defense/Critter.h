/* 
 * File:   Critter.h
 * Author: samu_b
 *
 * Created on October 8, 2014, 6:36 PM
 */

#ifndef CRITTER_H
#define	CRITTER_H

#include "MapEntity.h"

enum class EffectType {
	None, Slow,
};

enum class CritterType {
    None, Type1, Type2, Type3, Type4, Type5
};

enum class CritterState {
    Alive, Dead
};

enum class Direction{
	RIGHT, LEFT, TOP, DOWN
};


class Critter : public MapEntity {
public:

    Critter();
	Critter(int, int);
    Critter(const Critter& orig);
    virtual ~Critter();
    CritterState GetState() const;
	int GetHP() const;
    
	void Move(Direction);
    void ApplyDamage(int);
	void SetEffectType(EffectType);
	EffectType GetEffectType() const { return this->currentEffectType; }
	int GetSpeed() const { return this->speed; }
	void SetSpeed(int);

    
private:
    
    const int MAX_APPLIED_EFFECT = 3;
    
	int speed;
    int healthPoints;
    CritterState state;
	EffectType currentEffectType;
    
};

#endif	/* CRITTER_H */

