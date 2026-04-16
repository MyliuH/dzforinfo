#include <iostream>
#include <locale>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int v, Node* l, Node* r) 
	{
		value = v;
		left = l;
		right = r;
	}
};

Node* CreateList(int* A, int n) 
{
	Node* head = new Node(A[0], NULL, NULL);
	Node* prev = head;

	for (int i = 1; i < n; i++) 
	{
		Node* temp = new Node(A[i], prev, NULL);
		prev->right = temp;
		prev = temp;
	}

	return head;
}

void PrintList(Node* head) 
{
	if (head == NULL) return;

	if (head->left != NULL)
	{
		printf("<-");
	}

	printf("%d",head->value);

	if (head->right != NULL) 
	{
		printf("->");
		PrintList(head->right);
	}

}

Node* SortList_(Node* head) 
{
	if (head == NULL) return NULL;

	bool changed = true;

	while (changed)
	{
		if (changed == true) changed = false;

		Node* temp = head;

		while (temp->right != NULL)
		{
			if (temp->value > temp->right->value)
			{
				int tempValue = temp->value;
				temp->value = temp->right->value;
				temp->right->value = tempValue;
				changed = true;
			}

			temp = temp->right;
		}
	}

	return head;
}

Node* SortList(Node* head, int n)
{
	if (head == NULL) return NULL;

	for (int i = 0; i < n; i++) 
	{
		Node* temp = head;

		while (temp->right != NULL)
		{
			if (temp->value > temp->right->value)
			{
				int tempValue = temp->value;
				temp->value = temp->right->value;
				temp->right->value = tempValue;
			}

			temp = temp->right;
		}
	}

	return head;
}

void ClearList(Node* head)
{
	if (head == NULL) return;

	if (head->right != NULL) ClearList(head->right);

	delete head;
}

int main() 
{
	setlocale(LC_ALL, "ru");
	int A[5] = { 2, 5, 4, 1, 3 };

	printf("Массив: ");

	for (int i = 0; i < 5; i++) 
	{
		printf("%d ",A[i]);
	}
	printf("\n");

	Node* head1 = CreateList(A, 5);
	Node* head2 = CreateList(A, 5);

	printf("Список: ");
	PrintList(head1);
	printf("\n");

	head1 = SortList(head1,5);

	printf("Отсортированный список: ");
	PrintList(head1);
	printf("\n");

	head2 = SortList_(head2);

	printf("Отсортированный список: ");
	PrintList(head2);
	printf("\n");

	ClearList(head2);
	ClearList(head1);
}
