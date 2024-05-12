#include "stack.h"
#include "Point.h"

string intToString(int num)
{
    string result;
    if (num == 0)
    {
        result.push_back('0');
        return result;
    }
    bool isNegative = false;
    if (num < 0)
    {
        isNegative = true;
        num = -num;
    }
    while (num > 0)
    {
        char digit = num % 10 + '0';
        result = digit + result;
        num /= 10;
    }
    if (isNegative)
        result = '-' + result;
    return result;
}

void findTreasure(const char maze[5][7], Point start) 
{
    Stack<Point*> stack; 
    bool visited[5][7] = { false };

    stack.push(new Point(start));

    visited[start.row][start.column] = true;

    while (!stack.isEmpty()) 
    {
        Point* currentPtr = stack.top();
        Point current = *currentPtr;
        stack.pop();

        if (maze[current.row][current.column] == 'E') 
        {
            cout << "Found the treasure Path: (" << current.row << "," << current.column << ")" << endl;
            while (!stack.isEmpty()) 
            {
                delete stack.top();
                stack.pop();
            }
            return;
        }

        int rowOffsets[] = { -1, 1, 0, 0 };
        int colOffsets[] = { 0, 0, 1, -1 };

        for (int i = 0; i < 4; ++i) 
        {
            int newRow = current.row + rowOffsets[i];
            int newCol = current.column + colOffsets[i];

            if (newRow >= 0 && newRow < 5 && newCol >= 0 && newCol < 7 &&
                maze[newRow][newCol] != '#' && !visited[newRow][newCol])
            {
                Point* newPoint = new Point(newRow, newCol);
                stack.push(newPoint);
                visited[newRow][newCol] = true;
            }
        }
    }

    cout << "No Valid Path Found!" << endl;
    while (!stack.isEmpty()) 
    {
        delete stack.top();
        stack.pop();
    }
}

int main() {
    const char maze[5][7] = 
    {
        {'#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', 'E', '#'}
    };
    Point start(1, 1);
    findTreasure(maze, start);
    return 0;
}
