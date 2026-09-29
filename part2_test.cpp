#include <iostream>
#include <string>

using namespace std;

// 1. Result codes for Meta-Commands (commands starting with '.')
enum MetaCommandResult {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
};

// 2. Result codes for SQL Statements (like insert or select)
enum PrepareResult {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
};

// 3. What kind of SQL statement is it?
enum StatementType {
    STATEMENT_INSERT,
    STATEMENT_SELECT
};

struct Statement {
    StatementType type;
};

// Function A: Handles non-SQL commands starting with '.'
MetaCommandResult do_meta_command(const string& input) {
    if (input == ".exit") {
        cout << "Exiting database.\n";
        exit(0);
    }
    return META_COMMAND_UNRECOGNIZED_COMMAND;
}

// Function B: The "Compiler" - understands SQL keywords
PrepareResult prepare_statement(const string& input, Statement& statement) {
    if (input.rfind("insert", 0) == 0) { // starts with "insert"
        statement.type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (input == "select") {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

// Function C: The "Virtual Machine" - executes the statement
void execute_statement(const Statement& statement) {
    switch (statement.type) {
        case STATEMENT_INSERT:
            cout << "This is where we would do an insert.\n";
            break;
        case STATEMENT_SELECT:
            cout << "This is where we would do a select.\n";
            break;
    }
}

int main() {
    string input;

    while (true) {
        cout << "db > ";
        if (!getline(cin, input)) {
            break;
        }

        // Check if command starts with '.' (meta-command)
        if (!input.empty() && input[0] == '.') {
            switch (do_meta_command(input)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED_COMMAND:
                    cout << "Unrecognized command '" << input << "'.\n";
                    continue;
            }
        }

        // Otherwise, try to understand it as an SQL statement
        Statement statement;
        switch (prepare_statement(input, statement)) {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                cout << "Unrecognized keyword at start of '" << input << "'.\n";
                continue;
        }

        execute_statement(statement);
        cout << "Executed.\n";
    }

    return 0;
}
