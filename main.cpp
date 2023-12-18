#include <iostream>
#include "functions.h"

int main() { // main

    ofstream file("../Results.csv"); //ofstream for results, include "../"
    ifstream file1;
    ifstream file2;
    file1.open("../Books.csv"); // opens Books.csv
    file2.open("../Authors.csv"); // opens Authors.csv

    if(!file1) { // both statements let user know of error if file does not open
        cout << "Error occurred while reading Books.txt" << endl;
    }
    else if(!file2) {
        cout << "Error occurred while reading Authors.txt" << endl;
    }

    vector<vector<string>> books; // lines 19-21 create 2D vectors for the functions
    vector<vector<string>> authors;
    vector<vector<string>> inner;

    books = readTable(file1);
    authors = readTable(file2);

    inner = innerJoin(books, authors); // sends books and authors to innerJoin

    writeTable(file, inner); // sends to writeTable

    file1.close(); // lines 30-31 closes files once they are done being used
    file2.close();

    return 0;
}
