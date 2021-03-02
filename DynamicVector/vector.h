#include <malloc.h>

typedef struct {
	void* vector;

	unsigned int length;
} Vector;


Vector create_vector();

void free_vector(Vector*);

#define push_vector_data(__vect, __data, __type) {											\
	__vect.vector = realloc(__vect.vector, (__vect.length + 1) * sizeof(__type));			\
	if (__vect.vector == NULL) exit(-1);													\
																							\
	__type* __temp = (__type*)__vect.vector;												\
	__temp[__vect.length] = __data;															\
	__vect.length++;																		\
}

#define push_vector_ptr_data(__vect, __data, __type) {										\
	__vect->vector = realloc(__vect->vector, (__vect->length + 1) * sizeof(__type));		\
	if (__vect->vector == NULL) exit(-1);													\
																							\
	__type* __temp = (__type*)__vect->vector;												\
	__temp[__vect->length] = __data;														\
	__vect->length++;																		\
}

#define pop_vector_data(__vect, __type) {													\
	if (__vect.length > 0) {																\
		__vect.length--;																	\
		__vect.vector = realloc(__vect.vector, __vect.length * sizeof(__type));				\
		if (__vect.vector == NULL) exit(-1);												\
	}																						\
}

#define pop_vector_ptr_data(__vect, __type) {												\
	if (__vect->length > 0) {																\
		__vect->length--;																	\
		__vect->vector = realloc(__vect->vector, __vect->length * sizeof(__type));			\
		if (__vect->vector == NULL) exit(-1);												\
	}																						\
}

#define set_vector_length(__vect, __len, __type) {											\
	if (__vect.length >= 0) {																\
		__vect.vector = realloc(__vect.vector, __len * sizeof(__type));						\
		__vect.length = __len;																\
	}																						\
}

#define set_vector_ptr_length(__vect, __len, __type) {										\
	if (__vect->length >= 0) {																\
		__vect->vector = realloc(__vect->vector, __len * sizeof(__type));					\
		__vect->length = __len;																\
	}																						\
}

#define vector_data(vect, type) ((type*)vect.vector)