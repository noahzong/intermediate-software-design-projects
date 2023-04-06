// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.
#ifndef OBJECTFACTORY_CPP
#define OBJECTFACTORY_CPP
#include "ObjectFactory.h"
#include "Object.h"
#include "Universe.h"

Object* ObjectFactory::makeObject(
    const std::string& name, double mass, const vector2& pos, const vector2& vel)
{
    Object* tmp = new Object(name, mass, pos, vel);
    Universe::inst->addObject(tmp);
    return tmp;
}

#endif
