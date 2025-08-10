#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, p[30], bt[30], rt[30], ct[30], tat[30], wt[30];
    int tq, t_tat = 0, t_wt = 0, time = 0;
    float a_tat, a_wt;

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
            fin >> bt[i];
            p[i] = i + 1;
            rt[i] = bt[i];
        }
        fin >> tq; // time quantum

        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);

        cout << "\nGantt chart:\n";

        while (!q.empty())
        {
            int idx = q.front();
            q.pop();

            cout << "p" << p[idx];
            if (!q.empty() || rt[idx] > tq) cout << "->";

            if (rt[idx] <= tq)
            {
                time += rt[idx];
                rt[idx] = 0;
                ct[idx] = time;
                tat[idx] = ct[idx];
                wt[idx] = tat[idx] - bt[idx];
                t_tat += tat[idx];
                t_wt += wt[idx];
            }
            else
            {
                time += tq;
                rt[idx] -= tq;
                q.push(idx);
            }
        }

        cout << "\n\nProcess\tbrust\tcompletion\tturnaround\twating\n";
        for (int i = 0; i < n; i++)
        {
            cout << "p" << p[i] << "\t" << bt[i] << "\t" << ct[i]
                 << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
        }

        a_tat = (float)t_tat / n;
        a_wt = (float)t_wt / n;
        cout << "\n average weating time:" << a_wt << endl;
        cout << "\n average tnt time:" << a_tat << endl;
    }
    cout << endl;
    return 0;
}
