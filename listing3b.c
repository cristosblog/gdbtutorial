/* 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Listing 3b. Slightly modified list example */
/* Cristos' Blog - http://cristos.x25.pl */

#include <stdio.h>
#include <stdlib.h>

struct list_node {
	struct list_node* next;
	unsigned int blob[4];
	int data;
};

struct list_node* add_item(struct list_node* list, int data);
void remove_item(struct list_node* list, struct list_node* item);
void delete_list(struct list_node* list);

int main(int argc, char* argv[]) 
{
	struct list_node *list = malloc(sizeof(struct list_node));
	list->data=6;
	
	add_item(list, 10);
	add_item(list, 20);
	add_item(list, 30);
	struct list_node *tmp = add_item(list, 40);
	add_item(list, 50);
	add_item(list, 60);
	
	remove_item(list, tmp);

	add_item(list, 70);

	delete_list(list);
	return 0;
}

struct list_node* add_item(struct list_node* list, int data) 
{
	if (!list)
		return NULL;
	
	while (list->next != NULL)
		list = list->next;
	
	list->next = malloc(sizeof(struct list_node));
	list->next->data = data;
	list->next->next = NULL;

	return list->next;
}

void remove_item(struct list_node* list, struct list_node* item)
{
	struct list_node* tmpitem = NULL;

	if (!item || !list)
		return;

	if (item->next)
		tmpitem = item->next;

	while (list->next != NULL) {
		if (list->next == item) {
			free(item);
			list->next = tmpitem;
			return;
		}

		list = list->next;
	}
}

void delete_list(struct list_node* list)
{
struct list_node* tmp;

	while(list){
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
