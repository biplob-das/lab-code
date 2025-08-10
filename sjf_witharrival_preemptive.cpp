#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, p[30], at[30], bt[30], rt[30], ct[30], tat[30], wt[30];
    int t_tat = 0, t_wt = 0, completed = 0, time = 0;
    float a_tat, a_wt;
    bool done[30] = {false};

    fstream fin("input.txt");
    if (!fin)
    {
        cout << "file not found" << endl;
        return 0;
    }
    else
    {
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            fin >> at[i] >> bt[i];
            p[i] = i + 1;
            rt[i] = bt[i]; // remaining time
        }

        cout << "\nGantt chart:\n";

        while (completed < n)
        {
            int idx = -1, min_rt = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                if (!done[i] && at[i] <= time && rt[i] < min_rt && rt[i] > 0)
                {
                    min_rt = rt[i];
                    idx = i;
                }
            }

            if (idx != -1)
            {
                cout << "p" << p[idx];
                if (completed + time != n) cout << "->";

                rt[idx]--;
                time++;

                if (rt[idx] == 0)
                {
                    done[idx] = true;
                    completed++;
                    ct[idx] = time;
                    tat[idx] = ct[idx] - at[idx];
                    wt[idx] = tat[idx] - bt[idx];
                    t_tat += tat[idx];
                    t_wt += wt[idx];
                }
            }
            else
            {
                cout << "idle";
                time++;
                if (completed + time != n) cout << "->";
            }
        }

        cout << "\n\nProcess\tarrival\tbrust\tcompletion\tturnaround\twating\n";
        for (int i = 0; i < n; i++)
        {
            cout << "p" << p[i] << "\t" << at[i] << "\t" << bt[i]
                 << "\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
        }

        a_tat = (float)t_tat / n;
        a_wt = (float)t_wt / n;
        cout << "\n average weating time:" << a_wt << endl;
        cout << "\n average tnt time:" << a_tat << endl;
    }
    cout << endl;
    return 0;
}
