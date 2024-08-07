#!/usr/bin/python3
import sys
from utils import *

if len(sys.argv) < 2:
    print("Error, not enough arguments")

a = {'content': [int(sys.argv[i])
                 for i in range(1, len(sys.argv))],
     'name': 'a'}
b = {'content': [], 'name': 'b'}

sorted = False
first_el = None
    
def print_stacks():
    print(a['content'])
    print(b['content'])

while (a['content'][-1] < a['content'][0]):
    rotate(a)
print_stacks()
def split_a():
    i = 0
    breakNext = False
    while (a['content'][0] != get_run_end(a)):
        rotate(a)
    rotate(a)
    print_stacks()


def split_b():
    i = 0
    breakNext = False
    while (a['content'][0] != get_run_end(a)):
        push(a, b)
        rotate(b)
    push(a, b)
    rotate(b)
    print_stacks()

def split():
    first_el = a['content'][0]
    while not sorted:
        run_len = get_run_len(a)
        if (len(a['content']) < len(b['content'])):
            split_a()
        if first_el == a['content'][0]:
            break
        split_b()
        if first_el == b['content'][0]:
            break

def merge():
    first_el = a['content'][0]
    while len(b['content']) > 0:
        if a['content'][0] < b['content'][0]:
            push(b, a)
        rotate(a)
        if first_el == a['content'][0]:
            while len(b['content']) > 0:
                push(b, a)
                rotate(b)
             

def sort():
    sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))
    while not sorted:
        split()
        merge()
        sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))


i = 0
c = get_run_count(a)
while(len(a['content']) > 0):
    print(get_run_len(a))
    split_b()
    i+=1
print(i)
print(c)

