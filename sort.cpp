#include <iostream>
#include <cstdlib>

template<typename T, int N>
void InsertionSort(T(&arr)[N])
{
	for (int i = 1; i < N; ++i)
	{
		int j = i;
		auto tmp = std::move(arr[i]);
		for (; j > 0 && arr[j - 1] > tmp; --j)
			arr[j] = arr[j - 1];
		arr[j] = std::move(tmp);
	}
}

template<typename T, int N>
void ShellSort(T(&arr)[N])
{
	for (int gap = N / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < N; i += gap)
		{
			int j = i; auto tmp = std::move(arr[i]);
			for (; j > 0 && arr[j - gap] > tmp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = tmp;
		}
	}
}

template<typename T, int N>
void BubbleSort(T(&arr)[N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}

template<typename T, int N>
void QuickSortHelper(T(&arr)[N], int Start, int End)
{
	if (Start < End)
	{
		int low = Start; int high = End;
		T pivot = std::move(arr[Start]);
		while (Start < End)
		{
			while (Start < End && arr[End] > pivot) --End;
			arr[Start] = arr[End];
			while (Start < End && arr[Start] < pivot) ++Start;
			arr[End] = arr[Start];
		}
		arr[Start] = pivot;
		QuickSortHelper(arr, low, Start - 1);
		QuickSortHelper(arr, Start + 1, high);
	}
}

template<typename T, int N>
void QuickSort(T(&arr)[N])
{
	QuickSortHelper(arr, 0, N - 1);
}

template<typename T, int N>
void SelectSort(T(&arr)[N])
{
	for (int i = 0; i < N; ++i)
	{
		int minPos = i;
		for (int j = i + 1; j < N; ++j)
		{
			if (arr[j] < arr[minPos])
			{
				minPos = j;
			}
		}
		std::swap(arr[i], arr[minPos]);
	}
}

template<typename T, int N>
void Sink(T(&arr)[N], int i, int n)
{
	auto leftChild = [](int x)->int { return 2 * x + 1; };
	int child;
	T tmp;
	for (tmp = std::move(arr[i]); n > leftChild(i); i = child)
	{
		child = leftChild(i);
		if (child < n - 1 && arr[child] < arr[child + 1])
			++child;
		if (tmp < arr[child])
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = std::move(tmp);
}

template<typename T, int N>
void HeapSort(T(&arr)[N])
{
	//for (int i = 0; i <= N / 2 - 1; ++i)
	//	Sink(arr, i, N);
	for (int i = N / 2 - 1; i >= 0; --i)
		Sink(arr, i, N);
	for (int j = N - 1; j > 0; --j)
	{
		std::swap(arr[0], arr[j]);
		Sink(arr, 0, j);
	}
}

using namespace std;

int main(void)
{
	int arr[] = { 1,-2,3,-4,5,-6 };
	HeapSort(arr);
	for (auto& i : arr) cout << i << endl;
	system("pause");
	return 0;
}