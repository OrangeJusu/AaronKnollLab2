#pragma once
#ifndef UnsortedType1_h

#include <iostream>
#include "ItemType.h"

class UnsortedType {
private:
    ItemType* front;
    ItemType* current;
    Relation compare;
    int maxItems;

public:
    UnsortedType() {
        front = nullptr;
        current = front;
        maxItems = 10;
    }

    void addItem(int data) {
        ItemType* newItem = new ItemType(data);
        if (front == nullptr) {
            front = newItem;
        }
        else {
            resetList();
            while (current->next != nullptr) {
                getNextItem();
            }
            current->next = newItem;
        }
    }

    void deleteItem(int value) {
        if (front->data == value && front->next == nullptr) {
            front = nullptr;
        }
        current = front;
        while (current != nullptr) {
            if (current->next->data == value) {
                current->next = current->next->next;
                break;
            }
            getNextItem();
        }
    }

    ItemType* Search(int value) {
        ItemType* neededItem = new ItemType();
        current = front;
        if (front->data == value) {
            neededItem = front;
            return neededItem;
        }
        while (current != nullptr) {
            if (current->data == value) {
                neededItem = current;
                return neededItem;
            }
            getNextItem();
        }
        return nullptr;
    }

    void getNextItem() {
        current = current->next;
    }

    void makeEmpty() {
        current = front;
        front = nullptr;
        while (current != nullptr){
            current = nullptr;
            getNextItem();
        }
    }

    bool isFull() {
        current = front;
        int i = 0;
        while (current != nullptr) {
            getNextItem();
            i++;
        }
        if (i == maxItems) {
            return true;
        }
        return false;
    }

    void resetList() {
        current = front;
    }

    int getLength() {
        resetList();
        int i = 0;
        while (current != nullptr) {
            i++;
        }
        return i;
    }

    void ComparedTo(ItemType* i1, ItemType* i2) {
        resetList();
        while (current != nullptr){
            if (current == i1 && current == i2) {
                compare = EQUAL;
                break;
            }
            else if (current == i1) {
                compare = GREATER;
                break;
            }
            else if (current == i2) {
                compare = LESS;
                break;
            }
            getNextItem();
        }
    }

    UnsortedType Union(UnsortedType l1, UnsortedType l2) {
        resetList();
        l1.resetList();
        l2.resetList();
        UnsortedType newList = l1;
        while (l2.current != nullptr){
            if(newList.Search(l2.current->data) == nullptr){
                newList.addItem(l2.current->data);
            }
            l2.getNextItem();
        }
        return newList;
    }

    void display() {
        resetList();
        while (current != nullptr){
            cout << current->data << endl;
            getNextItem();
        }
    }
};

#endif
