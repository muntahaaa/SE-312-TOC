#include <iostream>
#include <vector>

using namespace std;

int num_of_stage, num_of_input, present_state, final_state, len;
vector<char> stage(10);
vector<int> input_alpha(2);

void printDFA(vector<vector<int>>& table) {
    cout << endl;
    for (int i = 0; i < num_of_stage; i++) {
        for (int j = 0; j < num_of_input; j++) {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
}

void minimize(vector<vector<int>>& table) {
    vector<vector<int>> minArray(num_of_stage, vector<int>(num_of_stage, 0));

    for (int i = 0; i < num_of_stage; i++) {
        for (int j = 0; j < num_of_stage; j++) {
            if (i != j) {
                if ((i == final_state && j != final_state) || (i != final_state && j == final_state))
                    minArray[i][j] = 1;
                else
                    minArray[i][j] = 0;
            } else
                minArray[i][j] = 0;
        }
    }
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < num_of_stage; i++) {
            for (int j = 0; j < num_of_stage; j++) {
                if (i != j && !minArray[i][j]) {
                    for (int input = 0; input < num_of_input; input++) {
                        int state1 = table[i][input];
                        int state2 = table[j][input];
                        if (minArray[state1][state2] || minArray[state1][state2]) {
                            minArray[i][j] = 1;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << "minimized array" << endl;
    for (int i = 0; i < num_of_stage; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << minArray[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter stage number & number of input: ";
    cin >> num_of_stage >> num_of_input;

    for (int i = 0; i < num_of_stage; i++) {
        cout << "Enter stages: ";
        cin >> stage[i];
    }

    for (int j = 0; j < num_of_input; j++) {
        cout << "Enter input alphabet: ";
        cin >> input_alpha[j];
    }

    char p_state, f_state;
    cout << "Enter present & final state: ";
    cin >> p_state >> f_state;
    for (int i = 0; i < num_of_stage; i++) {
        if (p_state == stage[i]) {
            present_state = i;
        }
        if (f_state == stage[i]) {
            final_state = i;
        }
    }
    vector<vector<int>> pS(num_of_stage, vector<int>(num_of_input));
    for (int i = 0; i < num_of_stage; i++) {
        for (int j = 0; j < num_of_input; j++) {
            cout << "Enter transition state for State " << stage[i] << " input " << input_alpha[j] << ": ";
            cin >> pS[i][j];
        }
    }
    cout << "Transition table:" << endl;
    cout << "Final state: " << final_state << endl;
    printDFA(pS);
    minimize(pS);
    return 0;
}
