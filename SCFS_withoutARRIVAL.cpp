#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p[30], bt[30], ct[30], tat[30], wt[30];
    int t_wt = 0, t_tat = 0;
    float a_wt, a_tat;

    fstream fin("input.txt");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> bt[i];
        p[i] = i + 1;
    }

    // Calculate Completion Time
    ct[0] = bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    // Turnaround Time = Completion Time (since AT = 0)
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i]; // AT = 0
        wt[i] = tat[i] - bt[i];
        t_wt += wt[i];
        t_tat += tat[i];
    }

    cout << "Process\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << bt[i] << "\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << "\n";
    }

    a_wt = (float)t_wt / n;
    a_tat = (float)t_tat / n;

    cout << "\nAverage Waiting Time: " << a_wt << "\n";
    cout << "Average TurnAround Time: " << a_tat << "\n";

    cout << "\nGantt Chart:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i];
        if (i < n - 1) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}
