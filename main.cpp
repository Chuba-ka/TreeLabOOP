#include <iostream>
#include <string>

#include "Array.h"
#include "Figure.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Octagon.h"

int main()
{
    Array figures;
    std::string command;

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
            try
            {
                figures.add(fig);
                std::cout << "Фигура добавена\n";
            }
            catch (const std::out_of_range &e)
            {
                std::cout << e.what() << "\n";
                delete fig;
            }
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
            std::cout << "Общая площадь: " << figures.totalArea() << "\n";
        }
        else if (command == "удалить")
        {
            size_t index;
            std::cout << "Введите индекс для удаления: ";
            std::cin >> index;
            try
            {
                figures.remove(index);
                std::cout << "Фигура удалена\n";
            }
            catch (const std::out_of_range &e)
            {
                std::cout << e.what() << "\n";
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

    return 0;
}