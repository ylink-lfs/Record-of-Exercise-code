bool judgeCircle(char* moves) 
{
	char* search = moves;
	int l_r = 0;
	int u_d = 0;
	while (*search)
	{
		if (*search == 'U')
		{
			u_d++;
		}
		else if (*search == 'D')
		{
			u_d--;
		}
		else if (*search == 'L')
		{
			l_r--;
		}
		else if (*search == 'R')
		{
			l_r++;
		}
		search++;
	}
	if (l_r == 0 && u_d == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
