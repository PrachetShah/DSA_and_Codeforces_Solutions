class Stack:
    def __init__(self):
        self.size = 5
        self.stack = [-1 for _ in range(self.size)]
        self.top = -1

    def push(self, value):
        if self.top < self.size-1:
            self.top += 1
            self.stack[self.top] = value
        else:
            print("Stack Overflow")

    def peek(self):
        if self.top == -1:
            print("Stack is empty")
        else:
            print(self.stack[self.top])
    
    def pop(self):
        if self.top == -1:
            print("Stack is Empty")
        else:
            self.top -= 1
            print("Element Popped")
    
    def printStack(self):
        print(self.stack[::-1])

    def deleteMiddle(self):
        if self.top < 0:
            print("Nothing to Delete")
            return
        size = self.top
        def solve(s, count, size):
            if count == size:
                s.pop()
                return
            # recursive backtrack
            top = s.pop()
            solve(s, count+1, size)
            s.append(top)
        solve(self.stack, 0, size//2)
        # reduce top since one element is deleted
        self.top -= 1

    def insertBottom(self, x):
        size = self.top
        def solve(st, size, count):
            if count == size:
                st.append(x)
                return
            # recursive backtracking
            top = st.pop()
            solve(st, size, count+1)
            st.append(top)
        solve(self.stack, size, 0)
        # increase top since one element is added
        self.top += 1
    
    def _sortedInsert(self, st, num):
        if len(st)==0 or st[-1]<num:
            st.append(num)
            return
        
        top = st.pop()
        self._sortedInsert(st, num)
        st.append(top)
    
    def sortStack(self):
        def helper(st):
            if len(st) == 0:
                return
            
            num = st.pop()
            helper(st)
            self._sortedInsert(st, num)
        helper(self.stack)

stack = Stack()
stack.push(5)
stack.push(6)
stack.push(24)
stack.push(142)
stack.push(141)
stack.pop()
stack.push(141)
stack.peek()
stack.printStack()
stack.deleteMiddle()
stack.printStack()
stack.deleteMiddle()
stack.insertBottom(70)
stack.printStack()
stack.sortStack()
stack.printStack()
