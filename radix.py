#!/usr/bin/python3
import sys
from utils import *

if len(sys.argv) < 2:
    print("Error, not enough arguments")

a = {'content': [int(arg)
                 for arg in sys.argv[1].strip().split(' ')],
     'name': 'a'}
b = {'content': [], 'name': 'b'}

sorted = False
first_el = None
radix = 0
    
def print_stacks():
    print(a['content'])
    print(b['content'])


def split():
    i = 0
    c = len(a['content'])
    while(i < c):
        if a['content'][0] & 1 << radix * 2 == 0:
            push(a, b)
        else:
            rotate(a)
        i+=1

def merge():
    i = 0
    c = len(b['content'])
    while(i < c):
        push(b, a)
        i+=1

def sort():
    global radix
    sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))
    while not sorted:
        split()
        print_stacks()
        merge()
        print_stacks()
        radix += 1
        sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))

sort()
