#include <iostream>
#include <string>

using namespace std;

class Number {
public:
    virtual ~Number() = default;
    virtual void print() const = 0;
    virtual Number* add(const Number* other) const = 0;
    virtual Number* subtract(const Number* other) const = 0;
};

class Hex : public Number {
private:
    static const int SIZE = 100;
    unsigned char digits[SIZE]; 
    
    int fromHexChar(char c) const {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'F') return c - 'A' + 10;
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        return 0; 
    }
    
    char toHexChar(int value) const {
        if (value >= 0 && value <= 9) return '0' + value;
        if (value >= 10 && value <= 15) return 'A' + (value - 10);
        return '0'; 
    }
    
    void normalize() {
        int i = SIZE - 1;
        while (i > 0 && digits[i] == 0) {
            i--;
        }
    }

    void initializeToZero() {
        for (int i = 0; i < SIZE; i++) {
            digits[i] = 0;
        }
    }

public:
    Hex() {
        initializeToZero();
    }
    
    Hex(const string& hexStr) : Hex() {
        int len = hexStr.length();
        if (len > SIZE) {
            len = SIZE;
        }
        
        for (int i = 0; i < len; i++) {
            digits[len - 1 - i] = fromHexChar(hexStr[i]);
        }
        normalize();
    }
    
    Hex(const Hex& other) {
        for (int i = 0; i < SIZE; i++) {
            digits[i] = other.digits[i];
        }
    }
  
    Hex& operator=(const Hex& other) {
        if (this != &other) {
            for (int i = 0; i < SIZE; i++) {
                digits[i] = other.digits[i];
            }
        }
        return *this;
    }
    
    void print() const override {
        int start = SIZE - 1;
        while (start > 0 && digits[start] == 0) {
            start--;
        }
        
        for (int i = start; i >= 0; i--) {
            cout << toHexChar(digits[i]);
        }
    }
    
    Number* add(const Number* other) const override {
        const Hex* otherHex = dynamic_cast<const Hex*>(other);
        if (!otherHex) {
            return new Hex(); 
        }
        
        Hex* result = new Hex();
        int carry = 0;
        
        for (int i = 0; i < SIZE; i++) {
            int sum = digits[i] + otherHex->digits[i] + carry;
            result->digits[i] = sum % 16;
            carry = sum / 16;
        }
        
        result->normalize();
        return result;
    }
    
    Number* subtract(const Number* other) const override {
        const Hex* otherHex = dynamic_cast<const Hex*>(other);
        if (!otherHex) {
            return new Hex(); 
        }
        
        Hex* result = new Hex();
        int borrow = 0;
        
        for (int i = 0; i < SIZE; i++) {
            int diff = digits[i] - otherHex->digits[i] - borrow;
            if (diff < 0) {
                diff += 16;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result->digits[i] = diff;
        }
        
        result->normalize();
        return result;
    }
    
    bool operator==(const Hex& other) const {
        for (int i = 0; i < SIZE; i++) {
            if (digits[i] != other.digits[i]) return false;
        }
        return true;
    }
    
    bool isZero() const {
        for (int i = 0; i < SIZE; i++) {
            if (digits[i] != 0) return false;
        }
        return true;
    }
};

//Класс для работы с битовыми строками
class BitString : public Number {
private:
    static const int SIZE = 100;
    unsigned char bits[SIZE]; 
    
    void normalize() {
        int i = SIZE - 1;
        while (i > 0 && bits[i] == 0) {
            i--;
        }
    }

    void initializeToZero() {
        for (int i = 0; i < SIZE; i++) {
            bits[i] = 0;
        }
    }

public:
    BitString() {
        initializeToZero();
    }
    
    BitString(const string& bitStr) : BitString() {
        int len = bitStr.length();
        if (len > SIZE) {
            len = SIZE;
        }
        
        for (int i = 0; i < len; i++) {
            if (bitStr[i] == '1') {
                bits[len - 1 - i] = 1;
            } else {
                bits[len - 1 - i] = 0;
            }
        }
        normalize();
    }
    
    BitString(const BitString& other) {
        for (int i = 0; i < SIZE; i++) {
            bits[i] = other.bits[i];
        }
    }
    
    BitString& operator=(const BitString& other) {
        if (this != &other) {
            for (int i = 0; i < SIZE; i++) {
                bits[i] = other.bits[i];
            }
        }
        return *this;
    }
    
    void print() const override {
        int start = SIZE - 1;
        while (start > 0 && bits[start] == 0) {
            start--;
        }
        
        for (int i = start; i >= 0; i--) {
            cout << (char)('0' + bits[i]);
        }
    }
    
    Number* add(const Number* other) const override {
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
    
    Number* subtract(const Number* other) const override {
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

    BitString bitwiseAnd(const BitString& other) const {
        BitString result;
        for (int i = 0; i < SIZE; i++) {
            result.bits[i] = bits[i] & other.bits[i];
        }
        result.normalize();
        return result;
    }
    
    BitString bitwiseOr(const BitString& other) const {
        BitString result;
        for (int i = 0; i < SIZE; i++) {
            result.bits[i] = bits[i] | other.bits[i];
        }
        result.normalize();
        return result;
    }
    
    BitString bitwiseXor(const BitString& other) const {
        BitString result;
        for (int i = 0; i < SIZE; i++) {
            result.bits[i] = bits[i] ^ other.bits[i];
        }
        result.normalize();
        return result;
    }
    
    BitString bitwiseNot() const {
        BitString result;
        for (int i = 0; i < SIZE; i++) {
            result.bits[i] = 1 - bits[i]; 
        }
        result.normalize();
        return result;
    }
    
    bool operator==(const BitString& other) const {
        for (int i = 0; i < SIZE; i++) {
            if (bits[i] != other.bits[i]) return false;
        }
        return true;
    }
    
    bool isZero() const {
        for (int i = 0; i < SIZE; i++) {
            if (bits[i] != 0) return false;
        }
        return true;
    }
};

int main() {
    cout << "=== Testing Hex Class ===" << endl;
    
    //Тестирование Hex
    Hex hex1("1A3F");
    Hex hex2("B2C");
    
    cout << "hex1 = ";
    hex1.print();
    cout << endl;
    
    cout << "hex2 = ";
    hex2.print();
    cout << endl;
    
    Number* hexSum = hex1.add(&hex2);
    cout << "hex1 + hex2 = ";
    hexSum->print();
    cout << endl;
    delete hexSum;
    
    Number* hexDiff = hex1.subtract(&hex2);
    cout << "hex1 - hex2 = ";
    hexDiff->print();
    cout << endl;
    delete hexDiff;
    
    //Тестирование BitString
    cout << "\n=== Testing BitString Class ===" << endl;
    
    BitString bits1("1101");
    BitString bits2("1010");
    
    cout << "bits1 = ";
    bits1.print();
    cout << endl;
    
    cout << "bits2 = ";
    bits2.print();
    cout << endl;
    
    Number* bitsSum = bits1.add(&bits2);
    cout << "bits1 OR bits2 = ";
    bitsSum->print();
    cout << endl;
    delete bitsSum;
    
    Number* bitsDiff = bits1.subtract(&bits2);
    cout << "bits1 AND NOT bits2 = ";
    bitsDiff->print();
    cout << endl;
    delete bitsDiff;
    
    //Дополнительные битовые операции
    cout << "\n=== Additional Bit Operations ===" << endl;
    
    BitString andResult = bits1.bitwiseAnd(bits2);
    cout << "bits1 AND bits2 = ";
    andResult.print();
    cout << endl;
    
    BitString orResult = bits1.bitwiseOr(bits2);
    cout << "bits1 OR bits2 = ";
    orResult.print();
    cout << endl;
    
    BitString xorResult = bits1.bitwiseXor(bits2);
    cout << "bits1 XOR bits2 = ";
    xorResult.print();
    cout << endl;
    
    BitString notResult = bits1.bitwiseNot();
    cout << "NOT bits1 = ";
    notResult.print();
    cout << endl;
    
    return 0;
} 
