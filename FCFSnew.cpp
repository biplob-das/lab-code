#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, p[30], at[30],bt[30],ct[30],tat[30],wt[30];
    int t_wt=0, t_tat=0;
    float a_wt,a_tat;

    fstream fin("input.txt");
    fin>>n;
    for(int i=0; i<n; i++){
        fin>>at[i]>>bt[i];
        p[i] = i+1;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(at[j] <at[i] || (at[i] == at[j] && p[j] < p[i])){
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(i == 0){
            ct[i] = max(0, at[i]) + bt[i];
        }
        else{
            ct[i] = max(ct[i-1], at[i]) + bt[i];

        }

        tat[i] = ct[i] -at[i];
        wt[i]=tat[i]-bt[i];
        t_wt = t_wt +wt[i];
        t_tat =t_tat +tat[i];
    }
    cout<<"Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for(int i=0; i<n; i++){
        cout<<"P"<<p[i]<< "\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<"\n";
    }
    a_wt = (float) t_wt/n;
    a_tat = (float) t_tat/n;
    cout<<"\nAverage Waiting Time: "<<a_wt<<"\n";
    cout<<"Average TurnAround Time: "<<a_tat<<"\n";

    cout<<"\nGantt Chart:\n";
    for(int i=0; i<n; i++){
        cout<<"P"<<p[i];
        if(i <n-1){
            cout<<" -> ";
        }
    }
    cout<<endl;
    return 0;
}