#include "vector.h"

Vector create_vector() {
	Vector vect;

	vect.vector = malloc(0);
	vect.length = 0;

	return vect;
}

void free_vector(Vector* vect) {
	free(vect->vector);
	vect->length = 0;
}