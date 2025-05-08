#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int na, nb, numQueries;
    cin >> na >> nb >> numQueries;

    vector<int> arrayA(na), arrayB(nb);
    
    for (int i = 0; i < na; ++i) {
        cin >> arrayA[i];
    }
    
    for (int i = 0; i < nb; ++i) {
        cin >> arrayB[i];
    }

    vector<int> uniqueB;
    int idxB = 0;
    
    while (idxB < nb) {
        if (uniqueB.empty() || uniqueB.back() != arrayB[idxB]) {
            uniqueB.push_back(arrayB[idxB]);
        }
        ++idxB;
    }

    map<int, int> countA;
    int idxA = 0, sizeB = uniqueB.size();
    
    int i = 0;
    while (i < sizeB) {
        if (idxA < na && uniqueB[i] == arrayA[idxA]) {
            countA[arrayA[idxA]]++;
            idxA++;
        } else {
            if (!countA.count(uniqueB[i])) {
                cout << "TIDAK\n";
                return;
            }
        }
        ++i;
    }

    cout << "YA\n";
}
int main(){
	int t; cin >> t;
	while(t--)
		test_case();

}