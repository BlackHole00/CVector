#include <stdio.h>
#include "vector.h"

typedef struct {
	int foo;
	float bar;
} Test;

int main()
{
	Vector vect = create_vector();
	Vector* temp = &vect;

	push_vector_data(vect, 10, int);
	push_vector_data(vect, 20, int);
	push_vector_data(vect, 30, int);
	push_vector_data(vect, 40, int);
	push_vector_data(vect, 50, int);
	push_vector_data(vect, 60, int);
	push_vector_data(vect, 70, int);
	push_vector_ptr_data(temp, 80, int);

	pop_vector_data(vect, int);
	pop_vector_ptr_data(temp, int);



	for (int i = 0; i < vect.length; i++) {
		printf("%d ", vector_data(vect, int)[i]);
	}
	printf("\n");

	free_vector(&vect);
	
	vect = create_vector();
	Test a = { 30, 40.0 };
	push_vector_data(vect, a, Test);
	printf("%d %f", vector_data(vect, Test)[0].foo, vector_data(vect, Test)[0].bar);

	free_vector(&vect);
	vect = create_vector();

	set_vector_length(vect, 1, Test);
	vector_data(vect, Test)[0].bar = 9.0f;
	vector_data(vect, Test)[0].foo = 5;
	set_vector_ptr_length(temp, 2, Test);
	printf("%d %f", vector_data(vect, Test)[0].foo, vector_data(vect, Test)[0].bar);

	free_vector(&vect);
}