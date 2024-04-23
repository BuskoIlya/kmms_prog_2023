#include <random>

#include "school_division_item.hpp"

namespace alicee{
    unsigned int get_random_divider(); // Делитель
    unsigned int get_random_divisible(unsigned int divider); // Делимое
    unsigned int *get_task(unsigned int *arr);
    std::random_device rd;
    std::mt19937 mt_rand(rd());
}


namespace IBusko {
    SchoolDevisionItem::SchoolDevisionItem(
            const char* const title,
            const MenuItem* parent
    ) : MenuItem(title, parent) {}

    const MenuItem* SchoolDevisionItem::execute() const {

        std::cout << "Деление — возможно, самое сложное действие для ученика начальной школы \n";
        std::cout << "Рассмотрим базовые термины: \n";
        std::cout << "\tДелимое" << "  - это число, которое подвергают делению. \n";
        std::cout << "\tДелитель" << " - это число, которым делят: оно указывает, на сколько равных частей нужно разделить делимое. \n";
        std::cout << "\tЧастное" << "  - это результат деления. Если умножить частное на делитель, получится делимое. \n\n";

        std::cout << "Сейчас на экране появятся 2 целых числа. Твоя задча найти частное от деления одного на другое.";

        bool repeat_same_task_flag = 0;
        int user_input;
        unsigned int *task = new unsigned int[3];
        unsigned int ans;

        do{
            if (!repeat_same_task_flag) {
                task = alicee::get_task(task);
                ans = task[2];
            }

            std::cout << std::endl << "Чему равно частное - " << task[0] << " : " << task[1] << " = ?" << std::endl;
            std::cout << "Для выхода из модуля деления введи 0: " << std::endl;
            std::cin >> user_input;

            if(user_input != ans && user_input != 0){
                std::cout << "Неверный ответ!" << std::endl;
                std::cout << "1 - Перерешать тот же пример" << std::endl;
                std::cout << "0 - Хочу новый пример!" << std::endl;
                int choice;
                do{
                    std::cout << "Ваш выбор: ";
                    std::cin >> choice;
                }
                while(abs(choice) > 1);
                repeat_same_task_flag = choice;
            }else if(user_input == ans && user_input != 0){
                std::cout << "Ответ Верный!" << std::endl;
                std::cout << "Держи еще один пример!" << std::endl;
                repeat_same_task_flag = 0;
            }


        }while(user_input != 0);
        delete[] task;
        std::cout << std::endl;
        return parent->get_parent();
    }
}

namespace alicee{
    unsigned int get_random_divider(){
        std::uniform_int_distribution<> distribution_divider(4,30);
        return distribution_divider(mt_rand);
    }

    unsigned int get_random_divisible(unsigned int divider) {
        std::uniform_int_distribution<> distribution_divisible(2,14);
        return distribution_divisible(mt_rand) * divider;
    }

    unsigned int *get_task(unsigned int *arr){
        arr[1] = get_random_divider();
        arr[0] = get_random_divisible(arr[1]);
        arr[2] = arr[0] / arr[1];
        return arr;
    }
}