#include <iostream>
using namespace std;

int unableToCollectToys(int children[], int childrenSize, int toys[], int toysSize) {
    int unable = 0;
    int childIndex = 0;
    int toyIndex = 0;
    int stack[1000];

    for (int i = 0; i < toysSize; ++i) 
    {
        while (childIndex < childrenSize && !((toyIndex == 0 && children[childIndex] == toys[i]) || (toyIndex != 0 && stack[toyIndex - 1] == children[childIndex]))) 
        {
            childIndex++;
            unable++;
        }

        // If the current toy doesn't match the preference of the child at the front of the line, push it onto the stack
        if (!(childIndex < childrenSize && children[childIndex] == toys[i])) 
        {
            stack[toyIndex++] = toys[i];
        }
        else {
            // Otherwise, remove the child from the front of the line
            childIndex++;
        }
    }

    // Count the remaining children who couldn't collect their preferred toy
    unable += childrenSize - childIndex;

    return unable;
}

