#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int _Ty;

struct linked_list {
	struct linked_node * head;
	struct linked_node * now;
	size_t size;
};

struct linked_node {
	_Ty value;
	struct linked_node * next;
};


void linked_init(struct linked_list * li) {
	li->head = NULL;
	li->size = 0;
}

bool linked_empty(struct linked_list * li) {
	return !(li->size);
}

size_t linked_size(struct linked_list * li) {
	return li->size;
}

void linked_push_back(struct linked_list * li, _Ty v) {
	if (linked_empty(li))
	{
		struct linked_node * New = (struct linked_node *)malloc(sizeof(struct linked_node));
		New->value = v;
		New->next = NULL;
		li->head = New;
	}
	else
	{
		struct linked_node * New = (struct linked_node *)malloc(sizeof(struct linked_node));
		struct linked_node * tmp = (struct linked_node *)malloc(sizeof(struct linked_node));
		New->value = v;
		New->next = NULL;
		tmp = li->head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = New;
	}
	(li->size)++;
}

_Ty linked_pop_mid(struct linked_list * li, int idx) { // idx보다 size가 큰거를 보장?
	_Ty temp;
	if (/*idx > linked_size(li) || */idx < 0 || linked_empty(li))
	{
		printf("잘못된 index\n");
		return -1;
	}
	struct linked_node * ptr = (struct linked_node *)malloc(sizeof(struct linked_node));
	//  ptr = li->head;
	ptr = li->now;//next
	if (idx)
	{
		while (--idx) // idx는 삽입할거 앞에 있는애임
					  //      while(idx--)
			ptr = ptr->next;
		//삭제
		struct linked_node * tmp = (struct linked_node *)malloc(sizeof(struct linked_node));
		tmp = ptr->next; // tmp가 삭제할 node

		li->now = tmp->next;
		ptr->next = tmp->next;
		//li->now = tmp->next;
		temp = tmp->value;
		free(tmp);
		(li->size)--;
		return temp;
	}
	else
	{
		struct linked_node * tmp = (struct linked_node *)malloc(sizeof(struct linked_node));
		tmp = ptr; // tmp가 삭제할 node

		int len = linked_size(li);

		while (--len)
			ptr = ptr->next;
		li->now = tmp->next;
		ptr->next = tmp->next;
		temp = tmp->value;
		free(tmp);
		(li->size)--;
		return temp;
	}
}

int main() {
	struct linked_list my_list;
	linked_init(&my_list);
	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
		linked_push_back(&my_list, i);
	//원형큐 연결
	struct linked_node * tmp = (struct linked_node *)malloc(sizeof(struct linked_node));
	tmp = my_list.head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = my_list.head;
	my_list.now = my_list.head;
	//값출력
	printf("<");
	if (!linked_empty(&my_list))
		printf("%d", linked_pop_mid(&my_list, N - 1));
	while (!linked_empty(&my_list))
		printf(", %d", linked_pop_mid(&my_list, N - 1));
	printf(">");
	return 0;
}
