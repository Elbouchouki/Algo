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
    Monome *head;
    Monome *tail;

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
            while (tmp->suivant != tail)
                tmp = tmp->suivant;
            delete (tail);
            tail = temp;
            return;
        }

        delete (tail);
    }
    void insert(poly_type coeff, int deg)
    {
        assert(deg >= 0);
        // Polynome est vide
        if (this.head == nullptr)
        {
            Monome *new_monome = new Monome<poly_type>(coeff, deg);
            this.head = this.tail = new_monome;
            return;
        }

        // Monome a ajouté est <= plys petit monome du polynome || ajout au début
        if (this.head->deg >= deg)
        {
            // test d'egalité
            if (this.head->deg == deg)
            {
                // test de suppression ou ajout
                if (this.head->coeff == -coeff)
                {
                    Monome *sup_monome = head;
                    head = head->suivant;
                    delete (sup_monome);
                }
                else
                    head->coeff += coeff;
                return;
            }
            Monome *new_monome = new Monome<poly_type>(coeff, deg, head);
            head = new_monome;
            return;
        }

        // Monome a ajouté est >= plus grand monome du polynome || ajout à la fin
        if (this.tail->deg <= new_monome->deg)
        {
            // test d'egalité
            if (this.head->deg == deg)
            {
                // test de suppression ou ajout
                if (this.head->coeff == -coeff)
                    this.delete_tail();
                else
                    tail->coeff += coeff;
                return;
            }
            Monome *new_monome = new Monome<poly_type>(coeff, deg);
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

        Monome<poly_type> *new_monome = new Monome(deg, coeff, curr->suivant);
        curr->suivant = new_monome;
    }
    string to_string()
    {
        string rt = "";
        if (head != tail)
        {
            Monome<poly_type> *curr = head;
            while (curr != nullptr)
            {
                to_string(curr->coeff)
            }
        }
    }
};

int main()
{
}