#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian");
	int c, nMin, n;// свободный член, номер минимального элемента, количество ячеек в массиве
	char t;
	do
	{
		system("cls");
		cout << "Введите длину массива: ";
		cin >> n;
		int* arr = new int[n];
	    srand(time(NULL));
		for (int i = 0; i < n; ++i)// заполнение массива случайными числами
		{
			arr[i] = rand() % (10-0+1)+0;
		}
		cout << "Созданный массив: ";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << " " << endl;
		int k = 0;
		for (int l = 0; l < n; ++l)
		{
			for (int l1 = l + 1; l1 < n; l1++)
			{
				if (arr[l] == arr[l1]) ++k;
			}
		}
		if (k == 0)// если в массиве нет дубликатов
		{
			cout << "В этом массиве нет дубликатов" << endl;
			for (int i = 0; i < n - 1; ++i)
			{
				nMin = i;
				for (int j = i + 1; j < n; ++j)
				{
					if (arr[j] < arr[nMin]) nMin = j;
				}
				if (nMin != i)
				{
					c = arr[i];
					arr[i] = arr[nMin];
					arr[nMin] = c;
				}
			}
			cout << "Отсортированный массив: ";
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << " " << endl;
		}
		else// если в массиве есть дубликаты
		{
			for (int i = 0; i < n; i++)// дубликаты перемещаем в конец массива и удаляем
			{
				for (int j = i + 1; j < n; j++)
				{
					if (arr[i] == arr[j])
					{
						for (int cout = j; cout < n - 1; cout++)
						{
							arr[cout] = arr[cout + 1];
						}
						--n;
						if (arr[i] == arr[j]) //если >2 дубликатов находятся рядом
						{
							--j;
						}
					}
				}
			}
			cout << "Неотсортированный массив без дубликатов: ";
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << " " << endl;
			for (int i = 0; i < n - 1; ++i)
			{
				nMin = i;
				for (int j = i + 1; j < n; ++j)
				{
					if (arr[j] < arr[nMin]) nMin = j;
				}
				if (nMin != i)
				{
					c = arr[i];
					arr[i] = arr[nMin];
					arr[nMin] = c;
				}
			}
			cout << "Отсортированный массив без дубликатов: ";
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << " " << endl;
		}
		delete[]arr;
		cout << "Хотите еще раз запустить программу?(y/n)";
		cin >> t;
	} while (t == 'y');
	system("pause");
}