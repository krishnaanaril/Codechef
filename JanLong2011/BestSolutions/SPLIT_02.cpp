#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

#define NMAX 1111
#define VMAX 501

int A[NMAX];
int N;

void ReadInput() {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &(A[i]));
}

int bsol[NMAX], nbsol;
int csol[NMAX], ncsol;

void UpdateSol() {
	if (ncsol < nbsol) {
		nbsol = ncsol;
		memcpy(bsol, csol, nbsol * sizeof(int));
	}
}

int need[VMAX], have[2][VMAX];

void SimpleGreedy() {
	int start, end, endmax, i, c;

	for (start = 1; start <= N; start++) {
		memset(have, 0, sizeof(have));
		for (endmax = start; endmax <= N; endmax++) {
			if (have[0][A[endmax]] + 1 > need[A[endmax]]) break;
			have[0][A[endmax]]++;
		}
		endmax--;
		
		for (end = endmax; end >= start && end >= endmax - 15; end--) {
			memset(have, 0, sizeof(have));
			ncsol = 0;
			if (start > 1) {
				csol[ncsol++] = start - 1;
				have[1][A[start - 1]]++;
			}
			if (end < N) {
				if (have[1][A[end + 1]] + 1 <= need[A[end + 1]]) {
					csol[ncsol++] = end;
					have[1][A[end + 1]]++;
				} else continue;
			}

			for (i = start; i <= end; i++) {
				if (have[0][A[i]] + 1 > need[A[i]]) break;
				have[0][A[i]]++;
			}
			
			if (i <= end) break;

			for (c = 1, i = end + 2; i <= N; i++) {
				if (have[c][A[i]] + 1 <= need[A[i]])
					have[c][A[i]]++;
				else {
					c = 1 - c;
					have[c][A[i]]++;
					csol[ncsol++] = i - 1;
				}
			}
	
			for (c = 1, i = start - 2; i >= 1; i--) {
				if (have[c][A[i]] + 1 <= need[A[i]])
					have[c][A[i]]++;
				else {
					c = 1 - c;
					have[c][A[i]]++;
					csol[ncsol++] = i;
				}
			}
		
			UpdateSol();
		}
	}
}

void Solve() {
	int i;

	memset(need, 0, sizeof(need));
	for (i = 1; i <= N; i++)
		need[A[i]]++;
	for (i = 1; i < VMAX; i++)
		need[i] >>= 1;

	nbsol = N;
	SimpleGreedy();
}

void WriteOutput() {
	int i;
	printf("%d\n", nbsol);
	sort(bsol, bsol + nbsol);
	for (i = 0; i < nbsol; i++)
		printf("%d ", bsol[i]);
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		ReadInput();
		Solve();
		WriteOutput();
	}

	return 0;
}
