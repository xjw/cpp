#include <iostream>
#include <unistd.h>

using namespace std;

/*
 * http://stackoverflow.com/questions/4459685/functionality-of-fork
 */
void printPidTree(int nChildren, int depth) {
    int child_counter, depth_counter, pid;
    child_counter = depth_counter = 0;
    while (child_counter<nChildren && depth_counter<depth) {
        cout << getppid() << "-" << getpid() << endl;
        pid = fork();
        if (pid == 0) { //executes for child
            cout << getppid() << "-" << getpid() << endl;//prints parent's id and self id to buffer
            child_counter = -1; //resets arity to 0 (after current iteration of loop is finished), so new process makes correct number of children
            depth_counter++;//increases depth counter for child and all of its children
        }
        if (pid > 0) {
            waitpid(pid, NULL, 0);
            cout << getppid() << "-" << getpid();//prints parent's id and self id to buffer
        }
        child_counter++;
    }
    cout << endl;
}

int main() {
    printPidTree(2, 2);
}
