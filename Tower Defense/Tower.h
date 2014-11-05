/* 
 * File:   Tower.h
 * Author: samu_b
 *
 * Created on October 1, 2014, 5:30 PM
 */

#ifndef TOWER_H
#define	TOWER_H

#include "MapEntity.h"
#include "Effect.h"
#include "CritterGroup.h"
#include "BaseModel.h"
#include <string>

class Tower : public MapEntity {
public:
    Tower();
    Tower(int cost, int range, int power, int initialLevelUpCost, int fireRate, int maxNumOfEffects, char dispChar, std::string name);
    Tower(const Tower& orig);
    virtual ~Tower();

    bool CanBuy(int);
    int GetCurrentRefundCost() const;
    bool TryToLevelUp(int);
    
    virtual bool AddEffect(const Effect&);
    virtual bool TryToAttackCritter(CritterGroup&);

	int GetCurrentLevelUpCost() const;
	int GetLevel() const;
	int GetPower() const;
	int GetRange() const;
	int GetCost() const;
	int GetFireRate() const;

	int GetMaxNumOfEffects() const;
	Effect** GetEffects() const;   //This is public and only implemented for the sake of this exercise
	Critter* GetCurrentCritter() const;

	std::string GetName() const { return name; }
	void SetName(std::string);

	

private:

    int cost; //In that case, int is precise enough
    int range;
    int power;
    int level;
    int currentLevelUpCost;
    int currentRefundCost;
    int fireRate;
    int hitChanceCounter;
    int maxNumOfEffects;
	std::string name;
	char initialDisplayChar;

    Effect** effects;
    Critter* currentCritter;

    virtual bool AttackCritter(Critter&);


protected:
    const int MAX_LEVEL = 5; //Does not need to be public
    const float REFUND_RATIO = 0.8;
    const float LEVEL_RATIO = 1.2;
    const int LEVEL_UP_MODIFIER = 1;
    
    bool CanTowerHit();
    
	bool NeedNewTarget() const;
    bool FindFirstCritterInRange(CritterGroup& );
    void ApplyEffectsAndDamage(Critter&);

    
	char GetInitialDisplayChar() const { return this->initialDisplayChar; }
	void SetInitialDisplayChar(char);
    
    
    int GetHitChanceCounter() const;
    void SetCurrentRefundCost(int currentRefundCost);

	void SetCurrentCritter(Critter*);
    
    

};

#endif	/* TOWER_H */

