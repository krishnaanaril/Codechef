#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;
 
	struct	node
	{
		int l, r, k;
	}	a[1005];
	
	bool	cmp(const node a, const node b)
	{
		return a.r - a.l < b.r - b.l;
	}
	
	int f[505][505], pre[505][505], v[505], w[505], id[505];
	
struct testcase{
	int N, I[1000], C[500];
	int Icnt, Iorder[1000], Istart[501];
	int S[1000], sflag;
	void readinput(){
		scanf("%d", &N);
		int CC[500]={0};
		for(int i=0; i<N; i++){
			scanf("%d", &I[i]);
			CC[--I[i]]++;
		}
		int renumber[500];
		for(int i=0; i<500; i++)
			if(CC[i]>0){
				C[Icnt]=CC[i]>>1;
				renumber[i]=Icnt++;
			}
		for(int i=0; i<N; i++)
			I[i]=renumber[I[i]];
		for(int i=0; i<Icnt; i++){
			Istart[i+1]=Istart[i]+2*C[i];
			CC[i]=0;
		}
		for(int i=0; i<N; i++)
			Iorder[Istart[I[i]]+CC[I[i]]++]=i;
	}
	int getscore(int *s){
		int ret=0;
		for(int i=1; i<N; i++)
			ret+=s[i]^s[i-1];
		return ret;
	}
	void printoutput(){
		printf("%d\n", getscore(S));
		bool	firstBlood = 1;
		for(int i=1; i<N; i++)
			if(S[i]!=S[i-1])
			{
				if (!firstBlood)	printf(" ");
				firstBlood = 0;
				printf("%d", i);
			}
		putchar('\n');
	}
	void sub_ans(int *s){
		if(!sflag || getscore(s)<getscore(S))
			for(int i=0; i<N; i++)
				S[i]=s[i];
		sflag=1;
	}
	
	
	inline void	color(int *s, int l, int r, int c)
	{
		for (int i = l; i <= r; ++ i)	s[i] = c;
	}
	
	inline void	work(int *s, int M, int k, int &V)
	{
		int n = 0, sum = 0;
		for (int i = 1; i <= M; ++ i)	if (a[i].k == k)
		{
			++ n;
			v[n] = a[i].r - a[i].l + 1, w[n] = (a[i].l > 0) + (a[i].r < N - 1), id[n] = i;
			sum += v[n];
		}
		if (sum <= V)
		{
			V -= sum;
			for (int i = 1; i <= n; ++ i)
			{
				int t = id[i];
				a[t].k = -1;
				color(s, a[t].l, a[t].r, k & 1);
			}
			return;
		}
		sum = 0;
		f[0][0] = 0;
		for (int i = 1; i <= n; ++ i)
		{
			int last = sum;
			sum = min(sum + v[i], V);
			for (int j = 0; j <= sum; ++ j)
			{
				f[i][j] = - 1 << 30;
				if (j <= last)	f[i][j] = f[i - 1][j], pre[i][j] = 0;
				if (j - v[i] >= 0 && f[i - 1][j - v[i]] + w[i] > f[i][j])	f[i][j] = f[i - 1][j - v[i]] + w[i], pre[i][j] = 1;
			}
		}
		int p = 0;
		for (int i = 0; i <= V; ++ i)	if (f[n][i] > f[n][p])	p = i;
		V -= p;
		for (int i = n; i; -- i)
			if (pre[i][p])
			{
				int t = id[i];
				a[t].k = -1;
				color(s, a[t].l, a[t].r, k & 1);
				p -= v[i];
			}
	}
	
	void small_improvement(int *s, int ing, int equal=0){
		int pre = getscore(s);
		
		int M = 0;
		for (int i = Istart[ing]; i < Istart[ing + 1]; ++ i)
		{
			int j = Iorder[i];
			if (M && a[M].r == j - 1)	a[M].r ++;
			else	a[++ M].l = j, a[M].r = j;
		}
		
		for (int i = 1; i <= M; ++ i)
		{
			a[i].k = 0;
			if (a[i].l > 0 && a[i].r < N - 1)
				a[i].k = s[a[i].l - 1] * 2 + s[a[i].r + 1];
			else
			{
				if (a[i].l > 0)	a[i].k = s[a[i].l - 1] * 3;
				if (a[i].r < N - 1)	a[i].k = s[a[i].r + 1] * 3;
			}
		}
		random_shuffle(a + 1, a + M + 1);
		int rest[2] = {C[ing], C[ing]};
		work(s, M, 0, rest[0]);
		work(s, M, 3, rest[1]);
		//sort(a + 1, a + M + 1, cmp);
		for (int i = 1; i <= M; ++ i)	if (a[i].k != -1)
		{
			int sum = a[i].r - a[i].l + 1, left = 0, right = 0;
			if (rest[0] - rest[1] >= sum)	left = sum;
			else if (rest[1] - rest[0] >= sum)	right = sum;
			else
			{
				left = max(0, rest[0] - rest[1]);
				right = max(0, rest[1] - rest[0]);
				sum -= left + right;
				left += sum / 2, right += sum / 2;
				if (sum % 2)	if (rand() % 2)	left ++;
				else	right ++;
			}
			rest[0] -= left, rest[1] -= right;
			if (a[i].k == 1)
			{
				color(s, a[i].l, a[i].l + left - 1, 0);
				color(s, a[i].l + left, a[i].r, 1);
			}
			else if (a[i].k == 2)
			{
				color(s, a[i].l, a[i].l + right - 1, 1);
				color(s, a[i].l + right, a[i].r, 0);
			}
			else if (a[i].k == 0)
			{
				int l = 0, r = 0;
				for (int j = a[i].l - 1; j >= 0 && I[j] != ing && s[j] == 0; -- j)	++ l;
				for (int j = a[i].r + 1; j < N && I[j] != ing && s[j] == 0; ++ j)	++ r;
				if (l > r || l == r && rand() % 2)
				{
					color(s, a[i].l, a[i].l + left - 1, 0);
					color(s, a[i].l + left, a[i].r, 1);
				}
				else
				{
					color(s, a[i].l, a[i].l + right - 1, 1);
					color(s, a[i].l + right, a[i].r, 0);
				}
			}
			else
			{
				int l = 0, r = 0;
				for (int j = a[i].l - 1; j >= 0 && I[j] != ing && s[j] == 1; -- j)	++ l;
				for (int j = a[i].r + 1; j < N && I[j] != ing && s[j] == 1; ++ j)	++ r;
				if (l > r || l == r && rand() % 2)
				{
					color(s, a[i].l, a[i].l + right - 1, 1);
					color(s, a[i].l + right, a[i].r, 0);
				}
				else
				{
					color(s, a[i].l, a[i].l + left - 1, 0);
					color(s, a[i].l + left, a[i].r, 1);
				}
			}
		}
		//assert(getscore(s) > pre);
		if (getscore(s) > pre)
		{
			int wei = 1;
		}
	}
	int improve(int *s=NULL){
		if(!s) s=S;
		int res=0;
		for(int i=0; i<Icnt; i++)
			small_improvement(s, i, 1);
		return res;
	}
	void improve_and_sub(int *s, int passes){
		for(int i=0; i<Icnt; i++)
			small_improvement(s, i);
		for(int i=0; i<Icnt; i++)
			small_improvement(s, i);
		for(int pass=0; pass<passes; pass++)
			improve(s);
		sub_ans(s);
	}
	void greedy(){
		int s[1000];
		int ingred[2][500]={{0}};
		s[0]=0;
		ingred[0][I[0]]++;
		for(int i=1; i<N; i++){
			if(ingred[s[i-1]][I[i]]<C[I[i]])
				s[i]=s[i-1];
			else
				s[i]=s[i-1]^1;
			ingred[s[i]][I[i]]++;
		}
		improve_and_sub(s, 300);
		ingred[s[N-1]][I[N-1]]--;
		for(int i=N-2; i>=0; i--){
			if(ingred[s[i+1]][I[i]]>0)
				s[i]=s[i+1];
			else
				s[i]=s[i+1]^1;
			ingred[s[i]][I[i]]--;
		}
		improve_and_sub(s, 300);
	}
	void random(){
		int s[1000];
		int ingred[2][500]={{0}};
		for(int i=0; i<N; i++){
			s[i]=(rand()%(2*C[I[i]]-ingred[0][I[i]]-ingred[1][I[i]]))<(C[I[i]]-ingred[1][I[i]]);
			ingred[s[i]][I[i]]++;
		}
		improve_and_sub(s, 30);
	}
};
 
int K;
testcase cases[30];
 
struct timeval start, now;
void starttimer(){
	gettimeofday(&start, NULL);
}
int elapsed(){
	gettimeofday(&now, NULL);
	return (now.tv_sec-start.tv_sec)*1000000+(now.tv_usec-start.tv_usec);
	//return clock() * 1000;
}
 
int main(){
	srand(time(0));
#ifndef ONLINE_JUDGE
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
#endif
	starttimer();
	scanf("%d", &K);
	for(int i=0; i<K; i++)
		cases[i].readinput();
	for(int i=0; i<K; i++)
		cases[i].greedy();
	while(elapsed()<4500000)
	//for (int t = 0; t <= 10; ++ t)
		for(int i=0; i<K; i++)
			cases[i].random();
	//while(elapsed()<4800000)
	//for (int t = 0; t <= 10; ++ t)
	//	for(int i=0; i<K; i++)
	//		cases[i].improve() && cases[i].improve() && cases[i].improve();
	for(int i=0; i<K; i++)
		cases[i].printoutput();
}
 
