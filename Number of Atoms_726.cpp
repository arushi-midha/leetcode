/*
Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

 

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 

Constraints:

1 <= formula.length <= 1000
formula consists of English letters, digits, '(', and ')'.
formula is always valid.
*/

class Solution {
public:
    string countOfAtoms(string formula) {
        // Recursively parse the formula
        unordered_map<string, int> finalMap = parseFormula(formula);

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }

    // Recursively parse the formula
    unordered_map<string, int> parseFormula(string& formula) {
        // Local variable
        unordered_map<string, int> currMap;
        string currAtom;
        string currCount;

        // Iterate until the end of the formula
        while (index < formula.length()) {
            // UPPERCASE LETTER
            if (isupper(formula[index])) {
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                currAtom = formula[index];
                currCount = "";
                index++;
            }

            // lowercase letter
            else if (islower(formula[index])) {
                currAtom += formula[index];
                index++;
            }

            // Digit. Concatenate the count
            else if (isdigit(formula[index])) {
                currCount += formula[index];
                index++;
            }

            // Left Parenthesis
            else if (formula[index] == '(') {
                index++;
                unordered_map<string, int> nestedMap = parseFormula(formula);
                for (auto& [atom, count] : nestedMap) {
                    currMap[atom] += count;
                }
            }

            // Right Parenthesis
            else if (formula[index] == ')') {
                // Save the last atom and count of nested formula
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                index++;
                string multiplier;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                return currMap;
            }
        }

        // Save the last atom and count
        if (!currAtom.empty()) {
            if (currCount.empty()) {
                currMap[currAtom] += 1;
            } else {
                currMap[currAtom] += stoi(currCount);
            }
        }

        return currMap;
    }

private:
    // Global variable
    int index = 0;
};