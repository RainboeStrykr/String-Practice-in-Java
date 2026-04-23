#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    float ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    sort(items, items + n, compare);
    float totalProfit = 0.0;
    float fraction;

    cout << "\nSelected items:\n";

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            cout << "Item with weight " << items[i].weight << " and profit "
                 << items[i].profit << " selected completely\n";

            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else {
            fraction = (float)capacity / items[i].weight;

            cout << "Item with weight " << items[i].weight << " and profit "
                 << items[i].profit << " selected partially (" << fraction << ")\n";

            totalProfit += items[i].profit * fraction;
            capacity = 0;
            break;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
