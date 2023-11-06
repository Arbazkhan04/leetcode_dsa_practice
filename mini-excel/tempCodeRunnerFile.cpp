 else
                        {
                            oriHead->down = cell;
                            cell->up = oriHead;
                            cell->left = utlis;
                            utlis->right = cell;
                            utlis = cell;
                        