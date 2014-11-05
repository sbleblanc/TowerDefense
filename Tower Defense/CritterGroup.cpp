/* 
 * File:   CritterGroup.cpp
 * Author: samu_b
 * 
 * Created on October 8, 2014, 6:55 PM
 */

#include "CritterGroup.h"

CritterGroup::CritterGroup() {
    this->critters = new Critter*[10];
}

CritterGroup::CritterGroup(int numMaxCritters) : maxNumOfCritters(numMaxCritters) {
    this->critters = new Critter*[numMaxCritters];
}

CritterGroup::CritterGroup(const CritterGroup& orig) {
	this->critters = new Critter*[orig.maxNumOfCritters];
	for (int i = 0; i < orig.maxNumOfCritters; i++){
		this->critters[i] = orig.critters[i];
	}
}

CritterGroup::~CritterGroup() {    
    delete[] this->critters;
}

int CritterGroup::GetMaxNumOfCritters() const {
    return maxNumOfCritters;
}

void CritterGroup::SetCritters(Critter** critters) {
    this->critters = critters;
}

Critter** CritterGroup::GetCritters() const {
    return critters;
}

//void CritterGroup::SetCritters(std::vector<Critter> critters) {
//    this->critters = critters;
//}

//std::vector<Critter> CritterGroup::GetCritters() const {
//    return critters;
//}
//
//bool CritterGroup::Contains(Critter* ref) const {
////    for (std::vector<Critter>::iterator<Critter> it = this->critters.begin() ; it != this->critters.end(); it++){
////        if (it == ref){
////            return true;
////        }
////    }
//    return false;
//}

