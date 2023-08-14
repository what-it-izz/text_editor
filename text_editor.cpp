#include <iostream>
#include <vector>
#include <string>

class TextEditor {
private:
    std::vector<std::string> lines;
    int cursorLine;
    int cursorColumn;

public:
    TextEditor() {
        lines.push_back("");
        cursorLine = 0;
        cursorColumn = 0;
    }

    void insertCharacter(char ch) {
        lines[cursorLine].insert(cursorColumn, 1, ch);
        cursorColumn++;
    }

    void insertNewLine() {
        std::string restOfLine = lines[cursorLine].substr(cursorColumn);
        lines[cursorLine].erase(cursorColumn);
        lines.insert(lines.begin() + cursorLine + 1, restOfLine);
        cursorLine++;
        cursorColumn = 0;
    }

    void display() {
        for (const auto& line : lines) {
            std::cout << line << '\n';
        }
    }

};

int main() {
    TextEditor editor;

    std::cout << "Simple Text Editor. Type your text below (enter 'exit' to quit):\n";

    std::string inputLine;
    while (true) {
        std::getline(std::cin, inputLine);
        if (inputLine == "exit") break;

        for (char ch : inputLine) {
            editor.insertCharacter(ch);
        }
        editor.insertNewLine();
    }

    std::cout << "\nYour text:\n";
    editor.display();

    return 0;
}
