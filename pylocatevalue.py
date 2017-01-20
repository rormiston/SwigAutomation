'''
Just a silly script for demonstration purposes. The function will
try to guess 'magic_number' given the range 'top' up to the precision
given by 'precision' by repeatedly splitting the distance to the
magic_number in half.
'''

def PyLocateValue(magic_number, top, precision):
    guess = top / 2
    while abs(guess - magic_number) > precision:
        if guess > magic_number:
            guess = guess - (top - guess) / 2
        else:
            guess = guess + (top - guess) / 2
    return guess
