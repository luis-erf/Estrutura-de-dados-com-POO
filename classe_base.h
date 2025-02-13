// Classe abstrata das listas
template <typename E> class Lista {
    private:
        void operator =(const Lista&) {}
        Lista(const Lista&) {}
    public:
        Lista() {}
        virtual ~Lista() {}
        virtual void clear() = 0;
        virtual void insert(const E& item) = 0;
        virtual void append(const E& item) = 0;
        virtual void remove() = 0;
        virtual void moveToStart() = 0;
        virtual void moveToEnd() = 0;
        virtual void prev() = 0;
        virtual void next() = 0;
        virtual int length() const = 0;
        virtual int currPos() const = 0;
        virtual void moveToPos(int pos) = 0;
        virtual const E& getValue() const = 0;
};

// Lista de arrays
template <typename T>
class Lista_array : public Lista<T>{
    private:
        int maxSize;
        int current_size;
        int curr;
        T* listArray;

    public:
        Lista_array(int size = 0);
        ~Lista_array();

        void clear();

        void insert(const T& termo);
        void append(const T& termo);

        void remove();

        void moveToStart();
        void moveToEnd();

        void prev();
        void next();

        int length() const;

        int count(const T& termo) const;

        int currPos() const;

        void moveToPos(int pos);

        const T& getValue() const;
};

template<typename T> 
class link{
    public:
        T elemento;
        link* next;
        link(const T& valor_elemento, link* next_val = NULL);
        link(link* next_val = NULL);
};

template<typename T>
class Linked_list : public Lista<T>{
    private:
        link<T>* head;
        link<T>* tail;
        link<T>* curr;
        int cnt;

        void init();
        void removeall();
    
    public:
        Linked_list();
        ~Linked_list();

        void insert(const T& termo);
        void append(const T& termo);

        void clear();

        void remove();

        void moveToStart();
        void moveToEnd();

        void prev();
        void next();

        int length() const;

        int count(const T& termo) const;

        int currPos() const;

        void moveToPos(int pos);

        const T& getValue() const;
};