#include <iostream>

int main()
{
    int m, n;
    std::cin >> m >> n;
    int suma{};
    for (int i = std::min(m, n) + 1; i < std::max(m, n); ++i)
        suma += i;

    std::cout << suma;
    // 47,8 MiB memory used
}
