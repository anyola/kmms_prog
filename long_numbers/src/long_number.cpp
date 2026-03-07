#include "long_number.hpp"
#include <iostream>
#include <string>

using saa::LongNumber;

LongNumber::LongNumber() {
    length = 1;
    sign = 1;
    numbers = new int[1];
    numbers[0] = 0;
}
LongNumber::LongNumber(int x){
    if(x == 0){
        length = 1;
        sign = 1;
        numbers = new int[1];
        numbers[0] = 0;
    }
    if( x > 0) {
        sign = 1;
    }
    else{
        sign = -1;
        x = x * (-1);
    }
    int x1 = x;
    while (x1 > 0){
        length++;
        x1 /= 10;
    }
    numbers = new int[length];
    for(int i = 0; i < length; i++){
        numbers[i] = x % 10;
        x /= 10;
    }
    
}

LongNumber::LongNumber(const char* const str) {
    int start = 0;
    if (str[0] == '-') {
        sign = -1;
        start = 1;
    } else {
        sign = 1;
    }

    if (str[start] == '\0') {
        length = 1;
        numbers = new int[1]{0};
        sign = 1;
        return;
    }

    length = get_length(str);
    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = str[start + length - 1 - i] - '0';
    }
    if (length == 1 && numbers[0] == 0) {
        sign = 1;
    }
}

LongNumber::LongNumber(const LongNumber& x) {
    length = x.length;
    sign = x.sign;
    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = x.numbers[i];
    }
}

LongNumber::LongNumber(LongNumber&& x) {
    numbers = x.numbers;
    length = x.length;
    sign = x.sign;
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;
}

LongNumber::~LongNumber() {
    delete[] numbers;
}

LongNumber& LongNumber::operator=(const char* const str) {
    *this = LongNumber(str);
    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber& x) {
    if (this == &x) {
        return *this;
    }
    delete[] numbers;
    length = x.length;
    sign = x.sign;
    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = x.numbers[i];
    }
    return *this;
}

LongNumber& LongNumber::operator=(LongNumber&& x) {
    if (this == &x) {
        return *this;
    }
    delete[] numbers;
    numbers = x.numbers;
    length = x.length;
    sign = x.sign;
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;
    return *this;
}

bool LongNumber::operator==(const LongNumber& x) const {
    if (length != x.length || sign != x.sign) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) {
            return false;
        }
    }
    return true;
}

bool LongNumber::operator!=(const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator>(const LongNumber& x) const {
    if (sign != x.sign) {
        if (sign > x.sign) {
            return true;
        } else {
            return false;
        }
    }

    if (length != x.length) {
        if (sign == 1) {
            if (length > x.length) {
                return true;
            } else {
                return false;
            }
        } else {
            if (length < x.length) {
                return true;
            } else {
                return false;
            }
        }
    }

    for (int i = length - 1; i >= 0; i--) {
        if (numbers[i] != x.numbers[i]) {
            if (sign == 1) {
                if (numbers[i] > x.numbers[i]) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (numbers[i] < x.numbers[i]) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool LongNumber::operator<(const LongNumber& x) const {
    if (*this > x) {
        return false;
    }
    if (*this == x) {
        return false;
    }
    return true;
}

LongNumber LongNumber::operator+(const LongNumber& x) const {
    if (sign < 0 && x.sign < 0) {
        LongNumber tmp1 = *this;
        LongNumber tmp2 = x;
        tmp1.sign = 1;
        tmp2.sign = 1;
        LongNumber res = tmp1 + tmp2;
        res.sign = -1;
        return res;
    }

    if (sign < 0) {
        LongNumber tmp = *this;
        tmp.sign = 1;
        return x - tmp;
    }

    if (x.sign < 0) {
        LongNumber tmp = x;
        tmp.sign = 1;
        return *this - tmp;
    }

    int max_len;
    if (length > x.length) {
        max_len = length;
    } else {
        max_len = x.length;
    }

    LongNumber res;
    delete[] res.numbers;
    res.length = max_len + 1;
    res.sign = 1;
    res.numbers = new int[res.length];

    for (int i = 0; i < res.length; i++) {
        res.numbers[i] = 0;
    }

    int carry = 0;
    for (int i = 0; i < res.length; i++) {
        int a;
        if (i < length) {
            a = numbers[i];
        } else {
            a = 0;
        }
        int b;
        if (i < x.length) {
            b = x.numbers[i];
        } else {
            b = 0;
        }
        int s = a + b + carry;
        res.numbers[i] = s % 10;
        carry = s / 10;
    }

    while (res.length > 1 && res.numbers[res.length - 1] == 0) {
        res.length--;
    }

    return res;
}

LongNumber LongNumber::operator-(const LongNumber& x) const {
    if (sign != x.sign) {
        LongNumber tmp = x;
        tmp.sign = -tmp.sign;
        return *this + tmp;
    }

    if (*this == x) {
        return 0;
    }

    bool greater = false;
    if (length > x.length) {
        greater = true;
    } else if (length < x.length) {
        greater = false;
    } else {
        for (int i = length - 1; i >= 0; i--) {
            if (numbers[i] > x.numbers[i]) {
                greater = true;
                break;
            }
            if (numbers[i] < x.numbers[i]) {
                greater = false;
                break;
            }
        }
    }

    if (greater) {
        LongNumber res;
        delete[] res.numbers;
        res.length = length;
        res.sign = sign;
        res.numbers = new int[length];

        int borrow = 0;
        for (int i = 0; i < length; i++) {
            int a = numbers[i] - borrow;
            int b;
            if (i < x.length) {
                b = x.numbers[i];
            } else {
                b = 0;
            }

            if (a < b) {
                a += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res.numbers[i] = a - b;
        }

        while (res.length > 1 && res.numbers[res.length - 1] == 0) {
            res.length--;
        }

        return res;
    } else {
        LongNumber res = x - *this;
        res.sign = -sign;
        return res;
    }
}

LongNumber LongNumber::operator*(const LongNumber& x) const {
    if(*this == 0 || x == 0){
        return 0;
    }
    LongNumber res;
    delete[] res.numbers;
    res.length = length + x.length;
    res.sign = sign * x.sign;
    res.numbers = new int[res.length];

    for (int i = 0; i < res.length; i++) {
        res.numbers[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        int carry = 0;
        for (int j = 0; j < x.length; j++) {
            int idx = i + j;
            int digit = res.numbers[idx] + numbers[i] * x.numbers[j] + carry;
            res.numbers[idx] = digit % 10;
            carry = digit / 10;
        }
        res.numbers[i + x.length] += carry;
    }

    while (res.length > 1 && res.numbers[res.length - 1] == 0) {
        res.length--;
    }

    return res;
}
LongNumber LongNumber::operator/(const LongNumber& x) const {
    if (x == LongNumber("0")) {
        return LongNumber(0);
    }

    LongNumber a = *this;
    LongNumber b = x;

    a.sign = 1;
    b.sign = 1;

    LongNumber result;
    result.length = length;
    result.numbers = new int[result.length];
    for (int i = 0; i < result.length; i++) {
        result.numbers[i] = 0;
    }

    LongNumber current("0");

    for (int i = length - 1; i >= 0; i--) {
        int* old = current.numbers;
        current.length++;
        current.numbers = new int[current.length];
        for (int j = 1; j < current.length; j++) {
            current.numbers[j] = old[j - 1];
        }
        current.numbers[0] = numbers[i];
        delete[] old;

        while (current.length > 1 && current.numbers[current.length - 1] == 0) {
            current.length--;
        }

        int count = 0;

        while (!(current < b)) {
            current = current - b;
            count++;
        }

        result.numbers[i] = count;
    }

    while (result.length > 1 && result.numbers[result.length - 1] == 0) {
        result.length--;
    }

    int result_sign = sign * x.sign;

    if (*this < LongNumber("0") && !(current == LongNumber("0"))) {
        result = result + LongNumber("1");
    }

    result.sign = result_sign;

    if (result.length == 1 && result.numbers[0] == 0) {
        result.sign = 1;
    }

    return result;
}
LongNumber LongNumber::operator%(const LongNumber& x) const {
    LongNumber r = *this - (*this / x) * x;
    if (r.is_negative()) {
        LongNumber abs_x = x;
        abs_x.sign = 1;
        r = r + abs_x;
    }
    return r;
}

bool LongNumber::is_negative() const noexcept {
    if (sign == -1) {
        return true;
    } else {
        return false;
    }
}

int LongNumber::get_length(const char* const str) const noexcept {
    int n = 0;
    int start;
    if (str[0] == '-') {
        start = 1;
    } else {
        start = 0;
    }

    while (str[start + n] != '\0') {
        n++;
    }
    return n;
}

namespace saa {
std::ostream& operator<<(std::ostream& os, const LongNumber& x) {
    if (x.sign < 0) {
        os << "-";
    }
    for (int i = x.length - 1; i >= 0; i--) {
        os << x.numbers[i];
    }
    return os;
}
}
