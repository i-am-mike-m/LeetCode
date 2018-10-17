// Needs redoing. Map really isn't necessary.

/*
// Employee info
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
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> idValue;
        int sum = 0;
        
        for (auto each : employees) {
            idValue.insert({each->id, each->importance});            
        }
        
        Employee* input;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) input = employees[i];
        }
        sum += input->importance;
        
        for (auto each : input->subordinates) {
            sum += getImportance(employees, each);
        }
        
        return sum;
    }
};