// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.
#ifndef OBJECT_CPP
#define OBJECT_CPP
#include "Object.h"
#include "Universe.h"
#include "Visitor.h"

void Object::accept(Visitor& visitor)
{
    visitor.visit(*this);
}

Object* Object::clone() const
{
    return new Object(name, mass, position, velocity);
}

double Object::getMass() const noexcept
{
    return mass;
}

std::string Object::getName() const noexcept
{
    return name;
}

vector2 Object::getPosition() const noexcept
{
    return position;
}

vector2 Object::getVelocity() const noexcept
{
    return velocity;
}

vector2 Object::getForce(const Object& rhs) const noexcept
{
    Vector<2> direction = position - rhs.position;
    double distance = direction.norm();
    double force = (Universe::G * mass * rhs.mass) / (distance * distance);
    return force * direction.normalize();
}

void Object::setPosition(const vector2& pos)
{
    position = pos;
}

void Object::setVelocity(const vector2& vel)
{
    velocity = vel;
}

bool Object::operator==(const Object& rhs) const
{
    if (position == rhs.position && velocity == rhs.velocity && mass == rhs.mass) {
        return true;
    }
    return false;
}

bool Object::operator!=(const Object& rhs) const
{
    return !(*this == rhs);
}

Object::Object(const std::string& name, double mass, const vector2& pos, const vector2& vel)
    : name(name)
    , mass(mass)
    , position(pos)
    , velocity(vel)
{
}

#endif
