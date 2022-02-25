#include <iostream>

using namespace std;

/* ----------------------------- structure noeud ---------------------------- */
template <class g_type> // type generique pour les noeuds (generique = variable)
struct Node
{
    // attribues
    g_type value;
    Node *next;
    // initialiser un noeud (creation) a vide
    Node()
    {
        value = 0;
        next = nullptr;
    }
    // initialiser un noeud (creation) avec des arguments
    Node(g_type v, Node *n)
    {
        value = v;
        next = n;
    }
};

/* ------------------- structure list simplement chainee ------------------- */
template <class g_type>
struct LinkedList
{
    // attribues
    struct Node<g_type> *head;
    struct Node<g_type> *tail;
    size_t length;
    // initialiser la list (creation)
    LinkedList()
    {
        head = tail = nullptr;
        length = 0;
    }
    // afficher la list
    void display()
    {
        if (length == 0)
        {
            cout << "Empty." << endl;
            return;
        }
        struct Node<g_type> *itr_node = head;
        while (itr_node != nullptr)
        {
            cout << itr_node->value << " ";
            itr_node = itr_node->next;
        }
        cout << endl;
        delete (itr_node);
    }
    /* ---------------------------- comportement FILE --------------------------- */
    void enqueue(g_type value)
    {
        struct Node<g_type> *temp_node = new Node<g_type>(value, nullptr);
        if (tail == nullptr)
        {
            head = temp_node;
            tail = temp_node;
            return;
        }
        tail->next = temp_node;
        tail = tail->next;
        length++;
    }
    g_type dequeue()
    {
        if (length == 0)
        {
            cout << "Linkedlist is empty. ";
            return 0;
        }
        g_type v = head->value;
        struct Node<g_type> *temp_node = head;
        head = head->next;
        delete (temp_node);
        return v;
    }
    /* ----------------------------------- end ---------------------------------- */

    /* ---------------------------- comportement PILE --------------------------- */
    void push(g_type value)
    {
        struct Node<g_type> *temp_node = new Node<g_type>(value, head);
        head = temp_node;
        length++;
    }
    g_type top()
    {
        if (length == 0)
        {
            cout << "Linkedlist is empty. ";
            return 0;
        }
        return head->value;
    }
    g_type pop()
    {
        if (length == 0)
        {
            cout << "Linkedlist is empty. ";
            return 0;
        }
        g_type v = head->value;                // conserver la valeur de l'element a supprimer.
        struct Node<g_type> *temp_node = head; // conserver le noeud a supprimer pour le supprimer de la memoire.
        head = head->next;
        delete (temp_node);
        length--;
        return v;
    }
    /* ----------------------------------- end ---------------------------------- */
};

/* ---------------------------------- TEST ---------------------------------- */
// tester comportement file
void test_queue()
{
    LinkedList<int> list;
    list.display();
    for (int i = 0; i < 10; i++)
    {
        cout << "enqueuing: " << i << endl;
        list.enqueue(i);
        list.display();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "dequeuing -> " << list.dequeue() << endl;
        list.display();
    }
}
// tester comportement pile
void test_stack()
{
    LinkedList<int> list;
    list.display();
    for (int i = 0; i < 10; i++)
    {
        cout << "pushing: " << i << endl;
        list.push(i);
        list.display();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "poping -> " << list.pop() << endl;
        list.display();
    }
}
/* ----------------------------------- end ---------------------------------- */

/* -------------------------  programme principale ------------------------ */
int main()
{
    // test_stack();
    test_queue();

    return 0;
}