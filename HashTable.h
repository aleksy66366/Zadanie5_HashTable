#pragma once

#include <iostream>
#include <String>
#include <cmath>

#include <locale.h>
#include <conio.h>

#include "SLL.h"

struct Tables {
    SLL<int> intTab;
    SLL<float> floatTab;
    SLL<char> charTab;
    SLL<std::string> stringTab;
};

class HashTable {
public:
    Tables* tab;
    int size;
    int used;

    HashTable() {
        tab = new Tables[10];
        size = 10;
        used = 0;
    }

    unsigned long long int hash(std::string key) {
        unsigned long long int size = std::size(key);
        unsigned long long int result = 0;
        for (unsigned long long int s = 0, q = 1; s < size; s++, q++)  result += (int)abs(pow((int)key[s] - 48, size - q));
        result = result % this->size;
        return result;
    }
   
    void add(int a) {
        std::system("cls");
        std::cout << "Wielkoœæ: " << this->size << "\t Stop. Zape³nienia: " << (double)this->used / (double)this->size << "\n";
        std::cout << "Wybierz opcje dzia³añ na tablicy:\n1.Dodaj element:\n\t1.int\n\t2.float\n\t3.char\n\t4.string\n2.Usuñ element\n3.Poka¿ element\n4.Poka¿ wszystko\n5.Usuñ wszystko\n6.SprawdŸ klucz\n7.Koniec\n->:" << a << ".";
        int b;
        std::cin >> b;
        if (b == 1) {
            int value;
            std::string key;

            std::cout << "\nPodaj klucz: ";
            std::cin >> key;
            std::cout << "Podaj wartoœc: ";
            std::cin >> value;

            long long int index = hash(key);
            int test = this->tab[index].intTab.add(key, value);
            if (test == 1) {
                std::cout << "Dodano: " << key << " -> " << value;
                this->used++;
            }
            else std::cout << "Edytowano na: " << key << " -> " << value;

            std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
            _getch();
        }
        else if (b == 2) {
            float value;
            std::string key;

            std::cout << "\nPodaj klucz: ";
            std::cin >> key;
            std::cout << "Podaj wartoœc: ";
            std::cin >> value;

            long long int index = hash(key);
            int test = this->tab[index].floatTab.add(key, value);
            if (test == 1) {
                std::cout << "Dodano: " << key << " -> " << value;
                this->used++;
            }
            else std::cout << "Edytowano na: " << key << " -> " << value;

            std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
            int _getch();
        }
        else if (b == 3) {
            char value;
            std::string key;

            std::cout << "\nPodaj klucz: ";
            std::cin >> key;
            std::cout << "Podaj wartoœc: ";
            std::cin >> value;

            long long int index = hash(key);
            int test = this->tab[index].charTab.add(key, value);
            if (test == 1) {
                std::cout << "Dodano: " << key << " -> " << value;
                this->used++;
            }
            else std::cout << "Edytowano na: " << key << " -> " << value;

            std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
            int _getch();
        }
        else if (b == 4) {
            std::string value;
            std::string key;

            std::cout << "\nPodaj klucz: ";
            std::cin >> key;
            std::cout << "Podaj wartoœc: ";
            std::cin >> value;

            long long int index = hash(key);
            int test = this->tab[index].stringTab.add(key, value);
            if (test == 1) {
                std::cout << "Dodano: " << key << " -> " << value;
                this->used++;
            }
            else std::cout << "Edytowano na: " << key << " -> " << value;

            std::cout << "Dodano: " << key << " -> " << value;
            std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
            int _getch();
        }
        else {
            long long int index[16];
            index[0] = hash("aba");
            index[1] = hash("baba");
            index[2] = hash("caba");
            index[3] = hash("daba");
            index[4] = hash("eba");
            index[5] = hash("faba");
            index[6] = hash("gaba");
            index[7] = hash("haba");
            index[8] = hash("iba");
            index[9] = hash("jaba");
            index[10] = hash("kaba");
            index[11] = hash("laba");
            index[12] = hash("maba");
            index[13] = hash("naba");
            index[14] = hash("oba");
            index[15] = hash("paba");

            int test;
            test = this->tab[index[0]].intTab.add("aba", 1);
            if (test == 1) this->used++;
            test = this->tab[index[1]].intTab.add("baba", 2);
            if (test == 1) this->used++;
            test = this->tab[index[2]].intTab.add("caba", 3);
            if (test == 1) this->used++;
            test = this->tab[index[3]].intTab.add("daba", 4);
            if (test == 1) this->used++;

            test = this->tab[index[4]].floatTab.add("eba", 1.5);
            if (test == 1) this->used++;
            test = this->tab[index[5]].floatTab.add("faba", 2.5);
            if (test == 1) this->used++;
            test = this->tab[index[6]].floatTab.add("gaba", 3.5);
            if (test == 1) this->used++;
            test = this->tab[index[7]].floatTab.add("haba", 4.5);
            if (test == 1) this->used++;

            test = this->tab[index[8]].charTab.add("iba", 'a');
            if (test == 1) this->used++;
            test = this->tab[index[9]].charTab.add("jaba", 'b');
            if (test == 1) this->used++;
            test = this->tab[index[10]].charTab.add("kaba", 'c');
            if (test == 1) this->used++;
            test = this->tab[index[11]].charTab.add("laba", 'd');
            if (test == 1) this->used++;

            test = this->tab[index[12]].stringTab.add("maba", "abc");
            if (test == 1) this->used++;
            test = this->tab[index[13]].stringTab.add("naba", "bcd");
            if (test == 1) this->used++;
            test = this->tab[index[14]].stringTab.add("oba", "cde");
            if (test == 1) this->used++;
            test = this->tab[index[15]].stringTab.add("paba", "def");
            if (test == 1) this->used++;
        }
    }
    void del() {
        std::string key;

        std::cout << "\nPodaj klucz: ";
        std::cin >> key;

        long long int index = hash(key);
        int a, b, c, d;
        a = tab[index].intTab.del(key);
        b = tab[index].floatTab.del(key);
        c = tab[index].charTab.del(key);
        d = tab[index].stringTab.del(key);

        if (a == 1 || b == 1 || c == 1 || d == 1) {
            std::cout << "Uda³o siê usun¹æ element";
            this->used--;
        }
        else std::cout << "Podany klucz nie istnieje w bazie danych";

        std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
        _getch();
    }
    void delAll(){
        delete[]tab;
        tab = new Tables[10];
        size = 10;
        used = 0;
    }

    void rehash() {
        Tables* tmp = new Tables;
        for (int i = 0; i < size; i++) {
            Node<int>* tmp2 = tab[i].intTab.head;
            while (tmp2 != NULL) {
                tmp->intTab.add(tmp2->key, tmp2->value);
                tmp2 = tmp2->child;
            }
            delete[]tmp2;
            Node<float>* tmp3 = tab[i].floatTab.head;
            while (tmp3 != NULL) {
                tmp->floatTab.add(tmp3->key, tmp3->value);
                tmp3 = tmp3->child;
            }
            delete[]tmp3;
            Node<char>* tmp4 = tab[i].charTab.head;
            while (tmp4 != NULL) {
                tmp->charTab.add(tmp4->key, (char)tmp4->value);
                tmp4 = tmp4->child;
            }
            delete[]tmp4;
            Node<std::string>* tmp5 = tab[i].stringTab.head;
            while (tmp5 != NULL) {
                tmp->stringTab.add(tmp5->key, tmp5->value);
                tmp5 = tmp5->child;
            }
            delete[]tmp5;
        }
        size = size * 2;
        delete[] tab;
        tab = new Tables[size];

        Node<int>* tmp2 = tmp->intTab.head;
        while (tmp2 != NULL) {
            long long int index = hash(tmp2->key);
            tab[index].intTab.add(tmp2->key, tmp2->value);
            tmp2 = tmp2->child;
        }
        Node<float>* tmp3 = tmp->floatTab.head;
        while (tmp3 != NULL) {
            long long int index = hash(tmp3->key);
            tab[index].floatTab.add(tmp3->key, tmp3->value);
            tmp3 = tmp3->child;
        }
        Node<char>* tmp4 = tmp->charTab.head;
        while (tmp4 != NULL) {
            long long int index = hash(tmp4->key);
            tab[index].charTab.add(tmp4->key, tmp4->value);
            tmp4 = tmp4->child;
        }
        Node<std::string>* tmp5 = tmp->stringTab.head;
        while (tmp5 != NULL) {
            long long int index = hash(tmp5->key);
            tab[index].stringTab.add(tmp5->key, tmp5->value);
            tmp5 = tmp5->child;
        }
    }

    void print() {
        std::string key;

        std::cout << "\nPodaj klucz: ";
        std::cin >> key;

        long long int index = hash(key);
        Node<int>* tmp1 = tab[index].intTab.search(key);
        Node<float>* tmp2 = tab[index].floatTab.search(key);
        Node<char>* tmp3 = tab[index].charTab.search(key);
        Node<std::string>* tmp4 = tab[index].stringTab.search(key);

        if (tmp1 != NULL) {
            std::cout << tmp1->print();
        }
        if (tmp2 != NULL) {
            std::cout << tmp2->print();
        }
        if (tmp3 != NULL) {
            std::cout << tmp3->print();
        }
        if (tmp4 != NULL) {
            std::cout << tmp4->printString();
        }
        if (tmp1 == NULL && tmp2 == NULL && tmp3 == NULL && tmp4 == NULL) {
            std::cout << "Podany klucz nie istnieje w bazie danych";
        }

        std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
        _getch();
    }
    void printAll() {
        std::system("cls");
        for (int i = 0; i < size; i++) {
            std::string tmp = "";
            tmp += tab[i].charTab.print();
            tmp += tab[i].floatTab.print();
            tmp += tab[i].intTab.print();
            tmp += tab[i].stringTab.printString();
            if (tmp != "")std::cout << i << " ------------------------------\n" << tmp;
        }
        std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
        _getch();
    }
    void test() {
        std::string key;
        std::cout << "\nPodaj klucz który chcesz zamieniæ:";
        std::cin >> key;
        long long int result;
        result = hash(key);
        std::cout << "Klucz ma wartoœæ: " << result;
        std::cout << "\n\nWciœnij dowolny przycisk by kontynuowaæ";
        _getch();
    }
   
    void menu() {
        setlocale(LC_ALL, "");
        bool loop = true;
        while (loop) {
            while ((double)this->used / (double)this->size >= 1) {
                rehash();
            }
            std::system("cls");
            std::cout << "Wielkoœæ: " << this->size << "\t Stop. Zape³nienia: " << (double)this->used / (double)this->size << "\n";
            std::cout << "Wybierz opcje dzia³añ na tablicy:\n1.Dodaj element:\n\t1.int\n\t2.float\n\t3.char\n\t4.string\n2.Usuñ element\n3.Poka¿ element\n4.Poka¿ wszystko\n5.Usuñ wszystko\n6.SprawdŸ klucz\n7.Koniec\n->:";
            int a;
            std::cin >> a;
            if (a == 1) add(a);
            else if (a == 2) del();
            else if (a == 3) print();
            else if (a == 4) printAll();
            else if (a == 5) delAll();
            else if (a == 6) test();
            else loop = false;
        }
    }
};














