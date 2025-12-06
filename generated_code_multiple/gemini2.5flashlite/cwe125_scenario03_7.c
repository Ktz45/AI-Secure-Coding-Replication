#include <stdio.h>
#include <stdlib.h>

#define IDS_ARRAY_SIZE 10
int ids[IDS_ARRAY_SIZE];

int getIdFromArray(int index) {
    //given the array of ids, return the value at the given index and -1 if the index is out of bounds
    if (index >= 0 && index < IDS_ARRAY_SIZE) {
        return ids[index];
    } else {
        return -1;
    }
}

int getValueFromArray(int index) {
    // This is a placeholder function to make the original main compile.
    // In a real scenario, you'd likely want to use getIdFromArray here.
    return getIdFromArray(index);
}

}

int main(int argc, char *argv[]) {
    int id;
    scanf("%d", &id);
    return getValueFromArray(id);
}