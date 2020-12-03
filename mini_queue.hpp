#pragma once
//A small class for managing a circular Queue.

//Think it is wrong? Go over your code again.
//You get an error? Use C++, not Python.
//Class acting funky? Check the return values.

template <class T, size_t L>
class alignas(alignof(T)) mini_queue {
	size_t F, S;//First element, and size of queue
	T A[L];
public:
		//Constructor
	constexpr mini_queue() :F(0), S(0), A() {}
		//Standard behavior
	inline bool push(const T& V) { return S < L ? &(A[(F + S++) % L] = V) : 0; }
	inline T pull() { return (S ? S-- : 0) ? A[(F %= L)++] : T(); }
		//Size and maximum size
	inline size_t size() const { return S; }
	constexpr inline size_t max_size() const { return L; }
		//Last and First inserted items (Returns 0 on failure)
	inline T* last() { return S ? A + (F + (S - 1)) % L : 0; }
	inline T* first() { return S ? A + F % L : 0; }
		//Constant first() and last(): Requires non-const last() and first()
	inline const T* last() const { return last(); }
	inline const T* first() const { return first(); }
};