#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p[30], at[30], bt[30], ct[30], tat[30], wt[30];
    int completed[30] = {0}, t_wt = 0, t_tat = 0;
    float a_wt, a_tat;

    fstream fin("input.txt");
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> at[i] >> bt[i];
        p[i] = i + 1;
    }

    int time = 0, done = 0;
    cout << "\nGantt Chart:\n";

    while (done < n) {
        int idx = -1, min_bt = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++;  // CPU is idle
            continue;
        }

        // Schedule the selected process
        ct[idx] = time + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        t_tat += tat[idx];
        t_wt += wt[idx];
        completed[idx] = 1;
        time = ct[idx];
        done++;

        // Print for Gantt chart
        cout << "P" << p[idx];
        if (done < n) cout << " -> ";
    }

    cout << "\n\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i]
             << "\t\t" << tat[i] << "\t\t" << wt[i] << "\n";
    }

    a_wt = (float)t_wt / n;
    a_tat = (float)t_tat / n;
    cout << "\nAverage Waiting Time: " << a_wt << "\n";
    cout << "Average TurnAround Time: " << a_tat << "\n";

    return 0;
}
