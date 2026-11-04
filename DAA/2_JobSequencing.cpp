#include<bits/stdc++.h>
using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b){
    return a.profit>b.profit;
}

void jobSequencing(Job jobs[], int n){
    sort(jobs, jobs+n, compare);
    int maxdeadline = 0;

    for(int i = 0; i<n; i++){
        if(jobs[i].deadline > maxdeadline){
            maxdeadline = jobs[i].deadline;
        } 
    }

    bool slots[maxdeadline];

    for(int i = 0; i<maxdeadline; i++){
        slots[i] = false;
    }

    int totalProfit = 0;
    int steps = 0;

    cout<<"Job sequence: ";

    for(int i = 0; i<n; i++){
        steps++;

        for(int j = jobs[i].deadline - 1; j>=0 ; j--){
            steps++;

            if(!slots[j]){
                slots[j] = true;
                cout<<jobs[i].id<<" ";
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout<<"\nTotal Profit: "<< totalProfit << endl;
    cout<<"Step count: " << steps << endl;

}

int main(){
    int n ;

    cout<<"Enter number of jobs: ";
    cin>>n;

    Job jobs[n];

    for(int i = 0; i< n; i++){
        cout<<"Enter job id, deadline and profit: ";
        cin>>jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs, n);

    return 0;
}