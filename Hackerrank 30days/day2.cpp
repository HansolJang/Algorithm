#include <iostream>

using namespace std;

// Complete the solve function below.
int solve(double meal_cost, int tip_percent, int tax_percent) {
    double tip = meal_cost / 100.0 * (double) tip_percent;
    double tax = meal_cost / 100.0 * (double) tax_percent;
    return meal_cost + tip + tax;
}

int main() {
    double meal_cost;
    cin >> meal_cost;

    int tip_percent;
    cin >> tip_percent;

    int tax_percent;
    cin >> tax_percent;

    printf("%d\n", (int) (solve(meal_cost, tip_percent, tax_percent) + 0.5f));

    return 0;
}
