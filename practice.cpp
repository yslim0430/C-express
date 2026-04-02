#include <iostream>
#include <vector>

using namespace std;

/*
2개의 정렬된 정수 배열 A와 B가 있고, 이 2개의 배열을 합쳐서 하나의 정렬된 배열 C로 만드는 함수.
일단 A와 B의 배열 크기는 동일하다고 하자.
*/

/*
일단 merge 함수에서 1번으로 생각할 건, while문을 통해 i나 j가 4가 되기 전까지
계속 반복해서 C에 대입하다가, 둘 중 하나가 4에 도달하면 나머지를 C에 넣고 탈출시키는 방법
*/

void merge(int* A, int* B, int* C, int size) {		//A와 B를 C에 저장하는 함수

	int i = 0, j = 0, k = 0;		//i는 A의, j는 B의, k는 C의 원소

	while (1) {		//A나 B가 C에 전부 들어갈 때 까지 반복하는 함수
		if (A[i] <= B[j]) {
			C[k] = A[i];
			i++;
			k++;
		}
		else {
			C[k] = B[j];
			j++;
			k++;
		}
		if (i == 4) {		//만약 A가 먼저 전부 C에 들어갔다면,
			for (j; j < 4; j++) {		//B의 남은 원소들을 C에 넣어라
				C[k] = B[j];
				k++;
			}
			break;
		}
		if (j == 4) {		//만약 B가 먼저 전부 C에 들어갔다면,
			for (i; i < 4; i++) {		//A의 남은 원소들을 C에 넣어라
				C[k] = A[i];
				k++;
			}
			break;
		}
	}
}

int main() {

	int A[4] = { 2,5,7,8 };
	int B[4] = { 1,3,4,6 };
	int C[8]; 
	
	merge(A, B, C, 8);

	for (int i = 0; i < 8; i++) {
		cout << " " << C[i];
	}
}