#include <iostream>
#include <string>
#include <iomanip>
// Будем использовать метод Ньютона потому, что немного недопонимаю Тейлора
// Функция для проверки, является ли строка числом
bool numm(const std::string& str) {
    for (char const &c : str) {
        if (!isdigit(c)) return false; // Проверка на только цифры
    }
    return true;
}

// Функция для вычисления квадратного корня с заданной точностью
std::string calculat(long long m, int precision) {
    // Начальные значения для метода Ньютона
    double x = m;
    double y = (x + 1) / 2;

    // Итеративное вычисление квадратного корня
    while (true) {
        double new_y = (y + m / y) / 2; 
        // Если изменение меньше требуемой точности, выбираем новое значение
        if (std::abs(new_y - y) < 1e-10) {
            y = new_y;
            break; 
        }
        y = new_y; // Обновляем y
    }
    
    // Редачим результат до нужной точности с помощью std::fixed и std::setprecision
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << y; // Устанавливаем необходимую точность
    return out.str(); // Возвращаем результат
}

int main() {
    long long m; // Переменная для хранения целого числа m
    int n; // Переменная для хранения количества знаков n (должно быть >= 50)
    std::string input; // Хранение строк

    // Цикл для ввода неотрицательного целого числа m
    while (true) {
        std::cout << "\nВведите целое неотрицательное число m: ";
        std::cin >> input; // Считываем входные данные

        // Проверка на корректность ввода m
        if (numm(input)) {
            m = std::stoll(input);
            if (m >= 0) // Проверяем, что число неотрицательное
                break; // Если все ок, выходим из цикла
            else 
                std::cout << "Ошибка: число должно быть неотрицательным." << std::endl;
        } else {
            std::cout << "Ошибка: введите корректное целое число." << std::endl;
        }
    }

    // Цикл для ввода количества знаков n после запято й
    while (true) {
        std::cout << "Введите количество знаков n (n >= 50): ";
        std::cin >> input; 

        if (numm(input)) { // Проверка на корректность ввода n
            n = std::stoi(input); // Преобразуем строку в int
            if (n >= 50) // Проверяем, что n >= 50
                break; // Если все ок, то выходим из цикла
            else 
                std::cout << "Ошибка: n должно быть больше или равно 50." << std::endl;
        } else {
            std::cout << "Ошибка: введите корректное целое число." << std::endl;
        }
    }

    std::string sqrt_m = calculat(m, n); // Вычисляем квадратный корень из m с заданной точностью n

    std::cout << "Квадратный корень из " << m << " с " << n << " знаками после запятой: ";
    std::cout << sqrt_m << std::endl; // Выводим результат

    return 0;
}
