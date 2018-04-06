int arrayPairSum(int* nums, int numsSize) 
{
	int sum = 0;
	std::sort(nums, nums + nunsSize);
	for (i = 0; i <= numsSize - 2; i += 2)
	{
		sum += nums[i];
	}
	return sum;
}