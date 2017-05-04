//Напишите функцию, которая перебирает натуральные числа от 1 до N включительно 
//и раскладывает каждое число на простые множители. Результат можно выводить на 
//экран либо копить в любой структуре данных.

#include <iostream>
#include <map>
#include <list>

using namespace std;

map<int, list<int> > function(int N) {

    map<int, list<int> > numbers;
    list<int> buffer;

    if (N > 2) {

        multimap<int, list<int> >::iterator it;

        buffer.push_back(2);
        numbers.insert(pair<int, list<int> >(2, buffer));

        for (int var = 3; var < N + 1; ++var) {
            buffer.clear();

            int temp = var;
            for (int numIn = var - 1; numIn > 1; --numIn){
                if ( !(temp % numIn) ){
                    numbers[var].insert(numbers[var].end(), numbers[numIn].begin(), numbers[numIn].end());
                    temp /= numIn;
                    numIn++;
                }
            }
            if(temp == var) {
                numbers[var].push_back(var);
            }
        }
    } else {
        numbers[0].push_back(0);
    }
    return numbers;
}

int main() {
    map<int, list<int> > numbers;
    int nums = 90;

    numbers = function(nums);

    for (int var = 2; var < nums + 1; ++var) {
        cout << var << " = ";

        for (list<int>::iterator it = numbers[var].begin(); it != numbers[var].end(); ++it) {
            it == numbers[var].begin() ?  cout << *it : cout << " * " << *it ;
        }
        cout << endl;
    }

    return 0;
}
