#include <iostream>
#include <string>
using namespace std;

int countUnmatchedLetters(string name1, string name2) {
    for (int i = 0; i < name1.length(); i++) {
        for (int j = 0; j < name2.length(); j++) {
            if (name1[i] == name2[j]) {
                name1[i] = name2[j] = '*';  
                break;
            }
        }
    }

    int count = 0;
    for (char c : name1) {
        if (c != '*') count++;
    }
    for (char c : name2) {
        if (c != '*') count++;
    }
    return count;
}

char getFlamesResult(int count) {
    string flames = "FLAMES";
    int index = 0;

    while (flames.length() > 1) {
        index = (index + count - 1) % flames.length();
        flames.erase(flames.begin() + index);
    }
    return flames[0];
}

int main() {
    string name1, name2;
    cout << "Enter the first name: ";
    cin >> name1;
    cout << "Enter the second name: ";
    cin >> name2;

    int unmatchedCount = countUnmatchedLetters(name1, name2);
    char result = getFlamesResult(unmatchedCount);

    cout << "The relationship is: ";
    switch (result) {
        case 'F': cout << "Friends"; break;
        case 'L': cout << "Love"; break;
        case 'A': cout << "Affection"; break;
        case 'M': cout << "Marriage"; break;
        case 'E': cout << "Enemies"; break;
        case 'S': cout << "Siblings"; break;
    }
    cout << endl;

    return 0;
}
