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

void Add_Branch(struct Tree*& Branch, int value);
void Print_Tree(struct Tree* Branch);
Tree* Delete_Tree(struct Tree* Branch);

int main()
{
	setlocale(0, "");

	Tree* root = NULL;
	int value;
	int cin_menu = 0;

menu:
	cout
		<< "1 - Добавление в дерево;\n"
		<< "2 - Вывод дерева;\n"
		<< "3 - Срубить дерево;\n"
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
			if (root == NULL)
			{
				cout << "\n\t\tВыводить нечего!\n\n";
			}
			else
			{
				system("cls");
				cout << "\n\n\n";
				Print_Tree(root);
				cout << "\n\t\tВывод завершен!\n\n";
			}
			system("pause");
			system("cls");
			goto menu;
		}

		case 3:
		{
			if (root == NULL)
			{
				cout << "\n\t\tУдалять нечего!\n\n";
			}
			else
			{
				root = Delete_Tree(root);
				cout << "\n\t\tДерево удалено!\n\n";
			}
			system("pause");
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


void Add_Branch(struct Tree*& Branch, int value)
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
	

void Print_Tree(struct Tree* Branch)
{
	if (Branch == NULL)
	{
		return;
	}
	tabs += 1;
	Print_Tree(Branch->RightBranch);
	for (int i = 0; i < tabs; i++)
	{
		cout << "\t";
	}
	cout << Branch->value << endl;
	Print_Tree(Branch->LeftBranch);
	tabs -= 1;
}

Tree* Delete_Tree(struct Tree* Branch)
{
	if (Branch == NULL)
	{
		return 0;
	}
	Delete_Tree(Branch->RightBranch);
	
	Delete_Tree(Branch->LeftBranch);
	delete Branch;
	Branch = NULL;
	return Branch;
}