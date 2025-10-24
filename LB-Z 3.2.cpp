#include <iostream>
#include <string>

using namespace std;

class Number
{
public:
    virtual ~Number() = default;
    virtual void display() const = 0;
    virtual Number* add(const Number* other) const = 0;
    virtual Number* substract(const Number* other) const = 0;
};

//==========================

class Hex : public Number
{
private:
    static const int SIZE = 100;
    char digit[SIZE];
    
    int fromHexChar(char c) const;
    char toHexChar(int value) const;
    void normalize();
    void initToZero();
    
public:
    Hex();
    Hex(const string& hexStr);
    Hex(const Hex& other);
    
    void display() const override;
    Number* add(const Number* other) const override;
    Number* substract(const Number* other) const override;
    bool isZero() const;
    
    Hex& operator=(const Hex& other);
    bool operator==(const Hex& other) const;
};

int Hex::fromHexChar(char c) const
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

char Hex::toHexChar(int value) const
{
    if (value >= 0 && value <= 9) return '0' + value;
    if (value >= 10 && value <= 15) return 'A' + (value - 10);
    return '0';
}

void Hex::normalize()
{
    int i = SIZE - 1;
    while (i > 0 && digit[i] == 0)
        i--;
}

void Hex::initToZero()
{
    for (int i = 0; i < SIZE; i++)
        digit[i] = 0;
}

Hex::Hex()
{
    initToZero();
}

Hex::Hex(const string& hexStr) : Hex()
{
    int len = hexStr.length();
    if (len > SIZE)
        len = SIZE;
    for (int i = 0; i < len; i++)
        digit[len - 1 - i] = fromHexChar(hexStr[i]);
    normalize();
}

Hex::Hex(const Hex& other)
{
    for (int i = 0; i < SIZE; i++)
        digit[i] = other.digit[i];
}

void Hex::display() const
{
    int start = SIZE - 1;
    while(start > 0 && digit[start] == 0)
        start--;
    for (int i = start; i >= 0; i--)
        cout << toHexChar(digit[i]);
}

Number* Hex::add(const Number* other) const
{
    const Hex* otherHex = dynamic_cast<const Hex*>(other);
    if (!otherHex)
        return new Hex();
    Hex* result = new Hex();
    int carry = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int sum = digit[i] + otherHex->digit[i] + carry;
        result->digit[i] = sum % 16;
        carry = sum / 16;
    }
    result->normalize();
    return result;
}

Number* Hex::substract(const Number* other) const
{
    const Hex* otherHex = dynamic_cast<const Hex*>(other);
    if (!otherHex)
        return new Hex();
    Hex* result = new Hex();
    int borrow = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int diff = digit[i] - otherHex->digit[i] - borrow;
        if (diff < 0)
        {
            diff += 16;
            borrow = 1;
        }
        else
            borrow = 0;
        result->digit[i] = diff;
    }
    result->normalize();
    return result;
}

bool Hex::isZero() const
{
    for (int i = 0; i < SIZE; i++)
        if (digit[i] != 0) return false;
    return true;
}

Hex& Hex::operator=(const Hex& other)
{
    if (this != &other)
    {
        for (int i = 0; i < SIZE; i++) 
            digit[i] = other.digit[i];
    }
    return *this;
}

bool Hex::operator==(const Hex& other) const 
{
    for (int i = 0; i < SIZE; i++)
        if (digit[i] != other.digit[i]) return false;
    return true;
}

//=======================

class BitString : public Number
{
private:
    static const int SIZE = 100;
    char bits[SIZE];
    
    void normalize();
    void initToZero();
    
public:
    BitString();
    BitString(const string& bitStr);
    BitString(const BitString& other);
    
    void display() const override;
    Number* add(const Number* other) const override;
    Number* substract(const Number* other) const override;
    BitString bitwiseAnd(const BitString& other) const;
    BitString bitwiseOr(const BitString& other) const;
    BitString bitwiseNot() const;
    bool isZero() const;
    
    bool operator==(const BitString& other) const;
    BitString& operator=(const BitString& other);
};

void BitString::normalize()
{
    int i = SIZE - 1;
    while (i > 0 && bits[i] == 0)
        i--;
}

void BitString::initToZero()
{
    for (int i = 0; i < SIZE; i++)
        bits[i] = 0;
}

BitString::BitString()
{
    initToZero();
}

BitString::BitString(const string& bitStr) : BitString()
{
    int len = bitStr.length();
    if (len > SIZE)
        len = SIZE;
    for (int i = 0; i < len; i++)
    {
        if (bitStr[i] == '1')
            bits[len - 1 - i] = 1;
        else
            bits[len - 1 - i] = 0;
    }
    normalize();
}

BitString::BitString(const BitString& other)
{
    for (int i = 0; i < SIZE; i++)
        bits[i] = other.bits[i];
}

void BitString::display() const
{
    int start = SIZE - 1;
    while (start > 0 && bits[start] == 0)
        start--;
    for (int i = start; i >= 0; i--)
        cout << (char)('0' + bits[i]);
}

Number* BitString::add(const Number* other) const
{
    const BitString* otherBitStr = dynamic_cast<const BitString*>(other);
    if (!otherBitStr) {
        return new BitString(); 
    }
    
    BitString* result = new BitString();
    
    for (int i = 0; i < SIZE; i++) {
        result->bits[i] = bits[i] | otherBitStr->bits[i];
    }
    
    result->normalize();
    return result;
}

Number* BitString::substract(const Number* other) const
{
    const BitString* otherBitStr = dynamic_cast<const BitString*>(other);
    if (!otherBitStr) {
        return new BitString(); 
    }
    
    BitString* result = new BitString();
    
    for (int i = 0; i < SIZE; i++) {
        result->bits[i] = bits[i] & (1 - otherBitStr->bits[i]);
    }
    
    result->normalize();
    return result;
}

BitString BitString::bitwiseAnd(const BitString& other) const
{
    BitString result;
    for (int i = 0; i < SIZE; i++) {
        result.bits[i] = bits[i] & other.bits[i];
    }
    result.normalize();
    return result;
}

BitString BitString::bitwiseOr(const BitString& other) const
{
    BitString result;
    for (int i = 0; i < SIZE; i++) {
        result.bits[i] = bits[i] | other.bits[i];
    }
    result.normalize();
    return result;
}

BitString BitString::bitwiseNot() const
{
    BitString result;
    for (int i = 0; i < SIZE; i++) {
        result.bits[i] = 1 - bits[i]; 
    }
    result.normalize();
    return result;
}

bool BitString::isZero() const
{
    for (int i = 0; i < SIZE; i++) {
        if (bits[i] != 0) return false;
    }
    return true;
}

bool BitString::operator==(const BitString& other) const
{
    for (int i = 0; i < SIZE; i++)
    {
        if (bits[i] != other.bits[i])
            return false;
    }
    return true;
}

BitString& BitString::operator=(const BitString& other)
{
    if (this != &other)
    {
        for (int i = 0; i < SIZE; i++)
            bits[i] = other.bits[i];
    }
    return *this;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    
    //Класс Hex
    cout << ">>КЛАСС HEX." << endl;
    cout << "=============" << endl;
    
    Hex hex1("1A3F");
    Hex hex2("B2C");
    
    cout << ">Вывод hex1: ";
    hex1.display();
    cout << endl;
    
    cout << ">Вывод hex2: ";
    hex2.display();
    cout << endl;
    
    Number* hexSum = hex1.add(&hex2);
    cout << ">Сумма hex1 + hex2: ";
    hexSum->display();
    cout << endl;
    delete hexSum;
    
    Number* hexDiff = hex1.substract(&hex2);
    cout << ">Разность hex1 - hex2: ";
    hexDiff->display();
    cout << endl;
    delete hexDiff;
    
    //Класс BitString
    cout << ">>КЛАСС BITSTRING." << endl;
    cout << "===================" << endl;
    
    BitString bits1("1101");
    BitString bits2("1010");
    
    cout << ">Вывод bits1: ";
    bits1.display();
    cout << endl;
    
    cout << ">Вывод bits2: ";
    bits2.display();
    cout << endl;
    
    cout << ">Вывод bits1 or bits2: ";
    Number* bitSum = bits1.add(&bits2);
    bitSum->display();
    cout << endl;
    delete bitSum;
    
    cout << ">Вывод bits1 and not bits2: ";
    Number* bitsDiff = bits1.substract(&bits2);
    bitsDiff->display();
    cout << endl;
    delete bitsDiff;
    
    //Доп. операции
    cout << ">>ДОПОЛНИТЕЛЬНЫЙ БИТОВЫЕ ОПЕРАЦИИ." << endl;
    cout << "==============================================" << endl;
    
    cout << ">Вывод bits1 and bits2: ";
    BitString andRes = bits1.bitwiseAnd(bits2);
    andRes.display();
    cout << endl;
    
    cout << ">Вывод bits1 or bits2: ";
    BitString orRes = bits1.bitwiseOr(bits2);
    orRes.display();
    cout << endl;
    
    cout << ">Вывод not bits1: ";
    BitString notRes = bits1.bitwiseNot();
    notRes.display();
    cout << endl;
    
    return 0;
}
