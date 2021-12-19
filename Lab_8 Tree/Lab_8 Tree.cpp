#include <iostream>
using namespace std;

int tabs = 0; //Кол-во отступов



//Структура ветки
struct Tree
{
	int value; //Поле данных
	Tree* LeftBranch; //УКАЗАТЕЛЬ на левую веточку
	Tree* RightBranch; //УКАЗАТЕЛЬ на правую веточку
};

void Add_Branch(struct Tree*& Branch, int value, int &count);
void Print_Tree(struct Tree* Branch);
Tree* Delete_Tree(struct Tree* Branch);
void Preorder(struct Tree* Branch);
void Postorder(struct Tree* Branch);
void Inorder(struct Tree* Branch);
void Count_Leaf(struct Tree* Branch, int& count_leaf);
int Level(struct Tree* Branch);
void Find_Value(struct Tree* Branch, int value);
void Find_Parent(struct Tree* Branch, int value);

int main()
{
	setlocale(0, "");

	Tree* root = NULL;
	int value;
	int count_value = 0, count_leaf = 0;
	int* pcount_value = &count_value, *pcount_leaf = &count_leaf;
	int cin_menu = 0;

menu:
	cout
		<< "1 - Добавление в дерево;\n"
		<< "2 - Вывод дерева;\n"
		<< "3 - Срубить дерево;\n"
		<< "4 - Обходы дерева;\n"
		<< "5 - Поиск в дереве;\n"
		<< "Выбор: ";
	cin >> cin_menu;


	switch (cin_menu)
	{
	case 1:
	{
		cout << "Введите значение: "; cin >> value;
		Add_Branch(root, value,*pcount_value);
		/*cout << "\n\t\tДобавление выполнено!\n\n";
		system("pause");*/
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
			count_leaf = 0;
			Count_Leaf(root, *pcount_leaf);
			cout << "\n\t\tКол-во узлов   в дереве: " << count_value;
			cout << "\n\t\tКол-во листьев в дереве: " << count_leaf;
			cout << "\n\t\tКол-во уровней в дереве: " << Level(root);
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
			count_value = 0;
			cout << "\n\t\tДерево удалено!\n\n";
		}
		system("pause");
		system("cls");
		goto menu;
	}

	case 4:
	{
		if (root == NULL)
		{
			cout << "\n\t\tОбходить нечего!\n\n";
		}
		else
		{
			cout << "\nПоследовательный (Inorder) = ";
			Inorder(root);
			cout << "\nНисходящий      (Preorder) = ";
			Preorder(root);
			cout << "\nВосходящий     (Postorder) = ";
			Postorder(root);
			cout << endl << endl;
		}
		system("pause");
		system("cls");
		goto menu;
	}

	case 5:
	{
		if (root == NULL)
		{
			cout << "\n\t\tСоздайте дерево!\n\n";
		}
		else
		{
			cout << "Введите значение: "; cin >> value;
			Find_Value(root, value);
		}
		cout << endl; system("pause");
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


void Add_Branch(struct Tree*& Branch, int value, int &count_value)
{
	if (Branch == NULL)
	{
		Branch = new (Tree);
		Branch->value = value;
		Branch->LeftBranch = NULL;
		Branch->RightBranch = NULL;
		count_value++;
		return;
	}
	else
	{
		if (value == Branch->value)
		{
			cout << "\n\t\tТакое значение уже есть в дереве!\n\n";
			system("pause");
			return;
		}
		else
		{
			if (value < Branch->value)
			{
				Add_Branch(Branch->LeftBranch, value, count_value);
			}
			else
			{
				Add_Branch(Branch->RightBranch, value, count_value);
			}
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

void Preorder(struct Tree* Branch)
{
	if (Branch == NULL)
	{
		return;
	}
	cout << Branch->value << " ";
	Preorder(Branch->LeftBranch);
	Preorder(Branch->RightBranch);
}

void Postorder(struct Tree* Branch)
{
	if (Branch == NULL)
	{
		return;
	}
	else
	{
		Postorder(Branch->LeftBranch);
		Postorder(Branch->RightBranch);
		cout << Branch->value << " ";
	}
}

void Inorder(struct Tree* Branch)
{
	if (Branch == NULL)
	{
		return;
	}
	else
	{
		Inorder(Branch->LeftBranch);
		cout << Branch->value << " ";
		Inorder(Branch->RightBranch);
	}
}

void Count_Leaf(struct Tree* Branch, int &count_leaf)
{
	if (Branch == NULL)
	{
		return;
	}
	if (Branch->LeftBranch == NULL and Branch->RightBranch == NULL)
	{
		count_leaf++;
		return;
	}
	Count_Leaf(Branch->RightBranch, count_leaf);
	Count_Leaf(Branch->LeftBranch, count_leaf);
}

int Level(struct Tree* Branch)
{
	if (Branch == NULL)
	{
		return 0;
	}
	else
	{
		if (Branch->LeftBranch == NULL && Branch->RightBranch == NULL)
		{
			return 0;
		}
		else
		{
			if (Level(Branch->LeftBranch) > Level(Branch->RightBranch)) 
			{
				return Level(Branch->LeftBranch) + 1;
			}
			else
			{
				return Level(Branch->RightBranch) + 1;
			}
		}
	}
}

void Find_Value(struct Tree* Branch, int value)
{
	if (Branch == NULL)
	{
		cout << "\n\t\tУказанное значение не найдено!\n\n";
		return;
	}
	if (value == Branch->value)
	{
		cout << "\n\t\tBranch->value  = " << Branch->value << endl;
		if (Branch->LeftBranch != NULL)
		{
			cout << "\n\t\tBranch->LeftBranch   = " << Branch->LeftBranch->value << endl;
		}
		if (Branch->RightBranch != NULL)
		{
			cout << "\n\t\tBranch->RightBranch  = " << Branch->RightBranch->value << endl;
		}
		return;
	}
	if (value > Branch->value)
	{
		Find_Parent(Branch, value);
		Find_Value(Branch->RightBranch, value);
	}
	else
	{
		Find_Parent(Branch, value);
		Find_Value(Branch->LeftBranch, value);
	}
}

void Find_Parent(struct Tree* Branch, int value)
{
	if (Branch->RightBranch != NULL)
	{
		if (Branch->RightBranch->value == value)
		{
			cout << "\n\t\tРодитель  = " << Branch->value << endl;
		}
	}

	if (Branch->LeftBranch != NULL)
	{
		if (Branch->LeftBranch->value == value)
		{
			cout << "\n\t\tРодитель  = " << Branch->value << endl;
		}
	}
}


