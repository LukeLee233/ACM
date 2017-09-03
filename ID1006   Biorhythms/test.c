/*
Description
���������������������ڣ��ֱ�Ϊ������������������ڣ����ǵ����ڳ���Ϊ23�졢28���33�졣ÿһ����������һ���Ǹ߷塣�ڸ߷����죬�˻�����Ӧ�ķ�����ֳ�ɫ�����磬�������ڵĸ߷壬�˻�˼ά���ݣ��������׸߶ȼ��С���Ϊ�������ڵ��ܳ���ͬ������ͨ���������ڵĸ߷岻������ͬһ�졣����ÿ���ˣ�������֪����ʱ�����߷�����ͬһ�졣����ÿ�����ڣ����ǻ�����ӵ�ǰ��ݵĵ�һ�쿪ʼ�������ָ߷����������һ���ǵ�һ�θ߷���ֵ�ʱ�䣩����������Ǹ���һ���ӵ����һ�쿪ʼ��������������Ӹ���ʱ�俪ʼ������������ʱ�䣩��һ�������߷�����ͬһ���ʱ�䣨�����ʱ��������������磺����ʱ��Ϊ10���´γ��������߷�ͬ���ʱ����12�������2��ע�����ﲻ��3����

Input
�����ĸ�������p, e, i��d�� p, e, i�ֱ��ʾ��������к������߷���ֵ�ʱ�䣨ʱ��ӵ���ĵ�һ�쿪ʼ���㣩��d �Ǹ�����ʱ�䣬����С��p, e, �� i�� ���и���ʱ���ǷǸ��Ĳ���С��365, �����ʱ��С��21252�� 
��p = e = i = d = -1ʱ���������ݽ�����

Output
�Ӹ���ʱ������һ�������߷�ͬ���ʱ�䣨�������ʱ����������� 
�������¸�ʽ�� 
Case 1: the next triple peak occurs in 1234 days. 
ע�⣺��ʹ�����1�죬Ҳʹ�ø�����ʽ��days����

Sample Input
0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320
203 301 203 40
-1 -1 -1 -1

Sample Output
Case 1: the next triple peak occurs in 21252 days.
Case 2: the next triple peak occurs in 21152 days.
Case 3: the next triple peak occurs in 19575 days.
Case 4: the next triple peak occurs in 16994 days.
Case 5: the next triple peak occurs in 8910 days.
Case 6: the next triple peak occurs in 10789 days.

*/

#include <stdio.h>

int main()
{
	int p,e,i,d;
	int Case;
	int count;
	int sum;
	Case = 1;
	scanf("%d%d%d%d",&p,&e,&i,&d);
	while(p!=-1 && e!=-1 && i!=-1 && d!=-1)
	{
		for(count = 1;count<21252;count++)
		{
			sum = count+d;
			if((sum-p)%23==0 && (sum-e)%28==0 && (sum-i)%33==0) break;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",Case,count);
		Case++;
		scanf("%d%d%d%d",&p,&e,&i,&d);
	}
	return 0;
}