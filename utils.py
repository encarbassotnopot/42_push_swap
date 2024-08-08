def swap(stack):
    print (f's{stack["name"]}')
    stack['content'][0], stack['content'][1] = stack['content'][1], stack['content'][0]

def rotate(stack):
    if len(stack['content']) < 2:
        return
    print (f'r{stack["name"]}')
    stack['content'].append(stack['content'].pop(0))

def rev_rotate(stack):
    if len(stack['content']) < 2:
        return
    print (f'rr{stack["name"]}')
    stack['content'].insert(0, stack['content'].pop())

def push(orig, dest):
    if orig == dest:
        return
    if len(orig['content']) < 1:
        return
    print (f'p{dest["name"]}')
    dest['content'].insert(0, orig['content'].pop(0))

def invert(orig, other, total):
    if total < 2:
        return
    elif total == 2:
        swap(orig)
    elif total == 3:
        swap(orig)
        rotate(orig)
        swap(orig)
        rev_rotate(orig)
        swap(orig)
    else:
        push(orig, other)
        invert(orig, other, total - 1)
        push(other, orig)
        rotate(orig)


def get_run_end(stack, radix, i = 0):
    if len(stack['content']) == 0:
        return None
    i = 0
    while (i < len(stack['content'])):
        if i + 1 == len(stack['content']):
            break
        elif stack['content'][i] < stack['content'][i+1]:
            i += 1
        else:
            break
    return(stack['content'][i])

def get_run_len(stack, radix, i = 0):
    if len(stack['content']) == 0:
        return None
    while (i < len(stack['content'])):
        if i + 1 == len(stack['content']):
            break
        elif stack['content'][i] <= stack['content'][i+1]:
            i += 1
        else:
            break
    return(i+1)

def get_rev_run_len(stack, radix, i = 0):
    if len(stack['content']) == 0:
        return None
    while (i < len(stack['content'])):
        if i + 1 == len(stack['content']):
            break
        elif stack['content'][i] > stack['content'][i+1]:
            i += 1
        else:
            break
    return(i+1)

def get_run_count(stack, radix, i = 0):
    if len(stack['content']) == 0:
        return None
    count = 0
    i = 0
    while (i < len(stack['content'])):
        i = get_run_len(stack, i, radix)
        count += 1
    return(count)
