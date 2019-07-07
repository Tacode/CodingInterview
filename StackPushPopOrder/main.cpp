#include <iostream>
#include <vector>
#include <MyStack.h>
using namespace std;

bool IsPopOrder(vector<int> &pushVec, vector<int> & popVec){
    MyStack<int> *mystack = new MyStack<int>(100);
    bool result = false;
    int push_index = 0;
    int pop_index = 0;
    int initPushIndex = 0;
    int initPopIndex = 0;
    int len = popVec.size();
    if (len>0){
        while ((pop_index - initPopIndex) < len){
            while (mystack->empty() || mystack->top() != popVec[pop_index]){
                if ((push_index - initPushIndex) == len)
                    break;
                mystack->push(pushVec[push_index++]);

            }

            if (mystack->top() != popVec[pop_index]) //这个清况是所有元素都压入栈中，依然没找到下一个弹出的元素
                break;
            mystack->pop();
            pop_index++;
        }
        cout << pop_index << endl;
        if (mystack->empty() && (pop_index-initPopIndex) == len){
            result = true;
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    vector<int> pushVec = {1,2,3,4,5};
    vector<int> popVec = {4,3,5,1,2};
    cout << IsPopOrder(pushVec, popVec) << endl;
    return 0;
}
