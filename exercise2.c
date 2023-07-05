#include <stdio.h>
#include <stdlib.h>


int findNSD(int number_1, int number_2);
int findNSK(int number_1, int number_2);

int main()
{
    int count_of_values = 0; // Оголошення змінної, яка буде отримувати кількість чисел

    printf("How many numbers do you want to input?\n*You can input values from 2 to 20*\nValue: "); // Підказка для користувача, що йому треба ввести
    scanf("%d", &count_of_values);
    while (count_of_values <= 2 || count_of_values >= 20) // Якщо користувач введе невірне значення, то буде переведення до циклу, до поки він не веде вірне значення
    {
        printf("\n!!!Invalid value!!!\n*You can input values from 2 to 20*\nValue:");
        scanf("%d", &count_of_values);
    }
    

    int *numbers =(int*)malloc(count_of_values * sizeof(int)); // Виділення пам'яті для масиву значень, куди будуть записані числа користувача

    printf("Input %d naturals numbers separated by space: ", count_of_values); // Підсказка для користувача, яка запитує кількість чисел, яку користувач задав раніше
    for (int i = 0; i < count_of_values; i++) // Заповнення масиву через цикл
    {
        scanf("%d", &numbers[i]); // Сканування чисел, які введе користувач

        if (numbers[i] <= 0) // Перевірка, чи всі числа підходять до умови, якщо ні - програма завершує роботу
        {
            printf("Invalid input. Please enter positive natural numbers.\n");
            free(numbers);
            return 0;
        }
    }
    
    int lcm = numbers[0]; // Ініціалізація НСК як перше число в масиві

    for (int i = 1; i < count_of_values; i++) // Знаходження НСК через цикл (починається з 2 числа, бо перше ми вже ініціалізували, і будемо переписувати значення, якщо це потрібно)
    {
        lcm = findNSK(lcm, numbers[i]);
    }
    
    printf("Least Common Multiple: %d\n", lcm); // Виведення на екран результату програми

    free(numbers);
    return 0;
}

int findNSD(int number_1, int number_2) // Знаходження найбільшого спільного дільника шляхом рекурсії, в якій базовою умовою є випадок, коли 2 число дорівнює 0
{
    if (number_2 == 0)
    {
        return number_1;
    }
    return findNSD(number_2, number_1 % number_2);
    
}

int findNSK(int number_1, int number_2) // Знаходження найменшого спільного кратного
{
    return (number_1 * number_2) / findNSD(number_1, number_2);
}
