/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    for (int i = 0; i < intervals.size(); i++)
    {
      insert(result, intervals[i]);
    }
    return result;
  }
  void insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval>::iterator it = intervals.begin();
    while (it != intervals.end())
    {
      if (newInterval.end < it->start)
      {
        intervals.insert(it, newInterval);
        return;
      }
      else if (newInterval.start > it->end)
      {
        it++;
        continue;
      }
      else
      {
        newInterval.start = min(newInterval.start, it->start);
        newInterval.end = max(newInterval.end, it->end);
        it = intervals.erase(it);
      }
    }
    intervals.insert(intervals.end(), newInterval);
  }
};