#include <iostream>

int minimum_calculation(int* arr)                             // Метод для вычисления минимального значения в массиве
{
	int min = 0;
	for (int i = 0; i < sizeof(arr); i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

void start_and_end_of_range(int m, int& s, int& e, int* arr) // Метод вычисляет начало и конец диапазона 
{                                                            // наибольшей суммы значений подряд.
	int sum = 0;                                             // Начальные значения начала и конца передаём
	                                                         // по ссылке для того чтобы в памяти зафиксировать
	for (int i = 0; i < sizeof(arr); i++)                    // значения вычесленные в методе.
	{
		for (int j = i; j < sizeof(arr); ++j)
		{
			for (int k = j; k >= i; k--)
			{
				sum += arr[k];
			}
			if (sum > m)
			{
				s = i;
				e = j;
				m = sum;
			}
			sum = 0;
		}
	}
}

void show_result(int s, int e, int *arr)                     // Метод для вывода результата в консоль
{
	std::cout << " Наибольшая сумма последовательных элементов находится между индексами " 
		<< s << " и " << e << ": ";
	for (int i = s; i <= e; i++)
	{
		if (i == s)
		{
			std::cout << "{ " << arr[i] << ", ";
		}
		else
		{
			if (i == e)
			{
				std::cout << arr[i] << " };" << std::endl;
			}
			else
			{
				std::cout << arr[i] << ", ";
			}
		}
	}
}

int main()
{
	system("color 80");
	system("chcp 1251>nul");

	int array[]{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };            // Объявляем и инициализируем массив
	int min = minimum_calculation(array);                    // Объявляем и инициализируем переменную значением
	                                                         // наимешим в массиве
	int start = 0;                                           // Объявляеми инициализируем нулём переменую начала
	int end = 0;                                             // Объявляеми инициализируем нулём переменую конца

	start_and_end_of_range(min, start, end, array);          // Передаём методу минимум по значению а старт и енд по ссылке
	show_result(start, end, array);                          // Передаём переменные старт и енд по значению

	system("pause>nul");
    return 0;
}