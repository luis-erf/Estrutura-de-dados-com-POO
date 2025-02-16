template<typename T>
class Queue{
    private:
        void operator = (const Queue&) {};
        Queue(const Queue&) {};
    public:
        Queue() {};
        virtual ~Queue() {};
        virtual void clear() = 0;
        virtual void enqueue(const T& termo) = 0;
        virtual T dequeue() = 0;
        virtual const T& front_value() const = 0;
        virtual int length() const = 0;
};

template<typename T>
class Array_queue : public Queue<T>{
    private:
        int max_size;
        int front;
        int rear;
        T* list_array;
    
    public:
        Array_queue(int size);
        ~Array_queue();

        void clear();

        void enqueue(const T& termo);

        T dequeue();

        const T& front_value() const;

        int length() const;
};