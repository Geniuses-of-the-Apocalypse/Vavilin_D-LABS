#include <iostream>
#include <cmath>
using namespace std;

class Angle {
private:
    int degrees;
    int minutes;

    void normalize() {
        int totalMinutes = degrees * 60 + minutes;
        totalMinutes %= 21600;
        if (totalMinutes < 0) {
            totalMinutes += 21600;
        }
        degrees = totalMinutes / 60;
        minutes = totalMinutes % 60;
    }

public:
    Angle(int deg = 0, int min = 0) : degrees(deg), minutes(min) {
        normalize();
    }

    double toRadians() const {
        double totalDegrees = degrees + minutes / 60.0;
        return totalDegrees * M_PI / 180.0;
    }

    double sin() const {
        return std::sin(toRadians());
    }

    void increase(int deg, int min = 0) {
        degrees += deg;
        minutes += min;
        normalize();
    }

    void decrease(int deg, int min = 0) {
        degrees -= deg;
        minutes -= min;
        normalize();
    }

    bool operator==(const Angle& other) const {
        return degrees == other.degrees && minutes == other.minutes;
    }

    bool operator!=(const Angle& other) const {
        return !(*this == other);
    }

    bool operator<(const Angle& other) const {
        if (degrees != other.degrees) {
            return degrees < other.degrees;
        }
        return minutes < other.minutes;
    }

    bool operator>(const Angle& other) const {
        return other < *this;
    }

    bool operator<=(const Angle& other) const {
        return !(other < *this);
    }

    bool operator>=(const Angle& other) const {
        return !(*this < other);
    }

    void print() const {
        cout << degrees << "° " << minutes << "'";
    }
};

int main() {
    Angle a1(45, 30);
    Angle a2(400, 15);
    Angle a3(-30, 45);

    cout << "a1: "; a1.print();
    cout << " = " << a1.toRadians() << " рад, sin = " << a1.sin() << endl;

    cout << "a2: "; a2.print();
    cout << " = " << a2.toRadians() << " рад" << endl;

    cout << "a3: "; a3.print();
    cout << " = " << a3.toRadians() << " рад" << endl;

    a1.increase(90, 15);
    cout << "После увеличения: "; a1.print(); cout << endl;

    a1.decrease(45, 30);
    cout << "После уменьшения: "; a1.print(); cout << endl;

    Angle b1(30, 0);
    Angle b2(30, 30);
    cout << "b1 < b2: " << (b1 < b2) << endl;
    cout << "b1 == b2: " << (b1 == b2) << endl;

    return 0;
}
