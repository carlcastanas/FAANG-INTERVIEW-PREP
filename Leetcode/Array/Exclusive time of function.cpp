/*  The intution for this problem is similar to checking valid parenthesis using stack, i.e push() when get an opening bracket else pop() from the stack.

    Before starting off with the solution, let's discuss a simple idea. Suppose we have three functions func1, func2, func3 such that func1 calls func2 and then func2 calls func3. 
    In this case, func3 starts at the end and ends first, func2 starts at 2nd position and ends at the 2nd last step. Similarly, func1 starts first and ends at the last position. 
    Thus, we can conclude that the function which is entered at the end finishes first and the one which is entered first ends at the last position. So we need a DS that supports such functionality.
        
    The basic idea is to maintain a stack DS that stores the starting timestamp for each process & when we encounter an ending log we just need to subtract from 
    starting timestamp. But here have to takecare of condtion when a func() calls other functions, so we've to subtract the time spend/consumed by those functions. 

    TC: O(N) and Space: O(N/2) becz the stack can grow upto the depth atmost N/2 here

*/

class Solution {
public:
    struct log
    {
        int pid;
        int timestamp;
        string type;
        
        log (int _pid, int _timestamp, string _type)
        {
            pid = _pid;
            timestamp = _timestamp;
            type = _type;
        }
    };
        
    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        stack<log> s;
        vector<int> times(n, 0);
        
        for(int i =0; i<logs.size(); i++)
        {
            string log = logs[i];
            int pos = log.find(":");
            int pid = stoi(log.substr(0, pos));
            log.erase(0, pos+1);
            
            pos = log.find(":");
            string type = log.substr(0, pos);
            log.erase(0, pos+1);
            
            int timestamp = stoi(log);
            
            if(type == "start")
            {
                struct log item(pid, timestamp, type);
                s.push(item);
            }
            else
            {
                int timespend = timestamp-s.top().timestamp+1;
                times[pid] += timespend;
                s.pop();    //remove completed process from stack
                
                if(!s.empty())
                    times[s.top().pid] -= timespend;
            }
        }
        return times;
    }
};