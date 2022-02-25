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
    g_type first()
    {
    }
    g_type last()
    {
    }
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
    void reverse()
    {
        if (length == 0)
        {
            cout << "Linkedlist is empty. ";
            return;
        }
        struct Node<g_type> *prev_node = nullptr, *curr_node = head, *next_node = nullptr;
        while (curr_node != nullptr)
        {
            next_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        tail = head;
        head = prev_node;
        delete (curr_node);
        delete (next_node);
    }
};

/* ---------------------------------- TEST ---------------------------------- */
// tester comportement file
void test_queue()
{
    cout << "[!] QUEUE [!]" << endl;
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
    cout << "[!] END QUEUE [!]" << endl;
}
// tester comportement pile
void test_stack()
{
    cout << "[!] STACK [!]" << endl;
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
    cout << "[!] END STACK [!]" << endl;
}
void test_reverse()
{
    cout << "[!] REVERSE [!]" << endl;
    LinkedList<int> list;
    for (int i = 0; i < 10; i++)
        list.enqueue(i);
    list.display();
    list.reverse();
    list.display();
    cout << "[!] END REVERSE [!]" << endl;
}
/* ----------------------------------- end ---------------------------------- */

/* -------------------------  programme principale ------------------------ */
int main()
{
    test_stack();
    test_queue();
    test_reverse();
    return 0;
}