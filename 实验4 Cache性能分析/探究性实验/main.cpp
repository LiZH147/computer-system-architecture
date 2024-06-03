#include <iostream>
#include <windows.h>

#define N 1024
int A[N][N], B[N][N], C[N][N];
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = B[i][j] = i + j;
		}
	}
}
int main() {
	init();
	LARGE_INTEGER start, end, freq;
	double elapsed_time;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	QueryPerformanceCounter(&end);
	elapsed_time = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
	printf("程序执行时间为: %f seconds\n", elapsed_time);
	return 0;
}
