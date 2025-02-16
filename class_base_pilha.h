template<typename T>
class stack{
    private:
        void operator =(const stack&) {};
        stack(const stack&) {};
    public:
        stack() {};
        virtual ~stack() {};
        virtual void clear() = 0;
        virtual void push(const T& termo) = 0;
        virtual T pop() = 0;
        virtual const T& top_value() const = 0;
        virtual int length() const = 0;
};

template<typename T>
class Array_stack : public stack<T>{
    private:
        int max_size;
        int top;
        T* list_array;
    
    public:
        Array_stack(int size);
        ~Array_stack();

        void clear();

        void push(const T& termo);

        T pop();

        const T& top_value() const;

        int length() const;
};