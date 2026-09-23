#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator() (const vector<int>& a, const vector<int>& b) {
        if(a[2] == b[2]) {
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] > b[1];
        }
        return a[2] > b[2];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, idx = 0, t = 0, job_num = jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    
    while(idx < job_num || !pq.empty()) {
        // 현재 시간까지 전부 넣기
        while(idx < job_num && t >= jobs[idx][0]) {
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        if(!pq.empty()) {
            // 하나 뽑아 시행
            auto current = pq.top();
            pq.pop();

            t += current[2];
            answer += t - current[1];
        }
        else if(idx < job_num) t = jobs[idx][0];
    }
    
    return answer / job_num;
}
