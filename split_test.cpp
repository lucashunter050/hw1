//
//  split_test.cpp
//  project1
//
//  Created by Lucas Hunter on 8/24/22.
//

#include <iostream>
#include "split.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Node * n1 = new Node(11, nullptr);
    Node * n2 = new Node(10, n1);
    Node * n3 = new Node(9, n2);
    Node * n4 = new Node(8, n3);
    Node * n5 = new Node(7, n4);
    Node * n6 = new Node(6, n5);
    Node * n7 = new Node(5, n6);
    Node * n8 = new Node(4, n7);
    Node * n9 = new Node(3, n8);
    Node * n10 = new Node(0, n9);
    Node * n11 = new Node(-1, n10);

    Node * curr = n11;

    std::cout << "Outputting the list normally" << std::endl;
    while (curr) {
        std::cout << curr->value << std::endl;
        curr = curr->next;
    }

    std::cout << "Splitting the list:" << std::endl << std::endl;

    Node* evens = nullptr;
    Node* odds = nullptr;

    split(n11, odds, evens);

    std::cout << "split successful!" << std::endl << std::endl;

    curr = n11;
    std::cout << "outputting the original list: ";
    if (curr) {
        std::cout << curr->value << " ";
        curr = curr->next;
    } else {
        std::cout << "original list is empty, success!" << std::endl;
    }

    std::cout << std::endl << std::endl;

    std::cout << "outputting odds: ";

    curr = odds;
    while (curr) {
        std::cout << curr->value << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
    std::cout << "output of odd numbers finished" << std::endl;

    curr = evens;

    std::cout << std::endl << std::endl << "outputting evens: ";
    while (curr) {
        std::cout << curr->value << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
    std::cout << "output of even numbers finished" << std::endl;

    // deallocate
    /*
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;
    delete n8;
    delete n9;
    delete n10;
    delete n11;
    delete curr;
    delete evens;
    delete odds;*/

    while (evens != nullptr) {
        curr = evens;
        evens = evens->next;
        delete curr;
        curr = nullptr;
    }

    while (odds != nullptr) {
        curr = odds;
        odds = odds->next;
        delete curr;
        curr = nullptr;
    }


    return 0;
}
