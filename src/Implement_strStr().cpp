class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		if (haystack == NULL || needle == NULL) return NULL;
		int hlen = strlen(haystack);
		int nlen = strlen(needle);
		if (nlen == 0) return haystack;
		if (hlen == 0 ) return NULL;
		int pattern[100000];
		GeneratePattern(needle, nlen, pattern);
		return Match(haystack, needle, pattern);
	}

	void GeneratePattern(char* str, int len, int* pattern)
	{
		pattern[0] = -1;
		int k = -1;
		for (int j = 1; j < len; j++)
		{
			while (k > -1 && str[k + 1] != str[j])
				k = pattern[k];
			if (str[k + 1] == str[j])
				k++;
			pattern[j] = k;
		}
	}

	char* Match(char* haystack, char* needle, int* pattern)
	{
		int hlen = strlen(haystack);
		int nlen = strlen(needle);
		int k = -1;
		for (int j = 0; j < hlen; j++, haystack++)
		{
			while (k > -1 && needle[k + 1] != *haystack)
				k = pattern[k];
			if (needle[k + 1] == *haystack)
				k++;
			if (k == nlen - 1)
				return haystack - k;
		}
		return NULL;
	}
};