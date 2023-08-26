#include <string.h>
#include <iostream>
#include <bits/stdint-uintn.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HNode
{
public:
    HNode *next;
    uint64_t hcode = 0;
};

class HTab
{
public:
    HNode **tab = NULL;
    size_t mask = 0;
    size_t slots = 0;
    size_t size = 0;

    HTab() = default;
    HTab(size_t n);

    void insert(HNode *node);
    HNode **h_lookup(HNode *key, bool (*cmp)(HNode *, HNode *));
    HNode *h_detach(HNode **from);
};

class HMap
{
public:
    HTab ht1;
    HTab ht2;
    size_t resizing_pos = 0;

    HNode *hm_lookup(HNode *key, bool (*cmp)(HNode *, HNode *));
    void hm_insert(HNode *node);
    HNode *hm_pop(HNode *key, bool (*cmp)(HNode *, HNode *));

private:
    void hm_help_resizing();
    void hm_start_resizing();
};

#endif