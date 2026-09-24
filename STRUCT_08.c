#include <stdio.h>

struct Data {
    int d,m,a;
};

int dias(struct Data x){
    return x.a*365 + x.m*30 + x.d;
}

int main() {
    struct Data a, b;
    int da, db;
    scanf("%d %d %d", &a.d,&a.m,&a.a);
    scanf("%d %d %d", &b.d,&b.m,&b.a);
    da = dias(a);
    db = dias(b);
    if(da > db) printf("%d\n", da - db);
    else printf("%d\n", db - da);
    return 0;
}
