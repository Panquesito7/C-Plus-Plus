// 0-1 Knapsack problem - Dynamic programming
//#include <bits/stdc++.h>
#include <iostream>

// void Print(int res[20][20], int i, int j, int capacity)
//{
//	if(i==0 || j==0)
//	{
//		return;
//	}
//	if(res[i-1][j]==res[i][j-1])
//	{
//		if(i<=capacity)
//		{
//			cout<<i<<" ";
//		}
//
//		Print(res, i-1, j-1, capacity-i);
//	}
//	else if(res[i-1][j]>res[i][j-1])
//	{
//		Print(res, i-1,j, capacity);
//	}
//	else if(res[i][j-1]>res[i-1][j])
//	{
//		Print(res, i,j-1, capacity);
//	}
//}

int Knapsack(int capacity, int n, int weight[], int value[]) {
    int res[20][20];
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < capacity + 1; ++j) {
            if (i == 0 || j == 0) {
                res[i][j] = 0;
            } else if (weight[i - 1] <= j) {
                res[i][j] = max(value[i - 1] + res[i - 1][j - weight[i - 1]],
                                res[i - 1][j]);
            } else {
                res[i][j] = res[i - 1][j];
            }
        }
    }
    //	Print(res, n, capacity, capacity);
    //	cout<<"\n";
    return res[n][capacity];
}

/**
 * Main function
 */
int main() {
    int n;
    std::cout << "Enter number of items: ";
    std::cin >> n;
    int weight[n], value[n];
    std::cout << "Enter weights: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> weight[i];
    }
    std::cout << "Enter values: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value[i];
    }
    int capacity;
    std::cout << "Enter capacity: ";
    std::cin >> capacity;
    std::cout << Knapsack(capacity, n, weight, value);
    return 0;
}
