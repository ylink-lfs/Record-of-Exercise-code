#pragma once
#include <stdbool.h>
#include "linked_list.h"

typedef llist_head self_a_list_head;

self_a_list_head* create(self_a_list_head*);

void ask(self_a_list_head*, ElementType);