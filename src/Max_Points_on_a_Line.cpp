/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		unordered_map<float, int> statistic;

		int maxNum = 0;
		for (int i = 0; i < points.size(); i++)
		{
			statistic.clear();
			statistic[INT_MIN] = 0; // for processing duplicate point
			int duplicate = 1;
			for (int j = 0; j < points.size(); j++)
			{
				if (j == i) continue;
				if (points[j].x == points[i].x && points[j].y == points[i].y) // count duplicate
				{
					duplicate++;
					continue;
				}
				float key = (points[j].x - points[i].x) == 0 ?
				            INT_MAX : // key for vertical line
				            (float) (points[j].y - points[i].y) / (points[j].x - points[i].x);
				statistic[key]++;
			}

			for (unordered_map<float, int>::iterator it = statistic.begin(); it != statistic.end(); ++it)
			{
				if (it->second + duplicate > maxNum)
				{
					maxNum = it->second + duplicate;
				}
			}
		}

		return maxNum;
	}
};