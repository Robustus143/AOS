#include <iostream>
#include <string>
#include <chrono>


using namespace std;
using namespace chrono;


int counter = 1000000;


double int_time() {
    
    int a = 13;
    int b = 37;
    int c = b + a, d = c + b, e = d + c, f = e + d, g = f + e, k = g + f, h = k + g, l = h + k, m = l + h;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = k;
        k = h;
        h = l;
        l = m;
    }

    auto end = high_resolution_clock::now();

    return (double)(end - start).count();
}


double int_avg_time() {
    
    double t = 0;

    for (int i = 0; i < 10; i++) {

        t += int_time();
    }
    
    return t / 10;
}


auto int_add_speed(double assingtime) {

    int a, b, c, d, e, f, g, h;
    int k = 13;
    int m = 37;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k + m;
        b = m + a;
        c = a + b;
        d = b + c;
        e = c + d;
        f = d + e;
        g = e + f;
        h = f + g;
        k = g + h;
        m = h + k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto int_sub_speed(double assingtime) {

    int a, b, c, d, e, f, g, h;
    int k = 13;
    int m = 37;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k - m;
        b = m - a;
        c = a - b;
        d = b - c;
        e = c - d;
        f = d - e;
        g = e - f;
        h = f - g;
        k = g - h;
        m = h - k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto int_multiply_speed(double assingtime) {

    int a, b, c, d, e, f, g, h;
    int k = 13;
    int m = 37;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k * m;
        b = m * a;
        c = a * b;
        d = b * c;
        e = c * d;
        f = d * e;
        g = e * f;
        h = f * g;
        k = g * h;
        m = h * k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto int_div_speed(double assingtime) {

    int a, b, c, d, e, f, g, k, h, m;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        k = 39366, m = 3;
        a = k / m;
        b = a / m;
        c = b / m;
        d = c / m;
        e = d / m;
        f = e / m;
        g = f / m;
        h = g / m;
        k = h / m;
        m = k / m;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto float_time() {

    float a = 312.6547;
    float b = 789.3564;
    float c = b + a, d = c + b, e = d + c, f = e + d, g = f + e, k = g + f, h = k + g, l = h + k, m = l + h;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = k;
        k = h;
        h = l;
        l = m;
    }

    auto end = high_resolution_clock::now();

    return (double)(end - start).count();
}


auto float_avg_time() {

    double t = 0;

    for (int i = 0; i < 10; i++) {

        t += float_time();
    }
    
    return t / 10;
}


auto float_add_speed(double assingtime) {

    float a, b, c, d, e, f, g, h;
    float k = 312.6547;
    float m = 789.3564;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k + m;
        b = m + a;
        c = a + b;
        d = b + c;
        e = c + d;
        f = d + e;
        g = e + f;
        h = f + g;
        k = g + h;
        m = h + k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto float_sub_speed(double assingtime) {

    float a, b, c, d, e, f, g, h;
    float k = 98642.2345672;
    float m = 579.98761;
    
    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k - m;
        b = m - a;
        c = a - b;
        d = b - c;
        e = c - d;
        f = d - e;
        g = e - f;
        h = f - g;
        k = g - h;
        m = h - k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto float_multiply_speed(double assingtime) {

    float a, b, c, d, e, f, g, h;
    float k = 19.43215;
    float m = 34.545;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k * m;
        b = m * a;
        c = a * b;
        d = b * c;
        e = c * d;
        f = d * e;
        g = e * f;
        h = f * g;
        k = g * h;
        m = h * k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto float_div_speed(double assingtime) {

    float a, b, c, d, e, f, g, h;
    float k = 23.4;
    float m = 4.5;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k / m;
        b = m / a;
        c = a / b;
        d = c / b;
        e = c / d;
        f = d / e;
        g = f / e;
        h = f / g;
        k = g / h;
        m = k / h;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto double_time() {

    double a = 1123456.123456;
    double b = 9876543.9876543;
    double c = b + a, d = c + b, e = d + c, f = e + d, g = f + e, k = g + f, h = k + g, l = h + k, m = l + h;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = k;
        k = h;
        h = l;
        l = m;
    }
   
    auto end = high_resolution_clock::now();
    
    return (double)(end - start).count();
}


auto double_avg_time() {

    double t = 0;

    for (int i = 0; i < 10; i++) {

        t += double_time();
    }
    
    return t / 10;
}


auto double_add_speed(double assingtime) {

    double a, b, c, d, e, f, g, h;
    double k = 1123456.123456;
    double m = 9876543.9876543;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k + m;
        b = m + a;
        c = a + b;
        d = b + c;
        e = c + d;
        f = d + e;
        g = e + f;
        h = f + g;
        k = g + h;
        m = h + k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto double_sub_speed(double assingtime) {

    double a, b, c, d, e, f, g, h;
    double k = 97864563728318.4362821394;
    double m = 32223132.12343192;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k - m;
        b = m - a;
        c = a - b;
        d = b - c;
        e = c - d;
        f = d - e;
        g = e - f;
        h = f - g;
        k = g - h;
        m = h - k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto double_multiply_speed(double assingtime) {

    double a, b, c, d, e, f, g, h;
    double k = 7658439.4576243;
    double m = 777653443.7245645;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k * m;
        b = m * a;
        c = a * b;
        d = b * c;
        e = c * d;
        f = d * e;
        g = e * f;
        h = f * g;
        k = g * h;
        m = h * k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto double_div_speed(double assingtime) {

    double a, b, c, d, e, f, g, h;
    double k = 234.34;
    double m = 40.24;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k / m;
        b = m / a;
        c = a / b;
        d = c / b;
        e = c / d;
        f = d / e;
        g = f / e;
        h = f / g;
        k = g / h;
        m = k / h;
    }

    auto end = high_resolution_clock::now();
    
    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto long_time() {

    long a = 123456;
    long b = 98765;
    long c = b + a, d = c + b, e = d + c, f = e + d, g = f + e, k = g + f, h = k + g, l = h + k, m = l + h;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = k;
        k = h;
        h = l;
        l = m;
    }

    auto end = high_resolution_clock::now();

    return (double)(end - start).count();
}


auto long_avg_time() {

    double t = 0;

    for (int i = 0; i < 10; i++) {

        t += long_time();
    }
    
    return t / 10;
}


auto long_add_speed(double assingtime) {

    long a, b, c, d, e, f, g, h;
    long k = 32413;
    long m = 9845;
   
    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k + m;
        b = m + a;
        c = a + b;
        d = b + c;
        e = c + d;
        f = d + e;
        g = e + f;
        h = f + g;
        k = g + h;
        m = h + k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto long_sub_speed(double assingtime) {

    long a, b, c, d, e, f, g, h;
    long k = 90782315;
    long m = 86573;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k - m;
        b = m - a;
        c = a - b;
        d = b - c;
        e = c - d;
        f = d - e;
        g = e - f;
        h = f - g;
        k = g - h;
        m = h - k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto long_multiply_speed(double assingtime) {

    long a, b, c, d, e, f, g, h;
    long k = 978651;
    long m = 6586;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k * m;
        b = m * a;
        c = a * b;
        d = b * c;
        e = c * d;
        f = d * e;
        g = e * f;
        h = f * g;
        k = g * h;
        m = h * k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto long_div_speed(double assingtime) {

    long a, b, c, d, e, f, g, k, h, m;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        k = 1594323, m = 3;
        a = k / m;
        b = a / m;
        c = b / m;
        d = c / m;
        e = d / m;
        f = e / m;
        g = f / m;
        h = g / m;
        k = h / m;
        m = k / m;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


/*double longlong_time() {

    long long a = 12345678910;
    long long b = 90876543210;
    long long c = b + a, d = c + b, e = d + c, f = e + d, g = f + e, k = g + f, h = k + g, l = h + k, m = l + h;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = k;
        k = h;
        h = l;
        l = m;
    }

    auto end = high_resolution_clock::now();

    return (double)(end - start).count();
}


double longlong_avg_time() {

    double t = 0;

    for (int i = 0; i < 20; i++) {

        t += longlong_time();
    }

    return t / 20;
}


auto longlong_add_speed(double assingtime) {

    long long a, b, c, d, e, f, g, h;
    long long k = 12343567891021413415;
    long long m = 9082765432101251;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k + m;
        b = m + a;
        c = a + b;
        d = b + c;
        e = c + d;
        f = d + e;
        g = e + f;
        h = f + g;
        k = g + h;
        m = h + k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto longlong_sub_speed(double assingtime) {

    long long a, b, c, d, e, f, g, h;
    long long k = 97876583491275712;
    long long m = 6567687383231289;


    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k - m;
        b = m - a;
        c = a - b;
        d = b - c;
        e = c - d;
        f = d - e;
        g = e - f;
        h = f - g;
        k = g - h;
        m = h - k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto longlong_multiply_speed(double assingtime) {

    long long a, b, c, d, e, f, g, h;
    long long k = 98674124562234;
    long long m = 9685125246;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k * m;
        b = m * a;
        c = a * b;
        d = b * c;
        e = c * d;
        f = d * e;
        g = e * f;
        h = f * g;
        k = g * h;
        m = h * k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto longlong_div_speed(double assingtime) {

    long long a, b, c, d, e, f, g, k, h, m;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        k = 31381059609, m = 3;
        a = k / m;
        b = a / m;
        c = b / m;
        d = c / m;
        e = d / m;
        f = e / m;
        g = f / m;
        h = g / m;
        k = h / m;
        m = k / m;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}
*/

auto char_time() {

    char a = 12;
    char b = 13;
    char c = b + a, d = c + b, e = d + c, f = e + d, g = f + e, k = g + f, h = k + g, l = h + k, m = l + h;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = k;
        k = h;
        h = l;
        l = m;
    }

    auto end = high_resolution_clock::now();

    return (double)(end - start).count();
}


auto char_avg_time() {

    double t = 0;

    for (int i = 0; i < 10; i++) {

        t += char_time();
    }

    return t / 10;
}


auto char_add_speed(double assingtime) {

    char a, b, c, d, e, f, g, h;
    char k = 12;
    char m = 13;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k + m;
        b = m + a;
        c = a + b;
        d = b + c;
        e = c + d;
        f = d + e;
        g = e + f;
        h = f + g;
        k = g + h;
        m = h + k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto char_sub_speed(double assingtime) {

    char a, b, c, d, e, f, g, h;
    char k = 3;
    char m = -7;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k - m;
        b = m - a;
        c = a - b;
        d = b - c;
        e = c - d;
        f = d - e;
        g = e - f;
        h = f - g;
        k = g - h;
        m = h - k;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto char_multiply_speed(double assingtime) {

    char a, b, c, d, e, f, g, h;
    char k = 3;
    char m = 17;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        a = k * m;
        b = m * a;
        c = a * b;
        d = b * c;
        e = c * d;
        f = d * e;
        g = e * f;
        h = f * g;
        k = g * h;
        m = h * k;
    }
    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;
}


auto char_div_speed(double assingtime) {

    char a, b, c, d, e, f, g, k, h, m;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < counter; i++) {

        k = 16, m = 4;
        a = k / m;
        b = m / a;
        c = a / b;
        d = c / b;
        e = c / d;
        f = d / e;
        g = f / e;
        h = f / g;
        k = g / h;
        m = k / h;
    }

    auto end = high_resolution_clock::now();

    double time = (end - start).count() - assingtime;

    return (double)counter * 1e10 / time;;
}


double maximum(double arr[24]) {

    double max = 0;

    for (int i = 0; i < 24; i++) {

        if (arr[i] > max) {

            max = arr[i];
        }
    }

    return max;
}


void output(double arr[20], double maximum) {

    char operators[4] = { '+', '-', '*', '/' };
    string types[5] = { "   int   ", "  long   ", "  float  ", " double  " , "  char   " };

    for (int i = 0; i < 20; i++) {

        cout << " " << operators[i % 4] << "  " << types[i / 4] << "  " << arr[i] << "  ";

        for (int j = 0; j < int(100 * (arr[i] / maximum)) / 2; j++) {

            cout << 'X';
        }

        for (int j = 0; j < 50 - int(100 * (arr[i] / maximum)) / 2; j++) {

            cout << ' ';
        }

        cout << "  " << int(100 * (arr[i] / maximum)) << " %" << endl;
    }
}
    

int main() {

    const double int_ass = int_avg_time();
    const double float_ass = float_avg_time();
    const double double_ass = double_avg_time();
    const double long_ass = long_avg_time();
    const double char_ass = char_avg_time();
    
    double result[20];

    result[0] = int_add_speed(int_ass);
    result[1] = int_sub_speed(int_ass);
    result[2] = int_multiply_speed(int_ass);
    result[3] = int_div_speed(int_ass);
    result[4] = long_add_speed(long_ass);
    result[5] = long_sub_speed(long_ass);
    result[6] = long_multiply_speed(long_ass);
    result[7] = long_div_speed(long_ass);
    result[8] = float_add_speed(float_ass);
    result[9] = float_sub_speed(float_ass);
    result[10] = float_multiply_speed(float_ass);
    result[11] = float_div_speed(float_ass);
    result[12] = double_add_speed(double_ass);
    result[13] = double_sub_speed(double_ass);
    result[14] = double_multiply_speed(double_ass);
    result[15] = double_div_speed(double_ass);
    result[16] = char_add_speed(char_ass);
    result[17] = char_sub_speed(char_ass);
    result[18] = char_multiply_speed(char_ass);
    result[19] = char_div_speed(char_ass);

    double max_speed = maximum(result);

    output(result, max_speed);

    return 0;
}
