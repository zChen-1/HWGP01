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
        vector(): size_v{0}, space{1}, elem{nullptr} {};

        // Alternate Constructor
        // Capacity of s elements on initialization
        explicit vector(int s): size_v{0}, space{s}, elem{new T[space]} {};

        // Copy constructor
        // !! If T is a pointer type, make sure to delete the data if
        // necessary
        vector(const vector& oldVec): size_v{oldVec.size_v}, space{oldVec.size_v}, elem{new T[space]} {
            for(int i = 0; i < size_v; i++){
                elem[i] = oldVec.elem[i];
            }

        };

        // Copy Assignment (NOT Constructor)
        // Copies data from a vector into an existing vector of the same type.
        vector& operator=(const vector& rhs) {
            // delete old array
            delete[] elem;

            // create new array with the same capacity as the rhs obj
            elem = new T[rhs.space];

            // copy rhs into lhs (this)
            for(int i = 0; i < size_v; i++){
                elem[i] = rhs.elem[i];
            }

            // update size and capacity
            size_v = rhs.size_v;
            space = rhs.space;

            return *this;

        };

        // Move Constructor
        // Copies from a temporary obj, temp obj is destroyed after
        // Shallow copy temp obj into new obj
        vector(const vector&& temp): size_v{temp.size_v}, space{temp.space}, elem{temp.elem} {

            // empty out temp value (is this necessary?)
            temp.size = 0;
            temp.capacity = 0;
            temp.elem = nullptr;

        };

        // Move Assignment
        // Moves a temp rvalue into an existing obj
        vector& operator=(const vector&& temp) {

            // delete old array
            delete [] elem;

            // shallow copy temp into existing obj
            elem = temp.elem;
            size_v = temp.size_v;
            space = temp.space;

            // empty out temp obj
            temp.elem = nullptr;
            temp.size = 0;
            temp.capacity = 0;

            return *this;
        };

        // Destructor
        ~vector() {
            // deletes dynamic array
            delete[] elem;
        };

        // Subscript operators
        // Returns element at n
        T& operator[] (int n) {return elem[n];};                  // access: return reference
        const T& operator[] (int n) const {return elem[n];};            // access: return reference

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
        // if there is no room, double the size of the array
        void push_back(T val) {
			if(size_v == 0) {
				reserve(8);
			}else if(size_v == space){
                reserve(size_v*2);
            }
			elem[size_v] = val;
			size_v++;
        };

        // reserve
        // grows the vector with uninitialized space
        // !! delete the contents first if T is a pointer type !!
        void reserve(int newalloc) {
            T* temp = new T[newalloc];
			
			if(newalloc <= space){
				return;
			}
			
            // copy old array into new array
            for(int i = 0; i < size_v; ++i){
                temp[i] = elem[i];
            }

            // delete old array
            delete[] elem;

            // point elem to new array
            elem = temp;
            temp = nullptr;

            // update capacity
            space = newalloc;
        };

        using iterator = T*;
        using const_iterator = const T*;

        // begin
        // return nullptr if vector is empty, else return a reference to
        // the first element in the vector
        iterator begin() {
            if(size_v == 0) {
                return nullptr;
            }
            return &elem[0];
        };

        // begin (const version)
        // return nullptr if vector is empty, else return a reference to
        // the first element in the vector
        // used when the vector is constant
        const_iterator begin() const {
            if(size_v == 0) {
                return nullptr;
            }
            return &elem[0];
        };

        // end
        // return nullptr if vector is empty, else return a reference to
        // one element past the last defined element
        iterator end() {
            if(size_v == 0) {
                return nullptr;
            }
            return &elem[size_v];
        };

        // end
        // return nullptr if vector is empty, else return a reference to
        // one element past the last defined element
        // used when vector is const
        const_iterator end() const {
            if(size_v == 0) {
                return nullptr;
            }
            return &elem[size_v];};

        // insert
        // inserts a new element v before p
        iterator insert(iterator p, const T& v) {

            // make room for new element of capacity of vector is too small
            if(size_v == space) {
                reserve(space+1);
            }

            // move elements down to make room to insert
            for (iterator pos = end(); pos != p; --pos)
            *pos  = *(pos - 1);

            // update size
            ++size_v;

            // insert new element
            *p = v;

            return p;

        };

        // erase
        // removes element pointed to by p
        // !! if p is a pointer, data pointed to must be deleted before erasing !!
        iterator erase(iterator p) {

            // end is one past the last element, cannot be erased
            if (p == end()){
                return p;
            }

            // start one after p and move all elements up, overwriting p
            for(iterator pos = p + 1; pos != end(); ++pos) {
                *(pos-1) = *pos;
            }

            // update size
            --size_v;

        };

    }; // end class template vector

} // end namespace gp

#endif /* VECTOR_H_ */
