
#include <malloc.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>

// 在linux环境下编译

using namespace std;

void heapTest()
{
    int res = mlockall(MCL_CURRENT | MCL_FUTURE);

    mallopt(M_MMAP_MAX, 0);
    char *buf = static_cast<char*>(malloc(100 * 1024 *1024));

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    cout<< "first get rusage: "<<usage.ru_majflt<<endl;

    memset(buf,1,100 * 1024 * 1024);
    getrusage(RUSAGE_SELF, &usage);
    cout<< "first get rusage: "<<usage.ru_majflt<<endl;

    free(buf);
}

void stackTest()
{
    char a[4*1024*1024];
    memset(a,0,sizeof(a));

}
int main(int argc, char** argv)
{
    heapTest();
    stackTest();
    return 0;
}
