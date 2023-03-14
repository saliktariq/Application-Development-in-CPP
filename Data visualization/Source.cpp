#include <iostream>
#include <iomanip> // for setw()
#include <string>
#include <vector>

using namespace std;

int main() {
    string title;
    vector<string> data_strings;
    vector<int> data_integers;
    string input, data_string, data_integer_string;

    // Prompt the user for a title
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl << endl;

    string header1, header2;

    // Prompt the user for the first column header
    cout << "Enter the column 1 header:" << endl;
    getline(cin, header1);
    cout << "You entered: " << header1 << endl << endl;

    // Prompt the user for the second column header
    cout << "Enter the column 2 header:" << endl;
    getline(cin, header2);
    cout << "You entered: " << header2 << endl << endl;

    // Prompt the user for data points until they enter -1
    while (true) {
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, input);

        if (input == "-1") {
            break;
        }

        // Find the positions of the commas
        size_t pos1 = input.find(',');
        size_t pos2 = input.find(',', pos1 + 1);

        // Check for errors
        if (pos1 == string::npos) {
            cout << "Error: No comma in string.\n" << endl;
            continue;
        }
        else if (pos2 != string::npos) {
            cout << "Error: Too many commas in input.\n" << endl;
            continue;
        }

        // Extract the string and integer components from the input
        data_string = input.substr(0, pos1);
        data_integer_string = input.substr(pos1 + 1);

        try {
            int data_integer = stoi(data_integer_string);

            // Store the string and integer components in the vectors
            data_strings.push_back(data_string);
            data_integers.push_back(data_integer);
            cout << "Data string: " << data_string << endl;
            cout << "Data integer: " << data_integer << endl << endl;
        }
        catch (invalid_argument) {
            cout << "Error: Comma not followed by an integer.\n" << endl;
            continue;
        }
    }

    // Output the title, right-justified with setw()
    cout <<  endl << setw(33) << right << title << endl;

    // Output the first column header
    cout << setw(20) << left << header1 << "|";

    // Output the second column header, with setw()
    cout << setw(23) << right << header2 << endl;

    // Draw the table's border
    cout << setfill('-') << setw(20) << left << "-" << setw(24) << "-" << endl;
    cout << setfill(' '); // reset the fill character

    // Output the string and integer components
    for (size_t i = 0; i < data_strings.size(); i++) {
        cout << setw(20) << left << data_strings[i] << "|" << setw(23) << right << data_integers[i] << endl;
    }

    cout << endl;

    // Output the information as a formatted histogram. Each name is right justified with a setw() value of 20
    for (size_t i = 0; i < data_strings.size(); i++) {
        cout << setw(20) << right << data_strings[i] << " ";
        cout << string(data_integers[i], '*') << endl;
    }

    return 0;
}
