void QuickSortRon(int a[], int left, int right)
{
	//手动利用栈来存储每次分块快排的起始点
	//栈非空时循环获取中轴入栈
	stack<int> s;
	if (left < right)
	{
		int keyi = PartSort1(a, left, right);

		if (keyi - 1 > left) //确保左分区存在 
		{
			//将左分区端点入栈 
			s.push(left);
			s.push(keyi - 1);
		}
		if (keyi + 1 < right) //确保右分区存在 
		{
			s.push(keyi + 1);
			s.push(right);
		}

		while (!s.empty())
		{
			//得到某分区的左右边界 
			int end = s.top();
			s.pop();
			int begin = s.top();
			s.pop();

			keyi = PartSort1(a, begin, end);
			if (keyi - 1 > begin) //确保左分区存在 
			{
				//将左分区端点入栈 
				s.push(begin);
				s.push(keyi - 1);
			}
			if (keyi + 1 < end) //确保右分区存在 
			{
				s.push(keyi + 1);
				s.push(end);
			}
		}
	}
}