/******************************************************
 ** FILE: Employee.h
 **
 ** ABSTRACT:
 ** design and implementation of Employee class.
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Matthew Eaton, Cynthia Obia
 **
 ** CREATION DATE: 1-27-16
 **
 *******************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <algorithm>
#include <iostream>
#include "Visitor.h"
#include "Unit.h"
using namespace std;
class Employee: public Unit{
protected:
    string m_firstName;
    string m_lastName;
    unsigned int m_hiringYear;
    unsigned int m_salary;
    unsigned int m_id;
    
public:
    // default constructor
    Employee() {
        m_firstName = "";
        m_lastName = "";
        m_hiringYear = 0;
        m_salary = 0;
        m_id = 0;
    }
    Employee(const string &first, const string &last, const unsigned int &sal, const unsigned int &yr, const unsigned int &id){
        m_firstName = first;
        m_lastName = last;
        m_hiringYear = yr;
        m_salary = sal;
        m_id = id;
    }
    Employee(const Employee &emp) {
        m_firstName = emp.m_firstName;
        m_lastName = emp.m_lastName;
        m_hiringYear = emp.m_hiringYear;
        m_salary = emp.m_salary;
        m_id = emp.m_id;
    }
    virtual ~Employee() {
        m_firstName.~string();
        m_lastName.~string();
    }
    // copy and swap
    Employee& operator=(Employee emp) {
        swap(m_firstName, emp.m_firstName);
        swap(m_lastName, emp.m_lastName);
        swap(m_hiringYear, emp.m_hiringYear);
        swap(m_salary, emp.m_salary);
        swap(m_id, emp.m_id);
        return *this;
    }
    void setFirstName(const string &name) {
        m_firstName = name;
    }
    void setLastName(const string &name) {
        m_lastName = name;
    }
    void setYear(const unsigned int &yr) {
        m_hiringYear = yr;
    }
    void setSal(const unsigned int &sal) {
        m_salary = sal;
    }
    void setID(const unsigned int &id) {
        m_id = id;
    }
    string getFirstName() const{
        return m_firstName;
    }
    string getLastName() const{
        return m_lastName;
    }
    unsigned int getYear() const{
        return m_hiringYear;
    }
    unsigned int getSal() const{
        return m_salary;
    }
    unsigned int getID() const{
        return m_id;
    }
    virtual void DisplayEmployee() const{
        cout << getFirstName() << " " << getLastName() << "; " << getSal() << "; " << getYear() << "; " << getID() << endl;
    }
    virtual void Accept(Visitor* v){
        v->VisitEmployee(this);
    }
};


#endif
