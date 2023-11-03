# String Formatting Tip

# String Concat
sentence = "Python is the " + "best programming lang"
print(sentence)

# Formatting with .format()
# "string {}".format(value1, value2)
sen2 = "{} is num {}".format("Python", 1)
print(sen2)

# Formatting with %
sen3 = "%s is num %d"%("Python", 1)
print(sen3)

# f string
val = "Python"
sen4 = f"{val} is best"
print(sen4)

# .join() method on list
list1 = ["Python", "is", "best"]
print("".join(list1))