#pragma once
#include <stdbool.h>
#include "sequential_list.h"

//self_a_list: self adjusting list

typedef slist self_a_list;

self_a_list* create_that_list(self_a_list*);

void ask(self_a_list*, ElementType);