#include <stdio.h>
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数 。
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	double medi=0.0;
	int num = 0, i = 0, j = 0, a = 0, arr[2] = { 0 };
	num = (nums1Size + nums2Size) / 2+1;
	if (nums1Size == 0)
	{
		if (nums2Size == 0)
			return 0;
		else
		{
			if(nums2Size%2)
				return *(nums2 + nums2Size / 2);
			else
				return (*(nums2 + nums2Size / 2)+ *(nums2 + nums2Size / 2-1))/2.0;
		}
			
	}
	else if(nums2Size == 0)
	{
		if (nums1Size % 2)
			return *(nums1 + nums1Size / 2);
		else
			return (*(nums1 + nums1Size / 2) + *(nums1 + nums1Size / 2 + 1)) / 2.0;
	}

	while ((i+j) < num)
	{
		if (i < nums1Size && j < nums2Size)
		{
			if (*(nums1 + i) >= *(nums2 + j))
			{
				if ((i + j) >= num - 2)
				{
					if (j < nums2Size)
						arr[a++] = *(nums2 + j);
				}
				if (j < nums2Size)
					j++;
			}
			else
			{
				if ((i + j) >= num - 2)
				{
					if (i < nums1Size)
						arr[a++] = *(nums1 + i);		
				}
				if (i < nums1Size)
					i++;
			}
		}
		else
		{
			if (a <= 1)
			{
				if (i >= nums1Size)
				{
					if ((i + j) >= num - 2)
					{
						arr[a++] = *(nums2 + j);
					}
					j++;
				}
				else if (j >= nums2Size)
				{
					if ((i + j) >= num - 2)
					{
						arr[a++] = *(nums1 + i);
					}
					i++;
				}
			}
		}
	}
	if ((nums1Size + nums2Size) % 2)
		medi = arr[1];
	else
		medi = (arr[0] + arr[1]) / 2.0;
	return medi;
}

int main()
{
	int nums1[1] = { 1 }, nums2[5] = {2,3,4,5,6};
	double a = 0.0;
	a = findMedianSortedArrays(nums1,1,nums2,5);
	printf("a = %f\r\n",a);
	return 0;
}