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
    Node<g_type> *head;
    Node<g_type> *tail;
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
        Node<g_type> *itr_node = head;
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
        if (length == 0)
        {
            cout << "Linkedlist is empty. ";
            return 0;
        }
        return head->value;
    }
    g_type last()
    {
        if (length == 0)
        {
            cout << "Linkedlist is empty. ";
            return 0;
        }
        return tail->value;
    }
    void enqueue(g_type value)
    {
        Node<g_type> *temp_node = new Node<g_type>(value, nullptr);
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
        Node<g_type> *temp_node = head;
        head = head->next;
        delete (temp_node);
        return v;
    }
    /* ----------------------------------- end ---------------------------------- */

    /* ---------------------------- comportement PILE --------------------------- */
    void push(g_type value)
    {
        Node<g_type> *temp_node = new Node<g_type>(value, head);
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
        g_type v = head->value;         // conserver la valeur de l'element a supprimer.
        Node<g_type> *temp_node = head; // conserver le noeud a supprimer pour le supprimer de la memoire.
        head = head->next;
        delete (temp_node);
        length--;
        return v;
    }
    /* ----------------------------------- end ---------------------------------- */
    void reverse_itr()
    {
        if (length == 0)
        {
            cout << "Linkedlist is empty. ";
            return;
        }
        Node<g_type> *prev_node = nullptr, *curr_node = head, *next_node = nullptr;
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

    void reverse_rec()
    {
        reverse(head);
    }

    Node<g_type> *reverse(Node<g_type> *curr_head)
    {
        if (curr_head == nullptr)
            return nullptr;
        if (curr_head->next == nullptr)
        {
            head = curr_head;
            return curr_head;
        }
        Node<g_type> *node1 = reverse(curr_head->next);
        node1->next = curr_head;
        curr_head->next = nullptr;
        return curr_head;
    }
    /* -------------------------------- recherche ------------------------------- */
    Node<g_type> *find_node(g_type value)
    {
        Node<g_type> *temp_node = head;
        while (temp_node != nullptr)
        {
            if (temp_node->value == value)
                return temp_node;
            temp_node = temp_node->next;
        }
        return nullptr;
    }
    // indice de la 1ere occurence d'un element
    int
    first_index(g_type value)
    {
        if (length != 0)
        {
            int index = 0;
            Node<g_type> *temp_node = head;
            while (temp_node != nullptr)
            {
                if (temp_node->value == value)
                    return index;
                index++;
                temp_node = temp_node->next;
            }
            delete (temp_node);
        }
        return -1;
    }
    // indice de la derniere occurence d'un element
    int last_index(g_type value)
    {
        int target_index = -1;
        if (length != 0)
        {
            int index = 0;
            Node<g_type> *temp_node = head;
            while (temp_node != nullptr)
            {
                if (temp_node->value == value)
                {
                    target_index = index;
                }
                index++;
                temp_node = temp_node->next;
            }
            delete (temp_node);
        }
        return target_index;
    }
    /* ----------------------------------- end ---------------------------------- */

    /* ------------------------------- suppression ------------------------------ */
    // supprimer 1ere occurrence d'un element
    void delete_first(g_type element)
    {
        if (length == 0)
            return;
        Node<g_type> *curr_node = head, *prev_node = nullptr;
        while (curr_node != nullptr)
        {
            if (curr_node->value == element)
            {
                if (prev_node == nullptr)
                    head = head->next;
                else
                    prev_node->next = curr_node->next;
                delete (curr_node);
                length--;
                return;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
    // supprimer toutes les occurrences d'un element
    void delete_all(g_type element)
    {
        if (length == 0)
            return;
        Node<g_type> *curr_node = head, *prev_node = nullptr, *next_node = nullptr;
        while (curr_node != nullptr)
        {
            // valeur du noeud = element
            if (curr_node->value == element)
            {
                // verifier si l'element se situe dans la tete
                if (prev_node == nullptr) // dans se cas il faut supprimer la tete
                {
                    head = head->next;  // avance la tete d'un pas
                    delete (curr_node); // desallouer la memoire de la ancienne tete
                    curr_node = head;   // changer current pour avancer
                }
                // l'element ne se situe pas dans la tete
                else
                {
                    prev_node->next = curr_node->next; // suivant d'ancien noeud point sur le suivant du current
                    delete (curr_node);                // desallouer la memoire du current
                    curr_node = prev_node->next;       // changer current pour avancer
                }
                length--;
            }
            // valeur du noeud != element
            else
            {
                prev_node = curr_node;       // avancer prev d'un pas
                curr_node = curr_node->next; // avancer current d'un pas
            }
        }
    }
    /* ----------------------------------- end ---------------------------------- */

    /* ----------------------------------- tri ---------------------------------- */
    void sort() // tri par changement de valeur (et non par adresses)
    {
        if (length <= 1)
            return;
        Node<g_type> *curr_node = head, *next_node = nullptr;
        while (curr_node != nullptr)
        {
            next_node = curr_node->next;
            while (next_node != nullptr)
            {
                if (curr_node->value > next_node->value)
                {
                    g_type temp = curr_node->value;
                    curr_node->value = next_node->value;
                    next_node->value = temp;
                }
                next_node = next_node->next;
            }
            curr_node = curr_node->next;
        }
    }

    void swap(Node<g_type> *prev_a, Node<g_type> *a, Node<g_type> *prev_b, Node<g_type> *b)
    {
        if (a == nullptr || b == nullptr)
            return;
        // a != head
        if (prev_a != nullptr)
            prev_a->next = b;
        else
            head = b;
        // b != head
        if (prev_b != nullptr)
            prev_b->next = a;
        else
            head = a;
        Node<g_type> *temp = b->next;
        b->next = a->next;
        a->next = temp;
        // delete(temp);
    }

    // merge sort
    // void merge_sort()
    // {
    // }
    // void find_middle()
    // {
    // }
    // void merged_sort()
    // {
    // }
    // end merge sort
    /* ----------------------------------- end ---------------------------------- */
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
    cout << "first element in queue : " << list.first() << endl;
    cout << "last element in queue : " << list.last() << endl;
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
        int to_push = rand();
        cout << "pushing: " << to_push << endl;
        list.push(to_push);
        list.display();
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "poping -> " << list.pop() << endl;
        list.display();
    }
    cout << "[!] END STACK [!]" << endl;
}
// tester le comportement de la fonction reverser
void test_reverse()
{
    cout << "[!] REVERSE [!]" << endl;
    LinkedList<int> list;
    for (int i = 0; i < 10; i++)
        list.enqueue(rand() % 20 + 1);
    list.display();
    list.reverse_rec();
    // list.reverse_itr();
    list.display();
    cout << "[!] END REVERSE [!]" << endl;
}
// tester le comportement des fonctions last/first index
void test_search()
{
    cout << "[!] SEARCH [!]" << endl;
    LinkedList<int> list;
    for (int i = 0; i < 40; i++)
        list.enqueue(rand() % 10 + 1);

    list.display();
    for (int i = 0; i < 5; i++)
    {
        int to_search = rand() % 20 + 1;
        cout << "index of first " << to_search << " : " << list.first_index(to_search) << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        int to_search = rand() % 20 + 1;
        cout << "index of last " << to_search << " : " << list.last_index(to_search) << endl;
    }
    Node<int> *temp_node = list.find_node(5);
    if (temp_node)
        cout << temp_node->value << endl;
    else
        cout << "5 Not found" << endl;
    temp_node = list.find_node(55);
    if (temp_node)
        cout << temp_node->value << endl;
    else
        cout << "55 Not found" << endl;

    cout << "[!] END SEARCH [!]" << endl;
}
// tester le comportement des fonctions delete first/all
void test_delete()
{
    cout << "[!] DELETE [!]" << endl;
    LinkedList<int> list;
    for (int i = 0; i < 20; i++)
        list.enqueue(rand() % 10 + 1);
    list.display();

    for (int i = 0; i < 5; i++)
    {
        int elem = rand() % 10 + 1;
        cout << "supprimer 1ere occurrence de " << elem << endl;
        list.delete_first(elem);
        list.display();
    }
    cout << "supprimer toutes les occurrence de " << 1 << endl;
    list.delete_all(1);
    list.display();

    cout << "supprimer toutes les occurrence de " << 2 << endl;
    list.delete_all(2);
    list.display();

    cout << "[!] END DELETE [!]" << endl;
}
// tester le comportement du tri
void test_sort()
{
    cout << "[!] SORT [!]" << endl;
    LinkedList<int> list;
    for (int i = 0; i < 10; i++)
        list.enqueue(rand() % 10 + 1);
    list.display();
    list.sort();
    list.display();
    cout << "[!] END SORT [!]" << endl;
}
/* ----------------------------------- end ---------------------------------- */

/* -------------------------  programme principale ------------------------ */
int main()
{
    // test_stack();
    // test_queue();
    test_reverse();
    // test_search();
    // test_delete();
    // test_sort();
    return 0;
}