#include <string>
#include <vector>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> um;
    map<string, int> m;
    
    for(size_t i = 0; i < genres.size(); i++) {
        um[genres[i]].push_back({plays[i], i});
        m[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> genre_sum(m.begin(), m.end());
    sort(genre_sum.begin(), genre_sum.end(), [&](auto& a, auto& b) {
        return a.second > b.second;
    });
    
    for(auto& a : genre_sum) {
        vector<pair<int, int>> songs(um[a.first].begin(), um[a.first].end());
        sort(songs.begin(), songs.end(), [&](auto& a, auto& b) {
            return a.first > b.first;
        });
        answer.push_back(songs[0].second);
        if(songs.size() > 1) answer.push_back(songs[1].second);
    }
    
    return answer;
}