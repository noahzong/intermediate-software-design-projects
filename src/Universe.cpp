// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.
#ifndef UNIVERSE_CPP
#define UNIVERSE_CPP
#include "Universe.h"
#include "Object.h"

Universe* Universe::instance()
{
    if (inst == nullptr) {
        inst = new Universe();
    }
    return inst;
}

Universe::~Universe()
{
    release(objects);
    inst = nullptr;
}

Universe::iterator Universe::begin()
{
    return objects.begin();
}

Universe::iterator Universe::end()
{
    return objects.end();
}

Universe::const_iterator Universe::begin() const
{
    return objects.begin();
}

Universe::const_iterator Universe::end() const
{
    return objects.end();
}

std::vector<Object*> Universe::getSnapshot() const
{
    std::vector<Object*> tmp;
    std::for_each(begin(), end(), [&tmp](Object* i) { tmp.push_back(i->clone()); });
    return tmp;
}

void Universe::stepSimulation(const double& timeSec)
{
    auto tmp = getSnapshot();
    std::vector<Vector<2>> objForces;
    objForces.resize(objects.size());

    for (uint32_t i = 1; i < objects.size(); ++i) {
        for (uint32_t j = 0; j < objects.size(); ++j) {
            if (i != j) {
                objForces[i] += tmp[j]->getForce(*objects[i]);
            }
        }
    }

    std::for_each(tmp.begin(), tmp.end(),
        [&timeSec](Object* i) { i->setPosition(i->getPosition() + timeSec * i->getVelocity()); });

    for (uint32_t i = 1; i < objects.size(); ++i) {
        tmp[i]->setVelocity(tmp[i]->getVelocity() + (objForces[i] / tmp[i]->getMass()) * timeSec);
    }

    swap(tmp);
}

void Universe::swap(std::vector<Object*>& snapshot)
{
    release(objects);
    std::swap(objects, snapshot);
}

Object* Universe::addObject(Object* ptr)
{
    objects.push_back(ptr);
    return ptr;
}

void Universe::release(std::vector<Object*>& objects)
{
    std::for_each(objects.begin(), objects.end(), [](auto i) { delete i; });
    objects.clear();
}

Universe* Universe::inst = nullptr;

#endif