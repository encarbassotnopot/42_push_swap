# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 11:51:16 by ecoma-ba          #+#    #+#              #
#    Updated: 2024/07/15 13:30:36 by ecoma-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) < 2:
    print("Error, not enough arguments")

a = {'content': [int(sys.argv[i])
                 for i in range(1, len(sys.argv))],
     'name': 'a'}
b = {'content': [], 'name': 'b'}

def swap(stack):
    print (f's{stack["name"]}')
    stack['content'][0], stack['content'][1] = stack['content'][1], stack['content'][0]
    #print(stack['content'])

def rotate(stack):
    print (f'r{stack["name"]}')
    stack['content'].append(stack['content'].pop(0))
    #print(stack['content'])

def rev_rotate(stack):
    print (f'rr{stack["name"]}')
    stack['content'].insert(0, stack['content'].pop())
    #print(stack['content'])

def push(orig, dest):
    print (f'p{dest["name"]}')
    dest['content'].insert(0, orig['content'].pop(0))
    #print(dest['content'])

def sort_top(stack):
    if stack[0] > stack[1]:
        swap(stack)

def push_rot_smallest(orig, dest):
    if (dest[0] < orig[0]):
        push(orig, dest)
    rotate(orig)

push(a, b)
push(a, b)
swap(b)
swap(a)
rotate(a)
rotate(a)
push(a, b)
push(a, b)
swap(a)
rotate(a)
push(b, a)
rotate(a)
rotate(a)
push(b, a)
rotate(a)
push(a, b)
rotate(b)
rotate(b)
push(a, b)
rotate(b)
rotate(b)
rotate(a)
push(b, a)
rotate(a)
rotate(a)
push(b, a)
rotate(a)
push(b, a)
rotate(a)
rotate(a)
push(b, a)
rotate(a)
rotate(a)
