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

//smart version
int strStr(const char* src, const char* pattern)
{
	int res = watch_Avideo(src, pattern);
    return res;
}

int* get_PMT(const char* pattern)
{
	int len_pat = strlen(pattern);

	int* pmt = (int*)malloc(sizeof(int) * len_pat);
	pmt[0] = pmt[1] = 0;

	int i = 0, j = 2;
	while (j < len_pat)
	{
		if (pattern[i] == pattern[j - 1])
		{
			pmt[j] = pmt[j - 1] + 1;
			i++;
			j++;
			continue;
		}
		else
		{
			while (i > 0 && pattern[i] != pattern[j - 1])
			{
				//change this argument to i - 1 if error occures
				i = pmt[i];
			}
			if (pattern[i] == pattern[j - 1])
			{
				pmt[j] = i + 1;
				i++;
				j++;
				continue;
			}
			else
			{
				pmt[j] = 0;
				j++;
				continue;
			}
		}
	}

	/*
	for (int index = 0; index < len_pat; index++)
	{
		printf("%d ", pmt[index]);
	}
	putchar('\n');
	*/

	return pmt;
}

//Why use this func name: KMP is a homonym for "watching adult video" in Chinese
int watch_Avideo(const char* src, const char* pattern)
{
	if (src == NULL || pattern == NULL)
		return -1;

	int len_src = strlen(src);
	int len_pat = strlen(pattern);

	if (len_pat == 0)
		return 0;
	else if (len_pat > len_src)
		return -1;

	int* PMT = get_PMT(pattern);
	int i, j;
	i = j = 0;
	while (i < len_src && j < len_pat)
	{
		if (j == 0 && src[i] != pattern[j])
		{
			i++;
		}
		else if (src[i] == pattern[j])
		{
			i++;
			j++;
			if (j >= len_pat)
				break;
		}
		else
		{
			j = PMT[j];
		}

	}

	free(PMT);

	if (j < len_pat)
		return -1;
	else
	{
		if (src[i - 1] == pattern[j - 1])
			return i - len_pat;
		else
			return -1;
	}	
}
