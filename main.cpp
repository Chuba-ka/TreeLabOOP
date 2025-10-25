#include <iostream>
#include <vector>
#include "Figure.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Octagon.h"

int main()
{
    std::vector<Figure *> figures;
    std::string command;
    double total_area = 0.0;

    while (true)
    {
        std::cout << "Введите команду (добавить, вывести, общая_площадь, удалить, выход): ";
        std::cin >> command;

        if (command == "добавить")
        {
            std::cout << "Введите тип фигуры (треугольник, шестиугольник, восьмиугольник): ";
            std::string type;
            std::cin >> type;

            Figure *fig = nullptr;
            if (type == "треугольник")
            {
                fig = new Triangle();
            }
            else if (type == "шестиугольник")
            {
                fig = new Hexagon();
            }
            else if (type == "восьмиугольник")
            {
                fig = new Octagon();
            }
            else
            {
                std::cout << "Неизвестный тип фигуры\n";
                continue;
            }

            std::cin >> *fig;
            figures.push_back(fig);
            std::cout << "Фигура добавлена\n";
        }
        else if (command == "вывести")
        {
            for (size_t i = 0; i < figures.size(); ++i)
            {
                std::cout << "Фигура " << i << ":\n";
                std::cout << *figures[i];
                auto center = figures[i]->geometricCenter();
                std::cout << "Геометрический центр: (" << center.first << ", " << center.second << ")\n";
                std::cout << "Площадь: " << double(*figures[i]) << "\n\n";
            }
        }
        else if (command == "общая_площадь")
        {
            total_area = 0.0;
            for (const auto &fig : figures)
            {
                total_area += double(*fig);
            }
            std::cout << "Общая площадь: " << total_area << "\n";
        }
        else if (command == "удалить")
        {
            size_t index;
            std::cout << "Введите индекс для удаления: ";
            std::cin >> index;
            if (index < figures.size())
            {
                delete figures[index];
                figures.erase(figures.begin() + index);
                std::cout << "Фигура удалена\n";
            }
            else
            {
                std::cout << "Неверный индекс\n";
            }
        }
        else if (command == "выход")
        {
            break;
        }
        else
        {
            std::cout << "Неизвестная команда\n";
        }
    }

    for (auto &fig : figures)
    {
        delete fig;
    }

    return 0;
}