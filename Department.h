/******************************************************
 ** FILE: Department.h
 **
 ** ABSTRACT:
 ** Department class, includes department name and sub-departments
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Cynthia Obia
 **
 ** CREATION DATE: 3-14-16
 **
 *******************************************************/

#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <vector>
#include <string>
#include <algorithm>
#include "Unit.h"
#include "Visitor.h"
using namespace std;

class Department: public Unit{
protected:
    string m_name;
    vector<Unit*> m_sub; //subdepartments
public:
    Department(){
        m_name = "";
    }
    Department(const string &name){
        //Unit(); //maybe need this
        m_name = name;
    }
    Department(const Department &dep){
        m_name = dep.m_name;
        m_sub = dep.m_sub;
    }
    Department& operator=(Department dep){
        swap(m_name, dep.m_name);
        swap(m_sub, dep.m_sub);
        return *this;
    }
    virtual ~Department(){}
    
    //gets and sets
    string getName() const{
        return m_name;
    }
    vector<Unit*> getSubDepartments() const{
        return m_sub;
    }
    void setName(const string &name){
        m_name = name;
    }
    void setSubDepartments(vector<Unit*> sub){
        m_sub = sub;
    }
    void addDepartmentMember(Unit* sub){
        m_sub.push_back(sub);
    }
    virtual void Accept(Visitor* v){
        v->VisitDepartment(this);
    }
};

#endif
