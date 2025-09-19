
class Spreadsheet {
private:
    vector<vector<int>> grid;
    int rows;

    pair<int, int> parseCell(const string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }

public:
    Spreadsheet(int rows) : rows(rows) {
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        if (formula[0] == '=') {
            formula = formula.substr(1);
        }
        stringstream ss(formula);
        string part;
        int sum = 0;
        while (getline(ss, part, '+')) {
            if (isalpha(part[0])) {
                auto [row, col] = parseCell(part);
                sum += grid[row][col];
            } else {
                sum += stoi(part);
            }
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */