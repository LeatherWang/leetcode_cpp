
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory.h>
#include <climits>
#include <sstream>
#include <set>

using namespace std;
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

int dfs(vector<Employee*> &employees, vector<int> &mapList, int id)
{
    int realID = mapList[id];
    int impSum=0;
    cout<<"realID: "<<realID<<"size: "<<employees[realID]->subordinates.size()<<endl;
    for(int i=0 ;i < employees[realID]->subordinates.size(); i++)
    {
        impSum += dfs(employees, mapList, employees[realID]->subordinates[i]);
    }
    return employees[realID]->importance+impSum;
}
int getImportance(vector<Employee*> employees, int id)
{
    if(employees.empty()) return 0;
    vector<int> mapList(employees.size(),0);
    for(int i=0; i<employees.size(); i++)
        mapList[employees[i]->id] = i;
    return dfs(employees, mapList, id);
}
//[[1,77,[2,6]],[2,53,[3,5]],[3,70,[4]],[4,51,[]],[5,60,[]],[6,83,[7]],[7,63,[8,10]],[8,89,[9]],[9,53,[]],[10,62,[]]]

int main()
{
    Employee *a1 = new Employee();
    a1->id = 1; a1->importance = 77; a1->subordinates = vector<int>{2,6};
    Employee *a2 = new Employee();
    a2->id = 2; a2->importance = 53; a2->subordinates = vector<int>{3,5};
    Employee *a9 = new Employee();
    a9->id = 9; a9->importance = 53; //a9->subordinates = vector<int>{2,6};
    Employee *a10 = new Employee();
    a10->id = 10; a10->importance = 62; //a2->subordinates = vector<int>{3,5};
    vector<Employee*> employees;
    employees.push_back(a1);
    employees.push_back(a2);
    employees.push_back(a9);
    employees.push_back(a10);

    cout<<"res: "<<getImportance(employees, 9)<<endl;
    return 0;
}









