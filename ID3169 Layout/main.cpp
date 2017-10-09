/*
Description
Like everyone else, cows like to stand close to their friends when queuing for feed. FJ has N (2 <= N <= 1,000) cows numbered 1..N standing along a straight line waiting for feed. The cows are standing in the same order as they are numbered, and since they can be rather pushy, it is possible that two or more cows can line up at exactly the same location (that is, if we think of each cow as being located at some coordinate on a number line, then it is possible for two or more cows to share the same coordinate).
Some cows like each other and want to be within a certain distance of each other in line. Some really dislike each other and want to be separated by at least a certain distance. A list of ML (1 <= ML <= 10,000) constraints describes which cows like each other and the maximum distance by which they may be separated; a subsequent list of MD constraints (1 <= MD <= 10,000) tells which cows dislike each other and the minimum distance by which they must be separated.
Your job is to compute, if possible, the maximum possible distance between cow 1 and cow N that satisfies the distance constraints.

Input
Line 1: Three space-separated integers: N, ML, and MD.
Lines 2..ML+1: Each line contains three space-separated positive integers: A, B, and D, with 1 <= A < B <= N. Cows A and B must be at most D (1 <= D <= 1,000,000) apart.
Lines ML+2..ML+MD+1: Each line contains three space-separated positive integers: A, B, and D, with 1 <= A < B <= N. Cows A and B must be at least D (1 <= D <= 1,000,000) apart.

Output
Line 1: A single integer. If no line-up is possible, output -1. If cows 1 and N can be arbitrarily far apart, output -2. Otherwise output the greatest possible distance between cows 1 and N.

Sample Input
4 2 1
1 3 10
2 4 20
2 3 3

Sample Output
27

Hint
Explanation of the sample:
There are 4 cows. Cows #1 and #3 must be no more than 10 units apart, cows #2 and #4 must be no more than 20 units apart, and cows #2 and #3 dislike each other and must be no fewer than 3 units apart.
The best layout, in terms of coordinates on a number line, is to put cow #1 at 0, cow #2 at 7, cow #3 at 10, and cow #4 at 27.
*/

#include <iostream>

using namespace std;

const int INF = 2147483647;


int main()
{
    int N,ML,MD;
    cin>>N>>ML>>MD;
    //生成数据结构
    int *AL = new int[ML];
    int *BL = new int[ML];
    int *DL = new int[ML];
    int *AD = new int[MD];
    int *BD = new int[MD];
    int *DD = new int[MD];
    int *d = new int[N];

    fill(d,d+N,INF);
    d[0] = 0;

    for(int i = 0;i<ML;i++)
        cin>>AL[i]>>BL[i]>>DL[i];
    for(int i= 0;i<MD;i++)
        cin>>AD[i]>>BD[i]>>DD[i];

    for(int k = 0;k<N;k++)
    {
        for(int i=0;i+1<N;i++)
        {
            if(d[i+1]<INF) d[i] = min(d[i],d[i+1]);
        }
        for(int i = 0;i<ML;i++)
        {
            if(d[AL[i]-1] < INF)
                d[BL[i]-1] = min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
        }
        for(int i = 0;i<MD;i++)
        {
            if(d[BD[i]-1] < INF)
                d[AD[i]-1] = min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
        }
    }

    int ans = d[N-1];
    if(d[0]<0)
        ans = -1;
    else if(ans == INF)
        ans = -2;

    cout<<ans<<endl;

    //释放数据结构
    delete [] d;
    delete [] DD;
    delete [] BD;
    delete [] AD;
    delete [] DL;
    delete [] BL;
    delete [] AL;
    return 0;
}
