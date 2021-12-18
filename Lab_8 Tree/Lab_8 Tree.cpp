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
void Print_Tree(Tree* Branch);

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
		Print_Tree(root);
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


void Print_Tree(Tree* Branch)
{
	if (Branch == NULL)
	{
		return;
	}
	tabs += 5;
	Print_Tree(Branch->RightBranch);
	for (int i = 0; i < tabs; i++)
	{
		cout << " ";
	}
	cout << Branch->value << endl;
	Print_Tree(Branch->LeftBranch);
	tabs -= 5;
}