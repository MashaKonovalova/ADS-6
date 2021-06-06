// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string>btree;
    std::string Word = "";
    char lowerletter = 'a' - 'A';
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return btree;
    }
    while (!file.eof()) {
        char ch = file.get();
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch >= 'A' && ch <= 'Z')
                ch += lowerletter;
            Word += ch;
        } else if (Word != "") {
            btree.add(Word);
            Word = "";
        }
    }
    file.close();
    return btree;
}
