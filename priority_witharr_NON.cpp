#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, pr[30], p[30], at[30], bt[30], ct[30], tat[30], wt[30];
    int t_wt = 0, t_tat = 0;
    float a_wt, a_tat;

    fstream fin("input.txt");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> pr[i] >> at[i] >> bt[i];
        p[i] = i + 1; // process ID
    }

    // Sort based on priority, then arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[j] < pr[i] || (pr[i] == pr[j] && at[j] < at[i])) {
                swap(pr[i], pr[j]);
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    // Calculate Completion, Turnaround and Waiting Times
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ct[i] = max(0, at[i]) + bt[i];
        } else {
            ct[i] = max(ct[i - 1], at[i]) + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        t_tat += tat[i];
        t_wt += wt[i];
    }

    // Output Table
    cout << "Process\tPriority\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << pr[i] << "\t\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << "\n";
    }

    a_wt = (float)t_wt / n;
    a_tat = (float)t_tat / n;

    cout << "\nAverage Waiting Time: " << a_wt << "\n";
    cout << "Average TurnAround Time: " << a_tat << "\n";

    // Gantt Chart
    cout << "\nGantt Chart:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i];
        if (i < n - 1) cout << " -> ";
    }
    cout << "\n";

    return 0;
}
