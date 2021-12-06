/*Составить программу поиска минимального элемента, расположенного под главной
диагональю, и максимального элемента, расположенного над главной диагональю заданной
целочисленной матрицы А(n*n).*/

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int chek = 1;
	while (chek == 1)
	{
		cout << "Выберите действие (1 - расчёт, 0 - остановка)" << endl;
		cin >> chek;
		switch (chek)
		{
		case(0):
		{
			cout << "Программа завершена" << endl;
			break;
		}
		case(1):
		{
			int i, j,size;
			cout << "Введите размер двумерного квадратного массива ";
			cin >> size;
			cout << endl;
			int** arr = new int*[size];// создаём динамический массив
			for (i = 0; i < size; i++)
				arr[i] = new int[size];
			
			
			srand(time(NULL)); // база, для того чтобы послед. была разной
			

			for ( i = 0; i < size; i++)// заполнение масива рандомными цифрами в промежутке от 0 до 100
			{
				for (j = 0; j < size; j++)
				{
					arr[i][j] = rand() % 100;
				}
			}
				
			cout << "Массив:" << endl;
			for (i = 0; i < size; i++) {// вывод массива
				for (j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			int max = arr[0][1]; // Присваеваем максимальное значенте эл. с индексом [0][1]
			for (int i = 0; i < size - 1; i++) // Сравниваем с эл. выше гл. диагонали
				for (int j = i + 1; j < size; j++)
					if (max < arr[i][j]) // Если находим эл. больше, то присваеваем max его занчение
						max = arr[i][j];
			cout << "Максимальный элемент над главной диагональю " << max << endl;
			int min = arr[1][0];// Присваеваем минимальное значенте эл. с индексом [1][0]
			for (i =  1; i < size; i++) // Сравниваем с эл. ниже гл. диагонали
				for (j = 0; j < i; j++) 
					if (arr[i][j] < min) // Если находим эл. меньше, то присваеваем min его занчение
						min = arr[i][j];
							
			cout << "Минимальный элемент под главной диагональю "<< min << endl;
			for (int i= 0; i < size; i++) // Удаление динамического двумерного массива
				delete[] arr[i];
			delete[]arr;
			break;
		}

		default:
		{
			cout << "Неправильно введеные данные" << endl;
			chek = 1;
			continue;
		}

		}

	}
}
