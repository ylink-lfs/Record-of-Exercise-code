//Brute Version
int strStr(const char* src, const char* pattern)
{
	if (src == NULL || pattern == NULL)
		return -1;

	int len_src = strlen(src);
	int len_pat = strlen(pattern);	

	if (len_pat == 0)
		return 0;
	else if (len_pat > len_src)
		return -1;

	for (int i = 0; i < len_src - len_pat + 1; i++)
	{
		if (src[i] == pattern[0])
		{
			int j;
			for (j = 0; j < len_pat; j++)
			{
				if (src[j + i] != pattern[j])
					break;
				}
				if (j == len_pat)
					return i;
		}
	}
	return -1;
}
