#include <bits/stdc++.h>
using namespace std;

template <class poly_type>
struct Monome
{
    poly_type coeff;
    int deg;
    Monome *suivant;
    Monome()
    {
        this->coeff = 0;
        this->deg = 0;
        this->suivant = nullptr;
    }
    Monome(poly_type coeff, int deg)
    {
        this->coeff = coeff;
        this->deg = deg;
        this->suivant = nullptr;
    }
    Monome(poly_type coeff, int deg, Monome<poly_type> *suiv)
    {
        this->coeff = coeff;
        this->deg = deg;
        this->suivant = suiv;
    }
};

template <class poly_type>
struct Polynome
{
    Monome<poly_type> *head;
    Monome<poly_type> *tail;

    Polynome()
    {
        this->head = this->tail = nullptr;
    }
    void delete_tail()
    {
        // si tete n'est pas null allez jusqu'a l'avant derrnier monome
        if (head != tail)
        {
            Monome<poly_type> *tmp = head;
            while (tmp->suivant->suivant != nullptr)
                tmp = tmp->suivant;
            tail = tmp;
            delete (tail->suivant);
            return;
        }
        delete (tail);
    }
    void insert(poly_type coeff, int deg)
    {
        assert(deg >= 0);
        // Polynome est vide
        if (this->head == nullptr)
        {
            Monome<poly_type> *new_monome = new Monome<poly_type>(coeff, deg);
            this->head = this->tail = new_monome;
            return;
        }

        // Monome a ajouté est <= plys petit monome du polynome || ajout au début
        if (this->head->deg >= deg)
        {
            // test d'egalité
            if (this->head->deg == deg)
            {
                // test de suppression ou ajout
                if (this->head->coeff == -coeff)
                {
                    Monome<poly_type> *sup_monome = head;
                    head = head->suivant;
                    delete (sup_monome);
                }
                else
                    head->coeff += coeff;
                return;
            }
            Monome<poly_type> *new_monome = new Monome<poly_type>(coeff, deg, head);
            head = new_monome;
            return;
        }

        // Monome a ajouté est >= plus grand monome du polynome || ajout à la fin
        if (this->tail->deg <= deg)
        {
            // test d'egalité
            if (this->tail->deg == deg)
            {
                // test de suppression ou ajout
                if (this->tail->coeff == -coeff)
                {
                    delete_tail();
                    return;
                }
                else
                    tail->coeff += coeff;
                return;
            }
            Monome<poly_type> *new_monome = new Monome<poly_type>(coeff, deg);
            tail->suivant = new_monome;
            tail = new_monome;
            return;
        }
        // chercher le monome avec le plus deg et inferieur à deg du nouveau monome
        Monome<poly_type> *curr = head;
        while (curr->suivant->suivant != nullptr && curr->suivant->deg < deg)
            curr = curr->suivant;

        if (curr->suivant->deg == deg)
        {
            if (curr->suivant->coeff == -coeff)
            {
                Monome<poly_type> *tmp = curr->suivant;
                curr->suivant = curr->suivant->suivant;
                delete (tmp);
                return;
            }
            curr->suivant->coeff += coeff;
            return;
        }

        Monome<poly_type> *new_monome = new Monome<poly_type>(deg, coeff, curr->suivant);
        curr->suivant = new_monome;
    }

    /* -------------------------------- addition -------------------------------- */
    Polynome<poly_type> addition(Polynome<poly_type> &poly)
    {
        Polynome<poly_type> result = Polynome<poly_type>();
        Monome<poly_type> *curr = head;
        Monome<poly_type> *curr_poly = poly.head;

        while (curr != nullptr && curr_poly != nullptr)
        {
            if (curr->deg == curr_poly->deg)
            {
                result.insert(curr->deg, curr->coeff + curr_poly->coeff);
                curr = curr->suivant;
                curr_poly = curr_poly->suivant;
                continue;
            }
            if (curr->deg > curr_poly->deg)
            {
                result.insert(curr->deg, curr->coeff);
                curr = curr->suivant;
            }
            else
            {
                result.insert(curr_poly->deg, curr_poly->coeff);
                curr_poly = curr_poly->suivant;
            }
        }
        while (curr != nullptr)
        {
            result.insert(curr->deg, curr->coeff);
            curr = curr->suivant;
        }
        while (curr_poly != nullptr)
        {
            result.insert(curr_poly->deg, curr_poly->coeff);
            curr_poly = curr_poly->suivant;
        }
        cout << result.toString() << endl;
        return result;
    }
    string toString()
    {
        string rt = "";
        if (head != nullptr)
        {
            Monome<poly_type> *curr = head;
            while (curr != nullptr)
            {
                if (curr != head)
                    rt += " + ";
                rt += to_string(curr->coeff);
                rt += "x^";
                rt += to_string(curr->deg);
                curr = curr->suivant;
            }
        }
        return rt;
    }
};

void test_addition()
{
    Polynome<double> poly_1 = Polynome<double>();
    poly_1.insert(1, 1);
    poly_1.insert(1, 2);
    poly_1.insert(1, 3);
    poly_1.insert(1, 4);
    Polynome<double> poly_2 = Polynome<double>();
    poly_2.insert(1, 2);
    poly_2.insert(1, 3);
    poly_2.insert(1, 4);
    poly_2.insert(1, 5);
    poly_2.insert(1, 6);
    Polynome<double> poly_3 = poly_1.addition(poly_2);
    cout << poly_1.toString() << endl;
    cout << poly_2.toString() << endl;
    cout << poly_3.toString() << endl;
}

void test_insert()
{
    Polynome<double> poly = Polynome<double>();
    poly.insert(1, 1);
    cout << poly.tail->deg << endl;
    poly.insert(2, 2);
    cout << poly.tail->deg << endl;
    poly.insert(3, 3);
    cout << poly.tail->deg << endl;
    poly.insert(4, 4);
    cout << poly.tail->deg << endl;
    cout << poly.toString() << endl;
    poly.insert(1, 1);
    poly.insert(2, 2);
    poly.insert(3, 3);
    poly.insert(4, 4);
    cout << poly.toString() << endl;
    poly.insert(-8, 4);
    cout << poly.toString() << endl;
    cout << poly.tail->deg << endl;
}

int main()
{
    test_insert();
    // test_addition();
    return 0;
}