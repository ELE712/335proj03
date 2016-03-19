/******************************************************
 ** FILE: Group.h
 **
 ** ABSTRACT:
 ** Group class, group name and employees as members
 **
 **
 ** AUTHOR: Ezekiel Zandbergen, Cynthia Obia
 **
 ** CREATION DATE: 3-14-15
 **
 *******************************************************/
#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <string>
#include "Unit.h"


class Group: public Unit{
protected:
    string m_name;
    vector<Unit*> m_members;
public:
    Group(){
        m_name = "";
    }
    Group(const string &name){
        m_name = name;
    }
    virtual ~Group(){}
    Group(const Group &group){
        m_name = group.m_name;
        m_members = group.m_members;
    }
    Group& operator=(Group group){
        swap(m_name, group.m_name);
        swap(m_members, group.m_members);
        return *this;
    }
    //get and sets
    string getName() const{
        return m_name;
    }
    vector<Unit*> getMembers() const{
        return m_members;
    }
    void setName(const string &name){
        m_name = name;
    }
    void setMembers(vector<Unit*> members){
        m_members = members;
    }
    void addGroupMember(Unit* mem){
        m_members.push_back(mem);
    }
    virtual void Accept(Visitor* v){
        v->VisitGroup(this);
    }
};

#endif
