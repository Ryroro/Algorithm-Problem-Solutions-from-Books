#include <stdio.h>
#include <stdlib.h>
typedef struct Node* link;
struct Node {
	char c;
	link next;
	link previous;
};

int main()
{
	int c;
	link node = malloc(sizeof *node);
	link head = node;
	link pos = head;
	node->previous = NULL;
	while((c = getchar()) != EOF) {
		node->c = c;
		node->next = malloc(sizeof *node);
		node->next->previous = node;
		node = node->next;
	}
	node = NULL;
	link before;
	link after;
	link word_start = NULL;
	link word_end = NULL;
	while (pos != NULL) {
		if (pos->c == '[') {
			before = pos->previous;
			pos = pos->next;
			if (pos->c != ']')
				word_start = pos;
			else
				word_start = NULL;
		} else if  (pos->c == ']') {
			after = pos->next;
			before->next = after;
			after->previous = before;
			if (before->c == '[')
				before = before->previous;
			if (word_start != NULL) {
				word_end = pos->previous;
				word_end->next = head;
				word_start->previous = NULL;
				head = word_start;
			}
			pos = pos->next;
		} else {
			pos = pos->next;
		}
			
	}
	while (head->next != NULL) {
		printf("%c", head->c);
		head = head->next;
	}
				
	return 0;	
}
