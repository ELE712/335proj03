#include "Employee.h"
#include "Manager.h"
#include "PrintVisitor.h"
#include "Group.h"
#include "Department.h"
#include "SumsalaryVisitor.h"

int main(int argc, char *argv[]) {
    Employee JohnSmith1("John","Smith1",10000,2011, 1);
    Employee JohnSmith2("John","Smith2",20000,2012,2);
    Employee JohnSmith3("John","Smith3",30000, 2013,3);
    Manager TomCruiseManager("Tom","Cruise",40000, 2000, 5,1);

    Employee JohnDoe1("John", "Doe1", 15000, 2010,6);
    Employee JohnDoe2("John", "Doe2", 25000, 2011,7);
    Employee JohnDoe3("John", "Doe3", 35000, 2012,8);
    Manager AliceCooperManager("Alice","Cooper",45000, 2000, 9,2);



    cout<<"===================================================== Test Visitor Pattern"<<endl;
    Group group1("Group1");
    group1.addGroupMember(&TomCruiseManager);
    group1.addGroupMember(&JohnSmith1);
    group1.addGroupMember(&JohnSmith2);
    group1.addGroupMember(&JohnSmith3);

    Group group2("Group2");
    group2.addGroupMember(&AliceCooperManager);
    group2.addGroupMember(&JohnDoe1);
    group2.addGroupMember(&JohnDoe2);
    group2.addGroupMember(&JohnDoe3);

    Employee SingleMan("Single","Man",50000,2009,10);

    Department salesDept("Sales");
    salesDept.addDepartmentMember(&group1);
    salesDept.addDepartmentMember(&group2);
    salesDept.addDepartmentMember(&SingleMan);

    PrintVisitor pv;
    salesDept.Accept(&pv);

    SumsalaryVisitor sv;
    salesDept.Accept(&sv);
    cout<<"Total Salary = "<<sv.getTotalSalary()<<endl;
    sv.restTotalSalary();
    }
