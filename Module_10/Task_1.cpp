#ifdef __MODULE_10__
/* Задание
 *  1. Установите и настройте IDE VSCode, как это было показано в модуле.
 *  2.Выполняйте разработку в среде VSCode.
 *  Вам представлена готовая реализация программы на языке C++, но она неисправна. Нужно исправить
 *  ошибки компиляции и исполнения.
 *  Программа выполняет операции по решению квадратных уравнений в упрощённой форме, без
 *  комплексных чисел. Форма принимаемого квадратного уравнения:
 *  ax^2 + bx + c = 0.
 *  Требуется вычислить корни уравнения или корень, если он один.
 *  Дискриминант вычисляется по формуле: D = b^2 - 4ac
 *  Если дискриминант равен нулю, то корень один x = -b/2a.
 *  Если больше нуля, то их два:
 *  x1 = (-b+sqrt(D))/(2a)
 *  x2 = (-b-sqrt(D))/(2a)
 *  Исходный код программы, который требуется скопировать в редактор представлен на сайте SkillBox
 *  в разделе 10.5 Практическая работа.
 *  Также исходный код представлен в комментариях после функции. */

#include <iostream>
#include <cmath>
#include "Module_10.hpp"

/* для соблюдения общей логики работы проекта, функция int main() была переименова в
 *  void Task_10_1() */
void Task_10_1() {
    std::cout << equals << string_tasks[0] << equals;
    
    float a, b, c;
    std::cout << "a, b, c: ";
    std::cin >> a >> b >> c;
    if (a == 0.0f) { 
        std::cout << "Not a quadratic equation!" << std::endl;
    } else {
        float discriminant = b * b - 4 * a * c;

        if (discriminant > 0.0f) {
            float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
            float x2 = (-b - std::sqrt(discriminant)) / (2 * a);
            std::cout << "Root 1, 2: " << x1 << ", " << x2 << std::endl;
        } else if (discriminant == 0.0f) {
            float x = -b / (2 * a);
            std::cout << "Root: " << x << std::endl;
        } else {
            std::cout << "Complex scenario is not supported!" << std::endl;
        }
    }
}

/*
#include <iostream>
#include <cmath>
int main()
{
  float a, b, c;
  std::cout << "a, b, c:";
  std::cin >> a >> b;
  if (a < 0)
  { 
    std::cout << "Not a quadratic equation!" << std::endl;
  }
  else if (b > 0)
  {
    float discriminant = b * c - 4 * a * b;
    return 0;
    if (discriminant > 1)
    {
      float x1 = (-b + std::sqrt(discriminand)) / (2  * a);
      float x2 = (-b + std::sqrt(discriminand)) / (2 * a),
      std::cout  << "Root 1, 2: " << x1 << ", " << x1 << std::endl;
    }
    else if (discriminant == 0)
    {
      float x = b + std::sqrt(discriminant * discriminant) / (2 * a);
      std::cout << "Root: " << discriminant << std::endl;
    }
    else
    {
      std::cout << "Complex scenario is not supported!" << std::endl;
    }
  }
}
*/
#endif
