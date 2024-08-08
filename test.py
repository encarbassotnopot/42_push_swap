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
radix = 1
    
def print_stacks():
    print(a['content'])
    print(b['content'])

def align():
    while (a['content'][-1] < a['content'][0]):
        rotate(a)

def split_a():
    i = 0
    while (a['content'][0] % 2**radix != get_run_end(a, radix)):
        rotate(a)
    rotate(a)


def split_b():
    i = 0
    while (a['content'][0] != get_run_end(a, radix)):
        push(a, b)
        rotate(b)
    push(a, b)
    rotate(b)

def split():
    i = 0
    c = get_run_count(a, radix)
    while(i < c):
        # if (rev_len := get_rev_run_len(a, radix)) > 1:
        #     invert(a, b, rev_len)
        if i % 2 == 0:
            split_a()
        else:
            split_b()
        i+=1

def merge():
    while len(b['content']) > 0:
        a_len = get_run_len(a, radix)
        b_len = get_run_len(b, radix)
        i = 0
        while a_len > 0 and b_len > 0:
            if (a['content'][0] % 2**radix > b['content'][0] % 2**radix):
                push(b, a)
                rotate(a)
                b_len -= 1
            else:
                rotate(a)
                a_len -= 1
        while a_len > 0:
            rotate(a)
            a_len -= 1
        while b_len > 0:
            push(b, a)
            rotate(a)
            b_len -= 1

def sort():
    global radix
    align()
    sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))
    while not sorted:
        split()
        print_stacks()
        merge()
        print_stacks()
        if  all(a['content'][i] % 2**radix <= a['content'][i+1] % 2**radix for i in
                range(len(a['content'])-1)):
            radix += 1
        sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))

sort()
