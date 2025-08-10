#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pr[30],p[30],at[30],bt[30],ct[30],tat[30],wt[30],t_tat=0,t_wt=0;
    float a_tat,a_wt;
    fstream fin("input.txt");
    if(!fin)
    {cout<<"file not found"<< endl;
    return 0;}
    else
    {
        fin>>n;
        for(int i=0;i<n;i++)
        {
            fin>>pr[i]>>at[i]>>bt[i];
            p[i]=i+1;
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(pr[j]<pr[i] || (pr[j]==pr[i]&& at[j]<at[i]))
                {   swap(pr[i],pr[j]);
                    swap(at[i],at[j]);
                    swap(bt[i],bt[j]);
                    swap(p[i],p[j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ct[i]=max(0,at[i]+bt[i]);
            }
            else{
                ct[i]=max(ct[i-1],at[i]+bt[i]);
            }
            tat[i]=ct[i]-at[i];
            wt[i]= tat[i]-bt[i];
            t_tat +=tat[i];
            t_wt +=wt[i];

        }
        cout<<"Process\tpriority\tarrival\tbrust\tcompletion\tturnaround\twating\n";
        for(int i=0;i<n;i++)
        {
            cout<<"p"<<p[i]<<"\t"<<pr[i]<<"\t"<<at[i] <<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
        }
        a_tat=(float)t_tat/n;
         a_wt=(float)t_wt/n;
         cout<<"\n average weating time:"<<a_wt<<endl;
          cout<<"\n average tnt time:"<<a_tat<<endl;
          cout<<"\nGantt chart:"<<endl;
          for(int i=0;i<n;i++)
          {
            cout<<"p"<<p[i];
            if(i<n-1)
            {
                cout<<"->";
            }
          }

    }
    cout<<endl;
    return 0;
}