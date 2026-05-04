/**
 * @file ReadNCharactersGivenRead4.cpp
 * @brief Read N Characters Given Read4 - Solution to read n characters from a file using the read4 API
 * @author Mervin Nguyen
 * @date 2026-04-07
 * @version 1.0.0
 */

#include <algorithm>
#include <iostream>
 
using namespace std;

extern int read4(char *buf4);

int read(char *buf, int n){
    int count = 0;
    char buf4[4];

    while(count < n){
        int chars_read = read4(buf4);
        int take = min(chars_read, n - count);

        for (int i = 0; i < take; i++){
            buf[count++] = buf4[i];

            if(chars_read < 4){
                break;
            }
        }
    }
    return count;
}

int main() {
    char buffer[16] = {};

    int first_read = read(buffer, 5);
    buffer[first_read] = '\0';
    cout << "Read " << first_read << " chars: " << buffer << '\n';

    int second_read = read(buffer, 8);
    buffer[second_read] = '\0';
    cout << "Read " << second_read << " chars: " << buffer << '\n';

    return 0;

}