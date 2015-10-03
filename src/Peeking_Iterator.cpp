// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    this->length = nums.size();
	    this->nums = &nums;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(currentIndex < length) {
	        return (*this->nums)[currentIndex];
	    }
	    return -1;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(currentIndex < length) {
	        currentIndex ++;
	        return (*this->nums)[currentIndex-1];
	    }
	    return -1;
	}

	bool hasNext() const {
	    return currentIndex < length;
	}
	
private:
    int currentIndex = 0;
    int length = 0;
    const vector<int>* nums = NULL;
};