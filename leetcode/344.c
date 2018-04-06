char* reverseString(char* s) {
	int i;
	char temp;
	for (i = 0; i < strlen(s) / 2; i++)
	{
		temp = s[i];
		s[i] = s[strlen(s) - 1 - i];
		s[strlen(s) - 1 - i] = temp;
	}
	return s;
}