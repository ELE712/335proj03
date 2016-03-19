/******************************************************
 ** FILE: Manager.h
 **
 ** ABSTRACT:
 ** design and implementation of Manager.
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Matthew Eaton, Cynthia Obia
 **
 ** CREATION DATE: 1-27-16
 **
 *******************************************************/

#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Employee.h"
#include "Visitor.h"
using namespace std;

class Manager: public Employee{
protected:
    unsigned int m_rank;
public:
    Manager():Employee() {
        m_rank = 0;
    }
    Manager(const string &first, const string &last, const unsigned int &sal, const unsigned int &yr, const unsigned int &id, const unsigned int &rank): Employee(first,last,sal,yr, id) {
        m_rank = rank;
    }
    //copy constructor
    Manager(const Manager &man): Employee(man){
        m_rank = man.m_rank;
    }
    
    virtual ~Manager(){
    }
    // = operator
    Manager& operator=(Manager man) {
        Employee::operator=(man);
        swap(m_rank, man.m_rank);
        return *this;
    }
    void setRank(const unsigned int &rank) {
        m_rank = rank;
    }

    unsigned int getRank() const{
        return m_rank;
    }
    virtual void DisplayEmployee() const {
        Employee::DisplayEmployee();
        cout << "; " << m_rank << endl;
    }
        virtual void Accept(Visitor* v){
        v->VisitManager(this);
    }
};

#endif
