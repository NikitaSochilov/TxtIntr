# Компилятор C++
CXX = g++

# Флаги компилятора
CXXFLAGS = -Wall -g -std=c++17

# Имя исполняемого файла
TARGET = trigonometric_calculator

# Исходные файлы
SOURCES = trigonometric_calculator.cpp

# Объектные файлы
OBJECTS = $(SOURCES:.cpp=.o)

# Все: сборка исполняемого файла
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
 $(CXX) $(OBJECTS) -o $@

# Сборка объектных файлов
%.o: %.cpp
 $(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка: удаление файлов сборки
clean:
 rm -f $(TARGET) $(OBJECTS)
