#!/usr/bin/env python3
import sys

def parse_args(args):
    """Parse command line arguments into stack a"""
    stack_a = []
    for arg in args:
        numbers = arg.split()
        for num in numbers:
            try:
                stack_a.append(int(num))
            except ValueError:
                print("Error")
                sys.exit(1)
    return stack_a

def execute_commands(stack_a, commands):
    """Execute push_swap commands on stack"""
    stack_b = []
    
    for cmd in commands:
        cmd = cmd.strip()
        if not cmd:
            continue
            
        if cmd == 'sa':
            if len(stack_a) >= 2:
                stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
        elif cmd == 'sb':
            if len(stack_b) >= 2:
                stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
        elif cmd == 'ss':
            if len(stack_a) >= 2:
                stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
            if len(stack_b) >= 2:
                stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
        elif cmd == 'pa':
            if stack_b:
                stack_a.insert(0, stack_b.pop(0))
        elif cmd == 'pb':
            if stack_a:
                stack_b.insert(0, stack_a.pop(0))
        elif cmd == 'ra':
            if stack_a:
                stack_a.append(stack_a.pop(0))
        elif cmd == 'rb':
            if stack_b:
                stack_b.append(stack_b.pop(0))
        elif cmd == 'rr':
            if stack_a:
                stack_a.append(stack_a.pop(0))
            if stack_b:
                stack_b.append(stack_b.pop(0))
        elif cmd == 'rra':
            if stack_a:
                stack_a.insert(0, stack_a.pop())
        elif cmd == 'rrb':
            if stack_b:
                stack_b.insert(0, stack_b.pop())
        elif cmd == 'rrr':
            if stack_a:
                stack_a.insert(0, stack_a.pop())
            if stack_b:
                stack_b.insert(0, stack_b.pop())
        else:
            print("Error")
            sys.exit(1)
    
    return stack_a, stack_b

def is_sorted(stack):
    """Check if stack is sorted in ascending order"""
    for i in range(len(stack) - 1):
        if stack[i] > stack[i + 1]:
            return False
    return True

def main():
    if len(sys.argv) < 2:
        sys.exit(1)
    
    # Parse stack a from arguments
    stack_a = parse_args(sys.argv[1:])
    
    # Read commands from stdin
    commands = sys.stdin.read().strip().split('\n')
    
    # Execute commands
    stack_a, stack_b = execute_commands(stack_a, commands)
    
    # Check result
    if is_sorted(stack_a) and len(stack_b) == 0:
        print("OK")
    else:
        print("KO")

if __name__ == '__main__':
    main()
