#pragma once
#ifndef ItemType_h
#include <string>

using namespace std;

enum Relation{
	LESS,
	GREATER,
	EQUAL
};

class ItemType {
public:
    int data;
    ItemType* next;

    ItemType() {
        this->data = NULL;
        this->next = nullptr;
    }

    ItemType(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

#endif
