#include <iostream>
using namespace std;

struct Node {
public:
    Node* left;
    Node* right;
    int value;
};

class Heap {
public:

    short size;
    Node* heap;


    Heap();
    bool addToHeap(int data);
    void findLeavesSum(Node* child, int& sum);
    int findHeapSum();

};

Heap::Heap() {
    heap = NULL;
    size = 0;
}

void Heap::findLeavesSum(Node* child, int& sum) {
    if (child != NULL) {
        sum += child->value;
        findLeavesSum(child->left, sum);
        findLeavesSum(child->right, sum);
    }

}

int Heap::findHeapSum() {
    int sum = 0;
    this->findLeavesSum(heap, sum);
    return sum;
}

bool Heap::addToHeap(int value) {
    Node* tempNode, *temp = heap;
    Node* parent = NULL;

    int tempValue;
    int index;

    short mask = 0x80;

    tempNode = new Node;

    size++;
    index = size;

    while (!(index & mask)) {
        index <<= 1;
    }
    index <<= 1;

    while (temp) {

        if (value > temp->value) {
            tempValue = temp->value;
            temp->value = value;
            value = tempValue;
        }

        parent = temp;

        if (!(index & mask)) {
            temp = temp->left;
        }
        else { 
            temp = temp->right; 
        }

        if (temp) {
            index <<= 1;
        }
    }

    tempNode->left = NULL;
    tempNode->right = NULL;
    tempNode->value = value;

    if (!parent) {
        heap = tempNode;
        return true;
    }

    if (!(index & mask)) parent->left = tempNode;
    else parent->right = tempNode;
    return true;
}

int main() {
    Heap heap;

    heap.addToHeap(6);
    heap.addToHeap(9);
    heap.addToHeap(10);
    heap.addToHeap(3);
    heap.addToHeap(1);

    cout <<"Heap sum: " << heap.findHeapSum() << endl;

    return 0;
}