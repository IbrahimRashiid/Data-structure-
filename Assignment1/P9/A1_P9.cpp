#include <bits/stdc++.h>
#include <time.h>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;


class Sorter {
public:
    Sorter() {

    }

    virtual void sort(vector<int> &array, int size) {
        cout << "base\n";
    }
};


class SelectionSorter : public Sorter {
public:
    SelectionSorter() : Sorter() {

    }

    void sort(vector<int> &arr, int n) override {
        int i, j, min_idx;

        for (i = 0; i < n - 1; i++) {
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            swap(arr[min_idx], arr[i]);
        }
    }
};

class QuickSorter : public Sorter {
public:
    void sort(vector<int> &arr, int n) override {
        quickSort(arr, 0, n - 1);
    }

private:
    int partition(vector<int> &arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {

            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(vector<int> &arr, int low, int high) {
        if (low < high) {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(arr, low, high);
            
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};

class Testbed {
public:
    vector<int> GenerateRandomList(int min, int max, int size) {
        vector<int> vec;
        auto gen = [&max, &min]() {
            return rand() % (max - min + 1) + min;
        };
        vec = vector<int>(size);
        generate(begin(vec), end(vec), gen);
        return vec;
    }

    vector<int> GenerateReverseOrderedList(int min, int max, int size) {
        vector<int> vec;
        vec = GenerateRandomList(min, max, size);
        sort(vec.begin(), vec.end(), greater<int>());
        return vec;
    }


    void printarray(vector<int> vec) {
        for (auto i: vec) {
            cout << i << " ";
        }
    }

    long long RunOnce(Sorter *sorter, vector<int> &vec, int size) {
        std::chrono::time_point<std::chrono::system_clock> start, end;

        start = std::chrono::system_clock::now();
        sorter->sort(vec, size);
        end = std::chrono::system_clock::now();

        auto duration = duration_cast<microseconds>(end - start);

        return duration.count();
    }

    long long RunAndAverage(Sorter *sorter,
                            vector<int>(Testbed::*type)(int, int, int),
                            int min, int max, int size, int sets_num) {
        long long sum = 0;
        int n = sets_num;
        while (sets_num--) {
            vector<int> vec = (this->*type)(min, max, size);
            sum += RunOnce(sorter, vec, size);
        }

        return (sum / n);
    }

    void RunExperient(Sorter *sorter,
                      vector<int>(Testbed::*type)(int, int, int),
                      int min, int max, int min_val, int max_val, int sets_num, int step) {
        vector<pair<long long, int>> table_data;
        for (int size = min_val; size <= max_val; size += step) {
            long long x = RunAndAverage(sorter, type, min, max, size, sets_num);
            table_data.emplace_back(x, size);
        }
        for (auto &z: table_data) {
            cout << " Time with micro seconds: " << z.first << " array size: " << z.second << '\n';
        }
    }
};

int main() {

    Testbed testbed;
    Sorter *selection = new SelectionSorter();
    Sorter *qucik = new QuickSorter();
    cout << "------random selection------------\n";
    testbed.RunExperient(selection, &Testbed::GenerateRandomList, 10, 1000, 1000, 5000, 12, 1000);
    cout << "------random quick------------\n";
    testbed.RunExperient(qucik, &Testbed::GenerateRandomList, 10, 1000, 1000, 5000, 12, 1000);
    cout << "------reversed selection------------\n";
    testbed.RunExperient(selection, &Testbed::GenerateRandomList, 10, 1000, 1000, 5000, 12, 1000);
    cout << "------reversed quick------------\n";
    testbed.RunExperient(qucik, &Testbed::GenerateRandomList, 10, 1000, 1000, 5000, 12, 1000);
    return 0;
}