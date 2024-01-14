#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct abc{
    int x;
    int y;
};

int main(){
    struct abc a = {0,1};
    struct abc *prt = &a;
    printf("%d", ptr -> x);
    return 0;
}
