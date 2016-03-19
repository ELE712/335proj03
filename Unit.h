/******************************************************
 ** FILE: Unit.h
 **
 ** ABSTRACT:
 ** Unit abstract class for employee/manager, group, and department
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Cynthia Obia
 **
 ** CREATION DATE: 3-14-16
 **
 *******************************************************/
#ifndef UNIT_H
#define UNIT_H

class Unit{
public:
    virtual void Accept(Visitor* v)=0;
};

#endif /* UNIT_H */

