# returns minimum element of stack in O(1) time without extra space complexity
class MinStack:
    def __init__(self):
        self.stack = []
        self.mini = float('inf')

    def push(self, value):
        # mini push
        if value < self.mini:
            valueToPush = 2*value - self.mini
            self.stack.append(valueToPush)
            self.mini = value
        # normal push
        else:
            self.stack.append(value)

    def pop(self):
        if len(self.stack)==0:
            print("Stack Underflow")
            return
        
        if self.stack[-1] > self.mini:
            toPop = self.stack.pop()
            print(f"{toPop} popped from stack")
        else:
            nextMin = 2*self.mini - self.stack[-1]
            self.mini = nextMin
            toPop = self.stack.pop()
            print(f"{(toPop+self.mini)//2} popped from stack")

    def peek(self):
        # if self.top is value for minimum, then rturn minimum since that contains it else return value
        if self.stack[-1] < self.mini:
            return self.mini
        return self.stack[-1]

    def getMin(self):
        print(f"Min element in stack is {self.mini}\n")
        return self.mini
    
    
    def printStack(self):
        print(self.stack[::-1])

stack = MinStack()
stack.push(142)
stack.push(6)
stack.push(24)
stack.push(5)
stack.push(141)

stack.printStack()

stack.pop()
stack.getMin()
stack.pop()
stack.getMin()
stack.pop()
stack.getMin()
stack.pop()
stack.getMin()
stack.pop()
stack.getMin()
stack.pop()
stack.getMin()
