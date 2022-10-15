#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------


class Comparison {
public:
    bool operator() (int x) {
        return (x % 2 == 0);
    }
} predicate;



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    
    // Pivot test
    {
        Node* input = readList(argv[1]);
        Node* smaller = NULL;
        Node* larger = NULL;
        cout << "LLPIVOT:\n";

        cout << "Original lists (input, smaller, larger):\n";
        print(input);
        print(smaller);
        print(larger);

        cout << "Pivoting...\n";
        // Test out your linked list code
        llpivot (input, smaller, larger, 5);

        // Print again
        cout << "After llrec (input, smaller, larger):\n";
        print(input);
        print(smaller);
        print(larger);

        // Clean up.
        dealloc(input);
        dealloc(smaller);
        dealloc(larger);
    }

    // // Filter test
    // {
    //     Node* input = readList(argv[1]);
    //     cout << "LLFITLER:\n";

    //     cout << "Origioinal list (input):\n";
    //     print(input);

    //     // Test out your linked list code
    //     cout << "Filtering...\n";
    //     Node* filtered = llfilter<Comparison>(input, predicate);

    //     // Print again
    //     cout << "After llfilter (input, filtered):\n";
    //     print(input);
    //     print(filtered);

    //     // Clean up.
    //     dealloc(input);
    //     dealloc(filtered);
    // }
    
    return 0;

}
