#include <iostream>

template <typename T>
class MergeSort
{
private:
    template <typename T, int N>
    static void _Merge(T (&arr)[N], T (&aux)[N], int LeftStart, int LeftEnd, int RightStart, int RightEnd)
    {
        int ElemNum = RightEnd - LeftStart + 1;
        int Counter = LeftStart;
        while (LeftStart <= LeftEnd && RightStart <= RightEnd)
        {
            if (arr[LeftStart] < arr[RightStart])
                aux[Counter++] = arr[LeftStart++];
            else
                aux[Counter++] = arr[RightStart++];
        }
        while (LeftStart <= LeftEnd)
            aux[Counter++] = arr[LeftStart++];
        while (RightStart < RightEnd)
            aux[Counter++] = arr[RightStart++];
        for (int i = 0; i < ElemNum; ++i, --RightEnd)
            arr[RightEnd] = aux[RightEnd];
    }

    template <typename T, int N>
    static void _MergeSort(T (&arr)[N], T (&aux)[N], int Start, int End)
    {
        if (Start < End)
        {
            int Mid = (Start + End) / 2;
            MergeSort(arr, aux, Start, Mid);
            MergeSort(arr, aux, Mid + 1, End);
            Merge(arr, aux, Start, Mid, Mid + 1, End);
        }
    }
public:
    template <typename T, int N>
    void operator()(T (&arr)[N])
    {
        int aux[N];
        _MergeSort(arr, aux, 0, N - 1);
    }
};

using namespace std;

int main()
{
    int arr[] = {1, -2, 3, -4, 5, -6, 7, -8};
    MergeSort<int> merge;
    merge(arr);
    for (auto &i : arr)
        cout << i << endl;
    system("pause");
    return 0;
}