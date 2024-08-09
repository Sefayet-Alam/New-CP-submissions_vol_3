#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct Event {
    long long time;
    int person;
    bool entering; // true for entry, false for exit
};

bool compareEvent(const Event &e1, const Event &e2) {
    if (e1.time == e2.time) {
        return e1.entering < e2.entering; // Ensure exits are processed before entries if they occur at the same time
    }
    return e1.time < e2.time;
}

void processRecords(int N, int M, vector<pair<long long, int>> &records,
                    unordered_map<int, vector<pair<long long, long long>>> &intervals) {
    vector<Event> events;

    for (const auto &record : records) {
        long long time = record.first;
        int person = record.second;
        events.push_back({time, person, true});  // Entry event
        events.push_back({time, person, false}); // Exit event
    }

    // Sort events by time; for same time, ensure exits are before entries
    sort(events.begin(), events.end(), compareEvent);

    unordered_map<int, long long> currentEntries;
    unordered_map<int, long long> lastEntryTime;

    for (const auto &event : events) {
        int person = event.person;
        if (event.entering) {
            // Record entry time
            lastEntryTime[person] = event.time;
        } else {
            // Record interval for person
            if (lastEntryTime.find(person) != lastEntryTime.end()) {
                intervals[person].emplace_back(lastEntryTime[person], event.time);
                lastEntryTime.erase(person);
            }
        }
    }
}

long long calculateOverlap(const vector<pair<long long, long long>> &intervals1,
                           const vector<pair<long long, long long>> &intervals2) {
    long long totalOverlap = 0;
    int i = 0, j = 0;
    while (i < intervals1.size() && j < intervals2.size()) {
        const auto &intv1 = intervals1[i];
        const auto &intv2 = intervals2[j];
        long long start = max(intv1.first, intv2.first);
        long long end = min(intv1.second, intv2.second);
        if (start < end) {
            totalOverlap += end - start;
        }
        if (intv1.second < intv2.second) {
            ++i;
        } else {
            ++j;
        }
    }
    return totalOverlap;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<long long, int>> records(M);
    for (int i = 0; i < M; ++i) {
        cin >> records[i].first >> records[i].second;
    }

    unordered_map<int, vector<pair<long long, long long>>> intervals;
    processRecords(N, M, records, intervals);

    int Q;
    cin >> Q;
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (const auto &query : queries) {
        int A = query.first;
        int B = query.second;
        long long result = calculateOverlap(intervals[A], intervals[B]);
        cout << result << '\n';
    }

    return 0;
}
