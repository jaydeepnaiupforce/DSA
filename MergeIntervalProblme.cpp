#include<bits/stdc++.h>
using namespace std; 

struct Interval {
    int start;
    int end;
    Interval(int s,int e):start(s),end(e){}
    Interval():start(0),end(0){}
};

bool doesOverlap(Interval a,Interval b){
    return min(a.end,b.end) >= max(a.start,b.start);
}

vector<Interval> InsertNewInterval(vector<Interval> intervals, Interval newInterval){
    int n = intervals.size();
    vector<Interval> ResultInterval;
    if(n == 0){
        ResultInterval.push_back(newInterval);
        return ResultInterval;
    }
    
    if(newInterval.end < intervals[0].start || newInterval.start > intervals[n-1].end){
        if(newInterval.end < intervals[0].start){
            ResultInterval.push_back(newInterval);
        }
        for (int i = 0; i < n;  i++) {
            ResultInterval.push_back(intervals[i]);
        }
        if(newInterval.start > intervals[n-1].end){
            ResultInterval.push_back(newInterval);
        }
    }
    
    if(newInterval.start <= intervals[0].start && newInterval.end >= intervals[n-1].end){
        ResultInterval.push_back(newInterval);
    }
    
    bool overlap = true;
    for (int i = 0; i < n; i++) {
        overlap = doesOverlap(intervals[i],newInterval);
        if(!overlap){
            ResultInterval.push_back(intervals[i]);
            if(i<n && intervals[i].end < newInterval.start && intervals[i+1].start > newInterval.end){
                ResultInterval.push_back(newInterval);
            }
            continue;
        }
        
        Interval temp;
        temp.start = min(newInterval.start,intervals[i].start);
        while(i<n && overlap){
            temp.end = max(newInterval.end,intervals[i].end);
            
            if(i==n-1){
                overlap = true;
            }
            else overlap = doesOverlap(intervals[i+1],newInterval);
            i++;
        };
        ResultInterval.push_back(temp);
        i--;
    }
    
    return ResultInterval;
};

int main(){
    vector<Interval> Intervals;
    Interval newInterval;
    vector<Interval> resultInterval;
    
    newInterval.start = 1;
    newInterval.end = 2;
    Intervals.push_back(newInterval);
    newInterval.start = 3;
    newInterval.end = 5;
    Intervals.push_back(newInterval);
    newInterval.start = 6;
    newInterval.end = 7;
    Intervals.push_back(newInterval);
    newInterval.start = 8;
    newInterval.end = 10;
    Intervals.push_back(newInterval);
    newInterval.start = 14;
    newInterval.end = 16;
    Intervals.push_back(newInterval);
    newInterval.start = 4;
    newInterval.end = 9;
    
    int n = Intervals.size();
    
    for (int i = 0; i < n; i++) {
        cout<<Intervals[i].start<<"  ";
        cout<<Intervals[i].end<<endl;
    }
    cout<<"Merged Intevals"<<endl;
    resultInterval = InsertNewInterval(Intervals,newInterval);
    for (int i = 0; i < resultInterval.size(); i++) {
        cout<<resultInterval[i].start<<"  ";
        cout<<resultInterval[i].end<<endl;
    }
    std::cout << "hare Krishna" << std::endl;
}