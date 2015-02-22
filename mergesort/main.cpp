#include <iostream>
#include <algorithm>
#include <vector>

///Tomas Abril
///Allan Patrick

//using namespace std;

std::vector<int> merge_sort(const std::vector<int> &data)
{
    if (data.size() <= 1) {
        return data;
    }

    int middle = data.size() / 2;
    std::vector<int> left(data.begin(), data.begin()+middle);
    std::vector<int> right(data.begin()+middle, data.end());

    left = merge_sort(left);
    right = merge_sort(right);

    std::vector<int> result(data.size());
    std::merge(left.begin(), left.end(),
               right.begin(), right.end(),
               result.begin());

    return result;
}

int main()
{
    int tam, num;
    std::vector<int> vetorinicial;
    std::vector<int> vetorfinal;
    std::vector<int>::iterator it;

    std::cout << "\n Qual o tamanho do vetor a ser ordenado? ";
    std::cin >> tam;
    for(int i =0; i<tam; i++) {
        std::cout << "\n digite um numero: ";
        std::cin >> num;
        vetorinicial.push_back(num);
    }
    vetorfinal = merge_sort(vetorinicial);

    std::cout << "\n Vetor ordenado: ";
    for (it=vetorfinal.begin(); it<vetorfinal.end(); it++) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';
    return 0;
}
