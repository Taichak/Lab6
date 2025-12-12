#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846

double deg2rad(double deg) {
    return deg * (PI / 180.0);
}

double rad2deg(double rad) {
    return rad * (180.0 / PI);
}
double findXcomponent(double l, double a) {
    return l * cos(a);
}
double findYcomponent(double l, double a) {
    return l * sin(a);
}

double pythagoras(double xcomp, double ycomp) {
    return hypot(xcomp, ycomp);
}

void showResult(double length, double direction) {
    cout << "*****************************************************" << endl;
    cout << "Length of the resultant vector = " << fixed << setprecision(4) << length << endl;
    cout << "Direction of the resultant vector (deg) = " << fixed << setprecision(4) << direction << endl;
    cout << "*****************************************************" << endl;
}

int main() {
    double l1, l2, a1, a2, xcomp_total, ycomp_total, result_vec_length, result_vec_direction;
    cout << "Enter length of the first vector: ";
    cin >> l1;
    cout << "Enter direction of the first vector (deg): ";
    cin >> a1;
    cout << "Enter length of the second vector: ";
    cin >> l2;
    cout << "Enter direction of the second vector (deg): ";
    cin >> a2;

    double rad1 = deg2rad(a1);
    double rad2 = deg2rad(a2);
    xcomp_total = findXcomponent(l1, rad1) + findXcomponent(l2, rad2);
    ycomp_total = findYcomponent(l1, rad1) + findYcomponent(l2, rad2);
    result_vec_length = pythagoras(xcomp_total, ycomp_total);
    double result_rad = atan2(ycomp_total, xcomp_total);
    result_vec_direction = rad2deg(result_rad);
    showResult(result_vec_length, result_vec_direction);

    return 0;
}