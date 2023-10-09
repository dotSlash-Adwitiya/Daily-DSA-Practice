
// * INTUTION : 
// * First think in minimal case, when we have 2 or 3 discs,
// * how will we transfer them without voilating given conditions ?

//* N-1 Discs will be transferred first then the last disc will be moved to actual desitnation

#include<bits/stdc++.h>
using namespace std;


long long solve(int N, int src, int dest, int helperDisk, long long &cnt) {
    if(N == 1) {
        cout << "move disk " << N << " from rod " << src << " to rod " << dest << endl;
        return cnt+1;
    }

    //* First, move N-1 disks from src to helper, using destination as the helper
    solve(N-1, src, helperDisk, dest, ++cnt);
    cout << "move disk " << N << " from rod " << src << " to rod " << dest << endl;
    

    //* Then, once we reach base case (only 1 disk left)
    //* Use src as helper, move all disks from helper to destination.
    solve(N-1, helperDisk, dest, src, ++cnt);

}

long long toh(int N, int src, int dest, int helperDisk) {
    
    long long cnt = 0;
    return solve(N, src, dest, helperDisk, cnt);
}