#include <iostream>
#include <string>
#include <vector>

std::string fizzBuzz(int number);
std::string fizzBuzztozz(int number);

int main() {

    int num = 0,numCount = 0;
    std::string input;
    std::vector<int> divisors;

    //Q1
    /*for (int i = 1; i <= 100; i++) {
        std::string result = fizzBuzz(i);
        std::cout << result << std::endl;
    }*/

    // ユーザーから数値を入力
    std::cout << "上限数を入力してください: ";
    std::cin >> num;

    //Q2
    /*for (int i = 1; i <= num; i++) {
        std::string result = fizzBuzz(i);
        std::cout << result << std::endl;
    }*/

    //Q3
    /*for (int i = 1; i <= num; i++) {
        std::string result = fizzBuzztozz(i);
        std::cout << result << std::endl;
    }*/

    //Q4
    /*std::cout << "割る数の個数を入力してください: ";
    std::cin >> numCount;

    divisors.resize(numCount);
    for (int i = 0; i < numCount; ++i) {
        std::cout << "割る数" << (i + 1) << "を入力してください: ";
        std::cin >> divisors[i];
    }

    for (int i = 1; i <= num; ++i) {
        std::string res1, res2;
        int divCount = 0;

        for (int j = 0; j < numCount; ++j) {
            if (i % divisors[j] == 0) {
                if (divCount == 0) {
                    res1 += std::to_string(divisors[j]) + "zz";
                }
                res2 += std::to_string(divisors[j]) + "zz";
                divCount++;
            }
        }

        if (divCount > numCount - 1) {
            std::cout << res2 << std::endl;
        }
        else if (!res1.empty()) {
            std::cout << res1 << std::endl;
        }
    }*/

    return 0;
}

// 数値を受け取り、対応するメッセージを返す関数
std::string fizzBuzz(int number) {
    std::string output;

    if (number % 3 == 0 && number % 5 == 0) {
        output += "fizzbuzz";
    }
    else if (number % 3 == 0) {
        output += "fizz";
    }
    else if (number % 5 == 0) {
        output += "buzz";
    }

    return output;
}

// 数値を受け取り、対応するメッセージを返す関数
std::string fizzBuzztozz(int number) {
    std::string output;

    if (number % 3 == 0 && number % 5 == 0 && number % 10 == 0) {
        output += "fizzbuzztozz";
    }
    else if (number % 3 == 0) {
        output += "fizz";
    }
    else if (number % 5 == 0) {
        output += "buzz";
    }
    else if (number % 10 == 0) {
        output += "tozz";
    }
    return output;
}