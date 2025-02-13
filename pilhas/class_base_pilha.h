template<typename T>
class stack{
    private:
        void operator =(const stack&);
        stack(const stack&);
    public:
        stack();
        virtual ~stack();
        virtual void clear() = 0;
        virtual void push(const T& termo) = 0;
        virtual void pop() = 0;
        virtual const T& top_value() const = 0;
        virtual int lenght() const = 0;
};

template<typename T>
class array_stack : public stack<T>{
    private:
        int max_size;
        int top;
        T* list_array;
    
    public:
        int default_size = 1000;
        array_stack(int size = default_size);
        ~array_stack();

        void clear();

        void push(const T& termo);

        void pop();

        const T& top_value() const;

        int length() const;
};