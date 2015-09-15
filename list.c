#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);


	//handle unique case of new_element < head
	if(new_element->index < head->index)
	  {
	  new_element->next = head;
	  head = new_element;
	  return head;
	  }
	
	
	list_t* prev = head;

	//loop through list and compare each element to the new one
	while(prev->next)
	  {
	    //if new is less than current insert it
	    if(new_element->index < prev->next->index)
	      {
		new_element->next = prev->next;
		prev->next = new_element;
		return head;
	      }
	  
	    prev = prev->next;
	    
	  }
	

	//handles unique case of new_element > last in list
	prev->next = new_element;
	new_element->next = NULL;
	
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	
	list_t* hold = head;
	list_t* grab = head->next;
	list_t* last = NULL;
	
	while(hold->next)
	  {
	    hold->next = last;
	    last = hold;

	    hold = grab;
	    grab = hold->next;
	  }

	hold->next = last;

	head = hold;

	return head;
}

