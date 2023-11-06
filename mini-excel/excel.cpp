#include <iostream>
#include <vector>
using namespace std;

class Cell
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

    void createGrid()
    {
        for (int i = 0; i < rows; i++)
        {
            head = new Cell(0);
            if (i == 0)
            {
                origionalHead = head;
            }
            Cell *temp = head;
            // for columns
            int count = 0;
            for (int j = i; j < col; j++)
            {
                if (j == 0)
                {
                    continue;
                }
                Cell *cell = new Cell(0);

                if (next != nullptr && pre != nullptr)
                {
                    if (count == 0)
                    {
                        temp->up = next;
                        next->down = temp;
                        pre->right = temp;
                        temp->left = pre;
                        count++;
                    }
                    else
                    {
                        cell->left = temp;
                        temp->right = cell;
                        next->down = cell;
                        cell->up = next;
                        temp = cell;
                    }

                    next = next->right;
                }
                else
                {
                    temp->right = cell;
                    cell->left = temp;

                    temp = cell;
                }
            }
            count = 0;          // do update the count;
            next = head->right; // do update next;
            // for rows
            temp = head;

            for (int k = i + 1; k < rows; k++)
            {

                Cell *cell = new Cell(0);

                if (next != nullptr && pre != nullptr)
                {
                    pre = pre->down;
                    cell->left = pre;
                    pre->right = cell;
                    cell->up = temp;
                    temp->down = cell;
                    temp = cell;
                }
                else
                {
                    temp->down = cell;
                    cell->up = temp;
                    temp = cell;
                }
            }

            // next = head->right;
            pre = head->down;
        }
        current = head;
        // current = origionalHead;
    }

    void displayGrid()
    {
        Cell *dcolumn = origionalHead;
        while (dcolumn != nullptr) // up is not equal nullptr;
        {
            Cell *temp = dcolumn;
            while (temp != nullptr) // when temp is equal to nulltptr it  means you are at left = nullptr
            {
                cout << temp->data << "-->";
                temp = temp->right;
            }
            cout << "Null" << endl;
            dcolumn = dcolumn->down;
        }
    }

    void insertAtAbove()
    {
        int rowIndex = getRowIndex();
        Cell *oriHead = origionalHead;
        Cell *utlis = nullptr; // previos cell of current inserted;
        if (rowIndex == -1)
        {
            cout << "current idnex not found" << endl;
            return;
        }
        if (rowIndex == 0) // it means there is only one row
        {
            for (int i = 0; i < col; i++)
            {
                Cell *cell = new Cell(1);
                if (i == 0)
                {
                    oriHead->up = cell;
                    cell->down = oriHead;
                    utlis = cell;
                    origionalHead = cell; // update the origional head;
                }
                else
                {
                    oriHead->up = cell;
                    cell->down = oriHead;
                    cell->left = utlis;
                    utlis->right = cell;
                    utlis = cell;
                }
                oriHead = oriHead->right;
            }
            // current = head; no need
            // // current = origionalHead;// do upate the curent
        }
        else
        {
            Cell *cell = new Cell(1);
            for (int i = 0; i < rowIndex; i++) // will give you the row index where you have to insert a row;
            {
                oriHead = oriHead->down;
            }
            for (int i = 0; i < col; i++)
            {
                Cell *temp = oriHead->up;
                if (i == 0)
                {
                    oriHead->up = cell;
                    cell->down = oriHead;
                    cell->up = temp;
                    temp->down = cell;
                    utlis = cell;
                }
                else
                {
                    Cell *newCell = new Cell(1);
                    oriHead->up = newCell;
                    newCell->down = oriHead;
                    newCell->up = temp;
                    temp->down = newCell;
                    utlis->right = newCell;
                    newCell->left = utlis;
                    utlis = newCell; // Update utlis to the newly inserted cell
                }
                oriHead = oriHead->right;
            }
        }
        rows++;
    }
    // onsert a row below to the current cell

    void insertRowBelow()
    {
        int rowIndex = getRowIndex();
        cout << "row index" << rowIndex << endl;
        Cell *oriHead = origionalHead;
        Cell *utlis = nullptr; // previos cell of current inserted;
        if (rowIndex == -1)
        {
            cout << "current idnex not found" << endl;
            return;
        }
        if (rowIndex == 0) // it means there is only one row
        {
            for (int i = 0; i < col; i++)
            {
                Cell *cell = new Cell(1);
                if (i == 0)
                {
                    oriHead->down = cell;
                    cell->up = oriHead;
                    utlis = cell;
                }
                else
                {
                    oriHead->down = cell;
                    cell->up = oriHead;
                    cell->left = utlis;
                    utlis->right = cell;
                    utlis = cell;
                }
                oriHead = oriHead->right;
            }
            // current = head; no need
            // current = origionalHead;// do upate the curent
        }
        else
        {
            Cell *cell = new Cell(1);
            for (int i = 0; i < rowIndex; i++) // will give you the row index where you have to insert a row;
            {
                oriHead = oriHead->down;
            }
            for (int i = 0; i < col; i++)
            {
                Cell *temp = oriHead->down;

                if (rowIndex + 1 == rows)
                {
                    for (int j = 0; j < col; j++)
                    {
                        Cell *cell = new Cell(1);
                        if (j == 0)
                        {
                            oriHead->down = cell;
                            cell->up = oriHead;
                            utlis = cell;
                        }
                        else
                        {
                            oriHead->down = cell;
                            cell->up = oriHead;
                            cell->left = utlis;
                            utlis->right = cell;
                            utlis = cell;
                        }
                        oriHead = oriHead->right;
                    }
                    break; // end the loop as well;
                }
                else if (i == 0)
                {
                    oriHead->down = cell;
                    cell->up = oriHead;
                    cell->down = temp;
                    temp->up = cell;
                    utlis = cell;
                }
                else
                {
                    Cell *newCell = new Cell(1);
                    oriHead->down = newCell;
                    newCell->up = oriHead;
                    newCell->down = temp;
                    temp->up = newCell;
                    utlis->right = newCell;
                    newCell->left = utlis;
                    utlis = newCell; // Update utlis to the newly inserted cell
                }
                oriHead = oriHead->right;
            }
        }
        rows++;
    }

    void insertColumnToRight()
    {
        Cell *oriHead = origionalHead;
        cout<<"jdklal"<<endl;
        int colIndex = getColumnIndex();
        int rowIdnex = getRowIndex();
        cout << colIndex << "rowdllj" << rowIdnex<<endl;
        if(colIndex==-1 || rowIdnex==-1)
        {
            cout<<"idnex are found"<<endl;
        }
        for (int i = 0; i < rowIdnex; i++)
        {
            oriHead = oriHead->down;
        }
        for (int i = 0; i < colIndex; i++)
        {
            oriHead = oriHead->right;
        }
        // if current cell is on mid
        if (oriHead->right != nullptr)
        {
            Cell *utlis = nullptr;
            Cell *top = oriHead->up;
            Cell *buttom = oriHead->down;
            Cell *tempRight = oriHead->right;
            Cell *cell = new Cell(3);
            oriHead->right = cell;
            cell->left = oriHead;
            tempRight->left = cell;
            cell->right = tempRight;
            utlis = cell;

            // for top
            while (top != nullptr)
            {
                Cell *c = new Cell(3);
                Cell *topRight = top->right;
                top->right = c;
                c->left = top;
                topRight->left = c;
                c->right = topRight;
                utlis->up = c;
                c->down = utlis;
                utlis = c;

                top = top->up;
            }

            //   for buttom
            utlis = cell; // update the utlis again
            while (buttom != nullptr)
            {
                Cell *c = new Cell(3);
                Cell *buttomRight = buttom->right;
                buttom->right = c;
                c->left = buttom;
                buttomRight->left = c;
                c->right = buttomRight;
                utlis->down = c;
                c->up = utlis;
                utlis = c;

                buttom = buttom->down;
            }
        }
        // and if the current cell is the last lest cell
        else
        {
            Cell *utlis = nullptr;
            Cell *top = oriHead->up;
            Cell *buttom = oriHead->down;
             Cell *cell = new Cell(3);
            oriHead->right = cell;
            cell->left = oriHead;
            utlis = cell;

               // for top
            while (top != nullptr)
            {
                Cell *c = new Cell(3);
                // Cell *topRight = top->right;
                top->right = c;
                c->left = top;
                // topRight->left = c;
                // c->right = topRight;
                utlis->up = c;
                c->down = utlis;
                utlis = c;

                top = top->up;
            }

            //   for buttom
            utlis = cell; // update the utlis again
            while (buttom != nullptr)
            {
                Cell *c = new Cell(3);
                // Cell *buttomRight = buttom->right;
                buttom->right = c;
                c->left = buttom;
                // buttomRight->left = c;
                // c->right = buttomRight;
                utlis->down = c;
                c->up = utlis;
                utlis = c;

                buttom = buttom->down;
            }

        }
        col++;
    }

    void insertColumnToLeft()
    {
        Cell *oriHead = origionalHead;
        cout<<"jdklal"<<endl;
        int colIndex = getColumnIndex();
        int rowIdnex = getRowIndex();
        cout << colIndex << "rowdllj" << rowIdnex<<endl;
        if(colIndex==-1 || rowIdnex==-1)
        {
            cout<<"idnex are found"<<endl;
        }
        for (int i = 0; i < rowIdnex; i++)
        {
            oriHead = oriHead->down;
        }
        for (int i = 0; i < colIndex; i++)
        {
            oriHead = oriHead->right;
        }
        // if current cell is on mid
        if (oriHead->left != nullptr)
        {
            Cell *utlis = nullptr;
            Cell *top = oriHead->up;
            Cell *buttom = oriHead->down;
            Cell *tempLeft = oriHead->left;
            Cell *cell = new Cell(3);
            oriHead->left = cell;
            cell->right = oriHead;
            tempLeft->right = cell;
            cell->left = tempLeft;
            utlis = cell;

            // for top
            while (top != nullptr)
            {
                Cell *c = new Cell(3);
                Cell *topleft = top->left;
                top->left = c;
                c->right = top;
                topleft->right = c;
                c->left = topleft;
                utlis->up = c;
                c->down = utlis;
                utlis = c;

                top = top->up;
            }

            //   for buttom
            utlis = cell; // update the utlis again
            while (buttom != nullptr)
            {
                Cell *c = new Cell(3);
                Cell *buttomLeft = buttom->left;
                buttom->left = c;
                c->right = buttom;
                buttomLeft->right = c;
                c->left = buttomLeft;
                utlis->down = c;
                c->up = utlis;
                utlis = c;

                buttom = buttom->down;
            }
        }
        // and if the current cell is the last lest cell
        else
        {
            Cell *utlis = nullptr;
            Cell *top = oriHead->up;
            Cell *buttom = oriHead->down;
             Cell *cell = new Cell(3);
            oriHead->left = cell;
            cell->right = oriHead;
            utlis = cell;
            
            // do upatet he original head as well 
            origionalHead= cell;

               // for top
            while (top != nullptr)
            {
                Cell *c = new Cell(3);
                // Cell *topRight = top->right;
                top->left = c;
                c->right = top;
                // topRight->left = c;
                // c->right = topRight;
                utlis->up = c;
                c->down = utlis;
                utlis = c;

                top = top->up;
            }

            //   for buttom
            utlis = cell; // update the utlis again
            while (buttom != nullptr)
            {
                Cell *c = new Cell(3);
                // Cell *buttomRight = buttom->right;
                buttom->left = c;
                c->right = buttom;
                // buttomRight->left = c;
                // c->right = buttomRight;
                utlis->down = c;
                c->up = utlis;
                utlis = c;

                buttom = buttom->down;
            }

        }
        col++;
    }

    int getColumnIndex()
    {
        Cell *forRow = origionalHead;
        for (int i = 0; i < col; i++)
        {
            Cell *forCol = forRow;
            for (int j = 0; j < rows; j++)
            {
                if (forCol == current)
                {
                    return i; // get row index
                }
                forCol = forCol->down;
            }
            forRow = forRow->right;
        }
        return -1;
    }
    int getRowIndex() // will give you the ucrrent index
    {
        Cell *forRow = origionalHead;
        for (int i = 0; i < rows; i++)
        {
            Cell *forCol = forRow;
            for (int j = 0; j < col; j++)
            {
                if (forCol == current)
                {
                    return i; // get row index
                }
                forCol = forCol->right;
            }
            forRow = forRow->down;
        }
        return -1;
    }
};

int main()
{
    Excel excel(5, 5);
    excel.displayGrid();
    cout << endl;
    excel.insertAtAbove();
    excel.displayGrid();
    cout << endl;
    excel.insertRowBelow();
    excel.displayGrid();
    cout << endl;
    excel.insertColumnToRight();
    excel.displayGrid();

     excel.insertColumnToLeft();
    excel.displayGrid();
}