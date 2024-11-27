#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <functional>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> v = { 3, -5, 4, 9, -2, 8, -5, 6, -1, 0 };
    cout << "Створений вектор:\n";
    for (int n : v)
        cout << n << " ";
    cout << "\n";

    int sum_positive = accumulate(v.begin(), v.end(), 0, [](int sum, int n) {
        return sum + (n > 0 ? n : 0);
        });
    cout << "Сума додатніх елементів: " << sum_positive << "\n";

    auto max_abs_iter = max_element(v.begin(), v.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });
    auto min_abs_iter = min_element(v.begin(), v.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });

    cout << "Максимальний по модулю: " << *max_abs_iter << " на позиції "
        << distance(v.begin(), max_abs_iter) << "\n";
    cout << "Мінімальний по модулю: " << *min_abs_iter << " на позиції "
        << distance(v.begin(), min_abs_iter) << "\n";

   int product = 1;
if (max_abs_iter > min_abs_iter) {
    product = accumulate(min_abs_iter + 1, max_abs_iter, 1, multiplies<int>());
} else if (min_abs_iter > max_abs_iter) {
    product = accumulate(max_abs_iter + 1, min_abs_iter, 1, multiplies<int>());
}
product = abs(product);



    cout << "Добуток елементів між максимальним і мінімальним по модулю: "
        << product << "\n";

    // Сортування за спаданням
    sort(v.begin(), v.end(), greater<int>());
    cout << "Відсортований вектор за спаданням:\n";
    for (int n : v)
        cout << n << " ";
    cout << "\n";

    return 0;
}