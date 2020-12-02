#pragma once

//Small n' Static Circular Queue
//No dynamic allocations, if you really wanted to know...
//No license, use at your own risk
//Programmer: Eric Petersen
template <class T, size_t S> //T is the variable to store, S is the max size of your queue
class alignas(alignof(T)) mini_queue {
	size_t F, R;//Front and Rear variables
	T A[S];//Array to hold T variables, with size S
public:
		//Constructor
	constexpr mini_queue() : F(0), R(0), A() {}//initialize all to zero
		//Minimal - push, pull, and size
	inline bool push(const T& V) { return size() <= S ? &(A[(R %= S)++] = V) : 0; }//adds to queue, returns true on success
	inline T pull() { return R != F ? A[(F %= S)++] : T(); }//take from front of Queue, returns new initialized object on failure
	inline size_t size() const { return F > R ? S - F + R : R - F; }//get number of stored elements inside queue
		//Head and rear reading - Not needed for functioning class
	inline T* head() { return size() ? &A[F] : 0; }//get pointer to beginning element, returns NULL pointer on failure
	inline const T* head() const { return head(); }//constant version of other head()
	inline T* back() { return size() ? &A[(R + S - 1) % S] : 0; }//get pointer to last element, returns NULL pointer on failure
	inline const T* back() const { return back(); }//constant version of back()
		//Capacity reading - Not needed for functioning class
	constexpr inline size_t max() const { return S; }
};