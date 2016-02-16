class Solution {
public:
	string countAndSay(int n) {
		string seq = "1";
		int it = 1;
		while (it < n)
		{
			stringstream newSeq;
			char last = seq[0];
			int count = 0;
			for (int i = 0; i <= seq.size(); i++)
			{
				if (seq[i] == last)
				{
					count ++;
					continue;
				}
				else
				{
					newSeq << count << last;
					last = seq[i];
					count = 1;
				}
			}
			seq = newSeq.str();
			it++;
		}
		return seq;
	}
};