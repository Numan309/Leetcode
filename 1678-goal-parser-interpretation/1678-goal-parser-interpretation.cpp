class Solution {
public:
    string interpret(string command) {
    string result; // To store the final result
    int n = command.size();
    
    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && command[i] == '(' && command[i + 1] == ')') {
            result += 'o'; // Replace '()' with 'o'
            i++; // Skip the next character since it's part of '()'
        } else if (command[i] == '(' || command[i] == ')') {
         
            continue;
        } else {
            result += command[i]; // Append other characters
        }
    }
        return result;
}
};