// Emily (Thien-Huong) Tran
// ID: tnt5tz
// File: heap.cpp
// Date: November 22, 2011

// I used/adapted the code from the Weiss book

#include "heap.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

// heap node methods
huffNode::huffNode(char c, int x) {
    left = NULL;
    right = NULL;
    value = c;
    freq = x; 
}

huffNode::~huffNode() {
    if (left != NULL) {
        delete left;
    }
    
    if (right != NULL) {
        delete right;
    }
}

void huffNode::insertPrefix(huffNode *cur, char c, string code) {
    if (code.length() > 0) {
        // handles 0
        if (code[0] == '0') {
            if (cur->left == NULL) {
                huffNode *n = new huffNode('-', 0);
                cur->left = n;
                insertPrefix(cur->left, c, code.substr(1)); 
            }
            else {
                insertPrefix(cur->left, c, code.substr(1)); 
            }
        }
    
    
        // handles 1
        else {
            if (cur->right == NULL) {
                huffNode *n = new huffNode('-', 0);
                cur->right = n; 
                insertPrefix(cur->right, c, code.substr(1));
            }
            else {
                insertPrefix(cur->right, c, code.substr(1)); 
            }
        }
    }

    else {
        cur->value = c; 
    }   

}

// heap methods
heap::heap(int x) {
    h = vector<huffNode*>(x+1);
    s = vector<string>(256);
    size = 0;
}

bool heap::isEmpty() const {
    return size == 0;
}

void heap::insert(huffNode *n) {
    if (size == h.size() - 1) 
        h.resize(h.size() * 2);
    int hole = ++size;
    for (; (hole > 1) && ((n->freq) < (h[hole/2]->freq)); hole /= 2) {
        h[hole] = h[hole/2];
    }
    h[hole] = n; 
}

huffNode* heap::deleteMin() {
    if (isEmpty()) 
        cout << "The heap is empty!" << endl;
    
    huffNode *tmp = h[1];   

    h[1] = h[size--];
    percolateDown(1);
    return tmp;
}

huffNode* heap::getMin() {
    return h[1];
}

void heap::percolateDown(unsigned int hole) {
    unsigned int ch;
    huffNode *tmp; 
    tmp = h[hole];

    for (; hole*2 <= size; hole = ch) {
        ch = hole*2;
        if (ch != size && (h[ch + 1]->freq) < (h[ch]->freq)) 
            ch++;
        if ((h[ch]->freq) < (tmp->freq)) 
            h[hole]= h[ch];
        else 
            break;
    }
    h[hole] = tmp;
}

void heap::createHuff() {
    huffNode *internal;
    while (size > 1) {
        huffNode *tmp1 = deleteMin();
        huffNode *tmp2 = deleteMin();
        int f = (tmp1->freq) + (tmp2->freq);
        internal = new huffNode('-', f); 
        internal->left = tmp1;
        internal->right = tmp2;
        insert(internal);
    }
}

void heap::prefix(huffNode *n, string path) {
    if (n->left == NULL && n->right == NULL) {
        cout << n->value << " " << path << endl;
        s[n->value] = path; 
    }
    else {
        prefix(n->left, (path + "0"));
        prefix(n->right, (path + "1"));     
    }
}   