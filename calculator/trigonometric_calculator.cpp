#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// Функция для вычисления тангенса
double tangent(double angle, bool radians) {
  if (radians) {
    return tan(angle);
  } else {
    return tan(angle * M_PI / 180.0); 
  }
}

// Функция для вычисления котангенса
double cotangent(double angle, bool radians) {
  if (radians) {
    return 1.0 / tan(angle);
  } else {
    return 1.0 / tan(angle * M_PI / 180.0); 
  }
}

int main(int argc, char* argv[]) {
  if (argc == 2 && (string(argv[1]) == "--help" || string(argv[1]) == "-h")) {
    cout << "Использование: trigonometric_calculator [операция] [угол] [режим]\n";
    cout << "Операции:\n";
    cout << "1. tangent - тангенс\n";
    cout << "2. cotangent - котангенс\n";
    cout << "Режим:\n";
    cout << "0 - градусы\n";
    cout << "1 - радианы\n";
    return 0;
  }

  if (argc < 2) {
    cerr << "Недостаточно аргументов. Используйте `trigonometric_calculator --help` для справки.\n";
    return 1;
  }

  string operation = argv[1];
  double angle;
  bool radians;

  if (argc < 3) {
    cerr << "Недостаточно аргументов. Используйте `trigonometric_calculator --help` для справки.\n";
    return 1;
  }

  try {
    angle = stod(argv[2]);
  } catch (const std::invalid_argument& e) {
    cerr << "Неверный формат угла. Введите число.\n";
    return 1;
  } catch (const std::out_of_range& e) {
    cerr << "Угол находится вне допустимого диапазона.\n";
    return 1;
  }

  if (argc < 4) {
    cerr << "Недостаточно аргументов. Используйте `trigonometric_calculator --help` для справки.\n";
    return 1;
  }

  try {
    radians = stoi(argv[3]);
  } catch (const std::invalid_argument& e) {
    cerr << "Неверный формат режима. Введите 0 или 1.\n";
    return 1;
  } catch (const std::out_of_range& e) {
    cerr << "Режим должен быть 0 или 1.\n";
    return 1;
  }

  double result;

  if (operation == "tangent") {
    result = tangent(angle, radians);
  } else if (operation == "cotangent") {
    result = cotangent(angle, radians);
  } else {
    cerr << "Неизвестная операция. Используйте `trigonometric_calculator --help` для справки.\n";
    return 1;
  }

  cout << "Результат: " << result << endl;

  return 0;
}
