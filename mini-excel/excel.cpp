
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
            Cell* temp = head;
            // for columns
             int count = 0;
            for (int j = i; j < col; j++)
            {
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
            count =0; //do update the count;
            next= head->right; //do update next;
            // for rows
            temp = head;
             
            for (int k = i + 1; k < rows; k++)
            {
             
                Cell *cell = new Cell(0);
                
                if(next != nullptr && pre != nullptr)
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
    }


    void displayGrid()
    {
       Cell* dcolumn = current;
       while(dcolumn!=nullptr)//up is not equal nullptr;
       {
           Cell* temp = dcolumn;
          while(temp!=nullptr) //when temp is equal to nulltptr it  means you are at left = nullptr
          {
            cout<<temp->data<<"-->";
            temp = temp->left;
          }
          cout<<"Null"<<endl;
          dcolumn = dcolumn->up;
       }
    }
};

int main()
{
    Excel excel(5,5);
    excel.displayGrid();
}