#ifndef DICT
#define DICT
#include "LinkedList.hpp"
#define MAX 100

template <class K, class V>
class Dict
{
public:
    using Pair = std::pair<K, V>;
    Dict();                     // Konstruktor
    void clear();               // Czyści słownik
    bool insert(const Pair &p); // Dodaje parę klucz-wartość do słownika
    bool find(const K &k);      // Sprawdza czy słownik zawiera klucz
    V &operator[](const K &k);  // Zwraca wartość dla klucza
    bool erase(const K &k);     // Usuwa parę od danym kluczu
    int size();                 // Zwraca liczbę par
    bool empty();               // Sprawdza czy słownik jest pusty
    void buckets();             // Wypisuje informację o słowniku (patrz poniżej)
    unsigned long hash(K key);

private:
    List<Pair> hash_tab[MAX];
};

template <class K, class V>
Dict<K, V>::Dict() {}

template <class K, class V>
void Dict<K, V>::clear()
{
    List<Pair> *lista;
    for (int i = 0; i < MAX; i++)
    {
        lista = &hash_tab[i];
        lista->clear();
    }
}

template <class K, class V>
bool Dict<K, V>::insert(const Pair &p)
{
    int index = hash(p.first);
    List<Pair> *lista = &hash_tab[index];

    bool is_duplicate = find(p.first);

    if (!is_duplicate)
    {
        lista->push_back(p);
        return true;
    }
    else
    {
        erase(p.first);
        lista->push_back(p);
        return false;
    }
}

template <class K, class V>
bool Dict<K, V>::find(const K &k)
{
    int index = hash(k);
    List<Pair> *lista = &hash_tab[index];
    bool is_key_present = false;
    Pair para;
    for (int i = 0; i < lista->size(); i++)
    {
        para = (*lista)[i];
        if (k == para.first)
        {
            is_key_present = true;
        }
    }

    return is_key_present;
}

template <class K, class V>
V &Dict<K, V>::operator[](const K &k)
{
    int index = hash(k);
    List<Pair> *lista = &hash_tab[index];
    Pair *para;

    if (!find(k))
    {
        lista->push_back(Pair(k, V{}));
    }

    for (int i = 0; i < lista->size(); i++)
    {
        para = &(*lista)[i];
        if (k == para->first)
        {
            break;
        }
    }

    return para->second;
}

template <class K, class V>
bool Dict<K, V>::erase(const K &k)
{
    int index = hash(k);
    List<Pair> *lista = &hash_tab[index];
    Pair *para;

    bool is_present = find(k);

    if (is_present)
    {
        for (int i = 0; i < lista->size(); i++)
        {
            para = &(*lista)[i];
            if (k == para->first)
            {
                lista->erase(i);
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

template <class K, class V>
int Dict<K, V>::size()
{
    List<Pair> *lista;
    int D_size = 0;
    for (int i = 0; i < MAX; i++)
    {
        lista = &hash_tab[i];
        D_size += lista->size();
    }

    return D_size;
}

template <class K, class V>
bool Dict<K, V>::empty()
{
    return size() == 0;
}

template <class K, class V>
void Dict<K, V>::buckets()
{
    List<Pair> *lista;
    int elements_amount = size();
    int min_size = 0;
    int max_size = 0;
    int classes_amount = 0;
    bool first_class = true;

    for (int i = 0; i < MAX; i++)
    {
        lista = &hash_tab[i];
        if (!lista->empty())
        {
            if (first_class)
            {
                min_size = lista->size();
                max_size = lista->size();
                first_class = false;
            }
            else
            {
                if (lista->size() < min_size)
                {
                    min_size = lista->size();
                }
                if (lista->size() > max_size)
                {
                    max_size = lista->size();
                }
            }
            classes_amount++;
        }
    }

    std::cout << "# " << elements_amount << " " << classes_amount << " " << min_size << " " << max_size << std::endl;
}

template <class K, class V>
unsigned long Dict<K, V>::hash(K key)
{
    unsigned long code = 5381;
    for (auto c : key)
    {
        code = ((code << 5) + code) + (int)c;
    }
    return code % MAX;
}

#endif // DICT
