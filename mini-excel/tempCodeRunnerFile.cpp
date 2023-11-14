lass Cell
{
public:
    int data;
    Cell *left;
    Cell *right;
    Cell *up;
    Cell *down;
    Cell(int val)
    {
        data = val;
        up = nullptr;
        down = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class Excel
{
public:
    int rows;
    int col;
    Cell *head;
    Cell *pre;
    Cell *next;
    Cell *current;
    Cell *origionalHead;
    Excel(int rows, int cols)
    {
        this->rows = rows;
        this->col = cols;
        head = next = pre = nullptr;
        createGrid();
    }