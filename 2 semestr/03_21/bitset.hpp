    #ifndef BITSET
    #define BITSET
    #include <iostream>
    // zapomnialem o rzuceniu bledu

    template <int MIN = 0, int MAX = 15>
    class BitSet
    {
    public:
        BitSet();
        void insert(int value);                // wstawia wartość value jeśli jej nie było w zbiorze, wpp operacja pusta
        void remove(int value);                // usuwa wartość value jeśli była w zbiorze, wpp operacja pusta
        bool contains(int value);              // sprawdza czy value jest w zbiorze
        void Union(const BitSet &other);        // dodaje do zbioru elementy z innego zbioru przekazanego jako argument
        void intersection(const BitSet &other); // wykonuje przcięcie zbioru z innym zbiorem
        void difference(const BitSet &other);   // znajduje roznice zbioru z innym zbiorem
        void printSet();

    private:
        unsigned char array[((MAX - MIN ) / 8) + 1];
        int bytes = ((MAX - MIN ) / 8) + 1;
    };

    template <int MIN, int MAX>
    BitSet<MIN, MAX>::BitSet()
    {
        for (int i = 0; i < bytes; i++)
        {
            array[i] = 0;
        }
    }

    template <int MIN, int MAX>
    void BitSet<MIN, MAX>::insert(int value)
    {
        if(value < MIN || value > MAX)
        {
            throw std::logic_error("Nieprawidlowa wartosc");
        }
        int cell = value / 8;
        int bit = value % 8;

        array[cell] = array[cell] | (1 << bit);
    }

    template <int MIN, int MAX>
    void BitSet<MIN, MAX>::remove(int value)
    {
        unsigned char cell = value / 8;
        unsigned char bit = value % 8;

        array[cell] = array[cell] & ~(1 << bit);
    }

    template <int MIN, int MAX>
    bool BitSet<MIN, MAX>::contains(int value)
    {
        int cell = value / 8;
        int bit = value % 8;

        return (!!((array[cell] << (7 - bit)) & 0x80)) == 1;
    }

    template <int MIN, int MAX>
    void BitSet<MIN, MAX>::Union(const BitSet &other)
    {
        for (int i = 0; i < bytes; i++)
        {
            array[i] = array[i] | other.array[i];
        }
    }

    template <int MIN, int MAX>
    void BitSet<MIN, MAX>::intersection(const BitSet &other)
    {
        for (int i = 0; i < bytes; i++)
        {
            array[i] = array[i] & other.array[i];
        }
    }

    template <int MIN, int MAX>
    void BitSet<MIN, MAX>::difference(const BitSet &other)
    {
        for (int i = 0; i < bytes; i++)
        {
            array[i] = array[i] & (~other.array[i]);
        }
    }

    template <int MIN, int MAX>
    void BitSet<MIN, MAX>::printSet()
    {
        for (int i = 0; i < bytes; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                std::cout << !!((array[i] << j) & 0x80);
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    #endif // BITSET
