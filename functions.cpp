//
// Created by Erik Gabrielsen on 2/20/23.
//

#include "functions.h"

vector<vector<string>> readTable(ifstream &file) {
    /** Implement this function that uses the file stream object, file,
     and creates a 2D vector with the data that is read from the file.
     You will use this function twice, one for Authors, one for Books.
     **/

    vector<vector<string>> data; // creates 2D vector
    string store; // creates a string to read file into

    while (getline(file, store)) { // uses getline to read the file into the string
        istringstream hold(store); // the string is then put into a stringstream
        vector<string> temporary; // a string vector is created
        while (getline(hold, store, ',')) { // uses getline to read the stringstream into a string vector, separating by commas
            temporary.push_back(store); // pushes the string into the string vector
        }
        data.push_back(temporary); // pushes the string vector into the 2D vector
    }
        return data;
}

void writeTable(ofstream &file, const vector<vector<string>> &table) {
    /** Implement this function - It should write the contends of any
     * 2D vector to a file object, file, in csv format
     **/

    for(int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.at(i).size(); j++) {
                if(j != table.at(i).size() - 1) { // this if statement only prints a comma if it is not the last word in the line
                    file << table[i][j] << ",";
                }
                else {
                    file << table[i][j]; // if it is the last word
                }
        }
        file << endl;
    }
}

vector<vector<string>> innerJoin(vector<vector<string>> &leftTable, vector<vector<string>> &rightTable) {
    /** This function should create a new 2D vector that is a "join" of leftTable and rightTable.
     *  You will join the data based on the AUTHOR_ID
     **/
    vector<vector<string>> table;
    vector<string> temp1;

    for(int i = 0; i < leftTable.size(); i++) { // loops through the left table
        temp1 = leftTable[i]; // stores left table at i into a vector string
        if (i == 0) {
            vector<string> temp = temp1; // stores the vector
            temp.insert(temp.end(),rightTable[0].begin() + 1,rightTable[0].end()); // inserts the right table into the temp vector
            table.push_back(temp); // inserts the temp vector into the 2D table vector
        }
        for (int j = 0; j  < rightTable.size(); j++) { // loops through the right table
            if (leftTable[i][1] == rightTable[j][0]) { // checks to see if the ID's are the same
                vector<string> temp = temp1; // stores the vector
                temp.insert(temp.end(),rightTable[j].begin() + 1,rightTable[j].end()); // inserts the right table into the temp vector
                table.push_back(temp); // inserts the temp vector into the 2D table vector
            }

        }
    }
    for (int g = 0; g < table.size(); g++) { // for loop to delete the first two columns
        table.at(g).erase(table.at(g).begin() + 1);
        table.at(g).erase(table.at(g).begin() + 0);
    }
    return table;
}
