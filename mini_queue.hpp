#pragma once

//Small n' Static Circular Queue
//No dynamic allocations, if you really wanted to know...
//No license, use at your own risk
//Programmer: Eric Petersen
template <class T, size_t S> //T is the variable to store, S is the max size of your queue
class mini_queue {
	T A[S];//Array to hold T variables, with size S
	size_t F, R;//Front and Rear variables
public:
	constexpr mini_queue() : F(0), R(0), A() {}//Initialize to zero
	inline bool push(const T& V) { return size() <= S ? &(A[(R %= S)++] = V) : 0; }//Adds to queue, returns true on success
	inline T pull() { return R != F ? A[(F %= S)++] : T(); }//take from front of Queue, returns new initialized object on failure
	inline T* head() { return size() ? &A[F] : 0; }//get pointer to beginning element, returns NULL pointer on failure
	inline const T* head() const { return size() ? &A[F] : 0; }//Constant version of other head()
	inline size_t size() const { return F > R ? S - F + R : R - F; }//get number of stored elements inside queue
};