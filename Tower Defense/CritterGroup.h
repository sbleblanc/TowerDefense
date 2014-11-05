/* 
 * File:   CritterGroup.h
 * Author: samu_b
 *
 * Created on October 8, 2014, 6:55 PM
 */

#ifndef CRITTERGROUP_H
#define	CRITTERGROUP_H

#include<vector>

#include "Critter.h"

class CritterGroup {
public:
    CritterGroup();
    CritterGroup(int);
    CritterGroup(const CritterGroup& orig);
    virtual ~CritterGroup();
    int GetMaxNumOfCritters() const;
    void SetCritters(Critter** critters);
    Critter** GetCritters() const;
//    void SetCritters(std::vector<Critter> critters);
//    std::vector<Critter> GetCritters() const;
//    bool Contains(Critter*) const;
    
private:

//    std::vector<Critter> critters2;
    
    Critter** critters;
    int maxNumOfCritters;
    
};

#endif	/* CRITTERGROUP_H */

