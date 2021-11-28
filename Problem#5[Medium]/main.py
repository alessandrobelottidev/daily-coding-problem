"""
Good morning! Here's your coding interview problem for today.
This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given the below implementation of cons, implement car(pair) and cdr(pair)
"""
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
    
# To solve this problem you have to know what are closures and how they work
# My first solution was:
# def car(pair):
#     return pair.__closure__[0].cell_contents
# def cdr(pair):
#     return pair.__closure__[1].cell_contents

# On a second though we can use lambda functions to target that anonymous function f
def car(pair):
    return pair(lambda a, b: a)

def cdr(pair):
    return pair(lambda a, b: b)

# Simple tests
print(car(cons(3, 4)))
print(cdr(cons(3, 4)))
