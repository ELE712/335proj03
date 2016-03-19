/******************************************************
 ** FILE: Visitor.h
 **
 ** ABSTRACT:
 ** Abstract visitor class
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Cynthia Obia
 **
 ** CREATION DATE: 3-14-15
 **
 *******************************************************/
#ifndef VISITOR_H
#define VISITOR_H

class Group;
class Department;
class Employee;
class Manager;

class Visitor{
public:
    virtual void VisitGroup(Group*)=0;
    virtual void VisitDepartment(Department*)=0;
    virtual void VisitEmployee(Employee*)=0;
    virtual void VisitManager(Manager*)=0;
};

#endif

