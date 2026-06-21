# Python program for the above approach

# Function to return ASCII
# value of a character
def val(c):
    if (c >= '0' and c <= '9'):
        return ord(c) - 48
    else:
        return ord(c) - 65  + 10

# Function to convert a number
# from given base to decimal number
def toDeci(strr, base):
    lenn = len(strr)
    # Initialize power of base
    power = 1
    # Initialize result
    num = 0
    
    # Decimal equivalent is strr[len-1]*1
    # + strr[len-2]*base + strr[len-3]*(base^2) + ...
    for i in range(lenn - 1, -1, -1):
        # A digit in input number must
        # be less than number's base
        if (val(strr[i]) >= base):
            print("Invalid Number")
            return -1

        num += val(strr[i]) * power
        
        # Update power
        power = power * base
    
    return num


# This is the reverse operation of the val() function
# The reVal function converts a numeric digit (0-35) back to its character
    # For digits 0-9: Convert numeric value to character '0'-'9'
    # ASCII code 48 corresponds to character '0'
    # So num=0 -> chr(0+48) -> chr(48) -> '0'
    # So num=1 -> chr(1+48) -> chr(49) -> '1'
    # ... and so on until num=9 -> chr(9+48) -> chr(57) -> '9'
# The reVal function converts a numeric digit
        # For digits 10-35: Convert to characters 'A'-'Z' for bases > 10
        # ASCII code 65 corresponds to character 'A'
        # So num=10 -> chr(10-10+65) -> chr(65) -> 'A' (represents 10 in base > 10)
        # So num=11 -> chr(11-10+65) -> chr(66) -> 'B' (represents 11 in base > 10)
        # ... and so on until num=35 -> chr(35-10+65) -> chr(90) -> 'Z' (represents 35 in base 36)
        # This function is essential for converting decimal numbers back to any base representation
        # It works with the fromDeci() function to build the final converted number string
def reVal(num):
    
    if (num >= 0 and num <= 9):
        return chr(num + 48)
    else:
        return chr(num - 10 + 65)


def fromDeci(base, inputNum):
    # Store the result
    res = ""
    
    # Repeatedly divide inputNum
    # by base and take remainder
    while (inputNum > 0):
        # Update res
        res += reVal(inputNum % base)
        # Update inputNum
        inputNum //= base
        
    # Reverse the result
    res = res[::-1]
    
    return res


# Function to convert a given number
# from a base to another base
def convertBase(s, a, b):
    num = toDeci(s, a)

    ans = fromDeci(b, num)

    print(ans)



# Given input
s = "10B"
a = 16
b = 10

# Function Call
convertBase(s, a, b)
