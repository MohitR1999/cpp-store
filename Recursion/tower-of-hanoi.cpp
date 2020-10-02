#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef vector<ull> vull;

void towerOfHanoi(int disks, string source, string help, string destination) {
    static int count = 0;
    if(disks == 1) {
        cout << "Moved disk "<<1<<" from "<<source<<" to "<<destination<<endl;
        count++;
        cout<<count<<" steps done\n";
    }
    else {
        towerOfHanoi(disks - 1, source, destination, help);
        cout <<"Moved disk "<< disks << " from "<<source<<" to "<<destination<<endl;
        count++;
        cout<<count<<" steps done\n";
        towerOfHanoi(disks - 1, help, source, destination);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    towerOfHanoi(5, "source", "helper", "destination");
    return 0;
}