// Name:Noah Ong
// VUnet ID: ongnz
// Email: noah.z.ong@vanderbilt.edu
// Honor Code: I attest that I understand the honor code for this class and have neither given
// nor received any unauthorized aid on this assignment.
#ifndef VISITOR_CPP
#define VISITOR_CPP

#include "Visitor.h"
#include "Object.h"

PrintVisitor::PrintVisitor(std::ostream& os)
    : os(os)
{
}

void PrintVisitor::visit(Object& object)
{
    os << object.getName();
}

#endif
