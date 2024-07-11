# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 11:51:16 by ecoma-ba          #+#    #+#              #
#    Updated: 2024/07/11 13:04:04 by ecoma-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) < 2:
    print("Error, not enough arguments")

sa = {'content': [int(sys.argv[i])
                  for i in range(1, len(sys.argv))], 'name': 'a'}
sb = {'content': [], 'name': 'b'}

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

swap(sa)
push(sa, sb)
push(sa, sb)
push(sa, sb)
rotate(sa)
rotate(sa)
push(sb, sa)
push(sb, sa)
push(sb, sa)
