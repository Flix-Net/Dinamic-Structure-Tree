#include <iostream>
using namespace std;

int tabs = 0; //Для создания отступов
int kol_vo = 0;
//Кол-во отступов высчитывается по кол-ву рекурсивного вхождения при выводе в фукцию print

//Структура ветки
struct Tree
{
	int value; //Поле данных
	Tree* LeftBranch; //УКАЗАТЕЛИ на соседние веточки
	Tree* RightBranch;
};

void Add_Branch(Tree*& Branch, int value);
void Print(Tree* Branch);

int main()
{
	setlocale(0, "");

	Tree* root = NULL;
	int value;
	int cin_menu = 0;

	menu:
	cout
		<< "1 - Добавление в дерево;\n"
		<< "2 - Вывод  дерева;\n"
		<< "Выбор: ";
	cin >> cin_menu;
	

	switch (cin_menu)
	{
		case 1:
		{
			cout << "Введите значение: "; cin >> value;
			Add_Branch(root, value);
			cout << "\n\t\tДобавление выполнено!\n\n";
			system("pause");
			system("cls");
			goto menu;
		}

		case 2:
		{
			Print(root);
			system("pause");
			cout << "\n\t\tВывод завершен!\n\n";
			system("cls");
			goto menu;
		}

		default:
		{
			cout << "Происходит выход...\n\n";
		}
	}
		




	return 0;
}

//Функция внесения данных
void Add_Branch(Tree*& Branch, int value)
{
	if (Branch == NULL)
	{
		Branch = new (Tree);
		Branch->value = value;
		Branch->LeftBranch = NULL;
		Branch->RightBranch = NULL;
		return;
	}
	else 
	{
		if (value < Branch->value)
		{
			Add_Branch(Branch->LeftBranch, value);
		}
		else
		{
			Add_Branch(Branch->RightBranch, value);
		}
	}
}

//Функция вывода дерева
void Print(Tree* Branch)
{
	if (!Branch) return; //Если ветки не существует - выходим. Выводить нечего
	tabs += 5; //Иначе увеличим счетчик рекурсивно вызванных процедур
	//Который будет считать нам отступы для красивого вывода

	Print(Branch->LeftBranch); //Выведем ветку и ее подветки слева

	for (int i = 0; i < tabs; i++) cout << " "; //Потом отступы
	cout << Branch->value << endl; //Данные этой ветки

	Print(Branch->RightBranch);//И ветки, что справа

	tabs -= 5; //После уменьшим кол-во отступов
}