#include <cstdio>
#include <cstdlib>
#include <C:\C++ dependencies\mini_queue.hpp>

//Here have a test.
//Compile & run to test the mini_queue.hpp class.

int main() {
	mini_queue<int, 45> q;
	for (size_t i = 0; i < 100; ++i) {
		if (!(i % 2)) {//Easy way to make this go once every other loop, starting on i == 0
			if (q.last()) {
				printf("Last inserted item: %i\n", *q.last());
			}
			else {
				printf("There is no last item avaliable.\n");
			}
			if (q.first()) {
				printf("First inserted item: %i\n", *q.first());
			}
			else {
				printf("There is no first item avaliable.\n");
			}
			printf("Pulled: %i\n", q.pull());
			printf("Size of Queue: %zu, Max size: %zu\n\n", q.size(), q.max_size());
		}
		int a = rand();
		printf("Pushing %i: Success? %u\n", a, q.push(a));
	}
}