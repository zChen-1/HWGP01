/*
 * vector.h 
 * by Ethan Lew
 */

#ifndef VECTOR_H_
#define VECTOR_H_

// vector is in gp namespace to avoid any confusion with std::vector
namespace gp{

    template<class T>

    class vector
    {
    private:
        int size_v;     // the size
        T* elem;        // a pointer to the elements
        int space;      // size+free_space

    public:
        // Default Constructor
        // Capacity of 1 element on initialization
        vector(): size_v{0}, space{1}, elem{new T[space]} {};

        // Alternate Constructor
        // Capacity of s elements on initialization
        explicit vector(int s): size_v{0}, space{s}, elem{new T[space]} {};

        vector(const vector&);                  // copy constructor
        vector& operator=vector(const vector&); // copy assignment
        vector(const vector&&);                 // move constructor
        vector& operator=vector(const vector&&);// move assignment

        // Destructor
        ~vector() {
            delete[] elem;
        };

        // Subscript operators
        // Returns element at n
        T& operator[] (int n) {return elem[n];};                  // access: return reference
        const T& operator[] (int n) {return elem[n];};            // access: return reference

        // size
        // returns size_v
        int size() const {return size_v;};

        // capacity
        // returns space
        int capacity() const {return space;};
        
        // resize
        // grows the vector
        // !! if T is a pointer, delete contents first !!
        void resize(int newsize) {
            reserve(newsize);
            for (int i = size_v; i < newsize; ++i){
                elem[i] = 0;
            }
			
		    size_v = newsize;
        };

        // push_back
        // adds an element to the vector
        // if there is no room, resize the vector with an extra space
        void push_back(T val) {
            if(size_v == capacity){
                reserve(size_v+1);
                size_v++
                elem[size_v] = val;
            }
        };

        // reserve
        // grows the vector with uninitialized space
        // !! delete the contents first if T is a pointer type !!
        void reserve(int newalloc) {
            T* temp = new T[newsize];

            // copy old array into new array
            for(int i - 0; i < size_v; ++i){
                temp[i] = elem[i];
            }

            // delete old array
            delete[] elem;

            // point elem to new array
            elem = temp;
            temp = nullptr;
        };
        
        using iterator = T*;
        using const_iterator = const T*;
        iterator begin();                       // points to first element
        const_iterator begin() const;
        iterator end();                         // points to one beyond the last element
        const_iterator end() const;
        iterator insert(iterator p, const T& v);// insert a new element v before p
        iterator erase(iterator p);             // remove element pointed to by p
    };

}
#endif /* VECTOR_H_ */