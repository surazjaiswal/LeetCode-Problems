https://leetcode.com/problems/flatten-nested-list-iterator/discuss/1156562/Short-and-Simple-Code-or-C%2B%2B-Solution-Using-Pointers-and-Iterators-without-making-Copies
​
​
```
class NestedIterator {
public:
stack<NestedInteger*> Start, End; // stores pointer to start & end of nested lists
NestedIterator(vector<NestedInteger> &nestedList) {
Start.push(&nestedList.front());
End.push(&nestedList.back());
}
// will only return the next integer and increment the pointer on top of stack
int next() {
return Start.top()++ -> getInteger();
}
// Returns true only if there's more integer(s) yet to be traversed
// If there are next integers, this function also ensures the stack top points to it
// when size of stack becomes 0, we have traversed all of nestedList
bool hasNext() {
while(size(Start)){
auto top = Start.top();
if(Start.top() > End.top()){ // when a list is completely traversed
Start.pop(), End.pop();
continue;
}
if(top -> isInteger()) break;
Start.top()++;
if(!size(top -> getList())) continue;
Start.push(&top -> getList().front());
End.push(&top -> getList().back());
}
return size(Start);
}
};
```