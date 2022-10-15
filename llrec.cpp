#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
	// Check if end of source list has been reached.
	if (head == NULL) {
		smaller = NULL;
		larger = NULL;
		return;
	}

	// Next item to classify in the source list. Prevents llpivot from losing track of
	// the next node it needs to classify when the head node gets put at the end of
	// one of the target lists. It is important for this not to be a reference.
	Node* next = head->next;

	// Determine which list to put this node in
	if (head->val <= pivot) {
		// Points smaller->next from the previous recursion step to current node.
		smaller = head;
		// Either point "smaller->next" or "larger" to the next node.
		llpivot(next, smaller->next, larger, pivot);
	} else {
		// Points larger->next from the previous recursion step to current node.
		larger = head;
		// Either point "smaller" or "larger->next" to the next node.
		llpivot(next, smaller, larger->next, pivot);
	}
}