
/*
In the computer lab, there are N tables numbered 0 to N-1. In each of the tables, either a student is seated or it is empty. The students will use computers to work on their assignments. A student can use a computer if it is placed to its immediate left or to its immediate right.
5
6 > 3.
Find the minimum number of computers that need to be allotted to the lab to serve all students. Determine if it is Impossible for all students to work on assignments.
*/

#include <bits/stdc++.h>
using namespace std;
/*
To solve the problem of determining the minimum number of computers needed in a lab with 
 tables, where each table can either be occupied by a student or be empty, we need to consider the seating arrangement of the students. ### Problem Breakdown 1. **Understanding the Setup**: - Each table is numbered from 
 to 
. - A student seated at table 
 can use a computer at table 
 (left) or table 
 (right). - If a student is at table 
, they can only use a computer at table 
. - If a student is at table 
, they can only use a computer at table 
. 2. **Objective**: - We need to find the minimum number of computers required such that every student can work on their assignments. - We also need to determine if it is impossible for all students to work. ### Strategy To minimize the number of computers, we can use a greedy approach: - **Placing Computers**: - Start from the leftmost table and move to the right. - If a student is seated at table 
: - If there is no computer at table 
 and 
, place a computer at table 
 (if 
 is not the last table). - If there is a student at table 
 and a computer at table 
, the student can use that computer. - If there is a student at table 
 and a computer at table 
, the student can use that computer. ### Example Let's consider an example with 
 tables and the following arrangement: - Table occupancy: [1, 0, 1, 0, 1] (1 indicates a student, 0 indicates an empty table) #### Step-by-Step Placement 1. **Table 0**: Student present, place a computer at table 1. 2. **Table 1**: Empty. 3. **Table 2**: Student present, place a computer at table 3. 4. **Table 3**: Empty. 5. **Table 4**: Student present, place a computer at table 3 (already has a computer). #### Result - Computers placed: [0, 1, 0, 1, 0] (computers at tables 1 and 3) - All students can work. ### Conclusion To generalize the solution: 1. Traverse the tables from left to right. 2. For each student, check the adjacent tables for existing computers. 3. Place a computer if necessary, ensuring that the minimum number is used. ### Complexity The time complexity of this approach is 
, where 
 is the number of tables. ### Final Output - If all students can be served, output the minimum number of computers. - If there is a configuration where students cannot be served (e.g., isolated students), output "Impossible". ### Example Output For the arrangement [1, 0, 1, 0, 1], the output would be: - Minimum computers needed: 3 - It is possible for all students to work. If you provide a specific arrangement of students and empty tables, I can calculate the exact number of computers needed and check for impossibility.

*/
int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    for(auto &x : s)
        x = (x == 'S') ? '1' : '0';
    // code based on aboce approach
    int ans = 0;
    vector<int> computers(n, 0);
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            if(i == 0){
                if(computers[i] == 0 && computers[i+1] == 0){
                    computers[i+1] = 1;
                    ans++;
                }
            }
            else if(i == n-1){
                if(computers[i] == 0 && computers[i-1] == 0){
                    computers[i-1] = 1;
                    ans++;
                }
            }
            else{
                if(computers[i] == 0 && computers[i-1] == 0){
                    computers[i-1] = 1;
                    ans++;
                }
                else if(computers[i] == 0 && computers[i+1] == 0){
                    computers[i+1] = 1;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

