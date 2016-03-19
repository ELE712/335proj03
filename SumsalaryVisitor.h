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
#ifndef SUMSALARYVISITOR_H
#define SUMSALARYVISITOR_H
#include "Visitor.h"
#include "Department.h"
#include "Group.h"
#include "Manager.h"
#include "Employee.h"

class SumsalaryVisitor: public Visitor{
protected:
    unsigned int v_salary;
public:
    SumsalaryVisitor(){
        v_salary = 0;
    }
    virtual ~SumsalaryVisitor(){}
    virtual void VisitDepartment(Department* d){
        for (int i=0; i<d->getSubDepartments().size(); i++){
            d->getSubDepartments()[i]->Accept(this);
        }
    }
    virtual void VisitGroup(Group* g){
        for (int i=0; i<g->getMembers().size(); i++){
            g->getMembers()[i]->Accept(this);
        }
    }
    virtual void VisitManager(Manager* m){
        v_salary += m->getSal();
    }
    virtual void VisitEmployee(Employee* e){
        v_salary += e->getSal();
    }
    unsigned int getTotalSalary(){
        return v_salary;
    }
    void restTotalSalary(){
        v_salary = 0;
    }
};

#endif
