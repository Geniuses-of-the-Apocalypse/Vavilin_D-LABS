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

    double cos() const {
        return std::cos(toRadians());
    }

    double tan() const {
        return std::tan(toRadians());
    }

    Angle& add(int deg, int min = 0) {
        degrees += deg;
        minutes += min;
        normalize();
        return *this;
    }

    Angle& subtract(int deg, int min = 0) {
        degrees -= deg;
        minutes -= min;
        normalize();
        return *this;
    }

    Angle operator+(const Angle& other) const {
        return Angle(degrees + other.degrees, minutes + other.minutes);
    }

    Angle operator-(const Angle& other) const {
        return Angle(degrees - other.degrees, minutes - other.minutes);
    }

    Angle& operator+=(const Angle& other) {
        degrees += other.degrees;
        minutes += other.minutes;
        normalize();
        return *this;
    }

    Angle& operator-=(const Angle& other) {
        degrees -= other.degrees;
        minutes -= other.minutes;
        normalize();
        return *this;
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

    int getDegrees() const { return degrees; }
    int getMinutes() const { return minutes; }

    friend ostream& operator<<(ostream& os, const Angle& angle) {
        os << angle.degrees << "° " << angle.minutes << "'";
        return os;
    }

    friend istream& operator>>(istream& is, Angle& angle) {
        is >> angle.degrees >> angle.minutes;
        angle.normalize();
        return is;
    }
};

int main() {
    // Создание углов
    Angle angle1(45, 30);  // 45° 30'
    Angle angle2(400, 15); // 400° 15' (будет приведено к 40° 15')
    Angle angle3(-90, 45); // -90° 45' (будет приведено к 269° 15')

    cout << "Угол 1: " << angle1 << endl;
    cout << "Угол 2: " << angle2 << endl;
    cout << "Угол 3: " << angle3 << endl;

    cout << "\nУгол 1 в радианах: " << angle1.toRadians() << endl;
    cout << "Угол 2 в радианах: " << angle2.toRadians() << endl;

    cout << "\nСинус угла 1: " << angle1.sin() << endl;
    cout << "Косинус угла 1: " << angle1.cos() << endl;
    cout << "Тангенс угла 1: " << angle1.tan() << endl;

    Angle sum = angle1 + angle2;
    Angle diff = angle1 - angle2;
    
    cout << "\nСумма углов 1 и 2: " << sum << endl;
    cout << "Разность углов 1 и 2: " << diff << endl;

    angle1.add(30, 15);
    cout << "\nУгол 1 после добавления 30°15': " << angle1 << endl;
    
    angle2.subtract(15, 30);
    cout << "Угол 2 после вычитания 15°30': " << angle2 << endl;

    cout << "\nСравнение углов:" << endl;
    cout << "Угол 1 == Угол 2: " << (angle1 == angle2 ? "да" : "нет") << endl;
    cout << "Угол 1 < Угол 2: " << (angle1 < angle2 ? "да" : "нет") << endl;
    cout << "Угол 1 > Угол 2: " << (angle1 > angle2 ? "да" : "нет") << endl;

    return 0;
}
