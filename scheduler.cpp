/* 
    Name: Avishrant Sharma
    Roll No: 195008
    CSE 2nd year
*/

#include <iostream>
#include <vector>
using namespace std; 

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 

// Function to sort the processes based on Arrival Time
void sort_arrival(int n, vector<int> &arr, vector<int> &burst){
    for (int i = 0; i < n-1; i++)      
    {  
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1]){
                swap(&burst[j], &burst[j+1]);
                cout << burst[j] << burst[j+1] << endl;
                swap(&arr[j], &arr[j+1]);
            } 
        }
    }
}

// Function to calculate Waiting Time 
void waitTime(int n, vector<int> burst, int tat[], int wt[]) 
{ 
    for (int  i = 0; i < n ; i++) 
        wt[i] =  tat[i] - burst[i]; 
}

// Function to calculate Turn Around Time 
void turnTime(int n, vector<int> arr, vector<int> burst, int tat[]) 
{ 
    for (int  i = 1; i < n ; i++)
        tat[i] = tat[i-1] + arr[i-1] + burst[i] - arr[i];
} 

// First Come First Serve Scheduling 
void FCFS(int n, vector<int> arr, vector<int> burst) 
{ 
    sort_arrival(n, arr, burst);
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int thresh = arr[0];
    if(thresh != 0){
        for(int i = 0; i < n; i++)
            arr[i] -= thresh;
    }
    turnTime(n, arr, burst, tat); 
    waitTime(n, burst, tat, wt); 
  
    cout << "\nProcesses  "<< "Arrival Time " <<" Burst time  " << " Waiting time  " << " Turn around time\n"; 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << i+1 << "\t\t" << arr[i]+thresh << "\t    " << burst[i] <<"\t\t  " << wt[i] << "\t\t " << tat[i] << endl; 
    } 
    cout << "\nAverage Waiting Time = " << (float)total_wt / (float)n; 
    cout << "\nAverage Turn Around Time = " << (float)total_tat / (float)n << "\n"; 
} 

// Shortest Job First Scheduling
void SJF(int n, vector<int> arr, vector<int> burst){
    sort_arrival(n, arr, burst);
    int wt[n], tat[n], p[n], total_wt = 0, total_tat = 0; 
    int thresh = arr[0];
    if(thresh != 0){
        for(int i = 0; i < n; i++)
            arr[i] -= thresh;
    }
    wt[0] = 0;
    for(int i = 0; i < n; i++)
        p[i] = i;

    tat[0] = burst[0];
    for(int i = 1; i < n; i++){
        int s_burst = burst[i];
        int s_process = i;
        for(int j = i; j < n; j++){
            if (burst[j] < s_burst && arr[j] <= tat[i-1] + arr[i-1]){
                s_process = j;
                s_burst = burst[j];
            }
        }
        if(i != s_process){
            swap(&burst[i], &burst[s_process]);
            swap(&arr[i], &arr[s_process]);
            swap(&p[i], &p[s_process]);
        }
        tat[i] = tat[i-1] + s_burst + arr[i-1] - arr[i];
        wt[i] = tat[i] - s_burst;
    }
    cout << "\nProcesses  "<< "Arrival Time " <<" Burst time  "<< " Waiting time  " << " Turn Around time\n"; 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << p[i] << "\t\t" << arr[i] + thresh << "\t    " << burst[i] <<"\t\t  " << wt[i] << "\t\t " << tat[i] << endl; 
    } 
    cout << "\nAverage Waiting Time = " << (float)total_wt / (float)n; 
    cout << "\nAverage Turn Around Time = " << (float)total_tat / (float)n << "\n";
}

int main() 
{ 
    int num, choice;
    vector<int> arr_time;
    vector<int> burst_time;
    cout << "Number of Processes: ";
    cin >> num;
    cout << "Enter the details in the following order (Arrival Time, Burst Time)" << endl;
    
    for(int i = 0; i < num; i++){
        cout << "Enter details for Process " << i+1 << " : ";
        int a, b;
        cin >> a >> b;
        arr_time.push_back(a);
        burst_time.push_back(b);
    }

    cout << "\nEnter the index of Scheduling Algorithm : " << endl;
    cout << "1. FCFS\n2. SJF" << endl;
    cout << "\nYour Choice : ";
    cin >> choice;
    if (choice == 1)
        FCFS(num, arr_time, burst_time);
    else if (choice == 2)
        SJF(num, arr_time, burst_time);
    else
        cout << "Invalid Option. Exiting" << endl;

    return 0; 
} 