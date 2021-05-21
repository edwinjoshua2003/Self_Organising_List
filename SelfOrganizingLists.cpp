/*
 * C++ Program to Implement Self Organising List 
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
 * Node Declaration
 */
struct node
{
    char info;
    int ctr;
    struct node *next;
} *start;

/*
 * Class Declaration
 */
class Self_List
{

public:
    node *CreateNode(char);
    void InsertLast(char);
    void InsertBegin(char);
    void DeletePos(int);
    void display();
    void sort();
    void MoveToFront();
    int search(char);
    void transpose();
    void count();

    Self_List()
    {
        start = NULL;
    }
};

/*
 * Main :contains menu 
 */
int main()
{
    int ch, pos;
    char element;
    Self_List sl;
    start = NULL;

    while (1)
    {
        cout << endl
             << "------------------------------------" << endl;
        cout << endl
             << "Operations on Self Organising list" << endl;
        cout << endl
             << "------------------------------------" << endl;

        cout << "1. Insert Node at first" << endl;
        cout << "2. Insert Node at last" << endl;
        cout << "3. Delete a Particular Node" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Move To Front Organising List" << endl;
        cout << "6. Transpose Organising List" << endl;
        cout << "7. Count Organising List" << endl;
        cout << "8. Exit " << endl;
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Inserting Element at first" << endl;
            cout << "Enter the character to be inserted: ";
            cin >> element;
            sl.InsertBegin(element);
            cout << endl;
            break;
        case 2:
            cout << "Inserting Element at last" << endl;
            cout << "Enter the character to be inserted: ";
            cin >> element;
            sl.InsertLast(element);
            cout << endl;
            break;
        case 3:
            cout << "Deleteing element at a given position" << endl;
            cout << "Enter the position of element to be deleted: ";
            cin >> pos;
            sl.DeletePos(pos);
            cout << endl;
            break;
        case 4:
            cout << "Display elements of link list" << endl;
            sl.display();
            cout << endl;
            break;
        case 5:
            cout << "Move To Front Organising List" << endl;
            sl.MoveToFront();
            cout << endl;
            break;
        case 6:
            cout << "Transpose Organising List" << endl;
            sl.transpose();
            cout << endl;
            break;
        case 7:
            cout << "Count Organising List" << endl;
            sl.count();
            cout << endl;
            break;
        case 8:
            cout << "Exiting..." << endl;
            exit(1);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}

/*
 * Creating Node
 */
node *Self_List::CreateNode(char val)
{
    struct node *temp;
    struct node *new_node;
    temp = new (struct node);

    if (temp == NULL)
    {
        cout << "Memory not allocated " << endl;
        return 0;
    }
    else
    {
        temp->info = val;
        temp->next = NULL;
        temp->ctr = 0;
        return temp;
    }
}

/*
 * Inserting Node at last
 */
void Self_List::InsertLast(char val)
{
    struct node *temp, *s;
    temp = CreateNode(val);

    if (start == NULL)
    {
        start = temp;
        return;
    }

    s = start;

    while (s->next != NULL)
    {
        s = s->next;
    }

    temp->next = NULL;
    s->next = temp;
    cout << "Element Inserted" << endl;
}

/*
 * Inserting Node at beginning
 */
void Self_List::InsertBegin(char val)
{
    struct node *temp, *p;
    temp = CreateNode(val);

    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
}

/*
 * Delete element at a given position
 */
void Self_List::DeletePos(int pos)
{
    int i, key = 0;
    
    if (start == NULL)
    {
        return;
    }

    struct node *s, *ptr;
    s = start;

    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            key++;
        }

        if (pos > 0 && pos <= key)
        {
            s = start;
            for (i = 1; i < pos; i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }

        free(s);
    }
}

/*
 * Searching an element
 */
int Self_List::search(char val)
{
    int pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        return 0;
    }

    struct node *s;
    s = start;

    while (s != NULL)
    {
        pos++;
        if (s->info == val)
        {
            flag = true;
            return pos;
        }
        s = s->next;
    }

    if (!flag)
    {
        return 0;
    }        
}

/*
 * Sorting Link List
 */
void Self_List::sort()
{
    struct node *ptr, *s;
    int val, temp;

    if (start == NULL)
    {
        return;
    }

    ptr = start;

    while (ptr != NULL)
    {
        for (s = ptr->next; s != NULL; s = s->next)
        {
            if (ptr->ctr < s->ctr)
            {
                val = ptr->info;
                temp = ptr->ctr;
                ptr->info = s->info;
                ptr->ctr = s->ctr;
                s->info = val;
                s->ctr = temp;
            }
        }
        ptr = ptr->next;
    }
}

/*
 * Display Elements
 */
void Self_List::display()
{
    struct node *temp;

    if (start == NULL)
    {
        cout << "The List is Empty, nothing to display" << endl;
        return;
    }

    temp = start;

    while (temp != NULL)
    {
        cout << temp->info << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/*
 * Move To Front Self Organizind List
 */
void Self_List::MoveToFront()
{
    if (start == NULL)
    {
        cout << "The List is Empty, first create the list" << endl;
        return;
    }

    char stream[100001];
    cout << "Enter the string of elements searched" << endl;
    cin >> stream;
    int len, pos;
    len = strlen(stream);

    for (int i = 0; i < len; i++)
    {
        if (search(stream[i]) != 0)
        {
            if (search(stream[i]) != 1)
            {
                pos = search(stream[i]);
                DeletePos(pos);
                InsertBegin(stream[i]);
            }
            cout << stream[i] << ": ";
            display();
        }
    }
}

/*
 * Transpose Self Organizind List
 */
void Self_List::transpose()
{
    if (start == NULL)
    {
        cout << "The List is Empty, first create the list" << endl;
        return;
    }

    char stream[100001];
    cout << "Enter the string of elements searched" << endl;
    cin >> stream;
    int len, pos, temp;
    len = strlen(stream);
    struct node *s;

    for (int i = 0; i < len; i++)
    {
        s = start;
        if (search(stream[i]) != 0)
        {
            if (search(stream[i]) != 1)
            {
                pos = search(stream[i]);
                for (int j = 1; j < pos - 1; j++)
                {
                    s = s->next;
                }
                temp = s->info;
                s->info = s->next->info;
                s->next->info = temp;
            }
            cout << stream[i] << ": ";
            display();
        }
    }
}

/*
 * Count Self Organizind List
 */
void Self_List::count()
{
    if (start == NULL)
    {
        cout << "The List is Empty, first create the list" << endl;
        return;
    }

    char stream[100001];
    cout << "Enter the string of elements searched" << endl;
    cin >> stream;
    int len, pos;
    len = strlen(stream);
    struct node *s;

    for (int i = 0; i < len; i++)
    {
        s = start;
        if (search(stream[i]) != 0)
        {
            pos = search(stream[i]);
            for (int j = 0; j < pos - 1; j++)
            {
                s = s->next;
            }
            (s->ctr)++;
            sort();
            cout << stream[i] << ": ";
            display();
        }
    }
}