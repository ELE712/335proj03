/******************************************************
 ** FILE: SumsalaryVisitor.h
 **
 ** ABSTRACT:
 ** Visitor class to add all salaries
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Cynthia Obia
 **
 ** CREATION DATE: 3-14-15
 **
 *******************************************************/
#ifndef PRINTVISITOR_H
#define PRINTVISITOR_H
#include "Visitor.h"
#include "Department.h"
#include "Group.h"
#include "Manager.h"
#include "Employee.h"
using namespace std;
class PrintVisitor: public Visitor{
    virtual void VisitDepartment(Department* d){
        cout << d->getName() << endl;
        for (int i=0; i<d->getSubDepartments().size(); i++){
            d->getSubDepartments()[i]->Accept(this);
        }
    }
    virtual void VisitGroup(Group* g){
        cout << g->getName() << endl;
        for (int i=0; i<g->getMembers().size(); i++){
            g->getMembers()[i]->Accept(this);
        }
    }
    virtual void VisitManager(Manager* m){
        cout << "       " << m->getFirstName() << " " << m->getLastName() << "; " << m->getSal() << "; " << m->getYear() << "; " << m->getID() << "; " << m->getRank() << endl;
    }
    virtual void VisitEmployee(Employee* e){
    cout << "           " << e->getFirstName() << " " << e->getLastName() << "; " << e->getSal() << "; " << e->getYear() << "; " << e->getID() << endl;
    }
};

#endif
