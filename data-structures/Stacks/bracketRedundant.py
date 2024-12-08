def checkRedundant(s):
    stack = []
    operator = "+-*/"

    for char in s:
        if char == "(" or char in operator:
            stack.append(char)
        else:
            if char == ")":
                isRedundant = True

                while stack and stack[-1] != "(":
                    if stack[-1] in operator:
                        isRedundant = False
                    stack.pop()
                
                if isRedundant:
                    return 1
                stack.pop()
    return 0

s = input("Enter to check redundancy: ")
if checkRedundant(s):
    print(s, "is redundant")
else:
    print(s, "is not redundant")